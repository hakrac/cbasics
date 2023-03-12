#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void readmatrix(int z, int s, int matrix[z][s]) {
  for(int i = 0; i < z; i++) {
    for(int j = 0; j < s;j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}


int main() {
  int m1, n1;
  scanf("%d %d", &n1, &m1);
  if(m1 > 20 || n1 > 20) {
    printf("Dimensionsfehler: Maximale Zeilen- bzw. Spaltenzahl ist 20");
    return 0;
  }
  int matrix1[m1][n1]; // m1 x n1 matrix
  readmatrix(m1, n1, matrix1);
  int m2, n2;
  scanf("%d %d", &n2, &m2);
  // check n1 == m2
  if(n1 != m2) {
    printf("Dimensionsfehler: Spaltenzahl der ersten Matrix muss mit Zeilenzahl der zweiten Matrix über einstimmen");
    return 0;
  }
  if(m2 > 20 || n2 > 20) {
    printf("Dimensionsfehler: Maximale Zeilen- bzw. Spaltenzahl ist 20");
    return 0;
  }
   
  int matrix2[m2][n2];
  readmatrix(m2, n2, matrix2);
  
  int prod[m1][n2];
  for(int z = 0; z < m1; z++) {
    for(int s = 0; s < n2; s++) {
      int sum = 0;
      for(int m = 0; m < n1; m++) {
        sum += matrix1[z][m] * matrix2[m][s];
      }
      prod[z][s] = sum;
      printf("%d ", sum);
    }
    printf("\n");
  } 
 
  return 0;
}
