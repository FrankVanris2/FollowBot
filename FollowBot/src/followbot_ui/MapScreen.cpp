#include "MapScreen.h"
#include "Button.h"
#include "TextBase.h"

MapScreen mapScreen;

void MapScreen::setup(TFT_eSPI& tft) {
    setTFT(tft);
    // Initialize components here
}

void MapScreen::draw() {
    getTFT().fillScreen(TFT_BLUE); // Example background color
    drawComponents();
}

bool MapScreen::touchScreenEvent(int x, int y) {
    MapScreenComponents selected = getComponentForTouch(x, y);
    // Handle touch events here
    return false;
}