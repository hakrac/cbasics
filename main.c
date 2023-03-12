#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("Your number: ");
  unsigned int myNumber;  
  scanf("%d", &myNumber);
  unsigned int remainder;
  remainder = myNumber % 2;
  char binaryNumber[10] = "Hello";
  printf("%s", binaryNumber);
  if (remainder == 1) {
    printf("%d is not even\n", myNumber);
  } else {
    printf("%d is even\n", myNumber);
  }

  remainder = myNumber % 4;

  switch (remainder) {
    case 1:
      printf("%d has a remainder of %d\n", myNumber, 1);
      break;  
    case 2:
      printf("%d has a remainder of %d\n", myNumber, 2);
      break;
    case 3:
      printf("%d has a remainder of %d\n", myNumber, 3);
      break;
    case 0:
      printf("%d is divisible by %d\n", myNumber, 4);
      break;
    default:
      printf("Something went seriously wrong!\n");
      break;
  }
  
  printf("%p", &remainder);
  return 0;
}
