//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>

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


  printf("OR: %d\n", 12|11);
  // expected: 15
  // OR GATE
  // 1100
  // 1011
  // ----
  // 1111


  printf("AND: %d\n", 7&6);
  // expected: 6
  // AND GATE
  // 0111
  // 0110
  // ----
  // 0110

  printf("SHIFT: %d\n", 1 << 2);
  // expected: 4
  // 0001 shift right 2 times
  // 0100 = 4

//  printf("TILDA: %d\n", ~3);
//  // expected: 12
//  // reverses the bit order




  return 0;
}

// vim: tabstop=2 shiftwidth=2 expandtab
