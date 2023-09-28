#ifndef SOUNDS_H
#define SOUNDS_H

#include "common.h"
#include "sound.h"

typedef struct
{
    Sound* ting;
    
} Sounds;

void load_sounds (Sounds* sounds);
void destroy_sounds (Sounds* sounds);

#endif