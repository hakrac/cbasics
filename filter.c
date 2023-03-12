#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_filter(const char* text) {
  int l = strlen(text);
  char *str = malloc(l * sizeof(char));
  int k = 0;
  for(int i = 0; i < l; i++) {
    if( (text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
      str[i - k] = text[i];
    } else {
      k += 1;
    }
  }
  
  return &str[0];
}

/*

int main() {
  printf("%s", string_filter(".....halllo.....welt..."));
  return 0;
}
*/
