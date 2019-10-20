//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>
#include <string.h>

int main() {
  // Bit table
  //
  // 0  | 0000
  // 1  | 0001
  // 2  | 0010
  // 3  | 0011
  // 4  | 0100
  // 5  | 0101
  // 6  | 0110
  // 7  | 0111
  // 8  | 1000
  // 9  | 1001
  // 10 | 1010
  // 11 | 1011
  // 12 | 1100
  // 13 | 1101
  // 14 | 1110
  // 15 | 1111
  //

  printf("0x%x\n", 0700);
  printf("0x%x\n", 'h');
  printf("%c\n", 0x68);
  printf("%d\n", (int)'d');
  printf("%c\n", 101);

  printf("\n");

  const int maxLine = 8;
  int lineIndex = 0;

  for (int i = 33; i < 127; i++) {
    if (lineIndex >= maxLine*2) {
      printf("\n");
      lineIndex = 0;
    }
    printf("%c ", i);
    lineIndex++;
  }

  printf("\n\n");

  static const char chars[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U',
    'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '\0'
  };

  lineIndex = 0;

  for (int i = 0; i < strlen(chars); i++) {
    if (lineIndex >= maxLine) {
      printf("\n");
      lineIndex = 0;
    }
    printf("0x%x ", chars[i]);
    lineIndex++;
  }
  printf("\n\n");

  static const unsigned char hexChars[] = {
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
    0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e,
    0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,
    0x56, 0x57, 0x58, 0x59, 0x5a, 0x61, 0x62,
    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
    0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70,
    0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
    0x78, 0x79, 0x7a, 0x30, 0x31, 0x32, 0x33, 
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x00
  };


  lineIndex = 0;

  for (int i = 0; i < strlen(hexChars); i++) {
    if (lineIndex >= maxLine*2) {
      printf("\n");
      lineIndex = 0;
    }
    printf("%c ", hexChars[i]);
    lineIndex++;
  }
  printf("\n\n");


  return 0;
}

// vim: tabstop=2 shiftwidth=2 expandtab
