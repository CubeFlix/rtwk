// main.c

#include <stdio.h>
#include <math.h>

#include "color.h"
#include "ppm.h"
#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "scene.h"
#include "camera.h"

// Get the ray color.
Color ray_color(const Ray r, Sphere *scene, int n) {
    Hit h = { 0 };
    if (scene_hit(scene, n, 0, INFINITY, r, &h)) {
        return (Color){(h.normal.x + 1.0) * 0.5, (h.normal.y + 1.0) * 0.5, (h.normal.z + 1.0) * 0.5};
    }
    Vec3 unit_dir = vec3_unit(r.direction);
    double t = 0.5 * (unit_dir.y + 1.0);
    const double one_minus_t = 1.0 - t;
    return (Color){one_minus_t + t * 0.5, one_minus_t + t * 0.7, one_minus_t + t};
}

int main(void) {
    struct Sphere scene[2];
    scene[0].center = (Vec3){0.0, 0.0, -1.0};
    scene[0].radius = 0.5;
    scene[1].center = (Vec3){0.0, -100.5, -1.0};
    scene[1].radius = 100.0;

    printf("hello, render!\n");
    printf("writing image...\n");

    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = (int)((double)image_width / aspect_ratio);

    // camera info
    Camera c;
    camera_init(&c, (Vec3){0.0, 0.0, 0.0}, 16.0 / 9.0, 2.0, 1.0);

    FILE *ppm = ppm_open("output.ppm", image_width, image_height);
    if (ppm == NULL) {
        printf("error opening file\n");
        return 1;
    }

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            double u = (double)i / (image_width - 1);
            double v = (double)j / (image_height - 1);
            Ray r = camera_ray(&c, u, v);

            if (!ppm_write(ppm, ray_color(r, scene, 2))) {
                ppm_close(ppm);
                printf("error writing file\n");
                return 1;
            }
        }
    }
    
    ppm_close(ppm);

    printf("done!\n");
    return 0;
}