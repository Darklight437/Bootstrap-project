#pragma once
#include <vector>
#include "Matrix3.h"
#include <string>

class Gameobject
{
public:
    Gameobject(std::string objectName);
    Gameobject();
    virtual ~Gameobject();

    void addChild(Gameobject* child);

    void updateGlobalTransform();






protected:

    Matrix3 m_globalTransform;
    Matrix3 m_localtransform;
    std::string m_name;
    Gameobject* m_parent;
    std::vector<Gameobject*> m_children;
   
};

