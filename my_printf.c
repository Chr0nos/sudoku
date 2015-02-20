#include <unistd.h>

char my_printf_replace_ascii(char *x)
{
    if (*x == 'n') return 10;
    else if (*x == 'r') return 13;
    else if (*x == '\\') return '\\';
    return *x;
}

void my_printf(const char* string)
{
    int i;
    int result;
    char x;

    i = 0;
    while (string[i])
    {
        x = string[i];
        if (x == '\\')
        {
            x = string[i+1];
            x = my_printf_replace_ascii(&x);
            i++;
        }
        result = write(STDOUT_FILENO,(const void*) &x,1);
        (void) result;
        i++;
    }
}
