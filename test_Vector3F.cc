#include "Vector3F.hh"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace testing;

// Tests the compound assignment operators on Vector3F
TEST(Vector3FTest, CompoundAssignment) {
    Vector3F a(2.1, 1.3, -5.2);
    Vector3F b(3.0, -.5, 2.1);

    a += b;
    EXPECT_FLOAT_EQ(a[0], 5.1);
    EXPECT_FLOAT_EQ(a[1], .8);
    EXPECT_FLOAT_EQ(a[2], -3.1);

    a -= b;
    EXPECT_FLOAT_EQ(a[0], 2.1);
    EXPECT_FLOAT_EQ(a[1], 1.3);
    EXPECT_FLOAT_EQ(a[2], -5.2);

    a *= 2.5;
    EXPECT_FLOAT_EQ(a[0], 5.25);
    EXPECT_FLOAT_EQ(a[1], 3.25);
    EXPECT_FLOAT_EQ(a[2], -13.0);

    a /= 2.5;
    EXPECT_FLOAT_EQ(a[0], 2.1);
    EXPECT_FLOAT_EQ(a[1], 1.3);
    EXPECT_FLOAT_EQ(a[2], -5.2);
}

// Tests arithmetic operators on Vector3F
TEST(Vector3FTest, SimpleArithmetic) {
    Vector3F a(2.1, 1.3, -5.2);
    Vector3F b(3.0, -.5, 2.1);
    Vector3F c;
    
    c = a + b;
    EXPECT_FLOAT_EQ(c[0], 5.1);
    EXPECT_FLOAT_EQ(c[1], 0.8);
    EXPECT_FLOAT_EQ(c[2], -3.1);

    c = a - b;
    EXPECT_FLOAT_EQ(c[0], -.9);
    EXPECT_FLOAT_EQ(c[1], 1.8);
    EXPECT_FLOAT_EQ(c[2], -7.3);

    c = a * 2.5;
    EXPECT_FLOAT_EQ(c[0], 5.25);
    EXPECT_FLOAT_EQ(c[1], 3.25);
    EXPECT_FLOAT_EQ(c[2], -13.0);

    c = 2.5 * a;
    EXPECT_FLOAT_EQ(c[0], 5.25);
    EXPECT_FLOAT_EQ(c[1], 3.25);
    EXPECT_FLOAT_EQ(c[2], -13.0);

    c = a / 2.0;
    EXPECT_FLOAT_EQ(c[0], 1.05);
    EXPECT_FLOAT_EQ(c[1], 0.65);
    EXPECT_FLOAT_EQ(c[2], -2.6);

}

// Tests the unary minus operator with Vector3F
TEST(Vector3FTest, UnaryMinus) {
    Vector3F a(2.1, 1.3, -5.2);

    Vector3F b = -a;
    EXPECT_FLOAT_EQ(b[0], -2.1);
    EXPECT_FLOAT_EQ(b[1], -1.3);
    EXPECT_FLOAT_EQ(b[2], 5.2);
}

// Tests accessors and mutators
TEST(Vector3FTest, GettingSetting) {
    Vector3F a(2.1, 1.3, -5.2);
    a[1] = -24.3;
    EXPECT_FLOAT_EQ(a[1], -24.3);
}

// Tests stream output
TEST(Vector3FTest, Print) {
    Vector3F a(2.1, 1.3, -5.2);
    string expected("(2.1, 1.3, -5.2)");
    ostringstream stream;
    stream << a;
    string result = stream.str();
    EXPECT_EQ(result, expected);
}

// Tests vector math using Vector3F
TEST(Vector3FTest, VectorOps) {
    Vector3F a(2.0, 1.0, -5.0);
    Vector3F b(3.0, -1., 2.);
    Vector3F c;
    float result;

    result = a * b;
    EXPECT_FLOAT_EQ(result, -5.);

    result = b * a;
    EXPECT_FLOAT_EQ(result, -5.);
    
    c = a.cross(b);
    EXPECT_FLOAT_EQ(c[0], -3.);
    EXPECT_FLOAT_EQ(c[1], -19.);
    EXPECT_FLOAT_EQ(c[2], -5.);
    
    a = a.normalize();
    EXPECT_FLOAT_EQ(a[0] * a[0] + a[1]* a[1] + a[2] * a[2], 1.);

    result = a.mag();
    EXPECT_FLOAT_EQ(result, 1.0);
}


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
