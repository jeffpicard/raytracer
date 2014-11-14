#include "Vector3F.hh"
#include <cmath>
#include <cassert>
#include <iostream>

/*************************************************************
 * Member functions and operator overloads for class Vector3F
 *************************************************************/

// Access a component of the vector
// i: The component to access: 0 for x, 1 for y, 2 for z
// Return: The value of the specified component
float Vector3F::operator[](int i) const {
    assert(i >= 0);
    assert(i < 3);
    return elems[i];
}

// Get a reference to a component of a vector for setting
// i: The component to reference: 0 for x, 1 for y, 2 for z
// Return: A reference to the given component of the vector
float & Vector3F::operator[](int i) {
    assert(i >= 0);
    assert(i < 3);
    return elems[i];
}

// Increase a vector component-wise by v
Vector3F & Vector3F::operator+=(const Vector3F &v) {
    for (int i = 0; i < 3; i++) {
        elems[i] += v[i];
    }
    return *this;
}

// Decrease a vector component-wise by v
Vector3F & Vector3F::operator-=(const Vector3F &v) {
    for (int i = 0; i < 3; i++) {
        elems[i] -= v[i];
    }
    return *this;
}

// Multipy component-wise a vector's components by factor
Vector3F & Vector3F::operator*=(float factor) {
    for (int i = 0; i < 3; i++) {
        elems[i] *= factor;
    }
    return *this;
}

// Divide each component of the vector by factor
Vector3F & Vector3F::operator/=(float factor) {
    assert(factor != 0);
    *this *= 1 / factor;
    return *this;
}

// Compute the dot product
// v: The vector to dot with
// return: The dot product with v
float Vector3F::dot(const Vector3F &v) const{
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += this->elems[i] * v[i];
    }
    return sum;
}

// Compute the cross product
// v: The vector to cross with
// return: (*this) cross v
const Vector3F Vector3F::cross(const Vector3F &v) const {
    float x, y, z;
    x = this->elems[1] * v[2] - this->elems[2] * v[1];
    y = this->elems[2] * v[0] - this->elems[0] * v[2];
    z = this->elems[0] * v[1] - this->elems[1] * v[0];
    return Vector3F(x,y,z);
}

// Compute the magnitude of a vector
// return: the magnitude
float Vector3F::mag() const {
    return sqrtf(this->magSq());
}

// Compute the magnitude squared of a vector
// Return: the magnitude squared
float Vector3F::magSq() const {
    return this->dot(*this);
}

// Return the normalized vector
Vector3F Vector3F::normalize() const {
    return *this / this->mag();
}






/*************************************
 * Non member functions and overloads
 ************************************/

// Add two vectors component-wise
const Vector3F operator+(const Vector3F &v1, const Vector3F &v2) {
    return Vector3F(v1) += v2;
}

// Subract two vectors component-wise
const Vector3F operator-(const Vector3F &v1, const Vector3F &v2) {
    return Vector3F(v1) -= v2;
}

// Multiply each component of a vector by the scaler factor
const Vector3F operator*(const Vector3F &v, float factor) {
    return Vector3F(v) *= factor;
}

// Multiply each component of a vector by the scaler factor
const Vector3F operator*(float factor, const Vector3F &v) {
    return Vector3F(v) *= factor;
}

// Divide each component of a vector by the scaler factor
const Vector3F operator/(const Vector3F &v, float factor) {
    assert(factor != 0);
    return Vector3F(v) /= factor;
}

// Unary minus for a vector: negate each component
const Vector3F operator-(const Vector3F &v) {
    return Vector3F(v) *= -1;
}

// Print a vector in the format (x, y, z)
ostream & operator<<(ostream &os, const Vector3F &v) {
    os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

// Compute the dot product of two vectors
// v1 the first vector in the product
// v2 the second vector in the product
// return The dot product of the two vectors
float operator*(const Vector3F &v1, const Vector3F &v2) {
    return v1.dot(v2);
}
