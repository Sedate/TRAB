#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	float G;

	ofImage BackGround;

	struct solarSystem
	{
		ofVec2f pos;
		ofVec2f velocity;
		ofVec2f distance;
		float speed, mass, xOrig, yOrig, radius;
		ofImage spriteTap;
		bool gravityForce = false;
	};
	solarSystem m1;
	solarSystem sun;
	solarSystem moon;
	solarSystem earth;
	solarSystem rangeS;
	solarSystem rangeT;

	void moviment(ofVec2f &pos, ofVec2f &velocity, float &speed, float &mass, double time)
	{
		velocity += (speed / mass);
		pos.x += velocity.x * time;
		velocity.limit(speed);
	}
	void returnMeteor(ofVec2f &pos)
	{
		if (pos.x >= ofGetWindowWidth())
		{
			pos.x = 10;
			pos.y = (rand() % ofGetWindowHeight());
		}
		if (pos.y >= ofGetWindowHeight())
		{
			pos.x = 10;
			pos.y = (rand() % ofGetWindowHeight());
		}
	}





	void gravity(solarSystem &meteor, solarSystem &Orbit, float gravity)
	{
		ofVec2f newPos;

		//m1*m2*G/d²
		//distanciaSM = sun.pos - m1.pos;
		ofVec2f distance = Orbit.pos - meteor.pos;
		//(sun.mass)*(m1.mass) * 5 / (distanciaSM*distanciaSM);
		meteor.pos -= (Orbit.mass)*(meteor.mass) * gravity / (distance * distance);

	}
};
