#include <stdio.h>


int main() {
  int phase = 0;
  scanf("%d", &phase);
  switch(phase % 4) {
    case 0:
      printf("ROT");
      break;
    case 1:
      printf("ROT/GELB");
      break;
    case 2:
      printf("GRÜN");
      break;
    case 3:
      printf("GELB");
      break;
  }
}
