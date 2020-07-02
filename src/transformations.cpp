#include "transformations.h"

#include <math.h>

namespace transformations {
Matrix<4, 4> translation(const double x, const double y, const double z) {
  return Matrix<4, 4>({1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1});
}
Matrix<4, 4> scaling(const double x, const double y, const double z) {

  return Matrix<4, 4>({x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1});
}

Matrix<4, 4> rotation_x(const double r) {
    return Matrix<4, 4>({
            1, 0, 0, 0,
            0, std::cos(r), -std::sin(r), 0,
            0, std::sin(r), std::cos(r), 0,
            0, 0, 0, 1
            });
}
Matrix<4, 4> rotation_y(const double r) {
    return Matrix<4, 4>({
            std::cos(r), 0, std::sin(r), 0,
            0, 1, 0, 0,
            -std::sin(r), 0, std::cos(r), 0,
            0, 0, 0, 1
            });
}
Matrix<4, 4> rotation_z(const double r) {
    return Matrix<4, 4>({
            std::cos(r), -std::sin(r), 0, 0,
            std::sin(r), std::cos(r), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
            });
}
Matrix<4, 4> shearing(const double x_y, const double x_z, const double y_x,
                      const double y_z, const double z_x, const double z_y) {
    return Matrix<4, 4>({
            1, x_y, x_z, 0,
            y_x, 1, y_z, 0,
            z_x, z_y, 1, 0,
            0, 0, 0, 1
            });
}

} // namespace transformations
