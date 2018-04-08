CC=gcc

sse_test: main.c sse.S
	$(CC) -I../include -c main.c -o main.o
	$(CC) -c sse.S -o sse.o
	$(CC) -L../common -lcommon sse.o main.o -o sse_test

.PHONY: clean
clean:
	rm -f sse_test main.o sse.o
