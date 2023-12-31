#ifndef FLOOR_H
#define FLOOR_H

#include "../inc/common.h"
#include "../inc/textures.h"

enum FLOOR_TYPE
{
    FLOOR_TYPE__NONE,

    FLOOR_TYPE__ROCK,
    FLOOR_TYPE__ROCK_CRACK_WATER,
    FLOOR_TYPE__ROCK_CRACK_LAVA,

    FLOOR_TYPE__STONE,
    FLOOR_TYPE__STONE_SPIKES_ON,
    FLOOR_TYPE__STONE_SPIKES_OFF,

    FLOOR_TYPE__METAL,
    FLOOR_TYPE__METAL_HATCH_OPEN,
    FLOOR_TYPE__METAL_HATCH_CLOSED,
    FLOOR_TYPE__METAL_COVER_BOTTOM,
    FLOOR_TYPE__METAL_PISTON,

    FLOOR_TYPE__GRASS,

    FLOOR_TYPE__WATER,
    FLOOR_TYPE__WATER_STALACTITE_FALLEN,

    FLOOR_TYPE__LAVA,
    FLOOR_TYPE__LAVA_STALACTITE_FALLEN,

    FLOOR_TYPE__ICE,
    FLOOR_TYPE__ICE_CRACK_WATER,

    FLOOR_TYPE__COUNT
};

int is_floor_interactable(int floor);
int is_floor_traversable(int floor);
int is_floor_deadly_on_move(int floor);
int is_floor_deadly_on_drop(int floor);

char* get_name_from_floor(int floor);
Texture* get_texture_1_from_floor_type(int type, Textures* textures);
Texture* get_texture_2_from_floor_type(int type, Textures* textures);

#endif
