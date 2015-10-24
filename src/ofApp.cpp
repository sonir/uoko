#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    

    //SetupScreen
    ofSetFrameRate(120);
    ofBackground(0);
    ofSetCircleResolution(50);
    
    //SetupNode (osc-hub)
    ofSystem("open ../../../data/launch");
    //Setup OSC
    osc = new Osc(OSC_PORT,this);

    //Yagi
    yagi.setup();
    
    sender.setup("224.0.0.1", SEND_OSC_PORT);
    

#ifdef DEBUG
    test();
#endif

    
}

//--------------------------------------------------------------
void ofApp::update(){

    osc->update();
    yagi.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,0);
    yagi.draw();
    
    ofSetColor(255);

#ifdef APP_BASIC
    ofDrawBitmapString("APP: BASIC", 10, 20);
#elif defined APP_UOKO
    ofDrawBitmapString("APP_MODE: UOKO" , 10, 20);
#endif
    
    
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 40);

    string phase;
    if(yagi.now_phase==VOID)phase = "VOID";
    if(yagi.now_phase==CLIMAX)phase = "CLIMAX";
    if(yagi.now_phase==ARRIVED)phase = "ARRIVED";
    ofDrawBitmapString(phase, 10, 60);
    
}

//--------------------------------------------------------------
void ofApp::test(){
    cout << "ofApp :: test" << endl;
    //Send test message to me
    ofxOscMessage m;
    m.setAddress("/seq/event");
    time_t start_time;
    time(&start_time);
    start_time+=4;
    m.addIntArg((int)start_time);
    m.addIntArg(6); //number of sequence

    m.addIntArg(0); //Delta time
    m.addIntArg(MAIN_M); //CMD
    m.addFloatArg(0.); //Delta time
    m.addFloatArg(0.6); //Delta time
    m.addFloatArg(0.7); //Delta time

    m.addIntArg(2000); //Delta time
    m.addIntArg(MAIN_M); //CMD
    m.addFloatArg(1.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time

    m.addIntArg(2000); //Delta time
    m.addIntArg(MAIN_M); //CMD
    m.addFloatArg(1.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time

    m.addIntArg(2000); //Delta time
    m.addIntArg(MAIN_M); //CMD
    m.addFloatArg(1.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time
    
    m.addIntArg(4000); //Delta time
    m.addIntArg(MAIN_M); //CMD
    m.addFloatArg(2.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time

    m.addIntArg(6000); //Delta time
    m.addIntArg(MAIN_M); //CMD
    m.addFloatArg(4.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time

    
    
    sender.sendMessage(m);

    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key == 't')test();        
    if(key == 'f')ofToggleFullscreen();
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
