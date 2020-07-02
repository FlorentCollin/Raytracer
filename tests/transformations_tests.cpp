#include <ostream>

#include "transformations.h"
#include "gtest/gtest.h"
#include "math.h"

using namespace transformations;

TEST(TransformationsTest, MultiplyingByATranslationMatrix) {
    auto transform = translation(5, -3, 2);
    Point p(-3, 4, 5);
    EXPECT_TRUE(transform * p == Point(2, 1, 7));
}

TEST(TransformationsTest, InverseMultiplicationTranslation) {
    auto transform = translation(5, -3, 2);
    auto inv = transform.inverse();
    Point p(-3, 4, 5);
    EXPECT_TRUE(inv * p == Point(-8, 7, 3));
}

TEST(TransformationsTest, VectorNotAffectedByTranslation) {
    auto transform = translation(5, -3, 2);
    Vector v(-3, 4, 5);
    EXPECT_TRUE(transform * v == v);
}

TEST(TransformationsTest, ScalingPoint) {
    auto transform = scaling(2, 3, 4);
    Point p(-4, 6, 8);
    EXPECT_TRUE(transform * p == Point(-8, 18, 32));
}

TEST(TransformationsTest, ScalingVector) {
    auto transform = scaling(2, 3, 4);
    Vector v(-4, 6, 8);
    EXPECT_TRUE(transform * v == Vector(-8, 18, 32));
}

TEST(TransformationsTest, MultiplyingByInvScaling) {
    auto transform = scaling(2, 3, 4);
    auto inv = transform.inverse();
    Vector v(-4, 6, 8);
    EXPECT_TRUE(inv * v == Vector(-2, 2, 2));
}

TEST(TransformationsTest, RotationX) {
    Point p(0, 1, 0);
    auto half_quarter = rotation_x(M_PI_4);
    auto full_quarter = rotation_x(M_PI_2);
    EXPECT_TRUE(half_quarter * p == Point(0, std::sqrt(2)/2, std::sqrt(2)/2));
    EXPECT_TRUE(full_quarter * p == Point(0, 0, 1));
}

TEST(TransformationsTest, RotationXInv) {
    Point p(0, 1, 0);
    auto half_quarter = rotation_x(M_PI_4);
    auto inv = half_quarter.inverse();
    EXPECT_TRUE(inv * p == Point(0, std::sqrt(2)/2, -std::sqrt(2)/2));
}

TEST(TransformationsTest, RotationY) {
    Point p(0, 0, 1);
    auto half_quarter = rotation_y(M_PI_4);
    auto full_quarter = rotation_y(M_PI_2);
    EXPECT_TRUE(half_quarter * p == Point(std::sqrt(2)/2, 0, std::sqrt(2)/2));
    EXPECT_TRUE(full_quarter * p == Point(1, 0, 0));
}

TEST(TransformationsTest, RotationZ) {
    Point p(0, 1, 0);
    auto half_quarter = rotation_z(M_PI_4);
    auto full_quarter = rotation_z(M_PI_2);
    EXPECT_TRUE(half_quarter * p == Point(-std::sqrt(2)/2, std::sqrt(2)/2, 0));
    EXPECT_TRUE(full_quarter * p == Point(-1, 0, 0));
}

TEST(TransformationsTest, ShearingX_Y) {
    auto transform = shearing(1, 0, 0, 0, 0, 0);
    Point p(2, 3, 4);
    EXPECT_TRUE(transform * p == Point(5, 3, 4));
}

TEST(TransformationsTest, ShearingX_Z) {
    auto transform = shearing(0, 1, 0, 0, 0, 0);
    Point p(2, 3, 4);
    EXPECT_TRUE(transform * p == Point(6, 3, 4));
}

TEST(TransformationsTest, ShearingY_X) {
    auto transform = shearing(0, 0, 1, 0, 0, 0);
    Point p(2, 3, 4);
    EXPECT_TRUE(transform * p == Point(2, 5, 4));
}

TEST(TransformationsTest, ShearingY_Z) {
    auto transform = shearing(0, 0, 0, 1, 0, 0);
    Point p(2, 3, 4);
    EXPECT_TRUE(transform * p == Point(2, 7, 4));
}

TEST(TransformationsTest, ShearingZ_X) {
    auto transform = shearing(0, 0, 0, 0, 1, 0);
    Point p(2, 3, 4);
    EXPECT_TRUE(transform * p == Point(2, 3, 6));
}

TEST(TransformationsTest, ShearingZ_Y) {
    auto transform = shearing(0, 0, 0, 0, 0, 1);
    Point p(2, 3, 4);
    EXPECT_TRUE(transform * p == Point(2, 3, 7));
}
