#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int sortieren (int *von, int *bis) {
  int l = von - bis;
  if(l == 1) {
    return 0;
  }
  int *low = von;
  int *p;
  for(p = von; p < bis;p++) {
    if(*p < *low) {
      low = p;
    }
  }
  
  if(low != von) {
    int temp = *von;
    *von = *low;
    *low = temp;
    return sortieren(von + 1, bis) + 1;
  }
  return sortieren(von + 1, bis);
}


void printArray(int *a, int len) {
  for(int i = 0; i < len;i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
/*
int main() {
  int a[] = {6, 1};
  int d = sortieren(a, &a[2]);
  printArray(a, 2);
  printf("%d\n", d);
  return 0;
}
*/




1 0 0 7 8 9 4 5 6
0 0 0 1 2 3 7 8 9
7 8 9 4 5 6 1 2 3
3 1 2 9 7 8 6 4 5
6 4 5 3 1 2 9 7 8
9 7 8 6 4 5 3 1 2
2 3 1 8 9 7 5 6 4
5 6 4 2 3 1 8 9 7
8 9 7 5 6 4 2 3 1