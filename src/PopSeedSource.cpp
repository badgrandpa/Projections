#include "PopSeedSource.h"

void PopSeedSource::setup(){
    
  //  name = "Watermelon Hole FBO Source";
    allocate(756,1134);
}

PopSeedSource::PopSeedSource(){}

PopSeedSource::PopSeedSource(string inputType, ofVec2f inputPos){
    type = inputType;
    
    //based on the type we are setting the radius
    if(type == "tinyPop") {
        radius = 20;
        //getPosx()
    } else if (type == "smallPop") {
        radius = 30;
    } else if (type == "mediumPop"){
      radius = 50;
    } else if (type == "largePop"){
        radius = 60;
    }
    
    //prevent two ellipses from being drawn in the same area of pixels
    // need to implement... eventually...
    //I would be all of the different unique values
    //create a vector in the .h that sends the posX
    
    posX = inputPos[0];
    posY = inputPos[1];
    stepX = ofRandom(0.5,5);
    stepY = ofRandom(0.5,5);
    
}


//--------------------------------------------------------------

string PopSeedSource::getType(){
    return type;
}

float PopSeedSource::getPosX() {
      return posX;
}  //this is the implementation of the getter
  
float PopSeedSource::getPosY() {
      return posY;
}

int PopSeedSource::getRadius() {
      return radius;
}

void PopSeedSource::negateStep(){
    stepX = -stepX;
    stepY = -stepY;

}


void PopSeedSource::updatePos() {
    posX += stepX;
    posY += stepY;

}

void PopSeedSource::wallBounce(){
    // the reson why Im using a static values (756) instead of ofGetWidth() is because I was getting a crash on Pimapper
       if (posX > 756 - 1.5*radius || posX < 0.5*radius){
           stepX = -stepX; //bounces back untill it hits another wall, then goes back to to positive and so on.
       }

       if (posY > 1134 - 1.5*radius || posY < 0.5*radius){
           stepY = -stepY; //the term negate is used when turning negative to positive and vice versa
       }
}
//bouncing the cheese holes off eachother as well as off the walls
void PopSeedSource::seedBounce(PopSeedSource popSeed2){
    //first we are identifying the hole we want tand then calculating the radius
    if(distance2Seed(popSeed2) < radius + popSeed2.getRadius()) {
        negateStep();
        popSeed2.negateStep();
    }
}

//calculating the distance between two cheese holes so they can bounce between themselves
// used the Eucledian formula
// https://codereview.stackexchange.com/questions/144586/finding-the-distance-between-two-points-in-c
float PopSeedSource::distance2Seed(PopSeedSource popSeed2) {
    return sqrt(pow(posX - popSeed2.getPosX(), 2) + pow(posY - popSeed2.getPosY(), 2));
}
