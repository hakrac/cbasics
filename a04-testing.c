#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int rec_contains(int **pos, int *start, int *end, int x) {
  int len = end - start;
  // printf("0: %d; len: %d\n", start[0], len);
  
  // printf("%d", len);
  if(len == 0) {
    *pos = NULL;
    printf("NOT FOUND");
    return 0;
  } else if(len == 1 && *start != x) {
    *pos = NULL;
    printf("NOT FOUND");
    return 0;
  }
  int m = len / 2;
  if(start[m] > x) {
    end = start + m;
    return rec_contains(pos, start, end, x);
  } else if(start[m] < x) {
    start = start + m;
    return rec_contains(pos, start, end, x);
  } else {
    // printf("m: %d, found: %d\n", m, start[m]);
    *pos = start + m;
    return 1;
  }  
}

/*
int main() {
  int a[] = {1, 2, 4, 4, 6, 7, 10, 20, 55, 69, 70, 71, 72};
  int *pos;
  int b = rec_contains(&pos, a, &a[13], 0);
  printf("%d, %d", b, pos == NULL);
  //printf("%p", pos);
  //printf("%d", *pos);
  return 0;
}
*/

