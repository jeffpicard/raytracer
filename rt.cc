/**
 * @file rt.cc
 */

#include "scene_generator.hh"
#include <iostream>

int main() {
    scene_generator gen;
    Scene basic_scene = gen.read(cin);
    basic_scene.render(400, cout);
    return 0;
}
