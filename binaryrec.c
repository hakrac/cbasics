#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "a04-testing.h"


int abs(int x) {
  return x > 0 ? x : -x;
}

void printArray(int *m, int l) {
  for(int i = 0; i < l;i++) {
    printf("%d ", m[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  if(argc != 3) {  
    printf("Fehler.");
    return -1;
  }
  int *start, *end;
  int *p;
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);
  if(n == 0 || k == 0) {
    printf("Fehler.");
    return -1;
  }
  if( n <= 0) {
    start = NULL, end = NULL;
    printf("%d \n", rec_contains(&p, start, end, k));
   
    return 0;
  } 
  int *m = malloc(n * sizeof(int));
  if(m == NULL) {
    printf("Fehler.");
    return -1;
  }
 
  for(int i = 0; i < n; i++) {  
    if(i == 0) {
      m[i] = i;
    } else {
      m[i] = i;
    } 
  }
  
  printArray(m, n);

  if(k < n) {
    int d = rec_contains(&p, m, &m[n], m[k]);
    printf("%d, %d, %p", d, *p, p);
  }


  free(m); 
  return 0;
}
