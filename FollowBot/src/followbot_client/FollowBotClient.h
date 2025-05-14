/*
 * FollowBotClient.h
 * By: Frank Vanris
 * Date: 8/21/2024
 * 
 * Description:
 * Client interface for robot communication with a central server.
 * Handles WiFi connectivity, data transmission, and command processing
 * for interaction between the robot, website, and mobile application.
 */

#pragma once
#include <Arduino.h>

/**
 * FollowBotClient Class
 * 
 * Manages WiFi connectivity and HTTP communication with a central server.
 * Provides methods to send sensor data to the server and process incoming commands.
 * Implements automatic reconnection and signal strength monitoring.
 */
class FollowBotClient {
public:
    /**
     * Constructor - initializes connection settings and state variables
     */
    FollowBotClient();

    /**
     * Initialize WiFi connection and prepare for communication
     * Called once during system initialization
     */
    void followBotClient_Setup();

    /**
     * Main update loop for client operations
     * Handles periodic updates, server communication, and command processing
     * Should be called regularly from the main program loop
     */
    void followBotClient_Loop();

    /**
     * Get the current WiFi signal strength
     * 
     * @return Signal strength in dBm (negative number, closer to 0 is stronger)
     */
    long getRSSI() {
        return mRSSI;
    }

    /**
     * Update and monitor WiFi signal strength
     */
    void checkRSSI();

    /**
     * Check if client is connected to WiFi network
     * 
     * @return true if connected, false otherwise
     */
    bool isConnected() {
        return mIsConnected;
    }
    
    
private:
    /**
     * Display WiFi connection information to serial monitor
     */
    void printWifiStatus();

    /**
     * Send robot status information to server
     * 
     * @return true if transmission was successful, false otherwise
     */
    bool postRobotInfo();

    /**
     * Retrieve action commands from server
     * 
     * @return String containing command data from server
     */
    String getActionData();

    /**
     * Process received action commands
     * Handles mode changes and control commands from server
     * 
     * @param dataString Raw command string from server
     */
    void handleActionData(String dataString);

    // Timing variables
    unsigned long mPreviousMillisMove;  // Last communication timestamp
    unsigned long lastServerCheck;      // Last server check timestamp

    // Connection state
    bool mIsConnected;              // WiFi connection state
    int mCountMoves;                // Count of movement commands
    int mWifiConnectionStatus;      // WiFi status code
    int mServerNotConnectedCnt;     // Failed connection counter
    long mRSSI;                     // Signal Strength in dBm   
    String mIPAddress;              // Server IP address
};

// Global singleton instance
extern FollowBotClient followBotClient;