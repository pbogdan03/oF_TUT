#include "ofApp.h"

enum brush {RECTANGLE, CIRCLE, STAR, TRIANGLE};
// initialize paintbrush
brush paintBrush = STAR;

//--------------------------------------------------------------
void ofApp::setup(){
    
    /**
     ***********************************************************
     *  GENERAL
     ***********************************************************
     */
    
    ofSetCircleResolution(50);
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    leftMouseButtonPressed = false;
    
    /**
     ***********************************************************
     *  BACKGROUND
     ***********************************************************
     */
    
    ofSetBackgroundAuto(false);
    ofBackground(0); // clear the screen with a black color
    
    /**
     ***********************************************************
     *  POLYLINES
     ***********************************************************
     */
    
    straightSegmentPolyline.addVertex(100, 100);
    straightSegmentPolyline.addVertex(150, 150);
    straightSegmentPolyline.addVertex(200, 100);
    straightSegmentPolyline.addVertex(250, 150);
    straightSegmentPolyline.addVertex(300, 100);
    
    curvedSegmentPolyline.curveTo(350, 100); // these curves are Catmull-Rom splines
    curvedSegmentPolyline.curveTo(350, 100); // necessary duplicate for control point
    curvedSegmentPolyline.curveTo(400, 150);
    curvedSegmentPolyline.curveTo(450, 100);
    curvedSegmentPolyline.curveTo(500, 150);
    curvedSegmentPolyline.curveTo(550, 100);
    curvedSegmentPolyline.curveTo(550, 100); // necessary duplicate for control point
    
    closedShapePolyline.addVertex(600, 125);
    closedShapePolyline.addVertex(700, 100);
    closedShapePolyline.addVertex(800, 125);
    closedShapePolyline.addVertex(700, 150);
    closedShapePolyline.close(); // connect first and last vertices

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetLineWidth(2.0); // line widths apply to polylines
    ofSetColor(255, 100, 0);
    straightSegmentPolyline.draw();
    curvedSegmentPolyline.draw();
    closedShapePolyline.draw();
    
    /**
     ***********************************************************
     *  EVENTS / ACTIONS
     ***********************************************************
     */
    
    if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) { // if the left mouse button is pressed
        
        switch (paintBrush) {
            case RECTANGLE:
            {
                ofSetRectMode(OF_RECTMODE_CENTER);
                int numRects = 10;
                
                for (int r = 0; r < numRects; r++) {
                    ofSetColor(ofRandom(50, 255));
                    float width = ofRandom(5, 20);
                    float height = ofRandom(5, 20);
                    float distance = ofRandom(35);
        
                    float randomColor = ofRandom(50, 255);
                    ofSetColor(randomColor); // exclude dark grayscale values (0 - 50) that won't show on black background
                    ofSetLineWidth(1.0);
        
                    // Formula for converting from polar to Cartesian coordinates:
                    // x = cos(polar angle) * (polar distance)
                    // y = sin(polar angle) * (polar distance)
        
                    // We need our angle to be in radians if we want to use sin() and cos()
                    // so we can make use of an oF function to convert from degrees to radians
                    float angle = ofRandom(ofDegToRad(360.0));
        
                    float xOffset = cos(angle) * distance;
                    float yOffset = sin(angle) * distance;
                    ofDrawRectangle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, width, height); // Draw a 50 x 50 rect centered on the mouse
                }
                break;
            }
                
            case CIRCLE:
            {
                int maxRadius = 30; // Increase for wider brush
                int radiusStepSize = 5; // Decrease for more circles (more opaque brush)
                int alpha = 3; // Increase for more opaque brush
                int maxOffsetDistance = 30; // Increase for a larger spread of circles
                
                // draw smaller and smaller circles and layering (increasing) opaqueness
                for (int radius = maxRadius; radius > 0; radius -= radiusStepSize) {
                    float distance = ofRandom(maxOffsetDistance);
                    float angle = ofRandom(ofDegToRad(360.0));
                    //ofSetColor(ofRandom(255), ofRandom(255), 0, alpha);
                    
                    ofColor myOrange(255, 132, 0, alpha);
                    ofColor myRed(255, 6, 0, alpha);
                    ofColor inBetween = myOrange.getLerped(myRed, ofRandom(1.0));
                    ofSetColor(inBetween);
                    ofSetLineWidth(1.0);
                    
                    float xOffset = cos(angle) * distance;
                    float yOffset = sin(angle) * distance;
                    ofDrawCircle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, radius);
                }
                break;
            }
                
            case STAR:
            {
                int numLines = 30;
                int minRadius = 25;
                int maxRadius = 125;
                
                for (int i = 0; i <= numLines; i++) {
                    float angle = ofRandom(ofDegToRad(360.0));
                    float distance = ofRandom(minRadius, maxRadius);
                    float xOffset = cos(angle) * distance;
                    float yOffset = sin(angle) * distance;
                    float alpha = ofMap(distance, minRadius, maxRadius, 50, 0); // Make shorter lines more opaque
                    
                    ofSetColor(255, alpha);
                    ofSetLineWidth(ofRandom(1.0, 5.0));
                    ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX() + xOffset, ofGetMouseY() + yOffset);
                }
                break;
            }
                
            case TRIANGLE:
            {
                ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
                
                int numTriangles = 10;
                int minOffset = 5;
                int maxOffset = 40;
                
                int alpha = ofMap(lastPoint.distance(mousePos) * 4, 0, ofGetWindowWidth(), 100, 0);
                
//                cout << "distance: " << lastPoint.distance(mousePos) << endl;
                cout << "alpha: " << alpha << endl;
                cout << "width: " << ofGetWindowWidth() << endl;
                
                for (int i = 0; i < numTriangles; i++) {
                    float offsetDistance = ofRandom(minOffset, maxOffset);
                    
                    // Define a triangle at the origin (0,0) that points to the right
                    ofVec2f p1(0, 10.0);
                    ofVec2f p2(40, 0);
                    ofVec2f p3(0, -10.0);
                    
                    // Rotate the triangle points around the origin
                    float rotation = ofRandom(360); // The rotate function uses degrees!
                    p1.rotate(rotation);
                    p2.rotate(rotation);
                    p3.rotate(rotation);
                    
                    ofVec2f triangleOffset(offsetDistance, 0.0);
                    triangleOffset.rotate(rotation);
                    
                    // Shift the triangle to the mouse position
                    p1 += mousePos + triangleOffset;
                    p2 += mousePos + triangleOffset;
                    p3 += mousePos + triangleOffset;
                    
                    ofColor myBlue(0, 100, 255, alpha);
                    ofColor myPink(100, 0, 255, alpha);
                    ofColor inBetween = myBlue.getLerped(myPink, ofRandom(1.0));
                    
                    ofSetColor(inBetween);
                    ofDrawTriangle(p1, p2, p3);
                    lastPoint = mousePos;
                }
            }
                
            default:
                break;
        }
    }
    
    if(ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) { // if the right mouse button is pressed
        ofBackground(0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // change brush type
    if(key == 's') {
        paintBrush = STAR;
    } else if (key == 'c') {
        paintBrush = CIRCLE;
    } else if (key == 'r') {
        paintBrush = RECTANGLE;
    } else if (key == 't') {
        paintBrush = TRIANGLE;
    } else {
        paintBrush = RECTANGLE;
    }
    
    // take screenshot
    if(key == 'p') {
        glReadBuffer(GL_FRONT);
        ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }
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
