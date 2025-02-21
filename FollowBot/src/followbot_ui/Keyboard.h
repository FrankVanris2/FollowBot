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
    KBD_BACK_BUTTON,
    KBD_INPUT_BOX,
    BACKSPACE_BUTTON,
    SPACE_BUTTON,
    ENTER_BUTTON,
    CAPS_BUTTON,
    SPECIAL_CHAR_BUTTON,

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
    KBD_b,
    KBD_c,
    KBD_d,
    KBD_e,
    KBD_f,
    KBD_g,
    KBD_h,
    KBD_i,
    KBD_j,
    KBD_k,
    KBD_l,
    KBD_m,
    KBD_n,
    KBD_o,
    KBD_p,
    KBD_q,
    KBD_r,
    KBD_s,
    KBD_t,
    KBD_u,
    KBD_v,
    KBD_w,
    KBD_x,
    KBD_y,
    KBD_z,

    //symbols
};

class Keyboard : public FrameBase<KeyboardButtons>{
public:

    void setup(TFT_eSPI& tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);
};

extern Keyboard keyboard;