#include "linked_list.h"

typedef struct list_iterator {
    struct node_t *current;
    struct node_t *next;
} iterator;

iterator init_iterator(const struct linked_list* const list);

void step(iterator *i);
node* swap(iterator *i, node* nd);