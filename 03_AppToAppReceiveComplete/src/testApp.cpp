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

	ofSetLogLevel( OF_LOG_VERBOSE );

	// set bg to black!
	ofBackground( 0 );

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
        //Log received message for easier debugging of participants' messages:
        ofLogVerbose("REcvd msg " + getOscMsgAsString(m) + " from " + m.getRemoteIp());

		// check the address of the incoming message
		if ( m.getAddress() == "/typing" )
		{
		    //Bonus stage material:
		    //Identify host of incoming msg
		    string incomingHost = m.getRemoteIp();
		    //See if incoming host is a new one:
            if ( std::find(knownhosts.begin(),knownhosts.end(),incomingHost) == knownhosts.end() ){
                knownhosts.push_back(incomingHost); //add new host to list
            }

			// get the first argument (we're only sending one) as a string
			if ( m.getNumArgs() > 0 ){

				if ( m.getArgType(0) == OFXOSC_TYPE_STRING){
                    //reimplemented message display:
                    //If vector has reached max size, delete the first/oldest element
                    if ( messages.size() == maxmessages ){
                        messages.erase( messages.begin() );
                    }
                    //Add message text at the end of the vector
                    messages.push_back(m.getArgAsString(0));

                    //Broadcast message to other chat participants
                    broadcastReceivedMessage(m.getArgAsString(0));
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

    //this is purely workaround for a mysterious OSCpack bug on 64bit linux
    // after startup, reinit the receiver
    // must be a timing problem, though - in debug, stepping through, it works.
	if ( ofGetFrameNum() == 60 ){
        receiver.setup(port);
	}
}

//--------------------------------------------------------------
void testApp::draw(){

    //Display some information
    string title = "Listening for OSC messages on\naaa.bbb.ccc.ddd:" + ofToString( port ) + ". Known chatters: " + ofToString(knownhosts.size());
    titleFont.drawString(title, 20, 37);

    //reimplemented message display:
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


string testApp::getOscMsgAsString(ofxOscMessage m){
	string msg_string;
	msg_string = m.getAddress();
	msg_string += ":";
	for ( int i=0; i<m.getNumArgs(); i++ )
	{
		// get the argument type
		msg_string += " " + m.getArgTypeName( i );
		msg_string += ":";
		// display the argument - make sure we get the right type
		if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
			msg_string += ofToString( m.getArgAsInt32( i ) );
		else if( m.getArgType( i ) == OFXOSC_TYPE_FLOAT )
			msg_string += ofToString( m.getArgAsFloat( i ) );
		else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
			msg_string += m.getArgAsString( i );
		else
			msg_string += "unknown";
	}
	return msg_string;
}

//Bonus stage material
void testApp::broadcastReceivedMessage(string chatmessage){

    //create a new OSC message
    ofxOscMessage m;
    m.setAddress("/chatlog");
    m.addStringArg(chatmessage);

    //Send message to all known hosts
    // use another port for now to avoid localhost loop
    for (unsigned int i=0;i<knownhosts.size();i++){
            sender.setup(knownhosts[i],port+1);
            m.setRemoteEndpoint(knownhosts[i],port+1);
            sender.sendMessage(m);
            ofLogVerbose("Broadcast message "+m.getArgAsString(0)+" to " + m.getRemoteIp()+":"+ofToString(m.getRemotePort()));
    }
}
