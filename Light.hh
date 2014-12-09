/** 
 *@file light.hh
 */

#ifndef LIGHT_HH
#define LIGHT_HH

#include "Vector3F.hh"
#include "Color.hh"
#include <boost/shared_ptr.hpp>

/** 
 * Represents a light
 */
class Light {
    Vector3F position;
    Color color;
public:
    /**
     * Initialize a light
     * @param p Position of the light
     * @param c Color of the light
     */
    Light(Vector3F p, Color c) : position(p), color(c) {}

    /**
     * Return the position of the light
     * @return Vector position of the light
     */
    Vector3F getPosition() const {return position;}

    /**
     * Return the color of the light
     * @return Color of the light
     */
    Color getColor() const {return color;}
};

// Boost shared-ownership smart pointer for lights
typedef boost::shared_ptr<Light> SPLight;


#endif
