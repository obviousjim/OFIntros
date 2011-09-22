#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

/***************************************************************
	AppToAppSendingExample
	- this app demonstrates using the ofxOsc addon
	- use with AppToAppReceiving example to send keyboard
	  commands from application to application
 
	SETUP:
	- One computer:
		- compile and run!
	- Two computers:
		- get the IP address of the second computer
			- Mac
				- open System Preferences
				- click on Network
				- in the area on the right, find your IP; it should look 
				  something like 192.168.1.100
			- PC

		- in testApp.cpp inside the setup() function, change the value of host
			to your IP (in quotes), e.g.:
			host = "192.168.1.100";
 
***************************************************************/

class testApp : public ofBaseApp{

	public:
		
		// CORE openFrameworks methods
		
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
	
		// AppToAppSending variables
		
		// OSC Sending variables
	
		ofxOscSender		sender;		// all-important ofxOscSender object
		string				host;		// IP address we're sending to (see above)
		int					port;		// port we're sending to
		string				typing;		// what we're going to send: some stuff you typed
	
		// debug + instructions
	
		ofTrueTypeFont		debugfont;		// font for drawing instructions to the screen
		ofTrueTypeFont		giantFont;		// font for drawing what you've typed to the screen
};

