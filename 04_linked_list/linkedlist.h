/* Author: Rodrigo Francisco
 * Desc: LinkedList implementation
 * Date: 02/11/21
 */
#ifndef LINKED_LIST_INC
#define LINKED_LIST_INC

#include "bool.h"

typedef int Type;

typedef struct Node_Type {
  Type data;
  struct Node_Type* next; // Point the next node.
} Node;

typedef struct LinkedList_Type {
  Node* first;
  Node* last;
} LinkedList;

LinkedList* linked_list_constructor();
void linked_list_destroyer(LinkedList* this);
bool linked_list_insert(LinkedList* this, Type value);
Type linked_list_remove(LinkedList* this);
bool linked_list_is_empty(LinkedList* this);
bool linked_list_element_in(LinkedList* this, Type query);
Node* linked_list_search(LinkedList* this, Type query);

#endif /*END LINKED_LIST_INC*/
