#include "my_strlen.h"

void my_strrev(char *s)
{
    int i;
    int j;
    char x;

    i = 0;
    j = my_strlen(s) -1;
    while (i < j)
    {
        x = s[i];
        s[i] = s[j];
        s[j] = x;
        i++;
        j--;
    }
}
