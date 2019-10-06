//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>

#ifndef BAR
#error "BAR is not defined :P  Compile with -DBAR"
#endif

int main() {

#ifndef FOO
    printf("FOO is not defined\n");
#else
    printf("FOO is defined\n");
#endif

    return(0);
}

