#ifndef FLOOR_H
#define FLOOR_H

#include "../inc/common.h"
#include "../inc/textures.h"

enum FLOOR_TYPE
{
    FLOOR__NONE,

    FLOOR__ROCK,
    FLOOR__ROCK_CRACK_WATER,
    FLOOR__ROCK_CRACK_LAVA,
    FLOOR__ROCK_CRACK_PIT,

    FLOOR__STONE,
    FLOOR__STONE_TRAP,

    FLOOR__METAL,
    FLOOR__METAL_SPIKES_ON,
    FLOOR__METAL_SPIKES_OFF,
    FLOOR__METAL_HATCH_OPEN,
    FLOOR__METAL_HATCH_CLOSED,
    FLOOR__METAL_COVER_BOTTOM,
    FLOOR__METAL_TARGET_UNCHECKED,
    FLOOR__METAL_TARGET_CHECKED,

    FLOOR__METAL_PISTON,
    FLOOR__METAL_PISTON_CELL,
    FLOOR__METAL_PISTON_DYNAMITE,
    FLOOR__METAL_PISTON_BARREL,
    FLOOR__METAL_PISTON_MIMIC,
    FLOOR__METAL_NO_PISTON,

    FLOOR__GOLD,
    FLOOR__GOLD_TRAP,

    FLOOR__MARBLE,

    FLOOR__OBSIDIAN,

    FLOOR__GRASS,

    FLOOR__SAND,

    FLOOR__COINS,

    FLOOR__PIT,
    FLOOR__PIT_COLUMN,

    FLOOR__WATER,
    FLOOR__WATER_LILY_POD,
    FLOOR__WATER_STALACTITE_FALLEN,
    FLOOR__WATER_COLUMN,

    FLOOR__LAVA,
    FLOOR__LAVA_STALACTITE_FALLEN,
    FLOOR__LAVA_COLUMN,

    FLOOR__ICE,
    FLOOR__ICE_CRACK_WATER,

    FLOOR__OBSTACLE,

    FLOOR__CONV_BELT_UP,
    FLOOR__CONV_BELT_RIGHT,
    FLOOR__CONV_BELT_DOWN,
    FLOOR__CONV_BELT_LEFT,

    FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL,
    FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL,
    FLOOR__EXT_BRIDGE_PART_HORIZONTAL,
    FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL,
    FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL,
    FLOOR__EXT_BRIDGE_PART_VERTICAL,

    FLOOR__STONE_STAIRS_BELOW,
    FLOOR__STONE_STAIRS_BELOW_BLOCKED,
    FLOOR__STONE_STAIRS_ABOVE_UNPOWERED,
    FLOOR__STONE_STAIRS_ABOVE_POWERED,
    FLOOR__ROCK_STAIRS_BELOW,
    FLOOR__METAL_STAIRS_BELOW_OFF,
    FLOOR__METAL_STAIRS_ABOVE_OFF,
    FLOOR__METAL_STAIRS_BELOW_ON,
    FLOOR__METAL_STAIRS_BELOW,

    FLOOR__COUNT
};

int is_floor_exit(int floor);
int is_floor_manipulatable(int floor);
int is_floor_burrow(int floor);
int is_floor_stomp(int floor);
int is_floor_meltable(int floor);
int is_floor_breakable(int floor);
int is_floor_fragile(int floor);
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

char* get_in_game_name_from_floor(int floor);
char* get_debug_name_from_floor(int floor);
Texture* get_texture_1_from_floor_type(int type, Textures* textures);
Texture* get_texture_2_from_floor_type(int type, Textures* textures);

#endif
