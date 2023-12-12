#ifndef ITEM_H
#define ITEM_H

#include "../inc/common.h"

enum Item
{
    ITEM__NONE,

    ITEM__GEMSTONE,
    ITEM__CELL,
    ITEM__DYNAMITE,

    ITEM__COUNT,
};

char* get_name_from_item(int item);

#endif
