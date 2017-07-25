#pragma once
#include "State.h"
class IncorrectState :
    public State
{
public:
    IncorrectState();
    ~IncorrectState();
	void draw();
    void update(float deltaTime);
};

