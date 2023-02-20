// ray.h
// Ray casting.

#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include "color.h"

typedef struct Ray {
    Vec3 origin;
    Vec3 direction;
} Ray;

// Get the location of the ray at a point.
Vec3 ray_at(const Ray r, double t);

#endif