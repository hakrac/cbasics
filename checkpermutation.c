#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int is_perm(const int perm[], int length) {
  if(perm == NULL) {
    return -1;
  }
  int *anzahl = malloc(length * sizeof(int));
  if(anzahl == NULL) {
    return 0;
  }
  for(int i = 0; i < length; i++) {
    anzahl[i] = 0;
  }
  for(int i = 0; i < length; i++) {
    if(perm[i] > length) {
      return 0;
    }
    if(anzahl[perm[i] - 1] == 0) {
      anzahl[perm[i] - 1] += 1;
    } else {
      return 0;
    }
  }
  for(int i = 0; i < length;i++) {
    if(anzahl[i] != 1) {
      return 0;
    }
  }
  
  free(anzahl);
  return 1;
}

/*
int main() {
  int p1[] = {1, 2};
  int l = sizeof(p1) / sizeof(p1[0]);
  int b = is_perm(NULL, 0);
  printf("%d", b);
  return 0;
}
*/
