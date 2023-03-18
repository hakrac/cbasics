#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int min(int *o, int len) {
  int m = o[0];
  for(int i = 0; i < len;i++) {
    if(o[i] < m) {
      m = o[i];
    }
  }
  return m;
}

void printMatrix(int n, int k, int m[n][k]) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k;j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}



int levenshtein(char* wort1, char* wort2) {
  int l1 = strlen(wort1);
  int l2 = strlen(wort2);
  if(l1 == 0 && l2 == 0) {
    return 0;
  }
  int m[l1 + 1][l2 + 1];
  int i, j;
  
  for(i = 0; i <= l1; i++) {
    for(j = 0; j <= l2; j++) {
      m[i][j] = 0;
    }
  }
  
  for(i = 0; i <= l1;i++) {
    m[i][0] = i;
  }
  for(j = 0; j <= l2; j++) {
    m[0][j] = j;
  }
 
  // printMatrix(l1+1, l2+1, m);
 
  for(i = 1; i <= l1; i++) {
    for(j = 1; j <= l2; j++) {
      int cell = 1;
      if(wort1[i - 1] == wort2[j - 1]) {
        cell = 0;
      }
      
      int o[4] = {
        m[i - 1][j - 1] + cell,
        m[i - 1][j - 1] + 1,
        m[i][j - 1] + 1,
        m[i - 1][j] + 1
      }; 

      m[i][j] = min(o, 4);
    }
  }

  // printMatrix(l1+1, l2+1, m);
  
  return m[i - 1][j - 1];
}
/*
int main() {
  printf("%d", levenshtein("saturday", "sunday"));
  return 0;
}
*/

