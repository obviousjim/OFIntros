#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //load the image object
    myImage.loadImage("myImage.jpg");
    
    //get the pixels from the image
    unsigned char* pixels = myImage.getPixels();
	
	//let's manipulate the pixels by iterating through them
    //or a rough bluescreen
    for(int y = 0; y < myImage.getHeight(); y++){
		for(int x = 0; x < myImage.getWidth(); x++){
			int index = (y*myImage.getWidth()+x)*3;
			
			// check the blue value ( pixels[index+2])
			int r = pixels[index];
			int g = pixels[index+1];
			int b = pixels[index+2];
			if(b > g+r){
				pixels[index+0] = 0;	//  r
				pixels[index+1] = 0;	//  g
				pixels[index+2] = 0;	//  b
			}
		}
	}
	
	//OR
    //we could put stripes on the image
	/*
    for(int y = 0; y < myImage.getHeight(); y++){
		for(int x = 0; x < myImage.getWidth(); x++){
			int index = (y*myImage.getWidth()+x)*bytesPerPixels;
            // % = modulo (http://en.wikipedia.org/wiki/Modulo_operation)
            // works like: num1 % num2 = remainder of num1 divided by num2 
            // e.g. 4 % 2 = 0; 11 % 10 = 1
			if( (x % 10) > 5){ //how would you make vertical
				pixels[index+0] = 0;
				pixels[index+1] = 0;
				pixels[index+2] = 0;
				if(bytesPerPixels == 4){
					pixels[index+3] = 0;
				}
			}
		}
	}*/
    
	// OR
	// create an image from some pixels
	/*
	int width	= 640;
	int height	= 480;
	
	// make a new array of pixels based on this width and height
	unsigned char* generativePixels = new unsigned char[width*height*3];
	
    for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			int index = (y*width+x)*3;
			generativePixels[index+0] = ofNoise(x,y)*ofRandom(255.0);	//  r
			generativePixels[index+1] = ofNoise(x,y)*ofRandom(255.0);	//  g
			generativePixels[index+2] = ofNoise(x,y)*ofRandom(255.0);	//  b
		}
	}
	myImage.setFromPixels(generativePixels, width, height, OF_IMAGE_COLOR);
	 
     */
	
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