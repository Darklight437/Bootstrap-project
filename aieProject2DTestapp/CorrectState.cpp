#include "CorrectState.h"



CorrectState::CorrectState()
{
    m_texture = correctSprite;
    m_Gameobject.setSprite(m_texture);
    ID = StateManager::States::CORRECT;
}


CorrectState::~CorrectState()
{
}

void CorrectState::update()
{
}


