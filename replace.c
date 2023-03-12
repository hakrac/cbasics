#include <stdio.h>
#include <string.h>

int exchange(char* s, char a, char b) {
  if(s == NULL) {
    return 0;
  }
  int l = strlen(s);
  int c = 0;
  for(int i = 0; i < l; i++) {
    if(s[i] == a) {
      s[i] = b;
      c += 1;
    }
  }
  return c;
}

/*
int main() {
  char s[] = "anna";
  int n = exchange(s, 'a', 'o');
  printf("%s", s);
  return 0;
}
*/
