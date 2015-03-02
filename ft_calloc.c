#include <stdlib.h>
#include "ft_memset.h"

void *ft_calloc(unsigned int size)
{
    char *d;

    d = malloc(size);
    if (!d) return NULL;
    return ft_memset(d, 0, size);
}

