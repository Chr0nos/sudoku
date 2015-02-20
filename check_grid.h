#ifndef CHECK_GRID
#define CHECK_GRID
#include <stdbool.h>

int count_key_line(int sudoku[9][9], int v, int k);
int count_key_column(int sudoku[9][9], int h, int k);
int count_key_block(int sudoku[9][9], int v, int h, int k);
bool check_grid(int sudoku[9][9]);

#endif
