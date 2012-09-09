#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    glEnable(GL_DEPTH_TEST);
    
    // Boxes Stuff
    
    movementSpeed = .1;
	cloudSize = 400;
	maxBoxSize = 50;
	spacing = 2;
	boxCount = 50;

}

//--------------------------------------------------------------
void testApp::update(){
    sCam.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    sCam.begin();
    
    for(int i = 0; i < boxCount; i++) {
		ofPushMatrix();
		
		float t = (ofGetElapsedTimef() + i * spacing) * movementSpeed;
		ofVec3f pos(
                    ofSignedNoise(t, 0, 0),
                    ofSignedNoise(0, t, 0),
                    ofSignedNoise(0, 0, t));
		
		float boxSize = maxBoxSize * ofNoise(pos.x, pos.y, pos.z);
		
		pos *= cloudSize;
		ofTranslate(pos);
		ofRotateX(pos.x);
		ofRotateY(pos.y);
		ofRotateZ(pos.z);
		
		ofFill();
		ofSetColor(20);
		ofBox(boxSize);
		
		ofNoFill();
		ofSetColor(ofColor::fromHsb(sinf(t) * 128 + 128, 255, 255));
		ofBox(boxSize * 1.1f);
		
		ofPopMatrix();
	}
    
    sCam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){    
    sCam.randomPos();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}