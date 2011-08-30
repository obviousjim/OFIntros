#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//set up the face finder.  this .xml file describes what faces look like to the finder
	//uncomment once the ofxOpenCV addon is added to the project
	//finder.setup("haarcascade_frontalface_default.xml");
	
	//initialize the video grabber
	grabber.initGrabber(320, 240);
}

//--------------------------------------------------------------
void testApp::update(){
	
	//grab a new frame from the camera stream
	grabber.update();
	
	//if we have a new frame, look for faces in it
    //#1
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//just draw what the camera is seeing
	grabber.draw(0,0);
	
	//set to draw only outlines
	ofNoFill();
	
	//for each face "blob" we found, draw a rectangle around the face
    //#2
    
    //challenege #1
    //put a smiley face :)
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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