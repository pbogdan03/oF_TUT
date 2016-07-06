#include "rectangle.h"

rectangle::rectangle() {
    shaper = 0.1;
}

void rectangle::draw() {
    ofFill();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    //ofSetColor(198, 246, 55);
    
    ofDrawRectangle(pos.x, pos.y, 20, 20);
}

void rectangle::interpolateByPct(float myPct) {
    pct = powf(myPct, shaper);
    pos.x = (1 - pct) * posa.x + pct * posb.x;
    pos.y = (1 - pct) * posa.y + pct * posb.y;
}