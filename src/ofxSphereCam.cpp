#include "ofxSphereCam.h"

ofxSphereCam::ofxSphereCam() {

    azimuth = 0;
    azimuthTarget = 0;
    
    zenith = 0;
    zenithTarget = 0;
    
    radius = 200;
    radiusTarget = 600;
    
    handheld = true;
    noiseScale = 0.004; 
    
    speed = 64;
    
    targ = ofVec3f(0,0,0);
    pos = ofVec3f(200,200,400);

}

void ofxSphereCam::update() {
    
    frameCount = ofGetFrameNum();
    
    if (azimuthTarget > azimuth) {
        azimuth = azimuth + ((ofDegToRad(azimuthTarget) - azimuth) / speed);
    } else {
        azimuth = azimuth - ((azimuth - ofDegToRad(azimuthTarget)) / speed);
    }
    
    if (zenithTarget > zenith) {
        zenith = zenith + ((ofDegToRad(zenithTarget) - zenith) / speed);
    } else {
        zenith = zenith - ((zenith - ofDegToRad(zenithTarget)) / speed);
    }
    
    if (radiusTarget > radius) {
        radius = radius + ((radiusTarget - radius) / speed);
    } else {
        radius = radius - ((radius - radiusTarget) / speed);
    }  
        
    pos.x = radius * (sin(zenith) * cos(azimuth));
    pos.y = radius * (sin(zenith) * sin(azimuth));
    pos.z = radius * (cos(zenith));
    
    if (handheld) {
        handNoise.x = ofNoise((frameCount)*noiseScale)-.5; 
        handNoise.y = ofNoise((frameCount)*noiseScale, (frameCount)*noiseScale)-.5; 
        handNoise.z = ofNoise((frameCount)*noiseScale, (frameCount)*noiseScale, (frameCount)*noiseScale)-.5; 
        targ = targ + handNoise;
    }
    
    camera.setPosition(pos);
    camera.lookAt(targ);

}

void ofxSphereCam::begin() {
    camera.begin();
}

void ofxSphereCam::end() {
    camera.end();
}

void ofxSphereCam::axis() {
    ofSetColor(255,0,0);
    ofLine(-50,0,0,50,0,0);
    ofSetColor(0,255,0);
    ofLine(0,-50,0,0,50,0);
    ofSetColor(0,0,255);
    ofLine(0,0,-50,0,0,50);
}

void ofxSphereCam::randomPos() {
}