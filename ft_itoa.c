#include <stdlib.h>
#include "ft_strrev.h"

void ft_itoa(int value, char *s)
{
    /*
    ** this function convert a number into a char* string
    ** the number can be positive or negative
    ** you need to allocate memory by yourself before calling this
    */
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
    ft_strrev(s);
}

char *ft_itobase(unsigned int value, char *s, const unsigned char base)
{
    /*
    ** this function convert a number into an other base
    ** and put the result in *s
    ** dont use a base lower than 2 or the function will set an empty string
    ** valid bases range are: 2 - 62
    ** you can allocate memory by yourself before calling this
    ** if you wont: use ft_itobase(value, 0, base); (0 for null pointer) will auto alocate
    ** this function cannot convert negative numbers
    */
    int i;
    const char *keys = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYXZ";

    if (!s)
    {
        s = malloc(33);
        if (!s) return 0;
    }
    if ((base < 2) || (base > 62))
    {
        s[0] = '\0';
        return s;
    }
    i = 0;
    while (value)
    {
        s[i] = keys[value % base];
        value /= base;
        i++;
    }
    s[i] = '\0';
    ft_strrev(s);
    return s;
}
