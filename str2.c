#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *strinv(const char *s) {
  if (s == NULL) {
    return NULL;  
  }
  int l = 0;
  while(s[l] != '\0')
    l++;
  char *t = malloc((size_t)l);
  for(int i = 0; i < l; i++) {
    t[i] = s[l - i - 1];
  }
  t[l] = '\0';
  return t;
}

char *strconcat(const char *s, const char *t) {
  int l1 = 0, l2 = 0;
  if(s == NULL && t == NULL) {
    return NULL;
  }
  if(s != NULL) {
    while(s[l1] != '\0')
      l1++;
  }
  if(t != NULL) {
    while(t[l2] != '\0')
      l2++;
  }

  int l;
  if (l1 != 0 && l2 != 0)
    l = l1 + l2 ;  
  else if(l1 == 0)
    l = l2;
  else if(l2 == 0)
    l = l1;

  char *b = malloc((size_t)l);
  for(int i = 0; i < l1; i++) {
    b[i] = s[i]; 
  }
  
  for(int i = 0; i < l2; i++) {
    b[l1 ? i + l1 : i] = t[i];
  }
 
  b[l] = '\0'; 

  return b;
}
/*
int main() {
  char a[] = "Hello World!";
  printf("%s \n", strinv((const char *)a));
  char b[] = "....";
  const char *t = NULL;
  printf("%s", strconcat((const char *)b, (const char *)a));
  return 0;
}*/
