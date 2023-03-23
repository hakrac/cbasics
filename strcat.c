#include <stdio.h>
#include <string.h>

int main() {
  char str1[15];
  char c;
  int i = 0;
  while((c = getchar()) != '\n') {
    if (i >= 14) {
      printf("Fehler");
      return 0;
    }
    str1[i] = c;
    i += 1;
  }
  str1[i] = '\0';


  char str2[15];
  i = 0;
  while((c = getchar()) != '\n') {
    if (i >= 14) {
      printf("Fehler");
      return 0;
    }
    str2[i] = c;
    i += 1;
  }
  str2[i] = '\0';

 
  char new[30];
  int j;
  for(i = 0; i < 15;i++) {
    if(str2[i] != '\0')
      new[i] = str2[i];
    else
      break;
  }
  for(j = i; j < 30;j++) {
    if(str1[j - i] == '\0')
      break;
    else
      new[j] = str1[j - i];
  }
  new[j] = '\0';
  printf("%s", new);
  return 0;
}
