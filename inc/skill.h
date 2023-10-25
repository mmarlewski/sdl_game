#ifndef SKILL_H
#define SKILL_H

#include "../inc/common.h"
#include "../inc/vec.h"

enum SKILL
{
    SKILL__NONE,

    SKILL__CHARGE,
    SKILL__JUMP,
    SKILL__CHARGE_AND_PUSH,
    SKILL__CHARGE_AND_THROW,
    SKILL__PUSH,
    SKILL__PULL,
    SKILL__PULL_AND_THROW,
    SKILL__THROW,

    SKILL__COUNT
};

int is_skill_two_target(int skill);
char* get_skill_name(int skill);

#endif
