#include <stdlib.h>

char* my_itoa(int value)
{
    char *result;
    int pos;

    pos = 0;
    result = malloc(sizeof(int) * 8);
    if (value < 0)
        result[pos++] = '-';

    result[pos] = '\0';
    return result;
}
