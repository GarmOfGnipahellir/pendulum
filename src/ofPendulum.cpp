#include "ofPendulum.h"

ofPendulum::ofPendulum() {}
ofPendulum::ofPendulum(ofVec2f _position, float _phaseOffset = 0) {
    position = _position;
    length = 50;
    radius = 10;
    slice = .75;
    
    phase = 0;
    period = 2;
    phaseOffset = _phaseOffset;
    
    position.y -= cos(slice * PI) * length + (length - cos(slice * PI) * length) / 2;
}

void ofPendulum::update() {
    phase = (sin((ofGetElapsedTimef() * period) + phaseOffset) + 1) * 0.5;
    angle = (phase - 0.5) * slice * TWO_PI;
    
    ballPosition = ofVec2f(sin(angle), cos(angle)) * length;
}

void ofPendulum::draw(ofPalette palette) {
    ofSetColor(palette.colors[1]);
    ofNoFill();
    ofBeginShape();
    for (int i = 0; i <= pathResolution; i++) {
        float a = (i * slice * TWO_PI / pathResolution) - (slice * PI);
        ofVertex(position.x + sin(a) * length, position.y + cos(a) * length);
    }
    ofEndShape();
    
    ofSetColor(palette.colors[2].getLerped(palette.colors[3], phase));
    ofFill();
    ofDrawCircle(position + ballPosition, radius);
}
