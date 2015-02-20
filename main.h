#ifndef MAIN
#include <stdbool.h>
#define MAIN

int main(int argc, char *argv[]);
void show_grid(int sudoku[9][9]);
bool check_block(int sudoku[9][9], int v, int h, int value);
bool check_line(int sudoku[9][9], int v, int k);
bool check_column(int sudoku[9][9], int h, int k);
int count_missing(int sudoku[9][9]);
bool check_position(int sudoku[9][9], int v, int h, int k);
bool fill_grid(int sudoku[9][9], int position);
void load_line(int sudoku[9][9], const char* line);
bool load_file(char* filepath, const int grid_num, int sudoku[9][9]);

#endif
