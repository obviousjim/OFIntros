#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //load the image object
    myImage.loadImage("myImage.jpg");
    
    //get the pixels from the image
    unsigned char* pixels = myImage.getPixels();

    //some images have alpha
	int bytesPerPixels = 3;
	if(myImage.getPixelsRef().getImageType() == OF_IMAGE_COLOR_ALPHA){
		bytesPerPixels = 4;
	}
	
    //let's manipulate the pixels by iterating through them
    //we could put stripes on the image
	/*
    for(int y = 0; y < myImage.getHeight(); y++){
		for(int x = 0; x < myImage.getWidth(); x++){
			int index = (y*myImage.getWidth()+x)*bytesPerPixels;
			if( (x % 10) > 5){ //how would you make verticle
				pixels[index+0] = 0;
				pixels[index+1] = 0;
				pixels[index+2] = 0;
				if(bytesPerPixels == 4){
					pixels[index+3] = 0;
				}
			}
		}
	}
	*/
	
    //OR
    //or a rough bluescreen
    for(int y = 0; y < myImage.getHeight(); y++){
		for(int x = 0; x < myImage.getWidth(); x++){
			int index = (y*myImage.getWidth()+x)*bytesPerPixels;
			if(pixels[index] < 80 && pixels[index+1] < 80 && pixels[index+2] > 80){
				pixels[index+0] = 0;
				pixels[index+1] = 0;
				pixels[index+2] = 0;				
				if(bytesPerPixels == 4){
					pixels[index+3] = 0;				
				}
			}
		}
	}
	
    //after we're done we need to put the pixels back into the image so the changes show up
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