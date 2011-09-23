#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

/***************************************************************

 AppToAppReceivingExample
 - this app demonstrates using the ofxOsc addon
 - use with AppToAppSending example to send keyboard
 commands from application to application

 SETUP:
 - One computer:
	- compile and run!
 - Two computers:
	- see the setup step in the AppToAppS
	ending example

 ***************************************************************/

class testApp : public ofBaseApp{
	public:

		// default OF methods

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

		// AppToAppReceiving methods

		ofTrueTypeFont		font;		// font to draw incoming messages
		ofTrueTypeFont      titleFont;  // font for some info in the title line
		ofxOscReceiver		receiver;	// OSC receiver
		int					port;		// port we're listening on: must match port from sender!

		string				typing;		//typing you've received from another app

        // Cleaner message display variables
		vector<string>      messages;   //vector containing the received messages for display
		unsigned int        maxmessages;//nr of messages fitting on the screen

		//		Parse an OscMessage into a string for easy logging
		string getOscMsgAsString(ofxOscMessage m);

        //Bonus stage material
		vector<string>      knownhosts; //collected IP's of chat participants
		ofxOscSender        sender;
		void broadcastReceivedMessage(ofxOscMessage m); //Distribute a received message among the known hosts


};
