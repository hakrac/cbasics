#include <stdio.h>
#include <limits.h>
#include <float.h>



int main () {
  int i;
  do {
    int res = scanf("%d", &i);
    if (res == EOF) {
      break;
    }
    printf("OKT: %o, HEX: %x\n", i, i);
  } while (1);
  return 0;
}
