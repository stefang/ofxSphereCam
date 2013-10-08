/*
 *  ofxSphereCam.h
 *
 *  Created by Stefan Goodchild on 13-08-12.
 *  Copyright 2012/13 Triple Geek Ltd. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxTween.h"
#include "ofxOsc.h"

class ofxSphereCam : public ofCamera {
public:
    
	ofxSphereCam();

    void update();
    
    void moveTo(ofVec3f& t, float d);
    void sphereTo(ofVec3f& t, float d);
    void lookAtTo(ofVec3f& t, float d);

    ofVec3f lookedAt;
    
    bool handheld;
    float handNoiseAmt;
    
    void randomPosM();
    void randomPosS();
    void drawAxis();
    void drawTarget();
    
private:
    
    ofxTween posTween;
    ofxTween lookAtTween;
    ofxEasingQuad easingquad;
    
    float noiseCount;
    float noiseSpeed;
    
    bool spherical;
    
    float radius;
    float phi;
    float theta;
    
};
