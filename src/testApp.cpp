#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
    ofBackground(255);
	
	device.listDevices();
	vector <ofSerialDeviceInfo> deviceList = device.getDeviceList();
	int baud = 19200;
	device.setup(0, baud); //open the first device
	//device.setup("COM4", baud); // windows example
	//device.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0);

	string msg;
	msg += "click to test serial:\n";
	msg += "Sent: " + ofToString(sentData) + "\n";

	ofDrawBitmapString(msg, 50, 100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    cout << key << endl;
    sendSerial(key);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    // TO DO: fix to correctly send/receive array of chars
    string text = "Hello world.\n";
    int textLength = text.length();
	unsigned char* buffer = (unsigned char*) text.c_str();
    device.writeBytes(buffer, textLength);
    sentData = ofToString(buffer);
}

//--------------------------------------------------------------
void testApp::sendSerial(int data){
    device.writeByte(data);
    sentData = ofToString(data);
}

//--------------------------------------------------------------
void testApp::readSerial(){
    //TODO
}

