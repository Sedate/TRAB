#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup() {
	///Aumentar propocional 50 50, 100 100 planetT e solarTap, luaTap 84 72
	//Fundo
	ofBackground(200);
	G = 5.0f;

	//Sol
	sun.spriteTap.loadImage("Imagens/Sol.png");
	sun.spriteTap.resize(110, 110);
	sun.spriteTap.setAnchorPercent(0.5, 0.5);
	sun.pos.x = ofGetWindowWidth() / 2;
	sun.pos.y = ofGetWindowHeight() / 2;
	sun.mass = 500.0f;

	//Planeta
	earth.spriteTap.loadImage("Imagens/Planet.png");
	earth.spriteTap.resize(62, 62);
	earth.spriteTap.setAnchorPoint(0.5, 0.5);
	earth.xOrig = 480;
	earth.yOrig = 320;
	earth.mass = 100.0f;
	earth.radius = 260.0f;

	//Lua
	moon.spriteTap.loadImage("Imagens/Lua.png");
	moon.spriteTap.resize(30, 25);
	moon.spriteTap.setAnchorPercent(0.5, 0.5);
	moon.xOrig = earth.xOrig;
	moon.yOrig = earth.yOrig;
	moon.mass = 30.0f;
	moon.radius = 75.0f;

	//Orbita do sol
	rangeS.spriteTap.loadImage("Imagens/Range.png");
	rangeS.spriteTap.resize(550, 550);
	rangeS.spriteTap.setAnchorPercent(0.5, 0.5);
	rangeS.pos = sun.pos;
	
	//Orbita do planeta
	rangeT.spriteTap.loadImage("Imagens/Range1.png");
	rangeT.spriteTap.resize(150, 150);
	rangeT.spriteTap.setAnchorPercent(0.5, 0.5);

	//Meteoro
	m1.spriteTap.loadImage("Imagens/Meteor.png");
	m1.spriteTap.resize(80, 60);
	m1.pos.x = 150;
	m1.pos.y = 500;
	m1.speed = 30.0f;
	m1.mass = 0.3f;
	m1.spriteTap.setAnchorPercent(0.5, 0.5);

	//BackGround
	BackGround.loadImage("Imagens/Space.jpg");
}

//--------------------------------------------------------------
void ofApp::update()
{
	moviment(m1.pos, m1.velocity, m1.speed, m1.mass, ofGetLastFrameTime());
	returnMeteor(m1.pos);

	//circular movement
	earth.pos.x = earth.xOrig + earth.radius * cos(ofGetElapsedTimef());
	earth.pos.y = earth.yOrig + earth.radius * sin(ofGetElapsedTimef());
	moon.pos.x = earth.pos.x + 30 + moon.radius * cos(ofGetElapsedTimef());
	moon.pos.y = earth.pos.y + 30 + moon.radius * sin(ofGetElapsedTimef());

	if (m1.pos.x >= 300 && m1.pos.x <= 500 || m1.pos.y >= 120 && m1.pos.y <= 240)
	{
		gravity(m1, sun, G);
		gravity(m1, earth, G);
		gravity(m1, moon, G);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	BackGround.draw(0, 0);

	//Sun
	sun.spriteTap.draw(sun.pos);
	rangeS.spriteTap.draw(rangeS.pos);
	

	//Meteor
	m1.spriteTap.draw(m1.pos);
	
	//Earth
	rangeT.spriteTap.draw((earth.pos.x + 30), (earth.pos.y + 30));
	earth.spriteTap.draw(earth.pos);

	//Moon  
	moon.spriteTap.draw(moon.pos);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
