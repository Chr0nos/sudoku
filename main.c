#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "my_strlen.h"
#include "my_printf.h"
#include "chained_list.h"
#include "check_grid.h"
#include "my_itoa.h"

void show_grid(int sudoku[9][9])
{
    int h;
    int v;
    int column;
    int x;

    column = 2;
    x = 2;
    v = 0;
    my_printf("\n");
    while (v < 9)
    {
        h = 0;
        while (h < 9)
        {
            my_printf("%i ", sudoku[v][h]);
            if (!column--)
            {
                column = 2;
                my_printf("  ");
            }
            h++;
        }
        my_printf("\n");
        if (!x--)
        {
            x = 2;
            my_printf("\n");
        }
        v++;
    }
    my_printf("#####################\n");
}

bool check_block(int sudoku[9][9], int v, int h, int value)
{
    int hl;
    int vl;

    v = v - (v % 3);
    h = h - (h % 3);
    hl = 0;
    while (hl < 3)
    {
        vl = 0;
        while (vl < 3)
        {
            if (sudoku[v + vl][h + hl] == value)
                return true;
        vl++;
        }
    hl++;
    }
    return false;
}

bool check_line(int sudoku[9][9], int v, int k)
{
    int i;

    i = 9;
    while (i--)
    {
        if (sudoku[v][i] == k)
            return true;
    }
    return false;
}

bool check_column(int sudoku[9][9], int h, int k)
{
    int p;

    p = 9;
    while (p--)
    {
        if (sudoku[p][h] == k)
            return true;
    }
    return false;
}

int count_missing(int sudoku[9][9])
{
    /* cette fonction compte le nombre de cases vides */
    int v;
    int h;
    int c;

    v = 9;
    c = 0;
    while (v--)
    {
        h = 9;
        while (h--)
        {
            if (!sudoku[v][h])
                c++;
        }
    }
    return c;
}
bool check_position(int sudoku[9][9], int v, int h, int k)
{
    if (check_line(sudoku, v, k)) return false;
    if (check_column(sudoku, h, k)) return false;
    if (check_block(sudoku, v, h, k)) return false;
    return true;
}

bool fill_grid(int sudoku[9][9], int position)
{
    /*
     * variables:
     * v : vertical position
     * h : horizontal position
     * k : current digit in try
     */
    int v;
    int h;
    int k;

    v = position / 9;
    h = position % 9;
    k = 1;

    if (position == 81)
        return true;

    if (sudoku[v][h])
        return fill_grid(sudoku,position+1);

    while (k <= 9)
    {
        if (check_position(sudoku, v, h, k))
        {
            sudoku[v][h] = k;
            /* printf("confirmed -> %i:%i x:%i\n", v, h,sudoku[v][h]); */
            if (fill_grid(sudoku,position +1))
                return true;
        }
        k++;
    }
    sudoku[v][h] = 0;
    return false;
}

void load_line(int sudoku[9][9], const char* line)
{
    int pos;
    int v;
    int h;
    int len;

    pos = 0;
    len = my_strlen(line);
    if (len > 81) len = 81;
    while (pos < len)
    {
        v = pos / 9;
        h = pos % 9;
        sudoku[v][h] = line[pos] - 48;
        pos++;
    }
}

bool load_file(char* filepath, const int grid_num, int sudoku[9][9])
{
    FILE* file;
    char data[82];
    int count;

    count = 0;
    file = fopen(filepath,"r");
    while (fread(data,sizeof(char),82,file))
    {
        count++;
        if (grid_num == count)
        {
            load_line(sudoku,data);
            return true;
        }
    }
    fclose(file);
    return false;
}

void grid_clear(int sudoku[9][9])
{
    int v;
    int h;
    int pos;

    pos = 82;
    while (pos--)
    {
        v = pos / 9;
        h = pos % 9;
        sudoku[v][h] = 0;
    }
}

int main(int argc, char *argv[])
{
    /*
    ** sudoku[] = vertical
    ** sudoku[][] = horizontal
    */
    int missing;
    int sudoku[9][9];

    my_printf("my test: %x\n",1000);
    if (argc > 1)
    {
        my_printf("loading user grid\n");
        grid_clear(sudoku);
        load_line(sudoku,argv[1]);
        if (!check_grid(sudoku))
        {
            my_printf("invalid user grid\n");
            exit(0);
        }
    }
    else {
        my_printf("loading default grid\n");
        load_line(sudoku,"780360000006010902003402607809504201060901070107206805508603700304090500000025048");
    }
    show_grid(sudoku);
    missing = count_missing(sudoku);
    my_printf("missing: %i\n",missing);

    fill_grid(sudoku,0);

    show_grid(sudoku);
    missing = count_missing(sudoku);
    my_printf("missing: %i\n",missing);
    return 0;
}

