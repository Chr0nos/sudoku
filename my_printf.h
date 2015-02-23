#ifndef MY_PRINTF
#define MY_PRINTF
#include <stdarg.h>

void my_printf_vars(va_list *args,char *x, int *i, const char* string);
void my_printf(const char* string, ...);

#endif
