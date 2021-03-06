/**
 * @file Ray.hh
 */

#ifndef RAY_HH
#define RAY_HH

#include "Vector3F.hh"

/**
 * Represent a ray in 3D space
 */
class Ray {
    Vector3F origin;
    Vector3F direction;
public:
    Ray(const Vector3F &orig, const Vector3F &dir, bool normalize = true);
    Vector3F getOrigin() const;
    Vector3F getDirection() const;
    Vector3F getPointAtT(float t) const;
    Ray reflect(const Vector3F &position, const Vector3F &normal, \
                float delta = 0.0001) const;
};

#endif
