#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#include "ppm.h"


////////////////////////////////////////////////////////////////////////////////////////////////

ppmPic *readPic(FILE *fp) {
    ppmPic *myPic = malloc(sizeof(ppmPic));
    int cols, rows, colors;

    readToken(fp);          // read the P3
    cols = readInt(fp);     // read the number of columns
    rows = readInt(fp);     // read the number of rows
    colors = readInt(fp);   // read the number of colors
    myPic->cols = cols;
    myPic->rows = rows;
    myPic->colors = colors;

    int i, j;
    myPic->pixels = malloc(sizeof(Pixel *) * rows);
    for (i=0; i<rows; i++)
        myPic->pixels[i] = malloc(sizeof(Pixel) * cols);

    int r, g, b;
    for (i = 0; i < rows; i++) {
        for (j=0; j < cols; j++) {
            r = readInt(fp);
            g = readInt(fp);
            b = readInt(fp);
            myPic->pixels[i][j].red = r;
            myPic->pixels[i][j].green = g;
            myPic->pixels[i][j].blue = b;
        }
    }
    fclose(fp);
    return myPic;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void writePic(ppmPic *myPic, FILE *fp) {
    // write the header information
    fprintf(fp, "P3\n%d %d\n%d\n", myPic->cols, myPic->rows, myPic->colors);

    int i, j;
    // write the pixel information
    for (i = 0; i < myPic->rows; i++) {
        for (j=0; j < myPic->cols; j++) {
            fprintf(fp,"%d %d %d   ", myPic->pixels[i][j].red,
                        myPic->pixels[i][j].green, myPic->pixels[i][j].blue);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void invertPic(ppmPic *myPic) {
    int i, j;
    for (i = 0; i < myPic->rows; i++) {
        for (j=0; j < myPic->cols; j++) {
            myPic->pixels[i][j].red   = myPic->colors - myPic->pixels[i][j].red;
            myPic->pixels[i][j].green = myPic->colors - myPic->pixels[i][j].green;
            myPic->pixels[i][j].blue  = myPic->colors - myPic->pixels[i][j].blue;
        }
    }
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void swapPic(ppmPic *myPic) {
    int i, j, temp;
    Pixel p;
    for (i = 0; i < myPic->rows; i++) {
        for (j=0; j < myPic->cols/2; j++) {
            temp = myPic->cols - j -1; 

            p.red   = myPic->pixels[i][j].red;
            p.green = myPic->pixels[i][j].green;
            p.blue  = myPic->pixels[i][j].blue;

            myPic->pixels[i][j].red   = myPic->pixels[i][temp].red;
            myPic->pixels[i][j].green = myPic->pixels[i][temp].green;
            myPic->pixels[i][j].blue  = myPic->pixels[i][temp].blue;

            myPic->pixels[i][temp].red   = p.red;
            myPic->pixels[i][temp].green = p.green;
            myPic->pixels[i][temp].blue  = p.blue;
        }
    }
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void rotatePic(ppmPic *myPic) {
    int i, j;
    Pixel **newData = malloc(sizeof(Pixel *) * myPic->cols);
    for (i=0; i<myPic->cols; i++)
        newData[i] = malloc(sizeof(Pixel) * myPic->rows);

    for (i = 0; i < myPic->cols; i++) {
        for (j=0; j < myPic->rows; j++) {
            newData[i][j].red   = myPic->pixels[myPic->rows-j-1][i].red;
            newData[i][j].green = myPic->pixels[myPic->rows-j-1][i].green;
            newData[i][j].blue  = myPic->pixels[myPic->rows-j-1][i].blue;
        }
    }

    int r, c;
    r = myPic->rows;
    c = myPic->cols;
    Pixel **p = myPic->pixels;

    myPic->rows = c;
    myPic->cols = r;
    myPic->pixels = newData;
    free(p);
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void flipPic(ppmPic *myPic) {
    int i, j, temp;
    Pixel *p;
    p = malloc(sizeof(Pixel) * myPic->cols);
    for (i = 0; i < myPic->rows/2; i++) {
        for (j=0; j < myPic->cols; j++) {
            p[j].red   = myPic->pixels[i][j].red;
            p[j].green = myPic->pixels[i][j].green;
            p[j].blue  = myPic->pixels[i][j].blue;
        }
        for (j=0; j < myPic->cols; j++) {
            temp = myPic->rows - i - 1; 
            myPic->pixels[i][j].red  = myPic->pixels[temp][j].red;
            myPic->pixels[i][j].green = myPic->pixels[temp][j].green;
            myPic->pixels[i][j].blue  = myPic->pixels[temp][j].blue;
            myPic->pixels[temp][j].red   = p[j].red;
            myPic->pixels[temp][j].green = p[j].green;
            myPic->pixels[temp][j].blue  = p[j].blue;
        }
    }
    free(p);
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////
