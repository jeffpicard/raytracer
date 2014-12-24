/**
 * @file scene_generator.cc
 */

#include "scene_generator.hh"

scene_generator::scene_generator() {
//    readFuncs["plane"] = ReadPlane;
//    readFuncs["sphere"] = ReadSphere;
};

/**
 * Create a new plane object specified by the stream is
 */
SPSceneObject scene_generator::ReadPlane(istream &is) {
    Vector3F normal;
    float dist;
    Color col;
    float reflectivity;
    is >> normal >> dist >> col >> reflectivity;
    SPSceneObject p(new Plane(dist, normal));
    p->setSurfaceColor(col);
    p->set_reflectivity(reflectivity);
    return p;
};

/**
 * Create a new sphere object specified by the stream is
 */
SPSceneObject scene_generator::ReadSphere(istream &is) {
    Vector3F center;
    float radius;
    Color col;
    float reflectivity;
    is >> center >> radius >> col >> reflectivity;
    SPSceneObject s(new Sphere(center, radius));
    s->setSurfaceColor(col);
    s->set_reflectivity(reflectivity);
    return s;
};

/**
 * Create a new light object specified by the stream is
 */
SPLight scene_generator::ReadLight(istream &is) {
    Vector3F pos;
    Color col;
    is >> pos >> col;
    return SPLight(new Light(pos, col));
};

/**
 * Create a new camera object specified by the stream is
 */
SPCamera scene_generator::ReadCamera(istream &is) {
    Vector3F pos, look, up;
    is >> pos >> look >> up;
    return SPCamera(new Camera(pos, look, up));
};

/**
 * Return a new scene with SceneObjects, lights, and camera specified by
 * the stream is
 */
Scene scene_generator::read(istream &is) {
    Scene new_scene;
    string line;
    while (getline(is, line)) {
        stringstream line_stream(line);
        string type;
        line_stream >> type;

/*
        if (readFuncs.find(type) != readFuncs.end()) {
            SPSceneObject newObj = readFuncs[type](line_stream);
            new_scene.addObject(newObj);
        }
*/
        if (type == "plane") {
            SPSceneObject newPlane = ReadPlane(line_stream);
            new_scene.addObject(newPlane);
        }
        else if (type == "sphere") {
            SPSceneObject newSphere = ReadSphere(line_stream);
            new_scene.addObject(newSphere);
        }
        else if (type == "light") {
            SPLight newLight = ReadLight(line_stream);
            new_scene.addLight(newLight);
        }
        else if (type == "camera") {
            SPCamera newCamera = ReadCamera(line_stream);
            new_scene.set_camera(newCamera);
        }
        else {
            //error
        }

    }
    return new_scene;
};
