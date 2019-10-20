//
// This project is unlicensed, you are free to use and modify any of these examples for your own needs.
//
// source code: https://github.com/WestleyR/c-examples
//

#include <stdio.h>

void getBcdArray(int ret[], int num) {
  int rindex = 0;
  for (int c = 3; c >= 0; c--) {
    int k = num >> c;

    //ret[rindex] = (k & 1 ? 1 : 0);
    if (k & 1) {
      ret[rindex] = 1;
    } else {
      ret[rindex] = 0;
    }
    printf("INFO: %d => %d\n", rindex, ret[rindex]);
    rindex++;
  }
}

int main() {
  int n;

  scanf("%d", &n);

  int arr[] = {0,0,0,0};

  getBcdArray(arr, n);

  printf("ARR[] = [ %d %d %d %d ]\n", arr[0], arr[1], arr[2], arr[3]);

  return 0;
}

// vim: tabstop=2 shiftwidth=2 expandtab
