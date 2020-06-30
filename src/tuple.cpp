#include "tuple.h"

#include <math.h>

#include <algorithm>
#include <iostream>
#include <numeric>

bool Tuple::operator==(const Tuple& other) {
    const auto equal = [](double x1, double x2) {
        constexpr double EPSILON = 1e-5;
        return abs(x1 - x2) <= EPSILON;
    };
    for (size_t i = 0; i < m_elems.size(); i++) {
        if (!equal(m_elems[i], other.m_elems[i])) {
            return false;
        }
    }
    return true;
}

Tuple Tuple::operator+(const Tuple& other) {
    std::array<double, 4> sum_elems = {0};
    std::transform(m_elems.begin(), m_elems.end(), other.m_elems.begin(),
                   sum_elems.begin(), std::plus<double>());
    return Tuple(sum_elems);
}

Tuple Tuple::operator-(const Tuple& other) {
    std::array<double, 4> sub = {0};
    std::transform(m_elems.begin(), m_elems.end(), other.m_elems.begin(),
                   sub.begin(), std::minus<double>());
    return Tuple(sub);
}

Tuple Tuple::operator-() {
    std::array<double, 4> minus_elems = {0};
    std::transform(m_elems.begin(), m_elems.end(), minus_elems.begin(),
                   [](double a) { return -a; });
    return Tuple(minus_elems);
}

Tuple Tuple::operator*(const double scalar) {
    std::array<double, 4> multiplied_elems = {0};
    std::transform(m_elems.begin(), m_elems.end(), multiplied_elems.begin(),
                   [&](double a) { return a * scalar; });
    return Tuple(multiplied_elems);
}

Tuple Tuple::operator/(const double scalar) {
    std::array<double, 4> divided_elems = {0};
    std::transform(m_elems.begin(), m_elems.end(), divided_elems.begin(),
                   [&](double a) { return a / scalar; });
    return Tuple(divided_elems);
}

double Vector::magnitude() {
    double sum_of_products = std::transform_reduce(
        m_elems.begin(), m_elems.end(), m_elems.begin(), 0.0);
    return std::sqrt(sum_of_products);
}

void Vector::normalize() {
    const double magnitude = this->magnitude();
    std::transform(m_elems.begin(), m_elems.end(), m_elems.begin(),
                   [magnitude](double a) { return a / magnitude; });
}

double Vector::dot(const Vector& other) {
    return std::inner_product(m_elems.begin(), m_elems.end(),
                              other.m_elems.begin(), 0.0);
}

Vector Vector::cross(const Vector& v) {
    return Vector(y() * v.z() - z() * v.y(), z() * v.x() - x() * v.z(),
                  x() * v.y() - y() * v.x());
}

Color Color::operator*(const Color& other) {
    return Color(x() * other.x(), y() * other.y(), z() * other.z());
}

void Color::round() {
    std::transform(m_elems.begin(), m_elems.end(), m_elems.begin(),
                   [](double a) { return std::round(a); });
}

Color& Color::operator*=(const double scalar) {
    std::transform(m_elems.begin(), m_elems.end(), m_elems.begin(),
                   [&](double a) { return a * scalar; });
    return *this;
}
