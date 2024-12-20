#include "../inc/sounds.h"

void load_sounds(Sounds* sounds)
{
    sounds->none = get_sound_from_filepath("./res/sound/none.mp3");

    sounds->use_exit = get_sound_from_filepath("./res/sound/human-impact-on-ground-6982-edited.mp3");
    sounds->use_station = get_sound_from_filepath("./res/sound/083525_drill-37769-edited.mp3");
    sounds->use_secret = get_sound_from_filepath("./res/sound/sound-effect-twinklesparkle-115095-edited.mp3");
    sounds->use_throne = get_sound_from_filepath("./res/sound/tadaa-47995-edited.mp3");

    sounds->move = get_sound_from_filepath("./res/sound/slash-21834-edited.mp3");
    sounds->move_floating = get_sound_from_filepath("./res/sound/menu-change-89197-edited.mp3");
    sounds->move_flying = get_sound_from_filepath("./res/sound/swoosh-sound-effect-for-fight-scenes-or-transitions-3-149888-edited.mp3");
    sounds->crash = get_sound_from_filepath("./res/sound/punchy-taps-ui-1-183897-edited.mp3");
    sounds->move_ice = get_sound_from_filepath("./res/sound/cartoon-yoink-2-183916-edited.mp3");

    sounds->fall_water = get_sound_from_filepath("./res/sound/water-splash-199583-edited.mp3");
    sounds->fall_lava = get_sound_from_filepath("./res/sound/8-bit-sizzle-102668-edited.mp3");
    sounds->fall_pit = get_sound_from_filepath("./res/sound/cartoon-slide-whistle-down-2-176648-edited.mp3");
    sounds->death = get_sound_from_filepath("./res/sound/pixel-death-66829.mp3");

    sounds->throww = get_sound_from_filepath("./res/sound/whoosh-6316.mp3");
    sounds->drop = get_sound_from_filepath("./res/sound/desk-thud-106752-edited.mp3");

    sounds->melt = get_sound_from_filepath("./res/sound/8-bit-sizzle-102668-edited.mp3");
    sounds->breakk = get_sound_from_filepath("./res/sound/rock-destroy-6409-edited.mp3");
    sounds->shake = get_sound_from_filepath("./res/sound/vibrating-thud-39536.mp3");

    sounds->cell = get_sound_from_filepath("./res/sound/bottle-break-39916-edited.mp3");
    sounds->bomb = get_sound_from_filepath("./res/sound/explosion-sound-effect-1-241821.mp3");

    sounds->laser = get_sound_from_filepath("./res/sound/laser-gun-81720-edited.mp3");
    sounds->kill_around = get_sound_from_filepath("./res/sound/collision-83248-edited.mp3");

    sounds->manipulation = get_sound_from_filepath("./res/sound/ui-beep-menu-positive-228336.mp3");
    sounds->teleportation = get_sound_from_filepath("./res/sound/game-teleport-90735-edited.mp3");

    sounds->put_item = get_sound_from_filepath("./res/sound/handgun-clip-in-89711.mp3");
    sounds->pick_up_close = get_sound_from_filepath("./res/sound/item-equip-6904-edited.mp3");
    sounds->pick_up_far = get_sound_from_filepath("./res/sound/lightclunk1-107615.mp3");

    sounds->minibot_launch = get_sound_from_filepath("./res/sound/metal-whoosh-hit-12-202179-edited.mp3");
    sounds->minibot_merge = get_sound_from_filepath("./res/sound/metal-whoosh-hit-3-201902-edited.mp3");

    sounds->stomp = get_sound_from_filepath("./res/sound/lettuce-48162.mp3");
    sounds->mimic = get_sound_from_filepath("./res/sound/wtf_01-96364.mp3");

    sounds->falling_stalactite = get_sound_from_filepath("./res/sound/hamer-90566-edited.mp3");
    sounds->emerge_water = get_sound_from_filepath("./res/sound/water-splash-199583-edited.mp3");
    sounds->emerge_pit = get_sound_from_filepath("./res/sound/wings-of-insects-45540-edited.mp3");
    sounds->emerge_burrow = get_sound_from_filepath("./res/sound/sand_step-87182-edited.mp3");
    sounds->emerge_pipe = get_sound_from_filepath("./res/sound/infographic-pop-2-197871.mp3");
    sounds->collapse_burrow = get_sound_from_filepath("./res/sound/rocks-and-gravel-slide-1-204994-edited.mp3");
    sounds->conv_belt = get_sound_from_filepath("./res/sound/servomotor-104111.mp3");

    sounds->vending = get_sound_from_filepath("./res/sound/vending-machine-104483-edited.mp3");
    sounds->glass_break = get_sound_from_filepath("./res/sound/glass-hit-192119.mp3");
}

void destroy_sounds(Sounds* sounds)
{
    // later...
}
