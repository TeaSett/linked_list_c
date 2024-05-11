#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_iterator.h"

typedef struct node_t { 
    struct node_t *next;
    void *data; 
} node;

typedef struct linked_list {
    struct node_t *start;
} linked_list;


struct linked_list * create_list() {
    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    
    if (list == NULL) perror("Error memory allocation");
    else list->start = NULL;

    return list;
}


void clean_list(struct linked_list *list) {
    if (list == NULL) {
        printf("List not exist");
        return;
    }

    void *res = pop(list);
    while (res) {
        free(res);
        res = pop(list);
    }
    assert(list->start == NULL);
}


void delete_list(struct linked_list *list) {
    if (list == NULL) {
        printf("List not exist");
        return;
    }
    
    clean_list(list);
    free(list);
    list = NULL;
}


int print_list(const struct linked_list* const list, const char * delimiter) {
    if (list->start == NULL) {
        printf("List is empty");
        return -1;
    }
    if (list == NULL) {
        printf("List not exist");
        return;
    }
    
    int ret = 0;
    iterator i = init_iterator(list);
    for (; i.current != NULL; step(&i)) {
        ret += printf("%d%s", *((int*)(i.current->data)), ((i.next) ? delimiter : ""));
    }

    return ret;
}


void push(struct linked_list *list, void *data, unsigned data_size) {
    if (list == NULL) {
        printf("List not exist");
        return;
    }
    if (data == NULL) {
        printf("Data not exist");
        return;
    }


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
    if (list == NULL) {
        printf("List not exist");
        return;
    }
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


static iterator init_iterator(const struct linked_list* const list) {
    iterator i = {list->start, list->start->next};
    return i;
}


static void step(iterator *i) {
    if (i->next == NULL) {
        i->current = NULL;
        return;
    }
    struct node_t *buf = i->next->next;
    i->current = i->next;
    i->next = buf;
}