#pragma once


#include "Renderer2D.h"
#include <Vector>
#include <algorithm>

class State;

class StateManager
{
public:

    enum class States { CORRECT, INCORRECT, PLAY, GAMEOVER, START };

    StateManager();
    ~StateManager();
    void setState(States changeTo);
    State* getState();

    State* findState(States findstate);
protected:
    State* m_currState;
    std::vector<State*> stateVect;
    aie::Renderer2D* renderEngine;
};

