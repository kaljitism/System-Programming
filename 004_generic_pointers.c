#include <stdio.h>

int main() {
  int a = 1025;
  int *p;
  p = &a;
  
  printf("size of integer is %lu bytes\n", sizeof(int));
  printf("address = %p, value = %d\n", p, *p);
  
  // Void Pointer/ Generic Pointer
  void *p0;
  p0 = p;
  printf("\naddress = %p\n", p0);
  
  // ERROR: printf("value = %d\n", p0, *p0);
  // ERROR: printf("address = %p\n", p0, p0+1);
}
