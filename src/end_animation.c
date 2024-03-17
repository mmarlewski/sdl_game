#include "../inc/state.h"

void end_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("end animation:      %s \n", get_animation_name_from_type(animation->type));

    switch(animation->type)
    {
        case ANIMATION__NONE:
        {
            //
        }
        break;
        case ANIMATION__SEQUENCE:
        {
            remove_all_list_elements(animation->sequence.animation_list, 1);
            animation->sequence.curr_animation_list_elem = 0;
        }
        break;
        case ANIMATION__SIMULTANEOUS:
        {
            remove_all_list_elements(animation->simultaneous.animation_list, 1);
        }
        break;
        case ANIMATION__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            remove_sprite_from_gamemap_sprites(state, animation->move_sprite_in_gamemap_in_line.sprite);
        }
        case ANIMATION__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            remove_sprite_from_gamemap_sprites(state, animation->move_sprite_in_gamemap_in_arch.sprite);
        }
        break;
        case ANIMATION__SHOW_SPRITE_IN_GAMEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, animation->show_sprite_in_gamemap.sprite);
        }
        break;
        case ANIMATION__ASCEND_SPRITE_IN_GAMEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, animation->ascend_sprite_in_gamemap.sprite);
        }
        break;
        case ANIMATION__DESCEND_SPRITE_IN_GAMEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, animation->descend_sprite_in_gamemap.sprite);
        }
        break;
        case ANIMATION__FALL_SPRITE_IN_GAMEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, animation->fall_sprite_in_gamemap.sprite);
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_WORLD_IN_LINE:
        {
            //
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_WORLD_IN_ARCH:
        {
            //
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:
        {
            //
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:
        {
            //
        }
        break;
        case ANIMATION__PLAY_SOUND:
        {
            //
        }
        break;
        case ANIMATION__CHANGE_BACKGROUND_COLOR:
        {
            change_background_color(state, animation->change_background_color.to_color);
        }
        break;
    }
}
