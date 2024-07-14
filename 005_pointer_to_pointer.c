#include <stdio.h>

int main() {
  int x = 5;
  int *p;
  p = &x;
  
  int **q;
  q = &p;
  
  int ***r;
  r = &q;
  
  printf("**q = %d\n", **q);
  printf("***r = %d\n", ***r);
  
  ***r = 10;
  printf("x = %d\n", x);
  
  **q = *p + 2;
  printf("x = %d\n", x);
}
