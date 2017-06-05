#include "Gameobject.h"



Gameobject::Gameobject()
{
    Transform2D.masterObject = this;
    m_texture = nullptr;
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
   


    for (auto child : Transform2D.m_children)
    {
        child->masterObject->draw(renderer);
    }
}

void Gameobject::setSprite(aie::Texture* texture)
{
    m_texture = texture;
}




void Gameobject::setname(std::string objectName)
{
    m_name = objectName;
}








