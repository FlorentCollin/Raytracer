#include <memory>

#include "gtest/gtest.h"
#include "matrix.cpp"
#include "matrix.h"

TEST(MatrixTest, MatrixInitialization) {
    Matrix<4, 4> m({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11, 12, 13.5, 14.5,
                    15.5, 16.5});
    EXPECT_EQ(m(0, 0), 1);
    EXPECT_EQ(m(0, 3), 4);
    EXPECT_EQ(m(1, 0), 5.5);
    EXPECT_EQ(m(1, 2), 7.5);
    EXPECT_EQ(m(2, 2), 11);
    EXPECT_EQ(m(3, 0), 13.5);
    EXPECT_EQ(m(3, 2), 15.5);
}

TEST(MatrixTest, Matrix2x2) {
    Matrix<2, 2> m({-3, 5, 1, -2});
    EXPECT_EQ(m(0, 0), -3);
    EXPECT_EQ(m(0, 1), 5);
    EXPECT_EQ(m(1, 0), 1);
    EXPECT_EQ(m(1, 1), -2);
}

TEST(MatrixTest, Matrix3x3) {
    Matrix<3, 3> m({-3, 5, 0, 1, -2, -7, 0, 1, 1});
    EXPECT_EQ(m(0, 0), -3);
    EXPECT_EQ(m(1, 1), -2);
    EXPECT_EQ(m(2, 2), 1);
}

