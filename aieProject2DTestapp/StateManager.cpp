#include "StateManager.h"




StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

void StateManager::setState(states changeTo)
{
    switch (changeTo)
    {
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
