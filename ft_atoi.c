#include "ft_strlen.h"
#include "ft_pow.h"

int ft_atoi(const char* string)
{
    int pos;
    int result;
    int len;

    pos = 0;
    result = 0;
    len = ft_strlen(string);
    while (string[pos] != '\0')
    {
        result += (string[pos] - '0') * ft_pow(10, len - pos -1);
        pos++;
    }
    return result;
}
