#include "linked_list.h"

typedef struct list_iterator {
    struct node_t *current;
    struct node_t *next;
} iterator;

static iterator init_iterator(const struct linked_list* const list);

static void step(iterator *i);