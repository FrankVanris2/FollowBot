/*
By: Frank Vanris
Date: 9/16/2024
Desc: Creating a captive portal in order to input your network credentials towards the robot
*/

#include "FollowBotCaptivePortal.h"
#include <WiFiS3.h>

// Universal Object
CaptivePortal captivePortal;

char ap_ssid[] = "FollowBot_v1";

int status = WL_IDLE_STATUS;
WiFiServer captivePortalServer(8080);


CaptivePortal::CaptivePortal() {}

void CaptivePortal::captivePortal_Setup() {
    // Setting up AP mode:
    Serial.println("Access Point Web Server");

    // Printing the network name (SSID);
    Serial.print("Creating access point named: ");
    Serial.println(ap_ssid);

    // Create open network. 
    status = WiFi.beginAP(ap_ssid);
    if(status != WL_AP_LISTENING) {
        Serial.println("Creating access point failed");
        // don't continue
        while (true);
    }

    Serial.println("Access Point started");
    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());


    // Starting the web server on port 8080
    captivePortalServer.begin();
    Serial.println("Servers started");

    // Your connected now, so print out the status


}

void CaptivePortal::captivePortal_Loop() {
    WiFiClient captiveClient = captivePortalServer.available();
    if (captiveClient) {
        handleCaptivePortal(captiveClient);
    }
}

void CaptivePortal::handleCaptivePortal(WiFiClient client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title> Captive Portal</title></head>");
    client.println("<body>");
    client.println("<h1>Heading Testing</h1>");
    client.println("<p> paragraph testing </p>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
}

