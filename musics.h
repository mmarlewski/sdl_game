#ifndef MUSICS_H
#define MUSICS_H

#include "common.h"
#include "music.h"

typedef struct
{
    Music* ambient;
    
} Musics;

void load_musics (Musics* musics);
void destroy_musics (Musics* musics);

#endif