#pragma once
#include "Vector2.h"


class Matrix2
{
public:
    //###########################################################################
    //internal coordinates
    union 
    {
        struct 
        {
            float xAxis[2];
            float yAxis[2];
        };
        struct 
        {
            Vector2 matrix[2];
        };
        struct 
        {
            float x1;
            float x2;
            float y1;
            float y2;
        };
        struct 
        {
            float M2[4];
        };

    };
    
    //###########################################################################

    void setRotate(float rot);

    //multiplication overloads
    Vector2 operator *(Vector2 rhs);
    Matrix2 operator *(Matrix2 rhs);


    operator float*();
    void operator =(const Matrix2 &other);


    Matrix2();
    Matrix2(const Matrix2& other);
    Matrix2(float pos1, float pos2, float pos3, float pos4);
    ~Matrix2();
    static Matrix2 identity();
};

