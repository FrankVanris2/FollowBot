/*
 * FollowBotClient.cpp
 * By: Frank Vanris
 * Date: 8/21/2024
 * 
 * Description:
 * Implementation of the client interface for robot-server communication.
 * Manages WiFi connectivity, HTTP requests, and command processing.
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


// Singleton instance
FollowBotClient followBotClient;

// Time interval constants
const int TENTH_SECOND = 100;       // 0.1 seconds
const int HALF_SECOND = 500;        // 0.5 seconds
const int SECOND = 1000;            // 1 second
const int FIVE_SECONDS = 5000;      // 5 seconds   
const int TEN_SECONDS = 10000;      // 10 seconds
const int SIXTY_SECONDS = 60000;    // 60 seconds
const int HOUR = 3600000;           // 1 hour
const int MAX_SERVER_NOT_CONNECTED = 3; // Max failed connection attemps before backoff

// Variable to track the last time postRobotInfo was executed
unsigned long lastPostTime = 0;

//JSON document for robot information
 StaticJsonDocument<128> robotInformationJson; // changed from 200 to 128 could potentially cause an issue 

// Server configuration
IPAddress server(192, 168, 0, 38); // Would be AWS instance but choose local for no production devices.
const int PORT = 5000; //Originally 80

// WiFi client
WiFiClient client;

/**
 * Constructor - initialize connection state variables
 */
FollowBotClient::FollowBotClient() : 
    mWifiConnectionStatus(WL_IDLE_STATUS), 
    mPreviousMillisMove(0), 
    mCountMoves(0), 
    mIPAddress(server.toString()),
    mRSSI(0), 
    lastServerCheck(0), 
    mServerNotConnectedCnt(0), 
    mIsConnected(false)
{
    // Set connection timeout (15 seconds)
    client.setConnectionTimeout(15000);
}

/**
 * Initialize WiFi connection and prepare for communication
 */
void FollowBotClient::followBotClient_Setup() {
    // Check firmware version
    String firmVersion = WiFi.firmwareVersion(); 
    if(firmVersion < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }
    Serial.println("Client Setup Starting");
    
    // Check for WiFi module
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");  
    }

    // Attempt to connect to WiFi network with timeout
    unsigned long startAttemptTime = millis();
    while(mWifiConnectionStatus != WL_CONNECTED && millis() - startAttemptTime < TEN_SECONDS) {
        Serial.print(String("Attempting to connect to SSID: ") + eepromStorage.getSSID());

        // Convert String to char array for WiFi.begin()
        int ssidLength  = eepromStorage.getSSID().length() + 1; 
        int passLength  = eepromStorage.getPassword().length() + 1;   //The +1 is for the 0x00h Terminator
        char ssidArray[ssidLength];
        char passArray[passLength];
        eepromStorage.getSSID().toCharArray(ssidArray, ssidLength);
        eepromStorage.getPassword().toCharArray(passArray, passLength);

        // Connect with or without password based on password length
        if(eepromStorage.getPassword().length() == 0) {
            mWifiConnectionStatus = WiFi.begin(ssidArray);
        } else {
            mWifiConnectionStatus = WiFi.begin(ssidArray, passArray);
        }
        
        delay(100); // Short delay between attempts
    }

    // Update connection state based on result
    if(mWifiConnectionStatus == WL_CONNECTED) {
        printWifiStatus();
        mIsConnected = true;
    } else {
        Serial.println("Failed to connect to Wifi");
        mIsConnected = false;
    }
}

/**
 * Main client update loop
 * Handles periodic server communication and manages connection state
 */
