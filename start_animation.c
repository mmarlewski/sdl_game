#include "state.h"

void start_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("start   animation:  %s \n", get_animation_name_from_type(animation->type));

    switch(animation->type)
    {
        case ANIMATION_TYPE__NONE:
        {
            //
        }
        break;
        case ANIMATION_TYPE__SEQUENCE:
        {
            animation->sequence.curr_animation = animation->sequence.animation_head;
            if(animation->sequence.curr_animation)
            {
                start_animation(state, animation->sequence.curr_animation, textures, sounds, musics);
            }
        }
        break;
        case ANIMATION_TYPE__SIMULTANEOUS:
        {
            animation->simultaneous.are_all_animations_finished = 0;
            Animation* curr_animation;
            for(curr_animation = animation->simultaneous.animation_head; curr_animation; curr_animation = curr_animation->next)
            {
                if(curr_animation)
                {
                    start_animation(state, curr_animation, textures, sounds, musics);
                }
            }
        }
        break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            animation->move_sprite_in_gamemap_in_line.time = 0.0f;

            Sprite* sprite = new_sprite(animation->move_sprite_in_gamemap_in_line.texture);
            sprite->gamemap_pos = animation->move_sprite_in_gamemap_in_line.from_gamemap_pos;
            animation->move_sprite_in_gamemap_in_line.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            animation->move_sprite_in_gamemap_in_arch.time = 0.0f;

            Sprite* sprite = new_sprite(animation->move_sprite_in_gamemap_in_arch.texture);
            sprite->gamemap_pos = animation->move_sprite_in_gamemap_in_arch.from_gamemap_pos;
            animation->move_sprite_in_gamemap_in_arch.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__SHOW_SPRITE_IN_TILEMAP:
        {
            animation->show_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->show_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(animation->show_sprite_in_tilemap.tilemap_pos);
            animation->show_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__ASCEND_SPRITE_IN_TILEMAP:
        {
            animation->ascend_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->ascend_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(animation->ascend_sprite_in_tilemap.tilemap_pos);
            animation->ascend_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__DESCEND_SPRITE_IN_TILEMAP:
        {
            
            animation->descend_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->descend_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(animation->descend_sprite_in_tilemap.tilemap_pos);
            animation->descend_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__DROP_SPRITE_IN_TILEMAP:
        {
            animation->drop_sprite_in_tilemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->drop_sprite_in_tilemap.texture);
            sprite->gamemap_pos = tilemap_pos_to_gamemap_pos(animation->drop_sprite_in_tilemap.tilemap_pos);
            animation->drop_sprite_in_tilemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:
        {
            animation->move_camera_in_world_in_line.time = 0.0f;

            if(animation->move_camera_in_world_in_line.start_from_curr)
            {
                animation->move_camera_in_world_in_line.from_world_pos = state->camera.world_pos;
                vec2f to_world_pos = state->camera.world_pos;
                to_world_pos.x += animation->move_camera_in_world_in_line.to_world_pos.x;
                to_world_pos.y += animation->move_camera_in_world_in_line.to_world_pos.y;
                animation->move_camera_in_world_in_line.to_world_pos = to_world_pos;
            }
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:
        {
            animation->move_camera_in_world_in_arch.time = 0.0f;

            if(animation->move_camera_in_world_in_arch.start_from_curr)
            {
                animation->move_camera_in_world_in_arch.from_world_pos = state->camera.world_pos;
                vec2f to_world_pos = state->camera.world_pos;
                to_world_pos.x += animation->move_camera_in_world_in_arch.to_world_pos.x;
                to_world_pos.y += animation->move_camera_in_world_in_arch.to_world_pos.y;
                animation->move_camera_in_world_in_arch.to_world_pos = to_world_pos;
            }
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:
        {
            animation->move_camera_in_gamemap_in_line.time = 0.0f;
        }
        break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:
        {
            animation->move_camera_in_gamemap_in_arch.time = 0.0f;
        }
        break;
        case ANIMATION_TYPE__PLAY_SOUND:
        {
            //
        }
        break;
    }
}