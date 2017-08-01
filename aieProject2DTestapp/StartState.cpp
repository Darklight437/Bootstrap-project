#include "StartState.h"



StartState::StartState()
{
    ID = StateManager::States::START;
    m_Gameobject.Transform2D.translateY(3000);
    m_Gameobject.Transform2D.UpdateTransform();


}


StartState::~StartState()
{
}

void StartState::update()
{
}



