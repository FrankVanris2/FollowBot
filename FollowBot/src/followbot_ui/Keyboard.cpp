/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a keyboard
*/

#include <TFT_eSPI.h>

#include "Keyboard.h"
#include "Button.h"
#include "InputBox.h"
#include "FollowBotLCD.h"


Keyboard keyboard;

void Keyboard::setInputAndCallback(const String& input, ScreenFrames screenFrame, std::function<void(const String&)> callback) {
    ((TextBase*) getComponents()[KBD_INPUT_BOX])->setText(input);
    mScreenFrame = screenFrame;
    mCallback = callback;
}

void Keyboard::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[KBD_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[KBD_TEXT_WAIT])->setHide(true);

    getComponents()[KBD_BACK_BUTTON] = new Button(tft, 5, 5, 60 , 40, "<--", 10);
    getComponents()[KBD_INPUT_BOX] = new InputBox(tft, 115, 72, 250);
    getComponents()[KBD_BACKSPACE_BUTTON] = new Button(tft, 423, 214, 45, 36, "Del", 1);
    getComponents()[KBD_SPACE_BUTTON] = new Button(tft, 383, 260, 80, 36, "Space", 1);
    getComponents()[KBD_CAPS_BUTTON] = new Button(tft, 23, 214, 36, 36, "^", 1);
    getComponents()[KBD_SPECIAL_CHAR_BUTTON] = new Button(tft, 23, 260, 63, 36, "*^&@", 1);
    getComponents()[KBD_ALPHABET_CHAR_BUTTON] = new Button(tft, 23, 260, 63, 36, "abc", 1);

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

    getComponents()[KBD_q_Q_LSQUAREBRACE] = new Button(tft, 42, 168, 36, 36, "q", 1);
    getComponents()[KBD_w_W_LESSTHAN] = new Button(tft, 82, 168, 36, 36, "w", 1);
    getComponents()[KBD_e_E_PERCENT] = new Button(tft, 122, 168, 36, 36, "e", 1);
    getComponents()[KBD_r_R_RSQUAREBRACE] = new Button(tft, 162, 168, 36, 36, "r", 1);
    getComponents()[KBD_t_T_VERTICALBAR] = new Button(tft, 202, 168, 36, 36, "t", 1);
    getComponents()[KBD_y_Y_QUESTION] = new Button(tft, 242, 168, 36, 36, "y", 1);
    getComponents()[KBD_u_U_COLON] = new Button(tft, 282, 168, 36, 36, "u", 1);
    getComponents()[KBD_i_I_LPARENTHESIS] = new Button(tft, 322, 168, 36, 36, "i", 1);
    getComponents()[KBD_o_O_SLASH] = new Button(tft, 362, 168, 36, 36, "o", 1);
    getComponents()[KBD_p_P_COLON] = new Button(tft, 402, 168, 36, 36, "p", 1);

    getComponents()[KBD_a_A_EXLAMATION] = new Button(tft, 63, 214, 36, 36, "a", 1);
    getComponents()[KBD_s_S_BACKSLASH] = new Button(tft, 103, 214, 36, 36, "s", 1);
    getComponents()[KBD_d_D_DOLLAR] = new Button(tft, 143, 214, 36, 36, "d", 1);
    getComponents()[KBD_f_F_CARET] = new Button(tft, 183, 214, 36, 36, "f", 1);
    getComponents()[KBD_g_G_AMPERSAND] = new Button(tft, 223, 214, 36, 36, "g", 1);
    getComponents()[KBD_h_H_ASTERISK] = new Button(tft, 263, 214, 36, 36, "h", 1);
    getComponents()[KBD_j_J_RPARENTHESIS] = new Button(tft, 303, 214, 36, 36, "j", 1);
    getComponents()[KBD_k_K_UNDERSCORE] = new Button(tft, 343, 214, 36, 36, "k", 1);
    getComponents()[KBD_l_L_PLUS] = new Button(tft, 383, 214, 36, 36, "l", 1);

    getComponents()[KBD_z_Z_ATSIGN] = new Button(tft, 103, 260, 36, 36, "z", 1);
    getComponents()[KBD_x_X_GREATERTHAN] = new Button(tft, 143, 260, 36, 36, "x", 1);
    getComponents()[KBD_c_C_HASHTAG] = new Button(tft, 183, 260, 36, 36, "c", 1);
    getComponents()[KBD_v_V_SEMICOLON] = new Button(tft, 223, 260, 36, 36, "v", 1);
    getComponents()[KBD_b_B_QUOTES] = new Button(tft, 263, 260, 36, 36, "b", 1);
    getComponents()[KBD_n_N_DOT] = new Button(tft, 303, 260, 36, 36, "n", 1);
    getComponents()[KBD_m_M_MINUS] = new Button(tft, 343, 260, 36, 36, "m", 1);

}

