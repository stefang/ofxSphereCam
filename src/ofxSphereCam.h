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

class ofxSphereCam {
public:
	
	ofxSphereCam();	

    void update();
    void begin();
    void end();
    void axis();
    void randomPos();
    
    bool handheld;
    
    float azimuth;
    float azimuthTarget;

    float zenith;
    float zenithTarget;

    float radius;
    float radiusTarget;
    
    ofVec3f pos;
    ofVec3f targ;
    ofVec3f targTarget;
    ofVec3f handNoise;
    
    float noiseScale;   
    float speed;
    int frameCount;
    
    ofCamera camera;
    
};
