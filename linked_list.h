#pragma once

struct linked_list;

struct linked_list * create_list();
void clean_list(struct linked_list *list);
void delete_list(struct linked_list **list);

int print_list(const struct linked_list* const list, const char * delimiter);

void push(struct linked_list *list, void *data, unsigned data_size);
void* pop(struct linked_list *list);

void reverse(struct linked_list *list);