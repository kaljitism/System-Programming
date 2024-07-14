// Pointers - Variables that store address of another variable.
// Let's take a pointer variable p

//  p --> address stored at p
// *p --> value at address stored at p
// &p --> address of p

#include <stdio.h>

int main() {
  int a;
  int b;
  char x;
  
  a = 4;
  b = 10;
  x = 'x';
  
  int *pA;
  int *pB;
  char *pX;
  
  pA = &a;
  pB = &b;
  pX = &x;
  
  // Value
  printf("------------ VALUES ------------\n");
  printf("Value of a: %d\n", a);
  printf("Value of b: %d\n", b);
  printf("Value of x: %c\n", x);
  
  // Memory Address
  printf("\n-------- MEMORY ADDRESSES --------\n");
  printf("Value of &a: %p\n", &a);
  printf("Value of &b: %p\n", &b);
  printf("Value of &x: %p\n", &x);
  
  // Memory Address
  printf("\n-------- MEMORY ADDRESSES -------\n");
  printf("Value of pA: %p\n", pA);
  printf("Value of pB: %p\n", pB);
  printf("Value of pX: %p\n", pX);

  // Value by dereferencing
  printf("\n----- VALUES BY DEREFERENCING -----\n");
  printf("Value of *pA: %d\n", *pA);
  printf("Value of *pB: %d\n", *pB);
  printf("Value of *pX: %c\n", *pX);
  
  return 1;
}
