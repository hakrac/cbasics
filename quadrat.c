#include <stdio.h>
#include <math.h>


int main() {
  int year;
  scanf("%d", &year);
  switch(year % 4) {
    case 1:
    case 3:
      printf("keine Spiele");
      break;
    case 2:
      printf("Winterspiele");
      break;
    case 0:
      printf("Sommerspiele");
      break;
  }
}
