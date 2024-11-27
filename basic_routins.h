#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "list_iterator.h"


#define alloc_list(list) \
    list = (struct linked_list*) malloc(list_struct_size()); \
    if (list) init_list(list)

void print_list(struct linked_list *l, char *separator) {
    if (list_is_empty(l)) return;

    struct list_iterator *i;
    if (!(i = (struct list_iterator*)malloc(list_iterator_struct_size()))) abort();
    for (init_iterator(i, l); !end_of_list(i); step(i))
        printf("%d%s", *((int*)current_data(i)), separator);
}