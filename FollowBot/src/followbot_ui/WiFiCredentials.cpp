/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a SSID screen where user inputs ssid info and it gets stored in the EEPROM
*/


#include "WiFiCredentials.h"
#include "TFT_eSPI.h"
#include "Button.h"
#include "InputBox.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"
#include "TextBase.h"
#include "Keyboard.h"
#include "secrets/EEPROMStorage.h"


//Universal Object
WiFiCredentials wifiCredentials;

void WiFiCredentials::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[WIFI_BACK_BUTTON] = new Button(tft, 5, 5, 60 , 40, "<--", 10);

    getComponents()[WIFI_SSID_TEXT] = new TextBase(tft, 50, 87, "Input SSID:"); 
    getComponents()[WIFI_SSID_INPUT_BOX] = new InputBox(tft, 200, 80, 200, "");

    getComponents()[WIFI_PASSWORD_TEXT] = new TextBase(tft, 50, 137, "Input Pass:");
    getComponents()[WIFI_PASSWORD_INPUT_BOX] = new InputBox(tft, 200, 130, 200, "");

    getComponents()[WIFI_SAVE_BUTTON] = new Button(tft, 140, 200, 200, 50, "Save", 10);
    getComponents()[WIFI_SAVE_TEXT] = new TextBase(tft, 200, 260, "");
    
    getComponents()[WIFI_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[WIFI_TEXT_WAIT])->setHide(true);

}

void WiFiCredentials::draw() {
    const String& ssid = eepromStorage.getSSID();
    const String& password = eepromStorage.getPassword();
    ((InputBox*) getComponents()[WIFI_SSID_INPUT_BOX])->setText(ssid);
    ((InputBox*) getComponents()[WIFI_PASSWORD_INPUT_BOX])->setText(password);
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool WiFiCredentials::touchScreenEvent(int x, int y) {
    ((TextBase*) getComponents()[WIFI_SAVE_TEXT])->setTextAndDraw("");
    
    WiFiCredentialsFrameComponents selected = getComponentForTouch(x, y);
    switch(selected) {
        case WIFI_BACK_BUTTON:
            Serial.println("SSID Back button pressed");
            ((TextBase*) getComponents()[WIFI_TEXT_WAIT])->setHide(false);
            getComponents()[WIFI_TEXT_WAIT]->draw();
            myLCDScreen.setCurrentFrame(MAIN_SCREEN);
            ((TextBase*) getComponents()[WIFI_TEXT_WAIT])->setHide(true);
            return true;

        case WIFI_SSID_INPUT_BOX:
            Serial.println("Input box pressed");
            ((TextBase*) getComponents()[WIFI_TEXT_WAIT])->setHide(false);
            getComponents()[WIFI_TEXT_WAIT]->draw();
            keyboard.setInputAndCallback(eepromStorage.getSSID(), WIFI_CREDENTIALS_SCREEN, std::bind(&WiFiCredentials::setSSID, this, std::placeholders::_1));
            myLCDScreen.setCurrentFrame(KEYBOARD_SCREEN);
            ((TextBase*) getComponents()[WIFI_TEXT_WAIT])->setHide(true);
            return true;
        
        case WIFI_PASSWORD_INPUT_BOX:
            Serial.println("Input box pressed");
            ((TextBase*) getComponents()[WIFI_TEXT_WAIT])->setHide(false);
            getComponents()[WIFI_TEXT_WAIT]->draw();
            keyboard.setInputAndCallback(eepromStorage.getPassword(), WIFI_CREDENTIALS_SCREEN, std::bind(&WiFiCredentials::setPassword, this, std::placeholders::_1));
            myLCDScreen.setCurrentFrame(KEYBOARD_SCREEN);
            ((TextBase*) getComponents()[WIFI_TEXT_WAIT])->setHide(true);
            return true;
        
        case WIFI_SAVE_BUTTON:
            Serial.println("Save button pressed");
            eepromStorage.saveWiFiCredentials();
            ((TextBase*) getComponents()[WIFI_SAVE_TEXT])->setTextAndDraw("Saved");
            return true;
    }
    return false;
}

void WiFiCredentials::setSSID(const String& ssid) {
    ((InputBox*) getComponents()[WIFI_SSID_INPUT_BOX])->setText(ssid);
    eepromStorage.setSSID(ssid);
}


void WiFiCredentials::setPassword(const String& password) {
    ((InputBox*) getComponents()[WIFI_PASSWORD_INPUT_BOX])->setText(password);
    eepromStorage.setPassword(password);
}
    