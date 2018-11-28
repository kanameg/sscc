#
# Makefile for sscc
#
CC=gcc
CFLAGS=-Wall -std=c11 # -DCC0_DEBUG
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)


sscc: $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJS): sscc

test: sscc
	./test.sh

clean:
	rm -f sscc *.o *~ tmp*
