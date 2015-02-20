#include <unistd.h>
#include "my_strlen.h"

/*
void my_printf(const char* string)
{
    int i;

    i = 0;
    while (string[i])
    {
        write(STDOUT_FILENO,(const void*) &string[i],1);
        i++;
    }
}
*/

void my_printf(const char* string)
{
    int size;

    size = my_strlen(string);
    write(STDOUT_FILENO, string, size);
}
