#include "../inc/action.h"

Action* new_action_none()
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = make_vec2i(-1, -1);
    action->is_finished = 0;
    action->type = ACTION_TYPE__NONE;

    return action;
}

Action* new_action_sequence()
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = make_vec2i(-1, -1);
    action->is_finished = 0;
    action->type = ACTION_TYPE__SEQUENCE;

    action->sequence.action_list = new_list((void(*)(void*))&destroy_action);
    action->sequence.curr_action_list_elem = 0;

    return action;
}

Action* new_action_sequence_of_1(Action* action_1)
{
    Action* sequence = new_action_sequence();
    add_action_to_end_action_sequence(sequence, action_1);
    return sequence;
}

Action* new_action_sequence_of_2(Action* action_1, Action* action_2)
{
    Action* sequence = new_action_sequence();
    add_action_to_end_action_sequence(sequence, action_1);
    add_action_to_end_action_sequence(sequence, action_2);
    return sequence;
}

Action* new_action_sequence_of_3(Action* action_1, Action* action_2, Action* action_3)
{
    Action* sequence = new_action_sequence();
    add_action_to_end_action_sequence(sequence, action_1);
    add_action_to_end_action_sequence(sequence, action_2);
    add_action_to_end_action_sequence(sequence, action_3);
    return sequence;
}

void add_action_to_end_action_sequence(Action* sequence, Action* new_action)
{
    add_new_list_element_to_list_end(sequence->sequence.action_list, new_action);
}

void add_action_after_curr_action_action_sequence(Action* sequence, Action* new_action)
{
    add_new_list_element_after_element(sequence->sequence.action_list, sequence->sequence.curr_action_list_elem, new_action);
}

void remove_all_actions_after_curr_action_action_sequence(Action* sequence)
{
    remove_all_list_elements_after_element(sequence->sequence.action_list, sequence->sequence.curr_action_list_elem, 1);
}

Action* new_action_simultaneous()
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = make_vec2i(-1, -1);
    action->is_finished = 0;
    action->type = ACTION_TYPE__SIMULTANEOUS;

    action->simultaneous.action_list = new_list((void(*)(void*))&destroy_action);

    return action;
}

Action* new_action_simultaneous_of_1(Action* action_1)
{
    Action* simultaneous = new_action_simultaneous();
    add_action_sequence_to_action_simultaneous(simultaneous, action_1);
    return simultaneous;
}

Action* new_action_simultaneous_of_2(Action* action_1, Action* action_2)
{
    Action* simultaneous = new_action_simultaneous();
    add_action_sequence_to_action_simultaneous(simultaneous, action_1);
    add_action_sequence_to_action_simultaneous(simultaneous, action_2);
    return simultaneous;
}

Action* new_action_simultaneous_of_3(Action* action_1, Action* action_2, Action* action_3)
{
    Action* simultaneous = new_action_simultaneous();
    add_action_sequence_to_action_simultaneous(simultaneous, action_1);
    add_action_sequence_to_action_simultaneous(simultaneous, action_2);
    add_action_sequence_to_action_simultaneous(simultaneous, action_3);
    return simultaneous;
}

void add_action_sequence_to_action_simultaneous(Action* simultaneous, Action* new_sequence)
{
    add_new_list_element_to_list_end(simultaneous->simultaneous.action_list, new_sequence);
}

Action* new_action_move_ground(Object* object, vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_GROUND;

    action->move_ground.is_move_blocked = 0;

    action->move_ground.object = object;
    action->move_ground.dir4 = dir4;

    return action;
}

Action* new_action_move_air(Object* object, vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_AIR;

    action->move_air.is_move_blocked = 0;

    action->move_air.object = object;
    action->move_air.dir4 = dir4;

    return action;
}

Action* new_action_crash_ground(Object* object_crushing, Object* object_crushed, vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__CRASH_GROUND;

    action->crash_ground.object_crushing = object_crushing;
    action->crash_ground.object_crushed = object_crushed;
    action->crash_ground.dir4 = dir4;

    return action;
}

Action* new_action_crash_air(Object* object_crushing, Object* object_crushed, vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__CRASH_AIR;

    action->crash_air.object_crushing = object_crushing;
    action->crash_air.object_crushed = object_crushed;
    action->crash_air.dir4 = dir4;

    return action;
}

Action* new_action_fall(Object* object, vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__FALL;

    action->fall.object = object;

    return action;
}

Action* new_action_death(Object* object, vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DEATH;

    action->death.object = object;

    return action;
}

Action* new_action_blow_up(vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__BLOW_UP;

    return action;
}

Action* new_action_throw(Object* object, vec2i tilemap_pos, int dir4, int distance)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__THROW;

    action->throw.object = object;
    action->throw.dir4 = dir4;
    action->throw.distance = distance;

    return action;
}

Action* new_action_drop(Object* object, vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DROP;

    action->drop.object = object;
    action->drop.dir4 = dir4;

    return action;
}

void destroy_action(Action* action)
{
    if(action->type == ACTION_TYPE__SEQUENCE)
    {
        destroy_list(action->sequence.action_list);
    }

    if(action->type == ACTION_TYPE__SIMULTANEOUS)
    {
        destroy_list(action->simultaneous.action_list);
    }

    free(action);
}

char* get_action_name_from_type(int action_type)
{
    char* name = "";

    switch(action_type)
    {
        case ACTION_TYPE__NONE:         name = "none";          break;
        case ACTION_TYPE__SEQUENCE:     name = "sequence";      break;
        case ACTION_TYPE__SIMULTANEOUS: name = "simultaneous";  break;
        case ACTION_TYPE__MOVE_GROUND:  name = "move_ground";   break;
        case ACTION_TYPE__MOVE_AIR:     name = "move_air";      break;
        case ACTION_TYPE__CRASH_GROUND: name = "crash_ground";  break;
        case ACTION_TYPE__CRASH_AIR:    name = "crash_air";     break;
        case ACTION_TYPE__FALL:         name = "fall";          break;
        case ACTION_TYPE__DEATH:        name = "death";         break;
        case ACTION_TYPE__BLOW_UP:      name = "blow up";       break;
        case ACTION_TYPE__THROW:        name = "throw";         break;
        case ACTION_TYPE__DROP:         name = "drop";          break;
        case ACTION_TYPE__COUNT:        name = "count";         break;
        default: break;
    }

    return name;
}
