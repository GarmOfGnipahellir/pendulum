#pragma once

#include "ofMain.h"
#include "ofPalette.h"

class ofPendulum {
public:
    ofVec3f position;
    float length;
    float radius;
    float slice;
    
    float phase;
    float period;
    float phaseOffset;
    
    ofPendulum();
    ofPendulum(ofVec2f _position, float _phaseOffset);
    void update();
    void draw(ofPalette palette);
    
protected:
    float angle;
    ofVec2f ballPosition;
    int pathResolution = 24;
};
