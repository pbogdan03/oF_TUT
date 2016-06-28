#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    minDistance = 10;
    leftMouseButtonPressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (leftMouseButtonPressed) {
        ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
        if (lastPoint.distance(mousePos) >= minDistance) {
            // a.distance(b) calculates the Euclidean distance between point a and b.  It's
            // the length of the straight line distance between the points.
            currentPolyline.curveTo(mousePos);  // Here we are using an ofVec2f with curveTo(...)
            lastPoint = mousePos;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofSetColor(255); // white color for saved polylines
    for (int i = 0; i < polylines.size(); i++) {
        ofPolyline polyline = polylines[i];
        polyline.draw();
        
//        // draw a circle at each vertex
//        vector<ofVec3f> vertices = polyline.getVertices();
//        for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
//            ofVec3f vertex = vertices[vertexIndex];
//            ofDrawCircle(vertex, 5);
//        }
        
//        // draw evenly spaced circles (10% distance between)
//        for (int i = 0; i < 100; i += 10) {
//            ofVec3f point = polyline.getPointAtPercent(i / 100.0); // Returns a point at a percentage along the polyline
//            ofDrawCircle(point, 5);
//        }
        
//        // draw normals at each vertex
//        vector<ofVec3f> vertices = polyline.getVertices();
//        float normalLength = 50;
//        for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
//            ofVec3f vertex = vertices[vertexIndex];
//            ofVec3f normal = polyline.getNormalAtIndex(vertexIndex) * normalLength; // scale the normal
//            ofDrawLine(vertex - normal / 2, vertex + normal / 2); // center the scaled normal around the vertex
//        }
        
//        // draw a lot of evenly spaced normals
//        float numPoints = polyline.size();
//        float normalLength = 50;
//        ofSetColor(255, 100);
//        for (int i = 0; i < 500; i += 1) {
//            ofVec3f point = polyline.getPointAtPercent(i / 500.0);
//            float floatIndex = i / 500.0 * (numPoints - 1);
//            ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
//            ofDrawLine(point - normal / 2, point + normal / 2);
//        }
        
//        // draw a tangent at each vertex
//        vector<ofVec3f> vertices = polyline.getVertices();
//        float tangentLength = 80;
//        for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
//            ofVec3f vertex = vertices[vertexIndex];
//            ofVec3f tangent = polyline.getTangentAtIndex(vertexIndex) * tangentLength;
//            ofDrawLine(vertex - tangent / 2, vertex + tangent / 2);
//        }
        
        int numPoints = polyline.size();
        float plLength = polyline.getPerimeter();
        cout << "plLength: " << plLength << endl;
        cout << "numPoints: " << numPoints << endl;
        float tangentLength = 300;
        ofSetColor(255, 100);
        for (int i = 0; i < floor(plLength); i += 10) {
            ofVec3f point = polyline.getPointAtPercent(i / plLength);
            float floatIndex = i / plLength * (numPoints - 1);
            ofVec3f tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
            ofDrawLine(point - tangent / 2, point + tangent / 2);
        }
    }
    ofSetColor(255, 100, 0); // orange color for active polyline
    currentPolyline.draw();

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
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = false;
        currentPolyline.curveTo(x, y); // Necessary duplicate for last control point
        currentPolyline.simplify(0.75); // Remove similar vertices from the curve
        polylines.push_back(currentPolyline);
        currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
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
