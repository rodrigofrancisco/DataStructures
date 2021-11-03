#include<stdio.h>
#include "queuearr.h"

int main(){
  Queue* pacients = queue_constructor(4);

  /*printf("Removing before inserting: %0.2f\n", queue_remove(pacients));*/

  queue_insert(pacients,1.0);
  queue_insert(pacients,2.0);
  queue_insert(pacients,6.0);
  /*queue_insert(pacients,7.0);*/
  /*queue_insert(pacients,0.0);*/
  /*queue_insert(pacients,0.0);*/

  printf("Removing: %0.2f\n", queue_remove(pacients));
  printf("first: %d\n", pacients->first);
  printf("Removing: %0.2f\n", queue_remove(pacients));
  printf("first: %d\n", pacients->first);
  printf("Removing: %0.2f\n", queue_remove(pacients));
  printf("first: %d\n", pacients->first);

  printf("Inserting 5.0 in the queue\n");
  queue_insert(pacients,5.0);
  printf("Removing: %0.2f\n", queue_remove(pacients));
  queue_insert(pacients,7.0);

  queue_destroyer(pacients);

  return 0;
}
