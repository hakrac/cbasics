#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *substitute(const char *source, const char *target, const char *text) {
  int l = strlen(text);
  char *result = malloc(l * sizeof(char));
  if(result == NULL) {
    return NULL;
  }
  int m = strlen(source);
  int n = strlen(target);
  
  if(m != n) {
    free(result);
    return NULL;
  }  

  int i, j;

  for(i = 0; i < l; i++) {
    for(j = 0; j < m; j++) {
      if(text[i] == source[j]) {
        result[i] = target[j];
        break;
      }
      if (j == m - 1) {
        free(result);
        return NULL;
      }
    }
  }
  
  result[i] = '\0';


  return result; 
}


/*
int main() {
  char *source = "123456780";
  char *target = "098765431";
  char *text = "149";
  printf("%s", substitute(source, target, text));
  return 0;
}
*/
