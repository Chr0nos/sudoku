#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "chained_list.h"

void my_memset(void *dest,size_t size, void *fill)
{
    char *d = (char*) dest;
    char *f = (char*) fill;
    while (size--)
        *d = *f;
}
int my_strlen(const char* string)
{
    int len;

    len = 0;
    while (string[len])
    {
        len++;
    }
    return 0;
}

void show_grid(int sudoku[9][9])
{
    int h;
    int v;
    int column;
    int x;

    column = 2;
    x = 2;
    v = 0;
    printf("\n");
    while (v < 9)
    {
        h = 0;
        while (h < 9)
        {
            printf("%i ", sudoku[v][h]);
            if (!column--)
            {
                column = 2;
                printf("  ");
            }
            h++;
        }
        printf("\n");
        if (!x--)
        {
            x = 2;
            printf("\n");
        }
        v++;
    }
    printf("#####################\n");
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
    (void) grid_num;
    FILE* file;
    char data[82];
    int count;

    count = 0;
    file = fopen(filepath,"r");
    while (fread(data,sizeof(char),82,file))
    {
        count++;
        if (grid_num == count) {
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
    //sudoku[] = vertical
    //sudoku[][] = horizontal
    int missing;

    int sudoku[9][9] = {
        {7,8,0,3,6,0,0,0,0},
        {0,0,6,0,1,0,9,0,2},
        {0,0,3,4,0,2,6,0,7},
        {8,0,9,5,0,4,2,0,1},
        {0,6,0,9,0,1,0,7,0},
        {1,0,7,2,0,6,8,0,5},
        {5,0,8,6,0,3,7,0,0},
        {3,0,4,0,9,0,5,0,0},
        {0,0,0,0,2,5,0,4,8}
    };
    if (argc > 1)
    {
        printf("loading user grid\n");
        grid_clear(sudoku);
        load_line(sudoku,argv[1]);
    }

    show_grid(sudoku);
    missing = count_missing(sudoku);
    printf("missing: %i\n",missing);

    fill_grid(sudoku,0);

    show_grid(sudoku);
    missing = count_missing(sudoku);
    printf("missing: %i\n",missing);
    return 0;
}

