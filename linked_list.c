#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_iterator.h"

typedef struct linked_list linked_list;


struct linked_list init_list() {
    linked_list new = {NULL};
    return new;
}


void clean_list(struct linked_list *list) {
    void *res = pop(list);
    while (res) {
        free(res);
        res = pop(list);
    }
    assert(list->start == NULL);
}


struct linked_list * create_dynamic_list() {
    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    (*list) = init_list();

    return list;
}


void delete_dynamic_list(struct linked_list *list) {
    clean_list(list);
    free(list);
}


int print_list(const struct linked_list* const list, const char * delimiter) {
    if (list->start == NULL) {
        printf("List is empty");
        return -1;
    }
    
    int ret = 0;
    iterator i = init_iterator(list);
    for (; i.current != NULL; step(&i)) {
        ret += printf("%d%s", *((int*)(i.current->data)), ((i.next) ? delimiter : ""));
    }

    return ret;
}


void push(struct linked_list *list, void *data, unsigned data_size) {
    struct node_t *new = (struct node_t*) malloc(sizeof(struct node_t));
    if (!new) {
        perror("Error memory allocation");
        abort();
    }
    
    new->data = malloc(data_size);
    if (!(new->data)) {
        perror("Error memory allocation");
        abort();
    }
    
    memcpy(new->data, data, data_size);
    new->next = list->start;
    list->start = new;
}


void* pop(struct linked_list *list) {
    if (list->start == NULL) return NULL;

    void *data_cpy = list->start->data;
    list->start->data = NULL;

    struct node_t *old = list->start;
    list->start = old->next;
    free(old);
    
    return data_cpy;
}


static node* swap(iterator *i, node* nd);

void reverse(struct linked_list *list) {
    node *buf = NULL;
    for (iterator i = init_iterator(list); i.current != NULL; step(&i)) {
        buf = swap(&i, buf);
    }
    list->start = buf;
}

static node* swap(iterator *i, node* nd) {
    node *buf = i->current;
    i->current->next = nd;
    return buf;
}