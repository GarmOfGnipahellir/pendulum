#pragma once

#include "ofMain.h"

class ofPendulum {
public:
    ofVec3f position;
    float length;
    float radius;
    float slice;
    
    float phase;
    float period;
    
    ofPendulum();
    ofPendulum(ofVec2f _position);
    void update();
    void draw();
    
protected:
    float angle;
    ofVec2f ballPosition;
    int pathResolution = 24;
};
