#include "action.h"

Action* new_action_none()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__NONE;

    return action;
}

Action* new_action_sequence()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__SEQUENCE;

    action->sequence.curr_action = 0;
    action->sequence.action_head = new_action_none();

    return action;
}

Action* new_action_sequence_of_1(Action* action_1)
{
    Action* sequence = new_action_sequence();
    add_action_to_end_after_action(sequence->sequence.action_head, action_1);
    return sequence;
}

Action* new_action_sequence_of_2(Action* action_1, Action* action_2)
{
    Action* sequence = new_action_sequence();
    add_action_to_end_after_action(sequence->sequence.action_head, action_1);
    add_action_to_end_after_action(sequence->sequence.action_head, action_2);
    return sequence;
}

Action* new_action_sequence_of_3(Action* action_1, Action* action_2, Action* action_3)
{
    Action* sequence = new_action_sequence();
    add_action_to_end_after_action(sequence->sequence.action_head, action_1);
    add_action_to_end_after_action(sequence->sequence.action_head, action_2);
    add_action_to_end_after_action(sequence->sequence.action_head, action_3);
    return sequence;
}

void add_action_after_action(Action* action, Action* new_action)
{
    new_action->next = action->next;
    action->next = new_action;
}

void add_action_to_end_after_action(Action* action, Action* new_action)
{
    Action* curr_action = action;
    while(curr_action->next)
    {
        curr_action = curr_action->next;
    }
    add_action_after_action(curr_action, new_action);
}

void remove_all_actions_after_action(Action* action)
{
    Action* curr_action = action->next;
    Action* next_action = (curr_action) ? (curr_action->next) : 0;
    while(curr_action)
    {
        destroy_action(curr_action);
        curr_action = next_action;
        next_action = (curr_action) ? (curr_action->next) : 0;
    }
    action->next = 0;
}

Action* new_action_simultaneous()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__SIMULTANEOUS;

    action->simultaneous.action_head = 0;
    action->simultaneous.action_tail = 0;

    return action;
}

Action* new_action_simultaneous_of_1(Action* action_1)
{
    Action* simultaneous = new_action_simultaneous();
    add_action_sequence_to_action_simultaneous(simultaneous, new_action_sequence_of_1(action_1));
    return simultaneous;
}

Action* new_action_simultaneous_of_2(Action* action_1, Action* action_2)
{
    Action* simultaneous = new_action_simultaneous();
    add_action_sequence_to_action_simultaneous(simultaneous, new_action_sequence_of_1(action_1));
    add_action_sequence_to_action_simultaneous(simultaneous, new_action_sequence_of_1(action_2));
    return simultaneous;
}

Action* new_action_simultaneous_of_3(Action* action_1, Action* action_2, Action* action_3)
{
    Action* simultaneous = new_action_simultaneous();
    add_action_sequence_to_action_simultaneous(simultaneous, new_action_sequence_of_1(action_1));
    add_action_sequence_to_action_simultaneous(simultaneous, new_action_sequence_of_1(action_2));
    add_action_sequence_to_action_simultaneous(simultaneous, new_action_sequence_of_1(action_3));
    return simultaneous;
}

void add_action_sequence_to_action_simultaneous(Action* action_simultaneous, Action* new_action_sequence)
{
    if(action_simultaneous->simultaneous.action_head)
    {
        action_simultaneous->simultaneous.action_tail->next = new_action_sequence;
    }
    else
    {
        action_simultaneous->simultaneous.action_head = new_action_sequence;
    }

    action_simultaneous->simultaneous.action_tail = new_action_sequence;
    new_action_sequence->next = 0;
}

Action* new_action_move(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE;
    
    action->move.is_move_blocked = 0;

    action->move.object = object;
    action->move.dir4 = dir4;

    return action;
}

Action* new_action_push(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__PUSH;

    action->push.is_move_blocked = 0;

    action->push.object = object;
    action->push.dir4 = dir4;

    return action;
}

Action* new_action_crash(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__CRASH;

    action->crash.object = object;
    action->crash.dir4 = dir4;

    return action;
}

Action* new_action_fall(Object* object)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__FALL;

    action->fall.object = object;

    return action;
}

Action* new_action_death(Object* object)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->animation = 0;
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
        case ACTION_TYPE__FALL:                             name = "fall";                              break;
        case ACTION_TYPE__DEATH:                            name = "death";                             break;
        case ACTION_TYPE__COUNT:                            name = "count";                             break;
        default: break;
    }

    return name;
}