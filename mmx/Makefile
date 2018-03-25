CC=gcc

mmx_test: main.c mmx.S
	$(CC) -I../include -c main.c -o main.o
	$(CC) -c mmx.S -o mmx.o
	$(CC) -L../common -lcommon mmx.o main.o -o mmx_test

.PHONY: clean
clean:
	rm -f mmx_test main.o mmx.o
