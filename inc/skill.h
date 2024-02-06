#ifndef SKILL_H
#define SKILL_H

#include "../inc/common.h"
#include "../inc/vec.h"

enum SKILL
{
    SKILL__NONE,

    SKILL__PICK_ITEM_CLOSE,
    SKILL__PICK_ITEM_FAR,
    SKILL__PUT_ITEM_CLOSE,
    SKILL__PUT_ITEM_FAR,

    SKILL__USE,
    SKILL__MANIPULATION,
    SKILL__TELEPORTATION,
    SKILL__MOVE,
    SKILL__MOVE_FLOATING,
    SKILL__MOVE_FLYING,
    SKILL__THROW_CELL,
    SKILL__THROW_DYNAMITE,
    SKILL__THROW_GEMSTONE,

    SKILL__PUSH,
    SKILL__THROW,
    SKILL__PULL,
    SKILL__JUMP,
    SKILL__CHARGE,
    SKILL__STOMP,

    SKILL__PULL_AND_THROW,
    SKILL__CHARGE_AND_PUSH,
    SKILL__CHARGE_AND_THROW,
    SKILL__CHARGE_AND_JUMP,
    SKILL__JUMP_AND_CARRY,
    SKILL__JUMP_AND_STOMP,

    SKILL__LAUNCH_MINIBOT,
    SKILL__ASCEND,
    SKILL__DESCEND,

    SKILL__TURRET_LASER,
    SKILL__TURRET_BOMB,
    SKILL__TURRET_PROJECTILE,

    SKILL__COUNT
};

int is_skill_two_target(int skill);
char* get_skill_name(int skill);

#endif
