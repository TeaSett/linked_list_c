/* Copyright 2024 Anton Lobastov
 * This file is part of linked_list_c library.
 * linked_list_c library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.
 * linked_list_c library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with linked_list_c library. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

typedef struct node_t { 
    struct node_t *next;
    #ifdef DOUBLY
    struct node_t *prev;
    #endif
    void *data; 
} node;

typedef struct linked_list {
    struct node_t *head;
    #ifdef DOUBLY
    struct node_t *tail;
    #endif
    char error_buf[50];
} linked_list;


void init_node(node **nd, char *allocated, unsigned long dtsz);
