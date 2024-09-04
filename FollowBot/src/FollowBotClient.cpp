/*
* By: Frank Vanris
* Date: 8/21/2024
* Desc: Creating a client in which I will be able to send information up to the server and the server 
* will be able to send information up to the website and the mobile app
*/

#include "FollowBotClient.h"
#include "Motors.h"
#include "WiFiS3.h"
#include "FollowBot_Secrets.h"
#include "FollowBotManager.h"
#include "MotorControlStates.h"
#include "ArduinoJson.h"

// Universal Object
FollowBotClient followBotClient;

//sensitive information
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

// Interval
const int ONE_SECOND = 1000;


//My Json creator
 StaticJsonDocument<200> robotInformationJson;

// If you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(3, 145, 197, 165); // numeric IP for Google (no DNS)
//IPAddress server(10, 0, 0, 245); // numeric IP for Google (no DNS)
// char server[] = "www.google.com";       // Name address for Google (using DNS)

// Initializing the Ethernet client library
// With the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

// Constructor
FollowBotClient::FollowBotClient(): mConnectionStatus(WL_IDLE_STATUS), mPreviousMillis(0), mCountMoves(0) {}

void FollowBotClient::followBotClient_Setup() {
    while(!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    String firmVersion = WiFi.firmwareVersion();
    if(firmVersion < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }

    // check for the WiFi module:
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");  
    }

    // Attempt to connect to WiFi network;
    while(mConnectionStatus != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        mConnectionStatus = WiFi.begin(ssid, pass); //pass for huis

        // wait 1 seconds for connection:
        delay(1000);
    }

    printWifiStatus(); 
}

void FollowBotClient::followBotClient_Loop() {
    //Movement will run for at most 10 seconds until stopping

    /*if(mCountMoves > 10) {
        while(true) {
            myMotors.motorStop();
        }
    }*/
    unsigned long currentMillis = millis();   

    if((unsigned long) (currentMillis - mPreviousMillis) >= ONE_SECOND) {
        mPreviousMillis = currentMillis;
        //mCountMoves++;
        infoExchange();

    }  
    
}

void FollowBotClient::printWifiStatus() {
    // Print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // Print your board's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // Print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI): ");
    Serial.print(rssi);
    Serial.println(" dBm");
}

void FollowBotClient::infoExchange() {
    if (client.connect(server, 80)) { //originally 80
        const OutputData& outputData = followBotManager.getOutputData();
        
        //Adding given components to json object
        robotInformationJson["temperature"] = outputData.mTemperature;
        robotInformationJson["heatIndex"] = outputData.mHeatIndex;
        String outputDataStr;
        serializeJson(robotInformationJson, outputDataStr);

        Serial.println("connected to server");
        client.println("POST /temp HTTP/1.1");
        client.println("Host: 3.145.197.165");
        client.println("Content-Type: application/json");
        client.print("Content-Length: ");
        client.println(outputDataStr.length());
        client.println();
        client.println(outputDataStr);
        client.println("Connection: close");
        client.println(); 

        String direction;
        while (true) {
            const int SIZE = 20;
            char buffer[SIZE];
            int numChars = client.read(reinterpret_cast<uint8_t*>(buffer), SIZE);
            buffer[numChars] = 0;

            Serial.println(numChars);
            Serial.println(buffer);
            
            if(numChars > 0) {
                direction = buffer;
                break;
            }       
        }

        followBotManager.setDirection(direction);
        client.stop();
    }
}