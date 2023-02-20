// scene.c
// Rendering.

#include <stdbool.h>
#include <math.h>

#include "scene.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"

// Check if a ray has hit the scene, given a list of spheres and a ray.
bool scene_hit(Sphere *scene, int n, double t_min, double t_max, const Ray r, Hit *hit) {
    // Render the ray.
    Hit h_temp = { 0 };
    bool did_hit = false;
    double closest = t_max;

    // Loop over each sphere.
    for (int i = 0; i < n; i++) {
        if (sphere_hit(scene[i], r, t_min, closest, &h_temp)) {
            did_hit = true;
            closest = h_temp.t;
            (*hit) = h_temp;
        }
    }

    return did_hit;
}