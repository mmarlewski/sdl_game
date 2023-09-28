#include "state.h"

void start_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("start   action:     %s \n", get_action_name_from_type(action->type));

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
            if(action->sequence.curr_action)
            {
                start_action(state, action->sequence.curr_action, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            action->simultaneous.are_all_actions_finished = 0;
            Action* curr_action;
            for(curr_action = action->simultaneous.action_head; curr_action; curr_action = curr_action->next)
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
            vec2i next_tilemap_pos = move_vec2i_in_dir4_by(curr_tilemap_pos,action->move.dir4,1);
            Object* object_on_next_tilemap_pos = get_object_on_tilemap_pos(state, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                Action* crash = new_action_crash(action->move.object, action->move.dir4);
                remove_all_actions_after_curr_action(state);
                add_action_after_curr_action(state, crash);

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
                
                action->move.animation_move_sprite_in_gamemap = animation;
                start_animation(state, action->move.animation_move_sprite_in_gamemap, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            action->push.object->is_visible = 0;

            vec2i curr_tilemap_pos = action->push.object->tilemap_pos;
            vec2i next_tilemap_pos = move_vec2i_in_dir4_by(curr_tilemap_pos,action->push.dir4,1);
            Object* object_on_next_tilemap_pos = get_object_on_tilemap_pos(state, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                Action* crash = new_action_crash(action->push.object, action->push.dir4);
                remove_all_actions_after_curr_action(state);
                add_action_after_curr_action(state, crash);

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
                
                action->push.animation_move_sprite_in_gamemap = animation;
                start_animation(state, action->push.animation_move_sprite_in_gamemap, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            action->crash.object->is_visible = 0;

            Texture* object_texture = get_texture_from_object_type(action->crash.object->type, textures);
            vec2f curr_object_gamemap_pos = tilemap_pos_to_gamemap_pos(action->crash.object->tilemap_pos);
            vec2f next_object_gamemap_pos = move_vec2f_in_dir4_by(curr_object_gamemap_pos,action->crash.dir4,1.0f);
            next_object_gamemap_pos.x = curr_object_gamemap_pos.x + (next_object_gamemap_pos.x - curr_object_gamemap_pos.x) * 0.5f;
            next_object_gamemap_pos.y = curr_object_gamemap_pos.y + (next_object_gamemap_pos.y - curr_object_gamemap_pos.y) * 0.5f;

            Animation* move_sprite_to_crashed = new_animation_move_sprite_in_gamemap_in_line(
                object_texture,
                curr_object_gamemap_pos,
                next_object_gamemap_pos,
                0.1f
                );
            
            Animation* camera_shake = new_animation_camera_shake(1, 5.0f, 0.1f);

            Animation* move_sprite_from_crashed = new_animation_move_sprite_in_gamemap_in_line(
                object_texture,
                next_object_gamemap_pos,
                curr_object_gamemap_pos,
                0.1f
                );
            
            Animation* camera_shake_and_move_sprite_from_crashed = new_animation_simultaneous();
            add_animation_to_end_animation_simultaneous(camera_shake_and_move_sprite_from_crashed,camera_shake);
            add_animation_to_end_animation_simultaneous(camera_shake_and_move_sprite_from_crashed,move_sprite_from_crashed);
            
            action->crash.animation_sequence = new_animation_sequence();
            add_animation_to_end_animation_sequence(action->crash.animation_sequence,move_sprite_to_crashed);
            add_animation_to_end_animation_sequence(action->crash.animation_sequence,camera_shake_and_move_sprite_from_crashed);

            start_animation(state, action->crash.animation_sequence, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            action->drop.object->is_visible = 0;

            Animation* drop_sprite = new_animation_drop_sprite_in_tilemap(
                get_texture_from_object_type(action->drop.object->type, textures),
                action->drop.object->tilemap_pos,
                0.1f,
                0.1f
                );
                
            action->drop.animation_drop_sprite_in_tilemap = drop_sprite;
            start_animation(state, action->drop.animation_drop_sprite_in_tilemap, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            //
        }
        break;
        default:
        break;
    }
}