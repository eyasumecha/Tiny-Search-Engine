# Makefile for the "crawler" program, part of our TSE
#
# CS50 Lab 4

L = ../libcs50
C = ../common

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$C -I$L
PROG = crawler
OBJS = crawler.o
LLIBS = $L/libcs50.a $C/common.a



# executable depends on object files
$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(CFLAGS) $^ -o $@
  
# object files depend on include files
crawler.o: $L/bag.h $L/hashtable.h $C/pagedir.h $L/memory.h #alternatively, use $(LLIBS)

.PHONY: clean testing1

clean:
	rm -f $(PROG)
	rm -f *~ *.o
	rm -rf *.dSYM

test: 
	bash -v testing.sh
	