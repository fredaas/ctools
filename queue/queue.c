#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Initializes the queue and returns a pointer to it
 */
Queue * queue_init(int num_items)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->num_items = num_items;
    queue->list = (QueueItem *)malloc(sizeof(QueueItem) * num_items);

    return queue;
}

/**
 * Adds a new element to the end of the queue
 */
void queue_push(Queue *self, void *value)
{
    if (self->size >= self->num_items)
        return;
    self->size++;
    self->list[self->tail].value = value;
    self->tail = ((self->tail + 1) % self->num_items);
}

/**
 * Returns and removes the next item in the queue
 */
void queue_pop(Queue *self, void **value)
{
    if (self->size == 0)
        return;
    *value = self->list[self->head].value;
    self->size--;
    self->head = ((self->head + 1) % self->num_items);
}

/**
 * Returns the next item in the queue
 */
void queue_peek(Queue *self, void **value)
{
    *value = self->list[self->head].value;
}
