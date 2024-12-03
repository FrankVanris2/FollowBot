/*
* By: Frank Vanris
* Date: 8/21/2024
* Desc: Creating a client in which I will be able to send information up to the server and the server 
* will be able to send information up to the website and the mobile app
*/

#include "FollowBotClient.h"
#include "motors/Motors.h"
#include "WiFiS3.h"
#include "secrets/FollowBot_Secrets.h"
#include "followbot_manager/FollowBotManager.h"
#include "states&types/DataStates.h"
#include "ArduinoJson.h"

// Universal Object
FollowBotClient followBotClient;

//sensitive information
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

// Interval
const int TENTH_SECOND = 100;
const int HALF_SECOND = 500;
const int SECOND = 1000;
const int TEN_SECONDS = 10000;
const int SIXTY_SECONDS = 60000;
const int MAX_SERVER_NOT_CONNECTED = 3;


//My Json creator
 StaticJsonDocument<200> robotInformationJson;

// Server IP address
//IPAddress server(3, 145, 197, 165); // numeric IP for Google (no DNS)
IPAddress server(10, 0, 0, 245); // numeric IP for Google (no DNS)
const int PORT = 5000;

// WiFi client
WiFiClient client;

// Constructor
FollowBotClient::FollowBotClient(): mWifiConnectionStatus(WL_IDLE_STATUS), mPreviousMillisMove(0), mCountMoves(0), 
mIPAddress(server.toString()), mRSSI(0), lastServerCheck(0), mServerNotConnected(0) {
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
    while(mWifiConnectionStatus != WL_CONNECTED && millis() - startAttemptTime < SIXTY_SECONDS) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        mWifiConnectionStatus = WiFi.begin(ssid, pass); //pass for private networks

        // non-blocking delay:
        delay(100);
    }

    if(mWifiConnectionStatus == WL_CONNECTED) {
        printWifiStatus();
    } else {
        Serial.println("Failed to connect to Wifi");
    }
    
}

void FollowBotClient::followBotClient_Loop() {
    int intervalTime = mServerNotConnected < MAX_SERVER_NOT_CONNECTED ? TENTH_SECOND : TEN_SECONDS;
    

    if((unsigned long) (millis() - mPreviousMillisMove) >= intervalTime) {
        mPreviousMillisMove = millis();

        // Check WiFi connection status 
        if(WiFi.status() != WL_CONNECTED) {
            mWifiConnectionStatus = WL_DISCONNECTED;
            Serial.println("FollowBotClient, Wifi disconnected");
        } else {
            mWifiConnectionStatus = WL_CONNECTED;
            Serial.println("FollowBotClient, Wifi connected");
        }

        if(mWifiConnectionStatus == WL_CONNECTED) {
            if (!getMove()) return;
            if(followBotManager.getDirtyFlag()) {
                if (!postRobotInfo()) return;
            }
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
        if(mServerNotConnected < MAX_SERVER_NOT_CONNECTED) {
            mServerNotConnected++;
        }
        return false;
    }
    Serial.println("FollowBotClient.postRobotInfo(): Server connected");
    mServerNotConnected = 0;

    const OutputData& outputData = followBotManager.getOutputData();
        
    //Adding given components to json object
    robotInformationJson["temperature"] = outputData.mTemperature;
    robotInformationJson["heatIndex"] = outputData.mHeatIndex;
    String outputDataStr;
    serializeJson(robotInformationJson, outputDataStr);

    //Serial.println("connected to server");
    client.println("POST /api/robotinfo HTTP/1.1");
    client.print("Host: "); // main server is 3.145.197.165
    client.println(mIPAddress);
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(outputDataStr.length());
    client.println();
    client.println(outputDataStr);
    client.println("Connection: close");
    client.println(); 
    client.stop();

    return true;
}

bool FollowBotClient::getMove() {
    Serial.println("FollowBotClient.getMove(): Connecting to server...") ;
    if(!client.connect(server, PORT)) {
        Serial.println("FollowBotClient.getMove(): Server did not connect");
        if(mServerNotConnected < MAX_SERVER_NOT_CONNECTED) {
            mServerNotConnected++;
        }
        return false;
    }
    Serial.println("FollowBotClient.getMove(): Server connected");
    mServerNotConnected = 0;

    // get the information to make the robot move
    client.println("GET /api/getmove HTTP/1.1");
    client.print("Host: ");
    client.println(mIPAddress);
    client.println("Connection: close");
    client.println();

    String direction;
    const int SIZE = 1024;
    char buffer[SIZE];
    int bufLength = 0;
    int bodyIdx = 0;
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
        
        direction = buffer + bodyIdx;  
    } 
    client.stop();

    Serial.print("Direction: ");
    Serial.println(direction);
    myMotors.setDirection(direction);
}

void FollowBotClient::checkRSSI() {
    // The RSSI check is now handled by the FreeRTOS task
    mRSSI = WiFi.RSSI();
    Serial.print("FollowBotClient, mRSSI = ");
    Serial.println(mRSSI);
}
