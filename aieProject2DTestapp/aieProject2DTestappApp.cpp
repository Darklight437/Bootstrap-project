#include "aieProject2DTestappApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"


aieProject2DTestappApp::aieProject2DTestappApp() {



}

aieProject2DTestappApp::~aieProject2DTestappApp() {

}

bool aieProject2DTestappApp::startup() {


    ObjectManager* manager = new ObjectManager();
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font(( manager->exePath+"/font/consolas.ttf").c_str(), 32);
    m_texture = new aie::Texture((manager->exePath+"/textures/car.png").c_str());


	return true;
}

void aieProject2DTestappApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
    delete m_texture;
    
}

void aieProject2DTestappApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void aieProject2DTestappApp::draw() {

	// wipe the screen to the background colour
    setBackgroundColour(192, 192, 192, 0.7);
    clearScreen();
    //set camera position before rendering
    m_2dRenderer->setCameraPos(0, 0);
	// begin drawing sprites
	m_2dRenderer->begin();









	// draw your stuff here!

    m_2dRenderer->setRenderColour(1, 1, 1, 1);
    
    m_2dRenderer->drawSprite(m_texture, 200, 200, 0, 0);


    m_2dRenderer->setRenderColour(0, 0, 0, 1);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "F-MEGA", 600, 500);

	// done drawing sprites
	m_2dRenderer->end();
}