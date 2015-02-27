#include <stdlib.h>

void *ft_calloc(unsigned int size)
{
    char *d;

    d = malloc(size);
    if (!d) return NULL;
    while (size)
    {
        d[size] = 0;
        size--;
    }
    return d;
}

