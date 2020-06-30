#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>

#include <array>
#include <memory>

#include "tuple.h"

template <unsigned N, unsigned M>
class Matrix {
   private:
    std::array<double, N * M> m_data;

   public:
    Matrix() : m_data{std::array<double, N * M>()} {}
    Matrix(std::array<double, N * M> data) : m_data{data} {}

    Matrix<M, N> transpose();
    inline double determinant();

    Matrix<N - 1, M - 1> submatrix(const unsigned row, const unsigned column);
    double minor(const unsigned row, const unsigned column);
    double cofactor(const unsigned row, const unsigned column);

    inline bool is_invertible() { return determinant() != 0; }
    Matrix<N, M> inverse();

    Tuple operator*(const Tuple t);
    inline double& operator()(const unsigned row, const unsigned column);
    inline double& at(const unsigned row, const unsigned column) { return operator()(row, column); }
    bool operator==(Matrix<N, M>& other);
    bool operator!=(Matrix<N, M>& other);
    template <unsigned O>
    Matrix<N, O> operator*(Matrix<M, O>& other) {
        Matrix<N, O> mul_mat(std::array<double, N * O>{0});
        for (unsigned i = 0; i < N; i++) {
            for (unsigned j = 0; j < M; j++) {
                for (unsigned k = 0; k < M; k++) {
                    mul_mat(i, j) += operator()(i, k) * other(k, j);
                }
            }
        }
        return mul_mat;
    }
};

#endif  // MATRIX_H
