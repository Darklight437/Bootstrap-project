#pragma once
#include "State.h"
#include "Renderer2D.h"
#include <Vector>
class StateManager
{
public:
    StateManager();
    ~StateManager();
    void update();
    void setState();
	void draw(aie::Renderer2D);
protected:
    State* m_currState;
};

