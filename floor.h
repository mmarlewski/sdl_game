#ifndef FLOOR_H
#define FLOOR_H

#include "common.h"
#include "textures.h"

enum FLOOR_TYPE
{
    FLOOR_TYPE__ROCK,
    FLOOR_TYPE__STONE,
    FLOOR_TYPE__METAL,
    FLOOR_TYPE__GRASS,
    FLOOR_TYPE__WATER,
    FLOOR_TYPE__LAVA,

    FLOOR_TYPE__COUNT
};

Texture* get_texture_from_floor_type(int type, Textures* textures);

#endif