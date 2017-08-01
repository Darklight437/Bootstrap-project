#pragma once
//set up so that update just calls this update

#include "Renderer2D.h"
#include "Gameobject.h"
#include <Texture.h>
#include <Windows.h>

class State
{
public:
    
    State();
    virtual ~State();
    virtual void update() = 0;
    std::string getExecutableFolder() const;

protected:
    Gameobject m_Gameobject;
    aie::Texture* m_texture;
    aie::Texture* correctSprite;
    aie::Texture* inCorrectSprite;
};

