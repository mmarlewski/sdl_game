#include "state.h"

void start_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("start action:   %s \n", get_action_name_from_type(action->type));

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
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            action->move_sprite_in_gamemap_in_line.time = 0.0f;

            Sprite* sprite = new_sprite(action->move_sprite_in_gamemap_in_line.texture);
            sprite->gamemap_pos = action->move_sprite_in_gamemap_in_line.from_gamemap_pos;
            action->move_sprite_in_gamemap_in_line.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            action->move_sprite_in_gamemap_in_arch.time = 0.0f;

            Sprite* sprite = new_sprite(action->move_sprite_in_gamemap_in_arch.texture);
            sprite->gamemap_pos = action->move_sprite_in_gamemap_in_arch.from_gamemap_pos;
            action->move_sprite_in_gamemap_in_arch.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ACTION_TYPE__SHOW_SPRITE_IN_TILEMAP:
        {
            action->show_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(action->show_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(action->show_sprite_in_tilemap.tilemap_pos);
            action->show_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ACTION_TYPE__ASCEND_SPRITE_IN_TILEMAP:
        {
            action->ascend_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(action->ascend_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(action->ascend_sprite_in_tilemap.tilemap_pos);
            action->ascend_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ACTION_TYPE__DESCEND_SPRITE_IN_TILEMAP:
        {
            
            action->descend_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(action->descend_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(action->descend_sprite_in_tilemap.tilemap_pos);
            action->descend_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ACTION_TYPE__DROP_SPRITE_IN_TILEMAP:
        {
            action->drop_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(action->drop_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(action->drop_sprite_in_tilemap.tilemap_pos);
            action->drop_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:
        {
            action->move_camera_in_world_in_line.time = 0.0f;

            if(action->move_camera_in_world_in_line.start_from_curr)
            {
                action->move_camera_in_world_in_line.from_world_pos = state->camera.world_pos;
                vec2f to_world_pos = state->camera.world_pos;
                to_world_pos.x += action->move_camera_in_world_in_line.to_world_pos.x;
                to_world_pos.y += action->move_camera_in_world_in_line.to_world_pos.y;
                action->move_camera_in_world_in_line.to_world_pos = to_world_pos;
            }
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:
        {
            action->move_camera_in_world_in_arch.time = 0.0f;

            if(action->move_camera_in_world_in_arch.start_from_curr)
            {
                action->move_camera_in_world_in_arch.from_world_pos = state->camera.world_pos;
                vec2f to_world_pos = state->camera.world_pos;
                to_world_pos.x += action->move_camera_in_world_in_arch.to_world_pos.x;
                to_world_pos.y += action->move_camera_in_world_in_arch.to_world_pos.y;
                action->move_camera_in_world_in_arch.to_world_pos = to_world_pos;
            }
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:
        {
            action->move_camera_in_gamemap_in_line.time = 0.0f;
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:
        {
            action->move_camera_in_gamemap_in_arch.time = 0.0f;
        }
        break;
        case ACTION_TYPE__PLAY_SOUND:
        {
            //
        }
        break;
        case ACTION_TYPE__MOVE:
        {
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
                Action* move_sprite = new_action_move_sprite_in_gamemap_in_line(
                    get_texture_from_object_type(action->move.object->type, textures),
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                    0.2f
                    );
                
                action->move.action_move_sprite_in_gamemap = move_sprite;
                start_action(state, action->move.action_move_sprite_in_gamemap, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__PUSH:
        {
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
                Action* move_sprite = new_action_move_sprite_in_gamemap_in_line(
                    get_texture_from_object_type(action->push.object->type, textures),
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                    0.2f
                    );
                
                action->push.action_move_sprite_in_gamemap = move_sprite;
                start_action(state, action->push.action_move_sprite_in_gamemap, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            Texture* object_texture = get_texture_from_object_type(action->crash.object->type, textures);
            vec2f curr_object_gamemap_pos = tilemap_pos_to_gamemap_pos(action->crash.object->tilemap_pos);
            vec2f next_object_gamemap_pos = move_vec2f_in_dir4_by(curr_object_gamemap_pos,action->crash.dir4,1.0f);
            next_object_gamemap_pos.x = curr_object_gamemap_pos.x + (next_object_gamemap_pos.x - curr_object_gamemap_pos.x) * 0.5f;
            next_object_gamemap_pos.y = curr_object_gamemap_pos.y + (next_object_gamemap_pos.y - curr_object_gamemap_pos.y) * 0.5f;

            Action* move_sprite_to_crashed = new_action_move_sprite_in_gamemap_in_line(
                object_texture,
                curr_object_gamemap_pos,
                next_object_gamemap_pos,
                0.1f
                );
            
            Action* camera_shake = new_action_camera_shake(1, 5.0f, 0.1f);

            Action* move_sprite_from_crashed = new_action_move_sprite_in_gamemap_in_line(
                object_texture,
                next_object_gamemap_pos,
                curr_object_gamemap_pos,
                0.1f
                );
            
            Action* camera_shake_and_move_sprite_from_crashed = new_action_simultaneous();
            add_action_to_end_action_simultaneous(camera_shake_and_move_sprite_from_crashed,camera_shake);
            add_action_to_end_action_simultaneous(camera_shake_and_move_sprite_from_crashed,move_sprite_from_crashed);
            
            action->crash.action_sequence = new_action_sequence();
            add_action_to_end_action_sequence(action->crash.action_sequence,move_sprite_to_crashed);
            add_action_to_end_action_sequence(action->crash.action_sequence,camera_shake_and_move_sprite_from_crashed);

            start_action(state, action->crash.action_sequence, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            Action* drop_sprite = new_action_drop_sprite_in_tilemap(
                get_texture_from_object_type(action->drop.object->type, textures),
                action->drop.object->tilemap_pos,
                0.2f
                );
                
            action->drop.action_drop_sprite_in_tilemap = drop_sprite;
            start_action(state, action->drop.action_drop_sprite_in_tilemap, textures, sounds, musics);
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