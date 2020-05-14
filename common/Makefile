#variables

L = ../libcs50
LIB = common.a

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I $L 
OBJS = pagedir.o index.o word.o
LLIBS = $L/libcs50-given.a
MAKE = MAKE

# Rules
$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

pagedir.o: pagedir.h $(LLIBS)
pagedir.h: $(LLIBS)

index.o: index.h word.h $(LLIBS)
index.h: word.h $(LLIBS)

word.o: word.h 


#phony Targets
.PHONY: clean

clean:
	rm -f core
	rm -f $(LIB) *~ *.o

