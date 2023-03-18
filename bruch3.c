#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
typedef struct {
  int zaehler;
  int nenner;
} bruch_t;

bruch_t sub_rational(bruch_t *x, bruch_t *y);

*/


bruch_t *max_rational(bruch_t list[], int length) {
  if(list == NULL || length <= 0) {
    return NULL;
  }
  bruch_t *max = list;
  for(int i = 0; i < length; i++) {
    if(sub_rational(max, list + i).zaehler < 0) {
      max = list + i;
    }
  }
  return max;
}
