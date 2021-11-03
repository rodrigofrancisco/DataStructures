#include<stdio.h>
#include "stackarr.h"

int main(){
  Stack* pacients = stack_constructor(4);

  /*printf("Popping before inserting: %0.2f\n", stack_pop(pacients));*/

  stack_push(pacients,1.0);
  stack_push(pacients,2.0);
  stack_push(pacients,6.0);
  stack_push(pacients,1.0);
  /*stack_push(pacients,0.0);*/
  /*stack_push(pacients,0.0);*/

  printf("Peeking: %0.2f\n", stack_peek(pacients));
  printf("Popping: %0.2f\n", stack_pop(pacients));
  printf("Peeking after popping: %0.2f\n", stack_peek(pacients));
  printf("Popping: %0.2f\n", stack_pop(pacients));
  printf("Popping: %0.2f\n", stack_pop(pacients));
  /*printf("Popping: %0.2f\n", stack_pop(pacients));*/
  printf("Peeking after popping: %0.2f\n", stack_peek(pacients));

  stack_destroyer(pacients);

  return 0;
}
