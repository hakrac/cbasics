#include <stdio.h>
#include <string.h>

int lex_sorted( const char* array[] ) {
  int i = 0;
  if(array[0] == NULL || array[1] == NULL) {
    return 1;
  }
  do {
    if(strcmp(array[i], array[i + 1]) > 0) {
      return 0;
    }
    i += 1;
  } while(array[i + 1] != NULL);
  return 1;
}

/*
int main() {
  const char* s[5];
  s[0] = "a";
  s[1] = "b";
  s[2] = "cz";
  s[3] = "cd"; 
  s[1] = NULL;
  printf("%d", lex_sorted(s));
  return 0;  
}
*/
