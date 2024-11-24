/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list_c library.
 * linked_list_c library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.
 * linked_list_c library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list_c library. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include "list_iterator.h"

static node* swap(iterator *i, node* nd);

void reverse(struct linked_list *list) {
    node *buf = NULL;
    iterator i;
    for (init_iterator(&i, list); i.current != NULL; step(&i)) {
        buf = swap(&i, buf);
    }
    list->head = buf;
}

static node* swap(iterator *i, node* nd) {
    node *buf = i->current;
    i->current->next = nd;
    return buf;
}
