#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){
	//points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
}

//--------------------------------------------------------------
void testApp::draw(){
	//set the background to white
	
	ofBackground(255);
	//let's go through the points and draw 
	
	//set the current color to red
	ofSetColor(255, 0, 0);

	//make sure you don't make solid shapes, just outlines
	ofNoFill();
	//start making a path
	ofBeginShape();
	
	//add a vertex for every mouse click that we've seen
	for(int i = 0; i < points.size(); i++){
		ofVertex(points[i]);
	}
	
	//finish the path, the false means don't close the loop.
	ofEndShape(false);
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
	//create a point and add it to the end of the array
	ofPoint p;
	p = ofPoint(x,y);
	points.push_back(p);
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