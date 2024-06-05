#ifndef SOUNDS_H
#define SOUNDS_H

#include "../inc/common.h"
#include "../inc/sound.h"

typedef struct
{
    Sound* none;

    Sound* move;
    Sound* push;
    Sound* crash;

    Sound* throw;
    Sound* drop;

    Sound* fall;
    Sound* death;
    Sound* blow_up;

    Sound* floor_trap;

} Sounds;

void load_sounds(Sounds* sounds);
void destroy_sounds(Sounds* sounds);

#endif
