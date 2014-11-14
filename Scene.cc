#include "Scene.hh"
#include <cmath>
#include <cassert>
#include <algorithm>


float Plane::intersection(const Ray &r) const {
    Vector3F P = r.getOrigin();
    Vector3F D = r.getDirection();
    if (D * N == 0) {
        return NO_INTERSECT;
    }
    float t = -(P * N + d) / (D * N);
    return t >= 0 ? t : NO_INTERSECT;
}


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

    for_each(objects.begin(), objects.end(), DeleteObject());
    for_each(lights.begin(), lights.end(), DeleteObject());
}

void Scene::addObject(SceneObject* o) {
    assert(o != 0);
    objects.push_back(o);
}

void Scene::addLight(Light *l) {
    assert(l != 0);
    lights.push_back(l);
}
