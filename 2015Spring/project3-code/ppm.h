#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RGB_STRUCT
#define RGB_STRUCT
typedef struct pixel {
    int red;   // red value
    int green; // green value
    int blue;  // blue value
} Pixel;
#endif

////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PPM_STRUCT
#define PPM_STRUCT
typedef struct ppm {
    int rows;       // number of rows
    int cols;       // number of columns
    int colors;     // number of colors
    Pixel **pixels; // the actual pixel data
} ppmPic;
#endif

////////////////////////////////////////////////////////////////////////////////////////////////

ppmPic *readPic(FILE *);
void writePic(ppmPic *, FILE *);

void swapPic(ppmPic *);
void flipPic(ppmPic *);
void rotatePic(ppmPic *);
void invertPic(ppmPic *);

////////////////////////////////////////////////////////////////////////////////////////////////
