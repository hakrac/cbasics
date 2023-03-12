#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void emptystr(char *buf) {
  int i;
  int l = strlen(buf);
  for(i = 0; i < l; i++) {
    buf[i] = -1;
  }
}

void readdouble(double *numbers, int n) {
  char str[100] = "";
  char *p;
  int l;
  if(scanf("%[^\n]", str) != EOF) {
    printf("\nstr %s", str);
    char buffer[100] = "";
    int i = 0; // Input array index
    int j = 0; // Number array index
    int k = 0; // Buffer index
    do {
      if(str[i] == ' ') {
        if (k != 0) {
          numbers[j++] = strtod(buffer, &p);
        }
        i += 1;
        k = 0;
        emptystr(buffer);
        if(n + 1 == j)
          break;
        continue;
      }
      // handle sign
      if(str[i] == '-') {
        buffer[k++] = str[i++];
        buffer[k++] = str[i++];       
      } else {
        buffer[k++] = str[i++];
      }
    } while (str[i] != '\0');
 
    if (k != 0) {
      numbers[j++] = strtod(buffer, &p);
    }
  }
}

double poly(double *coef, int n, double x) {
  double sum = 0;
  for(int i = n; i >= 0; i--) {
    sum += coef[i] * pow(x, n - i);
  }
  return sum;
}

int main() {
  int deg = -1; 
  scanf("%d", &deg);
  printf("\n%d", deg);
  if(deg < 0) {
    return 0;
  }
  double coef[deg + 1];
  char *str;
  scanf("%[^\n]", str);
  printf("%s\n", str);
  readdouble(coef, deg + 1);

  printf("coefs: %lf %lf\n", coef[0], coef[1]);
  printf("----------------\n"); 
  double x = 0;
  int res;
  do {
    res = scanf("%lf", &x);
    if(res == EOF) {
      break;
    }
    printf("%lf\n", poly(coef, deg, x));
  } while(res != EOF);

  return 0;
}


