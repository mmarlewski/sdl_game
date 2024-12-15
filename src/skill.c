#include "../inc/state.h"

int is_skill_two_target(int skill)
{
    int is = 0;

    switch(skill)
    {
        case SKILL__NONE:                       is = 0; break;

        case SKILL__ATTACK_DIR:                 is = 0; break;
        case SKILL__NO_ATTACK:                  is = 0; break;

        case SKILL__USE:                        is = 0; break;
        case SKILL__MANIPULATION:               is = 0; break;
        case SKILL__TELEPORTATION:              is = 0; break;
        case SKILL__TELEKINESIS:                is = 1; break;

        case SKILL__MOVE:                       is = 0; break;
        case SKILL__MOVE_FLOATING:              is = 0; break;
        case SKILL__MOVE_FLYING:                is = 0; break;

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

        case SKILL__SHOOT_PROJECTILE_FLY:       is = 0; break;
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:  is = 0; break;

        case SKILL__PUSH:                       is = 1; break;
        case SKILL__THROW:                      is = 1; break;
        case SKILL__PULL_HOOK:                  is = 1; break;
        case SKILL__PULL_SPIDERWEB:             is = 1; break;
        case SKILL__PULL_TENTACLE:              is = 1; break;
        case SKILL__PULL_TONGUE:                is = 1; break;
        case SKILL__DRAG_HOOK:                  is = 1; break;
        case SKILL__DRAG_SPIDERWEB:             is = 1; break;
        case SKILL__DRAG_TENTACLE:              is = 1; break;
        case SKILL__JUMP:                       is = 0; break;
        case SKILL__CHARGE:                     is = 0; break;
        case SKILL__STOMP:                      is = 0; break;

        case SKILL__DRAG_AND_THROW_HOOK:        is = 1; break;
        case SKILL__DRAG_AND_THROW_TONGUE:      is = 1; break;
        case SKILL__CHARGE_AND_PUSH:            is = 1; break;
        case SKILL__CHARGE_AND_THROW:           is = 1; break;
        case SKILL__CHARGE_AND_JUMP:            is = 1; break;
        case SKILL__JUMP_AND_CARRY:             is = 1; break;
        case SKILL__JUMP_AND_STOMP:             is = 0; break;

        case SKILL__LAUNCH_MINIBOT:             is = 0; break;
        case SKILL__MINIBOT_MERGE:              is = 0; break;

        case SKILL__TURRET_LASER:               is = 0; break;
        case SKILL__TURRET_BOMB:                is = 0; break;
        case SKILL__TURRET_PROJECTILE:          is = 0; break;

        case SKILL__KILL_AROUND:                is = 0; break;

        case SKILL__ENVIRONMENT_FALLING_STALACTITE: is = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_WATER:       is = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_PIT:         is = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_BURROW:      is = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_PIPE:        is = 0; break;
        case SKILL__ENVIRONMENT_COLLAPSE_BURROW:    is = 0; break;
        case SKILL__ENVIRONMENT_CONV_BELT:          is = 0; break;

        default: break;
    }

    return is;
}

