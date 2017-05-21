#pragma once
#include "Vector4.h"
class Matrix4
{
public:
    //###########################################################################
    //internal coordinates
    union
    {
        struct
        {
            float xAxis[4];
            float yAxis[4];
            float zAxis[4];
            float wAxis[4];
        };
        struct
        {
            Vector4 matrix[4];
        };
        struct
        {
            float x1;
            float x2;
            float x3;
            float x4;
            float y1;
            float y2;
            float y3;
            float y4;
            float z1;
            float z2;
            float z3;
            float z4;
            float w1;
            float w2;
            float w3;
            float w4;

        };
        struct
        {
            float M4[16];
        };

    };

    //###########################################################################


    //tie in code to cast the class into a pointer to work with the test
    operator float*();

    //matrix rotation

    void setRotateX(float rot);
    void setRotateY(float rot);
    void setRotateZ(float rot);

    //transform
    Vector4 operator *(Vector4 rhs);
    //matrix multiplication
    Matrix4 operator *(Matrix4 rhs);
    //asignment operator
    void operator =(const Matrix4 &other);

    //square bracket operator overload to get a column
    Vector4& operator [](int input);

    //identity matrix creator
    static Matrix4 identity();

    Matrix4();
    //copy constructor
    Matrix4(const Matrix4& other);
    Matrix4(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4);
    virtual ~Matrix4();
};

