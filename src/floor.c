#include "../inc/floor.h"
#include "../inc/item.h"

int is_floor_exit(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__STONE_STAIRS_BELOW:            is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 1; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 1; break;
        default: break;
    }

    return is;
}

int is_floor_manipulatable(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__METAL_SPIKES_ON:           is = 1; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 1; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 1; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 1; break;
        case FLOOR__METAL_PISTON_CELL:         is = 1; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 1; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 1; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__WATER:                     is = 0; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:    is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:   is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_HORIZONTAL:         is = 0; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:      is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:     is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_VERTICAL:           is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_burrow(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__SAND:       is = 1; break;
        case FLOOR__COINS:      is = 1; break;
        default: break;
    }

    return is;
}

int is_floor_traversable(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 1; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 1; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 1; break;
        case FLOOR__ROCK_CRACK_PIT:            is = 1; break;
        case FLOOR__STONE:                     is = 1; break;
        case FLOOR__STONE_TRAP:                is = 0; break;
        case FLOOR__METAL_SPIKES_ON:           is = 0; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 1; break;
        case FLOOR__METAL:                     is = 1; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 0; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 1; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 1; break;
        case FLOOR__METAL_TARGET_UNCHECKED:    is = 1; break;
        case FLOOR__METAL_TARGET_CHECKED:      is = 1; break;
        case FLOOR__METAL_PISTON:              is = 1; break;
        case FLOOR__METAL_PISTON_CELL:         is = 1; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 1; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 1; break;
        case FLOOR__METAL_NO_PISTON:           is = 1; break;
        case FLOOR__GOLD:                      is = 1; break;
        case FLOOR__MARBLE:                    is = 1; break;
        case FLOOR__OBSIDIAN:                  is = 1; break;
        case FLOOR__GRASS:                     is = 1; break;
        case FLOOR__SAND:                      is = 1; break;
        case FLOOR__COINS:                     is = 1; break;
        case FLOOR__PIT:                       is = 0; break;
        case FLOOR__WATER:                     is = 0; break;
        case FLOOR__WATER_LILY_POD:            is = 1; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 1; break;
        case FLOOR__LAVA:                      is = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 1; break;
        case FLOOR__ICE:                       is = 1; break;
        case FLOOR__ICE_CRACK_WATER:           is = 1; break;
        case FLOOR__OBSTACLE:                  is = 1; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 1; break;
        case FLOOR__STONE_STAIRS_BELOW_BLOCKED:is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 1; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:    is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:   is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_HORIZONTAL:         is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:      is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:     is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_VERTICAL:           is = 1; break;
        default: break;
    }

    return is;
}

int is_floor_traversable_for_floating(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 1; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 1; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 1; break;
        case FLOOR__ROCK_CRACK_PIT:            is = 1; break;
        case FLOOR__STONE:                     is = 1; break;
        case FLOOR__STONE_TRAP:                is = 0; break;
        case FLOOR__METAL_SPIKES_ON:           is = 0; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 1; break;
        case FLOOR__METAL:                     is = 1; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 1; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 1; break;
        case FLOOR__METAL_TARGET_UNCHECKED:    is = 1; break;
        case FLOOR__METAL_TARGET_CHECKED:      is = 1; break;
        case FLOOR__METAL_PISTON:              is = 1; break;
        case FLOOR__METAL_PISTON_CELL:         is = 1; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 1; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 1; break;
        case FLOOR__METAL_NO_PISTON:           is = 1; break;
        case FLOOR__GOLD:                      is = 1; break;
        case FLOOR__MARBLE:                    is = 1; break;
        case FLOOR__OBSIDIAN:                  is = 1; break;
        case FLOOR__GRASS:                     is = 1; break;
        case FLOOR__SAND:                      is = 1; break;
        case FLOOR__COINS:                     is = 1; break;
        case FLOOR__PIT:                       is = 0; break;
        case FLOOR__WATER:                     is = 1; break;
        case FLOOR__WATER_LILY_POD:            is = 1; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 1; break;
        case FLOOR__LAVA:                      is = 1; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 1; break;
        case FLOOR__ICE:                       is = 1; break;
        case FLOOR__ICE_CRACK_WATER:           is = 1; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 1; break;
        case FLOOR__STONE_STAIRS_BELOW_BLOCKED:is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 1; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:    is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:   is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_HORIZONTAL:         is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:      is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:     is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_VERTICAL:           is = 1; break;
        default: break;
    }

    return is;
}

