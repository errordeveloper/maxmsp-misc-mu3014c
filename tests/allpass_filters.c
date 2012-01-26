#include <stdio.h>

#ifdef PLOT
#define printf(...) \
  printf("\n"__VA_ARGS__)
#endif

#define SIZE      10
#define GAIN      0.5

void  allpass_test_topology_a (float y[], float x[], 
    float d, float g) {

  printf("allpass_var_a = < ");
  for (int i = 0; i < SIZE; i++) {
  
    if (i == 0) { 
      y[i] = -g*x[i];
    } else {
      y[i] = -g*x[i]+(1-g*g)*x[i-1]+g*y[i-1];
    }
    printf("%f ", y[i]);
  }
  printf(">\n");
}

void  allpass_test_topology_b (float y[], float x[],
    float d, float g) {

   printf("allpass_var_b = < ");
   for (int i = 0; i < SIZE; i++) {

     if (i == 0) { 
       y[i] = -g*x[i];
     } else {
       y[i] = -g*x[i]+x[i-1]+g*y[i-1];
     }
     printf("%f ", y[i]);
   }
   printf(">\n");
}

int main () {

  float x[SIZE], y[SIZE], g = GAIN, d = 0;

# define clear() \
  for (int i = 0; i < SIZE; i++) { \
    x[i] = y[i] = 0.0; }; x[0] = 1; d = 0;

  clear();
  allpass_test_topology_a (y, x, d, g);

  clear();
  allpass_test_topology_b (y, x, d, g);

  return 0;

}
