#pragma once
#include "Matrix3.h"
#include<vector>
#include "Renderer2D.h"
//#include "Gameobject.h"

class Gameobject;

class Transform
{
public:

	Transform();
	~Transform();


    
	Matrix3 m_localtransform;
    Matrix3 m_globalTransform;
    Gameobject* masterObject;

    
    void UpdateTransform();
    void scale(float scaleby);
	void setscale(const float scaleby);
    void rotateX(const float& amount);
    void rotateY(const float& amount);
    void translateX(const float& amount);
    void translateY(const float& amount);

    void addChild(Transform * child);
    void update(float deltatime);
    
    std::vector<Transform*> m_children;

protected:




    Transform* m_parent;
    
    Matrix3 m_position;
    Matrix3 m_rotation;
    Matrix3 m_scale;

};

