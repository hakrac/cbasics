#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void emptystr(char *buf) {
  int i;
  int l = strlen(buf);
  for(i = 0; i < l; i++) {
    buf[i] = -1;
  }
}


int main() {
  float numbers[100] = {};
  char str[100] = "";
  int l;


  if(scanf("%[^\n]", str) != EOF) {
    char buffer[100] = "";
    int i = 0; // Input array index
    int j = 0; // Number array index
    int k = 0; // Buffer index
    do {
      if(str[i] == ' ') {
        if (k != 0) {
          numbers[j++] = atof(buffer);
        }
        i += 1;
        k = 0;
        emptystr(buffer);
        continue;
      }
      // handle sign
      if(str[i] == '-') {
        buffer[k++] = str[i++];
        buffer[k++] = str[i++];       
      } else {
        buffer[k++] = str[i++];
      }
    } while (str[i] != '\0');
 
    if (k != 0) {
      numbers[j++] = atof(buffer);
    }
   
    l = j;
    int n;
    float sum = 0;
    for(n = 0; n < l;n++) {
      sum += numbers[n];
    }
    printf("%f", sum / l);
  }   

  return 0;
}
