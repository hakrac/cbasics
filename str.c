#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int strendX(const char *s, const char *t) {
  // start from end and compare char-wise
  if(s == NULL || t == NULL)
    return 0;
  int ls = strlen(s);
  int lt = strlen(t);
  for(int i = 0; i < lt; i++) {
    if(s[ls - i - 1] != t[lt - i - 1]) {
      // printf("%c != %c", s[ls - i - 1], t[lt - i - 1]);
      return 0;
    }
  }
  return 1;
}

char *strchrX(const char *s, char c) {
  if(s == NULL)
    return 0;
  char *p = NULL;
  int ls = strlen(s);
  for(int i = 0; i < ls; i++) {
    if(s[i] == c) {
      p = (char *)&s[i];
    }
  }
  return p;
}

char *strstrX(const char *s, const char *t) {
  if (s == NULL || t == NULL)
    return NULL;
  int ls = strlen(s);
  int lt = strlen(t);
  for(int i = 0; i <= ls - lt; i++) {
    for(int j = 0; j < lt; j++) {
      if(t[j] != s[i + j]) {
        break;
      }
      if(j == lt - 1) {
        return (char *)&s[i];
      } 
    } 
  }
  return NULL;
}

/*
int main() {
  char str[] = "Hello World!";
  char t[] = ",";
  char *p = strstrX(str, t);
  if(p == NULL) {
    printf("NOT FOUND");
    return 0;
  }
  printf("%c\n", *p);
  return 0;
}
*/
