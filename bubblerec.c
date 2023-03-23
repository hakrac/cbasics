#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int recSort(int* start, int* end, int reverse) {
  int l = start - end;


  for(int i = 0; i < l; i++) {
    printf("%d ", start[i]);
  }
  // printf("\n");

  if(l == 1) {
    return 0;
  }
  int *p;
  int k = 0;
  if(reverse == 0) {
    for(p = start; p < end;p++) {
      if(*p < *(p + 1)) {
        int temp = *(p + 1);
        *(p + 1) = *p;
        *p = temp;
        k++;
      }
    }
  } else {
    for(p = end; p > start; p--) {
      if(*p > *(p - 1)) {
        int temp = *(p - 1);
        *(p - 1) = *p;
        *p = temp;
        k++;
      }
    }
  }

  if(k == 0)
    return 0;
  if(reverse)
    return recSort(start + 1, end, 0) + k; 
  return recSort(start, end - 1, 1) + k;
}

void printArray(int *a, int l) {
  for(int i = 0; i < l;i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
/*
int main() {
  int a[6] = {9, 1, 11, 9, 10, 14};
  int d = recSort(a, &a[5], 0);
  printArray(a, 6);
  printf("%d\n", d);
  // int b[4] = {5, 3, 7, 1};
  // int f = recSort(b, b+3, 0);
  // printArray(b, 4);
  // printf("%d", f);
  return 0;
}
*/
