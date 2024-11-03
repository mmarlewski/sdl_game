#ifndef SOUNDS_H
#define SOUNDS_H

#include "../inc/common.h"
#include "../inc/sound.h"

typedef struct
{
    Sound* none;

    Sound* use_exit;
    Sound* use_station;

    Sound* move;
    Sound* move_floating;
    Sound* move_flying;
    Sound* crash;

    Sound* fall_water;
    Sound* fall_lava;
    Sound* fall_pit;
    Sound* death;

    Sound* throww;
    Sound* drop;

    Sound* melt;
    Sound* breakk;
    Sound* shake;

    Sound* cell;
    Sound* bomb;

    Sound* laser;
    Sound* kill_around;

    Sound* manipulation;
    Sound* teleportation;

    Sound* put_item;
    Sound* pick_up_close;
    Sound* pick_up_far;

    Sound* minibot_launch;
    Sound* minibot_merge;

    Sound* stomp;

    Sound* falling_stalactite;
    Sound* emerge_water;
    Sound* emerge_pit;
    Sound* emerge_burrow;
    Sound* emerge_pipe;
    Sound* collapse_burrow;
    Sound* conv_belt;

    Sound* vending;
    Sound* glass_break;

} Sounds;

void load_sounds(Sounds* sounds);
void destroy_sounds(Sounds* sounds);

#endif
