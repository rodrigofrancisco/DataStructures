#include<stdio.h>
#include "circularqueuearr.h"

int main(){
  CircularQueue* pacients = circular_queue_constructor(6);

  /*printf("Removing before inserting: %0.2f\n", circular_queue_remove(pacients));*/

  circular_queue_insert(pacients,1.0);
  circular_queue_insert(pacients,2.0);
  circular_queue_insert(pacients,6.0);
  /*circular_queue_insert(pacients,7.0);*/
  /*circular_queue_insert(pacients,0.0);*/
  /*circular_queue_insert(pacients,0.0);*/

  printf("Removing: %0.2f\n", circular_queue_remove(pacients));
  printf("first: %d\n", pacients->first);
  printf("Removing: %0.2f\n", circular_queue_remove(pacients));
  printf("first: %d\n", pacients->first);
  printf("Removing: %0.2f\n", circular_queue_remove(pacients));
  printf("first: %d\n", pacients->first);

  printf("Inserting 5.0 in the queue\n");
  circular_queue_insert(pacients,5.0);
  printf("Removing: %0.2f\n", circular_queue_remove(pacients));
  circular_queue_insert(pacients,7.0);
  circular_queue_insert(pacients,8.0);
  circular_queue_insert(pacients,9.0);
  circular_queue_insert(pacients,1.1);
  circular_queue_insert(pacients,1.2);
  circular_queue_insert(pacients,1.2);
  /*circular_queue_insert(pacients,1.2);*/
  printf("first: %d -> %0.2f\n", pacients->first,circular_queue_peek(pacients));
  printf("Removing: %0.2f\n", circular_queue_remove(pacients));
  printf("Removing: %0.2f\n", circular_queue_remove(pacients));
  printf("first: %d -> %0.2f\n", pacients->first,circular_queue_peek(pacients));

  circular_queue_destroyer(pacients);

  return 0;
}
