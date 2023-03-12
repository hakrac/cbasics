#include <stdio.h>


int main () {
  char buffer[100] = "";
  if(scanf("%s", buffer) == 1) {
    long d = 0;
    int i = 0;
    do {
      int c = buffer[i] - '0';
      if(i >= 64 || c > 2) {
        printf("Error");
        return 1;
      }
      d = (d << 1) | c;
      i++;
    } while(buffer[i] != '\0');
    printf("%ld", d); 
    /*
    int i;
    for(i = 99; i >= 0; i--) {
      printf("%d \n", buffer[i]);
    }
    */
  }
  return 0;
}
