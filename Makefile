CC=gcc
#my flags
#CFLAGS=-W -Wall -ansi -pedantic -O2 -ggdb -pipe

#42 flags
CFLAGS=-Wall -Wextra -Werror -O2 -pipe -ggdb
LDFLAGS=
EXEC=SudokuFinisher

all: $(EXEC)

SudokuFinisher: ft_strcpy.o ft_memcpy.o ft_itohex.o ft_memset.o ft_strlen.o ft_strrev.o ft_atoi.o ft_itoa.o ft_printf.o chained_list.o check_grid.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
