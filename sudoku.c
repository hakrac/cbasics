#include <stdio.h>
#include <string.h>
#include <ctype.h>


int sudokucheck(const int** s) {
  // check if numbers in rows / columns are unique
  for(int i = 0; i < 9;i++) {
    long c = 0;
    long r = 0;
    for(int j = 0; j < 9;j++) {
      r = r ^ (1 << (s[i][j] - 1));
      c = c ^ (1 << (s[j][i] - 1));
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
          b = b ^ (1 << (s[3 * i + k][3 * j + m] - 1));
        }
      }
      
      if(b != 511) {
        return 0;
      }
    }
  }
  
  return 1;
}

/*

int main() {
  int s[9 * 9] = {
     3, 1, 6, 5, 7, 8, 4, 9, 2,
     5, 2, 9, 1, 3, 4, 7, 6, 8,
     4, 8, 7, 6, 2, 9, 5, 3, 1,
     2, 6, 3, 4, 1, 5, 9, 8, 7,
     9, 7, 4, 8, 6, 3, 1, 2, 5,
     8, 5, 1, 7, 9, 2, 6, 4, 3,
     1, 3, 8, 9, 4, 7, 2, 5, 6,
     6, 9, 2, 3, 5, 1, 8, 7, 4,
     7, 4, 5, 2, 8, 6, 3, 1, 9
  };
  int *sudoku[9];
  for(int i = 0; i < 81; i += 9) {
    sudoku[i / 9] = &s[i];
  }
  
  const int** su = (const int**)sudoku; 
  printf("%d", sudokucheck(su));
  return 0;
}


*/
