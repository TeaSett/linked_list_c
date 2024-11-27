/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list_c library.
 * linked_list_c library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.
 * linked_list_c library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list_c library. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include "linked_list_&_node.h"

void* pop_front(linked_list * const list) {
    if (list->head == NULL) return NULL;

    #ifdef DOUBLY
    if (list->head == list->tail) list->tail = NULL;
    #endif
    node *old = list->head;
    list->head = old->next;

    void *ret = old->data;
    #ifdef DOUBLY
    old->prev = 
    #endif
    old->next = old->data = NULL;
    
    return ret;
}


#ifdef DOUBLY
void* pop_back(linked_list * const list) {
    if (list->head == NULL) return NULL;

    if (list->head == list->tail) list->head = NULL;
    node *old = list->tail;
    list->tail = old->prev;

    void *ret = old->data;
    old->next = old->prev = old->data = NULL;
    
    return ret;
}
#endif
