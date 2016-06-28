#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending(); // if we are using transparency we need to let oF know
    ofBackground(255);
    
    clearAlpha = 100;
    timeScale = 0.5;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor darkColor(0, 0, 0, 255); // opaque black
    ofColor lightColor(255, 255, 255, 255); // opaque white
    float time = ofGetElapsedTimef(); // time in seconds
    float percent = ofMap(cos(time / 2.0), -1, 1, 0, 1); // creates a value that oscillates between 0 to 1
    
    ofColor bgColor = darkColor; // color for the transparent rectangle we use to clear the screen
    bgColor.lerp(lightColor, percent); // this modifies our color "in place", check out the documentation page
    bgColor.a = clearAlpha; // our initial colors were opaque, but our rectangle needs to be transparent
    
    ofColor fgColor = lightColor; // color for rectangle outlines
    fgColor.lerp(darkColor, percent); // modifies the color in place
    
    // draw the transparent background
    ofSetColor(bgColor);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()); // ofBackground doesn't work with alpha sau draw a transparent rect
    
    // reset and draw the rectangles
    ofSetColor(fgColor);
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2); // translate to the center of the screen
    for (int i = 0; i < 100; i++) {
        ofScale(1.1, 1.1);
//        ofRotate(5);
        float time = ofGetElapsedTimef();
        float noise = ofSignedNoise(time * timeScale) * 20.0;
        ofRotate(noise);
        ofDrawRectangle(0, 0, 50, 50);
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    clearAlpha = ofMap(x, 0, ofGetWidth(), 0, 255); // clearAlpha goes from 0 to 255 as the mouse moves from left to right
    timeScale = ofMap(y, 0, ofGetHeight(), 0, 1); // timeScale goes from 0 to 1 as the mouse moves from top to bottom
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
