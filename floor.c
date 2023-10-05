#include "floor.h"

Texture* get_texture_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR_TYPE__ROCK: texture = textures->floor.rock; break;
        case FLOOR_TYPE__STONE: texture = textures->floor.stone; break;
        case FLOOR_TYPE__METAL: texture = textures->floor.metal; break;
        case FLOOR_TYPE__METAL_SPIKES: texture = textures->floor.metal_spikes; break;
        case FLOOR_TYPE__GRASS: texture = textures->floor.grass; break;
        case FLOOR_TYPE__WATER: texture = textures->floor.water; break;
        case FLOOR_TYPE__LAVA: texture = textures->floor.lava; break;
        default: break;
    }

    return texture;
}