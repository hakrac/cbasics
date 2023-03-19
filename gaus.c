#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define N 200

/*
double **prod(int n, int m, double **m1, int k, double **m2) {
  double **p = (double **)malloc(n * sizeof(double *));
  for(int i = 0; i < n;i++) {
    p[i] = (double *) malloc(k * sizeof(double));
  }
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k; j++) {
      double sum = 0;
      for(int l = 0; l < m; l++) {
        sum += m1[i][l] * m2[l][j];       
      }
      p[i][j] = sum;
    }
  }
  return p; 
}
*/

double *prod_vec(int n, int m, double **matrix, double *vec) {
  double *p = (double *)malloc(n * sizeof(double));
  for(int i = 0; i < n; i++) {
    double sum = 0;
    for(int j = 0; j < m; j++) {
      sum += matrix[i][j] * vec[j];
    }
    p[i] = sum;
  }
  return p;
}


// zeilen addition
// addieren der i1-zeile * f auf die i2-zeile
int z_add(int n, int i1, int i2, double f, double **m) {
  if(i2 >= n || i1 >= n) {
    return 0;
  }
  for(int k = 0; k < n; k++) {
    m[i2][k] += f * m[i1][k];
  }
  return 1;
}

int z_mul(int n, int i, double f, double **m) {
  for(int k = 0; k < n; k++) {
    m[i][k] *= f;
  }
  return 1;
}

double **id(int n) {
  double **m = (double **)malloc(n * sizeof(double *));
  for(int i = 0; i < n; i++) {
    m[i] = (double *)malloc(n * sizeof(double));
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (j == i)
        m[i][j] = 1.0;
      else
        m[i][j] = 0.0;
    }
  }
  
  return m; 
}

void printMatrix(int n, double **m) {
  for(int i = 0; i < n; i++) { // zeilen index
    for(int j = 0; j < n; j++) { // spalten index
      printf("%.2lf ", m[i][j]);
    }
    printf("\n");
  }
}

int inv(int n, double **m, double **m_id) {
 

  // gauß elimination
  for(int j = 0; j < n - 1; j++) { // spalten index
    double f = m[j][j];
    for(int i = j + 1; i < n; i++) { // zeilen index
      double t = -m[i][j];
      z_add(n, j, i, t / f, m);
      z_add(n, j, i, t / f, m_id); 
    }
  }

  // printf("m: \n");
  // printMatrix(n, m);
  // printf("\nm_id: \n");
  // printMatrix(n, m_id);
  
  // det pruefen
  double det = 1;
  for(int i = 0; i < n; i++) {
    det *= m[i][i];
  }
  if(det == 0) {
    return 0;
  }

  // rueckwaerts einsetzen
  for(int j = n - 1; j > 0; j--) {
    double f = m[j][j];
    for(int i = j - 1; i >= 0; i--) {
      double t = -m[i][j];
      z_add(n, j, i, t / f, m);
      z_add(n, j, i, t / f, m_id);
    }
  }
 
  // normieren
  for(int i = 0; i < n; i++) {
    double t = m[i][i];
    z_mul(n, i, 1 / t, m);
    z_mul(n, i, 1 / t, m_id);
  }
 
  //printf("m: \n");
  //printMatrix(n, m);
  //printf("m_id: \n");
  //printMatrix(n, m_id); 
 
  return 1;
}

void readMatrix(int n, double **m, double *b) {
  
  for(int i = 0; i < n; i++) {
    char *line = (char *)malloc(N * sizeof(char));
    char c = 0;
    int t = 0;
    while( (c = getchar()) != '\n') {
      line[t++] = c;
    }
    line[t] = '\0';
    if(t <= 0) {
      i -= 1;
      continue;
    }
      
     
    char *token = strtok(line, " ");
    char *p;
    for(int j = 0; j < n; j++) {
      m[i][j] = strtod((const char *)token, &p);
      if(token != NULL)
        token = strtok(NULL, " ");
      else
        printf("Fehler");
    }
    if(token != NULL)
      b[i] = strtod((const char *)token, &p);
    else
      printf("Dimensionsfehler\n");
    
  }
}

int main () {
  int n = 0;
  scanf("%d", &n);
  char c;
  while ( (c = getchar()) != '\n')
    ; 
  if(n <= 0) {
    return 0;
  }
  double **m = (double **)malloc(n * sizeof(double *));
  for(int i = 0; i < n; i++) {
    m[i] = (double *)malloc(n * sizeof(double));
  }
  double *b = (double *)malloc(n * sizeof(double));
  
  readMatrix(n, m, b);
 
  /* 
  printf("===========\n");
  printMatrix(n, m);
  printf("===========\n");
  */

    
  double **m_id = id(n);
  int invertable = inv(n, m, m_id); 
  if(invertable == 0) {
    printf("keine eindeutige Lösung \n");
  }
  double *x = prod_vec(n, n, m_id, b);
  for(int i = 0; i < n; i++) {
    printf("%.2lf\n", x[i]);
  }
 
  
 
  return 0;
}



