#ifndef SKILL_H
#define SKILL_H

#include "common.h"
#include "vec.h"

enum SKILL
{
    SKILL__NONE,

    SKILL__MOVE,
    SKILL__CHARGE,
    SKILL__PUSH,
    SKILL__PULL,

    SKILL__COUNT
};

int is_skill_two_target(int skill);
char* get_skill_name(int skill);

#endif