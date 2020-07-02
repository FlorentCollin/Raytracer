#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "matrix.h"

namespace transformations {
Matrix<4, 4> translation(const double x, const double y, const double z);
Matrix<4, 4> scaling(const double x, const double y, const double z);
Matrix<4, 4> rotation_x(const double r);
Matrix<4, 4> rotation_y(const double r);
Matrix<4, 4> rotation_z(const double r);
Matrix<4, 4> shearing(const double x_y, const double x_z, const double y_x,
                      const double y_z, const double z_x, const double z_y);
} // namespace transformations

#endif // TRANSFORMATIONS_H
