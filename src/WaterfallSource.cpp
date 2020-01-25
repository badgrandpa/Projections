#include "WaterfallSource.h"


//--------------------------------------------------------------
void WaterfallSource::setup(){
    
    ofBackground(0);
    name = "Waterfall FBO Source";
    
    allocate(756,1134);
    
    dropX = 0;
    dropY = 0;
    
    noiseFieldSource = new NoiseFieldSource(10); // sweet spot number
    noiseFieldSource -> update();
    //number of particles
    for (int i = 0; i < 10000; i++) {
        ofVec2f * start = new ofVec2f(ofRandom(fbo->getWidth()), fbo->getHeight());
      waterParticlesSource.push_back(WaterParticleSource(start, ofRandom(2, 8))); //adding to the end of the vector
    }
    
}

//--------------------------------------------------------------
void WaterfallSource::reset(){
    
   // dropX = ofRandom(2, 8);
   // dropY = ofRandom(2, 8);
    
    
    
    //noiseFieldSource = new NoiseFieldSource(4); // sweet spot number
}


//--------------------------------------------------------------
void WaterfallSource::setName(string _name){
    name = _name;
}



//--------------------------------------------------------------
void WaterfallSource::update(){
    
    

}

//--------------------------------------------------------------
void WaterfallSource::draw(){
    ofClear(0,96,255);
    
   noiseFieldSource->update();
   for (WaterParticleSource p : waterParticlesSource) {
     p.follow(noiseFieldSource);
     p.run();
   }
}

//--------------------------------------------------------------
void WaterfallSource::keyPressed(int key){

}

//--------------------------------------------------------------
void WaterfallSource::keyReleased(int key){

}

//--------------------------------------------------------------
void WaterfallSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void WaterfallSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void WaterfallSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void WaterfallSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void WaterfallSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void WaterfallSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void WaterfallSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void WaterfallSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void WaterfallSource::dragEvent(ofDragInfo dragInfo){ 

}
