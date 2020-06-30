#include <math.h>

#include <iostream>

#include "canvas.h"
#include "tuple.h"

struct Projectile {
    Point position;
    Vector velocity;
    Projectile(Point t_position, Vector t_velocity)
        : position{t_position}, velocity{t_velocity} {};
};

struct Environment {
    Vector gravity, wind;
    Environment(Vector t_gravity, Vector t_wind)
        : gravity{t_gravity}, wind{t_wind} {};
};

Projectile tick(Environment env, Projectile proj) {
    Point position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(position, velocity);
}

int main() {
    Vector velocity(1, 1.8, 0);
    velocity.normalize();
    velocity = velocity * 11.25;
    Projectile proj(Point(0, 1, 0), velocity);
    Environment env(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
    Canvas canvas(900, 500);
    Color c(1, 0.5, 0);
    for (int i = 0; proj.position.y() >= 0; i++) {
        int x = static_cast<int>(std::round(proj.position.x()));
        int y = static_cast<int>(canvas.get_height() - 1 - std::round(proj.position.y()));
        canvas.write_pixel(x, y, c);
        proj = tick(env, proj);
    }
    std::cout << canvas.to_PPM() << '\n';
}
