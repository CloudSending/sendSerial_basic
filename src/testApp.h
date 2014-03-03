#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	
    public:
        void setup();
        void update();
        void draw();
        void keyPressed  (int key);
        void mousePressed(int x, int y, int button);
    
        void sendSerial(int data);
        void readSerial();
    
        string sentData;
    
        ofSerial	device;
};
