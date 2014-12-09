/**
 * @file Color.cc
 */

#include "Color.hh"
#include <cassert>
#include <iostream>



/************************************************************* 
 * Member functions and operator overloads for class Color
 *************************************************************/

/**
 * Accessor for the red component
 * @return Red component in [0, 1]
 */
float Color::get_red() const {
    return red;
}

/**
 * Accessor for the green component
 * @return Green component in [0, 1]
 */
float Color::get_green() const {
    return green;
}

/**
 * Accessor for the blue component
 * @return Blue component in [0, 1]
 */
float Color::get_blue() const {
    return blue;
}

/**
 * Mutate the red component
 * @param val The new value for red in [0, 1]
 */
void Color::set_red(float val) {
    red = val;
}

/**
 * Mutate the green component
 * @param val The new value for green in [0, 1]
 */
void Color::set_green(float val) {
    green = val;
}

/**
 * Mutate the blue component
 * @param val The new value for blue in [0, 1]
 */
void Color::set_blue(float val) {
    blue = val;
}

/**
 * Trim the color components so they fall in the range [minVal, maxVal]. If any
 * component is higher (lower) than this range it is set to maxVal (minVal).
 * @param minVal The lowerbound such that all color components will be >= minVal
 * @param maxVal The upperbound such that all color coponents will be <= maxVal
 */
void Color::clamp(float minVal, float maxVal) {
    if (red < minVal) {red = minVal;}
    if (green < minVal) {green = minVal;}
    if (blue < minVal) {blue = minVal;}
    if (red > maxVal) {red = maxVal;}
    if (green > maxVal) {green = maxVal;}
    if (blue > maxVal) {blue = maxVal;}

    assert(red >= minVal);
    assert(red <= maxVal);
    assert(green >= minVal);
    assert(green <= maxVal);
    assert(blue >= minVal);
    assert(blue <= maxVal);
}


/**
 * Increases a color element-wise
 * @param col The amount to increase each component
*/
Color & Color::operator+=(const Color &col) {
    red   += col.get_red();
    green += col.get_green();
    blue  += col.get_blue();
    return *this;
}

/**
 * Decreases a color element-wise
 * @param col The amount to decrease each component
*/
Color & Color::operator-=(const Color &col) {
    red   -= col.get_red();
    green -= col.get_green();
    blue  -= col.get_blue();
    return *this;
}

/**
 * Filters a color
 * @param col The amount to element-wise multiply each component
*/
Color & Color::operator*=(const Color &col) {
    red   *= col.get_red();
    green *= col.get_green();
    blue  *= col.get_blue();
    return *this;
}

/**
 * Multiplies each component of a color by a scalar factor
 * @param factor The amount to multiply by
 */
Color & Color::operator*=(float factor) {
    red   *= factor;
    green *= factor;
    blue  *= factor;
    return *this;
}

/**
 * Divides each component of a color by a scalar factor
 * @param factor The amount to divide by
 */
Color & Color::operator/=(float factor) {
    red   /= factor;
    green /= factor;
    blue  /= factor;
    return *this;
}





/*************************************
 * Non member functions and overloads
 ************************************/

/**
 * Add two colors component-wise
 */
const Color operator+(const Color &col1, const Color &col2) {
    return Color(col1) += col2;
}

/**
 * Subtract two colors component-wise
 */
const Color operator-(const Color &col1, const Color &col2) {
    return Color(col1) -= col2;
}

/**
 * Multiply two colors component-wise
 */
const Color operator*(const Color &col1, const Color &col2) {
    return Color(col1) *= col2;
}

/**
 * Multiply a color component-wise by a scalar
 */
const Color operator*(const Color &col, float s) {
    return Color(col) *= s;
}

/** 
 * Multiply a color component-wise by a scalar
 */
const Color operator*(float s, const Color &col) {
    return Color(col) *= s;
}

/**
 * Divide a color component-wise by a scalar
 */
const Color operator/(const Color &col, float s) {
    return Color(col) /= s;
}

/**
 * Print a color in the format (r, g, b)
 * @param os The stream to print to
 */
ostream & operator<<(ostream &os, const Color &col){
    os << "(" << col.get_red() << ", " 
              << col.get_green() << ", " 
       << col.get_blue() << ")";
    return os;
}
