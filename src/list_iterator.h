/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list library.
 * linked_list library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version.
 * linked_list library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list library. If not, see <https://www.gnu.org/licenses/>.
 */

#include "linked_list_&_node.h"

typedef struct list_iterator {
    struct node_t *current;
    struct node_t *next;
} iterator;

void init_iterator(struct list_iterator* const i, const struct linked_list* const list);

void step(iterator* const i);
int end_of_list(const iterator* const i);
