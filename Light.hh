#ifndef LIGHT_HH
#define LIGHT_HH

#include "Vector3F.hh"
#include "Color.hh"
#include <boost/shared_ptr.hpp>


class Light {
    Vector3F position;
    Color color;
public:
    Light(Vector3F p, Color c) : position(p), color(c) {}
    Vector3F getPosition() const {return position;}
    Color getColor() const {return color;}
};

// Boost shared-ownership smart pointer for scene objects
typedef boost::shared_ptr<Light> SPLight;


#endif
