/*
* By: Frank Vanris
* Date: 8/27/2024
* Desc: Creating a temperature reader for the robot
*/

#include "TemperatureReader.h"
#include "FollowBotClient.h"
#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11

// Universal object
TemperatureReader temperatureReader;

//dht object
DHT dht(DHTPIN, DHTTYPE);

// Constructor
TemperatureReader::TemperatureReader(): interval(10000), previousMillis(0)  {}

// Temperature Setup
void TemperatureReader::temperatureReader_Setup() {
    Serial.println("Testing DHT");
    dht.begin();
}

// Temperature Loop
void TemperatureReader::temperatureReader_Loop() {
    if ((unsigned long) (millis() - previousMillis) >= interval) {
        previousMillis = millis();

        // Every Second I read the dht11 sensor

        float h = dht.readHumidity();
        float t = dht.readTemperature();

        //Check if any reads fails and exit early
        if(isnan(h) || isnan(t)) {
            Serial.println(F("Failed to read from DHT sensor!"));
            return;
        }

        //Compute heat index in Celcius
        float hic = dht.computeHeatIndex(t, h, false);

        Serial.print(F("Humidity: "));
        Serial.print(h);
        Serial.print(F("% Temperature: "));
        Serial.print(t);
        Serial.print(F("°C "));
        Serial.print(F("Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.println();

        // Sending temperature to server
        followBotClient.sendTemp(t);
    }
}
