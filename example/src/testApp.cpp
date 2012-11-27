#include "testApp.h"

// Press M to linear move the position and lookat
// Press S to rotate around current lookat

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(50);
    glEnable(GL_DEPTH_TEST);
    
    // Boxes Stuff
    
    movementSpeed = .1;
	cloudSize = 400;
	maxBoxSize = 50;
	spacing = 2;
	boxCount = 50;
    
    monitor.setPosition(400, -800, -1000);
    monitor.lookAt(ofVec3f(0,0,0));
}


//--------------------------------------------------------------
void testApp::update(){
    sCam.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
//    monitor.begin();
    sCam.begin();
    
    for(int i = 0; i < boxCount; i++) {
		ofPushMatrix();
		
		float t = (i * spacing) * movementSpeed;
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
		ofSetColor(ofColor::fromHsb(sinf(t) * 128 + 128, 255, 255, 50));
		ofBox(boxSize * 1.1f);
		
		ofPopMatrix();
	}
    
    sCam.axis();
    
    ofPushMatrix();
    ofSetColor(ofColor::fromHsb(0, 0, 255));
    ofTranslate(sCam.lookedAt);
    ofBox(0, 0, 0, 20);
    ofPopMatrix();

//    ofPushMatrix();
//    ofSetColor(ofColor::fromHsb(0, 100, 255));
//    ofTranslate(sCam.getPosition());
//    ofBox(0, 0, 0, 20);
//    ofPopMatrix();

//    monitor.end();
    sCam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 's':
            sCam.randomPosS();
            break;
        case 'm':
            sCam.randomPosM();
            break;
    }

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