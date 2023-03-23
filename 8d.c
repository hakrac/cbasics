#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


#define SHOW_OCCUPIED_POS 1

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void printFeld(int **f, int show_m);


int steps = 0;

int min(int a, int b) {
  return a >= b ? b : a;
}

void pmove(int **f) {
  
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(f[i][j] == 1) {
        for(int k = 0; k < 8; k++) {  
          f[i][k] = f[i][k] == 1 ? 1 : -1; 
        }

        for(int k = 0; k < 8; k++) {
          f[k][j] = f[k][j] == 1 ? 1 : -1;    
        }
        int t = min(i, j);
        int y = i - t, x = j - t;
        
        for(int k = 0; (x + k < 8) && (y + k < 8); k++) {
          f[y + k][x + k] = f[y + k][x + k] == 1 ? 1 : -1;
        }
       
        for(int k = 0; (i - k) >= 0 && (k + j) < 8; k++) {
          f[i - k][j + k] = f[i - k][j + k] == 1 ? 1 : -1;
        }
        
        for(int k = 0; (j - k) >= 0 && (k + i) < 8; k++) {
          f[i + k][j - k] = f[k + i][j - k] == 1 ? 1 : -1;
        }
        
      }
    }
  }
}


void cmove(int **f) {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      f[i][j] = f[i][j] == 1 ? 1 : 0;
    }
  }
}

void clear() {
  printf("\e[1;1H\e[2J"); 
}


int dame(int **f) {
  pmove(f);
  clear();
  printFeld(f, 1);
  usleep(1000);
  int d = 0;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(f[i][j] == 1) {
        d += 1;
      }
      if(f[i][j] == 0) {
        f[i][j] = 1;
        steps += 1;
        if(dame(f))
          return 1;
        f[i][j] = 0;
        cmove(f);
        pmove(f);
      }
    }
  }
  if(d == 8) {
    return 1;
  }
  return 0; 
}


void printFeld(int **f, int show_m) {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(f[i][j] == -1)
        if(show_m)
          printf("%s%d ", KRED, f[i][j]);
        else
          printf(" %s0 ", KRED);
      else
        if(f[i][j] == 1)
          printf(" %s%d ", KBLU, f[i][j]);
        else if(f[i][j] == 0)
          printf(" %s0 ", KGRN);
    }
    printf("\n");
  }
}


void flushFeld(int **f) {
  for(int i = 0; i < 8; i++) { 
    for(int j = 0; j < 8; j++) {
      f[i][j] = 0;
    }
  }
}

int main() {
  int **feld = (int **)malloc(8 * (sizeof(int *)));
  for(int i = 0; i < 8; i++) {
    feld[i] = (int *)malloc(8 * sizeof(int));
    for(int j = 0; j < 8; j++) {
      feld[i][j] = 0;
    }
  }

  for(int k = 0; k < 8; k++) {
    flushFeld(feld);
    feld[0][k] = 1;
    dame(feld);
    clear();
    printf("==============\n"
           "= #%d Lösung =\n"
           "==============\n", k + 1);
    printFeld(feld , 1);
    printf("SCHRITTE: %d\n", steps);
    steps = 0;
    sleep(5);
  }
  return 0;
}
