#include "CheeseHoleSource.h"

void CheeseHoleSource::setup(){
    
    name = "Cheese Hole FBO Source";
    allocate(756,1134);
}

CheeseHoleSource::CheeseHoleSource(){}

CheeseHoleSource::CheeseHoleSource(string inputType, ofVec2f inputPos){
    type = inputType;
    
    //based on the type we are setting the radius
    if(type == "tiny") {
        radius = 20;
        //getPosx()
    } else if (type == "small") {
        radius = 40;
    } else if (type == "medium"){
      radius = 50;
    } else if (type == "large"){
        radius = 60;
    }
    
    //prevent two ellipses from being drawn in the same area of pixels
    // need to implement... eventually...
    //I would be all of the different unique values
    //create a vector in the .h that sends the posX 
    
    posX = inputPos[0];
    posY = inputPos[1];
    stepX = ofRandom(0.2,2);
    stepY = ofRandom(0.2,2);
}


//--------------------------------------------------------------

string CheeseHoleSource::getType(){
    return type;
}

float CheeseHoleSource::getPosX() {
      return posX;
}  //this is the implementation of the getter
  
float CheeseHoleSource::getPosY() {
      return posY;
}

int CheeseHoleSource::getRadius() {
      return radius;
}

void CheeseHoleSource::negateStep(){
    stepX = -stepX;
    stepY = -stepY;
}


void CheeseHoleSource::updatePos() {
    posX += stepX;
    posY += stepY;
}

void CheeseHoleSource::wallBounce(){
    // the reson why Im using a static values (756) instead of ofGetWidth() is because I was getting a crash on Pimapper
       if (posX > 756 - 1.5*radius || posX < 0.5*radius){
           stepX = -stepX; //bounces back untill it hits another wall, then goes back to to positive and so on.
       }

       if (posY > 1134 - 1.5*radius || posY < 0.5*radius){
           stepY = -stepY; //the term negate is used when turning negative to positive and vice versa
       }
}
//bouncing the cheese holes off eachother as well as off the walls
void CheeseHoleSource::holeBounce(CheeseHoleSource cheeseHole2){
    //first we are identifying the hole we want tand then calculating the radius
    if(distance2Hole(cheeseHole2) < radius + cheeseHole2.getRadius()) {
        negateStep();
        cheeseHole2.negateStep(); 
    }
}

//calculating the distance between two cheese holes so they can bounce between themselves
// used the Eucledian formula
// https://codereview.stackexchange.com/questions/144586/finding-the-distance-between-two-points-in-c
float CheeseHoleSource::distance2Hole(CheeseHoleSource cheeseHole2) {
    return sqrt(pow(posX - cheeseHole2.getPosX(), 2) + pow(posY - cheeseHole2.getPosY(), 2));
}
