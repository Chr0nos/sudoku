#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_itoa.h"

void ft_printf_string(const char *string)
{
    int i;
    int result;

    i = 0;
    while (string[i] != '\0')
    {
        result = putchar(string[i]);
        i++;
    }
    (void) result;
}

void ft_printf_vars(va_list *args, char *x, int *i, const char* string)
{
    char *s;
    int result;
    int v;

    *i += 1;
    *x = string[*i];
    if (*x == 's')
    {
        s = va_arg(*args, char *);
        ft_printf_string(s);
    }
    else if (*x == 'i')
    {
        v = va_arg(*args, int);
        s = malloc(sizeof(char) * 8 + 2);
        ft_itoa(v, s);
        ft_printf_string(s);
        free(s);
        s = NULL;
    }
    else if ((*x == 'x') || (*x == 'b'))
    {
        v = va_arg(*args, int);
        s = malloc(sizeof(char) * 256);
        if (*x == 'x') ft_itobase(v, s, 16);
        else ft_itobase(v, s, 2);
        ft_printf_string(s);
        free(s);
    }
    *i += 1;
    *x = string[*i];
    (void) result;
}

void ft_printf(const char* string, ...)
{
    int i;
    int result;
    char x;
    va_list args;

    va_start(args,string);
    i = 0;
    while (string[i] != '\0')
    {
        x = string[i];
        if (x == '%')
        {
            ft_printf_vars(&args, &x, &i, string);
        }
        result = putchar(string[i]);
        (void) result;
        i++;
    }
    va_end(args);
}
