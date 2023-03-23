#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include "euklid.h"

unsigned long gcd(unsigned long a, unsigned long b) {
  if (b == 0) {
    return a;
  }
  if (a < b) {
    return gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

typedef struct {
  int zaehler;
  int nenner;
} bruch_t;

int abs(int x) {
  return x > 0 ? x : -x;
}

void bruchEingabe(bruch_t* bruch) {
  bruch->zaehler = 0;
  bruch->nenner = 0;
  while (bruch->nenner == 0) {
    scanf("%d/%d", &bruch->zaehler, &bruch->nenner);
  }
  if(bruch->nenner < 0) {
    bruch->zaehler *= -1;
    bruch->nenner *= -1;
  }
}

void bruchAusgabe(bruch_t* bruch) {
  printf("%d/%d", bruch->zaehler, bruch->nenner);
}

void bruchKuerzen(bruch_t* bruch) {
   if(bruch->nenner < 0) {
    bruch->zaehler *= -1;
    bruch->nenner *= -1;
  }
  
  int sign = bruch->zaehler / abs(bruch->zaehler);
  int ggT = (int)gcd(bruch->zaehler / sign, bruch->nenner);
   
  bruch->zaehler /= ggT;
  bruch->nenner /= ggT;
}

void bruchAddition(bruch_t* bruch, bruch_t add) {
  bruch->zaehler = bruch->zaehler * add.nenner + add.zaehler * bruch->nenner;
  bruch->nenner *= add.nenner;
 
  bruchKuerzen(bruch); 
}

void bruchSubtraktion(bruch_t* bruch, bruch_t sub) {
  if(sub.nenner < 0) {
    sub.zaehler *= -1;
    sub.nenner *= -1;
  }
  if(bruch->nenner < 0) {
    bruch->zaehler *= -1;
    bruch->nenner *= -1;
  }

  bruch->zaehler = bruch->zaehler * sub.nenner - sub.zaehler * bruch->nenner;
  bruch->nenner *= sub.nenner;
  if(bruch->zaehler == 0) {
    bruch->nenner = 1;
    bruch->zaehler = 0;
  } else {
    bruchKuerzen(bruch);
  }

  if(bruch->nenner < 0) {
    bruch->zaehler *= -1;
    bruch->nenner *= -1;
  }
}

void bruchMultiplikation(bruch_t* bruch, bruch_t mult) {
  bruch->zaehler *= mult.zaehler;
  bruch->nenner *= mult.nenner;
  bruchKuerzen(bruch);
}

void bruchDivision(bruch_t* bruch, bruch_t div) {
  bruch->zaehler *= div.nenner;
  bruch->nenner *= div.zaehler;
  
  bruchKuerzen(bruch);
}

float bruchQuotient(bruch_t bruch) {
  return (float)bruch.zaehler / (float)bruch.nenner;
}

void bruchErweitern(bruch_t* bruch, int faktor) {
  bruch->zaehler *= faktor;
  bruch->nenner *= faktor;
}

// int main() {
//   bruch_t b;
//   bruch_t f;
//   bruchEingabe(&b);
//   bruchEingabe(&f);

//   printf("\n");
//   bruchSubtraktion(&b, f);
//   bruchAusgabe(&b);
//   return 0;
// }
