#include "../inc/state.h"

int is_skill_two_target(int skill)
{
    int is = 0;

    switch(skill)
    {
        case SKILL__NONE:                   is = 0; break;
        case SKILL__HERO_PICK_ITEM_CLOSE:   is = 0; break;
        case SKILL__HERO_PICK_ITEM_FAR:     is = 0; break;
        case SKILL__HERO_PUT_ITEM_CLOSE:    is = 0; break;
        case SKILL__HERO_PUT_ITEM_FAR:      is = 0; break;
        case SKILL__HERO_MANIPULATION:      is = 0; break;
        case SKILL__HERO_MOVE:              is = 0; break;
        case SKILL__HERO_MOVE_FLOATING:     is = 0; break;
        case SKILL__HERO_MOVE_FLYING:       is = 0; break;
        case SKILL__HERO_THROW_CELL:        is = 0; break;
        case SKILL__HERO_THROW_DYNAMITE:    is = 0; break;
        case SKILL__HERO_THROW_GEMSTONE:    is = 0; break;
        case SKILL__CHARGE:                 is = 0; break;
        case SKILL__JUMP:                   is = 0; break;
        case SKILL__CHARGE_AND_PUSH:        is = 1; break;
        case SKILL__CHARGE_AND_THROW:       is = 1; break;
        case SKILL__PUSH:                   is = 1; break;
        case SKILL__PULL:                   is = 1; break;
        case SKILL__PULL_AND_THROW:         is = 1; break;
        case SKILL__THROW:                  is = 1; break;
        case SKILL__STOMP:                  is = 0; break;
        case SKILL__TURRET_LASER:           is = 0; break;
        case SKILL__TURRET_BOMB:            is = 0; break;
        case SKILL__TURRET_PROJECTILE:      is = 0; break;
        default: break;
    }

    return is;
}

char* get_skill_name(int skill)
{
    char* name = "";

    switch(skill)
    {
        case SKILL__NONE:                   name = "none";                  break;
        case SKILL__HERO_PICK_ITEM_CLOSE:   name = "hero pick item close";  break;
        case SKILL__HERO_PICK_ITEM_FAR:     name = "hero pick item far";    break;
        case SKILL__HERO_PUT_ITEM_CLOSE:    name = "hero put item close";   break;
        case SKILL__HERO_PUT_ITEM_FAR:      name = "hero put item far";     break;
        case SKILL__HERO_MANIPULATION:      name = "hero manipulation";     break;
        case SKILL__HERO_MOVE:              name = "hero move";             break;
        case SKILL__HERO_MOVE_FLOATING:     name = "hero move floating";    break;
        case SKILL__HERO_MOVE_FLYING:       name = "hero move flying";      break;
        case SKILL__HERO_THROW_CELL:        name = "hero throw cell";       break;
        case SKILL__HERO_THROW_DYNAMITE:    name = "hero throw dynamite";   break;
        case SKILL__HERO_THROW_GEMSTONE:    name = "hero throw gemstone";   break;
        case SKILL__CHARGE:                 name = "charge";                break;
        case SKILL__JUMP:                   name = "jump";                  break;
        case SKILL__CHARGE_AND_PUSH:        name = "charge and push";       break;
        case SKILL__CHARGE_AND_THROW:       name = "charge and throw";      break;
        case SKILL__PUSH:                   name = "push";                  break;
        case SKILL__PULL:                   name = "pull";                  break;
        case SKILL__PULL_AND_THROW:         name = "pull and throw";        break;
        case SKILL__THROW:                  name = "throw";                 break;
        case SKILL__STOMP:                  name = "stomp";                 break;
        case SKILL__TURRET_LASER:           name = "turret laser";          break;
        case SKILL__TURRET_BOMB:            name = "turret bomb";           break;
        case SKILL__TURRET_PROJECTILE:      name = "turret projectile";     break;
        default: break;
    }

    return name;
}
