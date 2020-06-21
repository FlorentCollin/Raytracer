#ifndef TUPLE_H
#define TUPLE_H

class Tuple {
   public:
    double x{0};
    double y{0};
    double z{0};
    double w{0};

    Tuple(double t_x, double t_y, double t_z, double t_w)
        : x{t_x}, y{t_y}, z{t_z}, w{t_w} {}

    bool operator==(const Tuple& other);
    Tuple operator+(const Tuple& other);
    Tuple operator-(const Tuple& other);
    Tuple operator-();
    Tuple operator*(const double scalar);
    Tuple operator/(const double scalar);
    double magnitude();
    void normalize();
    double dot(const Tuple& other);
};

class Point : public Tuple {
public:
    Point(double t_x, double t_y, double t_z) : Tuple(t_x, t_y, t_z, 1) {}
    Point(const Tuple& t) : Tuple(t) {}
};

class Vector : public Tuple {
   public:
    Vector(double t_x, double t_y, double t_z) : Tuple(t_x, t_y, t_z, 0) {}
    Vector(const Tuple& t) : Tuple(t) {}
    Vector cross(const Vector& v);
};

#endif  // TUPLE_H
