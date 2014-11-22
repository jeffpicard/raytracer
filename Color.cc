#include "Color.hh"
#include <cassert>
#include <iostream>



/************************************************************* 
 * Member functions and operator overloads for class Color
 *************************************************************/

// Accessor for the red component
// Returns red component in [0, 1]
float Color::get_red() const {
    return red;
}

// Accessor for the green component
// Returns green component in [0, 1]
float Color::get_green() const {
    return green;
}

// Accessor for the blue component
// Returns blue component in [0, 1]
float Color::get_blue() const {
    return blue;
}

// Mutate the red component
// Val is the new value for red in [0, 1]
void Color::set_red(float val) {
    red = val;
}

// Mutate the green component
// Val is the new value for green in [0, 1]
void Color::set_green(float val) {
    green = val;
}

// Mutate the blue component
// Val is the new value for blue in [0, 1]
void Color::set_blue(float val) {
    blue = val;
}

void Color::clamp(float minVal, float maxVal) {
    if (red < minVal) {red = 0;}
    if (green < minVal) {green = 0;}
    if (blue < minVal) {blue = 0;}
    float maxColor = maxVal;
    if (red > maxColor) {maxColor = red;}
    if (green > maxColor) {maxColor = green;}
    if (blue > maxColor) {maxColor = blue;}
    if (maxColor > maxVal) {
        red *= maxVal / maxColor;
        green *= maxVal / maxColor;
        blue *= maxVal / maxColor;
    }
    assert(red >= minVal);
    assert(red <= maxVal);
    assert(green >= minVal);
    assert(green <= maxVal);
    assert(blue >= minVal);
    assert(blue <= maxVal);
}


// Increases a color element-wise
// col is the amount to increase each component
Color & Color::operator+=(const Color &col) {
    red   += col.get_red();
    green += col.get_green();
    blue  += col.get_blue();
    return *this;
}

// Decreases a color element-wise
// col is the amount to decrease each component
Color & Color::operator-=(const Color &col) {
    red   -= col.get_red();
    green -= col.get_green();
    blue  -= col.get_blue();
    return *this;
}

// Filters a color
// col is the amount to element-wise multiply each component
Color & Color::operator*=(const Color &col) {
    red   *= col.get_red();
    green *= col.get_green();
    blue  *= col.get_blue();
    return *this;
}

// Multiplies each component of a color by factor
Color & Color::operator*=(float factor) {
    red   *= factor;
    green *= factor;
    blue  *= factor;
    return *this;
}

// Divides each component of a color by factor
Color & Color::operator/=(float factor) {
    red   /= factor;
    green /= factor;
    blue  /= factor;
    return *this;
}





/*************************************
 * Non member functions and overloads
 ************************************/

// Add two colors component-wise
const Color operator+(const Color &col1, const Color &col2) {
    return Color(col1) += col2;
}

// Subtract two colors component-wise
const Color operator-(const Color &col1, const Color &col2) {
    return Color(col1) -= col2;
}

// Multiply two colors component-wise
const Color operator*(const Color &col1, const Color &col2) {
    return Color(col1) *= col2;
}

// Multiply a color component-wise by a scalar
const Color operator*(const Color &col, float s) {
    return Color(col) *= s;
}

// Multiply a color component-wise by a scalar
const Color operator*(float s, const Color &col) {
    return Color(col) *= s;
}

// Divide a color component-wise by a scalar
const Color operator/(const Color &col, float s) {
    return Color(col) /= s;
}

// Print a color in the format (r, g, b)
ostream & operator<<(ostream &os, const Color &col){
    os << "(" << col.get_red() << ", " 
              << col.get_green() << ", " 
       << col.get_blue() << ")";
    return os;
}
