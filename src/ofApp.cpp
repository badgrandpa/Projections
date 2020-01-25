#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
    ofSetFrameRate(60);

	// Enable or disable audio for video sources globally
	// Set this to false to save resources on the Raspberry Pi
	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;

    // Add our BouncingBallsSource to list of fbo sources of the piMapper
	// FBO sources should be added before piMapper.setup() so the
	// piMapper is able to load the source if it is assigned to
	// a surface in XML settings.
    bouncingBallsSource = new BouncingBallsSource();
    bouncingBallsSource->setup();
    piMapper.registerFboSource(bouncingBallsSource);

    movingRectSource = new MovingRectSource();
    movingRectSource->setup();
    piMapper.registerFboSource(movingRectSource);
    
    //----------TronRects-----------
    
    tronRectsSource = new TronRectsSource();
    tronRectsSource->setup();
    piMapper.registerFboSource(tronRectsSource);
    
    tronRectsZSource = new TronRectsZSource();
    tronRectsZSource->setup();
    piMapper.registerFboSource(tronRectsZSource);
    
    tronRectsYSource = new TronRectsYSource();
    tronRectsYSource->setup();
    piMapper.registerFboSource(tronRectsYSource);
    
    //----------Bouncys-----------
    
    cheeseSource = new CheeseSource();
    cheeseSource->setup();
    piMapper.registerFboSource(cheeseSource);
    
    popSource = new PopSource();
    popSource->setup();
    piMapper.registerFboSource(popSource);
    
    //----------Waterfalls-----------
    
    waterfallSource = new WaterfallSource();
    waterfallSource->setup();
    piMapper.registerFboSource(waterfallSource);
    
 /*   cheeseHoleSource = new CheeseHoleSource();
    cheeseHoleSource->setup();
    piMapper.registerFboSource(cheeseHoleSource);*/
    
    
	piMapper.setup();

	// The info layer is hidden by default, press <i> to toggle
	// piMapper.showInfo();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	ofSetEscapeQuitsApp(false);

    dummyObjects.load("dummy-objects.png");

    //setup sceneManager to handle scene/present changes automatically
    sceneManager.setup("scenes.json", & piMapper);
}
//-----------------------------------------------------------
void ofApp::update(){
    if (ofGetElapsedTimeMillis() >= (3 * 60 * 1000) ) ofExit();
	piMapper.update();
    sceneManager.update();
}
//-----------------------------------------------------------
void ofApp::draw(){

    piMapper.draw();
}
//-----------------------------------------------------------
void ofApp::keyPressed(int key){
    //press 5 to go to previous preset (scene)
    if (key=='5') {
        if (piMapper.getNumPresets()>1){
            int targetScene = piMapper.getActivePresetIndex() - 1;
            if (targetScene<0) targetScene = piMapper.getNumPresets()-1;
            piMapper.setPreset(targetScene);
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    //press 6 to go to next preset (scene)
    else if (key=='6') {
        if (piMapper.getNumPresets()>1){
            piMapper.setNextPreset();
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    else if (key == '7'){
        piMapper.cloneActivePreset();
        piMapper.setPreset(piMapper.getNumPresets()-1);
        cout << "Cloned and switched to preset: " << piMapper.getActivePresetIndex() << endl;
    }

	piMapper.keyPressed(key);
}
//-----------------------------------------------------------
void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}
//-----------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}
//-----------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}
//-----------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}
