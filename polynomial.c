#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


double poly(double *coef, int n, double x) {
  double sum = coef[0];
  for(int i = 1; i <= n; i++) {
    sum = coef[i] + sum * x;
  }
  return sum;
}

int main() {
  int deg;
  scanf("%d", &deg);
  double coefs[deg + 1];
  for(int i = 0; i <= deg;i++) {
    scanf("%lf", &coefs[i]); 
  }
  
  double x;
  while(scanf("%lf", &x) != EOF) {
    printf("%lf\n", poly(coefs, deg, x));
  } 
  return 0;
}


