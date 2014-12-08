#include "Scene.hh"
#include "Camera.hh"
#include "Light.hh"
#include <iostream>

int main() {
    Scene testScene;

    SPSceneObject p1(new Plane(0, Vector3F(0,1,0)));
    p1->setSurfaceColor(Color(.5,0,.5));
    testScene.addObject(p1);

    SPSceneObject s1(new Sphere(Vector3F(-1.2,.5,0), .5));
    s1->setSurfaceColor(Color(1,0,0));
    testScene.addObject(s1);

    SPSceneObject s2(new Sphere(Vector3F(0,.5,0), .5));
    s2->setSurfaceColor(Color(0,1,0));
    testScene.addObject(s2);

    SPSceneObject s3(new Sphere(Vector3F(1.2,.5,0), .5));
    s3->setSurfaceColor(Color(0,0,1));
    testScene.addObject(s3);


    SPLight l1(new Light(Vector3F(-10,10,5), Color(.8,.8,.8)));
    testScene.addLight(l1);

    SPLight l2(new Light(Vector3F(5,3,5), Color(.3,.3,.3)));
    testScene.addLight(l2);

    Camera cam(Vector3F(-1.5,1,3), Vector3F(-.3,.5,0), Vector3F(0,1,0));

    testScene.render(cam, 400, cout);
    return 0;
}
