#include <stdio.h>


unsigned long ggT(unsigned long a, unsigned long b) {
  if (b == 0) {
    return a;
  }
  if (a < b) {
    return ggT(b, a);
  }
  if (a % b == 0) {
    return b;
  }
  return ggT(b, a % b);
}

/*
int main () {
  int a = ggT(10, 3);
  printf("%d", a);
  return 0;
}
*/
