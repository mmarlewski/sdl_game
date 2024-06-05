#include "../inc/action.h"

Action* new_action_none()
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = vec2i(-1, -1);
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__NONE;

    return action;
}

Action* new_action_sequence()
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = vec2i(-1, -1);
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__SEQUENCE;

    action->sequence.action_list = new_list((void(*)(void*)) & destroy_action);
    action->sequence.curr_action_list_elem = NULL;

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
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = vec2i(-1, -1);
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__SIMULTANEOUS;

    action->simultaneous.action_list = new_list((void(*)(void*)) & destroy_action);

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
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__MOVE;

    action->move.dir4 = dir4;
    action->move.object = NULL;

    return action;
}

Action* new_action_move_floating(Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__MOVE_FLOATING;

    action->move.dir4 = dir4;
    action->move.object = NULL;

    return action;
}

Action* new_action_move_flying(Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__MOVE_FLYING;

    action->move.dir4 = dir4;
    action->move.object = NULL;

    return action;
}

Action* new_action_crash(Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__CRASH;

    action->crash.dir4 = dir4;
    action->crash.object_crushing = NULL;
    action->crash.object_crushed = NULL;

    return action;
}

Action* new_action_fall(Object* object, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__FALL;

    action->fall.object = object;

    return action;
}

Action* new_action_death(Object* object, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__DEATH;

    action->death.object = object;

    return action;
}

Action* new_action_blow_up(Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__BLOW_UP;

    return action;
}

Action* new_action_throw(Vec2i tilemap_pos, int dir4, int distance)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__THROW;

    action->throw.dir4 = dir4;
    action->throw.distance = distance;
    action->throw.object_thrown = NULL;
    action->throw.object_on_target = NULL;

    return action;
}

Action* new_action_lift(Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__LIFT;

    action->lift.dir4 = dir4;
    action->lift.object = NULL;

    return action;
}

Action* new_action_drop(Object* object, Vec2i tilemap_pos, int dir4)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__DROP;

    action->drop.object = object;
    action->drop.dir4 = dir4;

    return action;
}

Action* new_action_change_floor(int new_floor_type, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__CHANGE_FLOOR;

    action->change_floor.new_floor_type = new_floor_type;

    return action;
}

Action* new_action_change_object(int new_object_type, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__CHANGE_OBJECT;

    action->change_object.new_object_type = new_object_type;

    return action;
}

Action* new_action_add_object(Object* new_object, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__ADD_OBJECT;

    action->add_object.new_object = new_object;

    return action;
}

Action* new_action_remove_object(Object* object_to_remove, Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__REMOVE_OBJECT;

    action->remove_object.object_to_remove = object_to_remove;

    return action;
}

Action* new_action_change_object_tilemap_pos(Object* object, Vec2i new_tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = object->tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__CHANGE_OBJECT_TILEMAP_POS;

    action->change_object_tilemap_pos.object = object;
    action->change_object_tilemap_pos.new_tilemap_pos = new_tilemap_pos;

    return action;
}

Action* new_action_melt(Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__MELT;

    return action;
}

Action* new_action_break(Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__BREAK;

    return action;
}

Action* new_action_shake(Vec2i tilemap_pos)
{
    Action* action = malloc(sizeof(*action));

    action->animation = NULL;
    action->tilemap_pos = tilemap_pos;
    action->is_finished = FALSE;
    action->is_finished_at_start = FALSE;
    action->type = ACTION__SHAKE;

    return action;
}

void destroy_action(Action* action)
{
    if(action->type == ACTION__SEQUENCE)
    {
        destroy_list(action->sequence.action_list);
    }

    if(action->type == ACTION__SIMULTANEOUS)
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
        case ACTION__NONE:             name = "none";          break;
        case ACTION__SEQUENCE:         name = "sequence";      break;
        case ACTION__SIMULTANEOUS:     name = "simultaneous";  break;
        case ACTION__MOVE:             name = "move";          break;
        case ACTION__MOVE_FLOATING:    name = "move floating"; break;
        case ACTION__MOVE_FLYING:      name = "move flying";   break;
        case ACTION__CRASH:            name = "crash";         break;
        case ACTION__FALL:             name = "fall";          break;
        case ACTION__DEATH:            name = "death";         break;
        case ACTION__BLOW_UP:          name = "blow up";       break;
        case ACTION__THROW:            name = "throw";         break;
        case ACTION__LIFT:             name = "lift";          break;
        case ACTION__DROP:             name = "drop";          break;
        case ACTION__CHANGE_FLOOR:     name = "change floor";  break;
        case ACTION__CHANGE_OBJECT:    name = "change object"; break;
        case ACTION__ADD_OBJECT:       name = "add object";    break;
        case ACTION__REMOVE_OBJECT:    name = "remove object"; break;
        case ACTION__CHANGE_OBJECT_TILEMAP_POS: name = "change object tilemap pos"; break;
        case ACTION__MELT:             name = "melt";          break;
        case ACTION__BREAK:            name = "break";         break;
        case ACTION__SHAKE:            name = "shake";         break;
        case ACTION__COUNT:            name = "count";         break;
        default: break;
    }

    return name;
}
