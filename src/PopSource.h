#pragma once

#include "ofMain.h"
#include "PopSeedSource.h"
#include "FboSource.h"



class PopSource : public ofx::piMapper::FboSource{
    
    private:
    //cheese radius from Large to Tiny
     //it can be a class called Cheese hole
     //Hole(size)
    vector<PopSeedSource> popSeeds;
    vector<ofImage> images;
    vector<ofVec2f> uniquePoss;
    

    public:
        void setup();
        void update();
        void draw();
        void reset();
        void setName(string _name);

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
        ofColor popColor;
    

    
 
    
    
};

