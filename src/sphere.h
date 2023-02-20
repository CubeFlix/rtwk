// sphere.h
// The sphere object.

#ifndef SPHERE_H
#define SPHERE_H

#include <stdbool.h>

#include "vec3.h"
#include "hit.h"
#include "ray.h"

typedef struct Sphere {
    Vec3 center;
    double radius;
} Sphere;

// Determine if the sphere is hit. Places the hit information into hit.
bool sphere_hit(Sphere s, Ray r, double t_min, double t_max, Hit *hit);

#endif