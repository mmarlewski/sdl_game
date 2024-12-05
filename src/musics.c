#include "../inc/musics.h"

void load_musics(Musics* musics)
{
    musics->music_num = 10;

    musics->music_array[0] = get_music_from_filepath("./res/music/thinking-time-219360.mp3");
    musics->music_array[1] = get_music_from_filepath("./res/music/morphism-111870.mp3");
    musics->music_array[2] = get_music_from_filepath("./res/music/dream-vortex-222853.mp3");
    musics->music_array[3] = get_music_from_filepath("./res/music/chloroform-eden-114281.mp3");
    musics->music_array[4] = get_music_from_filepath("./res/music/omega-centurion-113851.mp3");
    musics->music_array[5] = get_music_from_filepath("./res/music/floating-fractals-thinking-time-221128.mp3");
    musics->music_array[6] = get_music_from_filepath("./res/music/desolate-world-121196.mp3");
    musics->music_array[7] = get_music_from_filepath("./res/music/midnight-revelations-166773.mp3");
    musics->music_array[8] = get_music_from_filepath("./res/music/zero-gravity-199747.mp3");
    musics->music_array[9] = get_music_from_filepath("./res/music/flying-in-motion-206125.mp3");
}

void destroy_musics(Musics* musics)
{
    //
}
