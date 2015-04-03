#ifndef CHAINED_LIST_STRING_H
#define CHAINED_LIST_STRING_H

#include "chained_list.h"

s_chained_item* list_append_string(s_chained_item* parent, const char *string);
void list_show_string(s_chained_item *first, int lenght);

#endif
