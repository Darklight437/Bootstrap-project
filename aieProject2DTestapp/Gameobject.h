#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Trasnsform.h"
#include <vector>
#include <string>




class Gameobject
{
public:
    Gameobject();
    ~Gameobject() ;


    Transform Transform2D;
	void draw(aie::Renderer2D* renderer);
    void setSprite(aie::Texture* texture);
    void setFont(aie::Font* font);
    void setText(const char* text);
	void setname(std::string objectName);


protected:

    char m_text;
    aie::Texture* m_texture;
    std::string m_name;
    aie::Font* m_font;
};