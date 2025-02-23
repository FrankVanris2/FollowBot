/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a Keyboard interface
*/

#pragma once
#include "FrameBase.h"
#include <unordered_map>

class TFT_eSPI;

enum KeyboardButtons {
    //Necessary buttons
    KBD_TEXT_WAIT,
    KBD_BACK_BUTTON,
    KBD_INPUT_BOX,
    KBD_BACKSPACE_BUTTON,
    KBD_SPACE_BUTTON,
    KBD_ENTER_BUTTON,
    KBD_CAPS_BUTTON,
    KBD_SPECIAL_CHAR_BUTTON,
    KBD_ALPHABET_CHAR_BUTTON,

    //Numbers
    KBD_NUMBER_0,
    KBD_NUMBER_1,
    KBD_NUMBER_2,
    KBD_NUMBER_3,
    KBD_NUMBER_4,
    KBD_NUMBER_5,
    KBD_NUMBER_6,
    KBD_NUMBER_7,
    KBD_NUMBER_8,
    KBD_NUMBER_9,

    //Alphabet
    KBD_a_A_EXLAMATION,
    KBD_b_B_QUOTES,
    KBD_c_C_HASHTAG,
    KBD_d_D_DOLLAR,
    KBD_e_E_PERCENT,
    KBD_f_F_CARET,
    KBD_g_G_AMPERSAND,
    KBD_h_H_ASTERISK,
    KBD_i_I_LPARENTHESIS,
    KBD_j_J_RPARENTHESIS,
    KBD_k_K_UNDERSCORE,
    KBD_l_L_PLUS,
    KBD_m_M_MINUS,
    KBD_n_N_DOT,
    KBD_o_O_SLASH,
    KBD_p_P_COLON,
    KBD_q_Q_LSQUAREBRACE,
    KBD_r_R_RSQUAREBRACE,
    KBD_s_S_BACKSLASH,
    KBD_t_T_VERTICALBAR,
    KBD_u_U_COLON,
    KBD_v_V_SEMICOLON,
    KBD_w_W_LESSTHAN,
    KBD_x_X_GREATERTHAN,
    KBD_y_Y_QUESTION,
    KBD_z_Z_ATSIGN
};

enum KeyboardMode { //added this
    ALPHABET_MODE,
    CAPS_MODE,
    SPECIAL_CHAR_MODE1,
    SPECIAL_CHAR_MODE2,
};

class Keyboard : public FrameBase<KeyboardButtons>{
public:

    void setup(TFT_eSPI& tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);

private:
    void selectKeyboardMode(KeyboardButtons button); 
    void setUppercaseChars();
    void setLowercaseChars();

    void setSpecialChars1();
    void setSpecialChars2();


    // other fields
    KeyboardMode mKeyboardMode = ALPHABET_MODE; //added this
};

extern Keyboard keyboard;