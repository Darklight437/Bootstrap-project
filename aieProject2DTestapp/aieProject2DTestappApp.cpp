#include "aieProject2DTestappApp.h"
#include "State.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Matrix3.h"
#include "ConsoleManager.h"


#define OBJECTTRANSFORM m_Gameobject.Transform2D
#define CORRECTST StateManager::States::CORRECT
#define INCORRECTST StateManager::States::INCORRECT
#define STARTST StateManager::States::START
#define PLAYST StateManager::States::PLAY



aieProject2DTestappApp::aieProject2DTestappApp() {}

aieProject2DTestappApp::~aieProject2DTestappApp() {}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

bool aieProject2DTestappApp::startup() 
{


    
	m_2dRenderer = new aie::Renderer2D();
    m_stateManager = new StateManager;
    m_Console = new ConsoleManager;
    m_stateManager->setState(StateManager::States::START);
    m_Console->startup();

    return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void aieProject2DTestappApp::shutdown() 
{

	
	delete m_2dRenderer;
    delete m_stateManager;
    delete m_Console;
    
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void aieProject2DTestappApp::update(float deltaTime)
{

    
	// input setup
	aie::Input* input = aie::Input::getInstance();


    if (m_stateManager->getState() != nullptr)
    {
        m_currentState = m_stateManager->getState();
    }

    //spin the sprite for correct and incorrect
    if (m_currentState->ID == CORRECTST || m_currentState->ID == INCORRECTST)
    {
        //spin forever
        m_currentState->OBJECTTRANSFORM.rotate(3 * deltaTime);
    }

    //press enter to start
    if (input->isKeyDown(aie::INPUT_KEY_ENTER) && m_currentState->ID == STARTST)
    {
        m_stateManager->setState(PLAYST);
    }


    m_Console->run();


    if (m_currentState->ID == StateManager::States::PLAY)
    {

        if (m_Console->console.gotResult)
        {
            if (m_Console->console.consoleResult == true)
            {
                m_stateManager->setState(CORRECTST);
            }
            else if(m_Console->console.consoleResult == false)
            {
                m_stateManager->setState(INCORRECTST);
            }
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
