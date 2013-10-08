/*
 *  ofxSphereCam.h
 *
 *  Created by Stefan Goodchild on 13-08-12.
 *  Copyright 2012/13 Triple Geek Ltd. All rights reserved.
 *
 */

#include "ofxSphereCam.h"

ofxSphereCam::ofxSphereCam() {
    
    handheld = false;
    noiseCount = 0;
    noiseSpeed = 0.01;
    handNoiseAmt = 5;
    
    setPosition(0, 0, 500);
    ofVec3f sp = ofVec3f(0, 0, 500);
    moveTo(sp , 0);
       
}

void ofxSphereCam::moveTo(ofVec3f& t, float d) {

    spherical = false;

    ofVec3f pos = getPosition();
    
    posTween.setParameters(easingquad, ofxTween::easeInOut, pos.x, t.x, d, 0);
    posTween.addValue(pos.y, t.y);
    posTween.addValue(pos.z, t.z);

};

void ofxSphereCam::sphereTo(ofVec3f& t, float d) {
    
    spherical = true;
    ofVec3f pos = getPosition();
    radius = pos.distance(lookedAt);
    pos = pos - lookedAt; // correct to 0,0,0
    
    phi = acosf(ofClamp(pos.z / radius, -1, 1));

    float s = sqrt((pos.x * pos.x) + (pos.y * pos.y)) + 0.000001f;
    
    if (pos.x >= 0) {
        theta = asinf(pos.y / s);
    } else {
        theta = PI - asinf(pos.y / s);
    }
    
    theta = ofRadToDeg(theta);
    phi = ofRadToDeg(phi);
    
    posTween.setParameters(easingquad, ofxTween::easeInOut, radius, t.x, d, 0);
    posTween.addValue(phi, t.y);
    posTween.addValue(theta, t.z);
    
};

void ofxSphereCam::lookAtTo(ofVec3f& t, float d) {
    
    ofVec3f tar = lookedAt;
    
    lookAtTween.setParameters(easingquad, ofxTween::easeInOut, tar.x, t.x, d, 0);
    lookAtTween.addValue(tar.y, t.y);
    lookAtTween.addValue(tar.z, t.z);
    
};

void ofxSphereCam::update() {
    
    noiseCount += noiseSpeed;
    
    posTween.update();
    
    if (spherical) {
        
        float phiRad = ofDegToRad(posTween.getTarget(1));
        float thetaRad = ofDegToRad(posTween.getTarget(2));

        setPosition(
            (posTween.getTarget(0) * sin(phiRad) * cos(thetaRad)) + lookedAt.x,
            (posTween.getTarget(0) * sin(phiRad) * sin(thetaRad)) + lookedAt.y,
            (posTween.getTarget(0) * cos(phiRad)) + lookedAt.z
        );
    
    } else {
        
        setPosition(
            posTween.getTarget(0),
            posTween.getTarget(1),
            posTween.getTarget(2)
        );

    }
    
    lookAtTween.update();
    
    ofVec3f la = ofVec3f(
                         lookAtTween.update(),
                         lookAtTween.getTarget(1),
                         lookAtTween.getTarget(2)
                         );
    if (handheld) {
        lookAt(ofVec3f(
                       la.x + handNoiseAmt * (ofNoise(noiseCount)),
                       la.y + handNoiseAmt * (ofNoise(noiseCount, noiseCount)), 
                       la.z + handNoiseAmt * (ofNoise(noiseCount, noiseCount, noiseCount))));
    } else {
        lookAt(ofVec3f(la));
    }
    
    lookedAt=la;

}

void ofxSphereCam::drawAxis() {
    ofPushStyle();
    ofSetColor(255,0,0);
    ofLine(-50,0,0,50,0,0);
    ofSetColor(0,255,0);
    ofLine(0,-50,0,0,50,0);
    ofSetColor(0,0,255);
    ofLine(0,0,-50,0,0,50);
    ofPopStyle();
}

void ofxSphereCam::drawTarget() {
    ofPushMatrix();
    ofTranslate(lookedAt);
    ofPushStyle();
    ofSetColor(255,255,255);
    ofLine(-50,0,0,50,0,0);
    ofLine(0,-50,0,0,50,0);
    ofLine(0,0,-50,0,0,50);
    ofPopStyle();
    ofPopMatrix();
}

void ofxSphereCam::randomPosM() {
    ofVec3f mt = ofVec3f(
        ofRandom(-300,300),
        ofRandom(-300,300),
        ofRandom(-300,300)
    );

    moveTo(mt, ofRandom(1000,2000));
    
    ofVec3f lt = ofVec3f(
                         ofRandom(-300,300),
                         ofRandom(-300,300),
                         ofRandom(-300,300)
                         );
    
    lookAtTo(lt, ofRandom(1000,2000));
}

void ofxSphereCam::randomPosS() {
    ofVec3f st = ofVec3f(
                         ofRandom(300,600),
                         ofRandom(0,360),
                         ofRandom(0,360)
                         );
    
    sphereTo(st, ofRandom(1000,2000));
}

