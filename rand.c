#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>


int main() {
  time_t t;
  srand((unsigned) time(&t));
  for(int i = 0; i < 1;i++) {
    printf("%d\n", rand() % 6);
  }
  return 0;
}