int get_skill_action_points(int skill)
{
    int ap = 0;

    switch(skill)
    {
        case SKILL__NONE:                       ap = 0; break;

        case SKILL__ATTACK_DIR:                 ap = 0; break;
        case SKILL__NO_ATTACK:                  ap = 0; break;

        case SKILL__USE:                        ap = 1; break;
        case SKILL__MANIPULATION:               ap = 1; break;
        case SKILL__TELEPORTATION:              ap = 1; break;
        case SKILL__TELEKINESIS:                ap = 1; break;

        case SKILL__MOVE:                       ap = -1; break;
        case SKILL__MOVE_FLOATING:              ap = -1; break;
        case SKILL__MOVE_FLYING:                ap = -1; break;

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

        case SKILL__SHOOT_PROJECTILE_FLY:       ap = 1; break;
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:  ap = 1; break;

        case SKILL__PUSH:                       ap = 1; break;
        case SKILL__THROW:                      ap = 1; break;
        case SKILL__PULL_HOOK:                  ap = 1; break;
        case SKILL__PULL_SPIDERWEB:             ap = 1; break;
        case SKILL__PULL_TENTACLE:              ap = 1; break;
        case SKILL__PULL_TONGUE:                ap = 1; break;
        case SKILL__DRAG_HOOK:                  ap = 1; break;
        case SKILL__DRAG_SPIDERWEB:             ap = 1; break;
        case SKILL__DRAG_TENTACLE:              ap = 1; break;
        case SKILL__JUMP:                       ap = 1; break;
        case SKILL__CHARGE:                     ap = 1; break;
        case SKILL__STOMP:                      ap = 1; break;

        case SKILL__DRAG_AND_THROW_HOOK:        ap = 1; break;
        case SKILL__DRAG_AND_THROW_TONGUE:      ap = 1; break;
        case SKILL__CHARGE_AND_PUSH:            ap = 1; break;
        case SKILL__CHARGE_AND_THROW:           ap = 1; break;
        case SKILL__CHARGE_AND_JUMP:            ap = 1; break;
        case SKILL__JUMP_AND_CARRY:             ap = 1; break;
        case SKILL__JUMP_AND_STOMP:             ap = 1; break;

        case SKILL__LAUNCH_MINIBOT:             ap = 1; break;
        case SKILL__MINIBOT_MERGE:              ap = 1; break;

        case SKILL__TURRET_LASER:               ap = 1; break;
        case SKILL__TURRET_BOMB:                ap = 1; break;
        case SKILL__TURRET_PROJECTILE:          ap = 1; break;

        case SKILL__KILL_AROUND:                ap = 1; break;

        case SKILL__ENVIRONMENT_FALLING_STALACTITE: ap = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_WATER:       ap = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_PIT:         ap = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_BURROW:      ap = 0; break;
        case SKILL__ENVIRONMENT_EMERGE_PIPE:        ap = 0; break;
        case SKILL__ENVIRONMENT_COLLAPSE_BURROW:    ap = 0; break;
        case SKILL__ENVIRONMENT_CONV_BELT:          ap = 0; break;

        default: break;
    }

    return ap;
}

char* get_in_game_skill_name(int skill)
{
    char* name = "???";

    switch(skill)
    {
        case SKILL__NONE:                       name = "--"; break;

        case SKILL__ATTACK_DIR:                 name = "---"; break;
        case SKILL__NO_ATTACK:                  name = "no attack"; break;

        case SKILL__USE:                        name = "use"; break;
        case SKILL__MANIPULATION:               name = "manipulation"; break;
        case SKILL__TELEPORTATION:              name = "teleportation"; break;
        case SKILL__TELEKINESIS:                name = "telekinesis"; break;

        case SKILL__MOVE:                       name = "move"; break;
        case SKILL__MOVE_FLOATING:              name = "move"; break;
        case SKILL__MOVE_FLYING:                name = "move"; break;

        case SKILL__PICK_ITEM_CLOSE:            name = "pick item"; break;
        case SKILL__PICK_ITEM_FAR:              name = "pick item (far)"; break;

        case SKILL__PUT_ITEM_CELL_CLOSE:        name = "put cell"; break;
        case SKILL__PUT_ITEM_CELL_FAR:          name = "put cell (far)"; break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:    name = "put dynamite"; break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:      name = "put dynamite (far)"; break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:    name = "put gemstone"; break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:      name = "put gemstone (far)"; break;

        case SKILL__THROW_ITEM_CELL:            name = "throw cell"; break;
        case SKILL__THROW_ITEM_DYNAMITE:        name = "throw dynamite"; break;
        case SKILL__THROW_ITEM_GEMSTONE:        name = "throw gemstone"; break;

        case SKILL__SHOOT_PROJECTILE_FLY:       name = "shoot projectile"; break;
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:  name = "shoot projectile"; break;

        case SKILL__PUSH:                       name = "push"; break;
        case SKILL__THROW:                      name = "throw"; break;
        case SKILL__PULL_HOOK:                  name = "pull"; break;
        case SKILL__PULL_SPIDERWEB:             name = "pull"; break;
        case SKILL__PULL_TENTACLE:              name = "pull"; break;
        case SKILL__PULL_TONGUE:                name = "pull"; break;
        case SKILL__DRAG_HOOK:                  name = "drag"; break;
        case SKILL__DRAG_SPIDERWEB:             name = "drag"; break;
        case SKILL__DRAG_TENTACLE:              name = "drag"; break;
        case SKILL__JUMP:                       name = "jump"; break;
        case SKILL__CHARGE:                     name = "charge"; break;
        case SKILL__STOMP:                      name = "stomp"; break;

        case SKILL__DRAG_AND_THROW_HOOK:        name = "drag and throw"; break;
        case SKILL__DRAG_AND_THROW_TONGUE:      name = "drag and throw"; break;
        case SKILL__CHARGE_AND_PUSH:            name = "charge and push"; break;
        case SKILL__CHARGE_AND_THROW:           name = "charge and throw"; break;
        case SKILL__CHARGE_AND_JUMP:            name = "charge and jump"; break;
        case SKILL__JUMP_AND_CARRY:             name = "jump and carry"; break;
        case SKILL__JUMP_AND_STOMP:             name = "jump and stomp"; break;

        case SKILL__LAUNCH_MINIBOT:             name = "launch minibot"; break;
        case SKILL__MINIBOT_MERGE:              name = "minibot merge"; break;

        case SKILL__TURRET_LASER:               name = "turret laser"; break;
        case SKILL__TURRET_BOMB:                name = "turret bomb"; break;
        case SKILL__TURRET_PROJECTILE:          name = "turret projectile"; break;

        case SKILL__KILL_AROUND:                name = "kill around"; break;

        case SKILL__ENVIRONMENT_FALLING_STALACTITE: name = "stalactite falling !"; break;
        case SKILL__ENVIRONMENT_EMERGE_WATER:       name = "enemy emerge !"; break;
        case SKILL__ENVIRONMENT_EMERGE_PIT:         name = "enemy emerge !"; break;
        case SKILL__ENVIRONMENT_EMERGE_BURROW:      name = "enemy emerge !"; break;
        case SKILL__ENVIRONMENT_EMERGE_PIPE:        name = "enemy emerge !"; break;
        case SKILL__ENVIRONMENT_COLLAPSE_BURROW:    name = "floor collapsing !"; break;
        case SKILL__ENVIRONMENT_CONV_BELT:          name = "conveyor belt !"; break;

        default: break;
    }

    return name;
}

