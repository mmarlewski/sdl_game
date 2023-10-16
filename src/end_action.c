#include "../inc/state.h"

void end_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("\n");
    print_action(state->action.main_action_sequence, 0);

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
            remove_all_list_elements(action->sequence.action_list, 1);
            action->sequence.curr_action_list_elem = 0;
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            remove_all_list_elements(action->simultaneous.action_list, 1);
        }
        break;
        case ACTION_TYPE__MOVE_GROUND:
        {
            if(!action->move_ground.is_move_blocked)
            {
                action->move_ground.object->tilemap_pos = make_vec2i_move_in_dir4_by(action->move_ground.object->tilemap_pos,action->move_ground.dir4,1);
                end_animation(state, action->animation, textures, sounds, musics);

                int floor = get_floor_on_tilemap_pos(state, action->move_ground.object->tilemap_pos);
                floor_on_move_ground_end(state, sequence, action, floor);
            }

            action->move_ground.object->is_visible = 1;
        }
        break;
        case ACTION_TYPE__MOVE_AIR:
        {
            if(!action->move_air.is_move_blocked)
            {
                action->move_air.object->tilemap_pos = make_vec2i_move_in_dir4_by(action->move_air.object->tilemap_pos,action->move_air.dir4,1);
                end_animation(state, action->animation, textures, sounds, musics);

                int floor = get_floor_on_tilemap_pos(state, action->move_air.object->tilemap_pos);
                floor_on_move_air_end(state, sequence, action, floor);
            }

            action->move_air.object->is_visible = 1;
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            end_animation(state, action->animation, textures, sounds, musics);

            Action* crushed_action_sequence = new_action_sequence();
            Object* crushed_object = get_object_on_tilemap_pos(state, make_vec2i_move_in_dir4_by(action->crash.object->tilemap_pos, action->crash.dir4, 1));
            object_on_crashed(state, crushed_action_sequence, action, crushed_object);

            Action* crushing_action_sequence = new_action_sequence();
            Object* crushing_object = action->crash.object;
            object_on_crashing(state, crushing_action_sequence, action, crushing_object);

            add_action_after_curr_action_action_sequence(sequence, new_action_simultaneous_of_2(crushed_action_sequence, crushing_action_sequence));

            action->crash.object->is_visible = 1;
        }
        break;
        case ACTION_TYPE__FALL:
        {
            end_animation(state, action->animation, textures, sounds, musics);

            add_action_after_curr_action_action_sequence(sequence, new_action_death(action->fall.object, action->fall.tilemap_pos));

            action->fall.object->is_visible = 1;
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            end_animation(state, action->animation, textures, sounds, musics);

            object_on_death(state, sequence, action, action->death.object);

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
                if(is_object_flying(object_up->type))
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_air(object_up, object_up->tilemap_pos, DIR4__UP)));
                }
                else
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_ground(object_up, object_up->tilemap_pos, DIR4__UP)));
                }
            }
            if(object_right)
            {
                if(is_object_flying(object_right->type))
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_air(object_right, object_right->tilemap_pos, DIR4__RIGHT)));
                }
                else
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_ground(object_right, object_right->tilemap_pos, DIR4__RIGHT)));
                }
            }
            if(object_down)
            {
                if(is_object_flying(object_down->type))
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_air(object_down, object_down->tilemap_pos, DIR4__DOWN)));
                }
                else
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_ground(object_down, object_down->tilemap_pos, DIR4__DOWN)));
                }
            }
            if(object_left)
            {
                if(is_object_flying(object_left->type))
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_air(object_left, object_left->tilemap_pos, DIR4__LEFT)));
                }
                else
                {
                    add_action_sequence_to_action_simultaneous(push_around, new_action_sequence_of_1(new_action_move_ground(object_left, object_left->tilemap_pos, DIR4__LEFT)));
                }
            }
            add_action_after_curr_action_action_sequence(sequence, push_around);
        }
        break;
        case ACTION_TYPE__THROW:
        {
            end_animation(state, action->animation, textures, sounds, musics);

            vec2i curr_tilemap_pos = action->throw.object->tilemap_pos;
            vec2i next_tilemap_pos = make_vec2i_move_in_dir4_by(curr_tilemap_pos, action->throw.dir4, action->throw.distance);

            action->throw.object->tilemap_pos = next_tilemap_pos;

            add_action_after_curr_action_action_sequence(sequence, new_action_drop(action->throw.object, next_tilemap_pos, action->throw.dir4));

            action->throw.object->is_visible = 1;
        }
        break;
        case ACTION_TYPE__DROP:
        {
            object_on_drop(state, sequence, action, action->drop.object);

            end_animation(state, action->animation, textures, sounds, musics);

            int floor = get_floor_on_tilemap_pos(state, action->drop.object->tilemap_pos);
            floor_on_drop(state, sequence, action, floor);
        }
        break;
        default:
        break;
    }
}
