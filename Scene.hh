/**
 * @file Scene.hh
 */

#ifndef SCENE_HH
#define SCENE_HH

#include "Color.hh"
#include "Ray.hh"
#include "Vector3F.hh"
#include "Camera.hh"
#include "Light.hh"
#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>

#define NO_INTERSECT -1

using namespace std;

/**
 * Abstract class representing a generic object in a scene
 */
class SceneObject {
    Color surfaceColor;
public:
    /**
     * Initialize surface color to gray
     */
    SceneObject() : surfaceColor(Color(.5, .5, .5)) {}
    virtual ~SceneObject() {}

    /**
     * Return surface color of object
     */
    Color getSurfaceColor() const {return surfaceColor;}

    /**
     * Set surface color of object to c
     */
    void setSurfaceColor(const Color &c) {surfaceColor = c;}

    /**
     * Calculate the t-value at which a ray first intersects this object
     * @param r Intersecting ray
     * @return The t-value of the intersection, or NO_INTERSECT if the ray
     * does not intersect
     */
    virtual float intersection(const Ray &r) const = 0;

    /**
     * Returns the normal to the surface at a given point.
     * @param X The point of the normal. Assumes x is on surface.
     * @return Vector representing the normal
     */
    virtual Vector3F normal(const Vector3F &X) const = 0;

    /**
     * Returns the color at point p on the surface. Assumes p is on the surface.
     */
    virtual Color colorAtPoint(const Vector3F &p) const {return surfaceColor;}
};

// Boost shared-ownership smart pointer for scene objects
typedef boost::shared_ptr<SceneObject> SPSceneObject;



/**
 * Represents an infinite 2D plane in 3D space
 */
class Plane : public SceneObject {
    float d;
    Vector3F N;
public:
    /**
     * Initialize a plane
     * The normal vector of the plane
     * The shortest distance between the plane and origin
     */
    Plane(float distance, const Vector3F &normal) : d(distance), N(normal) {}
    float getDistance() const {return d;}
    Vector3F getNormal() const {return N;}
    float intersection(const Ray &r) const;
    Vector3F normal(const Vector3F &X) const;
};





/**
 * Represents a sphere in 3D space
 */
class Sphere : public SceneObject {
    Vector3F center;
    float radius;
public:
    /**
     * Initialize a sphere
     * @param c The vector center of the sphere
     * @param r The radius of the sphere
     */
    Sphere(const Vector3F &c, float r) : center(c), radius(r) {}
    Vector3F getCenter() const {return center;}
    float getRadius() const {return radius;}
    int getIntersections(const Ray &r, float &t1, float &t2) const;
    float intersection(const Ray &r) const;
    Vector3F normal(const Vector3F &X) const;
};




/**
 * Represents a scene including the objects, lights, and camera
 */
class Scene {
    vector<SPSceneObject> objects;
    vector<SPLight> lights;
public:
    Scene() {}
    ~Scene();
    void addObject(SPSceneObject o);
    void addLight(SPLight l);
    Color traceRay(Ray &r) const;
    SPSceneObject findClosestObject(const Ray &r, float &tIntersect) const;
    void render(const Camera &cam, int imgSize, ostream &os);
};


#endif
