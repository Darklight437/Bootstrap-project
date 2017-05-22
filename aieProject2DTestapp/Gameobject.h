#pragma once
#include"ObjectManager.h"
#include <vector>
#include "Matrix3.h"

class Gameobject
{
public:
    Gameobject();
    virtual ~Gameobject();

    void addChild(Gameobject* child);

    void updateGlobalTransform();






protected:

    Matrix3 m_globalTransform;
    Matrix3 m_localtransform;

    Gameobject* m_parent;
    std::vector<Gameobject*> m_children;
   
};