TEST(MatrixTest, IdenticalMatrix) {
    Matrix<4, 4> a({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
    Matrix<4, 4> b({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
    EXPECT_TRUE(a == b);
}

TEST(MatrixTest, DifferentsMatrix) {
    Matrix<4, 4> a({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
    Matrix<4, 4> b({2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    EXPECT_TRUE(a != b);
}

TEST(MatrixTest, MatrixMultiplication) {
    Matrix<4, 4> a({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
    Matrix<4, 4> b({-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8});
    Matrix<4, 4> mul_mat(
        {20, 22, 50, 48, 44, 54, 114, 108, 40, 58, 110, 102, 16, 26, 46, 42});
    EXPECT_TRUE(a * b == mul_mat);
}

TEST(MatrixTest, MatrixMultiplicationByTuple) {
    Matrix<4, 4> a({1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1});
    Tuple b({1, 2, 3, 1});
    EXPECT_TRUE(a * b == Tuple({18, 24, 33, 1}));
}

TEST(MatrixTest, MatrixMultiplicationByIdentity) {
    Matrix<4, 4> a({0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32});
    Matrix<4, 4> identity({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    EXPECT_TRUE(a * identity == a);
}

TEST(MatrixTest, MatrixTranspose) {
    Matrix<4, 4> a({0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8});
    Matrix<4, 4> expected({0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5, 0, 8, 3, 8});
    EXPECT_TRUE(a.transpose() == expected);
}

TEST(MatrixTest, MatrixTransposeIdentity) {
    Matrix<4, 4> identity({1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
    EXPECT_TRUE(identity.transpose() == identity);
}

TEST(MatrixTest, MatrixDeterminant2x2) {
    Matrix<2, 2> a({1, 5, -3, 2});
    EXPECT_TRUE(a.determinant() == 17);
}

TEST(MatrixTest, MatrixSubmatrix3x3) {
    Matrix<3, 3> a({1, 5, 0, -3, 2, 7, 0, 6, -3});
    Matrix<2, 2> expected({-3, 2, 0, 6});
    EXPECT_TRUE(a.submatrix(0, 2) == expected);
}

TEST(MatrixTest, MatrixSubmatrix4x4) {
    Matrix<4, 4> a({-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1});
    Matrix<3, 3> expected({-6, 1, 6, -8, 8, 6, -7, -1, 1});
    EXPECT_TRUE(a.submatrix(2, 1) == expected);
}

TEST(MatrixTest, MatrixMinor) {
    Matrix<3, 3> a({3, 5, 0, 2, -1, -7, 6, -1, 5});
    EXPECT_TRUE(a.minor(1, 0) == 25);
}

TEST(MatrixTest, MatrixCofactor) {
    Matrix<3, 3> a({3, 5, 0, 2, -1, -7, 6, -1, 5});
    EXPECT_EQ(a.minor(0, 0), -12);
    EXPECT_EQ(a.cofactor(0, 0), -12);
    EXPECT_EQ(a.minor(1, 0), 25);
    EXPECT_EQ(a.cofactor(1, 0), -25);
}

TEST(MatrixTest, MatrixDeterminant3x3) {
    Matrix<3, 3> a({1, 2, 6, -5, 8, -4, 2, 6, 4});
    EXPECT_EQ(a.cofactor(0, 0), 56);
    EXPECT_EQ(a.cofactor(0, 1), 12);
    EXPECT_EQ(a.cofactor(0, 2), -46);
    EXPECT_EQ(a.determinant(), -196);
}

TEST(MatrixTest, MatrixDeterminant4x4) {
    Matrix<4, 4> a({-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9});
    EXPECT_EQ(a.cofactor(0, 0), 690);
    EXPECT_EQ(a.cofactor(0, 1), 447);
    EXPECT_EQ(a.cofactor(0, 2), 210);
    EXPECT_EQ(a.cofactor(0, 3), 51);
    EXPECT_EQ(a.determinant(), -4071);
}

TEST(MatrixTest, MatrixIsInvertible) {
    Matrix<4, 4> a({6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6});
    EXPECT_EQ(a.determinant(), -2120);
    EXPECT_TRUE(a.is_invertible());
}

TEST(MatrixTest, MatrixNotInvertible) {
    Matrix<4, 4> a({-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0});
    EXPECT_EQ(a.determinant(), 0);
    EXPECT_FALSE(a.is_invertible());
}

TEST(MatrixTest, MatrixInverse) {
    Matrix<4, 4> a({-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4});
    EXPECT_EQ(a.determinant(), 532);
    EXPECT_EQ(a.cofactor(2, 3), -160);
    EXPECT_EQ(a.cofactor(3, 2), 105);
    Matrix<4, 4> b = a.inverse();
    EXPECT_LE(abs(b(3, 2) + 160.0 / 532.0), 1e-5);
    EXPECT_LE(abs(b(2, 3) - 105.0 / 532.0), 1e-5);
    Matrix<4, 4> expected({0.21805, 0.45113, 0.24060, -0.04511, -0.80827,
                           -1.45677, -0.44361, 0.52068, -0.07895, -0.22368,
                           -0.05263, 0.19737, -0.52256, -0.81391, -0.30075,
                           0.30639});
    EXPECT_TRUE(b == expected);
}

TEST(MatrixTest, MatrixInverse2) {
    Matrix<4, 4> a({8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4});
    Matrix<4, 4> inverse_expected({-0.15385, -0.15385, -0.28205, -0.53846,
                                   -0.07692, 0.12308, 0.02564, 0.03077, 0.35897,
                                   0.35897, 0.43590, 0.92308, -0.69231,
                                   -0.69231, -0.76923, -1.92308});
    EXPECT_TRUE(a.inverse() == inverse_expected);
}

TEST(MatrixTest, MatrixInverse3) {
    Matrix<4, 4> a({9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2});
    Matrix<4, 4> inverse_expected({-0.04074, -0.07778, 0.14444, -0.22222,
                                   -0.07778, 0.03333, 0.36667, -0.33333,
                                   -0.02901, -0.14630, -0.10926, 0.12963,
                                   0.17778, 0.06667, -0.26667, 0.33333});
    EXPECT_TRUE(a.inverse() == inverse_expected);
}

TEST(MatrixTest, MatrixMultiplicationInverse) {
    Matrix<4, 4> a({3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1});
    Matrix<4, 4> b({8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5});
    Matrix<4, 4> c = a * b;
    Matrix<4, 4> b_inv = b.inverse();
    EXPECT_TRUE(c * b_inv == a);
}

TEST(MatrixTest, MatrixAMultAinv) {
    Matrix<3, 3> a({1, 2, 3, 4, 5, 4, 3, 2, 1});
    Matrix<3, 3> identity({1, 0, 0, 0, 1, 0, 0, 0, 1});
    Matrix<3, 3> a_inv = a.inverse();
    EXPECT_TRUE(a * a_inv == identity);
}

TEST(MatrixTest, IdentityInv) {
    Matrix<3, 3> identity({1, 0, 0, 0, 1, 0, 0, 0, 1});
    EXPECT_TRUE(identity.inverse() == identity);
}
