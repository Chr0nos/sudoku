#include "ft_strcpy.h"
#include "my_strrev.h"

void ft_itohex(int value, char* s)
{
    int i;
    int k;
    const char* keys = "0123456789abcdef";

    i = 0;
    while (value)
    {
        value /= 16;
        k = value % 16;
        s[i] = keys[k];
        i++;
    }
    s[i] = '\0';
    my_strrev(s);
}
