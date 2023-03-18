#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int* fahrgaeste(int einaus[][2], int n) {
  int *g = malloc(n * sizeof(int)); 
  for (int i = 0; i < n;i++) {
    if(i == 0) {
      g[i] = einaus[i][0] - einaus[i][1];
    } else {
      g[i] = einaus[i][0] - einaus[i][1] + g[i - 1];
    }
  }
  return g;
}

/*
int main() {
  int einaus[5][2] = {{5, 0},{4, 2},{5, 1},{5, 2},{0, 1}};
  int* gaeste = fahrgaeste(einaus, 5);

  for(int i = 0; i < 5; i++) {
    printf("%d\n", gaeste[i]);
  }
  
  return 0;
}
*/
