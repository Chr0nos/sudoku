#include "../ft_printf.h"
#include "chained_list.h"
#include <stdio.h>

s_chained_item* list_append_string(s_chained_item* parent, const char *string)
{
    /*
    ** this method append a string into a chained list
    ** example: s_chained_item *string = list_append_string(0, "my test string");
    ** each char will be set into an "int" named "value"
    */
    s_chained_item *n;
    s_chained_item *last;
    int pos;

    n = 0;
    pos = 0;
    last = parent;
    while (string[pos] != '\0')
    {
        n = list_append(last, string[pos]);
        last = n;
        pos++;
    }
    return n;
}

void list_show_string(s_chained_item *first, int lenght)
{
    /*
    ** show a string value like printf but with the chained_item format
    */
    s_chained_item *n;

    n = first;
    while ((lenght--) && (n->next) && (n->value))
    {
        putchar(n->value);
        n = n->next;
    }
    putchar('\n');
}
