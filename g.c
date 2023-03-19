#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define N 60

void clear() {
  printf("\e[1;1H\e[2J");
}

int strcon(char *w, char c) {
  int l = strlen(w);
  for(int i = 0; i < l; i++) {
    if(w[i] == c) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int game_loop = 1;
  while (game_loop) {
    int MAX_VERSUCHE = 0;
    char w[N];
    printf("# Versuche > ");
    scanf("%d", &MAX_VERSUCHE);
    char c;
    while ( (c = getchar()) != '\n')
      ;
    int i = 0;
    printf("WORT > ");
    while ( (c = getchar()) != '\n')
      w[i++] = c;
    w[i] = '\0';
    printf("V: %d, W: %s \n", MAX_VERSUCHE, w); 
    
    int l = strlen(w);

    char *cs = (char *)malloc(64);
    cs[0] = '\0';

    clear();
    int v = 0;
    i = 0;
    c = '?';
    do {
      if(c == '\n')
        continue;
      if(isalnum(c)) {
        cs[i++] = c;
        cs[i] = '\0'; 
        if(!strcon(w, c)) {
          v += 1;
        }
      }
      
  
      
      clear(); 
      if(v >= MAX_VERSUCHE) {
        printf("===================\n");
        printf("=    GAME OVER    =\n");
        printf("===================\n\n\n");
        printf("Neue Runde (y/n): ");
        char ans;
        while( (c = getchar()) != '\n')
          ;
        scanf("%c", &ans);
        if(ans == 'y' || ans == 'Y') {
          clear();
          break;
        }
        return 0;
      } 
  

      int missing = 0;
      for(int j = 0; j < l; j++) {
        if(w[j] != ' ' && !strcon(cs, w[j])) {
          missing++;
          printf("_");
        } else {
          printf("%c", w[j]);
        }
      }
      if(missing == 0) {
        clear();
        printf("*******************\n");
        printf("**   GEWONNNEN   **\n");
        printf("*******************\n\n\n");
        printf("Neue Runde (y/n): ");
        char ans;
        while( (c = getchar()) != '\n')
          ;
        scanf("%c", &ans);
        if(ans == 'y' || ans == 'Y') {
          clear();
          break;
        }
        return 0;
      }
      printf("\nVerbleibende Versuche: %d \n", MAX_VERSUCHE - v);  
      printf("%s", cs);
    } while( (c = getchar()) != EOF );
    if(c == EOF) {
      return 0;
    }
  }
  return 0;  
}
