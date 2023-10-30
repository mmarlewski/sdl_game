#ifndef FLOOR_H
#define FLOOR_H

#include "../inc/common.h"
#include "../inc/textures.h"

enum FLOOR_TYPE
{
    FLOOR_TYPE__NONE,

    FLOOR_TYPE__METAL,
    FLOOR_TYPE__METAL_NO_SPIKES,
    FLOOR_TYPE__METAL_SPIKES,
    FLOOR_TYPE__METAL_LAVA_CRACK,
    FLOOR_TYPE__LAVA,
    FLOOR_TYPE__ICE,
    FLOOR_TYPE__ICE_WATER_CRACK,
    FLOOR_TYPE__WATER,
    FLOOR_TYPE__HATCH_CLOSED,
    FLOOR_TYPE__HATCH_OPEN,

    FLOOR_TYPE__COUNT
};

int is_floor_interactable(int type);
char* get_name_from_floor(int floor);
Texture* get_texture_1_from_floor_type(int type, Textures* textures);
Texture* get_texture_2_from_floor_type(int type, Textures* textures);

#endif
