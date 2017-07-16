#pragma once
#include "State.h"
class CorrectState :
    public State
{
public:
    CorrectState();
    ~CorrectState();
    void update();
	void draw();
};

