/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list_c library.
 * linked_list_c library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.
 * linked_list_c library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list_c library. If not, see <https://www.gnu.org/licenses/>.
 */

#include <memory.h>
#include <stdlib.h>
#include "linked_list_&_node.h"


int push(struct linked_list* const list, void *data, unsigned data_size) {
    size_t alloc_size = data_size + sizeof(node);

    char *alloc = malloc(alloc_size);
    if (!alloc) return -1;

    node *new;
    init_node(&new, alloc, data_size);
    (void) memcpy(new->data, data, data_size);
    
    new->next = list->head;
    list->head = new;

    return 0;
}

void init_node(node **nd, char *allocated, unsigned long dtsz) {
    (*nd) = (node*) (allocated + dtsz);
    (*nd)->data = allocated;
}


int push_nocopy(struct linked_list* const list, void *data) {
    node *new = malloc(sizeof(node));
    if (!new) return -1;

    new->data = data;
    new->next = list->head;
    list->head = new;

    return 0;
}
