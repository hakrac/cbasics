#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int isu(char c) {
  return c >= 'A' && c <= 'Z';
}

int isl(char c) {
  return c >= 'a' && c <= 'z';
}

int main() {
  char msg[100];
  scanf("%[^\n]", msg);
  int shift;
  scanf("%d", &shift);
  
  int l = strlen(msg);
  char *res = malloc(l * sizeof(char));
  if(res == NULL) {
    printf("Error");
    return 0;
  }
  for (int i = 0; i < l; i++) {
    if(isu(msg[i])) {
      res[i] = (msg[i] - 'A' + shift) % ('Z' - 'A' + 1) + 'A';  
    } else if(isl(msg[i])) {
      res[i] = (msg[i] - 'a' + shift) % ('z' - 'a' + 1) + 'a';
    } else {
      res[i] = msg[i]; 
    }
  }
  printf("%s", res);
  return 0;
}

