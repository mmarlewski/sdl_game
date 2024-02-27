#include "../inc/state.h"

int is_skill_two_target(int skill)
{
    int is = 0;

    switch(skill)
    {
        case SKILL__NONE:               is = 0; break;

        case SKILL__USE:                is = 0; break;
        case SKILL__MANIPULATION:       is = 0; break;
        case SKILL__TELEPORTATION:      is = 0; break;

        case SKILL__MOVE:               is = 0; break;
        case SKILL__MOVE_FLOATING:      is = 0; break;
        case SKILL__MOVE_FLYING:        is = 0; break;

        case SKILL__PICK_ITEM_CLOSE:            is = 0; break;
        case SKILL__PICK_ITEM_FAR:              is = 0; break;

        case SKILL__PUT_ITEM_CELL_CLOSE:        is = 0; break;
        case SKILL__PUT_ITEM_CELL_FAR:          is = 0; break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:    is = 0; break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:      is = 0; break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:    is = 0; break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:      is = 0; break;

        case SKILL__THROW_ITEM_CELL:            is = 0; break;
        case SKILL__THROW_ITEM_DYNAMITE:        is = 0; break;
        case SKILL__THROW_ITEM_GEMSTONE:        is = 0; break;

        case SKILL__PUSH:               is = 1; break;
        case SKILL__THROW:              is = 1; break;
        case SKILL__DRAG:               is = 1; break;
        case SKILL__PULL:               is = 1; break;
        case SKILL__JUMP:               is = 0; break;
        case SKILL__CHARGE:             is = 0; break;
        case SKILL__STOMP:              is = 0; break;

        case SKILL__DRAG_AND_THROW:     is = 1; break;
        case SKILL__CHARGE_AND_PUSH:    is = 1; break;
        case SKILL__CHARGE_AND_THROW:   is = 1; break;
        case SKILL__CHARGE_AND_JUMP:    is = 0; break;
        case SKILL__JUMP_AND_CARRY:     is = 1; break;
        case SKILL__JUMP_AND_STOMP:     is = 0; break;

        case SKILL__LAUNCH_MINIBOT:     is = 0; break;
        case SKILL__ASCEND:             is = 0; break;
        case SKILL__DESCEND:            is = 0; break;

        case SKILL__TURRET_LASER:       is = 0; break;
        case SKILL__TURRET_BOMB:        is = 0; break;
        case SKILL__TURRET_PROJECTILE:  is = 0; break;

        case SKILL__MINIBOT_MERGE:      is = 0; break;

        default: break;
    }

    return is;
}

int get_skill_action_points(int skill)
{
    int ap = 0;

    switch(skill)
    {
        case SKILL__NONE:               ap = 0; break;

        case SKILL__USE:                ap = 1; break;
        case SKILL__MANIPULATION:       ap = 1; break;
        case SKILL__TELEPORTATION:      ap = 1; break;

        case SKILL__MOVE:               ap = -1; break;
        case SKILL__MOVE_FLOATING:      ap = -1; break;
        case SKILL__MOVE_FLYING:        ap = -1; break;

        case SKILL__PICK_ITEM_CLOSE:            ap = 1; break;
        case SKILL__PICK_ITEM_FAR:              ap = 1; break;

        case SKILL__PUT_ITEM_CELL_CLOSE:        ap = 1; break;
        case SKILL__PUT_ITEM_CELL_FAR:          ap = 1; break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:    ap = 1; break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:      ap = 1; break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:    ap = 1; break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:      ap = 1; break;

        case SKILL__THROW_ITEM_CELL:            ap = 1; break;
        case SKILL__THROW_ITEM_DYNAMITE:        ap = 1; break;
        case SKILL__THROW_ITEM_GEMSTONE:        ap = 1; break;

        case SKILL__PUSH:               ap = 1; break;
        case SKILL__THROW:              ap = 1; break;
        case SKILL__DRAG:               ap = 1; break;
        case SKILL__PULL:               ap = 1; break;
        case SKILL__JUMP:               ap = 1; break;
        case SKILL__CHARGE:             ap = 1; break;
        case SKILL__STOMP:              ap = 1; break;

        case SKILL__DRAG_AND_THROW:     ap = 2; break;
        case SKILL__CHARGE_AND_PUSH:    ap = 2; break;
        case SKILL__CHARGE_AND_THROW:   ap = 2; break;
        case SKILL__CHARGE_AND_JUMP:    ap = 2; break;
        case SKILL__JUMP_AND_CARRY:     ap = 2; break;
        case SKILL__JUMP_AND_STOMP:     ap = 2; break;

        case SKILL__LAUNCH_MINIBOT:     ap = 1; break;
        case SKILL__ASCEND:             ap = 1; break;
        case SKILL__DESCEND:            ap = 1; break;

        case SKILL__TURRET_LASER:       ap = 1; break;
        case SKILL__TURRET_BOMB:        ap = 1; break;
        case SKILL__TURRET_PROJECTILE:  ap = 1; break;

        case SKILL__MINIBOT_MERGE:      ap = 1; break;

        default: break;
    }

    return ap;
}

