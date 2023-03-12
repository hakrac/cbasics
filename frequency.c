#include <stdio.h>
#include <string.h>
#include <ctype.h>

int frequency(const char string[], char ch) {
  if(string == NULL) {
    return 0;
  }
  int l = strlen(string);  
  int c = 0;
  for(int i = 0; i < l; i++) {
    if(tolower(string[i]) == tolower(ch)) {
      c += 1;  
    }
  }
  return c;
}
/*
int main() {
  printf("%d", frequency("Test!", 't'));
  return 0;
}
*/
