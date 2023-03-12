#include <stdio.h>
#include <ctype.h>


int main() {
  int num = 0;
  char word[20] = "";
  scanf("%s %d", word, &num);
 
 
  int i = 0;
  int t = num % 2 == 0? num / 2 : (num - 1) / 2;
  for(i = 0;i < t;i++) {
    if(tolower(word[i]) != tolower(word[num - i - 1])) {
      printf("kein palindrom");
      return 0;
    }
  }
  printf("palindrom");
  return 0;
}
