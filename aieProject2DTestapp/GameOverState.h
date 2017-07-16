#pragma once
#include "State.h"
class GameOverState :
    public State
{
public:
    GameOverState();
    ~GameOverState();
    void update();
	void draw();
};

