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


// Server configuration
IPAddress server(10, 12, 233, 78); // Would be AWS instance but choose local for no production devices.
const int PORT = 5000; //Originally 80

// Singleton instance
FollowBotClient followBotClient;

// Time interval constants
const int TEN_MILLISECONDS = 10;       // 0.01 seconds
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

void FollowBotClient::followBotClient_Setup() {
    // Check firmware version
    String firmVersion = WiFi.firmwareVersion(); 
    if(firmVersion < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }
    Serial.println("Client Setup Starting");
    
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");  
    }

    // Attempt to connect to WiFi network;
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

    if(mWifiConnectionStatus == WL_CONNECTED) {
        printWifiStatus();
        mIsConnected = true;
    } else {
        Serial.println("Failed to connect to Wifi");
        mIsConnected = false;
    }
}

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
            intervalTime = TENTH_SECOND;        // Moderate for following mode
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

    if (!client.connect(server, PORT)) {
        Serial.println("getActionData(): Server connection failed");
        if (mServerNotConnectedCnt < MAX_SERVER_NOT_CONNECTED) {
            mServerNotConnectedCnt++;
        }
        return ERROR;
    }
    Serial.println("getActionData(): Server connected");
    mServerNotConnectedCnt = 0;

    // Send HTTP GET request
    client.println("GET /api/getActionData HTTP/1.1");
    client.print("Host: ");
    client.println(mIPAddress);
    client.println("Connection: close"); // We expect the server to close the connection after response
    client.println();

    const int BUFFER_SIZE = 2048;
    char buffer[BUFFER_SIZE];
    int bufLength = 0;
    int bodyStartIndex = 0; // Index in buffer where the HTTP body starts
    Data_States dataState = HEADER_STATE;

    unsigned long responseStartTime = millis();
    const unsigned long RESPONSE_TIMEOUT_MS = 10000; // 10-second timeout for the entire response

    while (dataState != FINISHED) {
        // Check for overall response timeout
        if (millis() - responseStartTime > RESPONSE_TIMEOUT_MS) {
            Serial.println("getActionData(): Response timeout!");
            client.stop();
            return ERROR;
        }

        // Try to read data if the client is connected and there's space in the buffer
        if (client.connected() && bufLength < BUFFER_SIZE - 1) {
            int bytesRead = client.read(reinterpret_cast<uint8_t*>(buffer + bufLength), BUFFER_SIZE - 1 - bufLength);
            if (bytesRead > 0) {
                bufLength += bytesRead;
                buffer[bufLength] = '\0'; // Null-terminate the currently received data
                // Serial.print("getActionData(): Read "); Serial.print(bytesRead); Serial.println(" bytes.");
            }
        }

        if (dataState == HEADER_STATE) {
            // Try to find the end of headers (\r\n\r\n)
            char* headerEndPtr = strstr(buffer, "\r\n\r\n");
            if (headerEndPtr != nullptr) {
                bodyStartIndex = (headerEndPtr - buffer) + 4; // Calculate where the body begins
                dataState = BODY_STATE;
                Serial.println("getActionData(): Headers received, moving to BODY_STATE.");
            } else {
                // Headers not yet complete
                if (bufLength >= BUFFER_SIZE - 1) {
                    Serial.println("getActionData(): Buffer full, but headers not complete.");
                    client.stop();
                    return ERROR;
                }
                // If client disconnected before headers were fully received
                if (!client.connected() && client.available() == 0) { // Check available too
                     Serial.println("getActionData(): Client disconnected before headers complete.");
                     client.stop();
                     return ERROR;
                }
            }
        }

        if (dataState == BODY_STATE) {
            // Since we sent "Connection: close", the server should close the connection
            // after sending the response. The end of the body is when the client is no longer connected
            // and no more data is available.
            if (!client.connected() && client.available() == 0) {
                Serial.println("getActionData(): Client disconnected, assuming end of body.");
                dataState = FINISHED;
            }
            // If still connected, but no more data is coming in, the timeout will eventually trigger.
            // If the buffer is full and we are expecting more body (e.g. based on Content-Length, not parsed here)
            // this would be an issue, but for "Connection: close" we read till disconnect.
            if (bufLength >= BUFFER_SIZE - 1 && client.connected() && client.available() > 0) {
                 Serial.println("getActionData(): Buffer full while reading body, potential data loss.");
                 // Continue, but data might be truncated. Server should have closed.
                 // Or, treat as error if full body is critical and larger than buffer.
            }
        }

        // If no data was read and client is still connected, yield briefly to avoid tight spin
        // This is a fallback, the timeout is the main guard.
        if (client.connected() && client.available() == 0) {
            delay(1); // Small delay if waiting for data
        }
    }

    client.stop(); // Ensure the client connection is closed from our side as well

    if (bodyStartIndex > bufLength) {
        // This case should ideally not be reached if headers were parsed correctly.
        Serial.println("getActionData(): Error, bodyStartIndex is beyond buffer length after parsing.");
        return ERROR;
    }

    String responseBody = String(buffer + bodyStartIndex);
    // Serial.print("getActionData(): Response body: '"); Serial.print(responseBody); Serial.println("'");
    return responseBody;
}

