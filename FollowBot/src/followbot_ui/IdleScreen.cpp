#include "IdleScreen.h"
#include "Button.h"
#include "TextBase.h"

IdleScreen idleScreen;

void IdleScreen::setup(TFT_eSPI& tft) {
    setTFT(tft);
    // Initialize components here
}

void IdleScreen::draw() {
    getTFT().fillScreen(TFT_BLACK);
    drawComponents();
}

bool IdleScreen::touchScreenEvent(int x, int y) {
    IdleScreenComponents selected = getComponentForTouch(x, y);
    // Handle touch events here
    return false;
}