char* get_skill_name(int skill)
{
    char* name = "???";

    switch(skill)
    {
        case SKILL__NONE:               name = "none"; break;

        case SKILL__USE:                name = "use"; break;
        case SKILL__MANIPULATION:       name = "manipulation"; break;
        case SKILL__TELEPORTATION:      name = "teleportation"; break;

        case SKILL__MOVE:               name = "move"; break;
        case SKILL__MOVE_FLOATING:      name = "move floating"; break;
        case SKILL__MOVE_FLYING:        name = "move flying"; break;

        case SKILL__PICK_ITEM_CLOSE:            name = "pick item close"; break;
        case SKILL__PICK_ITEM_FAR:              name = "pick item far"; break;

        case SKILL__PUT_ITEM_CELL_CLOSE:        name = "put item cell close"; break;
        case SKILL__PUT_ITEM_CELL_FAR:          name = "put item cell far"; break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:    name = "put item dynamite close"; break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:      name = "put item dynamite far"; break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:    name = "put item gemstone close"; break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:      name = "put item gemstone far"; break;

        case SKILL__THROW_ITEM_CELL:            name = "throw item cell"; break;
        case SKILL__THROW_ITEM_DYNAMITE:        name = "throw item dynamite"; break;
        case SKILL__THROW_ITEM_GEMSTONE:        name = "throw item gemstone"; break;

        case SKILL__PUSH:               name = "push"; break;
        case SKILL__THROW:              name = "throw"; break;
        case SKILL__DRAG:               name = "drag"; break;
        case SKILL__PULL:               name = "pull"; break;
        case SKILL__JUMP:               name = "jump"; break;
        case SKILL__CHARGE:             name = "charge"; break;
        case SKILL__STOMP:              name = "stomp"; break;

        case SKILL__DRAG_AND_THROW:     name = "drag and throw"; break;
        case SKILL__CHARGE_AND_PUSH:    name = "charge and push"; break;
        case SKILL__CHARGE_AND_THROW:   name = "charge and throw"; break;
        case SKILL__CHARGE_AND_JUMP:    name = "charge and jump"; break;
        case SKILL__JUMP_AND_CARRY:     name = "jump and carry"; break;
        case SKILL__JUMP_AND_STOMP:     name = "jump and stomp"; break;

        case SKILL__LAUNCH_MINIBOT:     name = "launch minibot"; break;
        case SKILL__ASCEND:             name = "ascend"; break;
        case SKILL__DESCEND:            name = "descend"; break;

        case SKILL__TURRET_LASER:       name = "turret laser"; break;
        case SKILL__TURRET_BOMB:        name = "turret bomb"; break;
        case SKILL__TURRET_PROJECTILE:  name = "turret projectile"; break;

        case SKILL__MINIBOT_MERGE:      name = "minibot merge"; break;

        default: break;
    }

    return name;
}
