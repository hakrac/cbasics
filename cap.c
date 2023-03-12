#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
  char msg[160];
  scanf("%[^\n]", msg);
  int l = strlen(msg);
  char *toni = malloc(l * sizeof(char));
  char *tomke = malloc(l * sizeof(char));
  
  int k = 0, j = 0;
  for(int i = 0; i < l; i++) {
    if(msg[i] >= 'A' && msg[i] <= 'Z') {
      toni[k++] = msg[i]; 
    } else if(msg[i] >= 'a' && msg[i] <= 'z') {
      tomke[j++] = msg[i];
    }
  }
  
  printf("Nachricht an Toni: %s\n", toni);
  printf("Nachricht an Tomke: %s", tomke);
  
  return 0;
}
