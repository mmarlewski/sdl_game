#include "state.h"

void update_animation(State* state, Animation* animation, float delta_time, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("update  animation:  %s \n", get_animation_name_from_type(animation->type));

    switch(animation->type)
    {
        case ANIMATION_TYPE__NONE:
        {
            //
        }
        break;
        case ANIMATION_TYPE__SEQUENCE:
        {
            Animation_Sequence animation_animation = animation->sequence;

            if(animation_animation.curr_animation)
            {
                update_animation(state, animation_animation.curr_animation, delta_time, textures, sounds, musics);
                
                if(animation_animation.curr_animation->is_finished)
                {
                    Animation* next_animation = animation_animation.curr_animation->next;
                    end_animation(state, animation_animation.curr_animation, textures, sounds, musics);
                    destroy_animation(animation_animation.curr_animation);
                    animation_animation.curr_animation = next_animation;

                    if(animation_animation.curr_animation)
                    {
                        start_animation(state, animation_animation.curr_animation, textures, sounds, musics);
                    }
                }
            }

            animation->sequence = animation_animation;

            animation->is_finished = (!animation->sequence.curr_animation);
        }
        break;
        case ANIMATION_TYPE__SIMULTANEOUS:
        {
            Animation_Simultaneous animation_animation = animation->simultaneous;

            int is_any_animation_not_finished = 0;
            Animation* prev_animation = 0;
            Animation* curr_animation = animation_animation.animation_head;
            Animation* next_animation = (animation_animation.animation_head) ? (animation_animation.animation_head->next) : (0);
            while(curr_animation)
            {
                if(curr_animation->is_finished)
                {
                    end_animation(state, curr_animation, textures, sounds, musics);
                    next_animation = curr_animation->next;
                    destroy_animation(curr_animation);
                    
                    if(prev_animation)
                    {
                        prev_animation->next = next_animation;
                    }
                    else
                    {
                        animation_animation.animation_head = next_animation;
                    }
                    curr_animation = next_animation;
                    next_animation = (next_animation) ? (next_animation->next) : (0);
                }
                else
                {
                    is_any_animation_not_finished = 1;
                    update_animation(state, curr_animation, delta_time, textures, sounds, musics);

                    prev_animation = curr_animation;
                    curr_animation = next_animation;
                    next_animation = (next_animation) ? (next_animation->next) : (0);
                }
            }
            if(!is_any_animation_not_finished)
            {
                animation_animation.are_all_animations_finished = 1;
            }

            animation->simultaneous = animation_animation;

            animation->is_finished = (animation->simultaneous.are_all_animations_finished);
        }
        break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            Animation_MoveSpriteInGamemapInLine animation_animation = animation->move_sprite_in_gamemap_in_line;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x;
            gamemap_diff.y = animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y;
            vec2f sprite_gamemap_pos;
            sprite_gamemap_pos.x = animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            sprite_gamemap_pos.y = animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            animation_animation.sprite->gamemap_pos = sprite_gamemap_pos;
            animation_animation.time += delta_time;

            animation->move_sprite_in_gamemap_in_line = animation_animation;

            animation->is_finished = (animation->move_sprite_in_gamemap_in_line.time > animation->move_sprite_in_gamemap_in_line.seconds);
        }
        break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            Animation_MoveSpriteInGamemapInArch animation_animation = animation->move_sprite_in_gamemap_in_arch;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x;
            gamemap_diff.y = animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y;
            vec2f sprite_gamemap_pos;
            sprite_gamemap_pos.x = animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            sprite_gamemap_pos.y = animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            animation_animation.sprite->gamemap_pos = sprite_gamemap_pos;
            animation_animation.time += delta_time;

            animation->move_sprite_in_gamemap_in_arch = animation_animation;

            animation->is_finished = (animation->move_sprite_in_gamemap_in_arch.time > animation->move_sprite_in_gamemap_in_arch.seconds);
        }
        break;
        case ANIMATION_TYPE__SHOW_SPRITE_IN_TILEMAP:
        {
            Animation_ShowSpriteInTilemap animation_animation = animation->show_sprite_in_tilemap;

            animation_animation.time += delta_time;

            animation->show_sprite_in_tilemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION_TYPE__ASCEND_SPRITE_IN_TILEMAP:
        {
            Animation_AscendSpriteInTilemap animation_animation = animation->ascend_sprite_in_tilemap;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f origin_gamemap_pos = tilemap_pos_to_gamemap_pos(animation_animation.tilemap_pos);
            vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            origin_iso_pos.x += TILE_LENGTH * 0.5f;
            vec2f new_iso_pos = origin_iso_pos;
            new_iso_pos.y -= TILE_LENGTH * animation_animation.length * time_ratio;
            vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            animation_animation.sprite->gamemap_pos = new_gamemap_pos;
            animation_animation.time += delta_time;

            animation->ascend_sprite_in_tilemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION_TYPE__DESCEND_SPRITE_IN_TILEMAP:
        {
            Animation_DescendSpriteInTilemap animation_animation = animation->descend_sprite_in_tilemap;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f origin_gamemap_pos = tilemap_pos_to_gamemap_pos(animation_animation.tilemap_pos);
            vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            origin_iso_pos.x += TILE_LENGTH * 0.5f;
            origin_iso_pos.y -= TILE_LENGTH * animation_animation.length;
            vec2f new_iso_pos = origin_iso_pos;
            new_iso_pos.y += TILE_LENGTH * animation_animation.length * time_ratio;
            vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            animation_animation.sprite->gamemap_pos = new_gamemap_pos;
            animation_animation.time += delta_time;

            animation->descend_sprite_in_tilemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION_TYPE__DROP_SPRITE_IN_TILEMAP:
        {
            Animation_DropSpriteInTilemap animation_animation = animation->drop_sprite_in_tilemap;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f origin_gamemap_pos = tilemap_pos_to_gamemap_pos(animation_animation.tilemap_pos);
            vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            vec2f new_iso_pos;
            new_iso_pos.x = origin_iso_pos.x + TILE_LENGTH * 0.5f;
            new_iso_pos.y = origin_iso_pos.y + TILE_LENGTH * animation_animation.length * time_ratio;
            vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            animation_animation.sprite->gamemap_pos = new_gamemap_pos;
            animation_animation.time += delta_time;

            animation->drop_sprite_in_tilemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:
        {
            Animation_MoveCameraInWorldInLine animation_animation = animation->move_camera_in_world_in_line;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f world_diff;
            world_diff.x = animation_animation.to_world_pos.x - animation_animation.from_world_pos.x;
            world_diff.y = animation_animation.to_world_pos.y - animation_animation.from_world_pos.y;
            vec2f camera_world_pos;
            camera_world_pos.x = animation_animation.from_world_pos.x + world_diff.x * time_ratio;
            camera_world_pos.y = animation_animation.from_world_pos.y + world_diff.y * time_ratio;
            state->camera.world_pos = camera_world_pos;
            animation_animation.time += delta_time;

            animation->move_camera_in_world_in_line = animation_animation;

            animation->is_finished = (animation->move_camera_in_world_in_line.time > animation->move_camera_in_world_in_line.seconds);
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:
        {
            Animation_MoveCameraInWorldInArch animation_animation = animation->move_camera_in_world_in_arch;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f world_diff;
            world_diff.x = animation_animation.to_world_pos.x - animation_animation.from_world_pos.x;
            world_diff.y = animation_animation.to_world_pos.y - animation_animation.from_world_pos.y;
            vec2f camera_world_pos;
            camera_world_pos.x = animation_animation.from_world_pos.x + world_diff.x * time_ratio;
            camera_world_pos.y = animation_animation.from_world_pos.y + world_diff.y * time_ratio;
            camera_world_pos.y -= sin(3.14f * time_ratio) *  TILE_LENGTH * 0.5f * animation_animation.sin_mul;
            state->camera.world_pos = camera_world_pos;
            animation_animation.time += delta_time;

            animation->move_camera_in_world_in_arch = animation_animation;

            animation->is_finished = (animation->move_camera_in_world_in_arch.time > animation->move_camera_in_world_in_arch.seconds);
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:
        {
            Animation_MoveCameraInGamemapInLine animation_animation = animation->move_camera_in_gamemap_in_line;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x;
            gamemap_diff.y = animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y;
            vec2f camera_gamemap_pos;
            camera_gamemap_pos.x = animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            camera_gamemap_pos.y = animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            state->camera.world_pos = gamemap_pos_to_world_pos(camera_gamemap_pos);
            animation_animation.time += delta_time;

            animation->move_camera_in_gamemap_in_line = animation_animation;

            animation->is_finished = (animation->move_camera_in_gamemap_in_line.time > animation->move_camera_in_gamemap_in_line.seconds);
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:
        {
            Animation_MoveCameraInGamemapInArch animation_animation = animation->move_camera_in_gamemap_in_arch;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            vec2f gamemap_diff;
            gamemap_diff.x = animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x;
            gamemap_diff.y = animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y;
            vec2f camera_gamemap_pos;
            camera_gamemap_pos.x = animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            camera_gamemap_pos.y = animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            vec2f camera_cart_pos;
            camera_cart_pos = gamemap_pos_to_world_pos(camera_gamemap_pos);
            camera_cart_pos.y -= sin(3.14f * time_ratio) *  TILE_LENGTH * 0.5f * animation_animation.sin_mul;
            state->camera.world_pos = camera_cart_pos;
            animation_animation.time += delta_time;

            animation->move_camera_in_gamemap_in_arch = animation_animation;

            animation->is_finished = (animation->move_camera_in_gamemap_in_arch.time > animation->move_camera_in_gamemap_in_arch.seconds);
        }
        break;
        case ANIMATION_TYPE__PLAY_SOUND:
        {
            play_sound(animation->play_sound.sound);

            animation->is_finished = 1;
        }
        break;
    }
}