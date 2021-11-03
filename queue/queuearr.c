/* Author: Rodrigo Francisco
 * Desc: Queue implementation using arrays
 * Date: 02/11/21
 */
#include <stdlib.h>
#include <assert.h>
#include "bool.h"
#include "queuearr.h"

Queue* queue_constructor(int max){
  Queue* this = (Queue*) malloc(sizeof(Queue));
  this->queue = (double*) malloc(max*sizeof(double));
  this->max = max;
  this->first = 0;
  this->last = 0;
  return this;
}

void queue_destroyer(Queue* this) {
  if (!this) {
    free(this->queue);
    free(this);
  }
}

void queue_insert(Queue* this, double value) {
  if( queue_is_full(this) ) {
    if( this->first == 0 ) assert(queue_is_full(this) != TRUE);
    else {
      queue_refresher(this);
    }
  }
  this->queue[this->last] = value;
  ++this->last;
}

double queue_remove(Queue* this) {
  assert( queue_is_empty(this) != TRUE ); //Error
  ++this->first;
  return this->queue[this->first-1];
}

bool queue_is_full(Queue* this) {
  return this->last >= this->max;
}

bool queue_is_empty(Queue* this) {
  return this->last == this->first;
}

double queue_peek(Queue* this) {
  return this->queue[this->first];
}

void queue_cleaner(Queue* this) {
  this->first = 0;
  this->last = 0;
}

void queue_refresher(Queue* this) {
  assert( this->first != 0 ); //Error
  int j = 0;
  for( int i = this->first; i < this->last; i++ ) {
      this->queue[j] = this->queue[this->first];
      ++j;
  } 
  this->first = 0;
  this->last = j;
}
