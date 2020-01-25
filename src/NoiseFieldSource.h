#pragma once

#include "ofMain.h"
#include "FboSource.h"

class NoiseFieldSource {

    public:
        NoiseFieldSource(); // in a dition its also necesary to have a default constructor...
        NoiseFieldSource(int r); //parameterised constructor; doesnt use void because its not a function, its a constructor
        
        int getScale();
        int getRows();
        int getCols(); //Implementation of getters that is the magic to make sketch communicate between eachother: https://www.w3schools.com/cpp/cpp_encapsulation.asp
    
    
        ofVec2f * getVectors(); // we need to return an array to use in WaterParticle.cpp
    // since this is not allowed in c++ we return a pointer to it instead. https://stackoverflow.com/questions/3473438/return-array-in-a-function
    
        void update();
        void display();
        
    private:
       // PVector[] vectors;
       // vector <float> vectors;
        
        int cols, rows;
        float increment = 0.1;
        int scale;
        ofVec2f * vectors; // array of 2D vectors. Using a pointer because it allows dynamic allocation (using new).
    
    
    // Daniel Shiffmans miniseries on Perlin Noise was SUPER HELPFULL in understnading not only the concept of noise and the versatility but als the use of clases. https://www.youtube.com/watch?v=Qf4dIN99e2w
    
    
    
};

