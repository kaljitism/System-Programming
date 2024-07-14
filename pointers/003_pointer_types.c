// Pointers are strongly typed and follow the patterns
// of size and signs defined in data types

#include <stdio.h>

int main() {
  // 1025 ---> 00000000 00000000 00000100 00000001
  int a = 1025;
  int *pA;
  pA = &a;
  
  printf("size of integer is %lu bytes\n", sizeof(int));
  printf("pA       --> address = %p, value = %d\n", pA, *pA);
  printf("(pA + 1) --> address = %p, value = %d\n", pA+1, *(pA+1));
  
  char *pC;
  pC = (char*) pA;    // Typecasting
  printf("\nsize of char is %lu bytes\n", sizeof(char));
  printf("pC       --> address = %p, value = %d\n", pC, *pC);
  printf("(pC + 1) --> address = %p, value = %d\n", pC+1, *(pC+1));
}
