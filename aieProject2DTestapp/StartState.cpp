#include "StartState.h"



StartState::StartState()
{
    m_texture = startupSprite;
    m_Gameobject.setSprite(m_texture);
    ID = StateManager::States::START;
    m_Gameobject.Transform2D.translateX(600);
    m_Gameobject.Transform2D.translateY(400);
    m_Gameobject.Transform2D.UpdateTransform();


}


StartState::~StartState()
{
}

void StartState::update()
{
}



