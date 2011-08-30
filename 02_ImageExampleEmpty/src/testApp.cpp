#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //load the image object
    myImage.loadImage("myImage.jpg");
    
    //get the pixels from the image
    //#1

    //some images have alpha
    //#2
	
    //let's manipulate the pixels by iterating through them
    //we could put stripes on the image
    //#3
	
    //OR
    //or a rough bluescreen
    //challenge #1
	
	// OR
	// create an image from some pixels
    //challenge #2
    
    //after we're done we need to put the pixels back into the image so the changes show up
    // array of pixels
    // image width
    // image height
    // reference to pixels array
    // rgb vs rgba
    myImage.setFromPixels(pixels, myImage.getWidth(), myImage.getHeight(), myImage.getPixelsRef().getImageType());
}

//--------------------------------------------------------------
void testApp::update(){
    //no need to use this
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //draw the image every frame, the changes you made in setup() will be there
    myImage.draw(0,0);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == 's'){
		myImage.saveImage("myImageSaved.png");
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