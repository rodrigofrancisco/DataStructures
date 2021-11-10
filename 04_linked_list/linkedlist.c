/* Author: Rodrigo Francisco
 * Desc: LinkedList implementation
 * Date: 02/11/21
 */
#include <stdlib.h>
#include <assert.h>
#include "bool.h"
#include "linkedlist.h"

/**
 * Private function
 */
static Node* new_node(Type value) {
  Node* new = (Node*) malloc(sizeof(Node));
  if( new ) {
    new->data = value;
    new->next = NULL;
  }

  return new;
}

static void delete_node(Node* node) {
  if ( node ) free(node); 
}

/**
 * Public functions
 */
LinkedList* linked_list_constructor() {
  LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));
  if( this ) {
    this->first = NULL;
    this->last = NULL;
  }
  
  return this;
}

void linked_list_destroyer(LinkedList* this) {
  if( this ) {
    while( this->first ) {
      Node* tmp=this->first->next;
      delete_node(this->first);
      this->first=tmp;
    }
  }

  if(this) free(this);
}


bool linked_list_insert(LinkedList* this, Type value) {
  Node* node = new_node(value);
  if( !node ) return FALSE;

  if ( linked_list_is_empty(this) ) {
    this->first = node;
    this->last = node;
  } else {
    this->last->next = node;
    this->last = node;
  }
  return TRUE;
}


Type linked_list_remove(LinkedList* this) {
  if( linked_list_is_empty(this) ) return FALSE;
  
  Type value = this->first->data;
  // If only 1 element
  if( this->last == this->first ) {
    delete_node(this->first);
    this->last = NULL;
    this->first = NULL;
  } else {
  // Contains 2 or more elements
    Node* tmp = this->first->next; 
    delete_node(this->first);
    this->first = tmp;
  }
  
  return value;
}

bool linked_list_is_empty(LinkedList* this) {
  if( this->first == NULL ) return TRUE;
  return FALSE;
}

bool linked_list_element_in(LinkedList* this, Type query) {
  if( linked_list_is_empty(this) ) return FALSE;
  Node* iterator = this->first;
  while( iterator != NULL ) {
    if( iterator->data == query ) {
      return TRUE;
    }
    iterator = iterator->next;
  }

  return FALSE;
}

Node* linked_list_search(LinkedList* this, Type query) {
  if( linked_list_is_empty(this) ) return NULL;
  Node* iterator = this->first;
  while( iterator != NULL ) {
    if( iterator->data == query ) {
      return iterator;
    }
    iterator = iterator->next;
  }
  return NULL;
}
