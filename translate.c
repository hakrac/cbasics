#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct {
  char* src; // Ausgangswort
  char* dest; // Zielwort (Übersetzung)
} translation_t;


char* simpleTranslate(char* text, translation_t* dictionary, size_t dict_size) {
  printf("text: %s\n", text);
  const char s[2] = " ";
  char *str = malloc(500);
  char *nstr = malloc(500);
  strcpy(str, text); 
  char* token;
  token = strtok(str, s);
  while(token != NULL) {
    printf("token: %s; ", token);
    for(int i = 0; i < dict_size; i++) {
      printf("; dict[%d]: %s -> %s; ", i, dictionary[i].src, dictionary[i].dest);
      if(strcmp(token, dictionary[i].src) == 0) {
        strcat(nstr, dictionary[i].dest);
        strcat(nstr, s);
        token = strtok(NULL, s);
        continue;
      } 
    }
  
    if(token != NULL) {
      strcat(nstr, token);
      strcat(nstr, s);
    }
    token = strtok(NULL, s);
  }
 
  free(str);
  printf("nstr: %s\n", nstr);
  return nstr;
}
/*
int main() {
  translation_t dictionary[0] = {}; //{{"Ich", "I"}, {"mag", "love"}, {"Züge", "trains"}};
  char* text_trans = simpleTranslate("Ich mag Züge", dictionary, 0);
 
  printf("%s\n", text_trans);
  return 0;
}
*/
