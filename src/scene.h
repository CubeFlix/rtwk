// scene.h
// Scene definition.

#ifndef SCENE_H
#define SCENE_H

#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "hit.h"

// Check if a ray has hit the scene, given a list of spheres and a ray.
bool scene_hit(Sphere *scene, int n, double t_min, double t_max, const Ray r, Hit *hit);

#endif