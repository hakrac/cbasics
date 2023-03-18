#include <stdio.h>


void inc(int *i, int **j) {
  int c = 0;
  while (c < 10) {
    printf("i[%d]: %d\n", c, i[c]);
    c++;
 } 

  *j = i + 2;
  printf("**j: %d\n", **j);
}


int main() {
  int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *j;
  inc(i, &j);
  return 0;
}
