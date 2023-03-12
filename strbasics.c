#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* static_str(char* string) {
  static char str[150];
  strcpy(str, string);
  return &str[0];  
}

char* malloc_str(char string[], int len) {
  char *str = malloc(len * sizeof(char));
  strcpy(str, string);
  return &str[0];
}

