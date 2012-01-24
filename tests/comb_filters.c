#include <stdio.h>

#ifdef PLOT
#define printf(...) \
  printf("\n"__VA_ARGS__)
#endif

#define SIZE      6
#define GAIN    0.65

void  comb_test_topology_a (float y[], float x[], 
    float d, float g) {

  printf("y = < ");
  for (int i = 0; i < SIZE; i++) {
  
    y[i] = d;
    d = x[i];
    x[i+1] += d*g;
  
    printf("%f ", y[i]);
  
  }
  printf(">\n");
}

void  comb_test_topology_b (float y[], float x[],
    float d, float g) {

   printf("y = < ");
   for (int i = 0; i < SIZE; i++) {

     d = y[i] = x[i] + g*d;
     printf("%f ", y[i]);

   }
   printf(">\n");
}

int main () {

  float x[SIZE], y[SIZE], g = GAIN, d = 0;

# define clear() \
  for (int i = 0; i < SIZE; i++) { \
    x[i] = y[i] = 0.0; }; x[0] = 1;

  clear();
  comb_test_topology_a (y, x, d, g);

  clear();
  comb_test_topology_b (y, x, d, g);

  return 0;

}
