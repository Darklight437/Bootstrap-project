#include "Gameobject.h"



Gameobject::Gameobject()
{
    
}


Gameobject::~Gameobject()
{

}





void Gameobject::draw(aie::Renderer2D * renderer)
{
    for (auto child : Trasnform2D.getChilderen)
    {
        child->draw(renderer);
    }
}




void Gameobject::update(float deltaTime)
{
    for (auto child : Trasnform2D.getChilderen())
    {
        child->update(deltaTime);
    }
}

void Gameobject::setname(std::string objectName)
{
    m_name = objectName;
}








