#include "TronRectsYSource.h"

//--------------------------------------------------------------
void TronRectsYSource::setup(){
    name = "Tron Rects Y FBO Source";
    
   // ofSetBackgroundAuto(false);
    allocate(756,1134);
    rectColor = ofColor(255);
    ofBackground(0);

}

//--------------------------------------------------------------
void TronRectsYSource::setName(string _name){
    name = _name;
    
}

//--------------------------------------------------------------
void TronRectsYSource::update(){
    
numOfFrames++;
}

//--------------------------------------------------------------
void TronRectsYSource::draw(){
    
   // ofClear(0);
    
    ofSetColor(0, 0, 0, 20);
    ofDrawRectangle(0, 0,fbo->getWidth(),fbo->getHeight());
    
    int numOfRects = 12;
    for (int i=0; i<numOfRects; i++){
       oscilate(numOfFrames + i * 180/numOfRects, i); // we spread the "numOfRects" of half a cycle (180 degrees).
    }
}


//--------------------------------------------------------------
void TronRectsYSource::oscilate(float rot, int index){
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(fbo->getWidth()/2, index*(fbo->getHeight()/12));

   ofRotateYDeg(rot);
    
    float scaleFactor = abs(sin(ofDegToRad(rot))) + ofNoise(0.05);
    ofScale(scaleFactor, 1, 1);
    
    //ofNoFill();
    ofSetColor(255);
    
    int RectWidth = fbo->getWidth()/2; //I had to eyeball this number because of the oscilation. It is probably going to change when I bring this into pimapper as well
    int RectHeight = fbo->getHeight()/12; // devided by 12 because there are 6 steps. Each step has a run and a rise surface that double the amount of rects.
    ofSetColor(rectColor);
    ofDrawRectangle(0, 0, RectWidth, RectHeight);
    ofSetColor(0);
    ofDrawRectangle(0, 0, RectWidth - 3, RectHeight -3);
    ofPopMatrix();
}


//--------------------------------------------------------------
void TronRectsYSource::reset(){
    
    rectColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    //rotDirX = ofRotateXDeg(360);
  //  rotDirY = ofRotateYDeg(360);
    
    
}


//--------------------------------------------------------------
void TronRectsYSource::keyPressed(int key){

}

//--------------------------------------------------------------
void TronRectsYSource::keyReleased(int key){

}

//--------------------------------------------------------------
void TronRectsYSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void TronRectsYSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void TronRectsYSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void TronRectsYSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void TronRectsYSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void TronRectsYSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void TronRectsYSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void TronRectsYSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void TronRectsYSource::dragEvent(ofDragInfo dragInfo){

}
