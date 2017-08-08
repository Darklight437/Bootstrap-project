#include "PlayState.h"



PlayState::PlayState()
{
    m_texture = welcomeSprite;
    m_Gameobject.setSprite(m_texture);
    ID = StateManager::States::PLAY;
    m_Gameobject.Transform2D.translateX(600);
    m_Gameobject.Transform2D.translateY(400);
    m_Gameobject.Transform2D.UpdateTransform();
}


PlayState::~PlayState()
{
}

void PlayState::update()
{
    //call for the mutex


}


