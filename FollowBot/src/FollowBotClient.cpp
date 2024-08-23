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

// Universal Object
FollowBotClient followBotClient;

//sensitive information
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

// If you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(10, 12, 0, 195); // numeric IP for Google (no DNS)
// char server[] = "www.google.com";       // Name address for Google (using DNS)

// Initializing the Ethernet client library
// With the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

// Constructor
FollowBotClient::FollowBotClient(): keyIndex(0), status(WL_IDLE_STATUS), interval(1000), previousMillis(0) {}

void FollowBotClient::followBotClient_Setup() {
    while(!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // check for the WiFi module:
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        // don't continue
        while(true);
    }

    String fv = WiFi.firmwareVersion();
    if(fv < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }

    // Attempt to connect to WiFi network;
    while(status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid);

        // wait 10 seconds for connection:
        delay(10000);
    }

    printWifiStatus();

    Serial.println("\nStarting connection to server...");

    // If you get a connection, report back via serial:
    /*
    if (client.connect(server, 5000)) { //originally 80
        Serial.println("connected to server");

        //Make a HTTP request:
        //testGet();
        
        testGetMove();
        client.println("Host: 10.12.0.195");
        client.println("Connection: close");
        client.println();
        
    }
    */
}

void FollowBotClient::followBotClient_Loop() {
    //test_read_response();
    
    if((unsigned long) (millis() - previousMillis) >= interval) {
        previousMillis = millis();

            testGetMove();
            client.println("Host: 10.12.0.195");
            client.println("Connection: close");
            client.println();


        test_read_robotMovement();

        // If the server's disconnected, stop the client:
        if (!client.connected()) {
            Serial.println();
            Serial.println("disconnecting from server.");
            client.stop();

            // do nothing forevermore:
            //while (true);
        }
    }
        
}

void FollowBotClient::test_read_response() {
    uint32_t received_data_num = 0;
    while(client.available()) {

        /* actual data reception*/
        char c = client.read();

        /* print data to serial port */
        Serial.print(c);

        /* wrap data to 80 columns*/
        received_data_num++;
        if(received_data_num % 80 == 0) {
            Serial.println();
        }
    }
}

void FollowBotClient:: test_read_robotMovement() {
    while(client.available()) {

        /* actual data reception*/
        const int SIZE = 20;
        char buffer[SIZE];
        int numChars = client.read(reinterpret_cast<uint8_t*>(buffer), SIZE);
        buffer[numChars] = 0;

        Serial.println(numChars);
        Serial.println(buffer);

        myMotors.motorClientTesting(buffer);

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

// Testing mechanics
void FollowBotClient::testGet() {
    client.println("GET /");
}

void FollowBotClient::testGetMove() {
    client.println("GET /move");
}