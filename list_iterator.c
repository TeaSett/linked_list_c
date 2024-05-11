#include <stdlib.h>
#include "list_iterator.h"


iterator init_iterator(const struct linked_list* const list) {
    iterator i = {list->start, list->start->next};
    return i;
}


void step(iterator *i) {
    if (i->next == NULL) {
        i->current = NULL;
        return;
    }
    struct node_t *buf = i->next->next;
    i->current = i->next;
    i->next = buf;
}