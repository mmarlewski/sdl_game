#include "state.h"

void end_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    // printf("end action:         %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            //
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            //
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            action->move.object->is_visible = 1;

            if(!action->move.is_move_blocked)
            {
                action->move.object->tilemap_pos = make_vec2i_move_in_dir4_by(action->move.object->tilemap_pos,action->move.dir4,1);
                end_animation(state, action->animation, textures, sounds, musics);
            }

            int floor = get_floor_on_tilemap_pos(state, action->move.object->tilemap_pos);
            floor_on_move_end(state, action, floor);
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            action->push.object->is_visible = 1;

            if(!action->push.is_move_blocked)
            {
                action->push.object->tilemap_pos = make_vec2i_move_in_dir4_by(action->push.object->tilemap_pos,action->push.dir4,1);
                end_animation(state, action->animation, textures, sounds, musics);
            }

            int floor = get_floor_on_tilemap_pos(state, action->push.object->tilemap_pos);
            floor_on_push_end(state, action, floor);
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            action->crash.object->is_visible = 1;

            end_animation(state, action->animation, textures, sounds, musics);

            Action* crushed_action = new_action_crash(action->crash.object, action->crash.dir4);
            Object* crushed_object = get_object_on_tilemap_pos(state, make_vec2i_move_in_dir4_by(action->crash.object->tilemap_pos, action->crash.dir4, 1));
            object_on_crashed(state, crushed_action, crushed_object);

            Action* crushing_action = new_action_crash(action->crash.object, action->crash.dir4);
            Object* crushing_object = action->crash.object;
            object_on_crashing(state, crushing_action, crushing_object);

            Action* action_1 = new_action_none();
            Action* action_2 = new_action_none();
            if(crushing_action->next)
            {
                destroy_action(action_1);
                action_1 = crushing_action->next;
            }
            if(crushed_action->next)
            {
                destroy_action(action_2);
                action_2 = crushed_action->next;
            }
            add_action_after_action(action, new_action_simultaneous_of_2(action_1, action_2));
        }
        break;
        case ACTION_TYPE__FALL:
        {
            action->fall.object->is_visible = 1;

            end_animation(state, action->animation, textures, sounds, musics);

            add_action_after_action(action, new_action_death(action->fall.object));
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            end_animation(state, action->animation, textures, sounds, musics);

            object_on_death(state, action, action->death.object);
            
            remove_object_from_gamemap_objects(state, action->death.object);
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            end_animation(state, action->animation, textures, sounds, musics);

            vec2i tilemap_pos = action->blow_up.tilemap_pos;
            Object* object_up = get_object_on_tilemap_pos(state, make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__UP, 1));
            Object* object_right = get_object_on_tilemap_pos(state, make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__RIGHT, 1));
            Object* object_down = get_object_on_tilemap_pos(state, make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__DOWN, 1));
            Object* object_left = get_object_on_tilemap_pos(state, make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__LEFT, 1));

            Action* push_around = new_action_simultaneous();
            if(object_up)
            {
                add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_push(object_up, DIR4__UP)));
            }
            if(object_right)
            {
                add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_push(object_right, DIR4__RIGHT)));
            }
            if(object_down)
            {
                add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_push(object_down, DIR4__DOWN)));
            }
            if(object_left)
            {
                add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_push(object_left, DIR4__LEFT)));
            }
            add_action_after_action(action, push_around);
        }
        break;
        default:
        break;
    }

    print_action(state->action.action_sequence, 0);
}