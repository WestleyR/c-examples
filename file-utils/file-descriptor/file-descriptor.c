//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    // Open the file
    int fd = open("hello.txt", O_WRONLY|O_CREAT);
    if (fd == -1) {
        perror("open");
        return(1);
    }

    // Write to it
    char* text = "Hello, world!\n";
    int sz = write(fd, text, strlen(text));
    printf("Bytes writen: %d\n", sz);

    // Close it
    if (close(fd) != 0) {
        perror("close");
        return(1);
    }

    // Reopen it, as readonly
    fd = open("hello.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return(1);
    }

    // Read the file
    int ret;
    char buf[1024];
    while ((ret = read(fd, buf, sizeof(buf)-1)) > 0) {
        buf[ret] = 0x00;
        printf("%s\n", buf);
    }

    // Close it
    if (close(fd) != 0) {
        perror("close");
        return(1);
    }

    return(0);
}

