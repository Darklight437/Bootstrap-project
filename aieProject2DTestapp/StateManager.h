#pragma once
#include "State.h"
#include <Vector>
class StateManager
{
public:
    StateManager();
    ~StateManager();
    void update();
    void setState(enum states changeto);

protected:
    State* m_currState;
};

