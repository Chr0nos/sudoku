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

void ft_itobase(unsigned int value, char* s, const unsigned int base)
{
    /*
    ** this function convert a number into an other base
    ** and put the result in *s
    ** dont use a base lower than 2 or the function will set an empty string
    ** valid bases range are: 2 - 62
    ** you have to allocate memory by yourself before calling this
    ** this function cannot convert negative numbers
    */
    int i;
    unsigned int k;
    const char* keys = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYXZ";

    if (!s) return;
    if (base < 2)
    {
        s[0] = '\0';
        return;
    }
    i = 0;
    while (value)
    {
        k = value % base;
        s[i] = keys[k];
        value /= base;
        i++;
    }
    s[i] = '\0';
    ft_strrev(s);
}
