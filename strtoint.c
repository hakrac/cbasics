#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int string_to_int(char * str) {
  int l = strlen(str);
  int sign = 1;
  int sum = 0;
  if(str[0] == '-') {
    sign = -1;
  }
  int i;
  int num = 0;
  for(i = sign > 0 ? 0 : 1; i < l; i++) {
    num = str[i] - '0';
    sum += (int)(num * pow(10, l - i - 1));
  }
  return sum * sign;
}

/*
int main() {
  printf("%d", string_to_int("231231"));
  return 0;
}
*
*/

