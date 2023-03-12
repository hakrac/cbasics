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


int checkcollatz(int x) {
  if(x > INT_MAX) {
    return -1;
  } else if(x % 2 == 1 && x > INT_MAX/3) {
    return -1;
  }

  if(x == 1) {
    return 1;
  }
 
  int i = 0;
  int a = x; // ungerade werte von x_N 
  do {
      a = a % 2 == 0 ? a / 2 : 3 * a + 1;
      if(a == 1) {
        return 1;
      }
      if(a > INT_MAX) {
        return -1;
      }
  } while (i++ < INT_MAX);
  return -1;
 
}


int main() {
  int x = 0;
  scanf("%d", &x);
  int res = checkcollatz(x);
  if(res == -1) {
    printf("Leider keine Aussage möglich!");
  } else {
    printf("bestätigt!");
  }
  return 0;
}

