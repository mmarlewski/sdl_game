#include "../inc/floor.h"

int is_floor_interactable(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR_TYPE__NONE:                      is = 0; break;
        case FLOOR_TYPE__ROCK:                      is = 0; break;
        case FLOOR_TYPE__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR_TYPE__STONE:                     is = 0; break;
        case FLOOR_TYPE__STONE_SPIKES_ON:           is = 1; break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:          is = 1; break;
        case FLOOR_TYPE__METAL:                     is = 0; break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:        is = 1; break;
        case FLOOR_TYPE__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR_TYPE__METAL_PISTON:              is = 1; break;
        case FLOOR_TYPE__GRASS:                     is = 0; break;
        case FLOOR_TYPE__WATER:                     is = 0; break;
        case FLOOR_TYPE__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR_TYPE__LAVA:                      is = 0; break;
        case FLOOR_TYPE__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR_TYPE__ICE:                       is = 0; break;
        case FLOOR_TYPE__ICE_CRACK_WATER:           is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_traversable(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR_TYPE__NONE:                      is = 0; break;
        case FLOOR_TYPE__ROCK:                      is = 1; break;
        case FLOOR_TYPE__ROCK_CRACK_WATER:          is = 1; break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:           is = 1; break;
        case FLOOR_TYPE__STONE:                     is = 1; break;
        case FLOOR_TYPE__STONE_SPIKES_ON:           is = 0; break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:          is = 1; break;
        case FLOOR_TYPE__METAL:                     is = 1; break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:          is = 0; break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:        is = 1; break;
        case FLOOR_TYPE__METAL_COVER_BOTTOM:        is = 1; break;
        case FLOOR_TYPE__METAL_PISTON:              is = 1; break;
        case FLOOR_TYPE__GRASS:                     is = 1; break;
        case FLOOR_TYPE__WATER:                     is = 0; break;
        case FLOOR_TYPE__WATER_STALACTITE_FALLEN:   is = 1; break;
        case FLOOR_TYPE__LAVA:                      is = 0; break;
        case FLOOR_TYPE__LAVA_STALACTITE_FALLEN:    is = 1; break;
        case FLOOR_TYPE__ICE:                       is = 1; break;
        case FLOOR_TYPE__ICE_CRACK_WATER:           is = 1; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_move(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR_TYPE__NONE:                      is = 0; break;
        case FLOOR_TYPE__ROCK:                      is = 0; break;
        case FLOOR_TYPE__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR_TYPE__STONE:                     is = 0; break;
        case FLOOR_TYPE__STONE_SPIKES_ON:           is = 1; break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:          is = 0; break;
        case FLOOR_TYPE__METAL:                     is = 0; break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR_TYPE__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR_TYPE__METAL_PISTON:              is = 0; break;
        case FLOOR_TYPE__GRASS:                     is = 0; break;
        case FLOOR_TYPE__WATER:                     is = 1; break;
        case FLOOR_TYPE__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR_TYPE__LAVA:                      is = 1; break;
        case FLOOR_TYPE__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR_TYPE__ICE:                       is = 0; break;
        case FLOOR_TYPE__ICE_CRACK_WATER:           is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_drop(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR_TYPE__NONE:                      is = 0; break;
        case FLOOR_TYPE__ROCK:                      is = 0; break;
        case FLOOR_TYPE__ROCK_CRACK_WATER:          is = 1; break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:           is = 1; break;
        case FLOOR_TYPE__STONE:                     is = 0; break;
        case FLOOR_TYPE__STONE_SPIKES_ON:           is = 1; break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:          is = 0; break;
        case FLOOR_TYPE__METAL:                     is = 0; break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR_TYPE__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR_TYPE__METAL_PISTON:              is = 0; break;
        case FLOOR_TYPE__GRASS:                     is = 0; break;
        case FLOOR_TYPE__WATER:                     is = 1; break;
        case FLOOR_TYPE__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR_TYPE__LAVA:                      is = 1; break;
        case FLOOR_TYPE__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR_TYPE__ICE:                       is = 0; break;
        case FLOOR_TYPE__ICE_CRACK_WATER:           is = 1; break;
        default: break;
    }

    return is;
}

char* get_name_from_floor(int floor)
{
    char* name = "";

    switch(floor)
    {
        case FLOOR_TYPE__NONE:                      name = "none"; break;
        case FLOOR_TYPE__ROCK:                      name = "rock"; break;
        case FLOOR_TYPE__ROCK_CRACK_WATER:          name = "rock crack water"; break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:           name = "rock crack lava"; break;
        case FLOOR_TYPE__STONE:                     name = "stone"; break;
        case FLOOR_TYPE__STONE_SPIKES_ON:           name = "stone spikes on"; break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:          name = "stone spikes off"; break;
        case FLOOR_TYPE__METAL:                     name = "metal"; break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:          name = "metal hatch open"; break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:        name = "metal hatch closed"; break;
        case FLOOR_TYPE__METAL_COVER_BOTTOM:        name = "metal cover bottom"; break;
        case FLOOR_TYPE__METAL_PISTON:              name = "metal piston"; break;
        case FLOOR_TYPE__GRASS:                     name = "grass"; break;
        case FLOOR_TYPE__WATER:                     name = "water"; break;
        case FLOOR_TYPE__WATER_STALACTITE_FALLEN:   name = "water stalactite fallen"; break;
        case FLOOR_TYPE__LAVA:                      name = "lava"; break;
        case FLOOR_TYPE__LAVA_STALACTITE_FALLEN:    name = "lava stalactite fallen"; break;
        case FLOOR_TYPE__ICE:                       name = "ice"; break;
        case FLOOR_TYPE__ICE_CRACK_WATER:           name = "ice crack water"; break;
        default: break;
    }

    return name;
}

Texture* get_texture_1_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR_TYPE__NONE:                      texture = 0; break;
        case FLOOR_TYPE__ROCK:                      texture = textures->floor.rock; break;
        case FLOOR_TYPE__ROCK_CRACK_WATER:          texture = textures->floor.rock_crack_water; break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:           texture = textures->floor.rock_crack_lava; break;
        case FLOOR_TYPE__STONE:                     texture = textures->floor.stone; break;
        case FLOOR_TYPE__STONE_SPIKES_ON:           texture = textures->floor.stone_spikes_on; break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:          texture = textures->floor.stone_spikes_off; break;
        case FLOOR_TYPE__METAL:                     texture = textures->floor.metal; break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:          texture = textures->floor.metal_hatch_open_1; break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:        texture = textures->floor.metal_hatch_closed; break;
        case FLOOR_TYPE__METAL_COVER_BOTTOM:        texture = textures->floor.metal_cover_bottom; break;
        case FLOOR_TYPE__METAL_PISTON:              texture = textures->floor.metal_piston; break;
        case FLOOR_TYPE__GRASS:                     texture = textures->floor.grass; break;
        case FLOOR_TYPE__WATER:                     texture = textures->floor.water_1; break;
        case FLOOR_TYPE__WATER_STALACTITE_FALLEN:   texture = textures->floor.water_stalactite_fallen_1; break;
        case FLOOR_TYPE__LAVA:                      texture = textures->floor.lava_1; break;
        case FLOOR_TYPE__LAVA_STALACTITE_FALLEN:    texture = textures->floor.lava_stalactite_fallen_1; break;
        case FLOOR_TYPE__ICE:                       texture = textures->floor.ice; break;
        case FLOOR_TYPE__ICE_CRACK_WATER:           texture = textures->floor.ice_crack_water; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_2_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR_TYPE__NONE:                      texture = 0; break;
        case FLOOR_TYPE__ROCK:                      texture = textures->floor.rock; break;
        case FLOOR_TYPE__ROCK_CRACK_WATER:          texture = textures->floor.rock_crack_water; break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:           texture = textures->floor.rock_crack_lava; break;
        case FLOOR_TYPE__STONE:                     texture = textures->floor.stone; break;
        case FLOOR_TYPE__STONE_SPIKES_ON:           texture = textures->floor.stone_spikes_on; break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:          texture = textures->floor.stone_spikes_off; break;
        case FLOOR_TYPE__METAL:                     texture = textures->floor.metal; break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:          texture = textures->floor.metal_hatch_open_1; break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:        texture = textures->floor.metal_hatch_closed; break;
        case FLOOR_TYPE__METAL_COVER_BOTTOM:        texture = textures->floor.metal_cover_bottom; break;
        case FLOOR_TYPE__METAL_PISTON:              texture = textures->floor.metal_piston; break;
        case FLOOR_TYPE__GRASS:                     texture = textures->floor.grass; break;
        case FLOOR_TYPE__WATER:                     texture = textures->floor.water_2; break;
        case FLOOR_TYPE__WATER_STALACTITE_FALLEN:   texture = textures->floor.water_stalactite_fallen_2; break;
        case FLOOR_TYPE__LAVA:                      texture = textures->floor.lava_2; break;
        case FLOOR_TYPE__LAVA_STALACTITE_FALLEN:    texture = textures->floor.lava_stalactite_fallen_2; break;
        case FLOOR_TYPE__ICE:                       texture = textures->floor.ice; break;
        case FLOOR_TYPE__ICE_CRACK_WATER:           texture = textures->floor.ice_crack_water; break;
        default: break;
    }

    return texture;
}
