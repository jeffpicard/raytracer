#include "Color.hh"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace testing;

// Tests compound assignment opererators on Color
TEST(ColorTest, CompoundAssignment) {
    Color a(.2, .8, .6);
    Color b(.5, .25, .75);

    a += b;
    EXPECT_FLOAT_EQ(a.get_red(), .7);
    EXPECT_FLOAT_EQ(a.get_green(), 1.05);
    EXPECT_FLOAT_EQ(a.get_blue(), 1.35);
    
    a -= b;
    EXPECT_FLOAT_EQ(a.get_red(), .2);
    EXPECT_FLOAT_EQ(a.get_green(), .8);
    EXPECT_FLOAT_EQ(a.get_blue(), .6);
    
    a *= b;
    EXPECT_FLOAT_EQ(a.get_red(), .1);
    EXPECT_FLOAT_EQ(a.get_green(), .2);
    EXPECT_FLOAT_EQ(a.get_blue(), .45);

    a *= 2.0;
    EXPECT_FLOAT_EQ(a.get_red(), .2);
    EXPECT_FLOAT_EQ(a.get_green(), .4);
    EXPECT_FLOAT_EQ(a.get_blue(), .9);

    a /= 2.0;
    EXPECT_FLOAT_EQ(a.get_red(), .1);
    EXPECT_FLOAT_EQ(a.get_green(), .2);
    EXPECT_FLOAT_EQ(a.get_blue(), .45);
}

// Tests arithmetic operators on Color
TEST(ColorTest, SimpleArithmetic) {
    Color a(.2, .8, .6);
    Color b(.5, .25, .75);
    Color c;
    
    c = a + b;
    EXPECT_FLOAT_EQ(c.get_red(), .7);
    EXPECT_FLOAT_EQ(c.get_green(), 1.05);
    EXPECT_FLOAT_EQ(c.get_blue(), 1.35);

    c = a - b;
    EXPECT_FLOAT_EQ(c.get_red(), -.3);
    EXPECT_FLOAT_EQ(c.get_green(), .55);
    EXPECT_FLOAT_EQ(c.get_blue(), -.15);

    c = a * b;
    EXPECT_FLOAT_EQ(c.get_red(), .1);
    EXPECT_FLOAT_EQ(c.get_green(), .2);
    EXPECT_FLOAT_EQ(c.get_blue(), .45);

    c = a * 2;
    EXPECT_FLOAT_EQ(c.get_red(), .4);
    EXPECT_FLOAT_EQ(c.get_green(), 1.6);
    EXPECT_FLOAT_EQ(c.get_blue(), 1.2);

    c = 2 * a;
    EXPECT_FLOAT_EQ(c.get_red(), .4);
    EXPECT_FLOAT_EQ(c.get_green(), 1.6);
    EXPECT_FLOAT_EQ(c.get_blue(), 1.2);

    c = a / 2;
    EXPECT_FLOAT_EQ(c.get_red(), .1);
    EXPECT_FLOAT_EQ(c.get_green(), .4);
    EXPECT_FLOAT_EQ(c.get_blue(), .3);
}

// Tests stream output for Color
TEST(ColorTest, Print) {
    Color a(.2, .8, .6);
    string expected("(0.2, 0.8, 0.6)");
    ostringstream stream;
    stream << a;
    string result = stream.str();
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
