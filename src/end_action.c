#include "../inc/state.h"

void end_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("end action:         %s \n", get_action_name_from_type(action->type));

    if(action->is_finished_at_start) return;

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            remove_all_list_elements(action->sequence.action_list, 1);
            action->sequence.curr_action_list_elem = 0;
            action->sequence.was_curr_action_finished = 0;
            action->sequence.was_curr_action_just_finished = 0;
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            remove_all_list_elements(action->simultaneous.action_list, 1);
            remove_all_list_elements(action->simultaneous.started_action_list, 0);
            action->simultaneous.curr_action_list_elem = 0;
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            action->move.object->tilemap_pos = vec2i_move_in_dir4_by(action->move.object->tilemap_pos,action->move.dir4,1);

            int floor = get_floor_on_tilemap_pos(state, action->move.object->tilemap_pos);
            floor_on_move_end(state, sequence, action, floor);

            action->move.object->is_visible = 1;
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            Action* crushed_action_sequence = new_action_sequence();
            Object* crushed_object = get_object_on_tilemap_pos(state, vec2i_move_in_dir4_by(action->crash.object_crushing->tilemap_pos, action->crash.dir4, 1));
            object_on_crashed(state, crushed_action_sequence, action, crushed_object);

            Action* crushing_action_sequence = new_action_sequence();
            Object* crushing_object = action->crash.object_crushing;
            object_on_crashing(state, crushing_action_sequence, action, crushing_object);

            add_action_after_curr_action_action_sequence(sequence, new_action_simultaneous_of_2(crushed_action_sequence, crushing_action_sequence));

            action->crash.object_crushing->is_visible = 1;
        }
        break;
        case ACTION_TYPE__FALL:
        {
            add_action_after_curr_action_action_sequence(sequence, new_action_death(action->fall.object, action->tilemap_pos));

            action->fall.object->is_visible = 0;
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            object_on_death(state, sequence, action, action->death.object);

            action->death.object->is_dead = 1;
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            Action* push_around = new_action_simultaneous();

            add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move( vec2i_move_in_dir4_by(action->tilemap_pos, DIR4__UP, 1), DIR4__UP)));

            add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move( vec2i_move_in_dir4_by(action->tilemap_pos, DIR4__RIGHT, 1), DIR4__RIGHT)));

            add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move( vec2i_move_in_dir4_by(action->tilemap_pos, DIR4__DOWN, 1), DIR4__DOWN)));

            add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move( vec2i_move_in_dir4_by(action->tilemap_pos, DIR4__LEFT, 1), DIR4__LEFT)));

            add_action_after_curr_action_action_sequence(sequence, push_around);
        }
        break;
        case ACTION_TYPE__THROW:
        {
            Vec2i curr_tilemap_pos = action->throw.object_thrown->tilemap_pos;
            Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, action->throw.dir4, action->throw.distance);

            action->throw.object_thrown->tilemap_pos = next_tilemap_pos;

            add_action_after_curr_action_action_sequence(sequence, new_action_drop(action->throw.object_thrown, next_tilemap_pos, action->throw.dir4));

            action->throw.object_thrown->is_visible = 1;
        }
        break;
        case ACTION_TYPE__LIFT:
        {
            add_action_after_curr_action_action_sequence(sequence, new_action_drop(action->throw.object_thrown, action->tilemap_pos, action->throw.dir4));

            action->throw.object_thrown->is_visible = 1;
        }
        break;
        case ACTION_TYPE__DROP:
        {
            object_on_drop(state, sequence, action, action->drop.object);

            int floor = get_floor_on_tilemap_pos(state, action->drop.object->tilemap_pos);
            floor_on_drop(state, sequence, action, floor);
        }
        break;
        case ACTION_TYPE__CHANGE_FLOOR:
        {
            //
        }
        break;
        case ACTION_TYPE__CHANGE_OBJECT:
        {
            //
        }
        break;
        case ACTION_TYPE__ADD_OBJECT:
        {
            //
        }
        break;
        case ACTION_TYPE__REMOVE_OBJECT:
        {
            //
        }
        break;
        default:
        break;
    }
}
