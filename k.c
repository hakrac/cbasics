#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int strclean( char *t ) {
  int l = 0;
  while( t[l++] != '\0')
    ;
  char *n = malloc((size_t)l);
  int j = 0;
  int i;
  for(i = 0; i < l; i++) {
    if(!iscntrl(t[i]) && !isspace(t[i])) {
      n[j++] = t[i];
    }
  }
  n[j] = '\0';
  strcpy(t, n);
  return i - j; 
}

int main() {
  char t[50] = "Ha   \t li  00000000000";
  int d = strclean(t);
  printf("%d %s", d, t);
  return 0; 
}
