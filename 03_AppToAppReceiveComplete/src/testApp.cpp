#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	//listen for incoming messages on a port
	// setup receiver with usage:
	//		receiver.setup( int port );
	
	port = 9000;
	receiver.setup( port );
	
	// load font to display incoming message
	
	font.loadFont("futura_book.otf", 20);
	
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
					typing = m.getArgAsString(0);
					
					// let's use a new random color
					color.r = ofRandom( 0, 255 );
					color.g = ofRandom( 0, 255 );
					color.b = ofRandom( 0, 255 );
				}
			}
		}
		
		// handle getting random OSC messages here
		else
		{
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(color);
	font.drawString( typing, 20, 30 );
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

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
