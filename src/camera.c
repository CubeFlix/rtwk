// camera.c
// The camera object.

#include "camera.h"
#include "ray.h"
#include "vec3.h"

// Initialize a camera object.
void camera_init(Camera *c, Vec3 origin, double aspect_ratio, double viewport_height, double focal_length) {
    double viewport_width = aspect_ratio * viewport_height;
    c->origin = origin;
    c->horizontal = (Vec3){viewport_width, 0.0, 0.0};
    c->vertical = (Vec3){0.0, viewport_height, 0.0};
    c->lower_left_corner = (Vec3){origin.x - (c->horizontal.x + c->vertical.x) / 2.0, \
                origin.y - (c->horizontal.y + c->vertical.y) / 2.0, \
                origin.z - (c->horizontal.z + c->vertical.z) / 2.0 - focal_length};
}

// Get a ray from the camera.
Ray camera_ray(Camera *c, double u, double v) {
    Vec3 dir = {c->lower_left_corner.x + u * c->horizontal.x + v * c->vertical.x - c->origin.x, \
                c->lower_left_corner.y + u * c->horizontal.y + v * c->vertical.y - c->origin.y, \
                c->lower_left_corner.z + u * c->horizontal.z + v * c->vertical.z - c->origin.z};
    return (Ray){c->origin, dir};
}