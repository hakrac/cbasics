#include <stdio.h>


int main() {
  int n = 0, k = 0;
  while (n <= 0 || k <= 0)
    scanf("%d %d", &n, &k);

  int a[n];
  int p[n];  

  for(int i = 0; i < n; i++)
    a[i] = i + 1;

  int s = 0, f = 0;
  for(int i = 0; i < n; i++) {
    s = 0;
    while(s < k) {
      if(a[f % n]) {
        s++;
      }
      f++;
    }
     
    p[(f - 1) % n] = i + 1;
    a[(f - 1) % n] = 0;
    
  }

  for(int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
  return 0;
}