char* get_debug_skill_name(int skill)
{
    char* name = "???";

    switch(skill)
    {
        case SKILL__NONE:                       name = "none"; break;

        case SKILL__ATTACK_DIR:                 name = "attack dir"; break;
        case SKILL__NO_ATTACK:                  name = "no attack"; break;

        case SKILL__USE:                        name = "use"; break;
        case SKILL__MANIPULATION:               name = "manipulation"; break;
        case SKILL__TELEPORTATION:              name = "teleportation"; break;
        case SKILL__TELEKINESIS:                name = "telekinesis"; break;

        case SKILL__MOVE:                       name = "move"; break;
        case SKILL__MOVE_FLOATING:              name = "move floating"; break;
        case SKILL__MOVE_FLYING:                name = "move flying"; break;

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

        case SKILL__SHOOT_PROJECTILE_FLY:       name = "shoot projectile fly"; break;
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:  name = "shoot projectile squirrel"; break;

        case SKILL__PUSH:                       name = "push"; break;
        case SKILL__THROW:                      name = "throw"; break;
        case SKILL__PULL_HOOK:                  name = "pull hook"; break;
        case SKILL__PULL_SPIDERWEB:             name = "pull spiderweb"; break;
        case SKILL__PULL_TENTACLE:              name = "pull tentacle"; break;
        case SKILL__PULL_TONGUE:                name = "pull tongue"; break;
        case SKILL__DRAG_HOOK:                  name = "drag hook"; break;
        case SKILL__DRAG_SPIDERWEB:             name = "drag spiderweb"; break;
        case SKILL__DRAG_TENTACLE:              name = "drag tentacle"; break;
        case SKILL__JUMP:                       name = "jump"; break;
        case SKILL__CHARGE:                     name = "charge"; break;
        case SKILL__STOMP:                      name = "stomp"; break;

        case SKILL__DRAG_AND_THROW_HOOK:        name = "drag and throw hook"; break;
        case SKILL__DRAG_AND_THROW_TONGUE:      name = "drag and throw tongue"; break;
        case SKILL__CHARGE_AND_PUSH:            name = "charge and push"; break;
        case SKILL__CHARGE_AND_THROW:           name = "charge and throw"; break;
        case SKILL__CHARGE_AND_JUMP:            name = "charge and jump"; break;
        case SKILL__JUMP_AND_CARRY:             name = "jump and carry"; break;
        case SKILL__JUMP_AND_STOMP:             name = "jump and stomp"; break;

        case SKILL__LAUNCH_MINIBOT:             name = "launch minibot"; break;
        case SKILL__MINIBOT_MERGE:              name = "minibot merge"; break;

        case SKILL__TURRET_LASER:               name = "turret laser"; break;
        case SKILL__TURRET_BOMB:                name = "turret bomb"; break;
        case SKILL__TURRET_PROJECTILE:          name = "turret projectile"; break;

        case SKILL__KILL_AROUND:                name = "kill around"; break;

        case SKILL__ENVIRONMENT_FALLING_STALACTITE: name = "environment falling stalactite"; break;
        case SKILL__ENVIRONMENT_EMERGE_WATER:       name = "environment emerge water"; break;
        case SKILL__ENVIRONMENT_EMERGE_PIT:         name = "environment emerge pit"; break;
        case SKILL__ENVIRONMENT_EMERGE_BURROW:      name = "environment emerge burrow"; break;
        case SKILL__ENVIRONMENT_EMERGE_PIPE:        name = "environment emerge pipe"; break;
        case SKILL__ENVIRONMENT_COLLAPSE_BURROW:    name = "environment collapse burrow"; break;
        case SKILL__ENVIRONMENT_CONV_BELT:          name = "environment conv belt"; break;

        default: break;
    }

    return name;
}

