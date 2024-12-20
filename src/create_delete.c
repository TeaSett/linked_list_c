/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list_c library.
 * linked_list_c library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.
 * linked_list_c library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list_c library. If not, see <https://www.gnu.org/licenses/>.
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "list_iterator.h"

unsigned long list_struct_size() {
    return sizeof(linked_list);
}

void init_list(linked_list* const list) {
    list->head = NULL;
}


void clean_list(linked_list* const list) {
    if (list->head == NULL) return;

    iterator i;
    for (init_iterator(&i, list); !end_of_list(&i); step(&i)) {
        free(i.current->data);
    }
    assert(i.current == i.next && i.current == NULL);
    list->head = NULL;
}


int list_is_empty(const struct linked_list* const list) {
    return (list == NULL) || (list->head == NULL);
}
