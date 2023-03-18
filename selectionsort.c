#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selectionsort(long *nums, int l) {
  for(int i = 0; i < l;i++) {
    int lowi = i;
    for(int j = i; j < l; j++) {
      if(nums[j] < nums[lowi]) {
        lowi = j;
      }
    }
    
    long temp = nums[i];
    nums[i] = nums[lowi];
    nums[lowi] = temp;
  }
}

void emptystr(char *buff) {
  int i, l = strlen(buff);
  for(i = 0; i < l;i++) {
    buff[i] = -1;
  }
  buff[0] = '\0';
}

long *readnums(int n) {
  long *v = malloc(n * sizeof(long));
  for(int i = 0; i < n;i++) {
    scanf("%ld", &v[i]);
  }
  return v;
}

int main() {
  int n = 0;
  scanf("%d", &n);
  long *nums = readnums(n); 
  for(int i = 0; i < n;i++) {
    if(i < n - 1) {
      printf("%ld ", nums[i]);
    } else {
      printf("%ld\n", nums[i]);
    }
  }
  selectionsort(nums, n);
  
  for(int i = 0; i < n;i++) {
    if(i < n - 1) {
      printf("%ld ", nums[i]);
    } else {
      printf("%ld", nums[i]);
    }
  }
  
  return 0;
}

