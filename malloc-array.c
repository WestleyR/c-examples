//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **foo;

    foo = (char **) malloc(5);

    for (int i = 0; i < 5; i++) {
        char *bar = NULL;
        bar = (char *) malloc(20);
        foo[i] = (char *) malloc(20);
        sprintf(bar, "hello: %d", i);
        strcpy(foo[i], bar);
        bar = NULL;
        free(bar);
    }

    foo[5] = (char *) malloc(1);
    foo[5][0] = '\0';

    int b = 0;
    while(1) {
        if (foo[b][0] == '\0') break;
        printf("array: %s\n", foo[b]);
        //free(foo[b]);
        b++;
    }

    free(foo);

    return(0);
}

