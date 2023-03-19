#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 256


char ***parse_csv(char *csv) {
  int r = 0, col = 1;
  int i = 0;
  char c;
  while( (c = csv[i++]) != '\0') {
    if(c == '\n')
      r++;
  }
  i = 0;
  while ( (c = csv[i++]) != '\n') {
    if(c == ';')
      col++;
  }
  // printf("%d rows, %d cols\n", r, col);
  
  char ***m = (char ***)malloc(r * sizeof(char **));
  for(int i = 0; i < r; i++) {
    m[i] = (char **)malloc(col * sizeof(char *));
    for(int j = 0; j < col; j++) {
      m[i][j] = (char *)malloc(N * sizeof(char));
    }
  }
 
  c = 0;
  int j = 0, k = 0, t = 0;
  i = 0;
  while( (c = csv[i++]) != '\0') {
    if(c == '\n') {
      j++;
      k = 0;
      t = 0;
      continue;
    }
    if(c == ';') {
      m[j][k][t] = '\0';
      k++;
      t = 0;
      continue;
    }

    // printf("m[%d][%d][%d] = %c\n", j, k, t, c);
    m[j][k][t++] = c; 
  }
  return m; 
}
/*
int main() {
 char * csv_string = "ein sehhhrr seeeehhhrrr langer Text der sehr lang ist eig schon viel zu lang und er wird immer noch länger!!!!&§/$;a\n";
 char *** csv_array = parse_csv(csv_string);
 printf("%s\n", csv_array[0][1]);
  return 0;
}
*/
