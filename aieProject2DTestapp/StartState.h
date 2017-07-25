#pragma once
#include "State.h"
class StartState :
    public State
{
public:
    StartState();
    ~StartState();
	void draw();
    void update(float deltaTime);
};

