#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(24);
    
    int w = 6;
    int h = 10;
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            float x = ((ofGetWidth()) / w) * i;
            float y = ((ofGetHeight()) / h) * j;
            pendulums.emplace_back(ofPendulum(ofVec2f(x, y)));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < pendulums.size(); i++) {
        pendulums[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < pendulums.size(); i++) {
        pendulums[i].draw();
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
