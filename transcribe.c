#include <stdio.h>
#include <string.h>

int main() {
  char *numb[] = {
    "ein",
    "zwei",
    "drei",
    "vier",
    "fünf",
    "sechs",
    "sieben",
    "acht",
    "neun"
  };
  char *tumb[] = {
    "zehn",
    "zwanzig",
    "dreißig",
    "vierzig",
    "fünfzig",
    "sechzig",
    "siebzig",
    "achtzig",
    "neunzig"
  };
  
  int n = 0;
  char result[100]; 
  scanf("%d", &n);
  if(n == 0) {
    printf("null");
  } else if (n < 0 || n > 99) {
    printf("Nicht lesbar.");
  } else {
    int a = n % 10;
    int b = n / 10;
    switch (b) {
      case 0:
        if(a == 1) {
          printf("eins");
        } else {
          printf("%s", numb[a - 1]);
        }
        break;
      case 1:
        if(a == 1) {
          printf("elf");
        } else if(a == 2) {
          printf("zwölf");
        } else if (a == 6) {
          printf("sechzehn");
        } else if (a == 7) {
          printf("siebzehn"); 
        } else {
          strcpy(result, numb[a - 1]);
          strcat(result, tumb[0]);
          printf("%s", result);
        } 
        break;
      default:
        if(a == 0) {
          printf("%s", tumb[b - 1]);
          break;
        }
        strcpy(result, numb[a - 1]);
        strcat(result, "und");
        strcat(result, tumb[b - 1]);
        printf("%s", result);
        break;
    }
  }
  return 0;
}


