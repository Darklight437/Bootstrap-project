#pragma once
//set up so that update just calls this update

#include "Renderer2D.h"

class State
{
public:
    
    State();
    virtual ~State();
    virtual void update() = 0;


};

