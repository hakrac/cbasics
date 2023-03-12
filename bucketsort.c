#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int *bucket_sort( int values[], int length, int max ) {
  int *rg = malloc((max + 1) * sizeof(int));
  if(rg == NULL) {
    return NULL;
  }
  for(int i = 0; i < max + 1; i++) {
    rg[i] = 0;
  }
  for(int i = 0; i < length;i++) {
    if(values[i] < 0 || values[i] > max) {
      return NULL;
    } 
    rg[values[i]] += 1;
  }

  int k = 0;
  for(int i = 0; i < max + 1; i++) {
    for(int j = 0; j < rg[i]; j++) {
      values[k++] = i; 
    }
  }  
  free(rg);
  return values;
}


/*
int main() {
  int a[] = {5,3,6,1,5,4,8,9,6,6,6};
  int *result = bucket_sort(a, 11, 9);
  for(int i = 0; i < 11;i++) {
    printf("%d", result[i]);
  }
  return 0;
}
*/
