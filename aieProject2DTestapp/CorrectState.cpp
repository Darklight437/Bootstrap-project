#include "CorrectState.h"



CorrectState::CorrectState()
{
    m_texture = correctSprite;
    m_Gameobject.setSprite(m_texture);
    ID = StateManager::States::CORRECT;
    m_Gameobject.Transform2D.translateX(600);
    m_Gameobject.Transform2D.translateY(400);
    m_Gameobject.Transform2D.UpdateTransform();
}


CorrectState::~CorrectState()
{
}

void CorrectState::update()
{
}


