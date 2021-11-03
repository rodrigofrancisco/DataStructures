/* Author: Rodrigo Francisco
 * Desc: Stack implementation using arrays
 * Date: 02/11/21
 */
#ifndef STACK_INC
#define STACK_INC

#include "bool.h"

typedef struct Stack_Type {
  int top;                // Current value pointer
  unsigned int max;       // Max num of values allowed
  double* stack;          // Array to store values
} Stack;

Stack* stack_constructor(int max);
void stack_destroyer(Stack* this);
void stack_push(Stack* this, double value);
double stack_pop(Stack* this);
double stack_peek(Stack* this);
bool stack_is_empty(Stack* this);
bool stack_is_full(Stack* this);

#endif /*END STACK_INC*/
