CC=gcc
CFLAGS=-I.
DEPS=slp.h ../tools/util.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: program.o slp.o ../tools/util.o
	$(CC) -o test.out program.o slp.o ../tools/util.o
