#pragma once
#include "Matrix3.h"
#include<vector>

class Trasnsform
{
public:

	Trasnsform();
	~Trasnsform();

	Matrix3 m_localtransform;
    Matrix3 m_globalTransform;
	


    void UpdateTransform();
	void setscale(const float scaleby);
    void addChild(Trasnsform * child);
    std::vector<Trasnsform*> getChilderen();

protected:




    Trasnsform* m_parent;
    std::vector<Trasnsform*> m_children;
    Matrix3 m_transform;
    Matrix3 m_roatation;
    Matrix3 m_scale;

};

