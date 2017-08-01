#include "IncorrectState.h"



IncorrectState::IncorrectState()
{
    m_texture = inCorrectSprite;
    m_Gameobject.setSprite(m_texture);
    ID = StateManager::States::INCORRECT;
}


IncorrectState::~IncorrectState()
{
}

void IncorrectState::update()
{
}


