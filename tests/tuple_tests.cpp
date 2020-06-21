#include <type_traits>
#include <math.h>

#include "gtest/gtest.h"
#include "tuple.h"

constexpr double EPSILON = 1e-5;

TEST(TupleTest, PointTest) {
    Point p(4.3, -4.2, 3.1);
    Tuple expected(4.3, -4.2, 3.1, 1);
    EXPECT_TRUE(p == expected);
}

TEST(TupleTest, VectorTest) {
    Vector v(1, 2, 3);
    Tuple expected(1, 2, 3, 0);
    EXPECT_TRUE(v == expected);
}

TEST(TupleTest, PointInheritedFromTuple) {
    bool is_base = std::is_base_of<Tuple, Point>::value;
    EXPECT_TRUE(is_base);
}

TEST(TupleTest, VectorInheritedFromTuple) {
    bool is_base = std::is_base_of<Tuple, Vector>::value;
    EXPECT_TRUE(is_base);
}

TEST(TupleTest, TupleAddition) {
    Tuple t1(3, -2, 5, 1);
    Tuple t2(-2, 3, 1, 0);
    Tuple expected(1, 1, 6, 1);
    EXPECT_TRUE(t1 + t2 == expected);
}

TEST(TupleTest, PointSubstraction) {
    Point p1(3, 2, 1);
    Point p2(5, 6, 7);
    Tuple expected(-2, -4, -6, 0);
    EXPECT_TRUE(p1 - p2 == expected);
}

TEST(TupleTest, VectorPointSubstraction) {
    Point p(3, 2, 1);
    Vector v(5, 6, 7);
    Tuple expected(-2, -4, -6, 1);
    EXPECT_TRUE(p - v == expected);
}

TEST(TupleTest, VectorSubstraction) {
    Vector v1(3, 2, 1);
    Vector v2(5, 6, 7);
    Tuple expected(-2, -4, -6, 0);
    EXPECT_TRUE(v1 - v2 == expected);
}

TEST(TupleTest, TupleNegation) {
    Tuple t(1, -2, 3, -4);
    Tuple expected(-1, 2, -3, 4);
    EXPECT_TRUE(-t == expected);
}

TEST(TupleTest, TupleMultipliedByAScalar) {
    Tuple t(1, -2, 3, -4);
    Tuple expected(3.5, -7, 10.5, -14);
    EXPECT_TRUE(t * 3.5 == expected);
}

TEST(TupleTest, TupleMultipliedByAFraction) {
    Tuple t(1, -2, 3, -4);
    Tuple expected(0.5, -1, 1.5, -2);
    EXPECT_TRUE(t * 0.5 == expected);
}

TEST(TupleTest, TupleDividedByAScalar) {
    Tuple t(1, -2, 3, -4);
    Tuple expected(0.5, -1, 1.5, -2);
    EXPECT_TRUE(t / 2 == expected);
}

TEST(TupleTest, Magnitude1) {
    Vector t(1, 0, 0);
    EXPECT_LE(abs(1 - t.magnitude()), EPSILON);
}

TEST(TupleTest, Magnitude2) {
    Vector t(0, 1, 0);
    EXPECT_LE(abs(1 - t.magnitude()), EPSILON);
}

TEST(TupleTest, Magnitude3) {
    Vector t(0, 0, 1);
    EXPECT_LE(abs(1 - t.magnitude()), EPSILON);
}
TEST(TupleTest, Magnitude4) {
    Vector t(1, 2, 3);
    EXPECT_LE(abs(std::sqrt(14) - t.magnitude()), EPSILON);
}

TEST(TupleTest, Magnitude5) {
    Vector t(-1, -2, -3);
    EXPECT_LE(abs(std::sqrt(14) - t.magnitude()), EPSILON);
}

TEST(TupleTest, Normalize1) {
    Vector v(4, 0, 0);
    v.normalize();
    EXPECT_LE(abs(1 - v.magnitude()), EPSILON);
    EXPECT_TRUE(v == Vector(1, 0, 0));
}

TEST(TupleTest, Normalize2) {
    Vector v(1, 2, 3);
    v.normalize();
    EXPECT_LE(abs(1 - v.magnitude()), EPSILON);
    double sq_14 = std::sqrt(14);
    EXPECT_TRUE(v == Vector(1/sq_14, 2/sq_14, 3/sq_14));
}

TEST(TupleTest, DotProduct1) {
    Vector v1(1, 2, 3);
    Vector v2(2, 3, 4);
    EXPECT_LE(abs(20 - v1.dot(v2)), EPSILON);
}

TEST(TupleTest, Cross) {
    Vector a(1, 2, 3);
    Vector b(2, 3, 4);
    EXPECT_TRUE(a.cross(b) == Vector(-1, 2, -1));
    EXPECT_TRUE(b.cross(a) == Vector(1, -2, 1));
}
