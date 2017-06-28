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

void StateManager::setState(enum states changeto)
{


    //change to the state
}
