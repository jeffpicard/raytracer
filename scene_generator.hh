/**
 * @file scene_generator.hh
 */

#ifndef SCENE_GENERATOR_HH
#define SCENE_GENERATOR_HH

#include "Scene.hh"
#include "Vector3F.hh"
#include "Color.hh"
#include "Camera.hh"
#include "Light.hh"
#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/// Function pointer to read in scene objects
typedef SPSceneObject (*SceneObjectReader)(istream &is);

/**
 * Generates a scene by reading a config file or (later)
 * placing random objects
 */
class scene_generator {
    map<string, SceneObjectReader> readFuncs;
public:
    scene_generator();
    SPSceneObject ReadPlane(istream &is);
    SPSceneObject ReadSphere(istream &is);
    SPLight ReadLight(istream &is);
    SPCamera ReadCamera(istream &is);
    Scene read(istream &is);
};




#endif