void FollowBotClient::followBotClient_Loop() {
    // Use ternary to determine base interval based on server connectivity
    int baseIntervalTime = mServerNotConnectedCnt < MAX_SERVER_NOT_CONNECTED ? TENTH_SECOND : SIXTY_SECONDS;

    // Determine communication interval based on robot mode and server availability
    int intervalTime;

    if(mServerNotConnectedCnt >= MAX_SERVER_NOT_CONNECTED) {
        // If server is unresponsive, use the long interval regardless of mode
        intervalTime = SIXTY_SECONDS;
    } else {
        // Server is responsive, adjust interval based on mode
        String currentMode = followBotManager.getCurrentControl();

        if (currentMode == MANUAL) {
            intervalTime = TENTH_SECOND;        // Most responsive for manual control
        } else if (currentMode == FOLLOWING) {
            intervalTime = FIVE_SECONDS;        // Moderate for following mode
        } else {
            intervalTime = SECOND;              // Default for other modes
        }
    }

    // Only process when interval has elapsed
    unsigned long currentTime = millis();
    if((currentTime - mPreviousMillisMove) >= intervalTime) {
        mPreviousMillisMove = currentTime;

        // Update connection state
        mWifiConnectionStatus = WiFi.status() == WL_CONNECTED ? WL_CONNECTED : WL_DISCONNECTED;
        mIsConnected = mWifiConnectionStatus == WL_CONNECTED;

        // Only communicate if connected
        if(mIsConnected) {
            // Debug output during server reconnect backoff
            // if (intervalTime > SECOND) {
            //     Serial.println(String("Server connection attempts: ") + mServerNotConnectedCnt);
            // }

            // Process commands from server
            String dataString = getActionData();
            handleActionData(dataString);

            // Post robot status if it's time (once per hour)
            if(followBotManager.getDirtyFlag() && (currentTime - lastPostTime >= HOUR || lastPostTime == 0)) {
                bool postSuccess = postRobotInfo();
                if(postSuccess) {
                    lastPostTime = currentTime;
                    
                    // Debug output
                    Serial.println("Posted robot info - next post in 1 hour");
                }
            } 
        }  

        // Check signal strength during  connection problems
        if(mServerNotConnectedCnt >= MAX_SERVER_NOT_CONNECTED) {
            checkRSSI();
        }
    }  
}

/**
 * Retrieve action commands from server
 * @return String containing action data or ERROR if connection fails
 */
String FollowBotClient::getActionData() {
    // Check if server is reachable
    Serial.println("Retrieving action data from server...");

    // Connect to server
    if(!client.connect(server, PORT)) {
        Serial.println("Server connection failed");
        if(mServerNotConnectedCnt < MAX_SERVER_NOT_CONNECTED) {
            mServerNotConnectedCnt++;
        }
        return ERROR;
    }
    Serial.println("Server connected");
    mServerNotConnectedCnt = 0;

    // Send HTTP GET request
    client.println("GET /api/getActionData HTTP/1.1");
    client.print("Host: ");
    client.println(mIPAddress);
    client.println("Connection: close");
    client.println();

    // Buffer for response
    const int SIZE = 1024;
    char buffer[SIZE];
    int bufLength = 0;
    int bodyIdx = 0; // Start of body in buffer
    Data_States dataState = HEADER_STATE;
    bool readData = true;

    // Process HTTP response to extract body
    while (dataState != FINISHED) {
        int prevBufLen = bufLength;
        int numChars = 0; 

        // Read available data if needed
        if(readData) {      
            numChars = client.read(reinterpret_cast<uint8_t*>(buffer + bufLength), SIZE - bufLength);
            bufLength += numChars;
            buffer[bufLength] = 0;  // Null terminate
        }

        // Process data if available or if we're waiting for more
        if(!readData || numChars > 0) {
            switch(dataState) {
                // Parse headers to find start of body
                case HEADER_STATE: {
                    char* bufPtr;
                    for (bufPtr = buffer + prevBufLen; *(bufPtr + 3); ++bufPtr) {
                        // Look for empty line (CRLFCRLF) between headers and body
                        if (*bufPtr == 0x0d && *(bufPtr + 1) == 0x0a && *(bufPtr + 2) == 0x0d && *(bufPtr + 3) == 0x0a) {
                            bodyIdx = bufPtr - buffer + 4; // Skip past CRLFCRLF
                            dataState = BODY_STATE;
                            readData = false;
                            break;
                        } 
                    }
                    break;
                }

                // Process body state
                case BODY_STATE:
                    if(bufLength > bodyIdx) {
                        dataState = FINISHED;   // Body found, we're done
                    } else {
                        readData = true;        // Need more data
                    }
                    break;
            }
        }         
    } 

    client.stop();

    // Create string from response body
    String dataActionString(buffer + bodyIdx);
    return dataActionString;
}

