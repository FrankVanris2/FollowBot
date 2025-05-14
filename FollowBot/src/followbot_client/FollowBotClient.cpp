/*
* By: Frank Vanris
* Date: 8/21/2024
* Desc: Creating a client in which I will be able to send information up to the server and the server 
* will be able to send information up to the website and the mobile app
*/
#include <WiFiS3.h>
#include <ArduinoJson.h>

#include "FollowBotClient.h"
#include "motors/Motors.h"
#include "followbot_manager/FollowBotManager.h"
#include "following_mechanics/FollowMechanics.h"
#include "secrets/EEPROMStorage.h"
#include "states&types/DataStates.h"
#include "states&types/MotorControlStates.h"


// Universal Object
FollowBotClient followBotClient;

// Interval
const int TENTH_SECOND = 100;
const int HALF_SECOND = 500;
const int SECOND = 1000;
const int FIVE_SECONDS = 5000;
const int TEN_SECONDS = 10000;
const int SIXTY_SECONDS = 60000;
const int HOUR = 3600000;
const int MAX_SERVER_NOT_CONNECTED = 3;

// Variable to track the last time postRobotInfo was executed
unsigned long lastPostTime = 0;

//My Json creator
 StaticJsonDocument<200> robotInformationJson;

// Server IP address
//IPAddress server(3, 145, 197, 165); // numeric IP for Google (no DNS)
//IPAddress server(3, 131, 97, 5); // numeric IP for Google (no DNS) /
IPAddress server(10, 12, 199, 209);
const int PORT = 5000; //Originally 80

// WiFi client
WiFiClient client;

// Constructor
FollowBotClient::FollowBotClient(): mWifiConnectionStatus(WL_IDLE_STATUS), mPreviousMillisMove(0), mCountMoves(0), 
mIPAddress(server.toString()), mRSSI(0), lastServerCheck(0), mServerNotConnectedCnt(0), mIsConnected(false){
    client.setConnectionTimeout(15000);
}

void FollowBotClient::followBotClient_Setup() {

    String firmVersion = WiFi.firmwareVersion(); 
    if(firmVersion < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }
    Serial.println("Client Setup");
    
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");  
    }

    // Attempt to connect to WiFi network;
    unsigned long startAttemptTime = millis();
    while(mWifiConnectionStatus != WL_CONNECTED && millis() - startAttemptTime < TEN_SECONDS) {
        Serial.print(String("Attempting to connect to SSID: ") + eepromStorage.getSSID());
        int ssidLength  = eepromStorage.getSSID().length() + 1; 
        int passLength  = eepromStorage.getPassword().length() + 1;   //The +1 is for the 0x00h Terminator
        char ssidArray[ssidLength];
        char passArray[passLength];
        eepromStorage.getSSID().toCharArray(ssidArray, ssidLength);
        eepromStorage.getPassword().toCharArray(passArray, passLength);

        if(eepromStorage.getPassword().length() == 0) {
            mWifiConnectionStatus = WiFi.begin(ssidArray);
        } else {
            mWifiConnectionStatus = WiFi.begin(ssidArray, passArray);    //pass for private networks
        }
        
        // non-blocking delay:
        delay(100);
    }

    if(mWifiConnectionStatus == WL_CONNECTED) {
        printWifiStatus();
        mIsConnected = true;
    } else {
        Serial.println("Failed to connect to Wifi");
        mIsConnected = false;
    }
}

