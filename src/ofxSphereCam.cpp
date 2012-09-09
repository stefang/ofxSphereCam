#include "ofxSphereCam.h"

ofxSphereCam::ofxSphereCam() {

    handheld = true;
    noiseScale = 0.004; 
    
    speed = 64;
    
}

void ofxSphereCam::moveTo(ofVec3f t) {};
void ofxSphereCam::sphereTo(ofVec3f t) {};
void ofxSphereCam::lookAtTo(ofVec3f t) {};

void ofxSphereCam::update() {
    
//    setPosition(pos);
//    lookAt(targ);

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
    setSpeed((int) ofRandom(32,64));
}

void ofxSphereCam::setSpeed(int s) {
    speed = s;
}