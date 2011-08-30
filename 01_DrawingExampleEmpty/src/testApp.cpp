#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
	
    //set the background to white
    // in OF, you only have to do this once unless you call ofSetBackgroundAuto(false);
    //#1
}

//--------------------------------------------------------------
void testApp::update(){
	// uncomment this to add random points!
	//points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
}

//--------------------------------------------------------------
void testApp::draw(){
    //let's go through the points and draw 

    //set the current color to red
    //#2

    //make sure you don't make solid shapes, just outlines
    //#3
    
    //start making a path
    //#4
	
    //add a vertex for every mouse click that we've seen
    //#5
	
    //finish the path, the false means don't close the loop.
    //#6
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	// uncomment this to add a point every time you move your mouse

	//create a point and add it to the end of the array
    // challenge #1
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    //create a point and add it to the end of the array
    //#7
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