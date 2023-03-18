#include <stdio.h>

typedef struct {
  long low;   // lower bound
  long up;    // upper bound
} interval_t;


int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int is_empty_intersection(const interval_t *a, const interval_t *b) {
  if(a == NULL || b == NULL) {
    return 1;    
  }

  if(a->low > a->up || b->low > b->up) {
    return 1; 
  }
  
  int low = max(a->low, b->low);
  int up = min(a->up, b->up);

  if(low > up) {
    return 1;
  }
  

  return 0;
}
/*
int main() {
  interval_t a;
  interval_t b;
  b.low = 0;
  b.up = 1;
  a.up = 3;
  a.low = 2;
  printf("%d ", is_empty_intersection(&a, &b));
  return 0;
}
*/
