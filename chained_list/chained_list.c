#include <stdlib.h>
#include <stdio.h>
#include "chained_list.h"
#include "../ft_printf.h"

s_chained_item* list_append(s_chained_item* parent, const int value)
{
    /*
     ** add a new item to a list, it's ok to use:
     ** st_chained_item* n = list_append(NULL,value)
     ** to get the first item of the list
     */
    s_chained_item *n;

    n = malloc(sizeof(s_chained_item));
    if (!n)
    {
        ft_printf_string("cannot allocate memory for list_append: exiting\n");
        exit(1);
    }
    n->next = NULL;
    n->value = value;
    parent->next = n;
    return n;
}

int list_count(s_chained_item* first)
{
    /*
     ** return the size of the chain
     */
    int count;
    s_chained_item* n;

    count = 0;
    n = first;
    while (n->next)
    {
        n = n->next;
        count++;
    }
    return count;
}

s_chained_item** list_index(s_chained_item *first)
{
    s_chained_item *n;
    s_chained_item **list;
    int size;
    int pos;

    pos = 0;
    size = list_count(first);
    n = first;
    list = malloc(sizeof(s_chained_item*) * (size +1));
    if (!list)
        return NULL;
    while (n->next)
    {
        list[pos] = n;
        pos++;
        n = n->next;
    }
    list[pos] = NULL;
    return list;
}

void list_free(s_chained_item* first)
{
    /*
     ** this function free the entire chain list
     */
    s_chained_item *n;
    s_chained_item *next;

    n = first;
    while (n)
    {
        next = n->next;
        free(n);
        n = next;
    }
}

void list_show(s_chained_item *first)
{
    s_chained_item *n;
    int count;

    count = 0;
    n = first;
    while (n->next)
    {
        ft_printf("%i: %i\n", count, n->value);
        n = n->next;
        count++;
    }
}
s_chained_item* list_last(s_chained_item *first)
{
    /*
    ** return the last item of a chained list
    ** "first" dont need to be the real first item, it just need
    ** to be an item of the list
    */
    s_chained_item *n;

    n = first;
    while (n->next)
    {
        n = n->next;
    }
    return n;
}

s_chained_item* ft_list_get_parent(s_chained_item *item)
{
    /*
    ** return the parent of item
    ** if "item" has no parent: NULL will be returned
    */
    s_chained_item *n;
    s_chained_item *s;

    s = item;
    n = item;
    while (n->next)
    {
        if (s == n->next) return n;
        n = n->next;
    }
    return NULL;
}
