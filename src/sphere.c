// sphere.c
// The sphere object.

#include <math.h>

#include "sphere.h"
#include "vec3.h"
#include "hit.h"
#include "ray.h"

// Determine if the sphere is hit. Places the hit information into hit.
bool sphere_hit(Sphere s, Ray r, double t_min, double t_max, Hit *hit) {
    Vec3 oc = (Vec3){r.origin.x - s.center.x, r.origin.y - s.center.y, r.origin.z - s.center.z};
    double a = vec3_length_squared(r.direction);
    double half_b = oc.x * r.direction.x + oc.y * r.direction.y + oc.z * r.direction.z;
    double c = vec3_length_squared(oc) - s.radius * s.radius;

    double discriminant = half_b * half_b - a * c;
    if (discriminant < 0) return false;
    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    hit->t = root;
    hit->point = ray_at(r, hit->t);
    hit->normal = (Vec3){(hit->point.x - s.center.x) / s.radius, (hit->point.y - s.center.y) / s.radius, (hit->point.z - s.center.z) / s.radius};

    return true;
}