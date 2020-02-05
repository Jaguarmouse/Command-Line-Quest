CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

BBB: $(OBJS)
	$(CC) -o BBB $(OBJS) $(LDFLAGS)

$(OBJS): BBB.h

clean:
	rm -f BBB *.o *~ tmp*

.PHONY: clean
