CC=gcc
CFLAGS=-I. -I../tools/
DEPS=slp.h ../tools/util.h
OBJ=program.o slp.o ../tools/util.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
