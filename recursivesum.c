#include <stdio.h>
#include <math.h>
#define PI 3.14159265


double kreisflaeche(double durchmesser) {
  return pow(durchmesser / 2, 2) * PI;
}

double kreisumfang(double durchmesser) {
  return durchmesser * PI;
}

int main() {
  int i, j;
  for (i = 1; i <= 5; i++) {
    for (j = 1; j <= 5; j++) {
      if(i * j >= 10) {
        printf(" %d", i * j);
      } else {
        printf("  %d", i * j);
      }
    }
    printf("\n");
  }
}