void FollowBotClient::followBotClient_Loop() {
    int baseIntervalTime = mServerNotConnectedCnt < MAX_SERVER_NOT_CONNECTED ? TENTH_SECOND : SIXTY_SECONDS;
    
    // Adjust interval based on mode, but only if server is responsive
    int intervalTime;
    if(mServerNotConnectedCnt >= MAX_SERVER_NOT_CONNECTED) {
        // If server is unresponsive, use the long interval regardless of mode
        intervalTime = SIXTY_SECONDS;
    } else {
        // Server is responsive, adjust interval based o mode
        String currentMode = followBotManager.getCurrentControl();

        if (currentMode == MANUAL) {
            // Manual control needs most frequent updates
            intervalTime = TENTH_SECOND;
        } else if (currentMode == FOLLOWING) {
            // Following mode can use a moderate interval
            intervalTime = FIVE_SECONDS;
        } else {
            // Other modes (IDLE, etc.) can user a longer interval
            intervalTime = SECOND;
        }
    }
    unsigned long currentTime = millis();
    if((currentTime - mPreviousMillisMove) >= intervalTime) {
        mPreviousMillisMove = currentTime;

        // Check WiFi connection status 
        if(WiFi.status() != WL_CONNECTED) {
            mWifiConnectionStatus = WL_DISCONNECTED;
        } else {
            mWifiConnectionStatus = WL_CONNECTED;
        }

        if(mWifiConnectionStatus == WL_CONNECTED) {
            Serial.println(String("mServerNotConnectedCnt: ") + mServerNotConnectedCnt);

            String dataString = getActionData();
            handleActionData(dataString);

            // Check if it's time to post robot info (once per hour)
            if(followBotManager.getDirtyFlag() && (currentTime - lastPostTime >= HOUR || lastPostTime == 0)) {
                bool postSuccess = postRobotInfo();
                if(postSuccess) {
                    lastPostTime = currentTime; // Update last post time only on success
                    Serial.println("Posted robot info - next post in 1 hour");
                }
            }

            // During extended intervals, continously print RSSI
            if(mServerNotConnectedCnt >= MAX_SERVER_NOT_CONNECTED) {
                checkRSSI();
            }
        }

        
        // During extended intervals, continuously print RSSI
        if(mServerNotConnectedCnt >= MAX_SERVER_NOT_CONNECTED) {
            Serial.println("I am inside of this RSSI if statement");
            checkRSSI();
        }
    }  
}

void FollowBotClient::printWifiStatus() {
    // Print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // Print your board's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address from board to hotspot: ");
    Serial.println(ip);
    Serial.print("Server IP address: ");
    Serial.println(server.toString());

    // Print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI): ");
    Serial.print(rssi);
    Serial.println(" dBm");
}

bool FollowBotClient::postRobotInfo() {
    Serial.println("Post Robot Info");
    Serial.println("FollowBotClient.postRobotInfo(): Connecting to server...") ;
    if(!client.connect(server, PORT)) {
        Serial.println("FollowBotClient.postRobotInfo(): Server did not connect");
        if(mServerNotConnectedCnt < MAX_SERVER_NOT_CONNECTED) {
            mServerNotConnectedCnt++;
        }
        return false;
    }
    Serial.println("FollowBotClient.postRobotInfo(): Server connected");
    mServerNotConnectedCnt = 0;

    const OutputData& outputData = followBotManager.getOutputData();
        
    //Adding given components to json object
    robotInformationJson["botID"] = 123;
    robotInformationJson["temperature"] = outputData.mTemperature;
    robotInformationJson["battery"] = 100;
    
    JsonArray coordinates = robotInformationJson.createNestedArray("coordinates");
    coordinates.add(outputData.mCoordinates[LAT]);
    coordinates.add(outputData.mCoordinates[LON]);

    robotInformationJson["clock"] = outputData.mClock;


    String outputDataStr;
    serializeJson(robotInformationJson, outputDataStr);

    //Serial.println("connected to server");
    client.println("POST /api/postBotLogs HTTP/1.1"); //Originally /api/robotinfo
    client.print("Host: "); // main server is 3.145.197.165
    client.println(mIPAddress);
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(outputDataStr.length());
    client.println();
    client.println(outputDataStr);
    client.println("Connection: close");
    client.println(); 

    String response = "";
    while (client.available()) {
        char c = client.read();
        response += c;
    }
    client.stop();

    return true;
}

// TODO: change this name so it is more specific to manual movement, adjust api.jsx accordingly
String FollowBotClient::getActionData() {
    Serial.println("FollowBotClient.getMove(): Connecting to server...") ;
    if(!client.connect(server, PORT)) {
        Serial.println("FollowBotClient.getMove(): Server did not connect");
        if(mServerNotConnectedCnt < MAX_SERVER_NOT_CONNECTED) {
            mServerNotConnectedCnt++;
        }
        return ERROR;
    }
    Serial.println("FollowBotClient.getMove(): Server connected");
    mServerNotConnectedCnt = 0;

    // get the information to make the robot move
     client.println("GET /api/getactiondata HTTP/1.1");
     client.print("Host: ");
     client.println(mIPAddress);
     client.println("Connection: close");
     client.println();
 
     String robotUserSwitch;
     const int SIZE = 1024;
     char buffer[SIZE];
     int bufLength = 0;
     int bodyIdx = 0; // Start of body in buffer
     Data_States dataState = HEADER_STATE;
     bool readData = true;
 
     while (dataState != FINISHED) {
         int prevBufLen = bufLength;
         int numChars = 0; 
         if(readData) {
             
             numChars = client.read(reinterpret_cast<uint8_t*>(buffer + bufLength), SIZE - bufLength);
             bufLength += numChars;
             buffer[bufLength] = 0;
         }
 
         if(!readData || numChars > 0) {
             switch(dataState) {
                 // Find start of body in just read data
                 case HEADER_STATE: {
                     char* bufPtr;
                     for (bufPtr = buffer + prevBufLen; *(bufPtr + 3); ++bufPtr) {
                         /*if (isprint(*bufPtr)) Serial.print(*bufPtr);
                         char buf[5];
                         Serial.print(" ");
                         Serial.print(itoa(*bufPtr, buf, 16));
                         Serial.print(", ");*/
                         if (*bufPtr == 0x0d && *(bufPtr + 1) == 0x0a && *(bufPtr + 2) == 0x0d && *(bufPtr + 3) == 0x0a) {
                             bodyIdx = bufPtr - buffer + 4; // Calculate index relative to buffer start
                             dataState = BODY_STATE;
                             readData = false;
                             break;
                         } 
                     }
                     break;
                 }
 
                 // Wait for the body to arrive
                 case BODY_STATE:
                     if(bufLength > bodyIdx) {
                         dataState = FINISHED;
                     } else {
                         readData = true;
                     }
                     break;
             }
         }         
     } 
     client.stop();

     String dataActionString(buffer + bodyIdx); // Create a string starting at the body
     return dataActionString;
}



