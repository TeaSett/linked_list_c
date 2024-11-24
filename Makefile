# Copyright 2024 Anton Lobastov
# This file is part of linked_list library.
# linked_list library is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version.
# linked_list library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
# You should have received a copy of the GNU Lesser General Public License along with linked_list library. If not, see <https://www.gnu.org/licenses/>.


libsingly_linked_list.a: build/create_delete.o build/list_iterator.o build/pop.o build/push.o build/reverse.o
	$(AR) r $@ $^


build/create_delete.o: src/create_delete.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $^ -o $@

build/list_iterator.o: src/list_iterator.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $^ -o $@

build/pop.o: src/pop.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $^ -o $@

build/push.o: src/push.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $^ -o $@

build/reverse.o: src/reverse.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $^ -o $@


simple_test: libsingly_linked_list.a
	$(CC) $(CFLAGS) -DSIMPLE test.c -L../linked_list -lsingly_linked_list -o $@

essential_test: libsingly_linked_list.a
	$(CC) $(CFLAGS) -DESSENTIAL test.c -L../linked_list -lsingly_linked_list -o $@

reverse_test: libsingly_linked_list.a
	$(CC) $(CFLAGS) -DREVERSE test.c -L../linked_list -lsingly_linked_list -o $@


.PHONY: clean
clean:
	rm build/*.o
	rm libsingly_linked_list.a
	rm simple_test
	rm essential_test
	rm reverse_test
