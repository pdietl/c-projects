#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#include "image.h"
#include "ppm.h"

////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
    FILE *fpIn, *fpOut;
    ppmPic *myPic;
    int outFileName = 0;

    if (argc == 1) {
        printf("Usage: a.exe option(s) ppm-file, options are -swap, -flip, -rotate, -invert\n");
        return 1;
    }

    // check options are valid
    int a, opt;
    for (a=1; a<(argc-1); a++) {
        opt = validOption(argv[a]);
        if ( opt == 0 ) {
            fprintf(stderr, "Option '%s' is not a valid option\n", argv[a]);
            return 1;
        }
        if ( opt == 5 )
            a = a + 1;          // skip output file name
    }

    fpIn = fopen(argv[argc-1], "r");
    if ( fpIn == NULL ) {
        fprintf(stderr, "The file %s does not exist\n", argv[argc-1]);
        return 1;
    }
    // initialize the file
    myPic = readPic(fpIn);
    if ( myPic == NULL )
        return 1;

    for (a=1; a<(argc-1); a++)
        switch ( validOption(argv[a]) ) {
            case 1: flipPic(myPic);   // flip
                break;
            case 2: swapPic(myPic);   // swap
                break;
            case 3: rotatePic(myPic); // rotate
                break;
            case 4: invertPic(myPic); // invert
                break;
            case 5: outFileName = a + 1;  // save output filename location
                a = a + 1;                // don't process output filename
                break;
        }

    if (outFileName == 0)
        fpOut = stdout;
    else {
        fpOut = fopen(argv[outFileName], "w");
        if (fpOut == NULL) {
            fprintf(stderr, "Could not open output file %s\n", argv[a+1]);
            return 1;
        }
    }
    writePic(myPic, fpOut);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////

int validOption(char *s) {
    if (strcmp(s, "-f") == 0)   return 1;
    if (strcmp(s, "-s") == 0)   return 2;
    if (strcmp(s, "-r") == 0)   return 3;
    if (strcmp(s, "-i") == 0)   return 4;
    if (strcmp(s, "-o") == 0)   return 5;
    if (strcmp(s, "--flip") == 0)     return 1;
    if (strcmp(s, "--swap") == 0)     return 2;
    if (strcmp(s, "--rotate") == 0)   return 3;
    if (strcmp(s, "--invert") == 0)   return 4;
    if (strcmp(s, "--output") == 0)   return 5;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
