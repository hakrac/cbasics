#include <stdio.h>
#include <math.h>


int eimer(double l, double leak) {
  if (l == 0 && leak == 0) {
    return 0;
  }
  if (leak == 100) {
    return 1;
  }
  double r = 1 - leak / 100;
  return ceil(log(0.01 / l) / log(r));
}

