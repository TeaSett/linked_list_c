#include <stddef.h>
// #define DOUBLY
#include "list_iterator.h"

#ifndef DOUBLY
#define STEP step
#else
#define STEP step_forward
#endif

void STEP(iterator* const i) {
    if (i->next == NULL) {
        i->current = NULL;
        return;
    }
    node *buf = i->next->next;
    i->current = i->next;
    i->next = buf;
}

#ifdef DOUBLY
void step_back(iterator* const i) {
    if (i->current->prev == NULL) {
        return ;
    }
    node *buf = i->next->next;
    i->current = i->next;
    i->next = buf;
}
#endif