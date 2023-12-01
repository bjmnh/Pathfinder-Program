EXEC = pathfinder
CC = g++
CFLAGS = -c -Wall
#
$(EXEC) :main.o minheap.o grapha.o stack.o
	$(CC) -o $(EXEC) main.o minheap.o grapha.o stack.o
#
main.o :main.cpp minheap.h stack.h grapha.h
		$(CC) $(CFLAGS) main.cpp
#
minheap.o :minheap.h minheap.cpp
	$(CC) $(CFLAGS) minheap.cpp
#
grapha.o :grapha.h stack.h minheap.h grapha.cpp
	$(CC) $(CFLAGS) grapha.cpp
#
stack.o :stack.h stack.cpp
	$(CC) $(CFLAGS) stack.cpp

