#include "queue.h"
#include <stdlib.h>
#include <threads.h>


typedef struct node {
    void* elem;
    struct node* next;
    struct node* prev;
}node;

typedef struct queue {
    node* first_node;
    node* last_node;
    mtx_t mutex;
    cnd_t can_consume;
    cnd_t can_produce;
    size_t size;
}queue;

// This is the queue we will work with to contain all the data
static queue* q;

void initQueue(void) {
    q = calloc(1, sizeof(queue));
    mtx_init(&q->mutex, mtx_plain);
    cnd_init(&q->can_consume);
    cnd_init(&q->can_produce);
}

void destroyQueue(void) {
    node* next_p = q->first_node;
    node* curr_p;
    while (next_p != NULL) {
        curr_p = next_p;
        next_p = next_p->next;
        free(curr_p);
    }
    mtx_destroy(&q->mutex);
    cnd_destroy(&q->can_consume);
    cnd_destroy(&q->can_produce);
    free(q);
}


int run_enqueue(void** elem) {

    return 0;
}