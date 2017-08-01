#pragma once
#include "State.h"
#include "StartState.h"
#include "PlayState.h"
#include "CorrectState.h"
#include "IncorrectState.h"
#include "GameOverState.h"
#include "Renderer2D.h"
#include <Vector>
#include <algorithm>

enum class States { CORRECT, INCORRECT, PLAY, GAMEOVER, START };

class StateManager
{
public:
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

