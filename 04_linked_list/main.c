#include<stdio.h>
#include "linkedlist.h"

int main(){
  LinkedList* pacients = linked_list_constructor();

  /*printf("Popping before inserting: %0.2f\n", linked_list_pop(pacients));*/

  linked_list_insert(pacients,1);
  linked_list_insert(pacients,2);
  linked_list_insert(pacients,6);
  linked_list_insert(pacients,8);
  /*linked_list_insert(pacients,0);*/
  /*linked_list_insert(pacients,0);*/

  printf("Popping: %d\n", linked_list_remove(pacients));
  printf("Popping: %d\n", linked_list_remove(pacients));
  printf("Popping: %d\n", linked_list_remove(pacients));

  linked_list_destroyer(pacients);

  return 0;
}
