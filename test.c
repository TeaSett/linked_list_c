#include <assert.h>
#include "basic_routins.h"


void fill_list_ints(struct linked_list *list, size_t s) {
    for (int i = 0; i < s; ++i) push(list, &i, sizeof i);
}


int main() { 
// #define SIMPLE
#ifdef SIMPLE
#undef ESSENTIAL
#undef REVERSE
    {
    struct linked_list *l = malloc(list_struct_size());
    if (l) init_list(l);
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
    clean_list(l);
    free(l);
    l = NULL
    assert(list_is_empty(l));
    }
#endif

// #define ESSENTIAL
#ifdef ESSENTIAL
#undef REVERSE
#undef SIMPLE
    {
    const size_t s = 10;
    struct linked_list *l;
    alloc_list(l);
    else abort();

    fill_list_ints(l, s);
    print_list(l, " ");
    printf("\n");

    clean_list(l);
    print_list(l, " ");
    printf("list cleaned\n");

    free(l);
    l = NULL;
    }
#endif

// #define REVERSE
#ifdef REVERSE
#undef ESSENTIAL
#undef SIMPLE
    {
    struct linked_list *l;
    alloc_list(l);
    else abort();

    fill_list_ints(l, 20);
    print_list(l, " ");
    printf("\n");
    
    reverse(l);
    print_list(l, " ");
    printf("\n");

    clean_list(l);
    print_list(l, " ");
    printf("list cleaned\n");
    free(l);
    }
#endif
    return 0;
}
