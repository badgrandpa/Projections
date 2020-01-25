#pragma once

#include "ofMain.h"
#include "FboSource.h"
#include "NoiseFieldSource.h"


class WaterParticleSource {
	public:
    
    WaterParticleSource(); // in a dition its also necesary to have a default constructor...
    WaterParticleSource(ofVec2f * start, float maxSpeed);//parameterised constructor; doesnt use void because its not a function, its a constructor
    
    //REMEMBER: a method is a function inside a class
    
    void run(); 
    void update();
    void applyForce(ofVec2f force);
    void show();
    void edges();
    void updatePreviousPos();
    void follow(NoiseFieldSource * NoiseFieldSource);
       

    private:
    
    ofVec2f * position; //ofVec2f does not take l
    ofVec2f * velocity;
    ofVec2f * acceleration;
    ofVec2f * previousPos;
    float maxSpeed;
    
};
