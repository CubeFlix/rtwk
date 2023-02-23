// vec3.h
// Vector 3 type.

#include <math.h>

#include "vec3.h"
#include "random.h"

// Get the length of a vector.
double vec3_length(Vec3 vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

// Get the length of the vector, squared.
double vec3_length_squared(Vec3 vec) {
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

// Transform into a unit vector.
Vec3 vec3_unit(Vec3 vec) {
    double len = vec3_length(vec);
    return (Vec3){vec.x / len, vec.y / len, vec.z / len};
}

// Perform a dot product between two vectors.
inline double vec3_dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Create a random vector.
Vec3 vec3_random(double min, double max) {
    return (Vec3){random_range(min, max), random_range(min, max), random_range(min, max)};
}

// Create a random vector in a unit sphere.
inline Vec3 vec3_random_unit_sphere() {
    do {
        Vec3 v = vec3_random(-1.0, 1.0);
        if (vec3_length_squared(v) >= 1.0) {continue;}
        return v;
    } while (1);
}

// Create a random unit vector in a unit sphere.
Vec3 vec3_random_unit_vector() {
    return vec3_unit(vec3_random_unit_sphere());
}

// Create a random unit vector in a given hemisphere.
Vec3 vec3_random_hemisphere(const Vec3 *normal) {
    Vec3 unit = vec3_random_unit_sphere();
    if (vec3_dot(unit, *normal) > 0.0) {
        return unit;
    } else {
        return (Vec3){-unit.x, -unit.y, -unit.z};
    }
}