#pragma once
//set up so that update just calls this update

#include "Renderer2D.h"
#include "Gameobject.h"

class State
{
public:
    
    State();
    virtual ~State();
    virtual void update() = 0;

protected:
    Gameobject m_Gameobject;
};

