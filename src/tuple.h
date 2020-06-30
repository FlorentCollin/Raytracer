#ifndef TUPLE_H
#define TUPLE_H

#include <array>

class Tuple {
   public:
    std::array<double, 4> m_elems = {0};

    Tuple(std::array<double, 4> elems) : m_elems{elems} {}

    inline double at(std::size_t index) const { return m_elems.at(index); }
    inline double x() const { return m_elems[0]; }
    inline double y() const { return m_elems[1]; }
    inline double z() const { return m_elems[2]; }
    inline double w() const { return m_elems[3]; }

    Tuple operator+(const Tuple& other);
    Tuple operator-(const Tuple& other);
    Tuple operator-();
    Tuple operator*(const double scalar);
    Tuple operator/(const double scalar);
    bool operator==(const Tuple& other);
};

class Point : public Tuple {
   public:
    Point(double x, double y, double z) : Tuple({x, y, z, 1}) {}
    Point(const Tuple& t) : Tuple(t) {}
};

class Vector : public Tuple {
   public:
    Vector(double x, double y, double z) : Tuple({x, y, z, 0}) {}
    Vector(const Tuple& t) : Tuple(t) {}
    Vector cross(const Vector& v);
    double magnitude();
    void normalize();
    double dot(const Vector& other);
};

class Color : public Tuple {
   public:
    Color(double red, double green, double blue)
        : Tuple({red, green, blue, 0}) {}
    void round();
    Color& operator*=(const double scalar);
    Color operator*(const Color& other);
};

#endif  // TUPLE_H
