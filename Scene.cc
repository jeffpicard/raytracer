/**
 * @file Scene.cc
 */

#include "Scene.hh"
#include <cmath>
#include <cassert>
#include <algorithm>

/**
 * Calculate the t-value at which a ray first intersects this plane
 * @param r Intersecting ray
 * @return The t-value of the intersection, or NO_INTERSECT if the ray does not
 * intersect.
 */
float Plane::intersection(const Ray &r) const {
    Vector3F P = r.getOrigin();
    Vector3F D = r.getDirection();
    if (D * N == 0) {
        return NO_INTERSECT;
    }
    float t = -(P * N + d) / (D * N);
    return t >= 0 ? t : NO_INTERSECT;
}

/**
 * Returns the normal to the surface at point X
 * @param X The point on the surface to take the normal. Assumes X is on
 * the surface
 */
Vector3F Plane::normal(const Vector3F &X) const {
    return N;
}



/**
 * Calculate the t-value at which a ray first intersects the sphere
 * @param r Intersecting ray
 * @return The t-value of the intersection, or NO_INTERSECT if the ray does not
 * intersect.
 */
float Sphere::intersection(const Ray &r) const {
    float t1, t2;
    getIntersections(r, t1, t2);
    return t1;
}

/**
 * Returns the normal to the surface at point X
 * @param X The point on the surface to take the normal. Assumes X is on
 * the surface
 */
Vector3F Sphere::normal(const Vector3F &X) const {
    return (X - center).normalize();
}

/**
 * Calculate the t-values of all points at which a ray intersects the sphere
 * @param r Intersecting ray
 * @param t1 Modifies t1 to be the t-value of the first intersection, or
 * NO_INTERSECT if there're no intersections
 * @param t2 Modifies t2 to be the t-value of the second intersection, or
 * NO_INTERSECT if there're less than 2 intersections
 * @return the number of intersections
 */
int Sphere::getIntersections(const Ray &r, float &t1, float &t2) const {
    Vector3F P = r.getOrigin();
    Vector3F D = r.getDirection();
    Vector3F C = center;
    float a, b, c;

    a = D * D;
    b = 2 * (P * D - D * C);
    c = P * P + C * C - 2 * (P * C) - radius * radius;
    assert(a > 0);

    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) { // no solution
        t1 = t2 = NO_INTERSECT;
        return 0;
    } else if(discriminant == 0) { // one solution
        t1 = -b / 2 / a;
        if (t1 < 0) {
            t1 = t2 = NO_INTERSECT;
            return 0;
        } else {
            t2 = NO_INTERSECT;
            return 1;
        }
    } else { // 2 solutions
        t1 = (-b - sqrtf(discriminant)) / 2 / a;
        t2 = (-b + sqrtf(discriminant)) / 2 / a;
        if (t2 < 0) {
            t1 = t2 = NO_INTERSECT;
            return 0;
        } else if (t1 < 0) {
            t1 = t2;
            t2 = NO_INTERSECT;
            return 1;
        } else {
            return 2;
        }
    }
}


/**
 * Adds object o to the scene
 */
void Scene::addObject(SPSceneObject o) {
    assert(o != 0);
    objects.push_back(o);
}

/**
 * Adds light l to the scene
 */
void Scene::addLight(SPLight l) {
    assert(l != 0);
    lights.push_back(l);
}

/**
 * Sets c to be the scene's camera
 */
void Scene::set_camera(SPCamera c) {
    cam = c;
}

/**
 * Calculates the color that a given ray should be given the lights and
 * objects in the scene.
 * @param r The ray to trace
 * @return The color of the ray. Black if no object is intercepted.
 */
Color Scene::traceRay(Ray &r, int depth) const {
    int DEPTH_LIMIT = 10;
    float tIntersect;
    SPSceneObject object = findClosestObject(r, tIntersect);
    if (object == 0) { // no intersections
        return Color(0., 0., 0.);
    }
    Color result_color = Color(0, 0, 0);
    Vector3F intersect_loc = r.getPointAtT(tIntersect);

    vector<SPLight>::const_iterator it;
    for (it = lights.begin(); it != lights.end(); it++) {
        Vector3F L = ((*it)->getPosition() - intersect_loc).normalize();
        Vector3F N = object->normal(intersect_loc); // normal at intersection
        result_color += (*it)->getColor() * object->colorAtPoint(intersect_loc) \
                      * fmaxf(N * L, 0);
    }
    if (object->get_reflectivity() != 0 && depth < DEPTH_LIMIT) {
        Ray reflected_ray = r.reflect(intersect_loc, object->normal(intersect_loc));
        Color reflection_color = traceRay(reflected_ray, depth + 1);
        result_color += object->get_reflectivity() * reflection_color;
    }
    return result_color;
}

/**
 * Determines the first object in the scene a ray will intersect.
 * @param r The ray of interest
 * @param tIntersect This function modifies tIntersect to be the time of
 * intersection with the first object
 * @return shared_ptr to the object first intersected. 0 if this ray does
 * not intersect any objects 
 */
SPSceneObject Scene::findClosestObject(const Ray &r, float &tIntersect) const {
    vector<SPSceneObject>::const_iterator it;
    float t_min = 99999999.9;
    SPSceneObject object_min = 0;
    for (it = objects.begin(); it != objects.end(); it++) {
        float t_curr = (*it)->intersection(r);
        if (t_curr != NO_INTERSECT && t_curr < t_min) {
            t_min = t_curr;
            object_min = *it;
        }
    }
    tIntersect = t_min;
    return object_min;
}

/**
 * Prints the color of each pixel in an image.
 * @param imgSize The number of pixels wide and tall the image should be
 * @param os Where to print the image
 */
void Scene::render(int imgSize, ostream &os) {
    int maxVal = 255; // maximum color value for pixmap format
    os << "P3 " << imgSize << " " << imgSize << " " << maxVal << endl;
    for (int y = 0; y < imgSize; y++) {
        for (int x = 0; x < imgSize; x++) {
            Ray pixelRay = cam->getRayForPixel(x, y, imgSize);
            Color pixelColor = traceRay(pixelRay);

            pixelColor *= maxVal;
            pixelColor.clamp(0, maxVal);

            os << round(pixelColor.get_red()) << " "
               << round(pixelColor.get_green()) << " " 
               << round(pixelColor.get_blue()) << endl;

        }
    }
}
