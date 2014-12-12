/**
 * @file Color.hh
 */

#ifndef COLOR_HH
#define COLOR_HH

#include <iostream>

using namespace std;

/**
 * Represents an RGB color
 */
class Color {
    float red;
    float green;
    float blue;
public:
    /**
     * Initialize a color to black
     */
    Color() {red=0; blue=0; green=0;}

    /**
     * Initialize to custom color
     * @param r Red component in [0, 1]
     * @param g Green component in [0, 1]
     * @param b Blue component in [0, 1]
     */
    Color(float r, float g, float b) : red(r), green(g), blue(b) {}

    float get_red() const;
    float get_green() const;
    float get_blue() const;
    void set_red(float val);
    void set_green(float val);
    void set_blue(float val);
    void clamp(float minVal, float maxVal);

    Color & operator+=(const Color &col);
    Color & operator-=(const Color &col);
    Color & operator*=(const Color &col);

    Color & operator*=(float factor);
    Color & operator/=(float factor);
};

const Color operator+(const Color &col1, const Color &col2); 
const Color operator-(const Color &col1, const Color &col2); 
const Color operator*(const Color &col1, const Color &col2);
const Color operator*(const Color &col, float s);
const Color operator*(float s, const Color &col);
const Color operator/(const Color &col, float s);
ostream & operator<<(ostream &os, const Color &col);
istream & operator>>(istream &is, Color &col);

#endif
