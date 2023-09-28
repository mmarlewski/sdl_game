#include "sounds.h"

void load_sounds (Sounds* sounds)
{
    sounds->ting = get_sound_from_filepath ("./ting.mp3");
}

void destroy_sounds (Sounds* sounds)
{
    destroy_sound (sounds->ting);
}