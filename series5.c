#include <stdio.h>



long iteP(unsigned int k) {
  long p[3] = {3, 0, 2};
  
  if(k <= 2) {
    return p[k];
  }
 
  int i = 2; 
  while(i < k) {
    long temp = p[0];
    p[0] = p[1];
    p[1] = p[2]; 
    p[2] = p[0] + temp; 
    i += 1;
  }
  
  return p[2];
}

/*
int main() {
  printf("%ld", iteP(8)); 
  return 0;
}
*/
