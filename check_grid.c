#include <stdbool.h>

int count_key_line(int sudoku[9][9], int v, int k)
{
    int counter;
    int h;

    h = 9;
    counter = 0;
    while (h--)
    {
        if (sudoku[v][h] == k)
            counter++;
    }
    return counter;
}
int count_key_column(int sudoku[9][9], int h, int k)
{
    int v;
    int c;

    v = 9;
    c = 0;
    while (v--)
    {
        if (sudoku[v][h] == k)
            c++;
    }
    return c;
}

int count_key_block(int sudoku[9][9], int v, int h, int k)
{
    int hl;
    int vl;
    int c;

    c = 0;
    v = v - (v % 3);
    h = h - (h % 3);
    hl = 0;
    while (hl < 3)
    {
        vl = 0;
        while (vl < 3)
        {
            if (sudoku[v + vl][h + hl] == k)
                c++;
        vl++;
        }
    hl++;
    }
    return c;
}

bool check_grid(int sudoku[9][9])
{
    int k;
    int position;
    int v;
    int h;

    position = 81;
    while (position--)
    {
        v = position / 9;
        h = position % 9;
        k = 0;
        while (k++ < 8)
        {
            if (count_key_line(sudoku, v, k) > 1) return false;
            if (count_key_column(sudoku, h, k) > 1) return false;
            if (count_key_block(sudoku, v, h, k) > 1) return false;
        }
    }
    return true;
}