/**
 * Process data received from the server
 * @pre dataString can be in formats like "MODE", "MODE,COMMAND", or "MODE,PARAM1,PARAM2".
 *      An empty dataString will result in no action.
 * Message format examples:
 * - "FOLLOWING" - Simple mode change
 * - "MANUAL,Forward" - Mode with command
 * - "MAPPING,37.7749,-122.4194" - Mode with parameters (Note: MAPPING data via this path is illustrative)
 *
 * @param dataString The received data string to process
 */
void FollowBotClient::handleActionData(String dataString) {
    // Trim any whitespace
    dataString.trim();

    // If dataString is empty (e.g., from a 204 No Content response), do nothing.
    if (dataString.length() == 0) {
        Serial.println("FollowBotClient: Received empty data string. No action taken.");
        return;
    }

    // Log the received data for debugging
    Serial.println(String("FollowBotClient: Received data: ") + dataString);

    int firstComma = dataString.indexOf(',');
    String mode;
    String params = "";

    if (firstComma >= 0) {
        mode = dataString.substring(0, firstComma);
        // Ensure there are characters after the comma before creating the params string
        if (dataString.length() > firstComma + 1) {
            params = dataString.substring(firstComma + 1);
        }
    } else {
        mode = dataString; // No comma, the whole string is the mode
    }

    // Attempt to set control mode if it's a valid mode
    if (mode == FOLLOWING || mode == MANUAL || mode == MAPPING) {
        followBotManager.setCurrentControl(mode);
        Serial.println(String("Control mode changed to: ") + mode); // Log after successful mode change

        // Process parameters only if they exist (i.e., firstComma was found) and the mode is set
        if (firstComma >= 0) {
            if (mode == MANUAL) {
                // For manual mode, params is the direction command
                String direction = params;
                Serial.println(String("Direction command received: ") + direction);
                if (direction == MOTOR_FORWARD || direction == MOTOR_BACKWARD || direction == MOTOR_LEFT || direction == MOTOR_RIGHT || direction == MOTOR_STOP) {
                    myMotors.setDirection(direction);
                } else {
                    Serial.println(String("FollowBotClient: Unknown MANUAL command: ") + direction);
                }
            } else if (mode == MAPPING) {
                // For mapping mode, params should be "latitude,longitude"
                int secondComma = params.indexOf(',');
                if (secondComma >= 0) {
                    String latStr = params.substring(0, secondComma);
                    String lonStr = params.substring(secondComma + 1);
                    float lat = latStr.toFloat();
                    float lon = lonStr.toFloat();
                    Serial.print("Mapping coordinates: ");
                    Serial.print(lat, 6);
                    Serial.print(", ");
                    Serial.println(lon, 6);
                    // TODO: send the coordinates to ROS2 to create a path
                } else {
                    Serial.println(String("FollowBotClient: Invalid MAPPING params format: ") + params);
                }
            }
            // No specific parameters are expected for FOLLOWING mode when firstComma >= 0,
            // but the mode has already been set.
        }
        // If firstComma < 0, the mode is set, and there are no parameters to process, which is valid.
    } else {
        Serial.println(String("FollowBotClient: Unknown mode received: ") + mode);
        // If the mode itself is unknown, no action is taken.
    }
}

/**
 * Display current WiFi connection information
 */
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


