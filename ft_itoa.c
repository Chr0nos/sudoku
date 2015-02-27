#include "ft_strrev.h"

void ft_itoa(int value, char *s)
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
    ft_strrev(s);
}

void ft_itobase(int value, char* s, const int base)
{
    int i;
    int k;
    const char* keys = "0123456789abcdef";

    i = 0;
    while (value)
    {
        k = value % base;
        s[i] = keys[k];
        value /= base;
        i++;
    }
    if (i % 2 > 0)
    {
        s[i] = keys[0];
        i++;
    }
    s[i] = '\0';
    ft_strrev(s);
}

