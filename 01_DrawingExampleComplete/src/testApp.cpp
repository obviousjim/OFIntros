#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){
	//nothing to do in update
	//points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
	
}

//--------------------------------------------------------------
void testApp::draw(){
	//set the background to white
	
	ofBackground(255);
	//let's go through the points and draw 
	
	ofSetColor(255, 0, 0);
	ofNoFill();
	ofBeginShape();
	for(int i = 0; i < points.size(); i++){
		ofVertex(points[i]);
	}
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