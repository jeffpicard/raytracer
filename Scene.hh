#ifndef SCENE_HH
#define SCENE_HH

#include "Color.hh"
#include "Ray.hh"
#include "Vector3F.hh"
#include "Camera.hh"
#include "Light.hh"
#include <vector>
#include <iostream>

#define NO_INTERSECT -1

using namespace std;


class SceneObject {
    Color surfaceColor;
public:
    SceneObject() : surfaceColor(Color(.5, .5, .5)) {}
    virtual ~SceneObject() {}
    Color getSurfaceColor() const {return surfaceColor;}
    void setSurfaceColor(const Color &c) {surfaceColor = c;}

    // if it doesn't intersect, returns NO_INTERSECT
    virtual float intersection(const Ray &r) const = 0;

    // assume X is on surface
    virtual Vector3F normal(const Vector3F &X) const = 0;

    // assume p is on surface?
    virtual Color colorAtPoint(const Vector3F &p) const {return surfaceColor;}
};






class Plane : public SceneObject {
    float d;
    Vector3F N;
public:
    Plane(float distance, const Vector3F &normal) : d(distance), N(normal) {}
    float getDistance() const {return d;}
    Vector3F getNormal() const {return N;}
    float intersection(const Ray &r) const;
    Vector3F normal(const Vector3F &X) const;
};






class Sphere : public SceneObject {
    Vector3F center;
    float radius;
public:
    Sphere(const Vector3F &c, float r) : center(c), radius(r) {}
    Vector3F getCenter() const {return center;}
    float getRadius() const {return radius;}
    int getIntersections(const Ray &r, float &t1, float &t2) const;
    float intersection(const Ray &r) const;
    Vector3F normal(const Vector3F &X) const;
};





class Scene {
    vector<SceneObject*> objects;
    vector<Light*> lights;
public:
    Scene() {}
    ~Scene();
    void addObject(SceneObject* o);
    void addLight(Light* l);
    Color traceRay(Ray &r) const;
    SceneObject* findClosestObject(const Ray &r, float &tIntersect) const;
    void render(const Camera &cam, int imgSize, ostream &os);
};


#endif
