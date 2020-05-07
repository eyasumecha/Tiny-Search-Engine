#variables
L = ../libcs50

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I $L 
OBJS = pagedir.o 
LIB = common.a
LLIBS = $L/libcs50-given.a
MAKE = MAKE

# Rules
$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

pagedir.o: pagedir.h $(LLIBS)
pagedir.h: $(LLIBS)
#phony Targets
.PHONY: clean

clean:
	rm -f core
	rm -f $(LIB) *~ *.o

