#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int strclean(char *t) {
  if(t == NULL) {
    return -1;
  }
  int i = 0;
  int r = 0;
  while (t[i + r]) {
    if(iscntrl(t[i + r]) || isspace(t[i + r])) {
      r += 1;
    } else {
      t[i] = t[i + r];
      i += 1;
    }
  }
  t[i] = '\0';
  return r;
}
/*
int main() {
  char t[50] = "Ha   \t    li\t llo\nwelt\tte\t";
  int d = strclean(t);
  printf("%d %s", d, t);
  return 0;
}
*/
