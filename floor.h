#ifndef FLOOR_H
#define FLOOR_H

#include "common.h"
#include "textures.h"

enum FLOOR_TYPE
{
    FLOOR_TYPE__NONE,

    FLOOR_TYPE__METAL,
    FLOOR_TYPE__METAL_SPIKES,
    FLOOR_TYPE__METAL_LAVA_CRACK,
    FLOOR_TYPE__LAVA,
    FLOOR_TYPE__ICE,
    FLOOR_TYPE__ICE_WATER_CRACK,
    FLOOR_TYPE__WATER,

    FLOOR_TYPE__COUNT
};

char* get_name_from_floor(int floor);
Texture* get_texture_from_floor_type(int type, Textures* textures);

#endif