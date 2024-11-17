#include "../inc/sounds.h"

void load_sounds(Sounds* sounds)
{
    sounds->none = get_sound_from_filepath("./res/sound/none.mp3");

    sounds->use_exit = get_sound_from_filepath("./res/sound/human-impact-on-ground-6982-louder.mp3");
    sounds->use_station = get_sound_from_filepath("./res/sound/083525_drill-37769-quieter.mp3");

    sounds->move = get_sound_from_filepath("./res/sound/slash-21834-quieter.mp3");
    sounds->move_floating = get_sound_from_filepath("./res/sound/menu-change-89197-quieter.mp3");
    sounds->move_flying = get_sound_from_filepath("./res/sound/swoosh-sound-effect-for-fight-scenes-or-transitions-3-149888-quieter.mp3");
    sounds->crash = get_sound_from_filepath("./res/sound/punchy-taps-ui-1-183897-lower.mp3");

    sounds->fall_water = get_sound_from_filepath("./res/sound/water-splash-199583-shorter.mp3");
    sounds->fall_lava = get_sound_from_filepath("./res/sound/8-bit-sizzle-102668-quieter.mp3");
    sounds->fall_pit = get_sound_from_filepath("./res/sound/cartoon-slide-whistle-down-2-176648-lower.mp3");
    sounds->death = get_sound_from_filepath("./res/sound/pixel-death-66829.mp3");

    sounds->throww = get_sound_from_filepath("./res/sound/whoosh-6316.mp3");
    sounds->drop = get_sound_from_filepath("./res/sound/desk-thud-106752-quieter.mp3");

    sounds->melt = get_sound_from_filepath("./res/sound/8-bit-sizzle-102668-quieter.mp3");
    sounds->breakk = get_sound_from_filepath("./res/sound/rock-destroy-6409-quieter.mp3");
    sounds->shake = get_sound_from_filepath("./res/sound/vibrating-thud-39536.mp3");

    sounds->cell = get_sound_from_filepath("./res/sound/bottle-break-39916-quieter.mp3");
    sounds->bomb = get_sound_from_filepath("./res/sound/explosion-sound-effect-1-241821.mp3");

    sounds->laser = get_sound_from_filepath("./res/sound/laser-gun-81720-quieter.mp3");
    sounds->kill_around = get_sound_from_filepath("./res/sound/collision-83248-quieter.mp3");

    sounds->manipulation = get_sound_from_filepath("./res/sound/ui-beep-menu-positive-228336.mp3");
    sounds->teleportation = get_sound_from_filepath("./res/sound/game-teleport-90735-quieter.mp3");

    sounds->put_item = get_sound_from_filepath("./res/sound/thump-105302-louder.mp3");
    sounds->pick_up_close = get_sound_from_filepath("./res/sound/item-equip-6904-louder.mp3");
    sounds->pick_up_far = get_sound_from_filepath("./res/sound/lightclunk1-107615.mp3");

    sounds->minibot_launch = get_sound_from_filepath("./res/sound/metal-whoosh-hit-12-202179-quieter.mp3");
    sounds->minibot_merge = get_sound_from_filepath("./res/sound/metal-whoosh-hit-3-201902-quieter.mp3");

    sounds->stomp = get_sound_from_filepath("./res/sound/lettuce-48162.mp3");

    sounds->falling_stalactite = get_sound_from_filepath("./res/sound/hamer-90566-quieter.mp3");
    sounds->emerge_water = get_sound_from_filepath("./res/sound/water-splash-199583-shorter.mp3");
    sounds->emerge_pit = get_sound_from_filepath("./res/sound/wings-of-insects-45540.mp3");
    sounds->emerge_burrow = get_sound_from_filepath("./res/sound/dig-wet-sand-04-102880.mp3");
    sounds->emerge_pipe = get_sound_from_filepath("./res/sound/infographic-pop-2-197871.mp3");
    sounds->collapse_burrow = get_sound_from_filepath("./res/sound/rocks-and-gravel-slide-1-204994-quieter.mp3");
    sounds->conv_belt = get_sound_from_filepath("./res/sound/servomotor-104111.mp3");

    sounds->vending = get_sound_from_filepath("./res/sound/vending-machine-104483-shorter.mp3");
    sounds->glass_break = get_sound_from_filepath("./res/sound/glass-hit-192119.mp3");
}

void destroy_sounds(Sounds* sounds)
{
    // later...
}
