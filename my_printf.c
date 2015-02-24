#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my_itoa.h"
#include "my_strlen.h"

void my_printf_vars(va_list *args,char *x, int *i, const char* string)
{
    char *s;
    int result;
    int v;

    *x = string[++*i];
    if (*x == 's')
    {
       s = va_arg(*args,char *);
       while (*s != '\0')
       {
           result = write(STDOUT_FILENO,s,1);
            s++;
       }
    }
    else if (*x == 'i')
    {
        v = va_arg(*args,int);
        s = malloc(sizeof(char) * 8 + 2);
        my_itoa(v,s);
        result = write(STDOUT_FILENO,s,my_strlen(s));
        free(s);
        s = NULL;
    }
    *x = string[++*i];
    (void) result;
}

void my_printf(const char* string, ...)
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
            my_printf_vars(&args,&x,&i,string);
        }
        result = write(STDOUT_FILENO,&x,1);
        (void) result;
        i++;
    }
    va_end(args);
}
