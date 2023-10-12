#include "../inc/musics.h"

void load_musics (Musics* musics)
{
    musics->ambient = get_music_from_filepath ("./res/music/ambient.mp3");
}

void destroy_musics (Musics* musics)
{
    destroy_music (musics->ambient);
}