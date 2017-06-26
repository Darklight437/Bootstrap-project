#include "aieProject2DTestappApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Matrix3.h"

aieProject2DTestappApp::aieProject2DTestappApp() {}

aieProject2DTestappApp::~aieProject2DTestappApp() {

}

bool aieProject2DTestappApp::startup() {


    
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font((getExecutableFolder() +"/font/consolas.ttf").c_str(), 32);
    m_playertexture = new aie::Texture((getExecutableFolder() +"/textures/ship.png").c_str());



    Gameobject* emptySpinner = new Gameobject;
    emptySpinner->setname("emptySpinner");
    Gameobject* emptyMover = new Gameobject;
    emptyMover->setname("emptyMover");
    emptyMover->Transform2D.addChild(&emptySpinner->Transform2D);
    Gameobject* correctText = new Gameobject;
    Gameobject* incorrectText = new Gameobject;
    emptySpinner->Transform2D.addChild(&correctText->Transform2D);
    emptySpinner->Transform2D.addChild(&incorrectText->Transform2D);


    objectList.pushBack(emptyMover);
    objectList.pushBack(emptySpinner);
    objectList.pushBack(correctText);
    objectList.pushBack(incorrectText);

    return true;
}

void aieProject2DTestappApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
//    delete m_texture;
    
}

void aieProject2DTestappApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

    

   
    if (input->isKeyDown(aie::INPUT_KEY_Q)){}

    if (input->isKeyDown(aie::INPUT_KEY_D)){}

    if (input->isKeyDown(aie::INPUT_KEY_A)){}

    if (input->isKeyDown(aie::INPUT_KEY_W)){}

    if (input->isKeyDown(aie::INPUT_KEY_S)){}
    
    if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT)){}

    if (input->isKeyDown(aie::INPUT_KEY_LEFT_CONTROL)){}
    
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

    


}



 



void aieProject2DTestappApp::draw() 
{
    

	// wipe the screen to the background colour
    setBackgroundColour(192, 192, 192, 0);
    clearScreen();
    //set camera position before rendering
    m_2dRenderer->setCameraPos(0, 0);
	// begin drawing sprites
	m_2dRenderer->begin();
	// draw your stuff here!
    //call the draw function of the highest object to 
    


    
     // done drawing sprites


    m_2dRenderer->end();

}





std::string aieProject2DTestappApp::getExecutableFolder() const
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    char *pos;
    if (pos = strrchr(buffer, '\\'))
    {
        *pos = 0;
    }

    return buffer;
}

//    //fun little jojo reference put in draw
//m_2dRenderer->setRenderColour(1, 1, 1, 1);
//       
////m_2dRenderer->drawSpriteTransformed3x3(m_texture, );
//       
//m_2dRenderer->setRenderColour(0, 0, 0, 1);
//    // output some text, uses the last used colour
//m_2dRenderer->drawText(m_font, "F-MEGA", 600, 500);
