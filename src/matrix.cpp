#include "matrix.h"

#include <array>
#include <cmath>
#include <stdexcept>

template <unsigned N, unsigned M>
inline double& Matrix<N, M>::operator()(const unsigned row,
                                        const unsigned column) {
    return m_data.at(N * row + column);
}

template <unsigned N, unsigned M>
bool Matrix<N, M>::operator==(Matrix<N, M>& other) {
    constexpr double EPSILON = 1e-5;
    for (unsigned i = 0; i < M; i++) {
        for (unsigned j = 0; j < N; j++) {
            if (abs(at(i, j) - other(i, j)) > EPSILON) {
                return false;
            }
        }
    }
    return true;
}

template <unsigned N, unsigned M>
bool Matrix<N, M>::operator!=(Matrix<N, M>& other) {
    return !operator==(other);
}

template <>
Tuple Matrix<4, 4>::operator*(const Tuple t) {
    std::array<double, 4> tuple_data = {0};
    for (unsigned i = 0; i < 4; i++) {
        for (unsigned j = 0; j < 4; j++) {
            tuple_data[i] += at(i, j) * t.at(j);
        }
    }
    return Tuple(tuple_data);
}

template <unsigned N, unsigned M>
Matrix<M, N> Matrix<N, M>::transpose() {
    Matrix<M, N> res;
    for (unsigned i = 0; i < N; i++) {
        for (unsigned j = 0; j < M; j++) {
            res(j, i) = at(i, j);
        }
    }
    return res;
}

template <>
inline double Matrix<2, 2>::determinant() {
    return at(0, 0) * at(1, 1) - at(0, 1) * at(1, 0);
}

template <unsigned N, unsigned M>
Matrix<N - 1, M - 1> Matrix<N, M>::submatrix(const unsigned row,
                                             const unsigned column) {
    if (row < 0 || row >= N || column < 0 || column >= M) {
        throw std::out_of_range("Row or column indice is out of range");
    }
    std::array<bool, N* M> indices_to_removes = {false};
    const std::size_t begin_row = N * row;
    for (std::size_t i = begin_row; i < begin_row + N; i++) {
        indices_to_removes[i] = true;
    }
    for (std::size_t i = column; i < N * M; i += N) {
        indices_to_removes[i] = true;
    }
    const std::size_t submatrix_size = (N - 1) * (M - 1);
    std::array<double, submatrix_size> new_matrix;
    for (std::size_t i = 0, j = 0; i < N * M; i++) {
        if (indices_to_removes[i]) {
            j++;
        } else {
            new_matrix[i - j] = m_data[i];
        }
    }
    return Matrix<N - 1, M - 1>(new_matrix);
}

template <unsigned N, unsigned M>
double Matrix<N, M>::minor(const unsigned row, const unsigned column) {
    return submatrix(row, column).determinant();
}

template <unsigned N, unsigned M>
double Matrix<N, M>::cofactor(const unsigned row, const unsigned column) {
    return std::pow(-1, row + column) * minor(row, column);
}

template <unsigned N, unsigned M>
inline double Matrix<N, M>::determinant() {
    double det = 0;
    for (unsigned i = 0; i < M; i++) {
        det += at(0, i) * cofactor(0, i);
    }
    return det;
}

template <unsigned N, unsigned M>
Matrix<N, M> Matrix<N, M>::inverse() {
    if (!is_invertible()) {
        // TODO: create an error indicating that the matrix is not invertible
        throw;
    }
    double det = determinant();
    Matrix<M, N> inv;
    for(unsigned i = 0; i < N; i++) {
        for(unsigned j = 0; j < M; j++) {
            inv(j, i) = cofactor(i, j) / det;
        }
    }
    return inv;
}
