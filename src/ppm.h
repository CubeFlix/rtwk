// ppm.h
// PPM image format.

#ifndef PPM_H
#define PPM_H

#include <stdio.h>

#include "color.h"

// Open a new PPM image for writing.
FILE* ppm_open(char *path, int width, int height);

// Write a single pixel to a PPM image.
int ppm_write(FILE* ppm, Color c);

// Close a PPM image.
void ppm_close(FILE* ppm);

#endif