#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int issolved(int x) {
    return (x != 0) && (x & (x - 1)) == 0;
}

void deconvertsudoku(int** s) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      for(int k = 0; k < 9;k++) {
        if( (s[i][j] & (1 << k)) >> k == 1) {
          s[i][j] = k + 1;
        }
      }
    }
  }
}

void convertsudoku(int** s) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(s[i][j] != 0) 
        s[i][j] = (1 << (s[i][j] - 1));
      else
        s[i][j] = 0;
    }
  }
}


void printFancySudoku(int ** s) {
  for(int i = 0; i < 9; i++) {
    if(i % 3 == 0)
      printf("+-------+-------+-------+\n");
    for(int j = 0; j < 9; j++) {
      if(j % 3 == 0)
        printf("| ");
      printf("%d ", s[i][j]);
    }
    printf("|\n");
  }
  printf("+-------+-------+-------+\n");
}



void printSudoku(int ** s) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(j == 8)
        printf("%d", s[i][j]);
      else
        printf("%d ", s[i][j]);
    }
    printf("\n");
  }
}



int **readSudoku() {
  int** s = (int**)malloc(9 * sizeof(int*));
  for (int i = 0; i < 9; i++) {
    s[i] = (int*)malloc(9 * sizeof(int));
  }
   
  for(int i = 0; i < 9;i++) {
    for(int j = 0; j < 9; j++) {
      int c = -1;
      while (c < 0 || c > 9) {
        // scanf("%d %d %d %d %d %d %d %d %d", &);
        c = getchar() - '0';
      }
      s[i][j] = c;
    } 
  }

  
  return s;
}

void deleteSudoku(int **s) {
  for(int i = 0; i < 9; i++) {
    free(s[i]);
  }

  free(s);
}

int sudokucheck(int** s) {
  // check if numbers in rows / columns are unique
     

  for(int i = 0; i < 9;i++) {
    int c = 0;
    int r = 0;
    for(int j = 0; j < 9;j++) {
      r = r ^ s[i][j];
      c = c ^ s[j][i];
    }
    if(r != 511 || c != 511) {
      return 0;
    }
  }
 

  // check blocks
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      long b = 0;
      for(int k = 0; k < 3; k++) {
        for(int m = 0; m < 3; m++) {
          b = b ^ s[3 * i + k][3 * j + m];
        }
      }
      
      if(b != 511) {
        return 0;
      }
    }
  }
  
  return 1;
}

int solve(int **s) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if (!issolved(s[i][j])) {
        // rows
        int r = 0;
        for(int k = 0; k < 9; k++) {
          r = r ^ s[i][j];
        }

        // columns
        int c = 0;
        for(int k = 9; k < 9; k++) {
          c = c ^ s[i][j];
        }

        // blocks
        int b1 = i / 3;
        int b2 = j / 3;
        int b = 0;
        for(int k = 0; k < 3; k++) {
          for(int m = 0; m < 3; m++) {
            b = b ^ s[b1 * 3 + k][b2 * 3 + m];
          }
        }
       
        int n = 511 ^ b ^ r ^ c; // alle mögliche lsgen.
        if(n == 0) {
          return 0;
        } else if(issolved(s[i][j])) {
          continue;
        } else { 
          // s[i][j] = n;
          // probieren aller lsg
          for(int t = 0; t < 9; t++) {
            // t-te bit von n == 1 
            if((n & ( 1 << t )) >> t == 1) {
              s[i][j] = 1 << t;
              // printf("%d %d:\n", i, j);
              // deconvertsudoku(s);
              // printFancySudoku(s);
              // convertsudoku(s);
              if(solve(s))
                return 1;
            }
          }
          s[i][j] = 0;
          return 0;
        }
      }
    }
  }
  // ist geloest
  return sudokucheck(s); 
}


int main() {
  /*
  int s[9 * 9] = {
     0, 1, 6, 5, 7, 8, 4, 9, 2,
     5, 2, 9, 1, 3, 4, 7, 6, 8,
     4, 8, 7, 6, 2, 9, 5, 3, 1,
     2, 6, 3, 4, 1, 5, 9, 8, 7,
     9, 7, 4, 8, 6, 3, 1, 2, 5,
     8, 5, 1, 7, 9, 2, 6, 4, 3,
     1, 3, 8, 9, 4, 7, 0, 0, 0,
     6, 9, 2, 3, 5, 1, 0, 0, 0,
     7, 4, 5, 2, 8, 6, 0, 0, 0
  };
  int *sudoku[9];
  for(int i = 0; i < 81; i += 9) {
    sudoku[i / 9] = &s[i];
  }

  
  int** su = (int**)sudoku;
  */
  int ** su = readSudoku();
  // printSudoku(su);
  // convertsudoku(su);
  // deconvertsudoku(su);
  // printSudoku(su);

 
  // printf("%d", su[0][0]);


  convertsudoku(su); 
  int l = solve(su);
  // printf("solved: %d\n", solve(su));
  // printf("%d\n", sudokucheck(su));
  if(l) {
    deconvertsudoku(su);
    printSudoku(su);
  } else {
    printf("keine Lösung gefunden\n");
  }
  deleteSudoku(su);
  return 0;
}

