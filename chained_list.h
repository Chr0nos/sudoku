#ifndef CHAINED_LIST

#include <stdlib.h>

#define CHAINED_LIST

typedef struct st_chained_item st_chained_item;
struct st_chained_item
{
    unsigned short value;
    st_chained_item *next;
};
st_chained_item* append(st_chained_item* parent,const int value);
int list_count(st_chained_item* first);
void list_free(st_chained_item* first);
st_chained_item** list_index(st_chained_item* first);
void list_show(st_chained_item *first);
st_chained_item* list_last(st_chained_item* first);

#endif
