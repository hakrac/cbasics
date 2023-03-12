#include <stdio.h>

int hauskauf(float sparen_emily, float sparen_sarah, int haus_kosten) {
  int m = 0;
  double savings = sparen_emily + sparen_sarah; 
  while(savings < haus_kosten) {
    m += 1;
    // printf("%d", m / 36);
    savings *= (1.015 + (m / 36) * 0.001);
    savings += 2000;
  }
  return m;
}
/*
int main() {
  printf("%d", hauskauf(0, 1, 0));
  return 0;
}
*/
