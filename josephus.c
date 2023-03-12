#include <stdio.h>
#include <stdlib.h>


int josephus(int n) {
  if (n == 1) {
    return 1;
  } else if( n % 2 == 0) {
    return 2 * josephus(n / 2) - 1;
  } else {
    return 2 * josephus( (n - 1) / 2) + 1;
  }
}
