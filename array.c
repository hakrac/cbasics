#include <stdio.h>


int main() {
  int arr[10] = {};
  for(int i = 1; i < 11; i++) {
    arr[i - 1] = i % 2;
  }

  for(int j = 0; j < 10; j++) {
    printf("%d", arr[j]);
    if (j < 9)
      printf(" ");
  }

  return 0;
}
