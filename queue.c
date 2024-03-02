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
    uint32_t num_of_nodes;
}queue;

// This is the queue we will work with to contain all the data
static queue* q;

void initQueue(void) {
    q = calloc(1, sizeof(queue));
}

void destroyQueue(void) {
    node* next_p = q->first_node;
    node* curr_p;
    while (next_p != NULL) {
        curr_p = next_p;
        next_p = next_p->next;
        free(curr_p);
    }
    free(q);
}


int run_enqueue(void** elem) {

    return 0;
}