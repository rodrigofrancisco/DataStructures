/* Author: Rodrigo Francisco
 * Desc: DoubleLinkedList implementation
 * Date: 02/11/21
 */
#ifndef DOUBLE_LINKED_LIST_INC
#define DOUBLE_LINKED_LIST_INC

#include "bool.h"

typedef int Type;

typedef struct Node_Type {
  Type data;
  struct Node_Type* next;
  struct Node_Type* prev;
} Node;

typedef struct DoubleLinkedList_Type {
  Node* first;
  Node* last;
} DoubleLinkedList;

DoubleLinkedList* double_linked_list_constructor();
void double_linked_list_destroyer(DoubleLinkedList* this);
bool double_linked_list_insert(DoubleLinkedList* this, Type value);
bool double_linked_list_insert_back(DoubleLinkedList* this, Type value);
Type double_linked_list_remove(DoubleLinkedList* this);
Type double_linked_list_remove_back(DoubleLinkedList* this);
bool double_linked_list_is_empty(DoubleLinkedList* this);
bool double_linked_list_element_in(DoubleLinkedList* this, Type query);
Node* double_linked_list_search(DoubleLinkedList* this, Type query);

#endif /*END DOUBLE_LINKED_LIST_INC*/
