#include <stdlib.h>
#include <stdio.h>
#include "chained_list.h"

st_chained_item* list_append(st_chained_item* parent,const int value)
{
    /*
     ** add a new item to a list, it's ok to use:
     ** st_chained_item* n = list_append(NULL,value)
     ** to get the first item of the list
     */
    st_chained_item *n;

    n = malloc(sizeof(st_chained_item));
    if (!n) exit(1);
    n->next = NULL;
    n->value = value;
    parent->next = n;
    return n;
}

int list_count(st_chained_item* first)
{
    /*
     ** return the size of the chain
     */
    int count;
    st_chained_item* n;

    count = 0;
    n = first;
    while ((n = n->next))
    {
        count++;
    }
    return count;
}

st_chained_item** list_index(st_chained_item* first)
{
    st_chained_item *n;
    st_chained_item **list;
    int size;
    int pos;

    pos = 0;
    size = list_count(first);
    n = first;
    list = malloc(sizeof(st_chained_item*) * (size +1));
    if (!list)
        return NULL;
    while ((n = n->next))
    {
        list[pos] = n;
        pos++;
    }
    list[pos] = NULL;
    return list;
}

void list_free(st_chained_item* first)
{
    /*
     ** this function free the entire chain list
     */
    int pos;
    st_chained_item **list;
    st_chained_item *n;

    pos = 0;
    list = list_index(first);
    while ((n = list[pos++]))
    {
        free(n);
    }
    free(list);
}

void list_show(st_chained_item *first)
{
    st_chained_item *n;
    int count;

    count = 0;
    n = first;
    while (1)
    {
        if (!n) return;
        printf("%i: %i\n",count++,n->value);
        n = n->next;
    }
}
st_chained_item* list_last(st_chained_item *first)
{
    st_chained_item *n;

    n = first;
    while (n->next)
    {
        n = n->next;
    }
    return n;
}