/**
 * Process data received from the server
 * 
 * Message format:
 * - "MODE" - Simple mode change (e.g., "FOLLOWING")
 * - "MODE,COMMAND" - Mode with command (e.g., "MANUAL,Forward")
 * - "MODE,PARAM1,PARAM2" - Mode with parameters (e.g., "MAPPING,37.7749,-122.4194")
 * 
 * @param dataString The received data string to process
 */
void FollowBotClient::handleActionData(String dataString) {
    // Trim any whitespace
    dataString.trim();

    // Log the received data for debugging
    Serial.println(String("FollowBotClient: Received data: ") + dataString);

    // Find the first comma (if any)
    int firstComma = dataString.indexOf(',');

    // Extract mode (everything before first comma, or the entire string if no comma)
    String mode = (firstComma >= 0) ? dataString.substring(0, firstComma) : dataString;

    // Always update control mode first
    if (mode == FOLLOWING || mode == MANUAL || mode == MAPPING) {
        // Update the robot's control mode
        followBotManager.setCurrentControl(mode);

        //For debugging purposes
        Serial.print(String("Control mode changed to: ") + mode);
    }

    // Process any additional parameters based on the mode
    if (firstComma >= 0) {
        if (mode == MANUAL) {
            // For manual mode, everything after the comma is the direction command
            String direction = dataString.substring(firstComma + 1);

            // Printing if the direction has been received (debugging purposes)
            Serial.println(String("Direction command received: ") + direction);

            // Set motor direction based on the command
            if (direction == MOTOR_FORWARD || direction == MOTOR_BACKWARD || direction == MOTOR_LEFT || direction == MOTOR_RIGHT || direction == MOTOR_STOP) {
                // Set motor direction based on the command
                myMotors.setDirection(direction);
            } 
        } 
        else if (mode == MAPPING) {
            // For mapping mode, we expect latitude and longitude values
            String remainder = dataString.substring(firstComma + 1);
            int secondComma = remainder.indexOf(',');

            if (secondComma >= 0) {
                // Extract latitude and longitude from the remainder
                String latStr = remainder.substring(0, secondComma);
                String lonStr = remainder.substring(secondComma + 1);

                // setting the coordinates.
                float lat = latStr.toFloat();
                float lon = lonStr.toFloat();

                // Printing the Mapping coordinates (debugging purposes)
                Serial.print("Mapping coordinates: ");
                Serial.print(lat, 6);
                Serial.print(", ");
                Serial.println(lon, 6);

                // TODO: send the coordinates to ROS2 to create a path
                // For example:
                // ros2_serial.sendCoordinates(lat, lon);
                // replace bluetooth function in ros2_serial.
            }
            else {
                Serial.println("ERROR: Invalid mapping data format (missing second comma)");
            }
        }
    }
    // Handle FOLLOWING mode - no additional parameters needed
    else if (mode == FOLLOWING) {
        // Following mode with no parameters - robot does the work (debugging)
        Serial.println("Following mode activated - robot controlling movement");
        // No additional parameters needed for FOLLOWING mode.
    }
}



void FollowBotClient::checkRSSI() {
    // The RSSI check is now handled by the FreeRTOS task
    mRSSI = WiFi.RSSI();
    //Serial.print("FollowBotClient, mRSSI = ");
    //Serial.println(mRSSI);
}


