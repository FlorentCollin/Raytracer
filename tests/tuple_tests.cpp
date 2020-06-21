#include <type_traits>

#include "gtest/gtest.h"
#include "tuple.h"

TEST(TupleTest, PointTest) {
    Point p(4.3, -4.2, 3.1);
    EXPECT_EQ(p.x, 4.3);
    EXPECT_EQ(p.y, -4.2);
    EXPECT_EQ(p.z, 3.1);
    EXPECT_EQ(p.w, 1) << "A point should have a member `w` = 1";
}

TEST(TupleTest, VectorTest) {
    Vector v(1, 2, 3);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 3);
    EXPECT_EQ(v.w, 0) << "A point should have a member `w` = 0";
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
    Tuple add_t = t1 + t2;
    EXPECT_EQ(add_t.x, 1);
    EXPECT_EQ(add_t.y, 1);
    EXPECT_EQ(add_t.z, 6);
    EXPECT_EQ(add_t.w, 1) << "The addition of a Point and a Vector should be a "
                             "Point consequently w must be equal to 1";
}

TEST(TupleTest, TupleSubtraction) {
    Point p1(3, 2, 1);
    Point p2(5, 6, 7);
    Vector add_t = p1 - p2;
    EXPECT_EQ(add_t.x, -2);
    EXPECT_EQ(add_t.y, -4);
    EXPECT_EQ(add_t.z, -6);
    EXPECT_EQ(add_t.w, 0);
}
