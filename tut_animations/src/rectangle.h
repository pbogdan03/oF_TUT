#ifndef rectangle_h
#define rectangle_h

#include "ofMain.h"

class rectangle {
    public:
    
        rectangle();
        void draw();
        void interpolateByPct(float myPct);
    
        ofPoint pos;
        ofPoint posa;
        ofPoint posb;
        float pct; // what percent are we between 'a' and 'b'
        float shaper;
    
};

#endif /* rectangle_h */
