#include <stdlib.h>
#include "ft_strcpy.h"
#include "my_strrev.h"

void ft_itohex(int value, char* s)
{
    int i;
    int k;
    char *keys;

    keys = malloc(sizeof(char) * 17);
    keys = ft_strcpy(keys,"0123456789abcdef\0");
    i = 0;
    k = value % 16;
    s[i++] = keys[k];
    while ((value /= 16) > 0)
    {
        k = value % 16;
        s[i++] = keys[k];
    }
    free(keys);
    s[i] = '\0';
    my_strrev(s);
}
