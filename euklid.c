#include <stdio.h>


unsigned long gcd(unsigned long a, unsigned long b) {
  if (b == 0) {
    return a;
  }
  if (a < b) {
    return gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

/*
int main () {
  int a = ggT(10, 3);
  printf("%d", a);
  return 0;
}
*/
