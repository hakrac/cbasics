#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct {
  char* src; // Ausgangswort
  char* dest; // Zielwort (Übersetzung)
} translation_t;


char* simpleTranslate(char* text, translation_t* dictionary, size_t dict_size) {
  const char s[2] = " ";
  char *str = malloc(500);
  char *nstr = malloc(500);
  if(str == NULL || nstr == NULL) {
    return NULL;
  }
  strcpy(str, text); 
  char* token;
  token = strtok(str, s);
  
  while(token != NULL) {
    for(int i = 0; i < dict_size; i++) {  
      if(token == NULL) {
        break;
      }
      
  
      // printf("; dict[%d]: %s -> %s; ", i, dictionary[i].src, dictionary[i].dest);
      if(strcmp(token, dictionary[i].src) == 0) {
        strcat(nstr, dictionary[i].dest);
        // printf("token: %s; ", token);
        token = strtok(NULL, s);
        if(token != NULL)
          strcat(nstr, s);
        i = 0;
        continue;
      }
    }
  
    if(token != NULL) {
      strcat(nstr, token);
      token = strtok(NULL, s);
      if(token != NULL)
        strcat(nstr, s);
    } else {
      token = strtok(NULL, s);
    }
  }
 
  free(str);
  return nstr;
}

/*
int main() {
  translation_t dictionary[7] = {{"Ich", "I"}, {"mag", "love"}, {"Züge", "trains"}, {"Juhu", "Yay"}, {"Nein", "no"}, {"es", "it"}, {"funktioniert", "works"}};
  char* text_trans = simpleTranslate("Ich bin eine kluge Bohne", dictionary, 7);
 
  printf("\"%s\"\n", text_trans);
  return 0;
}
*/
