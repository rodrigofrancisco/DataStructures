#include<stdio.h>
#include "doublelinkedlist.h"

int main(){
  DoubleLinkedList* pacients = double_linked_list_constructor();

  /*printf("Popping before inserting: %0.2f\n", double_linked_list_pop(pacients));*/

  double_linked_list_insert(pacients,1);
  double_linked_list_insert(pacients,2);
  double_linked_list_insert_back(pacients,7);
  double_linked_list_insert(pacients,6);
  double_linked_list_insert(pacients,8);

  printf("Popping: %d\n", double_linked_list_remove(pacients));
  printf("Popping: %d\n", double_linked_list_remove(pacients));
  /*printf("Popping back: %d\n", double_linked_list_remove_back(pacients));*/
  printf("Popping: %d\n", double_linked_list_remove(pacients));
  printf("Popping: %d\n", double_linked_list_remove(pacients));
  printf("Popping: %d\n", double_linked_list_remove(pacients));

  double_linked_list_destroyer(pacients);

  return 0;
}
