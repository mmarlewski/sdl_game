#include "../inc/sounds.h"

void load_sounds(Sounds* sounds)
{
    sounds->none = get_sound_from_filepath("./res/sound/none.mp3");

    sounds->move = get_sound_from_filepath("./res/sound/move.mp3");
    sounds->push = get_sound_from_filepath("./res/sound/push.mp3");
    sounds->crash = get_sound_from_filepath("./res/sound/crash.mp3");

    sounds->throw = get_sound_from_filepath("./res/sound/throw.mp3");
    sounds->drop = get_sound_from_filepath("./res/sound/drop.mp3");

    sounds->fall = get_sound_from_filepath("./res/sound/fall.mp3");
    sounds->death = get_sound_from_filepath("./res/sound/death.mp3");
    sounds->blow_up = get_sound_from_filepath("./res/sound/blow_up.mp3");

    sounds->floor_trap = get_sound_from_filepath("./res/sound/floor_trap.mp3");
}

void destroy_sounds(Sounds* sounds)
{
    destroy_sound(sounds->none);

    destroy_sound(sounds->move);
    destroy_sound(sounds->push);
    destroy_sound(sounds->crash);

    destroy_sound(sounds->throw);
    destroy_sound(sounds->drop);

    destroy_sound(sounds->fall);
    destroy_sound(sounds->death);
    destroy_sound(sounds->blow_up);

    destroy_sound(sounds->floor_trap);
}
