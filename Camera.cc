#include "Camera.hh"
#include <cmath>
#include <cassert>

Camera::Camera(Vector3F pos, Vector3F look, Vector3F up, float fov) {
    location = pos;
    direction = (look - location).normalize();
    cameraRight = (direction.cross(up)).normalize();
    cameraUp = (cameraRight.cross(direction)).normalize();
    fov *= M_PI / 180;  // convert to radians
    dist = 0.5 / tanf(fov / 2.);
}

Ray Camera::getRayForPixel(int x, int y, int imgSize) const {
    assert(x >= 0);
    assert(y >= 0);
    assert(x < imgSize);
    assert(y < imgSize);
    Vector3F pixelDir = dist * direction + 
                        (0.5 - (float) y / (float) (imgSize - 1)) * cameraUp +
                        ((float) x / (float) (imgSize - 1) - 0.5) * cameraRight;
    Ray pixelRay(location, pixelDir);
    return pixelRay;
}
