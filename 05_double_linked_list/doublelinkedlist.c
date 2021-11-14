/* Author: Rodrigo Francisco
 * Desc: DoubleLinkedList implementation
 * Date: 02/11/21
 */
#include <stdlib.h>
#include <assert.h>
#include "bool.h"
#include "doublelinkedlist.h"

/**
 * Private function
 */
static Node* new_node(Type value) {
  Node* new = (Node*) malloc(sizeof(Node));
  if( new ) {
    new->data = value;
    new->next = NULL;
    new->prev = NULL;
  }

  return new;
}

static void delete_node(Node* node) {
  if ( node ) free(node); 
}

/**
 * Public functions
 */
DoubleLinkedList* double_linked_list_constructor() {
  DoubleLinkedList* this = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
  if( this ) {
    this->first = NULL;
    this->last = NULL;
  }
  
  return this;
}

void double_linked_list_destroyer(DoubleLinkedList* this) {
  if( this ) {
    while( this->first ) {
      Node* tmp=this->first->next;
      delete_node(this->first);
      this->first=tmp;
    }
  }

  free(this);
}


bool double_linked_list_insert(DoubleLinkedList* this, Type value) {
  Node* node = new_node(value);
  if( !node ) return FALSE;

  if ( double_linked_list_is_empty(this) ) {
    this->first = node;
    this->last = node;
  } else {
    this->last->next = node;
    node->prev = this->last;
    this->last = node;
  }
  return TRUE;
}

bool double_linked_list_insert_back(DoubleLinkedList* this, Type value) {
  Node* node = new_node(value);
  if(!node) return FALSE;
  if(double_linked_list_is_empty(this)) {
    this->first = node;
    this->last = node;
  } else {
  // There is at least one element
    this->first->prev = node;
    node->next = this->first;
    this->first = node;
  }
  return TRUE;
}

Type double_linked_list_remove(DoubleLinkedList* this) {
  if( double_linked_list_is_empty(this) ) assert(0);
  
  Type value = this->first->data;
  // If only 1 element
  if( this->last == this->first ) {
    delete_node(this->first);
    this->last = NULL;
    this->first = NULL;
  } else {
  // Contains 2 or more elements
    Node* tmp = this->first->next; 
    tmp->prev = NULL;
    delete_node(this->first);
    this->first = tmp;
  }
  
  return value;
}

Type double_linked_list_remove_back(DoubleLinkedList* this) {
  if(double_linked_list_is_empty(this)) assert(0);

  Type value = this->last->data;
  // If only 1 element
  if( this->last == this->first ) {
    delete_node(this->last);
    this->last = NULL;
    this->first = NULL;
  } else {
  // LL contains 2 or more elements
    Node *tmp = this->last->prev;
    tmp->next = NULL;
    delete_node(this->last);
    this->last = tmp;
  }

  return value;
}

bool double_linked_list_is_empty(DoubleLinkedList* this) {
  if( this->first == NULL ) return TRUE;
  return FALSE;
}

bool double_linked_list_element_in(DoubleLinkedList* this, Type query) {
  if( double_linked_list_is_empty(this) ) return FALSE;
  Node* iterator = this->first;
  while( iterator != NULL ) {
    if( iterator->data == query ) {
      return TRUE;
    }
    iterator = iterator->next;
  }

  return FALSE;
}

Node* double_linked_list_search(DoubleLinkedList* this, Type query) {
  if( double_linked_list_is_empty(this) ) return NULL;
  Node* iterator = this->first;
  while( iterator != NULL ) {
    if( iterator->data == query ) {
      return iterator;
    }
    iterator = iterator->next;
  }
  return NULL;
}
