#include <stdio.h>


int main() {
  int input = 0;
  scanf("%d", &input);
  int a = input / 4;
  int b = input % 4;
  for(int i = 1; i <= a; i++) {
    if(i == a) {
      printf("viele");
    } else {
      printf("viele-");
    }
  }
  if(a && b) {
    printf("-%d", b);
  } else if(b) {
    printf("%d", b);
  }
  return 0;
}
