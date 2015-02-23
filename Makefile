CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O2 -ggdb -pipe
LDFLAGS=
EXEC=SudokuFinisher

all: $(EXEC)

SudokuFinisher: my_strlen.o my_atoi.o my_itoa.o my_printf.o chained_list.o check_grid.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
