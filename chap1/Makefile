CC=gcc
CFLAGS=-I. -I../tools/
DEPS=slp.h maxargs.h ../tools/util.h
OBJ=program.o maxargs.o slp.o ../tools/util.o
BINARY_NAME=program.out

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINARY_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) $(BINARY_NAME)
