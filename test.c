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
    if (!alloc_list_iterator(&i)) abort();
    for (init_iterator(i, l); !end_of_list(i); step(i))
        printf("%d%s", *((int*)current_data(i)), separator);
}


int main() { 

#ifdef SIMPLE
#undef ESSENTIAL
#undef REVERSE
    {
    struct linked_list *l;
    if (alloc_list(&l)) init_list(l);
    else abort();

    clean_list(l);
    assert(l != NULL);

    int a = 42;
    push(l, &a, sizeof(int));
    int *data = (int*) pop(l);
    printf("%d", *data);
    free(data);
    a += 1;
    push(l, &a, sizeof(int));
    data = (int*) pop(l);
    printf("%d", *data);
    free(data);
    
    clean_list(l);
    a += 1;
    push(l, &a, sizeof(int));
    data = (int*) pop(l);
    printf("%d", *data);
    free(data);
    assert(list_is_empty(l));
    push(l, &a, sizeof(int));
    push(l, &a, sizeof(int));
    push(l, &a, sizeof(int));
    free_list(&l);
    assert(list_is_empty(l));
    }
#endif
#if ESSENTIAL
#undef REVERSE
#undef SIMPLE
    {
    const size_t s = 10;
    struct linked_list *l2;
    alloc_and_init_list_with_nullcheck(l2);
    else abort();

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
#undef ESSENTIAL
#undef SIMPLE

    struct linked_list *l3;
    if (!alloc_list(&l3)) abort();
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
