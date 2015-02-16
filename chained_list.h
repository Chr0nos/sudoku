#ifndef CHAINED_LIST

#include <stdlib.h>

#define CHAINED_LIST

typedef struct s_chained_item s_chained_item;
struct s_chained_item
{
    unsigned short value;
    s_chained_item *next;
};
s_chained_item* append(s_chained_item* parent,const int value);
int list_count(s_chained_item* first);
void list_free(s_chained_item *first);
s_chained_item** list_index(s_chained_item* first);
void list_show(s_chained_item *first);
s_chained_item* list_last(s_chained_item* first);

#endif
