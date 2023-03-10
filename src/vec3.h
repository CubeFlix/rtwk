// vec3.h
// Vector 3 type.

#ifndef VEC3_H
#define VEC3_H

// Vector 3 type.
typedef struct Vec3 {
    double x;
    double y;
    double z;
} Vec3;

// Get the length of the vector, squared.
double vec3_length_squared(Vec3 vec);

// Get the length of a vector.
double vec3_length(Vec3 vec);

// Transform into a unit vector.
Vec3 vec3_unit(Vec3 vec);

// Perform a dot product between two vectors.
inline double vec3_dot(Vec3 a, Vec3 b);

// Create a random vector.
Vec3 vec3_random(double min, double max);

// Create a random vector in a unit sphere.
inline Vec3 vec3_random_unit_sphere();

// Create a random unit vector in a unit sphere.
Vec3 vec3_random_unit_vector();

// Create a random unit vector in a given hemisphere.
Vec3 vec3_random_hemisphere(const Vec3 *normal);

#endif