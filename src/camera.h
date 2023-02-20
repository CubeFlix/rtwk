// camera.h
// The camera object.

#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vec3.h"

// The camera object.
typedef struct Camera {
    Vec3 origin;
    Vec3 lower_left_corner;
    Vec3 horizontal;
    Vec3 vertical;
} Camera;

// Initialize a camera object.
void camera_init(Camera *c, Vec3 origin, double aspect_ratio, double viewport_height, double focal_length);

// Get a ray from the camera.
Ray camera_ray(Camera *c, double u, double v);

#endif