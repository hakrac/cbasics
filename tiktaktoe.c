#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



void printField(int **f) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(f[i][j] == 1)
        printf("x ");
      else if(f[i][j] == -1)
        printf("o ");
      else
        printf("_ ");
    }
    printf("\n");
  }
}

void readMove(int **f) {
  int x = -1, y = -1;
  while(1) {
    printf("(x:y)> ");
    scanf("%d:%d", &x, &y);
    if( x >= 1 && x <= 3 && y >= 1 && y <= 3 && f[y - 1][x - 1] == 0 ) {
      f[y - 1][x - 1] = 1;
      break;
    }
  }
}

int check(int **f) {
  for(int k = 0; k < 2; k++) {
    int i, j;
    for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++) {
        if(f[i][j] != (int)pow(-1, k))
          break;
      }
      if(j == 3)
        return 1;
      for(j = 0; j < 3; j++) {
        if(f[j][i] != (int)pow(-1, k))
          break;
      }
      if(j == 3)
        return (int)pow(-1, k);
    }
  }
  for(int k = 0; k < 2; k++) {
    int i, j;
    for(i = 0; i < 3; i++) {
      if(f[k == 0 ? i : 2 - i][i] != (int)pow(-1, k))
        break;
    }
    if(i == 3)
      return (int)pow(-1, k);
  }   
  return 0;
}

int max() {
  return 1;
}

int min() {
  return 1;
}



int main () {
  int**f = (int **)malloc(3 * sizeof(int *));
  for(int i = 0; i < 3; i++) {
    f[i] = (int *)malloc(3 * sizeof(int));
    for(int j = 0; j < 3; j++) {
      f[i][j] = 0;
    }
  }

  while(check(f) != 1) {
    readMove(f);
    printField(f);
    printf("\n");
  }
  return 0;
}
