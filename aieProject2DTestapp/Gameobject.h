#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include <vector>
#include <string>

class Gameobject
{
public:
    Gameobject();
    virtual ~Gameobject();

    void addChild(Gameobject* child);

    void updateGlobalTransform();


 virtual void draw(aie::Renderer2D* renderer);

 virtual void update(float deltaTime);
    




protected:

    Matrix3 m_globalTransform;
    Matrix3 m_localtransform;
    Gameobject* m_parent;
    std::vector<Gameobject*> m_children;
    

};