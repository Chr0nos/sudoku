#include <stdlib.h>
#include "my_strrev.h"

void my_itoa(int value, char *s)
{
    int i;
    short negative;

    negative = 0;
    i = 0;
    if (value < 0)
    {
        value *= -1;
        negative = 1;
    }
    s[i++] = value % 10 + '0';
    while ((value /= 10) > 0)
    {
        s[i++] = value % 10 + '0';
    }
    if (negative)
        s[i++] = '-';
    s[i] = '\0';
    my_strrev(s);
}
