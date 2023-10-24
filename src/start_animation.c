#include "../inc/state.h"

void start_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("start animation:    %s \n", get_animation_name_from_type(animation->type));

    switch(animation->type)
    {
        case ANIMATION_TYPE__NONE:
        {
            //
        }
        break;
        case ANIMATION_TYPE__SEQUENCE:
        {
            animation->sequence.curr_animation_list_elem = animation->sequence.animation_list->head;
            ListElem* curr_elem = animation->sequence.curr_animation_list_elem;

            if(curr_elem)
            {
                Animation* curr_animation = (Animation*)curr_elem->data;
                start_animation(state, curr_animation, textures, sounds, musics, colors);
            }
            else
            {
                animation->is_finished = 1;
            }
        }
        break;
        case ANIMATION_TYPE__SIMULTANEOUS:
        {
            for(ListElem* curr_elem = animation->simultaneous.animation_list->head; curr_elem != 0; curr_elem = curr_elem->next)
            {
                if(curr_elem)
                {
                    Animation* curr_animation = (Animation*)curr_elem->data;
                    start_animation(state, curr_animation, textures, sounds, musics, colors);
                }
            }
        }
        break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            animation->move_sprite_in_gamemap_in_line.time = 0.0f;

            Sprite* sprite = new_sprite(animation->move_sprite_in_gamemap_in_line.texture);
            sprite->gamemap_pos.x = animation->move_sprite_in_gamemap_in_line.from_gamemap_pos.x;
            sprite->gamemap_pos.y = animation->move_sprite_in_gamemap_in_line.from_gamemap_pos.y;
            sprite->gamemap_pos.z = 0.0f;
            animation->move_sprite_in_gamemap_in_line.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            animation->move_sprite_in_gamemap_in_arch.time = 0.0f;

            Sprite* sprite = new_sprite(animation->move_sprite_in_gamemap_in_arch.texture);
            sprite->gamemap_pos.x = animation->move_sprite_in_gamemap_in_arch.from_gamemap_pos.x;
            sprite->gamemap_pos.y = animation->move_sprite_in_gamemap_in_arch.from_gamemap_pos.y;
            sprite->gamemap_pos.z = 0.0f;
            animation->move_sprite_in_gamemap_in_arch.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__SHOW_SPRITE_IN_GAMEMAP:
        {
            animation->show_sprite_in_gamemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->show_sprite_in_gamemap.texture);
            sprite->gamemap_pos.x = animation->show_sprite_in_gamemap.gamemap_pos.x;
            sprite->gamemap_pos.y = animation->show_sprite_in_gamemap.gamemap_pos.y;
            sprite->gamemap_pos.z = 0.0f;
            animation->show_sprite_in_gamemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__ASCEND_SPRITE_IN_GAMEMAP:
        {
            animation->ascend_sprite_in_gamemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->ascend_sprite_in_gamemap.texture);
            sprite->gamemap_pos.x = animation->ascend_sprite_in_gamemap.gamemap_pos.x;
            sprite->gamemap_pos.y = animation->ascend_sprite_in_gamemap.gamemap_pos.y;
            sprite->gamemap_pos.z = 0.0f;
            animation->ascend_sprite_in_gamemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__DESCEND_SPRITE_IN_GAMEMAP:
        {

            animation->descend_sprite_in_gamemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->descend_sprite_in_gamemap.texture);
            sprite->gamemap_pos.x = animation->descend_sprite_in_gamemap.gamemap_pos.x;
            sprite->gamemap_pos.y = animation->descend_sprite_in_gamemap.gamemap_pos.y;
            sprite->gamemap_pos.z = 0.0f;
            animation->descend_sprite_in_gamemap.sprite = sprite;
            add_sprite_to_gamemap_sprites(state, sprite);
        }
        break;
        case ANIMATION_TYPE__FALL_SPRITE_IN_GAMEMAP:
        {
            animation->fall_sprite_in_gamemap.time = 0.0f;

            Sprite* sprite = new_sprite(animation->fall_sprite_in_gamemap.texture);
            sprite->gamemap_pos.x = animation->fall_sprite_in_gamemap.gamemap_pos.x;
            sprite->gamemap_pos.y = animation->fall_sprite_in_gamemap.gamemap_pos.y;
            sprite->gamemap_pos.z = 0.0f;
            animation->fall_sprite_in_gamemap.sprite = sprite;
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
            play_sound(animation->play_sound.sound);
        }
        break;
    }
}
