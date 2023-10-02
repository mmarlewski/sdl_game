#include "state.h"

void start_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    // printf("start action:       %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            action->sequence.curr_action = action->sequence.action_head;
            start_action(state, action->sequence.curr_action, textures, sounds, musics);
            action->sequence.action_head = new_action_none();
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            for(Action* curr_action = action->simultaneous.action_head; curr_action; curr_action = curr_action->next)
            {
                if(curr_action)
                {
                    start_action(state, curr_action, textures, sounds, musics);
                }
            }
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            action->move.object->is_visible = 0;

            vec2i curr_tilemap_pos = action->move.object->tilemap_pos;
            vec2i next_tilemap_pos = make_vec2i_move_in_dir4_by(curr_tilemap_pos,action->move.dir4,1);
            Object* object_on_next_tilemap_pos = get_object_on_tilemap_pos(state, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                Action* crash = new_action_crash(action->move.object, action->move.dir4);
                remove_all_actions_after_action(action);
                add_action_after_action(action, crash);

                action->is_finished = 1;
                action->move.is_move_blocked = 1;
            }
            else
            {
                Animation* animation = new_animation_move_sprite_in_gamemap_in_line(
                    get_texture_from_object_type(action->move.object->type, textures),
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                    0.2f
                );
                action->animation = animation;
                start_animation(state, action->animation, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            action->push.object->is_visible = 0;

            vec2i curr_tilemap_pos = action->push.object->tilemap_pos;
            vec2i next_tilemap_pos = make_vec2i_move_in_dir4_by(curr_tilemap_pos,action->push.dir4,1);
            Object* object_on_next_tilemap_pos = get_object_on_tilemap_pos(state, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                Action* crash = new_action_crash(action->push.object, action->push.dir4);
                remove_all_actions_after_action(action);
                add_action_after_action(action, crash);

                action->is_finished = 1;
                action->push.is_move_blocked = 1;
            }
            else
            {
                Animation* animation = new_animation_move_sprite_in_gamemap_in_line(
                    get_texture_from_object_type(action->push.object->type, textures),
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                    0.2f
                );
                
                action->animation = animation;
                start_animation(state, action->animation, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            action->crash.object->is_visible = 0;

            Texture* object_texture = get_texture_from_object_type(action->crash.object->type, textures);
            vec2f curr_object_gamemap_pos = tilemap_pos_to_gamemap_pos(action->crash.object->tilemap_pos);
            vec2f next_object_gamemap_pos = make_vec2f_move_in_dir4_by(curr_object_gamemap_pos,action->crash.dir4,1.0f);
            next_object_gamemap_pos.x = curr_object_gamemap_pos.x + (next_object_gamemap_pos.x - curr_object_gamemap_pos.x) * 0.5f;
            next_object_gamemap_pos.y = curr_object_gamemap_pos.y + (next_object_gamemap_pos.y - curr_object_gamemap_pos.y) * 0.5f;

            Animation* animation = new_animation_sequence_of_2(
                new_animation_move_sprite_in_gamemap_in_line(
                object_texture,
                curr_object_gamemap_pos,
                next_object_gamemap_pos,
                0.1f
                ),
                new_animation_simultaneous_of_2(
                    new_animation_camera_shake(1, 5.0f, 0.1f),
                    new_animation_move_sprite_in_gamemap_in_line(
                    object_texture,
                    next_object_gamemap_pos,
                    curr_object_gamemap_pos,
                    0.1f
                    )
                )
            );
            
            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__FALL:
        {
            action->fall.object->is_visible = 0;

            Animation* animation = new_animation_fall_sprite_in_tilemap(
                get_texture_from_object_type(action->fall.object->type, textures),
                action->fall.object->tilemap_pos,
                0.1f,
                0.1f
                );
                
            action->animation = animation;
            start_animation(state, action->animation, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            Animation* animation = new_animation_none();

            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);
        }
        break;
        default:
        break;
    }
}