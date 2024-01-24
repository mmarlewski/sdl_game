#ifndef SKILL_H
#define SKILL_H

#include "../inc/common.h"
#include "../inc/vec.h"

enum SKILL
{
    SKILL__NONE,

    SKILL__HERO_PICK_ITEM_CLOSE,
    SKILL__HERO_PICK_ITEM_FAR,
    SKILL__HERO_PUT_ITEM_CLOSE,
    SKILL__HERO_PUT_ITEM_FAR,

    SKILL__HERO_INTERACT,
    SKILL__HERO_MOVE,
    SKILL__HERO_THROW_CELL,
    SKILL__HERO_THROW_DYNAMITE,
    SKILL__HERO_THROW_GEMSTONE,

    SKILL__CHARGE,
    SKILL__JUMP,
    SKILL__CHARGE_AND_PUSH,
    SKILL__CHARGE_AND_THROW,
    SKILL__PUSH,
    SKILL__PULL,
    SKILL__PULL_AND_THROW,
    SKILL__THROW,

    SKILL__TURRET_LASER,
    SKILL__TURRET_BOMB,
    SKILL__TURRET_PROJECTILE,

    SKILL__COUNT
};

int is_skill_two_target(int skill);
char* get_skill_name(int skill);

#endif
