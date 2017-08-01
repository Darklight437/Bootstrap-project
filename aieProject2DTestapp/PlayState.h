#pragma once
#include "State.h"
class PlayState :
    public State
{
public:
	//main state of gameplay
    PlayState();
    ~PlayState();
    void update();

};

