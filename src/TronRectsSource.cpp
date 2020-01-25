#include "TronRectsSource.h"

//--------------------------------------------------------------
void TronRectsSource::setup(){
    name = "Tron Rects FBO Source";
    
   // ofSetBackgroundAuto(false);
    allocate(756,1134);
    rectColor = ofColor(255);
    rotDirX = 0;
    rotDirY = 0;
    ofBackground(0);

}

//--------------------------------------------------------------
void TronRectsSource::setName(string _name){
    name = _name;
    
}

//--------------------------------------------------------------
void TronRectsSource::update(){
    
numOfFrames++;
}

//--------------------------------------------------------------
void TronRectsSource::draw(){
    
   // ofClear(0);
    
    ofSetColor(0, 0, 0, 20);
    ofDrawRectangle(0, 0,fbo->getWidth(),fbo->getHeight());
    
    int numOfRects = 12;
    for (int i=0; i<numOfRects; i++){
       oscilate(numOfFrames + i * 180/numOfRects, i); // we spread the "numOfRects" of half a cycle (180 degrees).
    }
}


//--------------------------------------------------------------
void TronRectsSource::oscilate(float rot, int index){
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(fbo->getWidth()/2, index*(fbo->getHeight()/12));
    
    
   ofRotateXDeg(rot);
   // ofRotateYDeg(rot);
   // ofRotateZDeg(rot);
    
    float scaleFactor = abs(sin(ofDegToRad(rot))) + ofNoise(0.05);
    ofScale(scaleFactor, 1, 1);
    
    //ofNoFill();
    ofSetColor(255);
    
    int RectWidth = 443; //I had to eyeball this number because of the oscilation. It is probably going to change when I bring this into pimapper as well
    int RectHeight = fbo->getHeight()/12; // devided by 12 because there are 6 steps. Each step has a run and a rise surface that double the amount of rects.
    ofSetColor(rectColor);
    ofDrawRectangle(0, 0, RectWidth, RectHeight);
    ofSetColor(0);
    ofDrawRectangle(0, 0, RectWidth - 3, RectHeight -3);
    ofPopMatrix();
}


//--------------------------------------------------------------
void TronRectsSource::reset(){
    
    rectColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    //rotDirX = ofRotateXDeg(360);
  //  rotDirY = ofRotateYDeg(360);
    
    
}


//--------------------------------------------------------------
void TronRectsSource::keyPressed(int key){

}

//--------------------------------------------------------------
void TronRectsSource::keyReleased(int key){

}

//--------------------------------------------------------------
void TronRectsSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void TronRectsSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void TronRectsSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void TronRectsSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void TronRectsSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void TronRectsSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void TronRectsSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void TronRectsSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void TronRectsSource::dragEvent(ofDragInfo dragInfo){ 

}
