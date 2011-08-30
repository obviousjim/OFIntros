#pragma once

#include "ofMain.h"

/***************************************************************
 Drawing example
 
 - this app demonstrates how to draw points to the screen with 
   your mouse
 - click anywhere on screen to add a new point
 
 ***************************************************************/

class testApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
	// vector: (similar to ArrayList in Processing and arrays in ActionScript)
	// set of stored points to draw to the screen
	
	vector<ofPoint> points;
};
