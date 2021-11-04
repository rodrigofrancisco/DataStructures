/* Author: Rodrigo Francisco
 * Desc: CircularQueue implementation using arrays
 * Date: 02/11/21
 */
#include <stdlib.h>
#include <assert.h>
#include "bool.h"
#include "circularqueuearr.h"

CircularQueue* circular_queue_constructor(int max){
  CircularQueue* this = (CircularQueue*) malloc(sizeof(CircularQueue));
  this->queue = (double*) malloc(max*sizeof(double));
  this->max = max;
  this->first = 0;
  this->last = 0;
  this->count = 0;
  return this;
}

void circular_queue_destroyer(CircularQueue* this) {
  if (!this) {
    free(this->queue);
    free(this);
  }
}

void circular_queue_insert(CircularQueue* this, double value) {
  if( circular_queue_is_full(this) ) {
    assert(circular_queue_is_full(this) != TRUE);
  }
  this->queue[this->last] = value;
  ++this->count;
  ++this->last;
  if ( this->last == this->max ) this->last = 0;
}

double circular_queue_remove(CircularQueue* this) {
  assert( circular_queue_is_empty(this) != TRUE ); //Error
  int tmp_first = this->first;
  ++this->first;
  if ( this->first == this->max ) this->first = 0;
  --this->count;
  return this->queue[tmp_first];
}

bool circular_queue_is_full(CircularQueue* this) {
  return this->count == this->max;
}

bool circular_queue_is_empty(CircularQueue* this) {
  return this->count == 0;
}

double circular_queue_peek(CircularQueue* this) {
  return this->queue[this->first];
}

void circular_queue_cleaner(CircularQueue* this) {
  this->first = 0;
  this->last = 0;
  this->count = 0;
}
