#include <stdio.h>
#include <string.h>


void emptystr(char *buf) {
  int i, l = strlen(buf);
  for(i = 0; i < l;i++) {
    buf[i] = -1;
  }
}

int main() {
  int nums[9] = {};
  int onums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  char ibuff[100] = "";
  if(scanf("%[^\n]", ibuff) != EOF) {
    int i = 0;
    int j = 0;
    int k = 0;
    char buff[100] = "";
    do {
      if(ibuff[i] != ' ' && (ibuff[i] < '0' || ibuff[i] > '9')) {
        printf("keine gültige Permutation");
        return 0;
      }
      
      if(ibuff[i] == ' ') {
        nums[k] = buff[j - 1] - '0';
        onums[nums[k] - 1] = 0;
        k += 1;
        i += 1;
        j = 0;
        emptystr(buff);
        continue;
      } else {
        buff[j] = ibuff[i];
        j += 1;
        i += 1; 
      }
      
    } while(ibuff[i] != '\0');
    
    if(j != 0) {
      nums[k] = buff[j - 1] - '0';
      onums[nums[k] - 1] = 0;
    }
 
  }

  // check for permutation
  int j;
  for(j = 0; j < 9; j++) {
    if(onums[j] != 0) {
      printf("keine gültige Permutation");
      return 0;
    }
  }


  printf("1 2 3 4 5 6 7 8 9\n");
  int i;
  for(i = 0;i < 9;i++) {
    printf("%d", nums[i]);
    if(i < 8) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}

