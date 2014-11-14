#include "gtest/gtest.h"
#include "Ray.hh"
#include "Light.hh"
#include "Scene.hh"
#include "Vector3F.hh"

using namespace testing;

/*
TEST(General, RayTest) {
}

TEST(General, Scene) {
}

TEST(SceneObjects, Plane) {
}
*/
TEST(SceneObjects, Sphere) {
    Vector3F origin(0,0,0);
    Vector3F dir(1,0,0);
    Ray beam(origin, dir);

    Vector3F center(2,0,0);
    Sphere target(center, 1.0);
    float result = target.intersection(beam);
    Vector3F boom = beam.getPointAtT(result);
    EXPECT_FLOAT_EQ(boom[0], dir[0]);
    EXPECT_FLOAT_EQ(boom[1], dir[1]);
    EXPECT_FLOAT_EQ(boom[2], dir[2]);

    float t1,t2;
    target.getIntersections(beam,t1,t2);
    EXPECT_FLOAT_EQ(t1, 1.0);
    EXPECT_FLOAT_EQ(t2, 3.0);
}



int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
