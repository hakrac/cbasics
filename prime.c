#include <stdio.h>
#include <math.h>

int main() {
  
  int i = 2;
  for (i = 2; i <= 1000; i++) {
    int d = 1;
    for (int j = 2; j <= ceil(sqrt(i));j++) {
      if(i % j == 0 && i != j) { 
        d = 0;
        break;
      }
    }
    if(d) {
      if (i > 2)
        printf(" %d", i);
      else
        printf("%d", i);
    } 
  }
  return 0;
}
