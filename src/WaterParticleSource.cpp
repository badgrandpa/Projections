#include "WaterParticleSource.h"


WaterParticleSource::WaterParticleSource(){}

WaterParticleSource::WaterParticleSource(ofVec2f * start, float maxspeed){
    
    maxSpeed = maxspeed;
    position = start;
    velocity = new ofVec2f(0, 0); //when we use ’new’ is creates a pointer
    acceleration = new ofVec2f(0, 0);
    previousPos = new ofVec2f(position->x, position->y);//to get preivous position we found the x and y positions
    
}

void WaterParticleSource::run(){
    
    update();
    edges();
    show();
    
}
void WaterParticleSource::update(){
    
    *position += *velocity; //using an operator addition-augmented assignment. Adding to the left what is on the right.
    
    velocity->limit(maxSpeed); // instead of operator we use a class method.
    
    *velocity += *acceleration;
    
    *acceleration *= 0; // multiplication-augmented assignment.
}

void WaterParticleSource::applyForce(ofVec2f force){
    
    *acceleration += force; 
    
}

void WaterParticleSource::show(){ //this is what is drawing
    ofPushMatrix();
   ofTranslate(756/2, 0);
    ofRotateDeg(45);
    ofDrawLine(position->x, position->y, previousPos->x, previousPos->y);
    ofPoint(position->x, position->y);
    ofPopMatrix();
    
    updatePreviousPos();
    
    // -> when we refer to a pointer to a vector
    // . when we refer to a vector
    // * takes the vector out of its pointer
    
}

void WaterParticleSource::edges(){
    
    if (position->x > 756*2) { //this is what creates the waterfall effect
      position->x = 0; // allows the repeittion of the pattern on the canvas
      updatePreviousPos();
    }
    if (position->x < 0) {
      position->x = 756;
      updatePreviousPos();
    }
    if (position->y > 1134) {
      position->y = 0;
      updatePreviousPos();
    }
    if (position->y < 0) {
      position->y = 1134;
      updatePreviousPos();
    }
    
}

void WaterParticleSource::updatePreviousPos(){
    
    this->previousPos->x = position->x;
    this->previousPos->y = position->y;
    
}

void WaterParticleSource::follow(NoiseFieldSource * NoiseFieldSource){

    int x = floor(position->x / NoiseFieldSource->getScale());
    int y = floor(position->y / NoiseFieldSource->getScale());
    int index = x + y * NoiseFieldSource->getCols();
    
    ofVec2f force = NoiseFieldSource->getVectors()[index];
    applyForce(force); //noise field is defnig the force using a vector. NoiseField defines the forces. Each vector corresponds to a force ehich is applied on the WaterParticleSource.
    
}



// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;

