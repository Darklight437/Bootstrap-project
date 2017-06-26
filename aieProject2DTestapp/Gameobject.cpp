#include "Gameobject.h"



Gameobject::Gameobject()
{
    Transform2D.masterObject = this;
    m_texture = nullptr;
    m_font = nullptr;
}


Gameobject::~Gameobject()
{

}





void Gameobject::draw(aie::Renderer2D* renderer)
{

    if ( m_texture != nullptr)
    {
        renderer->drawSpriteTransformed3x3(m_texture, Transform2D.m_globalTransform);
    }
    else if (m_font != nullptr)
    {
        renderer->drawText(m_font, m_text, );
    }

   


    for (auto child : Transform2D.m_children)
    {
        child->masterObject->draw(renderer);
    }
}

void Gameobject::setSprite(aie::Texture* texture)
{
    m_texture = texture;
}

void Gameobject::setsprite(aie::Font * font)
{
    m_font = font;
}

void Gameobject::setText(const char text)
{
    m_text = &text;
}





void Gameobject::setname(std::string objectName)
{
    m_name = objectName;
}








