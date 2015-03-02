#include "ft_pow.h"

int ft_basetoi_indexof(const char *s, const char *keys)
{
    int pos;

    pos = 0;
    while (keys[pos])
    {
        if (keys[pos] == *s) return pos;
        pos++;
    }
    return -1;
}

int ft_basetoi(const char *s, const int base)
{
    int result;
    int value;
    int pos;
    const char *keys = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (!s) return -1;
    pos = 0;
    result = 0;
    while (s[pos] != '\0')
    {
        value = ft_basetoi_indexof(&s[pos], keys);
        if (value < 0) return -2;
        result += value * ft_pow(base, pos);
        pos++;
    }
    return result;
}
