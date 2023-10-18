#include "../inc/state.h"

int is_skill_two_target(int skill)
{
    int is = 0;

    switch(skill)
    {
        case SKILL__CHARGE: is = 0; break;
        case SKILL__CHARGE_AND_PUSH: is = 1; break;
        case SKILL__CHARGE_AND_THROW: is = 1; break;
        case SKILL__JUMP: is = 0; break;
        case SKILL__PUSH: is = 1; break;
        case SKILL__PULL: is = 1; break;
        case SKILL__PULL_AND_THROW: is = 1; break;
        case SKILL__THROW: is = 1; break;
        default: break;
    }

    return is;
}

char* get_skill_name(int skill)
{
    char* name = "";

    switch(skill)
    {
        case SKILL__NONE:               name = "none";              break;
        case SKILL__FLY:                name = "fly";               break;
        case SKILL__JUMP:               name = "jump";              break;
        case SKILL__CHARGE:             name = "charge";            break;
        case SKILL__CHARGE_AND_PUSH:    name = "charge_and_push";   break;
        case SKILL__CHARGE_AND_THROW:   name = "charge_and_throw";  break;
        case SKILL__PUSH:               name = "push";              break;
        case SKILL__PULL:               name = "pull";              break;
        case SKILL__PULL_AND_THROW:     name = "pull_and_throw";    break;
        case SKILL__THROW:              name = "throw";             break;
        default: break;
    }

    return name;
}
