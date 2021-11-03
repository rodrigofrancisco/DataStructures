/* Author: Rodrigo Francisco
 * Desc: Queue implementation using arrays
 * Date: 02/11/21
 */
#ifndef QUEUE_INC
#define QUEUE_INC

#include "bool.h"

typedef struct Queue_Type {
  double* queue;          // Array to store values
  unsigned int max;       // Max num of values allowed
  int first;                
  int last;                
} Queue;

Queue* queue_constructor(int max);
void queue_destroyer(Queue* this);
void queue_insert(Queue* this, double value);
double queue_remove(Queue* this);
bool queue_is_empty(Queue* this);
bool queue_is_full(Queue* this);
double queue_peek(Queue* this);
void queue_cleaner(Queue* this);
void queue_refresher(Queue* this);

#endif /*END QUEUE_INC*/
