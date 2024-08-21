/*
* By: Frank Vanris
* Date: 8/20/2024
* Desc: Creating wifi access to the arduino board so we can wirelessly download sketches into the board*/


#include "FollowBotWifi.h"
#include "WiFiS3.h"

// Universal Object
FollowBotWifi followBotWifi;

//setting up server
WiFiServer server(80);

// Setting my constructor
FollowBotWifi::FollowBotWifi() : ssid("followBotv1"), password("robotics101"), keyIndex(0), status(WL_IDLE_STATUS) {}

// Setup for Wifi
void FollowBotWifi::followBotWifi_Setup() {
    while(!Serial) {
        // Wait for serial port to connect. Needed for native USB port only
    }

    Serial.println("Access Point Web Server");

    // Checking for the WiFi Module:
    if(WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module  failed");

        // Don't Continue
        while(true);
    }

    String fv = WiFi.firmwareVersion();
    if(fv < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }

    // By default the local IP address will be 192.168.4.1
    // You can override it with the following:
    WiFi.config(IPAddress(192, 48, 56, 2));

    // Print the network name (SSID);
    Serial.print("Creating access point named: ");
    Serial.println(ssid);

    // Create open network. Change this line if you want to create an WEP network:
    status = WiFi.beginAP(ssid, password);
    if(status != WL_AP_LISTENING) {
        Serial.println("Creating access point failed");

        // Don't continue
        while(true);
    }

    // Wait 10 seconds for connection
    delay(10000);

    // Start the web server on port 80
    server.begin();

    // You're connected now, so print out the status
    printWiFiStatus();

}

void FollowBotWifi::followBotWifi_Loop() {
    // Compare the previous status to the current status
    if(status != WiFi.status()) {
        // It has changed update the variable
        status = WiFi.status();

        if (status == WL_AP_CONNECTED) {
            // A device has connected to the AP
            Serial.println("Device connected to AP");
        } else {
            // A device has disconnected from the AP, and we are back in listening mode
            Serial.println("Device disconnected from AP");
        }
    }

    WiFiClient client = server.available();     // Listen for incoming clients

    if (client) {
        Serial.println("new client");
        String currentLine = "";
        while(client.connected()) {
            delayMicroseconds(10);
            if(client.available()) {
                char c = client.read();
                Serial.write(c);
                if(c == '\n') {

                    if(currentLine.length() == 0) {

                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();

                        // the content of the HTTP response follows the header:
                        client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn the LED on<br></p>");
                        client.print("<p style=\"font-size:7vw;\">Click <a href=\"/L\">here</a> turn the LED off<br></p>");

                        // The HTTP response ends with another blank line:
                        client.println();
                        
                        // Break out of the while loop:
                        break;

                    }
                    else {
                        currentLine = "";  // if you got a newline, then clear currentLine:
                    }
                }

                else if (c != '\r') {   // if you got anything else but a carriage return character,
                    currentLine += c;   // add it to the end of the currentLine
                }

                // Check to see if the client request was "GET /H" or "GET /L":
                if(currentLine.endsWith("GET /H")) {
                    Serial.println("Light is on");  // Turns LED on
                }
                if(currentLine.endsWith("GET /L")) {
                    Serial.println("Light is off"); // Turns LED off
                }
            }
        }

        // Close the connection:
        client.stop();
        Serial.println("client disconnected");
    }
}


void FollowBotWifi::printWiFiStatus() {
    // Print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // Print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // Print where to go in a browser:
    Serial.print("To see this page in action, open a browser to http://");
    Serial.println(ip);
}