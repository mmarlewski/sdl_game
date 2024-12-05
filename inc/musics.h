#ifndef MUSICS_H
#define MUSICS_H

#include "../inc/common.h"
#include "../inc/music.h"

typedef struct
{
    int music_num;

    Music* music_array[11];

} Musics;

void load_musics(Musics* musics);
void destroy_musics(Musics* musics);

#endif
