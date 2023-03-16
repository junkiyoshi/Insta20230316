#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(3);
	ofSetCircleResolution(72);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);
	
	auto radius = 250;
	auto target_deg = ofGetFrameNum() % 360;
	auto target_location = glm::vec2(radius * cos(target_deg * DEG_TO_RAD), radius * sin(target_deg * DEG_TO_RAD));

	ofNoFill();
	for (int i = 0; i < 40; i++) {

		auto random_radius = ofRandom(200, 300);
		auto random_deg = ofRandom(360);
		auto random_location = glm::vec2(random_radius * cos(random_deg * DEG_TO_RAD), random_radius * sin(random_deg * DEG_TO_RAD));

		auto distance = glm::distance(random_location, target_location);
		auto size = ofMap(distance, 0, 30, 50, 0);

		ofDrawCircle(random_location, size);
	}

	ofFill();
	ofDrawCircle(target_location, 8);
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}