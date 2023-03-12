#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int suche(int *array, int len, int value) {
  if(len == 0)
    return 0;
  if(len == 1) {
    return array[0] == value ? 1 : 0;
  }
  int m = floor(len / 2.0);
  if(array[m] < value) {
    int *narray = malloc(m * sizeof(int));
    for(int i = 0; i < m;i++) {
      narray[i] = array[i];
    }
    return suche(narray, m, value);
  } else if(array[m] > value) { 
    int *narray = malloc((len - m) * sizeof(int));
    for(int i = 0; i < len - m; i++) {
      narray[i] = array[i + m];
    }
    return suche(narray, len - m, value);
  } else {
    return 1;
  } 
}

/*
int main () {
  int a[] = {50,20};
  printf("%d", suche(a, 2, 20));
  return 0;
}
*/
