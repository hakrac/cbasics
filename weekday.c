#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int abs(int x) {
  return x > 0 ? x : -x;
}

int date2int(int tag, int monat, int year) {
  int m = monat;
  int dpm[12] = {
    31, // Januar
    ((year % 4 == 0 && year % 100 != 0)||year % 400 == 0) ? 29 : 28, // Feb
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
  return (year % 4 == 0 && year % 100 != 0)||year % 400 == 0 ? 366 : 365;
}

int dayspermonth(int year, int month) {
   int dpm[12] = {
    31, // Januar
    ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28, // Feb
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
  
  return dpm[month - 1];
}

int daydiff(int syear, int eyear, int smonth, int emonth, int sday, int eday) {
  int c = 0;
  int sign = 1; 
 
  if(syear > eyear) {
    int temp = eyear;
    eyear = syear;
    syear = temp;
    sign = -1;
  }
 
  for(int i = 0; i < eyear - syear; i++) {
    c += daysperyear(syear+i) * sign;
  }

  // printf("1. %d\n", c);
  sign = 1;
  
  if(smonth > emonth) {
    int temp = emonth;
    emonth = smonth;
    smonth = temp;
    sign = -1;
  }
  
  for(int i = 0; i < emonth - smonth; i++){
    c += dayspermonth(syear, smonth + i) * sign;
  }

  // printf("2. %d\n", c);
  sign = 1;
  
  if(sday > eday) {
    int temp = eday;
    eday = sday;
    sday = temp;
    sign = -1;
  }

   
  for(int i = 0; i < eday - sday;i++) {
    c += 1 * sign;
  }

  return c;
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

  // printf("%d\n\n", daydiff(1599, 1600, 12, 1, 31, 1));

  int day, month, year;
  scanf("%d.%d.%d", &day, &month, &year); 
  
  if(year > 5000 || year < 1582) {
    return 0;
  } 
  if(month > 12 || month < 0) {
    return 0;
  } else if(day < 1 || day > dayspermonth(year, month)) {
    return 0;
  }

  if(year == 1582) {
    if(month < 10) {
      return 0;
    }
    if(month == 10 && day < 15) {
      return 0;
    }
  }

  // 15.10.1582
  int dtotal = daydiff(1582, year, 10, month, 15, day);
  // printf("%d", dtotal);
  printf("%s", wdays[(dtotal + 4) % 7]);
  
  // calculate day difference
  // difference mod 7 = weekday
  
   
  return 0;
}
