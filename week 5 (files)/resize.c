#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[]) {

    // ensure proper usage
    if (argc != 4) {
        printf("Usage:resize n infile outfile\n");
        return 1;
    }

    // Check the resize factor
    int factor = atoi(argv[1]); // parse int from console args
    if (factor < 0 || factor > 100) {
        printf("The resize factor should be a positive integer 0..100\n");
        return 2;
    }

    // remember filenames and factor
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL) {
        printf("Could not open file %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL) {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // todo: add [parsing] files

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;
}