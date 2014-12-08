#include "Scene.hh"
#include <cmath>
#include <cassert>
#include <algorithm>

/**
 * @brief Determines stuff
 *
 * @paramp[in] r ray to Blach
 *
 * @return The intersection tim
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
 * @brief stuff
 */
Vector3F Plane::normal(const Vector3F &X) const {
    return N;
}






float Sphere::intersection(const Ray &r) const {
    float t1, t2;
    getIntersections(r, t1, t2);
    return t1;
}

Vector3F Sphere::normal(const Vector3F &X) const {
    return (X - center).normalize();
}

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




/*for some reason this can't live inside ~Scene. I'll try to fix later */
    struct DeleteObject {
        template<typename T>
        void operator()(const T *ptr) const {
            delete ptr;
        }
    };

Scene::~Scene() {

//    for_each(objects.begin(), objects.end(), DeleteObject());
//    for_each(lights.begin(), lights.end(), DeleteObject());
}

void Scene::addObject(SPSceneObject o) {
    assert(o != 0);
    objects.push_back(o);
}

void Scene::addLight(SPLight l) {
    assert(l != 0);
    lights.push_back(l);
}

Color Scene::traceRay(Ray &r) const {
    float tIntersect;
    SPSceneObject object = findClosestObject(r, tIntersect);
    if (object == 0) { // no intersections
        return Color(0., 0., 0.);
    }
    Color finalColor = Color(0, 0, 0);
    Vector3F intersect_loc = r.getPointAtT(tIntersect);

    vector<SPLight>::const_iterator it;
    for (it = lights.begin(); it != lights.end(); it++) {
        Vector3F L = ((*it)->getPosition() - intersect_loc).normalize();
        Vector3F N = object->normal(intersect_loc);
        finalColor += (*it)->getColor() * object->colorAtPoint(intersect_loc) \
                      * fmaxf(N * L, 0);
    }
    return finalColor;
}

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

void Scene::render(const Camera &cam, int imgSize, ostream &os) {
    int maxVal = 255; // maximum color value for pixmap format
    os << "P3 " << imgSize << " " << imgSize << " " << maxVal << endl;
    for (int y = 0; y < imgSize; y++) {
        for (int x = 0; x < imgSize; x++) {
            Ray pixelRay = cam.getRayForPixel(x, y, imgSize);
            Color pixelColor = traceRay(pixelRay);

            pixelColor *= maxVal;
            pixelColor.clamp(0, maxVal);

            os << round(pixelColor.get_red()) << " "
               << round(pixelColor.get_green()) << " " 
               << round(pixelColor.get_blue()) << endl;

        }
    }
}
