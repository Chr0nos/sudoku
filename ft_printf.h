#ifndef FT_PRINTF
#define FT_PRINTF
#include <stdarg.h>

void ft_printf_string(const char *string);
void ft_printf_vars(va_list *args,char *x, int *i, const char* string);
void ft_printf(const char* string, ...);

#endif
