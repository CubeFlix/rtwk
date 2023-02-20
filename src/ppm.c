// ppm.c
// PPM image format.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "ppm.h"
#include "color.h"

// Open a new PPM image for writing.
FILE* ppm_open(char *path, int width, int height) {
    // Open the file.
    FILE *ppm = fopen(path, "wb");
    if (ppm == NULL) {
        return NULL;
    }

    // Prepare a buffer to place the string in.
    char buf[64];

    // Write the header.
    if (fwrite("P3\n", sizeof(char), 3, ppm) != 3) {
        // Write failure. Close the file.
        fclose(ppm);
        return NULL;
    }
    itoa(width, buf, 10);
    int len = strlen(buf);
    if (fwrite(buf, sizeof(char), len, ppm) != len) {
        fclose(ppm);
        return NULL;
    }
    if (fwrite(" ", sizeof(char), 1, ppm) != 1) {
        fclose(ppm);
        return NULL;
    }
    itoa(height, buf, 10);
    len = strlen(buf);
    if (fwrite(buf, sizeof(char), len, ppm) != len) {
        fclose(ppm);
        return NULL;
    }
    if (fwrite("\n255\n", sizeof(char), 5, ppm) != 5) {
        fclose(ppm);
        return NULL;
    }

    return ppm;
}

// Write a single pixel to a PPM image.
int ppm_write(FILE* ppm, Color c) {
    // Prepare a buffer to place the string in.
    char buf[4];

    uint8_t ir = (uint8_t)(255.999 * c.r);
    uint8_t ig = (uint8_t)(255.999 * c.g);
    uint8_t ib = (uint8_t)(255.999 * c.b);

    // Write the red, green, and blue values.
    itoa(ir, buf, 10);
    int len = strlen(buf);
    if (fwrite(buf, sizeof(char), len, ppm) != len) {
        return 0;
    }
    if (fwrite(" ", sizeof(char), 1, ppm) != 1) {
        return 0;
    }
    itoa(ig, buf, 10);
    len = strlen(buf);
    if (fwrite(buf, sizeof(char), len, ppm) != len) {
        return 0;
    }
    if (fwrite(" ", sizeof(char), 1, ppm) != 1) {
        return 0;
    }
    itoa(ib, buf, 10);
    len = strlen(buf);
    if (fwrite(buf, sizeof(char), len, ppm) != len) {
        return 0;
    }
    if (fwrite("\n", sizeof(char), 1, ppm) != 1) {
        return 0;
    }

    return 1;
}

// Close a PPM image.
void ppm_close(FILE* ppm) {
    fclose(ppm);
}