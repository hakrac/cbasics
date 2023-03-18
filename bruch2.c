#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
  int zaehler;
  int nenner;
} bruch_t;

int compare_rational( bruch_t x, bruch_t y ) {
  
  if(x.nenner < 0) {
    x.zaehler *= -1;
    x.nenner *= -1;
  }
  if(y.nenner < 0) {
    y.zaehler *= -1;
    y.nenner *= -1;
  }

  return x.zaehler * y.nenner - x.nenner * y.zaehler;
}

/*
int main() {
  bruch_t x;
  bruch_t y;
  x.zaehler = -1;
  x.nenner = 2;
  y.zaehler = 1;
  y.nenner = -3;
  printf("%d", compare_rational(x, y));;
  return 0;
}
*/
