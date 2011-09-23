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
	titleFont.loadFont("futura_book.otf", 35);

//	ofSetLogLevel( OF_LOG_VERBOSE );

	// set bg to black!
	ofBackground( 0 );

	//Bonus stage material
	maxmessages=15;
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
		    //Bonus stage material:
		    //Identify host of incoming msg
		    string incomingHost = m.getRemoteIp();
		    //See if incoming host is already known:
            if ( std::find(knownhosts.begin(),knownhosts.end(),incomingHost) == knownhosts.end() ){
                knownhosts.push_back(incomingHost); //add new host to list
            }

			// get the first argument (we're only sending one) as a string
			if ( m.getNumArgs() > 0 ){
				if ( m.getArgType(0) == OFXOSC_TYPE_STRING){
//					string oldTyping = typing;
//					typing = m.getArgAsString(0) +"\n"+oldTyping;

                    //Bonus stage material:
                    //If vector has reached max size, delete the first/oldest element
                    if ( messages.size() == maxmessages ) messages.erase( messages.begin() );

                    //Add message text at the end of the vector
                    messages.push_back(m.getArgAsString(0));
                    broadcastReceivedMessage(m);
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

    //Display some information
    string title = "Listening for OSC messages on port " + ofToString( port ) + "\nKnown hosts: " + ofToString(knownhosts.size());
    titleFont.drawString(title, 20, 35);

    //Bonus stage material:
    typing="";
    // Concatenate a nice multiline string to display
    for (unsigned int i=0; i<messages.size(); i++){
        string oldTyping = typing;
        typing = oldTyping + "\n" + messages[i];
    }

    //Display the messages
	font.drawString( typing, 20, 90 );
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    //this is purely workaround for my mysterious OSCpack bug.
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

//Bonus stage material
void testApp::broadcastReceivedMessage(ofxOscMessage m){

    //Send message to all known hosts
    // use another port for now to avoid localhost loop
    for (unsigned int i=0;i<knownhosts.size();i++){
            sender.setup(knownhosts[i],port+1);
            sender.sendMessage(m);
    }
}
