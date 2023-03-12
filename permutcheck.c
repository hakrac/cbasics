#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 2


int permatcheck(const int** p, int laenge) {
  if(p == NULL) {
    return 0;
  }
  for(int i = 0; i < laenge;i++) {
    int zs = 0;
    int ss = 0;
    for(int j = 0; j < laenge;j++) {
      zs += p[i][j];
      ss += p[j][i];
      if(p[i][j] != 1 && p[i][j] != 0) {
        return 0;
      }
    }

    if(zs != 1 || ss != 1) {
      return 0;
    }
  }
  
  return 1;
  
}

/*
int main() {
  int inhalt[N*N] = {1,0,0,1};
  int *matrix[N];
  matrix[0] = &inhalt[0];
  matrix[1] = &inhalt[N];
  printf("%d\n",permatcheck((const int**)matrix,N));
}
*/
