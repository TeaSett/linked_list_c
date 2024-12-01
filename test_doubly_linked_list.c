#include <stdio.h>
// #include <assert.h>
#include <stdlib.h>
#define DOUBLY
#include "linked_list.h"
#include "list_iterator.h"

void fill_list_ints(struct linked_list *list, size_t s) {
    for (int i = 0; i < s; ++i) push_back(list, &i, sizeof i);
}

void print_list(struct linked_list *l, char *separator) {
    if (list_is_empty(l)) return;

    struct list_iterator *i;
    if (!alloc_list_iterator(&i)) abort();
    for (init_iterator(i, l); !end_of_list(i); step(i))
        printf("%d%s", *((int*)current_data(i)), separator);
}


int main() {
    int a = 42, sz = sizeof(int);
    struct linked_list *l;
    alloc_and_init_list_with_nullcheck(l);
    // fill_list_ints(l, 10);
    push_back(l, &a, sz);
    ++a;
    push_back(l, &a, sz);
    ++a;
    push_front(l, &a, sz);
    ++a;
    push_front(l, &a, sz);
    ++a;
    push_back(l, &a, sz);
    ++a;
    push_back(l, &a, sz);

    print_list(l, " ");

    return 0;
}