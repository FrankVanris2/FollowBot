/*
By: Frank Vanris
Date: 2/17/2025
Desc: Creating a Framebase which will be used in multiple frames
*/

#pragma once
#include <unordered_map>
#include "UIComponent.h"

template<typename T>
class FrameBase : public UIComponent {
public:

    virtual void setup(TFT_eSPI&  tft) = 0;

protected:
    std::unordered_map<T, UIComponent*>& getComponents() {
        return comps;
    }

    virtual void drawComponents() {
        for (auto& it: comps) {
            it.second->draw();
        }
    }

    T getComponentForTouch(int x, int y) {
        T selected = static_cast<T>(-1);
    
        for (auto& it: comps) {
            if(it.second->touchScreenEvent(x, y)) {
                selected = it.first;
                break;
            }    
        }
    
        return selected;
    }

private:
    std::unordered_map<T, UIComponent*> comps;
};
