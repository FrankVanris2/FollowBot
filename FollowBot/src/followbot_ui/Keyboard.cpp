/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a keyboard
*/

#include "Keyboard.h"
#include "TFT_eSPI.h"
#include "Button.h"
#include "InputBox.h"
#include "FollowBotLCD.h"


Keyboard keyboard;

void Keyboard::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[KBD_BACK_BUTTON] = new Button(tft, 5, 5, 60 , 40, "<--", 10);
    getComponents()[KBD_INPUT_BOX] = new InputBox(tft, 140, 72, 200, "input box", 2, TFT_BLACK);
    getComponents()[BACKSPACE_BUTTON] = new Button(tft, 423, 214, 45, 36, "Del", 1);
    getComponents()[SPACE_BUTTON] = new Button(tft, 383, 260, 80, 36, "Space", 1);
    getComponents()[CAPS_BUTTON] = new Button(tft, 23, 214, 36, 36, "^", 1);
    getComponents()[SPECIAL_CHAR_BUTTON] = new Button(tft, 23, 260, 63, 36, "*^&@", 1);
    
    getComponents()[KBD_NUMBER_1] = new Button(tft, 42, 122, 36, 36, "1", 1);
    getComponents()[KBD_NUMBER_2] = new Button(tft, 82, 122, 36, 36, "2", 1);
    getComponents()[KBD_NUMBER_3] = new Button(tft, 122, 122, 36, 36, "3", 1);
    getComponents()[KBD_NUMBER_4] = new Button(tft, 162, 122, 36, 36, "4", 1);
    getComponents()[KBD_NUMBER_5] = new Button(tft, 202, 122, 36, 36, "5", 1);
    getComponents()[KBD_NUMBER_6] = new Button(tft, 242, 122, 36, 36, "6", 1);
    getComponents()[KBD_NUMBER_7] = new Button(tft, 282, 122, 36, 36, "7", 1);
    getComponents()[KBD_NUMBER_8] = new Button(tft, 322, 122, 36, 36, "8", 1);
    getComponents()[KBD_NUMBER_9] = new Button(tft, 362, 122, 36, 36, "9", 1);
    getComponents()[KBD_NUMBER_0] = new Button(tft, 402, 122, 36, 36, "0", 1);

    getComponents()[KBD_q] = new Button(tft, 42, 168, 36, 36, "q", 1);
    getComponents()[KBD_w] = new Button(tft, 82, 168, 36, 36, "w", 1);
    getComponents()[KBD_e] = new Button(tft, 122, 168, 36, 36, "e", 1);
    getComponents()[KBD_r] = new Button(tft, 162, 168, 36, 36, "r", 1);
    getComponents()[KBD_t] = new Button(tft, 202, 168, 36, 36, "t", 1);
    getComponents()[KBD_y] = new Button(tft, 242, 168, 36, 36, "y", 1);
    getComponents()[KBD_u] = new Button(tft, 282, 168, 36, 36, "u", 1);
    getComponents()[KBD_i] = new Button(tft, 322, 168, 36, 36, "i", 1);
    getComponents()[KBD_o] = new Button(tft, 362, 168, 36, 36, "o", 1);
    getComponents()[KBD_p] = new Button(tft, 402, 168, 36, 36, "p", 1);

    getComponents()[KBD_a_A_EXLAMATION] = new Button(tft, 63, 214, 36, 36, "a", 1);
    getComponents()[KBD_s] = new Button(tft, 103, 214, 36, 36, "s", 1);
    getComponents()[KBD_d] = new Button(tft, 143, 214, 36, 36, "d", 1);
    getComponents()[KBD_f] = new Button(tft, 183, 214, 36, 36, "f", 1);
    getComponents()[KBD_g] = new Button(tft, 223, 214, 36, 36, "g", 1);
    getComponents()[KBD_h] = new Button(tft, 263, 214, 36, 36, "h", 1);
    getComponents()[KBD_j] = new Button(tft, 303, 214, 36, 36, "j", 1);
    getComponents()[KBD_k] = new Button(tft, 343, 214, 36, 36, "k", 1);
    getComponents()[KBD_l] = new Button(tft, 383, 214, 36, 36, "l", 1);

    getComponents()[KBD_z] = new Button(tft, 103, 260, 36, 36, "z", 1);
    getComponents()[KBD_x] = new Button(tft, 143, 260, 36, 36, "x", 1);
    getComponents()[KBD_c] = new Button(tft, 183, 260, 36, 36, "c", 1);
    getComponents()[KBD_v] = new Button(tft, 223, 260, 36, 36, "v", 1);
    getComponents()[KBD_b] = new Button(tft, 263, 260, 36, 36, "b", 1);
    getComponents()[KBD_n] = new Button(tft, 303, 260, 36, 36, "n", 1);
    getComponents()[KBD_m] = new Button(tft, 343, 260, 36, 36, "m", 1);

}

void Keyboard::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool Keyboard::touchScreenEvent(int x, int y) {
    KeyboardButtons selected = getComponentForTouch(x, y);

    switch(selected) {
        case KBD_BACK_BUTTON:
            Serial.println("Back button pressed");
            myLCDScreen.setCurrentFrame(SSID_SCREEN);
            return true;
    }

    if (KBD_NUMBER_0 <= selected && selected <= KBD_NUMBER_9) {
        char chr = static_cast<char>('0' + (selected - KBD_NUMBER_0));
        Serial.println(String(chr) + " is pressed");
        return true;
    }

    return false;
}