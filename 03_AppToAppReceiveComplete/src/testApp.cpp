#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60); // run at 60 fps
	ofSetVerticalSync(true);

	//listen for incoming messages on a port; setup OSC receiver with usage:
	port = 9000;
	receiver.setup( port );

	// load font to display incoming message
	font.loadFont("futura_book.otf", 30);

//	ofSetLogLevel( OF_LOG_VERBOSE );

	// set bg to black!
	ofBackground( 0 );
}

//--------------------------------------------------------------
void testApp::update(){

	// OSC receiver queues up new messages, so you need to iterate
	// through waiting messages to get each incoming message

	// check for waiting messages

	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );

		// check the address of the incoming message

		if ( m.getAddress() == "/typing" )
		{
			// get the first argument (we're only sending one) as a string
			if ( m.getNumArgs() > 0 ){
				if ( m.getArgType(0) == OFXOSC_TYPE_STRING){
					string oldTyping = typing;
					typing = m.getArgAsString(0) +"\n"+oldTyping;
				}
			}
		}

		// handle getting random OSC messages here
		else
		{
			ofSetLogLevel( OF_LOG_VERBOSE ); // need this to catch ofLogVerbose messages
			ofLogVerbose( "got weird message: " + m.getAddress() );
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	font.drawString( typing, 20, 50 );
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    //this is purely workaround for this mysterious OSCpack bug.
    // if there are problems, reinit the receiver
    // must be a timing problem, though - in debug, stepping through, it works.
    if ( key =='r' || key == 'R' ){
        receiver.setup( port );
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
