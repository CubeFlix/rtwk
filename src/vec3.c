// vec3.h
// Vector 3 type.

#include <math.h>

#include "vec3.h"

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