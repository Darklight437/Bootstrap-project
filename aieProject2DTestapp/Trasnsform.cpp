#include "Trasnsform.h"






Transform::Transform()
{
    m_parent = (nullptr);
}


Transform::~Transform()
{
    for (auto child : m_children)
    {
//        delete child;
    }
}




void Transform::UpdateTransform()
{  
        m_localtransform = m_position * m_rotation *  m_scale;
        
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
                child->UpdateTransform();
            }        
}

void Transform::scale(float scaleby)
{

    m_scale.u.x1 += scaleby;
    m_scale.u.y2 += scaleby;
    

}

void Transform::addChild(Transform * child)
{
    if (child->m_parent == nullptr)
    {
        child->m_parent = this;
        m_children.push_back(child);
    }

}


void Transform::update(float deltaTime)
{
    for (auto child : m_children)
    {
        child->update(deltaTime);
    }
}




void Transform::setscale(const float scaleby)
{
	//multiply the scale values of the scale matrix by the float
	//update the scale matrix
    m_scale = Matrix3(scaleby, 0, 0, 0, scaleby, 0, 0, 0, scaleby);
}

void Transform::rotate(const float & amount)
{
    Matrix3 rotation;
    rotation.setRotateZ(amount);
    m_rotation = m_rotation * rotation;
}



void Transform::translateX(const float & amount)
{
    m_position.u.z1 += amount;
}

void Transform::translateY(const float & amount)
{
    m_position.u.z2 += amount;
}



