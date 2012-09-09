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
    void setSpeed(int speed);
    
    void moveTo(ofVec3f t);
    void sphereTo(ofVec3f t);
    void lookAtTo(ofVec3f t);
    
    void randomPos();
    
    bool handheld;

    void axis();
        
private:
    
    float speed;
    float noiseScale;   

    ofVec3f posCartesian;
    ofVec3f posSpherical;
    
    ofVec3f targCartesian;
    ofVec3f targSpherical;
    
    ofVec3f targLookAt;
    ofVec3f handNoise;
        
};
