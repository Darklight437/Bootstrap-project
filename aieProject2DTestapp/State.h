#pragma once
//set up so that update just calls this update

#include "Renderer2D.h"
#include "Gameobject.h"
#include <Texture.h>
#include <Windows.h>
#include "StateManager.h"

    
class State
{
public:
    StateManager::States ID;
   
    State();
    virtual ~State();
    virtual void update() = 0;
    std::string getExecutableFolder() const;
    Gameobject m_Gameobject;

protected:
    
    aie::Texture* m_texture;
    aie::Texture* correctSprite;
    aie::Texture* inCorrectSprite;
    aie::Texture* welcomeSprite;
};

