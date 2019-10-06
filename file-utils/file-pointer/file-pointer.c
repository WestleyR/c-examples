//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>

int main(int argc, char** argv) {
    FILE *fileout;

    fileout = stdout;

    if (argc > 1) {
        FILE *fp;
        fp = fopen(argv[1], "w");

        fileout = fp;
    }

    fprintf(fileout, "hello world!\n");

    return(0);
}

