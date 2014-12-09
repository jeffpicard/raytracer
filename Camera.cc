/**
 * @file Camera.cc
 */

#include "Camera.hh"
#include <cmath>
#include <cassert>

/**
 * Initializes the camera.
 * @param pos Vector position of the camera
 * @param look Vector position of what the camera is looking at
 * @param up Vector representing the "up" direction for the camera
 * @param fov Field of view of the camera in degrees
 */
Camera::Camera(Vector3F pos, Vector3F look, Vector3F up, float fov) {
    location = pos;
    direction = (look - location).normalize();
    cameraRight = (direction.cross(up)).normalize();
    cameraUp = (cameraRight.cross(direction)).normalize();
    fov *= M_PI / 180;  // convert to radians
    dist = 0.5 / tanf(fov / 2.);
}

/**
 * Return the ray starting at the camera and going out in the direction of the
 * pixel.
 * @param x X-coordinate of pixel. 0 on the left, increasing to the right
 * @param y Y-coordinate of pixel. 0 at the top, increasing downwards
 * @param imgSize The number of pixels wide and tall the image is
 * @return The ray from the camera to the given pixel
 */
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
