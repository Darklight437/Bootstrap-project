#pragma once
class Vector4
{
public:
    //################################################################
    float x;
    float y;
    float z;
    float w;

    //################################################################

    //adds the two vectors and returns a third vector
    Vector4 operator+(Vector4& refVect);


    //suntract the first vector by the second
    Vector4 operator-(Vector4& refVect);

    //tie in code to cast the class into a pointer to work with the test
    operator float*();

    //scale by the 2nd value
    Vector4 operator*(float scale);


    //multiplying by a scalar
    Vector4 operator*(Vector4 vect);


    //the dot product of the vector and another one returns a float
    float dot(Vector4);

    //the cross product of two vectors
    Vector4 cross(Vector4);

    //gets magnitude of the current vector
    float magnitude();


    //returns a normalised copy of the vector
    Vector4 Vector4CpNorm();


    //normalises the vector of the clas without returning anything
    void normalise();

    //the strange multip0lication to do float by vector this oe technically overloads float
    friend Vector4 operator * (float lhs, Vector4& rhs);

    Vector4();
    Vector4::Vector4(float valuex, float valuey, float valuez, float valuew);
    ~Vector4();
};

