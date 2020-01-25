//
//  NoiseFieldSource.cpp
//  Week10_EndOfTermProject02 - Waterfall
//
//  Created by Alesandra on 07/01/2020.
//
#include "NoiseFieldSource.h"

NoiseFieldSource::NoiseFieldSource(){}

NoiseFieldSource::NoiseFieldSource(int resolution){

    scale = resolution;
    cols = floor(756*2 / resolution) + 1; //floor turns a decimal number into the nearest smaller ineger.
    rows = floor(1134*2 / resolution) + 1;

    vectors = new ofVec2f[cols * rows]; //pointer!!!!
}

int NoiseFieldSource::getScale() {
    return scale;
}  //this is the implementation of the getter

int NoiseFieldSource::getRows() {
    return rows;
}  //this is the implementation of the getter

int NoiseFieldSource::getCols() {
    return cols;
}  //this is the implementation of the getter

ofVec2f * NoiseFieldSource::getVectors() {
    return vectors;
}  //this is the implementation of the getter

void NoiseFieldSource::update(){
    
    //determines the location
    
    float xoff = 0;
       for (int y = 0; y < rows; y++) {
         float yoff = 0;
         for (int x = 0; x < cols; x++) {
             
          float angle = ofNoise(xoff, yoff) * PI * 4;
             
             ofVec2f vec = ofVec2f(angle);
             int index = x + y * cols;
             vectors[index] = vec;
            
           xoff += increment;
            
         }
         yoff += increment;
       }
    
}



void NoiseFieldSource::display(){
    
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
          int index = x + y * cols;
          ofVec2f vec = vectors[index];
          ofPushMatrix();
          ofTranslate(x * scale, y * scale);
          ofDrawLine(0, 0, scale, 0);
          ofPopMatrix();
        }
      }
}

