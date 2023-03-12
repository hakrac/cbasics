#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* convert_message(const char *message, char receiver) {
  int l = strlen(message);
  char *msg = malloc(l * sizeof(message)); 
  int k = 0;
  if(receiver == 'L' || receiver == 'M') {
    for(int i = 0; i < l; i++) {
      if ((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z')) {
        if(receiver == 'M') {
          msg[i] = k % 2 ? toupper(message[i]) : tolower(message[i]);    
        }else{
          msg[i] = k % 2 ? tolower(message[i]) : toupper(message[i]);
        }
        k+=1;
      }else{
        msg[i] = message[i];
      }
    }
  }else{
    msg = "Mit dir schreib ich nicht!";
  }
  return &msg[0];
}
/*
int main() {
  char str[] = "Hallo Welt";
  printf("%s", convert_message(str, 'a'));
  return 0;
}
*/

