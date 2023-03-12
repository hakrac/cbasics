#include <stdio.h>

/*

long iteA(unsigned int n) {
  if(n == 0) {
    return 0;
  } else if(n == 1) {
    return 1;
  }
  
  return -2 * iteA(n - 1) + 3 * iteA(n - 2);
}

*/

long iteA(unsigned int n) {
  int a = 0, b = 1;
  int i;
  for(i = 1; i < n; i++) {
    if(i % 2 == 1) {
      a = - 2 * b + 3 * a;
    } else {
      b = - 2 * a + 3 * b;
    }
  }
  
  if (n % 2 == 0) {
    return a;
  } else {
    return b;
  }
}

/*
int main () {
  printf("%ld\n", iteA(5)); 
  return 0;
}
*/
