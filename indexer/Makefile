# Makefile for the "crawler" program, part of our TSE
#
# CS50 Lab 4
C = ../common
L = ../libcs50


CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$C -I$L
PROG = indexer
OBJS = indexer.o
PROG1 = indextest
OBJS1 = indextest.o
LLIBS = $C/common.a $L/libcs50.a 

all: $(PROG) $(PROG1)

# executable depends on object files
$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(CFLAGS) $^ -o $@

$(PROG1): $(OBJS1) $(LLIBS)
	$(CC) $(CFLAGS) $^ -o $@

  
# object files depend on include files
indexer.o:  $C/index.h $L/hashtable.h $L/memory.h #alternatively, use $(LLIBS)
indextest.o: $C/index.h $L/hashtable.h  $L/file.h $L/memory.h

.PHONY: clean test

clean:
	rm -f $(PROG)
	rm -f $(PROG1)
	rm -f *~ *.o
	rm -rf *.dSYM

test: 
	bash -v testing.sh
	