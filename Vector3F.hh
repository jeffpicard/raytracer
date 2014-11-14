#ifndef VECTOR3F_HH
#define VECTOR3F_HH

#include <iostream>

using namespace std;

// Represent a vector of floats in 3 dimensional space
class Vector3F {
    float elems[3];
public:
    // Initialize vector with all components set to 0
    Vector3F() : elems{0} {}

    // Initialize a vector to a custom value
    // x is the x-componet
    // y is the y-component
    // x is the z-component
    Vector3F(float x, float y, float z) : elems{x, y, z} {}

    float operator[](int i) const;
    float & operator[](int i);

    Vector3F & operator+=(const Vector3F &v);
    Vector3F & operator-=(const Vector3F &v);

    Vector3F & operator*=(float factor);
    Vector3F & operator/=(float factor);

    float dot(const Vector3F &v) const;
    const Vector3F cross(const Vector3F &v) const;
    float mag() const;
    float magSq() const;
    Vector3F normalize() const;
};


const Vector3F operator+(const Vector3F &v1, const Vector3F &v2);
const Vector3F operator-(const Vector3F &v1, const Vector3F &v2);
const Vector3F operator*(const Vector3F &v, float factor);
const Vector3F operator*(float factor, const Vector3F &v);
const Vector3F operator/(const Vector3F &v, float factor);
const Vector3F operator-(const Vector3F &v);
ostream & operator<<(ostream &os, const Vector3F &v);
float operator*(const Vector3F &v1, const Vector3F &v2);


#endif
