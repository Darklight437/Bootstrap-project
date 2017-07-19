#include "StateManager.h"



StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

void StateManager::update()
{
    m_currState->update();
}



void StateManager::setState()
{


    //change to the state
}

void StateManager::draw(aie::Renderer2D currentrenderer)
{
	m_currState->draw(currentrenderer);
}
