// random.c
// Random number generation.

#include "random.h"

#include <stdlib.h>

// Initialize random number generation.
void random_init() {
    srand(time(NULL));
}

// Generate a random number.
double random_range(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}