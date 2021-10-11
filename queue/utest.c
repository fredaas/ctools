#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _print_status(const char *fname, int errors)
{
    if (errors)
        printf("[ \e[0;91mfail\e[0m ] %s\n", fname);
    else
        printf("[ \e[0;92msuccess\e[0m ] %s\n", fname);
}

#define print_status(errors) do { \
    _print_status(__func__, errors); \
} while (0)

Queue * setup_queue(void)
{
    Queue *queue = queue_init(4);

    for (int i = 0; i < 4; i++)
    {
        int *value = (int *)malloc(sizeof(int));
        *value = i + 1;
        queue_push(queue, (void *)value);
    }

    return queue;
}

void test_queue_add(void)
{
    int errors = 0;

    Queue *queue = queue_init(4);

    int values[10];

    for (int i = 0; i < 10; i++)
    {
        values[i] = i + 1;
        queue_push(queue, (void *)&(values[i]));
    }

    /* Check queue size */
    errors += (queue->size != 4);

    /* Check queue contents */
    int head = queue->head;
    int size = queue->size;
    for (int i = head, j = 0; size-- > 0; i++, j++)
    {
        int a = *((int *)queue->list[i].value);
        int b = values[j];
        errors += (a != b);
    }

    print_status(errors);
}

void test_queue_pop(void)
{
    int errors = 0;

    Queue *queue = queue_init(4);

    int values[4];

    for (int i = 0; i < 4; i++)
    {
        values[i] = i + 1;
        queue_push(queue, (void *)&(values[i]));
    }

    /* Check if items are removed in correct order */
    for (int i = 0; i < 4; i++)
    {
        int *a;
        queue_pop(queue, (void **)&a);
        int b = values[i];
        errors += (*a != b);
    }

    /* Check that we can't remove items from an empty queue */
    for (int i = 0; i < 4; i++)
    {
        int *a;
        queue_pop(queue, (void **)&a);
    }

    /* Check queue size */
    errors += (queue->size != 0);

    print_status(errors);
}

void print_queue(Queue *queue)
{
    int head = queue->head;
    int size = queue->size;
    for (int i = head; size-- > 0; i++)
        printf("%d ", *((int *)queue->list[i].value));
    printf("\n");
}

int main(void)
{
    test_queue_add();
    test_queue_pop();
}
