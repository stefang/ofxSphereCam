/*
 *  ofxSphereCam.h
 *  arcballExample
 *
 *  Created by Stefan Goodchild on 13-08-12.
 *  Copyright 2012 Triple Geek Ltd. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

class ofxSphereCam : public ofCamera {
public:
	
	ofxSphereCam();	

    void update();
    void axis();
    void randomPos();
    void setSpeed(int speed);
    
    float azimuthTarget;
    float zenithTarget;
    float radiusTarget;
    ofVec3f targTarget;

    
private:
    float zenith;
    float azimuth;
    float radius;
    float speed;
    bool handheld;
    
    ofVec3f pos;
    ofVec3f targ;
    ofVec3f handNoise;
    
    float noiseScale;   
    int frameCount;
        
};
