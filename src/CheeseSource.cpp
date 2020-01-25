#include "CheeseSource.h"


//--------------------------------------------------------------
void CheeseSource::setup(){
    
    //ofSetFrameRate(60);
    ofBackground(0);
    //ofBackground(242,186,39);
    allocate(756,1134);
    
    name = "Cheese FBO Source";
    
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
    
    int numOfHoles = 15;
    
    for( int i = 0; i < numOfHoles; i++){ //pass the vector values as args
      //  royalty free image can be found at: https://clipartpng.com/?3142,swiss-cheese-png-clipart

        cheeseHoles.push_back(CheeseHoleSource("tiny", uniquePoss[i]));
        images.push_back(ofImage());
        
        cheeseHoles.push_back(CheeseHoleSource("small", uniquePoss[i+numOfHoles]));
        images.push_back(ofImage());
        
        cheeseHoles.push_back(CheeseHoleSource("medium", uniquePoss[i+numOfHoles*2]));
        images.push_back(ofImage());
        
        cheeseHoles.push_back(CheeseHoleSource("large", uniquePoss[i+numOfHoles*3]));
        images.push_back(ofImage());
    }
    //loading images
    for(int i = 0; i < images.size(); ++i) {
       images[i].load(cheeseHoles[i].getType() + ".png");
        
       images[i].resize(cheeseHoles[i].getRadius(), cheeseHoles[i].getRadius());
    }
}


//--------------------------------------------------------------
void CheeseSource::setName(string _name){
    name = _name;
}

//--------------------------------------------------------------
void CheeseSource::reset(){
    
    cheeseColor = ofColor(243,ofRandom(221,183),16);
    
}

//--------------------------------------------------------------
void CheeseSource::update(){
    for (int i = 0; i < cheeseHoles.size(); i++) {
    // update position
      cheeseHoles[i].updatePos();
      //bouncing off walls
      cheeseHoles[i].wallBounce();
        
    // ------- UNCOMMENT ME -----
      //bouncing cheese holes off eachother -> there is a bug here that I cannot figure out! When the balls bounce off eachother sometimes they get stuck. WHY!!!!! fixing this for the show
        
    //  for (int j = 0; j < cheeseHoles.size(); j++)
      //  if(i != j)
        //  cheeseHoles[i].holeBounce(cheeseHoles[j]); //the argument is not an int or float its an object
    }
    
}

//--------------------------------------------------------------
void CheeseSource::draw(){
    
    ofClear(cheeseColor);
    
    for (int i = 0; i < images.size(); i++) {
        images[i].draw(cheeseHoles[i].getPosX(), cheeseHoles[i].getPosY(), cheeseHoles[i].getRadius());
    }
}

//--------------------------------------------------------------
void CheeseSource::keyPressed(int key){

}

//--------------------------------------------------------------
void CheeseSource::keyReleased(int key){

}

//--------------------------------------------------------------
void CheeseSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void CheeseSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void CheeseSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void CheeseSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void CheeseSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void CheeseSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void CheeseSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void CheeseSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void CheeseSource::dragEvent(ofDragInfo dragInfo){ 

}
