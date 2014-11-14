#ifndef RAY_HH
#define RAY_HH

#include "Vector3F.hh"

class Ray {
    Vector3F origin;
    Vector3F direction;
public:
    Ray(const Vector3F &orig, const Vector3F &dir, bool normalize = true);
    Vector3F getOrigin() const;
    Vector3F getDirection() const;
    Vector3F getPointAtT(float t) const;

};



#endif
