#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int max(int **f, int** p);
int min(int **f, int** p);

void printField(int **f) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(f[i][j] == 1)
        printf("x ");
      else if(f[i][j] == -1)
        printf("o ");
      else
        printf("_ ");
    }
    printf("\n");
  }
}

void readMove(int **f) {
  int x = -1, y = -1;
  while(1) {
    printf("(x:y)> ");
    scanf("%d:%d", &x, &y);
    if( x >= 1 && x <= 3 && y >= 1 && y <= 3 && f[y - 1][x - 1] == 0 ) {
      f[y - 1][x - 1] = 1;
      break;
    }
  }
}

int isfull(int **f) {
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(f[i][j] == 0)
        return 0;
  return 1;
}


int check(int **f) {
  // if(isfull(f))
  //   return 0;

  for(int k = 0; k < 2; k++) {
    int i, j;
    for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++) {
        if(f[i][j] != (int)pow(-1, k))
          break;
      }
      if(j == 3)
        return 1;
      for(j = 0; j < 3; j++) {
        if(f[j][i] != (int)pow(-1, k))
          break;
      }
      if(j == 3)
        return (int)pow(-1, k);
    }
  }
  for(int k = 0; k < 2; k++) {
    int i, j;
    for(i = 0; i < 3; i++) {
      if(f[2 - i][i] != (int)pow(-1, k))
        break;
    }
    if(i == 3)
      return (int)pow(-1, k);
    
    for(i = 0; i < 3; i++) {
      if(f[i][i] != (int)pow(-1, k))
        break;
    }
    if(i == 3)
      return (int)pow(-1, k);
  }   
  return 0;
}

// maximiert spieler gewinn
int max(int **f, int **p) {
  int maximum = -10;
  if(isfull(f)) {
    *p = NULL;
    return 0;
  }
  
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(f[i][j] == 0) {
        f[i][j] = 1;
     
        if(check(f) == 1) {
          *p = &f[i][j];
          f[i][j] = 0;
          return 1;
        }

        int **pos = (int **)malloc(sizeof(int *));
        int rating = min(f, pos); 
        free(pos);
        if(maximum < rating) {
          *p = &f[i][j];
          maximum = rating;
        }
        
        f[i][j] = 0; 
      }
    }
  }
  return maximum;
}

int min(int **f, int** p) {
  int minimum = 10;
  if(isfull(f)) {
    *p = NULL;
    return 0;
  }

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(f[i][j] == 0) {
        f[i][j] = -1;
        if(check(f) == -1) {
          *p = &f[i][j];
          f[i][j] = 0;
          return -1;  
        }
       
        int **pos = (int **)malloc(sizeof(int *));
        int rating = max(f, pos);
        free(pos);
        if(minimum > rating) {
          *p = &f[i][j];
          minimum = rating;
        }
        
        f[i][j] = 0; 
      }
    }
  } 
   
  return minimum;
}

int main () {
  int**f = (int **)malloc(3 * sizeof(int *));
  for(int i = 0; i < 3; i++) {
    f[i] = (int *)malloc(3 * sizeof(int));
    for(int j = 0; j < 3; j++) {
      f[i][j] = 0;
    }
  }

  while(check(f) == 0 && !isfull(f)) {
    readMove(f);
    printField(f);
    if(isfull(f) && check(f) == 0) {
      printf("=================\n"
             "= Unentschieden =\n"
             "=================\n");
      break; 
    }
    if(check(f) == 1) {
       printf("=================\n"
              "= * Gewonnnen * =\n"
              "=================\n");
      break;  
    }
    printf("\n");
    int **p = (int **)malloc(sizeof(int *));
    int res = min(f, p);
    **p = -1;
    
    
    printField(f);
    if(check(f) == -1) {
       printf("=================\n"
              "=   Verloren    =\n"
              "=================\n");
      break;  
    }
    printf("\n");
  }
 
  for(int i = 0; i < 3; i++) {
    free(f[i]);
  }
  free(f);
 
  return 0;
}