/**
 * Process data received from the server
 * @pre dataString has to contain `{mode},{command}`
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
    String mode = (firstComma >= 0) ? dataString.substring(0, firstComma) : dataString;

    if (firstComma < 0) {
        return;
    }
    // Always update control mode first
    if (mode == FOLLOWING || mode == MANUAL || mode == MAPPING) {
        // Update the robot's control mode
        followBotManager.setCurrentControl(mode);

        //For debugging purposes
        Serial.print(String("Control mode changed to: ") + mode);
    } else {
        // Action data did not specify a mode
        return;
    }

    // Process any additional parameters based on the mode
    if (mode == MANUAL) {
        // For manual mode, everything after the comma is the direction command
        String direction = dataString.substring(firstComma + 1);

        // Printing if the direction has been received (debugging purposes)
        Serial.println(String("Direction command received: ") + direction);

        // Set motor direction based on the command
        if (direction == MOTOR_FORWARD || direction == MOTOR_BACKWARD || direction == MOTOR_LEFT || direction == MOTOR_RIGHT || direction == MOTOR_STOP) {
            myMotors.setDirection(direction);
        } 
    } else if (mode == MAPPING) {
        // For mapping mode, we expect latitude and longitude values
        String remainder = dataString.substring(firstComma + 1);
        int secondComma = remainder.indexOf(',');

        if (secondComma < 0) {
            return;     // Invalid format for coordinates
        }
        
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
        
    } else if (mode == FOLLOWING) {
        // Following mode with no parameters - robot does the work (debugging)
        // TODO: Block other functionalities while in FOLLOWING mode
        Serial.println("Following mode activated - robot controlling movement");
        // No additional parameters needed for FOLLOWING mode.
    }
}

/**
 * Display current WiFi connection information
 */
void FollowBotClient::printWifiStatus() {
    // Print network information
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // Print IP address
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
    Serial.print("Server IP address: ");
    Serial.println(mIPAddress);

    // Print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI): ");
    Serial.print(rssi);
    Serial.println(" dBm");
}

/**
 * Send robot status information to server
 * 
 * @return True if successful, false otherwise
 */
bool FollowBotClient::postRobotInfo() {
    // Check if server is reachable
    Serial.println("Posting robot information to server...");

    // Connect to server
    if(!client.connect(server, PORT)) {
        Serial.println("FollowBotClient.postRobotInfo(): Server did not connect");
        if(mServerNotConnectedCnt < MAX_SERVER_NOT_CONNECTED) {
            mServerNotConnectedCnt++;
        }
        return false;
    }

    Serial.println("Server connected");
    mServerNotConnectedCnt = 0;

    // Get current robot state data
    const OutputData& outputData = followBotManager.getOutputData();
        
    //Build JSON object with robot information
    robotInformationJson["botID"] = 123;
    robotInformationJson["temperature"] = outputData.mTemperature;
    robotInformationJson["battery"] = 100;
    
    JsonArray coordinates = robotInformationJson.createNestedArray("coordinates");
    coordinates.add(outputData.mCoordinates[LAT]);
    coordinates.add(outputData.mCoordinates[LON]);

    robotInformationJson["clock"] = outputData.mClock;

    // Serialize JSON to string
    String outputDataStr;
    serializeJson(robotInformationJson, outputDataStr);

    // Send HTTP POST request
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

    // Read response (for future use)
    String response = "";
    while (client.available()) {
        char c = client.read();
        response += c;
    }
    client.stop();

    return true;
}

/**
 * Update and monitor WiFi signal strength
 */
void FollowBotClient::checkRSSI() {
    mRSSI = WiFi.RSSI();

    // Only log RSSI if it's very poor or debugging is enabled
    if (mRSSI < -80) {
        Serial.print("Signal strength is weak: ");
        Serial.print(mRSSI);
        Serial.println(" dBm");
    }
}


