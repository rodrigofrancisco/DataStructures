/* Author: Rodrigo Francisco
 * Desc: Stack implementation using arrays
 * Date: 02/11/21
 */
#include <stdlib.h>
#include <assert.h>
#include "bool.h"
#include "stackarr.h"

Stack* stack_constructor(int max){
  Stack* this = (Stack*) malloc(sizeof(Stack));
  this->stack = (double*) malloc(max*sizeof(double));
  this->max = max;
  this->top = 0;
  return this;
}

void stack_destroyer(Stack* this) {
  if (!this) {
    free(this->stack);
    free(this);
  }
}

void stack_push(Stack* this, double value) {
  assert( stack_is_full(this) != TRUE ); //Error
  this->stack[this->top] = value;
  ++this->top;
}

double stack_pop(Stack* this) {
  assert( stack_is_empty(this) != TRUE ); //Error
  --this->top;
  return this->stack[this->top];
}

bool stack_is_full(Stack* this) {
  return this->top >= this->max;
}

bool stack_is_empty(Stack* this) {
  return this->top == 0;
}

double stack_peek(Stack* this) {
  assert( stack_is_empty(this) != TRUE ); //Error
  return this->stack[this->top - 1];
}