void Keyboard::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool Keyboard::touchScreenEvent(int x, int y) {
    KeyboardButtons selected = getComponentForTouch(x, y);

    switch(selected) {
        case KBD_BACK_BUTTON:
            handleBackButton();
            return true;
        
        case KBD_CAPS_BUTTON:
            Serial.println("CAPS button pressed");
            selectKeyboardMode(KBD_CAPS_BUTTON);
            return true;
        
        case KBD_SPECIAL_CHAR_BUTTON:
            Serial.println("SPECIAL CHAR button pressed");
            selectKeyboardMode(KBD_SPECIAL_CHAR_BUTTON);
            return true;
        
        case KBD_BACKSPACE_BUTTON:
            Serial.println("BACKSPACE button pressed");
            handleBackSpaceButton();
            return true;

        case KBD_SPACE_BUTTON:
            Serial.println("SPACE button pressed");
            handleSpaceButton();
            return true;
    
    }

    if (checkButtonPressed(selected)) {
        return true;
    }

    return false;
}

bool Keyboard::checkButtonPressed(KeyboardButtons selected) {
    char chr = '\0';

    if (KBD_NUMBER_0 <= selected && selected <= KBD_NUMBER_9) {
        chr = static_cast<char>('0' + (selected - KBD_NUMBER_0));
    }

    switch (mKeyboardMode) {
        case ALPHABET_MODE:
            if(KBD_a_A_EXLAMATION <= selected && selected <= KBD_z_Z_ATSIGN) {
                chr = static_cast<char>('a' + (selected - KBD_a_A_EXLAMATION));
            }
            break;
    
        case CAPS_MODE:
            if(KBD_a_A_EXLAMATION <= selected && selected <= KBD_z_Z_ATSIGN) {
                chr = static_cast<char>('A' + (selected - KBD_a_A_EXLAMATION));
            }
            break;

        case SPECIAL_CHAR_MODE1:
            if(KBD_a_A_EXLAMATION <= selected && selected <= KBD_z_Z_ATSIGN) {
                if(KBD_p_P_COLON <= selected && selected <= KBD_v_V_SEMICOLON) {
                    chr = static_cast<char>(':' + (selected - KBD_p_P_COLON));
                }  else if(KBD_w_W_LESSTHAN <= selected && selected <= KBD_z_Z_ATSIGN) {
                    chr = static_cast<char>('[' + (selected - KBD_w_W_LESSTHAN));
                }
                else {
                    chr = static_cast<char>('!' + (selected - KBD_a_A_EXLAMATION));
                }  
            }
            break;
        
        case SPECIAL_CHAR_MODE2:
            if(KBD_a_A_EXLAMATION <= selected && selected <= KBD_b_B_QUOTES) {
                chr = static_cast<char>('_' + (selected - KBD_a_A_EXLAMATION));
            } else if(KBD_c_C_HASHTAG <= selected && selected <= KBD_f_F_CARET) {
                chr = static_cast<char>('{' + (selected - KBD_c_C_HASHTAG));
            }
            break;
    }

    if(chr != '\0') {
        Serial.println(String(chr) + " is pressed");
        InputBox* inputBox = (InputBox*) getComponents()[KBD_INPUT_BOX];
        String currentText = inputBox->getText();
        if(currentText.length() < 20) {
            currentText += chr;     
        } 
        inputBox->setTextAndDraw(currentText);
        return true;
    }

    return false;
}

