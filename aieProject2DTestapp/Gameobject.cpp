#include "Gameobject.h"



Gameobject::Gameobject()
{
    
}


Gameobject::~Gameobject()
{

}





void Gameobject::draw(aie::Renderer2D * renderer)
{
    for (auto child : Trasnform2D.getChildren)
    {
        child->draw(renderer);
    }
}






void Gameobject::setname(std::string objectName)
{
    m_name = objectName;
}








