#pragma once
class Vector3
{
public:
    Vector3(float valuex, float valuey, float valuez);
    Vector3();
    Vector3(const Vector3& other);
    ~Vector3();
    //###############################################################################
    // internal coordinates
    float x;
    float y;
    float z;

    //###############################################################################


    //still not sure about this one
    //float Vector3Translate(const Vector3&a_first, const Vector3&a_second);


    //adds the two vectors and returns a third vector
    Vector3 operator+(Vector3& refVect);


    //suntract the first vector by the second
    Vector3 operator-(Vector3& refVect);

    //tie in code to cast the class into a pointer to work with the test
    operator float*();

    //scale by the 2nd value
    Vector3 operator*(float scale);

    //multiplying by a scalar
    Vector3 operator*(Vector3 vect);

    //assignment operator (vector = vector)
    Vector3 &operator = (const Vector3 &other);

    //the dot product of the vector and another one returns a float
    float dot(Vector3);

    //gets magnitude of the current vector
    float magnitude();

    //the cross product of two vectors
    Vector3 cross(Vector3);

    //returns a normalised copy of the vector
    Vector3 Vector3CpNorm();

    //the strange multip0lication to do float by vector this oe technically overloads float
    friend Vector3 operator * (float lhs, Vector3& rhs);

    //normalises the vector of the clas without returning anything
    void normalise();
private:


   
};

