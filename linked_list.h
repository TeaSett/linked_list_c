/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list_c library.
 * linked_list_c library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.
 * linked_list_c library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list_c library. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

struct linked_list;

unsigned long list_struct_size();
void init_list(struct linked_list * const list);
void clean_list(struct linked_list *list);

int list_is_empty(const struct linked_list* const list);

void push(struct linked_list* const list, void *data, unsigned data_size);
void* pop(struct linked_list* const list);

void reverse(struct linked_list *list);