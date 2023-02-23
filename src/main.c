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
#include "random.h"

// Get the ray color.
Color ray_color(const Ray r, Sphere *scene, int n, int depth) {
    Hit h = { 0 };
    
    if (depth <= 0) {
        return (Color){0.0, 0.0, 0.0};
    }
    
    if (scene_hit(scene, n, 0.001, INFINITY, r, &h)) {
        // Vec3 random_unit = vec3_random_unit_vector();
        // Vec3 target = (Vec3){h.point.x + h.normal.x + random_unit.x, h.point.y + h.normal.y + random_unit.y, h.point.z + h.normal.z + random_unit.z};
        
        Vec3 random_unit = vec3_random_hemisphere(&h.normal);
        Vec3 target = (Vec3){h.point.x + random_unit.x, h.point.y + random_unit.y, h.point.z + random_unit.z};
        
        Color col = ray_color((Ray){h.point, (Vec3){target.x - h.point.x, target.y - h.point.y, target.z - h.point.z}}, scene, n, depth - 1);
        return (Color){col.r * 0.5, col.g * 0.5, col.b * 0.5};
    }

    Vec3 unit_dir = vec3_unit(r.direction);
    double t = 0.5 * (unit_dir.y + 1.0);
    const double one_minus_t = 1.0 - t;
    return (Color){one_minus_t + t * 0.5, one_minus_t + t * 0.7, one_minus_t + t};
}

int main(void) {
    random_init();

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

    const int max_depth = 50;
    const int samples_per_pixel = 100;
    const double sample_scale = 1.0 / (double)samples_per_pixel;

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
            Color pix_color = (Color){0.0, 0.0, 0.0};
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = ((double)i + random_range(0.0, 1.0)) / (double)(image_width - 1);
                double v = ((double)j + random_range(0.0, 1.0)) / (double)(image_height - 1);
                Ray r = camera_ray(&c, u, v);

                // Calculate each sample.
                Color sample = ray_color(r, scene, 2, max_depth);
                pix_color.r += sample.r;
                pix_color.g += sample.g;
                pix_color.b += sample.b;
            }

            // Scale the color and apply gamma correction.
            pix_color.r = sqrt(pix_color.r * sample_scale);
            pix_color.g = sqrt(pix_color.g * sample_scale);
            pix_color.b = sqrt(pix_color.b * sample_scale);

            if (!ppm_write(ppm, (Color){pix_color.r, pix_color.g, pix_color.b})) {
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