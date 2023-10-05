#include "floor.h"

char* get_name_from_floor(int floor)
{
    char* name = "";

    switch(floor)
    {
        case FLOOR_TYPE__NONE: name = "none"; break;
        case FLOOR_TYPE__METAL: name = "metal"; break;
        case FLOOR_TYPE__METAL_SPIKES: name = "metal spikes"; break;
        case FLOOR_TYPE__METAL_LAVA_CRACK: name = "metal lava crack"; break;
        case FLOOR_TYPE__LAVA: name = "lava"; break;
        case FLOOR_TYPE__ICE: name = "ice"; break;
        case FLOOR_TYPE__ICE_WATER_CRACK: name = "ice water crack"; break;
        case FLOOR_TYPE__WATER: name = "water"; break;
        default: break;
    }

    return name;
}

Texture* get_texture_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR_TYPE__NONE: texture = 0; break;
        case FLOOR_TYPE__METAL: texture = textures->floor.metal; break;
        case FLOOR_TYPE__METAL_SPIKES: texture = textures->floor.metal_spikes; break;
        case FLOOR_TYPE__METAL_LAVA_CRACK: texture = textures->floor.metal_lava_crack; break;
        case FLOOR_TYPE__LAVA: texture = textures->floor.lava; break;
        case FLOOR_TYPE__ICE: texture = textures->floor.ice; break;
        case FLOOR_TYPE__ICE_WATER_CRACK: texture = textures->floor.ice_water_crack; break;
        case FLOOR_TYPE__WATER: texture = textures->floor.water; break;
        default: break;
    }

    return texture;
}