#include <stdio.h>



int datum2int(int tag, int monat) {
  int m = monat;
  int dpm[12] = {
    31, // Januar
    28, // Feb
    31, // Maer
    30, // Apr
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
  };
  
  int d = 0;
  int i;
  for(i = 0; i < (m - 1); i++) {
    d += dpm[i];
  }
  return d + tag;
}

void int2datum(int tage, int* ergebnis) {
  int dpm[12] = {
    31, // Januar
    28, // Feb
    31, // Maer
    30, // Apr
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
  };
  

  int d;
  int m;
  int t = tage % 366;
  int i;
  for(i = 0; i < 12; i++) {
    if(t <= dpm[i]) {
      d = t;
      m = i + 1;
      break;
    } else {
      t -= dpm[i];
    }
  }
  
  ergebnis[0] = d;
  ergebnis[1] = m; 
}


/*
int main() {
  printf("%d\n", datum2int(1, 1));
  int e[2] = {0, 0};
 
  int2datum(31, e);
  
  printf("%d %d", e[0], e[1]); 
  return 0;  
}
*/
