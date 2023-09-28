#include "action.h"

Action* new_action_none()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__NONE;

    return action;
}

Action* new_action_sequence()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__SEQUENCE;

    action->sequence.curr_action = 0;
    action->sequence.action_head = 0;
    action->sequence.action_tail = 0;

    return action;
}

void add_action_to_end_action_sequence(Action* action_sequence, Action* new_action)
{
    if(action_sequence->sequence.action_head)
    {
        action_sequence->sequence.action_tail->next = new_action;
    }
    else
    {
        action_sequence->sequence.action_head = new_action;
    }

    action_sequence->sequence.action_tail = new_action;
    new_action->next = 0;
}

Action* new_action_simultaneous()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__SIMULTANEOUS;

    action->simultaneous.are_all_actions_finished = 0;
    action->simultaneous.action_head = 0;
    action->simultaneous.action_tail = 0;

    return action;
}

void add_action_to_end_action_simultaneous(Action* action_simultaneous, Action* new_action)
{
    if(action_simultaneous->simultaneous.action_head)
    {
        action_simultaneous->simultaneous.action_tail->next = new_action;
    }
    else
    {
        action_simultaneous->simultaneous.action_head = new_action;
    }

    action_simultaneous->simultaneous.action_tail = new_action;
    new_action->next = 0;
}

Action* new_action_move(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE;
    
    action->move.animation_move_sprite_in_gamemap = 0;
    action->move.is_move_blocked = 0;

    action->move.object = object;
    action->move.dir4 = dir4;

    return action;
}

Action* new_action_push(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__PUSH;
    
    action->push.animation_move_sprite_in_gamemap = 0;
    action->push.is_move_blocked = 0;

    action->push.object = object;
    action->push.dir4 = dir4;

    return action;
}

Action* new_action_crash(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__CRASH;

    action->crash.animation_sequence = 0;

    action->crash.object = object;
    action->crash.dir4 = dir4;

    return action;
}

Action* new_action_drop(Object* object)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DROP;

    action->drop.animation_drop_sprite_in_tilemap = 0;

    action->drop.object = object;

    return action;
}

Action* new_action_death(Object* object)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DEATH;

    action->death.object = object;

    return action;
}

void destroy_action(Action* action)
{
    free(action);
}

char* get_action_name_from_type(int action_type)
{
    char* name = "";

    switch(action_type)
    {
        case ACTION_TYPE__NONE:                             name = "none";                              break;
        case ACTION_TYPE__SEQUENCE:                         name = "sequence";                          break;
        case ACTION_TYPE__SIMULTANEOUS:                     name = "simultaneous";                      break;
        case ACTION_TYPE__MOVE:                             name = "move";                              break;
        case ACTION_TYPE__PUSH:                             name = "push";                              break;
        case ACTION_TYPE__CRASH:                            name = "crash";                             break;
        case ACTION_TYPE__DROP:                             name = "drop";                              break;
        case ACTION_TYPE__DEATH:                            name = "death";                             break;
        case ACTION_TYPE__COUNT:                            name = "count";                             break;
        default: break;
    }

    return name;
}