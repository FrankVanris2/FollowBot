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

// Universal Object
FollowBotClient followBotClient;

//sensitive information
char ssid[] = SECRET_SSID;
// char pass[] = SECRET_PASS;

// Interval
const int INTERVAL = 1000;

// If you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(10, 12, 1, 195); // numeric IP for Google (no DNS)
//IPAddress server(10, 0, 0, 245); // numeric IP for Google (no DNS)
// char server[] = "www.google.com";       // Name address for Google (using DNS)

// Initializing the Ethernet client library
// With the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

// Constructor
FollowBotClient::FollowBotClient(): mConnectionStatus(WL_IDLE_STATUS), mPreviousMillis(0) {}

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
        mConnectionStatus = WiFi.begin(ssid); //pass for huis

        // wait 1 seconds for connection:
        delay(1000);
    }

    printWifiStatus(); 
}

void FollowBotClient::followBotClient_Loop() {
    unsigned long currentMillis = millis();
    if((unsigned long) (currentMillis - mPreviousMillis) >= INTERVAL) {
        mPreviousMillis = currentMillis;
        getMove();
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

void FollowBotClient::getMove() {
    if (client.connect(server, 5000)) { //originally 80
        Serial.println("connected to server");
        client.println("GET /move");
        client.println("Host: 10.12.1.195");
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