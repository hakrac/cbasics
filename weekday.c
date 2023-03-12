#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int date2int(int tag, int monat, int year) {
  int m = monat;
  int dpm[12] = {
    31, // Januar
    ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28, // Feb
    31, // Maer
    30, // Apr
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
  };
  
  int d = 0;
  int i;
  for(i = 0; i < (m - 1); i++) {
    d += dpm[i];
  }
  return d + tag;
}

int daysperyear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 366 : 365;
}


int main () {
  char *wdays[7] = {
    "Montag",
    "Dienstag",
    "Mittwoch",
    "Donnerstag",
    "Freitag",
    "Samstag",
    "Sonntag"
  };


  int day, month, year;
  scanf("%d.%d.%d", &day, &month, &year);
  if(year > 5000 || year < 1500) {
    return 0;
  }
  
  if(month > 12 || month < 0) {
    return 0;
  } else if(day < 1 || day > dpm[month]) {
    return 0;
  }

   
  return 0;
}
