#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    ofBackground(30, 30, 30);
    
    for (int i = 0; i < 10; i++) {
        myRectangles[i].posa.x = 0;
        myRectangles[i].posa.y = 10 + i * 20;
        myRectangles[i].posb.x = 400;
        myRectangles[i].posb.y = 10 + i * 20;
        myRectangles[i].shaper = 1 + 0.2 * i;
        myRectangles[i].interpolateByPct(0);
    }
    
    
    pct = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //printf("%f \n", pct);
    
    pct += 0.003f; // increase by certain amount
    if (pct > 1) {
        pct = 0; // just between 0 and 1
    }
    for (int i = 0; i < 10; i++) {
        myRectangles[i].interpolateByPct(pct); // go between point a and point b
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 10; i++) {
        ofSetColor(198, 246, 55);
        if (i == 3) ofSetColor(255, 0, 0);
        myRectangles[i].draw();
    }
    
    ofSetColor(255, 255, 255);
    for (int i = 0; i < 10; i++) {
        ofDrawLine(0, i * 20, ofGetWidth(), i * 20);
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
