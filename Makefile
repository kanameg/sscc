#
# Makefile for 0cc
#
CC=gcc
CFLAGS=-Wall -std=c11 # -DCC0_DEBUG
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)


cell: $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJS): cell

test: cell
	./test.sh

clean:
	rm -f cell *.o *~ tmp*
