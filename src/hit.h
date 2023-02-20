// hit.h
// Ray hit information.

#ifndef HIT_H
#define HIT_H

#include "vec3.h"

typedef struct Hit {
    Vec3 point;
    Vec3 normal;
    double t;
} Hit;

#endif