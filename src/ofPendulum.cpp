#include "ofPendulum.h"

ofPendulum::ofPendulum() {}
ofPendulum::ofPendulum(ofVec2f _position) {
    position = _position;
    length = 100;
    radius = 10;
    slice = .25;
    
    phase = 0;
    period = 10;
    
    position.y -= cos(slice * PI) * length + (length - cos(slice * PI) * length) / 2;
}

void ofPendulum::update() {
    phase = (sin(ofGetElapsedTimef() * slice * period) + 1) * 0.5;
    angle = (phase - 0.5) * slice * TWO_PI;
    
    ballPosition = ofVec2f(sin(angle), cos(angle)) * length;
}

void ofPendulum::draw() {
    ofNoFill();
    ofBeginShape();
    for (int i = 0; i <= pathResolution; i++) {
        float a = (i * slice * TWO_PI / pathResolution) - (slice * PI);
        ofVertex(position.x + sin(a) * length, position.y + cos(a) * length);
    }
    ofEndShape();
    
    ofFill();
    ofDrawCircle(position + ballPosition, radius);
}
