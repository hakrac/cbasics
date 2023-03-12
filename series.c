#include <stdio.h>
#include <limits.h>


int sequence(int x, int n) {
  if(x > INT_MAX) {
    return -1;
  } else if(x % 2 == 1 && x > INT_MAX/3) {
    return -1;
  }  
  if(n < 0) {
    return 0;
  } else if(n == 0) {
    return x;
  }
  int a = x; // ungerade werte von x_N
   
  for(int i = 1; i <= n; i++) {
      a = a % 2 == 0 ? a / 2 : 3 * a + 1;
      if(a > INT_MAX) {
        return -1;
      }
  }
  return a;
}

/*

int main() {
  printf("%d", sequence(2147483647, 10));
  return 0;
}

*/
