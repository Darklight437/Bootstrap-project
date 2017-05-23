#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "ObjectManager.h"
#include <string>

class aieProject2DTestappApp : public aie::Application {
public:

	aieProject2DTestappApp();
	virtual ~aieProject2DTestappApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();




protected:
    ObjectManager*      m_manager;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
    aie::Texture*       m_texture;
};