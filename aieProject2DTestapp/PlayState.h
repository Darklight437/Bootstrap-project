#pragma once
#include "State.h"
class PlayState :
    public State
{
public:
	//main state of gameplay
    PlayState();
    ~PlayState();
	void draw(aie::Renderer2D);
    void update(float deltaTime);
};

