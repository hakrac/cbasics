#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



char *reverse(char *str) {
  int l = strlen(str);
  char *res = malloc(l * sizeof(char));
  for(int i = 0; i < l; i++) {
    res[l - i - 1] = str[i];
  }
  res[l] = '\0';
  return res;
}


int main() {
  int num, base;
  scanf("%d %d", &num, &base);
  if(base <= 1) {
    return 0;
  }
  
  char *n = malloc(1000 * sizeof(char));
  int r, i = 0;
  do {
    r = num % base;
    num -= r;
    num /= base;
    if(r >= 10 && r <= 36) {
      n[i++] = r - 10 + 'a';
    } else {
      n[i++] = r + '0';
    }
  } while(num);
  n[i] = '\0';
  printf("%s", reverse(n));
  free(n);
  return 0;
}
