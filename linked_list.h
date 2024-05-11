#pragma once

typedef struct node_t { 
    struct node_t *next;
    void *data; 
} node;

struct linked_list {
    struct node_t *start;
};

struct linked_list init_list();
void clean_list(struct linked_list *list);
struct linked_list * create_dynamic_list();
void delete_dynamic_list(struct linked_list *list);

int print_list(const struct linked_list* const list, const char * delimiter);

void push(struct linked_list *list, void *data, unsigned data_size);
void* pop(struct linked_list *list);

void reverse(struct linked_list *list);