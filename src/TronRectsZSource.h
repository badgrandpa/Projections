#pragma once

#include "ofMain.h"
#include "FboSource.h"

class TronRectsZSource : public ofx::piMapper::FboSource {

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
    
        float numOfFrames;
        void oscilate(float rot, int index);
        ofColor rectColor;
        float rotDirX;
        float rotDirY;
        
        
};
