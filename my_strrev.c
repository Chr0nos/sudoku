#include "my_strlen.h"

void my_strrev(char *s)
{
    int i;
    int j;
    int size;
    char x;

    size = my_strlen(s) -1;
    i = 0;
    j = size;
    while (i < j)
    {
        x = s[i];
        s[i] = s[j];
        s[j] = x;
        i++;
        j--;
    }
}
