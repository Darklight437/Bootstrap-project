#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Gameobject.h"
#include "StateManager.h"
#include "Trasnsform.h"
#include "ConsoleManager.h"
#include <string>
#include <Windows.h>
#include <vector>

class aieProject2DTestappApp : public aie::Application {
public:

	aieProject2DTestappApp();
	virtual ~aieProject2DTestappApp();

	virtual bool startup();
	virtual void shutdown();

    //core gameloop functions
	virtual void update(float deltaTime);
	virtual void draw();



protected:
    State*              m_currentState;
    StateManager*       m_stateManager;
    ConsoleManager*     m_Console;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
    aie::Texture*       m_yesTexture;
    aie::Texture*       m_noTexture;
    std::vector<aie::Texture> texturelist;

};