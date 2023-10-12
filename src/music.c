#include "../inc/music.h"

int is_music_paused = 0;
float music_volume = 1.0f;

Music* get_music_from_filepath ( char* filepath)
{
    Music* music;

    music = Mix_LoadMUS(filepath);

    return music;
}

void destroy_music (Music* music)
{
    Mix_FreeMusic(music);
}

void play_new_music(Music* new_music)
{
    Mix_PlayMusic(new_music, -1);
}

int get_is_music_paused()
{
    return is_music_paused;
}

void pause_music()
{
    is_music_paused = 1;
    Mix_PauseMusic();
}

void resume_music()
{
    is_music_paused = 0;
    Mix_ResumeMusic();
}

float get_music_volume()
{
    return music_volume;
}

void set_music_volume(float new_volume)
{
    if(new_volume < 0.0f) new_volume = 0.0f;
    if(new_volume > 1.0f) new_volume = 1.0f;

    music_volume = new_volume;

    Mix_VolumeMusic(music_volume * MIX_MAX_VOLUME);
}