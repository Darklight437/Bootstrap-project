#pragma once
#include "State.h"
#include "Renderer2D.h"
#include <Vector>

enum States { correct, incorrect, play, gameOver, start };

class StateManager
{
public:
    StateManager();
    ~StateManager();
    void update();
    void setState(states changeTo);
	void draw(aie::Renderer2D);
protected:
    State* m_currState;
    std::vector<State> stateVect;
};

