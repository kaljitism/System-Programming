#include <stdio.h>

int main() {
  int A[] = {2, 4, 5, 8, 1};
  
  printf("\nIn C, array objects are treated differently;\n");
  printf("\nWhen you try to access the array, you get its \n");
  printf("first index' memory address.\n");
  printf("\nYou could dereference it to access the value of it.\n");
  printf("\nOr, you could perform pointer arithmetic on it to \n");
  printf("jump memory blocks, reach to next indices, \n");
  printf("and access the address or dereference the value on that\n");
  printf("address if that index is within the range of length of array.\n");
  
  printf("\n-----------------------------------------------------------------\n");
  
  printf("\nAddress A     = %p;\n", A);
  printf("Address &A    = %p;\n", &A);
  printf("Address &A[0] = %p;\n", &A[0]);
  
  printf("\nValue *A   = %d;\n", *A);
  printf("Value A[0] = %d;\n", A[0]);
  
  printf("\n-----------------------------------------------------------------\n");
  
  printf("\nA  , &A   , &A[0] ==> Address of 1st element\n");
  printf("A+i, &A[i],       ==> Address of ith element\n");
  
  printf("\n*A    , A[0] ==> Value of 1st element\n");
  printf("*(A+i), A[i] ==> Value of ith element\n");
  
  printf("\n-----------------------------------------------------------------\n");
  
  int i;
  for (i = 0; i < 5; i++) {
    printf("\nAddress &A[%d] = %p;   Value A[%d]   = %d\n", i, A+i, i, A[i]);
    printf("Address A+%d   = %p;   Value *(A+%d) = %d;\n", i, &A[i], i, *(A + i));
  }
  
  printf("We can assign value of A to a pointer *p");
  int *p = A;
  p++; // Valid
  A++; // Invalid
}
