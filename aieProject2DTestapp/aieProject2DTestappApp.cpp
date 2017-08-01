#include "aieProject2DTestappApp.h"
#include "State.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Matrix3.h"


#define OBJECTTRANSFORM m_Gameobject.Transform2D


aieProject2DTestappApp::aieProject2DTestappApp() {}

aieProject2DTestappApp::~aieProject2DTestappApp() {

}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

bool aieProject2DTestappApp::startup() 
{


    
	m_2dRenderer = new aie::Renderer2D();
    m_stateManager = new StateManager;

    m_stateManager->setState(StateManager::States::CORRECT);
    

    return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void aieProject2DTestappApp::shutdown() 
{

	
	delete m_2dRenderer;
    delete m_stateManager;

    
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void aieProject2DTestappApp::update(float deltaTime) {

    
	// input example
	aie::Input* input = aie::Input::getInstance();


    if (m_stateManager->getState() != nullptr)
    {
        m_currentState = m_stateManager->getState();
    }

    m_currentState->OBJECTTRANSFORM.rotate(3 * deltaTime);
    

   
    if (input->isKeyDown(aie::INPUT_KEY_Q)){}

    if (input->isKeyDown(aie::INPUT_KEY_ENTER))
    {
        if (m_currentState->ID == StateManager::States::CORRECT)
        {
            m_stateManager->setState(StateManager::States::INCORRECT);
            
        }
        else
        {
            m_stateManager->setState(StateManager::States::CORRECT);
            
        }


    }

    m_currentState->OBJECTTRANSFORM.UpdateTransform();
    
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
    
}

 
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


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
    m_currentState->m_Gameobject.draw(m_2dRenderer);
    
	
    


    
     


    m_2dRenderer->end();

}












//    //fun little jojo reference put in draw
//m_2dRenderer->setRenderColour(1, 1, 1, 1);
//       
////m_2dRenderer->drawSpriteTransformed3x3(m_texture, );
//       
//m_2dRenderer->setRenderColour(0, 0, 0, 1);
//    // output some text, uses the last used colour
//m_2dRenderer->drawText(m_font, "F-MEGA", 600, 500);
