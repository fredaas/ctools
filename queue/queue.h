#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;
typedef struct QueueItem QueueItem;

struct Queue {
    int head;      /* Points to the current head of the queue */
    int tail;      /* Points to the next free slot in the queue */
    int size;      /* Current queue size */
    int num_items; /* Queue capacity */
    QueueItem *list;
};

struct QueueItem {
    void *value;
};

Queue * queue_init(int num_items);
void queue_push(Queue *self, void *value);
void queue_pop(Queue *self, void **value);
void queue_peek(Queue *self, void **value);

#endif /* QUEUE_H */