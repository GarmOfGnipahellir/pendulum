#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(24);
    
    paletteDay.colors = {
        ofColor(200), // Background
        ofColor(51), // Path
        ofColor(255, 51, 51), // Ball 1
        ofColor(255, 255, 51) // Ball 2
    };
    
    paletteNight.colors = {
        ofColor(51), // Background
        ofColor(200), // Path
        ofColor(51, 255, 51), // Ball 1
        ofColor(51, 255, 255) // Ball 2
    };
    
    int w = 9;
    int h = 9;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            float x = ((ofGetWidth()) / (w - 1)) * i;
            float y = ((ofGetHeight()) / (h - 1)) * j;
            
            float d = ofVec2f(i, j).distance(ofVec2f((w - 1) / 2.0, (h - 1) / 2.0));
            pendulums.emplace_back(ofPendulum(ofVec2f(x, y), d / 2));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    palette = paletteDay.getLerped(paletteNight, (sin(ofGetElapsedTimef()) + 1) / 2);
    
    for (int i = 0; i < pendulums.size(); i++) {
        pendulums[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(palette.colors[0]);
    for (int i = 0; i < pendulums.size(); i++) {
        pendulums[i].draw(palette);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
