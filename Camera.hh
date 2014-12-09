/**
 * @file Camera.hh
 */

#ifndef CAMERA_HH
#define CAMERA_HH

#include "Vector3F.hh"
#include "Ray.hh"


/**
 * Represents the camera where the raytraced image is seen from
 */
class Camera {
    Vector3F location;
    Vector3F direction;
    float viewing_angle;
    Vector3F cameraUp;
    Vector3F cameraRight;
    float dist;
public:
    Camera(Vector3F pos, Vector3F look, Vector3F up, float fov=60);
    Ray getRayForPixel(int x, int y, int imgSize) const;

};


#endif
