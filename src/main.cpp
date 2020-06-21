#include <iostream>

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
    Projectile proj(Point(0, 0, 0), Vector(1, 1, 0));
    Environment env(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
    std::printf("%d %.4f %.4f\n", 0, proj.position.x, proj.position.y);
    for(int i = 1; proj.position.y >= 0; i++) {
        proj = tick(env, proj);
        std::printf("%d %.4f %.4f\n", i, proj.position.x, proj.position.y);
    }
}
