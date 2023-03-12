#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int qs(char *str) {
  int i;
  int sum = 0;
  do {
    sum += str[i] - '0';
    i += 1;
  } while (str[i] != '\0');
  return sum;  
}


int aqs(char *str) {
  int sum = 0;  
  int l = (int)strlen(str) - 1;
  int i = l;
  // printf("%d \n", i); 
 
  do {
    int sign = (l - i) % 2 == 0 ? 1 : -1;
    sum += (str[i] - '0') * sign;
    i -= 1;
    // printf("%d \n", sum);
  } while (i >= 0);
  return sum;

}


int main() {
  char str[100] = "";
  scanf("%s", str);
 
  int sum = aqs(str);
  /*
  while (sum >= 10) {
    int qs = 0; 
    while (sum) {
      qs += sum % 10;
      sum -= sum % 10;
      sum /= 10;
    }
    sum = qs;
    // printf("%d\n", sum);
  }
  */
  printf("%d", sum); 
  return 0;

}
