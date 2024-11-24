#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linked_list.h"
#include "list_iterator.h"

void fill_list_ints(struct linked_list *list, size_t s) {
    for (int i = 0; i < s; ++i) push(list, &i, sizeof i);
}

void print_list(struct linked_list *l, char *separator) {
    if (list_is_empty(l)) return;

    struct list_iterator *i;
    alloc_list_iterator(&i);
    for (init_iterator(i, l); !end_of_list(i); step(i))
        printf("%d%s", *((int*)current_data(i)), separator);
}
// extern struct linked_list;

int main() { 

#ifdef SIMPLE
    {
    struct linked_list *l;
    if (alloc_list(&l)) init_list(l);

    clean_list(l);
    assert(l != NULL);

    int a = 42;
    push(l, &a, sizeof(int));
    int *data = (int*) pop(l);
    printf("%d", *data);
    free(data);
    
    free_list(&l);
    assert(list_is_empty(l));
    }
#endif
#if ESSENTIAL
    {
    const size_t s = 10;
    struct linked_list *l2;
    alloc_and_init_with_nullcheck(l2);

    fill_list_ints(l2, s);
    print_list(l2, " ");
    printf("\n");

    clean_list(l2);
    print_list(l2, " ");
    printf("list cleaned\n");

    free_list(&l2);
    }
#endif
#if REVERSE
    struct linked_list *l3;
    alloc_list(&l3);
    init_list(l3);

    fill_list_ints(l3, 20);
    print_list(l3, " ");
    printf("\n");
    
    reverse(l3);
    print_list(l3, " ");
    printf("\n");

    clean_list(l3);
    print_list(l3, " ");
    printf("list cleaned\n");
    free_list(&l3);
#endif
    return 0;
}