int is_floor_traversable_for_flying(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 1; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 1; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 1; break;
        case FLOOR__ROCK_CRACK_PIT:            is = 1; break;
        case FLOOR__STONE:                     is = 1; break;
        case FLOOR__STONE_TRAP:                is = 1; break;
        case FLOOR__METAL_SPIKES_ON:           is = 1; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 1; break;
        case FLOOR__METAL:                     is = 1; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 1; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 1; break;
        case FLOOR__METAL_TARGET_UNCHECKED:    is = 1; break;
        case FLOOR__METAL_TARGET_CHECKED:      is = 1; break;
        case FLOOR__METAL_PISTON:              is = 1; break;
        case FLOOR__METAL_PISTON_CELL:         is = 1; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 1; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 1; break;
        case FLOOR__METAL_NO_PISTON:           is = 1; break;
        case FLOOR__GOLD:                      is = 1; break;
        case FLOOR__MARBLE:                    is = 1; break;
        case FLOOR__OBSIDIAN:                  is = 1; break;
        case FLOOR__GRASS:                     is = 1; break;
        case FLOOR__SAND:                      is = 1; break;
        case FLOOR__COINS:                     is = 1; break;
        case FLOOR__PIT:                       is = 1; break;
        case FLOOR__WATER:                     is = 1; break;
        case FLOOR__WATER_LILY_POD:            is = 1; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 1; break;
        case FLOOR__LAVA:                      is = 1; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 1; break;
        case FLOOR__ICE:                       is = 1; break;
        case FLOOR__ICE_CRACK_WATER:           is = 1; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 1; break;
        case FLOOR__STONE_STAIRS_BELOW_BLOCKED:is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 1; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 1; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:    is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:   is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_HORIZONTAL:         is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:      is = 1; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:     is = 1; break;
        case FLOOR__EXT_BRIDGE_PART_VERTICAL:           is = 1; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_move(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__STONE_TRAP:                is = 1; break;
        case FLOOR__METAL_SPIKES_ON:           is = 1; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 0; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 0; break;
        case FLOOR__METAL_PISTON_CELL:         is = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 0; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__PIT:                       is = 1; break;
        case FLOOR__WATER:                     is = 1; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 1; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_move_for_floating(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__STONE_TRAP:                is = 1; break;
        case FLOOR__METAL_SPIKES_ON:           is = 1; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 0; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 0; break;
        case FLOOR__METAL_PISTON_CELL:         is = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 0; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__PIT:                       is = 1; break;
        case FLOOR__WATER:                     is = 0; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_move_for_flying(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__STONE_TRAP:                is = 0; break;
        case FLOOR__METAL_SPIKES_ON:           is = 0; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 0; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 0; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 0; break;
        case FLOOR__METAL_PISTON_CELL:         is = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 0; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__PIT:                       is = 0; break;
        case FLOOR__WATER:                     is = 0; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_drop(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 1; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 1; break;
        case FLOOR__ROCK_CRACK_PIT:            is = 1; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__STONE_TRAP:                is = 1; break;
        case FLOOR__METAL_SPIKES_ON:           is = 1; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 0; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 1; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 0; break;
        case FLOOR__METAL_PISTON_CELL:         is = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 0; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__PIT:                       is = 1; break;
        case FLOOR__WATER:                     is = 1; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 1; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 1; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_drop_for_floating(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR__ROCK_CRACK_PIT:            is = 1; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__STONE_TRAP:                is = 1; break;
        case FLOOR__METAL_SPIKES_ON:           is = 1; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 0; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 0; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 0; break;
        case FLOOR__METAL_PISTON_CELL:         is = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 0; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__PIT:                       is = 1; break;
        case FLOOR__WATER:                     is = 0; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        default: break;
    }

    return is;
}

int is_floor_deadly_on_drop_for_flying(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR__ROCK_CRACK_PIT:            is = 0; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__STONE_TRAP:                is = 0; break;
        case FLOOR__METAL_SPIKES_ON:           is = 0; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 0; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 0; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 0; break;
        case FLOOR__METAL_PISTON_CELL:         is = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 0; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__PIT:                       is = 0; break;
        case FLOOR__WATER:                     is = 0; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        default: break;
    }

    return is;
}

int get_floor_item_type(int floor)
{
    int item = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      item = ITEM__NONE; break;
        case FLOOR__ROCK:                      item = ITEM__NONE; break;
        case FLOOR__ROCK_CRACK_WATER:          item = ITEM__NONE; break;
        case FLOOR__ROCK_CRACK_LAVA:           item = ITEM__NONE; break;
        case FLOOR__STONE:                     item = ITEM__NONE; break;
        case FLOOR__METAL_SPIKES_ON:           item = ITEM__NONE; break;
        case FLOOR__METAL_SPIKES_OFF:          item = ITEM__NONE; break;
        case FLOOR__METAL:                     item = ITEM__NONE; break;
        case FLOOR__METAL_HATCH_OPEN:          item = ITEM__NONE; break;
        case FLOOR__METAL_HATCH_CLOSED:        item = ITEM__NONE; break;
        case FLOOR__METAL_COVER_BOTTOM:        item = ITEM__NONE; break;
        case FLOOR__METAL_PISTON:              item = ITEM__NONE; break;
        case FLOOR__METAL_PISTON_CELL:         item = ITEM__NONE; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     item = ITEM__NONE; break;
        case FLOOR__METAL_PISTON_BARREL:       item = ITEM__NONE; break;
        case FLOOR__METAL_NO_PISTON:           item = ITEM__NONE; break;
        case FLOOR__GRASS:                     item = ITEM__NONE; break;
        case FLOOR__WATER:                     item = ITEM__NONE; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   item = ITEM__NONE; break;
        case FLOOR__LAVA:                      item = ITEM__NONE; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    item = ITEM__NONE; break;
        case FLOOR__ICE:                       item = ITEM__NONE; break;
        case FLOOR__ICE_CRACK_WATER:           item = ITEM__NONE; break;
        case FLOOR__STONE_STAIRS_BELOW:        item = ITEM__NONE; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  item = ITEM__NONE; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    item = ITEM__CELL; break;
        case FLOOR__ROCK_STAIRS_BELOW:             item = ITEM__NONE; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        item = ITEM__NONE; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        item = ITEM__NONE; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         item = ITEM__NONE; break;
        case FLOOR__METAL_STAIRS_BELOW:            item = ITEM__NONE; break;
        default: break;
    }

    return item;
}

int get_floor_item_count(int floor)
{
    int count = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      count = 0; break;
        case FLOOR__ROCK:                      count = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          count = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           count = 0; break;
        case FLOOR__STONE:                     count = 0; break;
        case FLOOR__METAL_SPIKES_ON:           count = 0; break;
        case FLOOR__METAL_SPIKES_OFF:          count = 0; break;
        case FLOOR__METAL:                     count = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          count = 0; break;
        case FLOOR__METAL_HATCH_CLOSED:        count = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        count = 0; break;
        case FLOOR__METAL_PISTON:              count = 0; break;
        case FLOOR__METAL_PISTON_CELL:         count = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     count = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       count = 0; break;
        case FLOOR__METAL_NO_PISTON:           count = 0; break;
        case FLOOR__GRASS:                     count = 0; break;
        case FLOOR__WATER:                     count = 0; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   count = 0; break;
        case FLOOR__LAVA:                      count = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    count = 0; break;
        case FLOOR__ICE:                       count = 0; break;
        case FLOOR__ICE_CRACK_WATER:           count = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        count = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  count = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    count = 1; break;
        case FLOOR__ROCK_STAIRS_BELOW:             count = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        count = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        count = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         count = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            count = 0; break;
        default: break;
    }

    return count;
}

int is_floor_put_item(int floor)
{
    int is = 0;

    switch(floor)
    {
        case FLOOR__NONE:                      is = 0; break;
        case FLOOR__ROCK:                      is = 0; break;
        case FLOOR__ROCK_CRACK_WATER:          is = 0; break;
        case FLOOR__ROCK_CRACK_LAVA:           is = 0; break;
        case FLOOR__STONE:                     is = 0; break;
        case FLOOR__METAL_SPIKES_ON:           is = 0; break;
        case FLOOR__METAL_SPIKES_OFF:          is = 0; break;
        case FLOOR__METAL:                     is = 0; break;
        case FLOOR__METAL_HATCH_OPEN:          is = 0; break;
        case FLOOR__METAL_HATCH_CLOSED:        is = 0; break;
        case FLOOR__METAL_COVER_BOTTOM:        is = 0; break;
        case FLOOR__METAL_PISTON:              is = 0; break;
        case FLOOR__METAL_PISTON_CELL:         is = 0; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     is = 0; break;
        case FLOOR__METAL_PISTON_BARREL:       is = 0; break;
        case FLOOR__METAL_NO_PISTON:           is = 0; break;
        case FLOOR__GRASS:                     is = 0; break;
        case FLOOR__WATER:                     is = 0; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   is = 0; break;
        case FLOOR__LAVA:                      is = 0; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    is = 0; break;
        case FLOOR__ICE:                       is = 0; break;
        case FLOOR__ICE_CRACK_WATER:           is = 0; break;
        case FLOOR__STONE_STAIRS_BELOW:        is = 0; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  is = 1; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    is = 0; break;
        case FLOOR__ROCK_STAIRS_BELOW:             is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         is = 0; break;
        case FLOOR__METAL_STAIRS_BELOW:            is = 0; break;
        default: break;
    }

    return is;
}

char* get_name_from_floor(int floor)
{
    char* name = "";

    switch(floor)
    {
        case FLOOR__NONE:                      name = "none"; break;
        case FLOOR__ROCK:                      name = "rock"; break;
        case FLOOR__ROCK_CRACK_WATER:          name = "rock crack water"; break;
        case FLOOR__ROCK_CRACK_LAVA:           name = "rock crack lava"; break;
        case FLOOR__ROCK_CRACK_PIT:            name = "rock crack pit"; break;
        case FLOOR__STONE:                     name = "stone"; break;
        case FLOOR__STONE_TRAP:                name = "stone trap"; break;
        case FLOOR__METAL_SPIKES_ON:           name = "metal spikes on"; break;
        case FLOOR__METAL_SPIKES_OFF:          name = "metal spikes off"; break;
        case FLOOR__METAL:                     name = "metal"; break;
        case FLOOR__METAL_HATCH_OPEN:          name = "metal hatch open"; break;
        case FLOOR__METAL_HATCH_CLOSED:        name = "metal hatch closed"; break;
        case FLOOR__METAL_COVER_BOTTOM:        name = "metal cover bottom"; break;
        case FLOOR__METAL_TARGET_UNCHECKED:    name = "metal target unchecked"; break;
        case FLOOR__METAL_TARGET_CHECKED:      name = "metal target checked"; break;
        case FLOOR__METAL_PISTON:              name = "metal piston"; break;
        case FLOOR__METAL_PISTON_CELL:         name = "metal piston cell"; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     name = "metal piston dynamite"; break;
        case FLOOR__METAL_PISTON_BARREL:       name = "metal piston barrel"; break;
        case FLOOR__METAL_NO_PISTON:           name = "metal no piston"; break;
        case FLOOR__GOLD:                      name = "gold"; break;
        case FLOOR__MARBLE:                    name = "marble"; break;
        case FLOOR__OBSIDIAN:                  name = "obsidian"; break;
        case FLOOR__GRASS:                     name = "grass"; break;
        case FLOOR__SAND:                      name = "sand"; break;
        case FLOOR__COINS:                     name = "coins"; break;
        case FLOOR__WATER:                     name = "water"; break;
        case FLOOR__WATER_LILY_POD:            name = "water lily pod"; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   name = "water stalactite fallen"; break;
        case FLOOR__LAVA:                      name = "lava"; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    name = "lava stalactite fallen"; break;
        case FLOOR__ICE:                       name = "ice"; break;
        case FLOOR__ICE_CRACK_WATER:           name = "ice crack water"; break;
        case FLOOR__OBSTACLE:                  name = "obstacle"; break;
        case FLOOR__STONE_STAIRS_BELOW:        name = "stone stairs below"; break;
        case FLOOR__STONE_STAIRS_BELOW_BLOCKED:name = "stone stairs below blocked"; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  name = "stone stairs above unpowered"; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    name = "stone stairs above powered"; break;
        case FLOOR__ROCK_STAIRS_BELOW:             name = "rock stairs below"; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        name = "metal stairs below off"; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        name = "metal stairs above off"; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         name = "metal stairs below on"; break;
        case FLOOR__METAL_STAIRS_BELOW:            name = "metal stairs below"; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:    name = "ext bridge source on horizontal"; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:   name = "ext bridge source off horizontal"; break;
        case FLOOR__EXT_BRIDGE_PART_HORIZONTAL:         name = "ext bridge part horizontal"; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:      name = "ext bridge source on vertical"; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:     name = "ext bridge source off vertical"; break;
        case FLOOR__EXT_BRIDGE_PART_VERTICAL:           name = "ext bridge part vertical"; break;
        default: break;
    }

    return name;
}

Texture* get_texture_1_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR__NONE:                      texture = 0; break;
        case FLOOR__ROCK:                      texture = textures->floor.rock; break;
        case FLOOR__ROCK_CRACK_WATER:          texture = textures->floor.rock_crack_water; break;
        case FLOOR__ROCK_CRACK_LAVA:           texture = textures->floor.rock_crack_lava; break;
        case FLOOR__ROCK_CRACK_PIT:            texture = textures->floor.rock_crack_pit; break;
        case FLOOR__STONE:                     texture = textures->floor.stone; break;
        case FLOOR__STONE_TRAP:                texture = textures->floor.stone_trap; break;
        case FLOOR__METAL_SPIKES_ON:           texture = textures->floor.metal_spikes_on; break;
        case FLOOR__METAL_SPIKES_OFF:          texture = textures->floor.metal_spikes_off; break;
        case FLOOR__METAL:                     texture = textures->floor.metal; break;
        case FLOOR__METAL_HATCH_OPEN:          texture = textures->floor.metal_hatch_open_1; break;
        case FLOOR__METAL_HATCH_CLOSED:        texture = textures->floor.metal_hatch_closed; break;
        case FLOOR__METAL_COVER_BOTTOM:        texture = textures->floor.metal_cover_bottom; break;
        case FLOOR__METAL_TARGET_UNCHECKED:    texture = textures->floor.metal_target_unchecked; break;
        case FLOOR__METAL_TARGET_CHECKED:      texture = textures->floor.metal_target_checked; break;
        case FLOOR__METAL_PISTON:              texture = textures->floor.metal_piston; break;
        case FLOOR__METAL_PISTON_CELL:         texture = textures->floor.metal_piston_cell; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     texture = textures->floor.metal_piston_dynamite; break;
        case FLOOR__METAL_PISTON_BARREL:       texture = textures->floor.metal_piston_barrel; break;
        case FLOOR__METAL_NO_PISTON:           texture = textures->floor.metal_no_piston; break;
        case FLOOR__GOLD:                      texture = textures->floor.gold; break;
        case FLOOR__MARBLE:                    texture = textures->floor.marble; break;
        case FLOOR__OBSIDIAN:                  texture = textures->floor.obsidian; break;
        case FLOOR__GRASS:                     texture = textures->floor.grass; break;
        case FLOOR__SAND:                      texture = textures->floor.sand; break;
        case FLOOR__COINS:                     texture = textures->floor.coins; break;
        case FLOOR__PIT:                       texture = textures->floor.pit; break;
        case FLOOR__WATER:                     texture = textures->floor.water_1; break;
        case FLOOR__WATER_LILY_POD:            texture = textures->floor.water_lily_pod_1; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   texture = textures->floor.water_stalactite_fallen_1; break;
        case FLOOR__LAVA:                      texture = textures->floor.lava_1; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    texture = textures->floor.lava_stalactite_fallen_1; break;
        case FLOOR__ICE:                       texture = textures->floor.ice; break;
        case FLOOR__ICE_CRACK_WATER:           texture = textures->floor.ice_crack_water; break;
        case FLOOR__OBSTACLE:                  texture = textures->floor.obstacle; break;
        case FLOOR__STONE_STAIRS_BELOW:        texture = textures->floor.stone_stairs_below; break;
        case FLOOR__STONE_STAIRS_BELOW_BLOCKED:texture = textures->floor.stone_stairs_below_blocked; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  texture = textures->floor.stone_stairs_above_unpowered; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    texture = textures->floor.stone_stairs_above_powered; break;
        case FLOOR__ROCK_STAIRS_BELOW:             texture = textures->floor.rock_stairs_below; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        texture = textures->floor.metal_stairs_below_off; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        texture = textures->floor.metal_stairs_above_off; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         texture = textures->floor.metal_stairs_below_on; break;
        case FLOOR__METAL_STAIRS_BELOW:            texture = textures->floor.metal_stairs_below; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:    texture = textures->floor.ext_bridge_source_on_horizontal; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:   texture = textures->floor.ext_bridge_source_off_horizontal; break;
        case FLOOR__EXT_BRIDGE_PART_HORIZONTAL:         texture = textures->floor.ext_bridge_part_horizontal; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:      texture = textures->floor.ext_bridge_source_on_vertical; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:     texture = textures->floor.ext_bridge_source_off_vertical; break;
        case FLOOR__EXT_BRIDGE_PART_VERTICAL:           texture = textures->floor.ext_bridge_part_vertical; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_2_from_floor_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case FLOOR__NONE:                      texture = 0; break;
        case FLOOR__ROCK:                      texture = textures->floor.rock; break;
        case FLOOR__ROCK_CRACK_WATER:          texture = textures->floor.rock_crack_water; break;
        case FLOOR__ROCK_CRACK_LAVA:           texture = textures->floor.rock_crack_lava; break;
        case FLOOR__ROCK_CRACK_PIT:            texture = textures->floor.rock_crack_pit; break;
        case FLOOR__STONE:                     texture = textures->floor.stone; break;
        case FLOOR__STONE_TRAP:                texture = textures->floor.stone_trap; break;
        case FLOOR__METAL_SPIKES_ON:           texture = textures->floor.metal_spikes_on; break;
        case FLOOR__METAL_SPIKES_OFF:          texture = textures->floor.metal_spikes_off; break;
        case FLOOR__METAL:                     texture = textures->floor.metal; break;
        case FLOOR__METAL_HATCH_OPEN:          texture = textures->floor.metal_hatch_open_2; break;
        case FLOOR__METAL_HATCH_CLOSED:        texture = textures->floor.metal_hatch_closed; break;
        case FLOOR__METAL_COVER_BOTTOM:        texture = textures->floor.metal_cover_bottom; break;
        case FLOOR__METAL_TARGET_UNCHECKED:    texture = textures->floor.metal_target_unchecked; break;
        case FLOOR__METAL_TARGET_CHECKED:      texture = textures->floor.metal_target_checked; break;
        case FLOOR__METAL_PISTON:              texture = textures->floor.metal_piston; break;
        case FLOOR__METAL_PISTON_CELL:         texture = textures->floor.metal_piston_cell; break;
        case FLOOR__METAL_PISTON_DYNAMITE:     texture = textures->floor.metal_piston_dynamite; break;
        case FLOOR__METAL_PISTON_BARREL:       texture = textures->floor.metal_piston_barrel; break;
        case FLOOR__METAL_NO_PISTON:           texture = textures->floor.metal_no_piston; break;
        case FLOOR__GOLD:                      texture = textures->floor.gold; break;
        case FLOOR__MARBLE:                    texture = textures->floor.marble; break;
        case FLOOR__OBSIDIAN:                  texture = textures->floor.obsidian; break;
        case FLOOR__GRASS:                     texture = textures->floor.grass; break;
        case FLOOR__SAND:                      texture = textures->floor.sand; break;
        case FLOOR__COINS:                     texture = textures->floor.coins; break;
        case FLOOR__PIT:                       texture = textures->floor.pit; break;
        case FLOOR__WATER:                     texture = textures->floor.water_2; break;
        case FLOOR__WATER_LILY_POD:            texture = textures->floor.water_lily_pod_2; break;
        case FLOOR__WATER_STALACTITE_FALLEN:   texture = textures->floor.water_stalactite_fallen_2; break;
        case FLOOR__LAVA:                      texture = textures->floor.lava_2; break;
        case FLOOR__LAVA_STALACTITE_FALLEN:    texture = textures->floor.lava_stalactite_fallen_2; break;
        case FLOOR__ICE:                       texture = textures->floor.ice; break;
        case FLOOR__ICE_CRACK_WATER:           texture = textures->floor.ice_crack_water; break;
        case FLOOR__OBSTACLE:                  texture = textures->floor.obstacle; break;
        case FLOOR__STONE_STAIRS_BELOW:        texture = textures->floor.stone_stairs_below; break;
        case FLOOR__STONE_STAIRS_BELOW_BLOCKED:texture = textures->floor.stone_stairs_below_blocked; break;
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:  texture = textures->floor.stone_stairs_above_unpowered; break;
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:    texture = textures->floor.stone_stairs_above_powered; break;
        case FLOOR__ROCK_STAIRS_BELOW:             texture = textures->floor.rock_stairs_below; break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:        texture = textures->floor.metal_stairs_below_off; break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:        texture = textures->floor.metal_stairs_above_off; break;
        case FLOOR__METAL_STAIRS_BELOW_ON:         texture = textures->floor.metal_stairs_below_on; break;
        case FLOOR__METAL_STAIRS_BELOW:            texture = textures->floor.metal_stairs_below; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:    texture = textures->floor.ext_bridge_source_on_horizontal; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:   texture = textures->floor.ext_bridge_source_off_horizontal; break;
        case FLOOR__EXT_BRIDGE_PART_HORIZONTAL:         texture = textures->floor.ext_bridge_part_horizontal; break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:      texture = textures->floor.ext_bridge_source_on_vertical; break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:     texture = textures->floor.ext_bridge_source_off_vertical; break;
        case FLOOR__EXT_BRIDGE_PART_VERTICAL:           texture = textures->floor.ext_bridge_part_vertical; break;
        default: break;
    }

    return texture;
}
