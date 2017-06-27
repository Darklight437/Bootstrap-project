#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Gameobject.h"

#include "Trasnsform.h"
#include <string>
#include <Windows.h>
#include <vector>

class aieProject2DTestappApp : public aie::Application {
public:

	aieProject2DTestappApp();
	virtual ~aieProject2DTestappApp();

	virtual bool startup();
	virtual void shutdown();
    //list of objects in the game
   
    Gameobject emptyMover;
    Gameobject emptySpinner;
    Gameobject correctText;
    Gameobject incorrectText;



	virtual void update(float deltaTime);
	virtual void draw();

    std::string getExecutableFolder() const;


protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
    aie::Texture*       m_yesTexture;
    aie::Texture*       m_noTexture;
    std::vector<aie::Texture> texturelist;

};