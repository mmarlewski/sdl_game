#include "state.h"

void end_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("end     action:     %s \n", get_action_name_from_type(action->type));

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
                action->move.object->tilemap_pos = move_vec2i_in_dir4_by(action->move.object->tilemap_pos,action->move.dir4,1);
                end_animation(state, action->move.animation_move_sprite_in_gamemap, textures, sounds, musics);
            }

            int floor = get_floor_on_tilemap_pos(state, action->move.object->tilemap_pos);
            Action* action_result = get_action_from_floor_on_action(action, floor);
            add_action_after_curr_action(state, action_result);
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            action->push.object->is_visible = 1;

            if(!action->push.is_move_blocked)
            {
                action->push.object->tilemap_pos = move_vec2i_in_dir4_by(action->push.object->tilemap_pos,action->push.dir4,1);
                end_animation(state, action->push.animation_move_sprite_in_gamemap, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            action->crash.object->is_visible = 1;

            end_animation(state, action->crash.animation_sequence, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            action->drop.object->is_visible = 1;

            end_animation(state, action->drop.animation_drop_sprite_in_tilemap, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            remove_object_from_gamemap_objects(state, action->death.object);
        }
        break;
        default:
        break;
    }
}