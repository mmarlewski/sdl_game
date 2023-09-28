#include "sound.h"

float sound_volume = 1.0f;

Sound* get_sound_from_filepath ( char* filepath)
{
    Sound* sound;

    sound = Mix_LoadWAV(filepath);

    return sound;
}

void destroy_sound (Sound* sound)
{
    Mix_FreeChunk(sound);
}

void play_sound(Sound* sound)
{
    Mix_PlayChannel(0, sound, 0);
}

float get_sound_volume()
{
    return sound_volume;
}

void set_sound_volume(float new_volume)
{
    if(new_volume < 0.0f) new_volume = 0.0f;
    if(new_volume > 1.0f) new_volume = 1.0f;

    sound_volume = new_volume;

    Mix_Volume(-1, sound_volume * MIX_MAX_VOLUME);
}