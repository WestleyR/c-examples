//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int a, b;
  unsigned char l;
  unsigned char m[256];
} code;

int write_bin(const char* filepath, const char *msg, int msg_len) {
  //unsigned char buffer[msg_len+1];
  //unsigned char buffer[64];
//  buffer[0] = '\0';
//
//  //strcat(buffer, msg);
//  strcat(buffer, "Hello");

  //unsigned char buffer[] = "foo";

  //buffer[msg_len] = '\0';

  FILE *fp;

  fp = fopen(filepath, "wb");
  if (fp == NULL) {
    perror("open");
    return(1);
  }

  //printf("Writing: %s to: %s...\n", buffer, filepath);
  
  code cp;

  cp.a = 1;
  cp.b = 2;
  cp.l = 'H';


//  cp.m = (char*) malloc(20);

  cp.m[0] = '\0';
  //strcat(cp.m, msg);
  strcpy(cp.m, msg);

  size_t write_bytes = fwrite(&cp, sizeof(cp), 1, fp);
  fclose(fp);
  printf("Written %d elements(s) to %s\n", (int)write_bytes, filepath);

  //fwrite(buffer, sizeof(buffer), sizeof(buffer), fp);

//  free(cp.m);

  return(0);
}

int read_bin(const char* filepath) {
//  unsigned char buffer[64];
  FILE *fp;

  fp = fopen(filepath, "rb");
  if (fp == NULL) {
    perror("open");
    return(1);
  }

  code buffer;

//  buffer.m = (char*) malloc(20);
//  buffer.m[0] = '\0';


  fread(&buffer, sizeof(buffer), 1, fp);
  
  fclose(fp);


  printf("%d %d %c\n", buffer.a, buffer.b, buffer.l);

  printf("%s\n", buffer.m);

//  free(buffer.m);


//  for (int i = 0; i < strlen(buffer); i++) {
//    printf("%c", buffer[i]);
//  }
//  printf("\n");



  return(0);
}

int main(int argc, char** argv) {

  if (argc < 3) {
    printf("arg err\n");
    return(1);
  }

  if (strcmp(argv[1], "write") == 0) {
    write_bin("foo.bin", argv[2], strlen(argv[2]));
  } else if (strcmp(argv[1], "read") == 0) {
    read_bin(argv[2]);
  } else {
    printf("command not supported\n");
  }

  return(0);
}


// vim: tabstop=2 shiftwidth=2 expandtab
