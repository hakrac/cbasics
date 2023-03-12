#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int strclean(char *t) {
  int i = 0;
  int k = 0;
    if(t[i] < 33 || t[i] > 126) {
      t[i] = -1;
      k += 1;
    }
    i += 1;
  } while(t[i] != '\0');

  return k;
}

int main() {
  return 0;
}
