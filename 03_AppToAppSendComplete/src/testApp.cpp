#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60); // run at 60 fps
	ofSetVerticalSync(true);

	// set the background color to a lovely gray
	ofBackground( 150 );

	/*
		SETUP OSC SENDER

		usage: sender.setup( string host, int port );
			host:
				- if on one computer, set to "localhost"
				- if sending to another computer, set to the IP address
				  of second computer (found in network settings), e.g. "192.168.1.1"
			port:
				- this is arbitrary, but MUST match the port of the reciever application
	*/

	host	= "localhost";
	port	= 9000;

	sender.setup( host, port );

	/*
		Load font to display instructions + what you've typed
		simplest usage:
			font.loadFont(string filename, int fontsize );
	*/

	debugfont.loadFont("futura_book.otf", 12);
	giantFont.loadFont("futura_book.otf", 20);

	//Bonus stage material:
	recvPort = port+1;
	receiver.setup(recvPort);
}

//--------------------------------------------------------------
void testApp::update(){

    //Bonus stage material:
	// OSC receiver queues up new messages, so you need to iterate
	// through waiting messages to get each incoming message

	// check for waiting messages

	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );
        ofLogVerbose("got a message");
		// check the address of the incoming message
		if ( m.getAddress() == "/chatlog" )
		{
			// get the first argument (we're only sending one) as a string
			if ( m.getNumArgs() > 0 ){
				if ( m.getArgType(0) == OFXOSC_TYPE_STRING){
					string oldMessages = messages;
					messages = m.getArgAsString(0) +"\n"+oldMessages;
				}
			}
		}
	}

}

//--------------------------------------------------------------
void testApp::draw(){

	// draw some debug data + instructions to the screen with the font you loaded

	string debug			= "sending osc messages to " + string( host ) +" on port "+ ofToString( port );
	string instructions		= "type to create a new message. hit RETURN to send!";

	debugfont.drawString( debug, 20, 20);
	debugfont.drawString( instructions, 20, 40);

	// what have we typed so far?
	giantFont.drawString( typing, 20, 80);

	//Bonus stage material:
	debugfont.drawString(messages, 20, 100);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	// if we didn't hit return, add the key to our string
	if ( key != OF_KEY_RETURN ){

		// some trickery: ignore the backspace key
		if (key != OF_KEY_BACKSPACE){
			typing += key;
		} else {
			if (typing.size() > 0){
				typing.erase( typing.end() - 1 );
			}
		};
	}

	// hit Return, time to send the osc message
	else {

		// to send a string, create an ofxOscMessage object, give it an address
		// and add a string argument to the object

		ofxOscMessage m;
		m.setAddress( "/typing" );
		m.addStringArg( typing );
		sender.sendMessage( m );

		// clear out "typing"
		typing = "";
	}

	    //this is purely workaround for my mysterious OSCpack bug.
    // if there are problems, reinit the receiver
    // must be a timing problem, though - in debug, stepping through, it works.
    if ( key =='r' || key == 'R' ){
        receiver.setup( recvPort );
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){}

