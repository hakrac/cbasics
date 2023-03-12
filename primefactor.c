#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int isprime(int num) {
  for(int i = 2; i <= sqrt(num);i++) {
    if(num % i == 0) {
      return 0; 
    }
  }
  return 1;
}

int *factor(int num) {
  int factors[num];
  int k = 0;
  // find prime number that divides num
  int i;
  for(i = 2; i <= sqrt(num); i++) {
    if(num % i == 0 && isprime(i)) {
      factors[k++] = i;
      num /= i;
      i = 1;
    }
  }
  factors[k++] = num;
  factors[k++] = 0; // marks end
  int *f = malloc(k * sizeof(int));
  for(int j = 0; j < k; j++) {
    f[j] = factors[j];
  }
  return &f[0];
}


int main () {
  int num;
  scanf("%d", &num);
  if(num > UINT_MAX || num < 0) {
    return 0;
  }
  
  int *array = factor(num);
  int i = 0;
  int c = 0;
  printf("%d: ", num);
  if(num == 1)
    return 0;
  while ((c = array[i++])) {
    printf("%d", c);
    if (array[i] != 0) {
      printf(" ");
    }
  }
  
  return 0;
}
