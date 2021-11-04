/* Author: Rodrigo Francisco
 * Desc: CircularQueue implementation using arrays
 * Date: 02/11/21
 */
#ifndef CIRCULAR_QUEUE_INC
#define CIRCULAR_QUEUE_INC

#include "bool.h"

typedef struct Circularcircular_queue_Type {
  double* queue;          // Array to store values
  unsigned int max;       // Max num of values allowed
  int first;                
  int last;                
  int count;                
} CircularQueue;

CircularQueue* circular_queue_constructor(int max);
void circular_queue_destroyer(CircularQueue* this);
void circular_queue_insert(CircularQueue* this, double value);
double circular_queue_remove(CircularQueue* this);
bool circular_queue_is_empty(CircularQueue* this);
bool circular_queue_is_full(CircularQueue* this);
double circular_queue_peek(CircularQueue* this);
void circular_queue_cleaner(CircularQueue* this);

#endif /*END CIRCULAR_QUEUE_INC*/
