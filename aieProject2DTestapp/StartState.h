#pragma once
#include "State.h"
class StartState :
    public State
{
public:
    StartState();
    ~StartState();
	void draw(aie::Renderer2D renderer);
    void update();
};

