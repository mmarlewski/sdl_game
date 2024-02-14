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
    FLOOR_TYPE__ROCK_CRACK_PIT,

    FLOOR_TYPE__STONE,
    FLOOR_TYPE__STONE_TRAP,
    FLOOR_TYPE__STONE_SPIKES_ON,
    FLOOR_TYPE__STONE_SPIKES_OFF,

    FLOOR_TYPE__METAL,
    FLOOR_TYPE__METAL_HATCH_OPEN,
    FLOOR_TYPE__METAL_HATCH_CLOSED,
    FLOOR_TYPE__METAL_COVER_BOTTOM,
    FLOOR_TYPE__METAL_TARGET_UNCHECKED,
    FLOOR_TYPE__METAL_TARGET_CHECKED,

    FLOOR_TYPE__METAL_PISTON,
    FLOOR_TYPE__METAL_PISTON_CELL,
    FLOOR_TYPE__METAL_PISTON_DYNAMITE,
    FLOOR_TYPE__METAL_PISTON_BARREL,
    FLOOR_TYPE__METAL_NO_PISTON,

    FLOOR_TYPE__GRASS,

    FLOOR_TYPE__PIT,

    FLOOR_TYPE__WATER,
    FLOOR_TYPE__WATER_LILY_POD,
    FLOOR_TYPE__WATER_STALACTITE_FALLEN,

    FLOOR_TYPE__LAVA,
    FLOOR_TYPE__LAVA_STALACTITE_FALLEN,

    FLOOR_TYPE__ICE,
    FLOOR_TYPE__ICE_CRACK_WATER,

    FLOOR_TYPE__STONE_STAIRS_BELOW,
    FLOOR_TYPE__STONE_STAIRS_BELOW_BLOCKED,
    FLOOR_TYPE__STONE_STAIRS_ABOVE_UNPOWERED,
    FLOOR_TYPE__STONE_STAIRS_ABOVE_POWERED,
    FLOOR_TYPE__ROCK_STAIRS_BELOW,
    FLOOR_TYPE__METAL_STAIRS_BELOW_OFF,
    FLOOR_TYPE__METAL_STAIRS_ABOVE_OFF,
    FLOOR_TYPE__METAL_STAIRS_BELOW_ON,
    FLOOR_TYPE__METAL_STAIRS_BELOW,

    FLOOR_TYPE__COUNT
};

int is_floor_exit(int floor);
int is_floor_manipulatable(int floor);
int is_floor_traversable(int floor);
int is_floor_traversable_for_floating(int floor);
int is_floor_traversable_for_flying(int floor);
int is_floor_deadly_on_move(int floor);
int is_floor_deadly_on_move_for_floating(int floor);
int is_floor_deadly_on_move_for_flying(int floor);
int is_floor_deadly_on_drop(int floor);
int is_floor_deadly_on_drop_for_floating(int floor);
int is_floor_deadly_on_drop_for_flying(int floor);

int get_floor_item_type(int floor);
int get_floor_item_count(int floor);
int is_floor_put_item(int floor);

char* get_name_from_floor(int floor);
Texture* get_texture_1_from_floor_type(int type, Textures* textures);
Texture* get_texture_2_from_floor_type(int type, Textures* textures);

#endif