void Keyboard::selectKeyboardMode(KeyboardButtons button) {
    //do things in order to change the text of the buttons
    Serial.println(String("selectKeyboardMode, button = ") + button + ", mKeyboardMode = " + mKeyboardMode);
    if(button == KBD_CAPS_BUTTON) {
        if (mKeyboardMode == ALPHABET_MODE) {
            Serial.println("In Caps Mode");
            mKeyboardMode = CAPS_MODE;
            ((TextBase*) getComponents()[KBD_CAPS_BUTTON])->setTextAndDraw("^");
            setUppercaseChars();
        } else if (mKeyboardMode == CAPS_MODE) {
            Serial.println("In ALPHABET_MODE");
            mKeyboardMode = ALPHABET_MODE;
            ((TextBase*) getComponents()[KBD_CAPS_BUTTON])->setTextAndDraw("^");
            setLowercaseChars();
        } else if (mKeyboardMode == SPECIAL_CHAR_MODE1) {
            Serial.println("In special char mode2");
            mKeyboardMode = SPECIAL_CHAR_MODE2;
            ((TextBase*) getComponents()[KBD_CAPS_BUTTON])->setTextAndDraw("^2");
            setSpecialChars2();
        } else if (mKeyboardMode == SPECIAL_CHAR_MODE2) {
            Serial.println("In Special char mode1");
            mKeyboardMode = SPECIAL_CHAR_MODE1;
            ((TextBase*) getComponents()[KBD_CAPS_BUTTON])->setTextAndDraw("^1");
            setSpecialChars1();
        }
    }  else if (button == KBD_SPECIAL_CHAR_BUTTON) {
        Serial.println("IN SPECIAL CHAR MODE");
        if (mKeyboardMode == ALPHABET_MODE || mKeyboardMode == CAPS_MODE) {
            mKeyboardMode = SPECIAL_CHAR_MODE1;
            ((TextBase*) getComponents()[KBD_CAPS_BUTTON])->setTextAndDraw("^1");
            setSpecialChars1();
        } else {
            Serial.println("In else ALPHABET MODE");
            mKeyboardMode = ALPHABET_MODE;
            ((TextBase*) getComponents()[KBD_CAPS_BUTTON])->setTextAndDraw("^");
            setLowercaseChars();
        }
    } 
}

void Keyboard::setUppercaseChars() {
    for (KeyboardButtons but = KBD_a_A_EXLAMATION; but <= KBD_z_Z_ATSIGN; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw(String(static_cast<char>('A' + but - KBD_a_A_EXLAMATION)));
    }
}

void Keyboard::setLowercaseChars() {
    Button* button = (Button*) getComponents()[KBD_SPECIAL_CHAR_BUTTON];
    button->setTextAndDraw(String("*^&@"));
    for (KeyboardButtons but = KBD_a_A_EXLAMATION; but <= KBD_z_Z_ATSIGN; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw(String(static_cast<char>('a' + but - KBD_a_A_EXLAMATION)));
    }
}

void Keyboard::setSpecialChars1() {
    Button* button = (Button*) getComponents()[KBD_SPECIAL_CHAR_BUTTON];
    button->setTextAndDraw(String("abcd"));
    for (KeyboardButtons but = KBD_a_A_EXLAMATION; but <= KBD_o_O_SLASH; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw(String(static_cast<char>('!' + but - KBD_a_A_EXLAMATION)));
    }
    for (KeyboardButtons but = KBD_p_P_COLON; but <= KBD_v_V_SEMICOLON; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw(String(static_cast<char>(':' + but - KBD_p_P_COLON)));
    }
    for (KeyboardButtons but = KBD_w_W_LESSTHAN; but <= KBD_z_Z_ATSIGN; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw(String(static_cast<char>('[' + but - KBD_w_W_LESSTHAN)));
    } 
}

void Keyboard::setSpecialChars2() {
    for (KeyboardButtons but = KBD_a_A_EXLAMATION; but <= KBD_b_B_QUOTES; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw(String(static_cast<char>('_' + but - KBD_a_A_EXLAMATION)));
    }
    for (KeyboardButtons but = KBD_c_C_HASHTAG; but <= KBD_f_F_CARET; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw(String(static_cast<char>('{' + but - KBD_c_C_HASHTAG)));
    }
    for (KeyboardButtons but = KBD_g_G_AMPERSAND; but <= KBD_z_Z_ATSIGN; but = static_cast<KeyboardButtons>(but + 1)) {
        Button* button = (Button*) getComponents()[but];
        button->setTextAndDraw("  ");
    }
}

void Keyboard::handleSpaceButton() {
    Serial.println("Space button pressed");
    InputBox* inputBox = (InputBox*) getComponents()[KBD_INPUT_BOX];
    String currentText = inputBox->getText();
    currentText += " ";
    inputBox->setTextAndDraw(currentText);
}

void Keyboard::handleBackSpaceButton() {
    Serial.println("Backspace button pressed");
    InputBox* inputBox = (InputBox*) getComponents()[KBD_INPUT_BOX];
    String currentText = inputBox->getText();
    if (currentText.length() > 0) {
        currentText.remove(currentText.length() - 1);
        inputBox->setTextAndDraw(currentText);
    }
}

void Keyboard::handleBackButton() {
    Serial.println("Back button pressed");
    ((TextBase*) getComponents()[KBD_TEXT_WAIT])->setHide(false);
    getComponents()[KBD_TEXT_WAIT]->draw();

    mKeyboardMode = ALPHABET_MODE;
    setLowercaseChars();

    const String& text = ((InputBox*) getComponents()[KBD_INPUT_BOX])->getText();
    mCallback(text);
    myLCDScreen.setCurrentFrame(mScreenFrame);

    ((TextBase*) getComponents()[KBD_TEXT_WAIT])->setHide(true);
}