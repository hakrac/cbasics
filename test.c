#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
  int i, size;
  int *v;
  scanf("%d", &size);
  v = malloc(size * sizeof(int));
  for(i=0; i < size; i++) {
    scanf("%d", &v[i]); 
  }
  
  for(int j = 0; j < size;j++) {
    printf("%d", v[j]);
  }
  return 0;
}
