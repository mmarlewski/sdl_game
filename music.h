#ifndef MUSIC_H
#define MUSIC_H

#include "common.h"

Music* get_music_from_filepath ( char* filepath);
void destroy_music (Music* music);
void play_new_music(Music* new_music);
int get_is_music_paused();
void pause_music();
void resume_music();
float get_music_volume();
void set_music_volume(float new_volume);

#endif