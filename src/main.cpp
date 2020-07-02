#include <math.h>

#include <iostream>
#include <vector>

#include "transformations.h"
#include "canvas.h"

using namespace transformations;

void print_point(Point p) {
    std::cout << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")\n";
}

int main() {
    const int width = 100;
    const int height = 100;
    Canvas canvas(width, height);
    Color point_color(1, 0, 0);
    auto translation_center = translation(width/2, height/2, 0);
    Point start(0, 0, 0);
    std::vector<Point> v({Point(0, 1, 0), Point(1, 0, 0), Point(0, -1, 0), Point(-1, 0, 0)});
    auto scale = scaling(20, 20, 0);
    for(Point p : v) {
        p = scale * p;
        p = translation_center * p;
        canvas.write_pixel(p.x(), p.y(), point_color);
    }
    for(Point p : v) {
        p = rotation_z(M_PI/6) * p;
        p = scale * p;
        p = translation_center * p;
        canvas.write_pixel(p.x(), p.y(), point_color);
    }
    for(Point p : v) {
        p = rotation_z(M_PI/3) * p;
        p = scale * p;
        p = translation_center * p;
        canvas.write_pixel(p.x(), p.y(), point_color);
    }

    std::cout << canvas.to_PPM();
}
