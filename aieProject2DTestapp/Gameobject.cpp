#include "Gameobject.h"



Gameobject::Gameobject()
{
    m_parent = (nullptr);
}


Gameobject::~Gameobject()
{


    for (auto child :m_children)
    {
        delete child;
    }
}

void Gameobject::addChild(Gameobject * child)
{
    if (child->m_parent == nullptr)
    {
        child->m_parent = this;
        m_children.push_back(child);
    }

}

void Gameobject::updateGlobalTransform()
{

    if (m_parent != nullptr)
    {
        m_globalTransform = m_parent->m_globalTransform * m_localtransform;
        
    }
    else
    {
        m_globalTransform = m_localtransform;
    }
    for (auto child : m_children)
    {
        child->updateGlobalTransform();
    }
}

void Gameobject::draw(aie::Renderer2D * renderer)
{
    for (auto child : m_children)
    {
        child->draw(renderer);
    }
}



void Gameobject::update(float deltaTime)
{
    for (auto child : m_children)
    {
        child->update(deltaTime);
    }
}


