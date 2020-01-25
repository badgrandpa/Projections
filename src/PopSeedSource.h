#pragma once

#include "ofMain.h"
#include "FboSource.h"

class PopSeedSource : public ofx::piMapper::FboSource {
    public:
    void setup();
    //void reset();
    PopSeedSource(); // in a dition its also necesary to have a default constructor...
    PopSeedSource(string type, ofVec2f inputPos);//decides the size of the hole using the name
  //  void setName(string _name);
    string getType();
    float getPosX();
    float getPosY();
    int getRadius();
    void negateStep();
    void updatePos();
    void wallBounce();
    void seedBounce(PopSeedSource watermellonSeed2);
    float distance2Seed(PopSeedSource watermellonSeed2);
    
    //negating
    //https://www.geeksforgeeks.org/negate-function-in-c-stl/
        
    private:
    
    string type;
    int radius;
    float posX;
    float posY;
    float stepX;
    float stepY;

    
    
    
};
