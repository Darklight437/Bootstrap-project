#pragma once
class Vector2
{
public:
//###############################################################################
// internal coordinates
    float x;
    float y;
//###############################################################################


    //adds the two vectors and returns a third vector
    Vector2 operator+(Vector2& refVect);

    //suntract the first vector by the second
    Vector2 operator-(Vector2& refVect);

    //scale by the 2nd value
    Vector2 operator*(float scale);

    //multiply by another vect
    Vector2 operator*(Vector2 vect);

    operator float*();

    //multiplying by a scalar
    friend Vector2 operator * (float lhs, Vector2& rhs);

    //calculates and returns the magnitude as a float
    float magnitude();

    //returns a normalised copy of the vector
    Vector2 Vector2CpNorm();

    //normalises the current vector
    void normalise();
  
    //the dot product of the vector and another one returns a float
    float dot(Vector2);



    Vector2();
    ~Vector2();
    //overloaded to allow for initialisation on creation
    Vector2(float valuex, float valuey);

};

