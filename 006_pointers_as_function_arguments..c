#include <stdio.h>

// Application Memory -
// [Code, Static and Stack Segment are fixed memory]
// [Heap is variable, app can ask for more or less memory as required]
// -----------------------------------------------------------------------------
// heap       -> does something I have no idea about
// stack      -> local variables(can only be accessed and modified in scope)
// static     -> global variables(can be accessed and modified anywhere in code)
// Code(text) -> instructions in our program
// -----------------------------------------------------------------------------

// In stack, each function(when its invoked) has its configuration(parameters,
// local vars, return type, etc) stored in a memory block called Stack-Frame.

// We can't access the variable outside it's stackframe. The lifetime of a
// local variable exists only till the time function is executing.

// The following code has no effect on value of "a"
// "a" variable in increment() and main() are inside two different stackframes.

// When the execution of increment() is done, compiler clears the stackframe
// for increment()

// printf() is a library function, not a user-defined function.
// Memory in stack assigned for library functions is called Callstack.

// In this code, increment() is being called from main(), so...
// main()      ---> calling function
// => In calling function, the argument passed is called actual argument
// increment() ---> called function
// => In called function, the argument received is called formal argument

// What happens is, actual argument is mapped(copied) to the formal argument.
// Note that, both are different argument in different stackframes.
// Such a function call is called "call by value", where actual argument is
// mapped or copied to formal argument.

//void increment(int a) {    // formal argument
//  a += 1;   // --> local var 2 which has value of local var 1
//  printf("Address of var a in increment function: %p\n", &a);
//}
//
//int main() {
//  int a;   // --> local var 1
//  a = 10;
//  increment(a); // --> value of local var 1 is passed, not local var itself
//  increment(a);
//  increment(a);
//  increment(a);
//  printf("a = %d\n", a);  // actual argument
//  printf("Address of var a in increment function: %p\n", &a);
//
//  return 0;
//}

// To overcome this problem and increment the 'a' variable which is in the
// stackframe of main(), we have to use pointers.
// So that we are referring to the value at exact address of a, thus no
// chance of worry about incrementing a different variable because we are
// referring to the value of 'a' which resides at a stackframe of main().

// Such a function call is called "call by reference", where you pass the
// reference to a variable instead of the variable's value itself, which will
// get copied into a different variable in another stackframe.

void increment(int *p) {
  *p += 1;
}

int main() {
  int a = 10;
  increment(&a);
  increment(&a);
  increment(&a);
  increment(&a);
  printf("a = %d", a);
  
  return 0;
}

// Works like a breeze..., eh!
