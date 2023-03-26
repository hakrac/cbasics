#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>


#define DEBUG 0

typedef struct {  
  char name[32];
  int  number;
  char checksum;
} data_t;

data_t *new_data(char *name, int number) {
  data_t *t = malloc(sizeof(data_t));
  t->number = number;
  strcpy(t->name, name);
  t->checksum = 0;
  int l = strlen(name);
  for(int i = 0; i < l;i++) {
    if(t->checksum < CHAR_MAX - name[i])
      t->checksum += name[i];
    else {
      int k = (int)t->checksum + (int)name[i];
      t->checksum = (char)(k % CHAR_MAX);
    }
    #if DEBUG
    printf("%c: %d %d\n", name[i], name[i], t->checksum);
    #endif
  }
  
  if(t->checksum < CHAR_MAX - number)
    t->checksum += number;
  else {
    int k = (int)t->checksum + (int)number;
    t->checksum = (char)(k % CHAR_MAX);
  }
  
  return t;
}

int main() {
  #if DEBUG
  printf("%d\n", CHAR_MAX);
  #endif
  data_t *d = new_data("Saturn", 5);
  printf("%s\n%d\n%d", d->name, d->number, d->checksum);
  return 0;
}
