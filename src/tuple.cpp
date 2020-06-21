#include "tuple.h"

#include <math.h>

#include <iostream>

bool Tuple::operator==(const Tuple& other) {
    const auto equal = [](double x1, double x2) {
        constexpr double EPSILON = 1e-5;
        return abs(x1 - x2) <= EPSILON;
    };
    return equal(x, other.x) && equal(y, other.y) && equal(z, other.z) &&
           equal(w, other.w);
}

Tuple Tuple::operator+(const Tuple& other) {
    return Tuple(x + other.x, y + other.y, z + other.z, w + other.w);
}

Tuple Tuple::operator*(const double scalar) {
    return Tuple(x * scalar, y * scalar, z * scalar, w * scalar);
}

Tuple Tuple::operator/(const double scalar) {
    return Tuple(x / scalar, y / scalar, z / scalar, w / scalar);
}

Tuple Tuple::operator-(const Tuple& other) {
    return Tuple(x - other.x, y - other.y, z - other.z, w - other.w);
}

Tuple Tuple::operator-() { return Tuple(-x, -y, -z, -w); }

double Tuple::magnitude() { return std::sqrt(x * x + y * y + z * z + w * w); }

void Tuple::normalize() {
    double magnitude = this->magnitude();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    w /= magnitude;
}

double Tuple::dot(const Tuple& other) {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vector Vector::cross(const Vector& v) {
    return Vector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
