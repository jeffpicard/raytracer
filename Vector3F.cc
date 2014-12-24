/**
 * @file Vector3F.cc
 */

#include "Vector3F.hh"
#include <cmath>
#include <cassert>
#include <iostream>

/*************************************************************
 * Member functions and operator overloads for class Vector3F
 *************************************************************/

/**
 * Access a component of the vector
 * @param i The component to access: 0 for x, 1 for y, 2 for z
 * @return: The value of the specified component
 */
float Vector3F::operator[](int i) const {
    assert(i >= 0);
    assert(i < 3);
    return elems[i];
}

/**
 * Get a reference to a component of a vector for assignment
 * @param i The component to reference: 0 for x, 1 for y, 2 for z
 * @return: A reference to the given component of the vector
 */
float & Vector3F::operator[](int i) {
    assert(i >= 0);
    assert(i < 3);
    return elems[i];
}

/**
 * Increase a vector component-wise by v
 */
Vector3F & Vector3F::operator+=(const Vector3F &v) {
    for (int i = 0; i < 3; i++) {
        elems[i] += v[i];
    }
    return *this;
}

/**
 * Decrease a vector component-wise by v
 */
Vector3F & Vector3F::operator-=(const Vector3F &v) {
    for (int i = 0; i < 3; i++) {
        elems[i] -= v[i];
    }
    return *this;
}

/**
 * Multipy component-wise a vector's components by a scalar factor
 */
Vector3F & Vector3F::operator*=(float factor) {
    for (int i = 0; i < 3; i++) {
        elems[i] *= factor;
    }
    return *this;
}

/**
 * Divide each component of the vector by a scalar factor
 */
Vector3F & Vector3F::operator/=(float factor) {
    assert(factor != 0);
    *this *= 1 / factor;
    return *this;
}

/**
 * Compute the dot product
 * @param v The vector to dot with
 * @return The dot product with v
 */
float Vector3F::dot(const Vector3F &v) const{
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += this->elems[i] * v[i];
    }
    return sum;
}

/**
 * Compute the cross product
 * @param v The vector to cross with
 * @return: (*this) cross v
 */
const Vector3F Vector3F::cross(const Vector3F &v) const {
    float x, y, z;
    x = this->elems[1] * v[2] - this->elems[2] * v[1];
    y = this->elems[2] * v[0] - this->elems[0] * v[2];
    z = this->elems[0] * v[1] - this->elems[1] * v[0];
    return Vector3F(x,y,z);
}

/**
 * Compute the magnitude of a vector
 * @return: the magnitude
 */
float Vector3F::mag() const {
    return sqrtf(this->magSq());
}

/**
 * Compute the magnitude squared of a vector
 * @return The magnitude squared
 */
float Vector3F::magSq() const {
    return this->dot(*this);
}

/**
 * Return a normalized copy of the vector
 */
Vector3F Vector3F::normalize() const {
    return *this / this->mag();
}





/*************************************
 * Non member functions and overloads
 ************************************/

/**
 * Add two vectors component-wise
 */
const Vector3F operator+(const Vector3F &v1, const Vector3F &v2) {
    return Vector3F(v1) += v2;
}

/**
 * Subract two vectors component-wise
 */
const Vector3F operator-(const Vector3F &v1, const Vector3F &v2) {
    return Vector3F(v1) -= v2;
}

/**
 * Multiply each component of a vector by the scaler factor
 */
const Vector3F operator*(const Vector3F &v, float factor) {
    return Vector3F(v) *= factor;
}

/**
 * Multiply each component of a vector by the scaler factor
 */
const Vector3F operator*(float factor, const Vector3F &v) {
    return Vector3F(v) *= factor;
}

/**
 * Divide each component of a vector by the scaler factor
 */
const Vector3F operator/(const Vector3F &v, float factor) {
    assert(factor != 0);
    return Vector3F(v) /= factor;
}

/**
 * Unary minus for a vector: negate each component
 */
const Vector3F operator-(const Vector3F &v) {
    return Vector3F(v) *= -1;
}

/**
 * Print a vector in the format (x, y, z). Example: cout << v
 * prints (1, 2, -3).
 * @param os The stream to print to
 */
ostream & operator<<(ostream &os, const Vector3F &v) {
    os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

/**
 * Read a stream of the form '(3.3, -2.5, 4.1)' from is into v
 */
istream & operator>>(istream &is, Vector3F &v) {
    float x, y, z;
    char p1,c1,c2,p2;

    if (!is) return is;

    is >> p1 >> x >> c1 >> y >> c2 >> z >> p2;
    if (p1 != '(' || c1 != ',' || c2 != ',' || p2 != ')') {
        is.clear(ios_base::failbit);
    }
    if (is) v = Vector3F(x, y , z);
    return is;    
}

/**
 * Compute the dot product of two vectors
 * @param v1 The first vector in the product
 * @param v2 The second vector in the product
 * @return The dot product of the two vectors
 */
float operator*(const Vector3F &v1, const Vector3F &v2) {
    return v1.dot(v2);
}


/**
 * Project a onto b
 * @return a projected onto b as a Vector3F
 */
Vector3F project(const Vector3F &a, const Vector3F &b) {
    return b * ((a * b) / (b * b));
}
