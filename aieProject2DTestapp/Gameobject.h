#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include <vector>
#include <string>


enum class GOType{spriteobject};

class Gameobject
{
public:
    Gameobject();
    virtual ~Gameobject() = 0;

    void addChild(Gameobject* child);

    void updateGlobalTransform();


 virtual void draw(aie::Renderer2D* renderer);

 virtual void update(float deltaTime);
    
 void setname(std::string objectName);

 void updateLocalTransform(Matrix3 transformTo);

 

 Matrix3 m_localtransform;


protected:

    Matrix3 m_globalTransform;

    std::string m_name;
    Gameobject* m_parent;
    std::vector<Gameobject*> m_children;
    

};