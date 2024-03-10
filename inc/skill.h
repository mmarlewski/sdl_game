#ifndef SKILL_H
#define SKILL_H

#include "../inc/common.h"
#include "../inc/vec.h"

enum SKILL
{
    SKILL__NONE,

    SKILL__USE,
    SKILL__MANIPULATION,
    SKILL__TELEPORTATION,

    SKILL__MOVE,
    SKILL__MOVE_FLOATING,
    SKILL__MOVE_FLYING,

    SKILL__PICK_ITEM_CLOSE,
    SKILL__PICK_ITEM_FAR,

    SKILL__PUT_ITEM_CELL_CLOSE,
    SKILL__PUT_ITEM_CELL_FAR,
    SKILL__PUT_ITEM_DYNAMITE_CLOSE,
    SKILL__PUT_ITEM_DYNAMITE_FAR,
    SKILL__PUT_ITEM_GEMSTONE_CLOSE,
    SKILL__PUT_ITEM_GEMSTONE_FAR,

    SKILL__THROW_ITEM_CELL,
    SKILL__THROW_ITEM_DYNAMITE,
    SKILL__THROW_ITEM_GEMSTONE,

    SKILL__PUSH,
    SKILL__THROW,
    SKILL__PULL,
    SKILL__DRAG_HOOK,
    SKILL__DRAG_SPIDERWEB,
    SKILL__DRAG_TENTACLE,
    SKILL__JUMP,
    SKILL__CHARGE,
    SKILL__STOMP,

    SKILL__DRAG_AND_THROW,
    SKILL__CHARGE_AND_PUSH,
    SKILL__CHARGE_AND_THROW,
    SKILL__CHARGE_AND_JUMP,
    SKILL__JUMP_AND_CARRY,
    SKILL__JUMP_AND_STOMP,

    SKILL__LAUNCH_MINIBOT,

    SKILL__TURRET_LASER,
    SKILL__TURRET_BOMB,
    SKILL__TURRET_PROJECTILE,

    SKILL__MINIBOT_MERGE,

    SKILL__COUNT
};

int is_skill_two_target(int skill);
int get_skill_action_points(int skill);
char* get_skill_name(int skill);

#endif
