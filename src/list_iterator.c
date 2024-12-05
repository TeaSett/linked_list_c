/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list_c library.
 * linked_list_c library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.
 * linked_list_c library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list_c library. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#define DOUBLY
#include "list_iterator.h"


int alloc_list_iterator(struct list_iterator **i) {
    (*i) = malloc(sizeof(iterator));
    return (*i) != NULL;
}

void init_iterator(struct list_iterator* const i, const struct linked_list* const list) {
    i->current = list->head;
    i->next = list->head->next;
}


int end_of_list(const iterator* const i) {
    return i->current == i->next;
}


#ifdef DOUBLY
int begin_list(const iterator* const i) {
    return i->current->prev == NULL;
}
#endif


void* current_data(const struct list_iterator* const i) {
    return i->current->data;
}
