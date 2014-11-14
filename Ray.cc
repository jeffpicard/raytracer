#include "Ray.hh"
#include <cassert>

Ray::Ray(const Vector3F &orig, const Vector3F &dir, bool normalize) {
    origin = orig;
    direction = normalize ? dir.normalize() : dir;
}

Vector3F Ray::getOrigin() const {
    return origin;
}

Vector3F Ray::getDirection() const {
    return direction;
}

Vector3F Ray::getPointAtT(float t) const {
    assert(t >= 0);
    return origin + t * direction;
}
