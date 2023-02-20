// ray.c
// Ray casting.

#include "ray.h"
#include "vec3.h"
#include "color.h"

// Get the location of the ray at a point.
Vec3 ray_at(const Ray r, double t) {
    return (Vec3){r.origin.x + t * r.direction.x, r.origin.y + t * r.direction.y, r.origin.z + t * r.direction.z};
}