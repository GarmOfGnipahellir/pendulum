#pragma once

#include "ofMain.h"

class ofPalette {
public:
    vector<ofColor> colors;
    
    ofPalette getLerped(ofPalette other, float alpha);
};
