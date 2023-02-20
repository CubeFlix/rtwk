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

#endif