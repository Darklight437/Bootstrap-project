#include "StateManager.h"




StateManager::StateManager()
{
    //create one of each state here and store a pointer of it in the vector


}


StateManager::~StateManager()
{
}

void StateManager::setState(States changeTo)
{
    switch (changeTo)
    {

    case States::START:
        // learn how to do this again
        //iterate through the vector till you find the stored state that corresponds to this state



        break;

    case States::PLAY:
        break;

    case::States::CORRECT:
        break;

    case States::INCORRECT:
        break;

    case States::GAMEOVER:
        break;


    default:
        break;
    }

    //change to the state
}


void StateManager::update()
{
    m_currState->update();
}



void StateManager::draw(aie::Renderer2D currentrenderer)
{
	m_currState->draw(currentrenderer);
}

State * StateManager::findState(States toFind)
{

        
    return nullptr;
}
