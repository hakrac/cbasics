#include <stdio.h>
#include <limits.h>


long rekS(unsigned int k) {
  
  if(k == 0) {
    return 0;
  } else if (k == 1) {
    return 1;
  }
  
 
  if(k % 2 == 0) {
    return rekS(k / 2);
  } else {
    if( rekS((k - 1) / 2) >= LONG_MAX/2 || rekS((k + 1) / 2) >= LONG_MAX / 2) {
      return -1;
    } else if( rekS((k - 1) / 2) <= LONG_MIN/2 || rekS((k + 1) / 2) <= LONG_MIN / 2) {
      return -1;
    }
    return rekS((k - 1) / 2) + rekS((k + 1) / 2);
  }
}


/*

int main() {
  printf("%ld", rekS(3));
  return 0;  
}
*/
