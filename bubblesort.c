#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define N 10


int strtoint(char str[]) {
  int l = strlen(str);
  int sign = 1;
  int sum = 0;
  if(str[0] == '-') {
    sign = -1;
  }
  int i;
  int num = 0;
  for(i = sign > 0 ? 0 : 1; i < l; i++) {
    num = str[i] - '0';
    sum += (int)(num * pow(10, l - i - 1));
  }
  return sum * sign;
}

void sort(int *nums, int len) {
  int i, j;
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      if ( nums[i] > nums[j] ) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }
}


int main(int argc, char *argv[]) {
  /*
  int k;
  int num; 
  int nums[argc - 1];
  for (k = 1; k < argc; k++) { 
    nums[k - 1] = strtoint(argv[k]);
  }
 
  printf("\n");

  int l = sizeof(nums) / sizeof(nums[0]);
  // printf("%d", l);
  int i;
  int j;
  for (i = 0; i < l; i++) {
    for (j = 0; j < l; j++) {
      if (nums[i] > nums[j] && j > i) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }
  
  printf("\n");
  int q;
  for(q = 0; q < l; q++) {
    printf("%d", nums[q]);
    if(l - q  > 1) {
      printf(" ");
    }
  }
  */
  
  int b[] = {1,3,4,5,2,0};
  sort(b, 6);
  printf("%d %d %d %d %d %d", b[0], b[1], b[2], b[3], b[4], b[5]);

  return 0;
}