char* get_description_from_skill(int skill, int i)
{
    char* description = "";

    switch(skill)
    {
        case SKILL__NONE:
        {
            switch(i)
            {
                case 1: description = "(no skill)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ATTACK_DIR:
        {
            switch(i)
            {
                case 1: description = "(no attack)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__NO_ATTACK:
        {
            switch(i)
            {
                case 1: description = "(no attack)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__USE:
        {
            switch(i)
            {
                case 1: description = "use *EXITS* to travel between rooms"; break;
                case 2: description = "or *STATIONS* to add augmentations"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            switch(i)
            {
                case 1: description = "remotely manipulate objects or floors,"; break;
                case 2: description = "turn them *ON* and *OFF*"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__TELEPORTATION:
        {
            switch(i)
            {
                case 1: description = "teleport to any place in room"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__TELEKINESIS:
        {
            switch(i)
            {
                case 1: description = "move any object in room across space"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__MOVE:
        {
            switch(i)
            {
                case 1: description = "move through tiles"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__MOVE_FLOATING:
        {
            switch(i)
            {
                case 1: description = "move through tiles"; break;
                case 2: description = "(can move through water and lava tiles)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__MOVE_FLYING:
        {
            switch(i)
            {
                case 1: description = "move through tiles"; break;
                case 2: description = "(can move through pit tiles)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        {
            switch(i)
            {
                case 1: description = "pick items from objects"; break;
                case 2: description = "(can only pick from nearby objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PICK_ITEM_FAR:
        {
            switch(i)
            {
                case 1: description = "pick items from objects"; break;
                case 2: description = "(can pick from FAR away objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_CLOSE:
        {
            switch(i)
            {
                case 1: description = "put a *CELL* item into an object"; break;
                case 2: description = "(can only put into nearby objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_FAR:
        {
            switch(i)
            {
                case 1: description = "put a *CELL* item into an object"; break;
                case 2: description = "(can put into FAR away objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
        {
            switch(i)
            {
                case 1: description = "put a *DYNAMITE* item into an object"; break;
                case 2: description = "(can only put into nearby objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:
        {
            switch(i)
            {
                case 1: description = "put a *DYNAMITE* item into an object"; break;
                case 2: description = "(can put into FAR away objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
        {
            switch(i)
            {
                case 1: description = "put a *GEMSTONE* item into an object"; break;
                case 2: description = "(can only put into nearby objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:
        {
            switch(i)
            {
                case 1: description = "put a *GEMSTONE* item into an object"; break;
                case 2: description = "(can put into FAR away objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            switch(i)
            {
                case 1: description = "throw a *CELL* item on object or floor"; break;
                case 2: description = "(melt *METAL* objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            switch(i)
            {
                case 1: description = "throw a *DYNAMITE* item on object or floor"; break;
                case 2: description = "(break *STONE* objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            switch(i)
            {
                case 1: description = "throw a *GEMSTONE* item on object or floor"; break;
                case 2: description = "(shake *GLASS* objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__SHOOT_PROJECTILE_FLY:
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:
        {
            switch(i)
            {
                case 1: description = "shoot a projectile in straight line"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PUSH:
        {
            switch(i)
            {
                case 1: description = "push an object"; break;
                case 2: description = "(you can't move *STABLE objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__THROW:
        {
            switch(i)
            {
                case 1: description = "throw an object"; break;
                case 2: description = "(you can't move *STABLE objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__PULL_HOOK:
        case SKILL__PULL_SPIDERWEB:
        case SKILL__PULL_TENTACLE:
        case SKILL__PULL_TONGUE:
        {
            switch(i)
            {
                case 1: description = "pull yourself towards a *STABLE* object"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__DRAG_HOOK:
        case SKILL__DRAG_SPIDERWEB:
        case SKILL__DRAG_TENTACLE:
        {
            switch(i)
            {
                case 1: description = "drag an object towards you"; break;
                case 2: description = "(you can't move *STABLE objects)"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__JUMP:
        {
            switch(i)
            {
                case 1: description = "jump over other objects"; break;
                case 2: description = "and over tiles"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__CHARGE:
        {
            switch(i)
            {
                case 1: description = "charge in a straight line"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__STOMP:
        {
            switch(i)
            {
                case 1: description = "damage certain floors"; break;
                case 2: description = "or kill small enemies"; break;
                case 3: description = "while shaking nearby objects"; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__DRAG_AND_THROW_HOOK:
        case SKILL__DRAG_AND_THROW_TONGUE:
        {
            switch(i)
            {
                case 1: description = "drag an object towards you"; break;
                case 2: description = "then throw it behind you"; break;
                case 3: description = "(you can't move *STABLE objects)"; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            switch(i)
            {
                case 1: description = "charge in a straight line"; break;
                case 2: description = "then push another object"; break;
                case 3: description = "(greater push distance)"; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            switch(i)
            {
                case 1: description = "charge in a straight line"; break;
                case 2: description = "then throw another object"; break;
                case 3: description = "(greater throw distance)"; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__CHARGE_AND_JUMP:
        {
            switch(i)
            {
                case 1: description = "charge in a straight line"; break;
                case 2: description = "then jump"; break;
                case 3: description = "(greater jump distance)"; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__JUMP_AND_CARRY:
        {
            switch(i)
            {
                case 1: description = "jump over other objects"; break;
                case 2: description = "while carrying another object"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__JUMP_AND_STOMP:
        {
            switch(i)
            {
                case 1: description = "jump over other objects"; break;
                case 2: description = "then stomp nearby objects or floors"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__LAUNCH_MINIBOT:
        {
            switch(i)
            {
                case 1: description = "launch an ally *MINIBOT*"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__MINIBOT_MERGE:
        {
            switch(i)
            {
                case 1: description = "merge an ally *MINIBOT* into hero"; break;
                case 2: description = "so it can be launched again"; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__TURRET_LASER:
        {
            switch(i)
            {
                case 1: description = "shoot a laser in a straight line"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            switch(i)
            {
                case 1: description = "throw a bomb over another objects"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            switch(i)
            {
                case 1: description = "shoot a projectile in a straight line"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__KILL_AROUND:
        {
            switch(i)
            {
                case 1: description = "kill all nearby objects"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ENVIRONMENT_FALLING_STALACTITE:
        {
            switch(i)
            {
                case 1: description = "(environment falling stalactite)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_WATER:
        {
            switch(i)
            {
                case 1: description = "(environment emerge water)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_PIT:
        {
            switch(i)
            {
                case 1: description = "(environment emerge pit)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_BURROW:
        {
            switch(i)
            {
                case 1: description = "(environment emerge burrow)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_PIPE:
        {
            switch(i)
            {
                case 1: description = "(environment emerge pipe)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ENVIRONMENT_COLLAPSE_BURROW:
        {
            switch(i)
            {
                case 1: description = "(environment collapse burrow)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        case SKILL__ENVIRONMENT_CONV_BELT:
        {
            switch(i)
            {
                case 1: description = "(environment conv belt)"; break;
                case 2: description = ""; break;
                case 3: description = ""; break;
                case 4: description = ""; break;
                default: break;
            }
        }
        break;
        default:
        break;
    }

    return description;
}

Texture* get_skill_hud_texture(int skill, Textures* textures)
{
    Texture* texture = NULL;

    switch(skill)
    {
        case SKILL__USE:                        texture = textures->hud.use; break;
        case SKILL__MANIPULATION:               texture = textures->hud.manipulation; break;
        case SKILL__TELEPORTATION:              texture = textures->hud.teleportation; break;
        case SKILL__TELEKINESIS:                texture = textures->hud.telekinesis; break;

        case SKILL__MOVE:                       texture = textures->hud.move; break;
        case SKILL__MOVE_FLOATING:              texture = textures->hud.move; break;
        case SKILL__MOVE_FLYING:                texture = textures->hud.move; break;

        case SKILL__PICK_ITEM_CLOSE:            texture = textures->hud.pick_item; break;
        case SKILL__PICK_ITEM_FAR:              texture = textures->hud.pick_item_far; break;

        case SKILL__PUT_ITEM_CELL_CLOSE:        texture = textures->hud.put_item_cell; break;
        case SKILL__PUT_ITEM_CELL_FAR:          texture = textures->hud.put_item_cell_far; break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:    texture = textures->hud.put_item_dynamite; break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:      texture = textures->hud.put_item_dynamite_far; break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:    texture = textures->hud.put_item_gemstone; break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:      texture = textures->hud.put_item_gemstone_far; break;

        case SKILL__THROW_ITEM_CELL:            texture = textures->hud.throw_item_cell; break;
        case SKILL__THROW_ITEM_DYNAMITE:        texture = textures->hud.throw_item_dynamite; break;
        case SKILL__THROW_ITEM_GEMSTONE:        texture = textures->hud.throw_item_gemstone; break;

        case SKILL__SHOOT_PROJECTILE_FLY:       texture = textures->hud.shoot_projectile; break;
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:  texture = textures->hud.shoot_projectile; break;

        case SKILL__PUSH:                       texture = textures->hud.push; break;
        case SKILL__THROW:                      texture = textures->hud.throww; break;
        case SKILL__PULL_HOOK:                  texture = textures->hud.pull; break;
        case SKILL__PULL_SPIDERWEB:             texture = textures->hud.pull; break;
        case SKILL__PULL_TENTACLE:              texture = textures->hud.pull; break;
        case SKILL__PULL_TONGUE:                texture = textures->hud.pull; break;
        case SKILL__DRAG_HOOK:                  texture = textures->hud.drag; break;
        case SKILL__DRAG_SPIDERWEB:             texture = textures->hud.drag; break;
        case SKILL__DRAG_TENTACLE:              texture = textures->hud.drag; break;
        case SKILL__JUMP:                       texture = textures->hud.jump; break;
        case SKILL__CHARGE:                     texture = textures->hud.charge; break;
        case SKILL__STOMP:                      texture = textures->hud.stomp; break;

        case SKILL__DRAG_AND_THROW_HOOK:        texture = textures->hud.drag_and_throw; break;
        case SKILL__DRAG_AND_THROW_TONGUE:      texture = textures->hud.drag_and_throw; break;
        case SKILL__CHARGE_AND_PUSH:            texture = textures->hud.charge_and_push; break;
        case SKILL__CHARGE_AND_THROW:           texture = textures->hud.charge_and_throw; break;
        case SKILL__CHARGE_AND_JUMP:            texture = textures->hud.charge_and_jump; break;
        case SKILL__JUMP_AND_CARRY:             texture = textures->hud.jump_and_carry; break;
        case SKILL__JUMP_AND_STOMP:             texture = textures->hud.jump_and_stomp; break;

        case SKILL__LAUNCH_MINIBOT:             texture = textures->hud.launch_minibot; break;
        case SKILL__MINIBOT_MERGE:              texture = textures->hud.minibot_merge; break;

        case SKILL__TURRET_LASER:               texture = textures->hud.turret_laser; break;
        case SKILL__TURRET_BOMB:                texture = textures->hud.turret_bomb; break;
        case SKILL__TURRET_PROJECTILE:          texture = textures->hud.turret_projectile; break;

        case SKILL__KILL_AROUND:                texture = textures->hud.kill_around; break;

        default: break;
    }

    return texture;
}
