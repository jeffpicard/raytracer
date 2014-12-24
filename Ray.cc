/**
 * @file Ray.cc
 */

#include "Ray.hh"
#include <cassert>

/**
 * Initialize a ray
 * @param orig Vector origin of the ray 
 * @param dir Vector direction of propagation
 * @param normalize true (default) makes the ray length 1 
 */
Ray::Ray(const Vector3F &orig, const Vector3F &dir, bool normalize) {
    origin = orig;
    direction = normalize ? dir.normalize() : dir;
}

/**
 * Return the origin of the ray
 */
Vector3F Ray::getOrigin() const {
    return origin;
}

/**
 * Return the direction of the ray
 */
Vector3F Ray::getDirection() const {
    return direction;
}

/**
 * Return the vector position of the tip of the ray after propagating for t
 * @param t Specifies the distance along the rays path.
 */
Vector3F Ray::getPointAtT(float t) const {
    assert(t >= 0);
    return origin + t * direction;
}

/**
 * stuff
 */
Ray Ray::reflect(const Vector3F &position, const Vector3F &normal, \
                 float delta) const {
    // compute direction of reflected ray using incident ray
    Vector3F D_par = project(-direction, normal);
    Vector3F D_r = direction + 2 * D_par;

    // new reflected ray
     Ray R_r(position + D_r * delta, D_r);
    return R_r;
}
