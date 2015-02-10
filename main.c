#include <stdio.h>
#include <stdbool.h>

void my_memset(void *dest,size_t size, void *fill)
{
    char *d = (char*) dest;
    char *f = (char*) fill;
    while (size--)
        *d = *f;
}
void show_grid(int sudoku[9][9])
{
    int h;
    int v;
    int colone;
    int x;

    colone = 2;
    x = 2;
    v = 0;
    printf("\n");
    while (v < 9)
    {
        h = 0;
        while (h < 9)
        {
            printf("%i ", sudoku[v][h]);
            if (!colone--)
            {
                colone = 2;
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
                return false;
        vl++;
        }
    hl++;
    }
    return true;
}

bool check_line(int sudoku[9][9], int v, int k)
{
    int i;

    i = 9;
    while (i--)
    {
        if (sudoku[v][i] == k)
            return false;
    }
    return true;
}

bool check_colone(int sudoku[9][9], int h, int k)
{
    /* cette fonction compte le nombre de "value" sur toute la ligne et renvoi le résultat */
    int p;

    p = 9;
    while (p--)
    {
        if (sudoku[p][h] == k)
            return false;
    }
    return true;
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
bool check_all(int sudoku[9][9], int v, int h, int k)
{
    if (check_line(sudoku, v, k)) return true;
    if (check_colone(sudoku, h, k)) return true;
    if (check_block(sudoku, v, h, k)) return true;
    return false;
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
    printf("pos: %i\n",position);

    if (sudoku[v][h])
        return fill_grid(sudoku,position+1);

    while (k <= 9)
    {
        if (!check_all(sudoku, v, h, k))
        {
            sudoku[v][h] = k;
            printf("confirmed -> %i:%i x:%i\n", v, h,sudoku[v][h]);
            if (fill_grid(sudoku,position +1))
                return true;
        }
        k++;
    }
    printf("failed on %i:%i\n",v,h);
    sudoku[v][h] = 0;
    return false;
}

int main(void)
{
    /* sudoku contiens un array d'entier représentant les cases
     * 0 = une case vide
     * 1 à 9 une case pleine
     *
     * A A A B B B C C C
     * A A A B B B C C C
     * A A A B B B C C C
     * D D D E E E F F F
     * D D D E E E F F F
     * D D D E E E F F F
     * G G G H H H I I I
     * G G G H H H I I I
     * G G G H H H I I I
     */

    //un bon vieux tableau à deux dimentions
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

    show_grid(sudoku);
    missing = count_missing(sudoku);
    printf("missing: %i\n",missing);

    fill_grid(sudoku,0);

    show_grid(sudoku);
    missing = count_missing(sudoku);
    printf("missing: %i\n",missing);
    return 0;
}

