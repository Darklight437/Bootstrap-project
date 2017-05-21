#pragma once

#include "Vector3.h"
class Matrix3
{
public:
    //###########################################################################
    //internal coordinates
    union MyUnion
    {
        MyUnion() {}
        ~MyUnion() {}

        struct
        {
            float xAxis[3];
            float yAxis[3];
            float zAxis[3];
        };
        struct
        {
            Vector3 matrix[3];
        };
        struct
        {
            float x1;
            float x2;
            float x3;
            float y1;
            float y2;
            float y3;
            float z1;
            float z2;
            float z3;
            
        };
        struct
        {
            float M3[9];
        };

    } u;

    //###########################################################################
    operator float*();


    //matrix rotations
    void setRotateX(float rot);
    void setRotateY(float rot);
    void setRotateZ(float rot);
    //matrix * vector
    Vector3 operator *(Vector3 rhs);

    //matrix * matrix
    Matrix3 operator *(Matrix3 rhs);

    //asignment operator
    Matrix3 & operator =(const Matrix3 &other);

    //square bracket operator overload to get a row
    Vector3& operator [] (int input);
    //identity matrix creator
    static Matrix3 identity();



    Matrix3();
    //copy constructor
    Matrix3(const Matrix3& other);
    Matrix3(float X1, float X2, float X3, float Y1, float Y2, float Y3, float Z1, float Z2, float Z3);
    ~Matrix3();
};

