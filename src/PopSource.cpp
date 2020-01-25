#include "PopSource.h"


//--------------------------------------------------------------
void PopSource::setup(){
    
    //ofSetFrameRate(60);
    //ofBackground(255);
    //ofBackground(242,186,39);
    allocate(756,1134);
    
    name = "Watermellon FBO Source";
    
    //Generating a random number with no duplicates. The reason for this is because sometims more that 1 cheese hole would be generating in the same x,y coordinates. This  https://forum.openframeworks.cc/t/generate-random-numbers-without-duplicates-random-sampling-without-replacement/32065
    int dist_factor = ofRandom(15,30);
    
   for (int i = 0; i<fbo->getWidth()/dist_factor; i++){
       for(int j = 0; j<fbo->getHeight()/dist_factor; j++){
        uniquePoss.push_back(ofVec2f(i * dist_factor, j * dist_factor));
    }
   }
    //random shuffle
    ofRandomize(uniquePoss);
    //for(int i = 0; i < fbo->getWidth() * fbo->getHeight(); i++){
    //    cout <<uniquePoss[i][0] << endl;
    //}
    
    int numOfHoles = 20;
    
    for( int i = 0; i < numOfHoles; i++){ //pass the vector values as args
       //  royalty free image can be found at: http://pngimg.com/download/43480

        popSeeds.push_back(PopSeedSource("tinyPop", uniquePoss[i]));
        images.push_back(ofImage());
        
        popSeeds.push_back(PopSeedSource("smallPop", uniquePoss[i+numOfHoles]));
        images.push_back(ofImage());
        
        popSeeds.push_back(PopSeedSource("mediumPop", uniquePoss[i+numOfHoles*2]));
        images.push_back(ofImage());
        
        popSeeds.push_back(PopSeedSource("largePop", uniquePoss[i+numOfHoles*3]));
        images.push_back(ofImage());
    }
    //loading images
    for(int i = 0; i < images.size(); ++i) {
       images[i].load(popSeeds[i].getType() + ".png");
        
       images[i].resize(popSeeds[i].getRadius(), popSeeds[i].getRadius());
    }
    
}


//--------------------------------------------------------------
void PopSource::setName(string _name){
    name = _name;
}

//--------------------------------------------------------------
void PopSource::reset(){
    
    int red = ofRandom(60,112);
    popColor = ofColor(255,red,red);
    
}

//--------------------------------------------------------------
void PopSource::update(){
    for (int i = 0; i < popSeeds.size(); i++) {
    // update position
      popSeeds[i].updatePos();
      //bouncing off walls
      popSeeds[i].wallBounce();
        
    // ------- UNCOMMENT ME -----
      //bouncing cheese holes off eachother -> there is a bug here that I cannot figure out! When the balls bounce off eachother sometimes they get stuck. WHY!!!!! fixing this for the show
        
     // for (int j = 0; j < popSeeds.size(); j++)
      // if(i != j)
      //  popSeeds[i].seedBounce(popSeeds[j]); //the argument is not an int or float its an object
    }
    
}

//--------------------------------------------------------------
void PopSource::draw(){
    
    ofClear(255,255,255,50);
    ofSetColor(255,255,255, 50);
    //popcorn background
    int x = 0;
    while(x<fbo->getWidth()){
        ofSetColor(255,0,0);
        ofDrawRectangle(x, 0, 40, 1134);
        ofSetColor(255);
        ofDrawRectangle(x+100, 0, 40, 1134);
        x = x+100;
    }
    
    for (int i = 0; i < images.size(); i++) {
        images[i].draw(popSeeds[i].getPosX(), popSeeds[i].getPosY(), popSeeds[i].getRadius());
    }
}

//--------------------------------------------------------------
void PopSource::keyPressed(int key){

}

//--------------------------------------------------------------
void PopSource::keyReleased(int key){

}

//--------------------------------------------------------------
void PopSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void PopSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void PopSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void PopSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void PopSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void PopSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void PopSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void PopSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void PopSource::dragEvent(ofDragInfo dragInfo){

}
