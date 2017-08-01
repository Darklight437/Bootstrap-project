#pragma once
#include "State.h"
class StartState :
    public State
{
public:
    StartState();
    ~StartState();
    void update();
};

