#include "IncorrectState.h"



IncorrectState::IncorrectState()
{
    m_texture = inCorrectSprite;
    m_Gameobject.setSprite(m_texture);
    ID = StateManager::States::INCORRECT;
    m_Gameobject.Transform2D.translateX(600);
    m_Gameobject.Transform2D.translateY(400);
    m_Gameobject.Transform2D.UpdateTransform();
}


IncorrectState::~IncorrectState()
{
}

void IncorrectState::update()
{
}


