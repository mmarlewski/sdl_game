#include "../inc/action.h"

Action* new_action_none()
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = vec2i(-1, -1);
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__NONE;

    return action;
}

Action* new_action_sequence()
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = vec2i(-1, -1);
    action->is_finished = 0;
    action->is_finished_at_start = 0;
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
    action->tilemap_pos = vec2i(-1, -1);
    action->is_finished = 0;
    action->is_finished_at_start = 0;
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

Action* new_action_move(Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__MOVE;

    action->move.dir4 = dir4;
    action->move.object = 0;

    return action;
}

Action* new_action_crash(Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__CRASH;

    action->crash.dir4 = dir4;
    action->crash.object_crushing = 0;
    action->crash.object_crushed = 0;

    return action;
}

Action* new_action_fall(Object* object, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__FALL;

    action->fall.object = object;

    return action;
}

Action* new_action_death(Object* object, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__DEATH;

    action->death.object = object;

    return action;
}

Action* new_action_blow_up(Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__BLOW_UP;

    return action;
}

Action* new_action_throw( Vec2i tilemap_pos, int dir4, int distance)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__THROW;

    action->throw.dir4 = dir4;
    action->throw.distance = distance;
    action->throw.object_thrown = 0;
    action->throw.object_on_target = 0;

    return action;
}

Action* new_action_lift( Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__LIFT;

    action->lift.dir4 = dir4;
    action->lift.object = 0;

    return action;
}

Action* new_action_drop(Object* object, Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__DROP;

    action->drop.object = object;
    action->drop.dir4 = dir4;

    return action;
}

Action* new_action_change(int is_change_object, int new_object_type, int new_floor_type, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(* action));

    action->animation = 0;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = 0;
    action->is_finished_at_start = 0;
    action->type = ACTION_TYPE__CHANGE;

    action->change.is_change_object = is_change_object;
    action->change.new_object_type = new_object_type;
    action->change.new_floor_type = new_floor_type;

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
        case ACTION_TYPE__MOVE:         name = "move";          break;
        case ACTION_TYPE__CRASH:        name = "crash";         break;
        case ACTION_TYPE__FALL:         name = "fall";          break;
        case ACTION_TYPE__DEATH:        name = "death";         break;
        case ACTION_TYPE__BLOW_UP:      name = "blow up";       break;
        case ACTION_TYPE__THROW:        name = "throw";         break;
        case ACTION_TYPE__LIFT:         name = "lift";          break;
        case ACTION_TYPE__DROP:         name = "drop";          break;
        case ACTION_TYPE__CHANGE:       name = "change";        break;
        case ACTION_TYPE__COUNT:        name = "count";         break;
        default: break;
    }

    return name;
}
