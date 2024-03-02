#include "queue.h"

typedef struct node {
    void* elem;
    node* next;
}node;

typedef struct queue {
    node* first_node;
    unsigned int num_of_nodes;
}queue;

