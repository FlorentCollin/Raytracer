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

    Tuple operator+(const Tuple& other) {
        return Tuple(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Tuple operator-(const Tuple& other) {
        return Tuple(x - other.x, y - other.y, z - other.z, w - other.w);
    }
};

class Point : public Tuple {
public:
    Point(double t_x, double t_y, double t_z) : Tuple(t_x, t_y, t_z, 1) {}
    Point(const Tuple& t) : Tuple(t) {}
};

class Vector : public Tuple {
   public:
    Vector(double t_x, double t_y, double t_z) : Tuple(t_x, t_y, t_z, 1) {}
    Vector(const Tuple& t) : Tuple(t) {}
};

#endif  // TUPLE_H
