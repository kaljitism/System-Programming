#include <stdio.h>

int main() {
  int a = 5;
  int b = 10;
  
  int *pA = &a;
  int *pB = &b;
  
  printf("a = %d                 *pA = %d\n&a = %p    pA = %p\n", a, *pA, &a,
         pA);
  printf("b = %d                *pB = %d\n&b = %p    pB = %p\n", b, *pB, &b,
         pB);


//  *pA = b;
//  printf("\n*pA = b; Assign the value of b to the address of a\n");
//  printf("a = %d                *pA = %d\n&a = %p    pA = %p\n", a, *pA, &a, pA);
//  printf("b = %d                *pB = %d\n&b = %p    pB = %p\n", b, *pB, &b,
//         pB);

//  pA = &b;
//  printf("\npA = &b; Assign the value of b to the address of a\n");
//  printf("a = %d                 *pA = %d\n&a = %p    pA = %p\n", a, *pA, &a,
//         pA);
//  printf("b = %d                *pB = %d\n&b = %p    pB = %p\n", b, *pB, &b,
//         pB);
  
  return 0;
}
