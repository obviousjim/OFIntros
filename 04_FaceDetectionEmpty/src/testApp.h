#pragma once

#include "ofMain.h"
//#include "ofxCvHaarFinder.h"

/***************************************************************
 
 Face detection
 - this app demonstrates how to use OpenCV to find haar-like features	
 (http://en.wikipedia.org/wiki/Haar-like_features)
 - includes file for detecting faces
 
 ***************************************************************/

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

		ofVideoGrabber grabber;  // how OF gets camera input
	//uncomment this once you've added the ofxOpenCV addon
//		ofxCvHaarFinder finder;	 // object used to detect haar features
};
