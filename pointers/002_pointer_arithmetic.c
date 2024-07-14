#include <stdio.h>

int main() {
  int a  = 10;
  char c = 'a';
  int *pA = &a;
  char *pC = &c;
  
  // Pointer Arithmetic
  
  // For integers, value of pA is incrementing 4 steps on adding 1.
  // since, sizeof(int) in C is 4 bytes
  printf("%p\n", pA);
  printf("%p\n", pA+1);
  
  // For characters, value of pC is decrementing 1 steps on subtracting 1.
  // since, sizeof(char) in C is 1 byte
  printf("%p\n", pC);
  printf("%p\n", pC-1);
  
  // Trying to get values at addresses we got upon modification
  printf("%d\n", *(pA+1));
  printf("%c\n", *(pC-1));
  
  return 0;
}
