#ifndef SOUND_H
#define SOUND_H

#include "../inc/common.h"

Sound* get_sound_from_filepath ( char* filepath);
void destroy_sound (Sound* sound);
void play_sound(Sound* sound);
float get_sound_volume();
void set_sound_volume(float new_volume);

#endif