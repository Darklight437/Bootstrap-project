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





    mainObject.setSprite(m_playertexture);

    childship.setSprite(m_playertexture);


    mainObject.Transform2D.addChild(&empty1.Transform2D);
    empty1.Transform2D.addChild(&ship2ptr->Transform2D);


    childship.Transform2D.translateX(300);


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

    //switch (input->isKeyDown)
    //{
    //
    //}

    empty1.Transform2D.rotate(1 * deltaTime);

    if (input->isKeyDown(aie::INPUT_KEY_Q))
    {
        mainObject.Transform2D.rotate(0.5 * deltaTime);
    }

    if (input->isKeyDown(aie::INPUT_KEY_D))
    {
       mainObject.Transform2D.translateX(120 * deltaTime);
    }

    if (input->isKeyDown(aie::INPUT_KEY_A))
    {
        mainObject.Transform2D.translateX(-120 * deltaTime);
    }

    if (input->isKeyDown(aie::INPUT_KEY_W))
    {
        mainObject.Transform2D.translateY(120 * deltaTime);
    }

    if (input->isKeyDown(aie::INPUT_KEY_S))
    {
        mainObject.Transform2D.translateY(-120 * deltaTime);
    }
    

    if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
    {
        mainObject.Transform2D.scale(1 * deltaTime);
    }

    if (input->isKeyDown(aie::INPUT_KEY_LEFT_CONTROL))
    {
        mainObject.Transform2D.scale(-1 * deltaTime);
    }
    mainObject.Transform2D.UpdateTransform();
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
    
    mainObject.draw(m_2dRenderer);


    
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
