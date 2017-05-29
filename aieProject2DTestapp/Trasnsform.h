#pragma once
#include "Matrix3.h"


class Trasnsform
{
public:

	Trasnsform();
	~Trasnsform();

	Matrix3 m_localtransform;

	Matrix3 transform;
	Matrix3 roatation;
	Matrix3 scale;

	Matrix3 update();
	Matrix3 rotate(float rotateBy);
	Matrix3 scale(float scale);



};

