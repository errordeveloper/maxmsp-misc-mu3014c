#include <stdio.h>

#define SAMPLES 8
#define GAIN    0.5

#define RESET() \
  for (i = 0; i < SAMPLES; i++) { \
    x[i] = y[i] = 0.0; \
  }; x[0] = 1; d = 0;

int main () {

  float x[SAMPLES], y[SAMPLES], g = GAIN, d;
  int i;

  RESET();
  printf("y = < ");
  for (i = 0; i < SAMPLES; i++) {

    y[i] = d;
    d = x[i];
    x[i+1] = d*g;

    printf("%f ", y[i]);

  }
  printf(">)\n");

  RESET();
  printf("y = < ");
  for (i = 0; i < SAMPLES; i++) {

    d = y[i] = x[i] + g*d;
    printf("%f ", y[i]);

  }
  printf(">)\n");

  return 0;

}
