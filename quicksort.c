#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define N 8

void printMyArray(int *a, int len) {
  printf("{ ");
  for(int i = 0; i < len;i++) {
    if(i < len - 1)
      printf("%d, ", a[i]);
    else
      printf("%d", a[i]);
  }
  printf(" }\n");
}

void sort(int *array, int low, int high) {
  if(low >= high || high - low == 0)
    return;
 
  // printMyArray(array, 4);
  int temp;
  // vertauschen von pivot und high
  int pivot = array[high];
  int pivot_index = high; 

  // printf("p: %d\n", pivot); 

  // printMyArray(array, N);

  int j = high - 1;
  for(int i = low; i < j;i++) {
    if( array[i] > pivot ) {
      while (j > i) {
        if ( array[j] < pivot ) {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
          // printMyArray(array, N);
          break;
        }
        j -= 1;
      }
    }
  }
  

  // vertauschen von array[j] und pivot
  if(array[j] > pivot) {
    temp = array[j];
    array[j] = pivot;
    array[pivot_index] = temp;
    pivot_index = j;
    pivot = array[pivot_index];
  }
  // rekursion
  sort(array, low, pivot_index - 1);
  sort(array, pivot_index + 1, high);
}

/*
int main() {
  int a[] = {9, 4, 1, 0, 2, 10, 12, -15};
  sort(a, 0, N - 1);
  // printMyArray(a, N);
  return 0;
}

*/
