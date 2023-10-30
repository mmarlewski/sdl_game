#include "../inc/floor.h"

int is_floor_interactable(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR_TYPE__NONE: is = 0; break;
        case FLOOR_TYPE__METAL: is = 0; break;
        case FLOOR_TYPE__METAL_NO_SPIKES: is = 1; break;
        case FLOOR_TYPE__METAL_SPIKES: is = 1; break;
        case FLOOR_TYPE__METAL_LAVA_CRACK: is = 0; break;
        case FLOOR_TYPE__LAVA: is = 0; break;
        case FLOOR_TYPE__ICE: is = 0; break;
        case FLOOR_TYPE__ICE_WATER_CRACK: is = 0; break;
        case FLOOR_TYPE__WATER: is = 0; break;
        case FLOOR_TYPE__HATCH_CLOSED: is = 1; break;
        case FLOOR_TYPE__HATCH_OPEN: is = 1; break;
        default: break;
    }

    return is;
}

char* get_name_from_floor(int floor)
{
    char* name = "";

    switch(floor)
    {
        case FLOOR_TYPE__NONE: name = "none"; break;
        case FLOOR_TYPE__METAL: name = "metal"; break;
        case FLOOR_TYPE__METAL_NO_SPIKES: name = "metal no spikes"; break;
        case FLOOR_TYPE__METAL_SPIKES: name = "metal spikes"; break;
        case FLOOR_TYPE__METAL_LAVA_CRACK: name = "metal lava crack"; break;
        case FLOOR_TYPE__LAVA: name = "lava"; break;
        case FLOOR_TYPE__ICE: name = "ice"; break;
        case FLOOR_TYPE__ICE_WATER_CRACK: name = "ice water crack"; break;
        case FLOOR_TYPE__WATER: name = "water"; break;
        case FLOOR_TYPE__HATCH_CLOSED: name = "hatch closed"; break;
        case FLOOR_TYPE__HATCH_OPEN: name = "hatch open"; break;
        default: break;
    }

    return name;
}

Texture* get_texture_1_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR_TYPE__NONE: texture = 0; break;
        case FLOOR_TYPE__METAL: texture = textures->floor.metal; break;
        case FLOOR_TYPE__METAL_NO_SPIKES: texture = textures->floor.metal_no_spikes; break;
        case FLOOR_TYPE__METAL_SPIKES: texture = textures->floor.metal_spikes; break;
        case FLOOR_TYPE__METAL_LAVA_CRACK: texture = textures->floor.metal_lava_crack; break;
        case FLOOR_TYPE__LAVA: texture = textures->floor.lava_1; break;
        case FLOOR_TYPE__ICE: texture = textures->floor.ice; break;
        case FLOOR_TYPE__ICE_WATER_CRACK: texture = textures->floor.ice_water_crack; break;
        case FLOOR_TYPE__WATER: texture = textures->floor.water_1; break;
        case FLOOR_TYPE__HATCH_CLOSED: texture = textures->floor.hatch_closed; break;
        case FLOOR_TYPE__HATCH_OPEN: texture = textures->floor.hatch_open_1; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_2_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR_TYPE__NONE: texture = 0; break;
        case FLOOR_TYPE__METAL: texture = textures->floor.metal; break;
        case FLOOR_TYPE__METAL_NO_SPIKES: texture = textures->floor.metal_no_spikes; break;
        case FLOOR_TYPE__METAL_SPIKES: texture = textures->floor.metal_spikes; break;
        case FLOOR_TYPE__METAL_LAVA_CRACK: texture = textures->floor.metal_lava_crack; break;
        case FLOOR_TYPE__LAVA: texture = textures->floor.lava_2; break;
        case FLOOR_TYPE__ICE: texture = textures->floor.ice; break;
        case FLOOR_TYPE__ICE_WATER_CRACK: texture = textures->floor.ice_water_crack; break;
        case FLOOR_TYPE__WATER: texture = textures->floor.water_2; break;
        case FLOOR_TYPE__HATCH_CLOSED: texture = textures->floor.hatch_closed; break;
        case FLOOR_TYPE__HATCH_OPEN: texture = textures->floor.hatch_open_2; break;
        default: break;
    }

    return texture;
}
