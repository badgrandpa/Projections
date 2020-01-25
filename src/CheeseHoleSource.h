#pragma once

#include "ofMain.h"
#include "FboSource.h"

class CheeseHoleSource : public ofx::piMapper::FboSource {
    public:
    void setup();
    //void reset();
    CheeseHoleSource(); // in a dition its also necesary to have a default constructor...
    CheeseHoleSource(string type, ofVec2f inputPos);//decides the size of the hole using the name
  //  void setName(string _name);
    string getType();
    float getPosX();
    float getPosY();
    int getRadius();
    void negateStep();
    void updatePos();
    void wallBounce();
    void holeBounce(CheeseHoleSource cheeseHole2);
    float distance2Hole(CheeseHoleSource cheeseHole2);
    
    //negating
    //https://www.geeksforgeeks.org/negate-function-in-c-stl/
        
    private:
    
    string type;
    int radius;
    float posX;
    float posY;
    float stepX;
    float stepY;
    
    //ofImage tiny;
   // ofImage small;
   // ofImage medium;
  //  ofImage large;
    
    
    
};
