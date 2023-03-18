#include <stdio.h>
#include <stdlib.h>



int permtest( const unsigned int* p, int laenge) {
  if(p == NULL) {
    return 0;
  }
  int *uval = malloc(laenge * sizeof(int));
  if(uval == NULL) {
    return 0;
  }
  for(int i = 0; i < laenge;i++) {
    uval[i] = 0;
  }
  for(int i = 0; i < laenge;i++) {
    if(p[i] > laenge) {
      return 0;
    }
    if(uval[p[i] - 1] == 0) {
      uval[p[i] - 1] += 1;
    } else {
      return 0;
    }
  }
  for(int i = 0; i < laenge;i++) {
    if(uval[i] != 1) {
      return 0;  
    }
  }
  free(uval);
  return 1;
}

int main() {
  const unsigned int p[] = {2};
  printf("%d", permtest(p, 1));
  return 0;
}
