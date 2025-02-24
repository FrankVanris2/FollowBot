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
#include "secrets/SecureWifiCredentials.h"


//Universal Object
WiFiCredentials wifiCredentials;

void WiFiCredentials::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[BACK_BUTTON] = new Button(tft, 5, 5, 60 , 40, "<--", 10);
    getComponents()[SSID_TEXT] = new TextBase(tft, 50, 87, "Input SSID:");
    getComponents()[PASSWORD_TEXT] = new TextBase(tft, 50, 137, "Input Pass:");
    getComponents()[SSID_INPUT_BOX] = new InputBox(tft, 200, 80, 200, "");
    getComponents()[PASSWORD_INPUT_BOX] = new InputBox(tft, 200, 130, 200, "");
    getComponents()[CRED_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[CRED_TEXT_WAIT])->setHide(true);
}

void WiFiCredentials::draw() {
    const String& ssid = secureWifiCredentials.getSSID();
    const String& password = secureWifiCredentials.getPassword();
    ((InputBox*) getComponents()[SSID_INPUT_BOX])->setText(ssid);
    ((InputBox*) getComponents()[PASSWORD_INPUT_BOX])->setText(password);
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool WiFiCredentials::touchScreenEvent(int x, int y) {
    WiFiCredentialsFrameComponents selected = getComponentForTouch(x, y);
    switch(selected) {
        case BACK_BUTTON:
            Serial.println("SSID Back button pressed");
            ((TextBase*) getComponents()[CRED_TEXT_WAIT])->setHide(false);
            getComponents()[CRED_TEXT_WAIT]->draw();
            myLCDScreen.setCurrentFrame(MAIN_SCREEN);
            ((TextBase*) getComponents()[CRED_TEXT_WAIT])->setHide(true);
            return true;

        case SSID_INPUT_BOX:
            Serial.println("Input box pressed");
            ((TextBase*) getComponents()[CRED_TEXT_WAIT])->setHide(false);
            getComponents()[CRED_TEXT_WAIT]->draw();
            keyboard.setInputAndCallback(secureWifiCredentials.getSSID(), WIFI_CREDENTIALS_SCREEN, std::bind(&WiFiCredentials::setSSID, this, std::placeholders::_1));
            myLCDScreen.setCurrentFrame(KEYBOARD_SCREEN);
            ((TextBase*) getComponents()[CRED_TEXT_WAIT])->setHide(true);
            return true;
        
        case PASSWORD_INPUT_BOX:
            Serial.println("Input box pressed");
            ((TextBase*) getComponents()[CRED_TEXT_WAIT])->setHide(false);
            getComponents()[CRED_TEXT_WAIT]->draw();
            keyboard.setInputAndCallback(secureWifiCredentials.getPassword(), WIFI_CREDENTIALS_SCREEN, std::bind(&WiFiCredentials::setPassword, this, std::placeholders::_1));
            myLCDScreen.setCurrentFrame(KEYBOARD_SCREEN);
            ((TextBase*) getComponents()[CRED_TEXT_WAIT])->setHide(true);
            return true;
    }
    return false;
}

void WiFiCredentials::setSSID(const String& ssid) {
    ((InputBox*) getComponents()[SSID_INPUT_BOX])->setText(ssid);
    secureWifiCredentials.setSSID(ssid);
}


void WiFiCredentials::setPassword(const String& password) {
    ((InputBox*) getComponents()[PASSWORD_INPUT_BOX])->setText(password);
    secureWifiCredentials.setPassword(password);
}
    