CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O2
LDFLAGS=
EXEC=SudokuFinisher

all: $(EXEC)

SudokuFinisher: my_strlen.o my_printf.o chained_list.o check_grid.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
