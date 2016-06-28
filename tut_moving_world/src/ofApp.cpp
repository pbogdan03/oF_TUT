#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofScale(0.5, 0.5); // to scale the whole drawing
    
    for (int rows = 0; rows < 4; rows++) {
        ofPushMatrix(); // save the coordinate system before we shift it horizontally
        
        // Loop and draw a row
        for (int cols = 0; cols < 4; cols++) {
            
            // Draw the stick figure family
            ofSetColor(255, ofRandom(255), 0);
            ofDrawCircle(30, 30, 30);
            ofDrawRectangle(5, 70, 50, 100);
            ofSetColor(255, ofRandom(255), 0);
            ofDrawCircle(95, 30, 30);
            ofDrawRectangle(70, 70, 50, 100);
            ofSetColor(255, ofRandom(255), 0);
            ofDrawCircle(45, 90, 15);
            ofDrawRectangle(30, 110, 30, 60);
            ofSetColor(255, ofRandom(255), 0);
            ofDrawCircle(80, 90, 15);
            ofDrawRectangle(65, 110, 30, 60);
            
            ofTranslate(150, 0);
        }
        
        ofPopMatrix(); // return to the coordinate system before we shifted it horizontally
        ofTranslate(0, 200);
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
