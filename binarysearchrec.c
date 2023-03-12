#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int rec_contains(int **pos, int *start, int *end, int x) {
  int len = start - end;
  printf("%d", len);
  if(len == 0) {
    pos = NULL;
    return 0;
  } else if(len == 1) {
    pos = NULL;
    return 0;
  }
  int m = floor(len / 2.0);
  if(start[m] > x) {
    end = start + m;
    return rec_contains(pos, start, end, x);
  } else if(start[m] < x) {
    start = start + m;
    return rec_contains(pos, start, end, x);
  } else {
    pos = &(start + m);
    return 1;
  }  
}


int main() {
  int a[] = {50, 20};
  int **pos;
  int b = rec_contains(pos, a, &a[2], 20);
  return 0;
}
