#include "state.h"

void update_action(State* state, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("update action:  %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            Action_Sequence action_action = action->sequence;

            if(action_action.curr_action)
            {
                update_action(state, action_action.curr_action, delta_time, textures, sounds, musics);
                
                if(action_action.curr_action->is_finished)
                {
                    Action* next_action = action_action.curr_action->next;
                    end_action(state, action_action.curr_action, textures, sounds, musics);
                    destroy_action(action_action.curr_action);
                    action_action.curr_action = next_action;

                    if(action_action.curr_action)
                    {
                        start_action(state, action_action.curr_action, textures, sounds, musics);
                    }
                }
            }

            action->sequence = action_action;

            action->is_finished = (!action->sequence.curr_action);
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            Action_Simultaneous action_action = action->simultaneous;

            int is_any_action_not_finished = 0;
            Action* prev_action = 0;
            Action* curr_action = action_action.action_head;
            Action* next_action = (action_action.action_head) ? (action_action.action_head->next) : (0);
            while(curr_action)
            {
                if(curr_action->is_finished)
                {
                    end_action(state, curr_action, textures, sounds, musics);
                    next_action = curr_action->next;
                    destroy_action(curr_action);
                    
                    if(prev_action)
                    {
                        prev_action->next = next_action;
                    }
                    else
                    {
                        action_action.action_head = next_action;
                    }
                    curr_action = next_action;
                    next_action = (next_action) ? (next_action->next) : (0);
                }
                else
                {
                    is_any_action_not_finished = 1;
                    update_action(state, curr_action, delta_time, textures, sounds, musics);

                    prev_action = curr_action;
                    curr_action = next_action;
                    next_action = (next_action) ? (next_action->next) : (0);
                }
            }
            if(!is_any_action_not_finished)
            {
                action_action.are_all_actions_finished = 1;
            }

            action->simultaneous = action_action;

            action->is_finished = (action->simultaneous.are_all_actions_finished);
        }
        break;
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            Action_MoveSpriteInGamemapInLine action_action = action->move_sprite_in_gamemap_in_line;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = action_action.to_gamemap_pos.x - action_action.from_gamemap_pos.x;
            gamemap_diff.y = action_action.to_gamemap_pos.y - action_action.from_gamemap_pos.y;
            vec2f sprite_gamemap_pos;
            sprite_gamemap_pos.x = action_action.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            sprite_gamemap_pos.y = action_action.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            action_action.sprite->gamemap_pos = sprite_gamemap_pos;
            action_action.time += delta_time;

            action->move_sprite_in_gamemap_in_line = action_action;

            action->is_finished = (action->move_sprite_in_gamemap_in_line.time > action->move_sprite_in_gamemap_in_line.seconds);
        }
        break;
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            Action_MoveSpriteInGamemapInArch action_action = action->move_sprite_in_gamemap_in_arch;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = action_action.to_gamemap_pos.x - action_action.from_gamemap_pos.x;
            gamemap_diff.y = action_action.to_gamemap_pos.y - action_action.from_gamemap_pos.y;
            vec2f sprite_gamemap_pos;
            sprite_gamemap_pos.x = action_action.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            sprite_gamemap_pos.y = action_action.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            action_action.sprite->gamemap_pos = sprite_gamemap_pos;
            action_action.time += delta_time;

            action->move_sprite_in_gamemap_in_arch = action_action;

            action->is_finished = (action->move_sprite_in_gamemap_in_arch.time > action->move_sprite_in_gamemap_in_arch.seconds);
        }
        break;
        case ACTION_TYPE__SHOW_SPRITE_IN_TILEMAP:
        {
            Action_ShowSpriteInTilemap action_action = action->show_sprite_in_tilemap;

            action_action.time += delta_time;

            action->show_sprite_in_tilemap = action_action;

            action->is_finished = (action_action.time > action_action.seconds);
        }
        break;
        case ACTION_TYPE__ASCEND_SPRITE_IN_TILEMAP:
        {
            Action_AscendSpriteInTilemap action_action = action->ascend_sprite_in_tilemap;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f origin_gamemap_pos = tilemap_pos_to_gamemap_pos(action_action.tilemap_pos);
            vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            origin_iso_pos.x += TILE_LENGTH * 0.5f;
            vec2f new_iso_pos = origin_iso_pos;
            new_iso_pos.y -= TILE_LENGTH * 0.5f * time_ratio;
            vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            action_action.sprite->gamemap_pos = new_gamemap_pos;
            action_action.time += delta_time;

            action->ascend_sprite_in_tilemap = action_action;

            action->is_finished = (action_action.time > action_action.seconds);
        }
        break;
        case ACTION_TYPE__DESCEND_SPRITE_IN_TILEMAP:
        {
            Action_DescendSpriteInTilemap action_action = action->descend_sprite_in_tilemap;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f origin_gamemap_pos = tilemap_pos_to_gamemap_pos(action_action.tilemap_pos);
            vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            origin_iso_pos.x += TILE_LENGTH * 0.5f;
            origin_iso_pos.y -= TILE_LENGTH * 0.5f;
            vec2f new_iso_pos = origin_iso_pos;
            new_iso_pos.y += TILE_LENGTH * 0.5f * time_ratio;
            vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            action_action.sprite->gamemap_pos = new_gamemap_pos;
            action_action.time += delta_time;

            action->descend_sprite_in_tilemap = action_action;

            action->is_finished = (action_action.time > action_action.seconds);
        }
        break;
        case ACTION_TYPE__DROP_SPRITE_IN_TILEMAP:
        {
            Action_DropSpriteInTilemap action_action = action->drop_sprite_in_tilemap;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f origin_gamemap_pos = tilemap_pos_to_gamemap_pos(action_action.tilemap_pos);
            vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            vec2f new_iso_pos;
            new_iso_pos.x = origin_iso_pos.x + TILE_LENGTH * 0.5f;
            new_iso_pos.y = origin_iso_pos.y + TILE_LENGTH * 0.25f * time_ratio;
            vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            action_action.sprite->gamemap_pos = new_gamemap_pos;
            action_action.time += delta_time;

            action->drop_sprite_in_tilemap = action_action;

            action->is_finished = (action_action.time > action_action.seconds);
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:
        {
            Action_MoveCameraInWorldInLine action_action = action->move_camera_in_world_in_line;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f world_diff;
            world_diff.x = action_action.to_world_pos.x - action_action.from_world_pos.x;
            world_diff.y = action_action.to_world_pos.y - action_action.from_world_pos.y;
            vec2f camera_world_pos;
            camera_world_pos.x = action_action.from_world_pos.x + world_diff.x * time_ratio;
            camera_world_pos.y = action_action.from_world_pos.y + world_diff.y * time_ratio;
            state->camera.world_pos = camera_world_pos;
            action_action.time += delta_time;

            action->move_camera_in_world_in_line = action_action;

            action->is_finished = (action->move_camera_in_world_in_line.time > action->move_camera_in_world_in_line.seconds);
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:
        {
            Action_MoveCameraInWorldInArch action_action = action->move_camera_in_world_in_arch;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f world_diff;
            world_diff.x = action_action.to_world_pos.x - action_action.from_world_pos.x;
            world_diff.y = action_action.to_world_pos.y - action_action.from_world_pos.y;
            vec2f camera_world_pos;
            camera_world_pos.x = action_action.from_world_pos.x + world_diff.x * time_ratio;
            camera_world_pos.y = action_action.from_world_pos.y + world_diff.y * time_ratio;
            camera_world_pos.y -= sin(3.14f * time_ratio) *  TILE_LENGTH * 0.5f * action_action.sin_mul;
            state->camera.world_pos = camera_world_pos;
            action_action.time += delta_time;

            action->move_camera_in_world_in_arch = action_action;

            action->is_finished = (action->move_camera_in_world_in_arch.time > action->move_camera_in_world_in_arch.seconds);
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:
        {
            Action_MoveCameraInGamemapInLine action_action = action->move_camera_in_gamemap_in_line;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = action_action.to_gamemap_pos.x - action_action.from_gamemap_pos.x;
            gamemap_diff.y = action_action.to_gamemap_pos.y - action_action.from_gamemap_pos.y;
            vec2f camera_gamemap_pos;
            camera_gamemap_pos.x = action_action.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            camera_gamemap_pos.y = action_action.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            state->camera.world_pos = gamemap_pos_to_world_pos(camera_gamemap_pos);
            action_action.time += delta_time;

            action->move_camera_in_gamemap_in_line = action_action;

            action->is_finished = (action->move_camera_in_gamemap_in_line.time > action->move_camera_in_gamemap_in_line.seconds);
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:
        {
            Action_MoveCameraInGamemapInArch action_action = action->move_camera_in_gamemap_in_arch;

            float time_ratio = action_action.time / action_action.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = action_action.to_gamemap_pos.x - action_action.from_gamemap_pos.x;
            gamemap_diff.y = action_action.to_gamemap_pos.y - action_action.from_gamemap_pos.y;
            vec2f camera_gamemap_pos;
            camera_gamemap_pos.x = action_action.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            camera_gamemap_pos.y = action_action.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            vec2f camera_cart_pos;
            camera_cart_pos = gamemap_pos_to_world_pos(camera_gamemap_pos);
            camera_cart_pos.y -= sin(3.14f * time_ratio) *  TILE_LENGTH * 0.5f * action_action.sin_mul;
            state->camera.world_pos = camera_cart_pos;
            action_action.time += delta_time;

            action->move_camera_in_gamemap_in_arch = action_action;

            action->is_finished = (action->move_camera_in_gamemap_in_arch.time > action->move_camera_in_gamemap_in_arch.seconds);
        }
        break;
        case ACTION_TYPE__PLAY_SOUND:
        {
            play_sound(action->play_sound.sound);

            action->is_finished = 1;
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            Action_Move action_action = action->move;

            update_action(state, action_action.action_move_sprite_in_gamemap, delta_time, textures, sounds, musics);

            action->move = action_action;

            action->is_finished = (action->move.action_move_sprite_in_gamemap->is_finished);
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            Action_Push action_action = action->push;

            update_action(state, action_action.action_move_sprite_in_gamemap, delta_time, textures, sounds, musics);

            action->push = action_action;

            action->is_finished = (action->push.action_move_sprite_in_gamemap->is_finished);
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            Action_Crash action_action = action->crash;

            update_action(state, action_action.action_sequence, delta_time, textures, sounds, musics);

            action->crash = action_action;

            action->is_finished = (action->crash.action_sequence->is_finished);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            Action_Drop action_action = action->drop;

            update_action(state, action_action.action_drop_sprite_in_tilemap, delta_time, textures, sounds, musics);

            action->drop = action_action;

            action->is_finished = (action->drop.action_drop_sprite_in_tilemap->is_finished);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            action->is_finished = 1;
        }
        break;
        default:
        break;
    }
}