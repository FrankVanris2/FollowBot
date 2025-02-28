/*
* By: Frank Vanris
* Date: 8/27/2024
* Desc: Creating a temperature reader for the robot
*/

#include <DHT.h>
#include "TemperatureReader.h"
#include "followbot_client/FollowBotClient.h"
#include "followbot_manager/FollowBotManager.h"


#define DHTPIN 6
#define DHTTYPE DHT11

const int TEN_SECONDS = 10000;

// Universal object
TemperatureReader temperatureReader;

//dht object
DHT dht(DHTPIN, DHTTYPE);

// Constructor
TemperatureReader::TemperatureReader(): previousMillis(0)  {}

// Temperature Setup
void TemperatureReader::temperatureReader_Setup() {
    Serial.println("Temperature Reader Setup");
    dht.begin();
}

// Temperature Loop
void TemperatureReader::temperatureReader_Loop() {
    if ((unsigned long) (millis() - previousMillis) >= TEN_SECONDS) {
        previousMillis = millis();

        // Every Second I read the dht11 sensor
        float hum = dht.readHumidity();
        float tmp = dht.readTemperature();

        //Check if any reads fails and exit early
        if(isnan(hum) || isnan(tmp)) {
            Serial.println(F("Failed to read from DHT sensor!"));
            return;
        }

        //Compute heat index in Celcius
        float hic = dht.computeHeatIndex(tmp, hum, false);

        Serial.print(F("Temperature: "));
        Serial.print(tmp);
        Serial.print(F("°C"));
        Serial.println();
        Serial.print(F("Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.println();
        followBotManager.setTemperatureParams(tmp, hic);
    }
}
