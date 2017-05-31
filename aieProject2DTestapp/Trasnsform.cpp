#include "Trasnsform.h"






Trasnsform::Trasnsform()
{
    m_parent = (nullptr);
}


Trasnsform::~Trasnsform()
{
    for (auto child : m_children)
    {
        delete child;
    }
}


void Trasnsform::UpdateTransform()
{  
        m_localtransform = m_roatation * m_scale* m_transform;

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
                child->update();
            }        
}

void Trasnsform::addChild(Trasnsform * child)
{
    if (child->m_parent == nullptr)
    {
        child->m_parent = this;
        m_children.push_back(child);
    }

}

std::vector<Trasnsform*> Trasnsform::getChilderen()
{
    return m_children;
}





void Trasnsform::setscale(const float scaleby)
{
	//multiply the scale values of the scale matrix by the float
	//update the scale matrix
    m_scale = Matrix3(scaleby, 0, 0, 0, scaleby, 0, 0, 0, scaleby);
}


