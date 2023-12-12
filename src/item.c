#include "../inc/item.h"

char* get_name_from_item(int item)
{
    char* name = "";

    switch(item)
    {
        case ITEM__GEMSTONE:        name = "gemstone"; break;
        case ITEM__CELL:            name = "cell"; break;
        case ITEM__DYNAMITE:        name = "dynamite"; break;
        default: break;
    }

    return name;
}
