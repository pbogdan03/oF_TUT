#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	myBlueBall.setup();
	myRedBall.setup();
	myGreenBall.setup();

	for (int i = 0; i<myBall.size(); i++) {
		int size = (i + 1) * 10; // size of each ball based on the position in the array
		int randomX = ofRandom(0, ofGetWidth());
		int randomY = ofRandom(0, ofGetHeight());
		myBall[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	myBlueBall.update();
	myGreenBall.update();
	myRedBall.update();

	for (int i = 0; i<myBall.size(); i++) {
		myBall[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	myBlueBall.draw();
	myGreenBall.draw();
	myRedBall.draw();

	for (int i = 0; i<myBall.size(); i++) {
		myBall[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'd') {
		myBall.clear();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	Ball tempBall;
	tempBall.setup();
	myBall.push_back(tempBall);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	for (int i = 0; i < myBall.size(); i++) {
		float distance = ofDist(x, y, myBall[i].x, myBall[i].y);

		if (distance < myBall[i].dim) {
			myBall.erase(myBall.begin() + i); // iterator/reference to the vector position we want to delete
		}
	}
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
