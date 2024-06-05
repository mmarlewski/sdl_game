#include "../inc/state.h"

void update_animation(State* state, Animation* animation, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("update animation:   %s \n", get_animation_name_from_type(animation->type));

    switch(animation->type)
    {
        case ANIMATION__NONE:
        {
            animation->is_finished = 1;
        }
        break;
        case ANIMATION__SEQUENCE:
        {
            ListElem* curr_elem = animation->sequence.curr_animation_list_elem;
            Animation* curr_animation = (Animation*) curr_elem->data;

            update_animation(state, curr_animation, delta_time, textures, sounds, musics, colors);

            if(curr_animation->is_finished)
            {
                end_animation(state, curr_animation, textures, sounds, musics, colors);
                ListElem* next_elem = curr_elem->next;
                animation->sequence.curr_animation_list_elem = next_elem;

                if(next_elem != 0)
                {
                    Animation* next_animation = (Animation*) next_elem->data;
                    start_animation(state, next_animation, textures, sounds, musics, colors);
                }
            }

            animation->is_finished = (!animation->sequence.curr_animation_list_elem);
        }
        break;
        case ANIMATION__SIMULTANEOUS:
        {
            int are_all_animations_finished = 1;
            List* animation_to_be_removed_list = new_list(0);

            for(ListElem* curr_elem = animation->simultaneous.animation_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Animation* curr_animation = (Animation*) curr_elem->data;
                if(curr_animation->is_finished)
                {
                    end_animation(state, curr_animation, textures, sounds, musics, colors);
                    add_new_list_element_to_list_end(animation_to_be_removed_list, curr_animation);
                }
                else
                {
                    update_animation(state, curr_animation, delta_time, textures, sounds, musics, colors);
                    are_all_animations_finished = 0;
                }
            }

            for(ListElem* curr_elem = animation_to_be_removed_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                remove_list_element_of_data(animation->simultaneous.animation_list, curr_elem->data, 1);
            }

            destroy_list(animation_to_be_removed_list);

            animation->is_finished = (are_all_animations_finished);
        }
        break;
        case ANIMATION__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            Animation_MoveSpriteInGamemapInLine animation_animation = animation->move_sprite_in_gamemap_in_line;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f gamemap_diff = vec2f(
                animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x,
                animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y
            );
            Vec2f sprite_gamemap_pos = vec2f(
                animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio,
                animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio
            );
            animation_animation.sprite->gamemap_pos = vec3f(
                sprite_gamemap_pos.x,
                sprite_gamemap_pos.y,
                0.0f
            );
            animation_animation.time += delta_time;

            animation->move_sprite_in_gamemap_in_line = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            Animation_MoveSpriteInGamemapInArch animation_animation = animation->move_sprite_in_gamemap_in_arch;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f gamemap_diff;
            gamemap_diff.x = animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x;
            gamemap_diff.y = animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y;
            Vec2f sprite_gamemap_pos;
            sprite_gamemap_pos.x = animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            sprite_gamemap_pos.y = animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            Vec2f sprite_world_pos;
            sprite_world_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(sprite_gamemap_pos));
            Vec2f new_gamemap_pos = world_pos_to_gamemap_pos(iso_pos_to_cart_pos(sprite_world_pos));
            animation_animation.sprite->gamemap_pos.x = new_gamemap_pos.x;
            animation_animation.sprite->gamemap_pos.y = new_gamemap_pos.y;
            animation_animation.sprite->gamemap_pos.z = -sin(3.14f * time_ratio) * animation_animation.sin_mul;

            animation_animation.time += delta_time;

            animation->move_sprite_in_gamemap_in_arch = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__SHOW_SPRITE_IN_GAMEMAP:
        {
            Animation_ShowSpriteInGamemap animation_animation = animation->show_sprite_in_gamemap;

            animation_animation.time += delta_time;

            animation->show_sprite_in_gamemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__ASCEND_SPRITE_IN_GAMEMAP:
        {
            Animation_AscendSpriteInGamemap animation_animation = animation->ascend_sprite_in_gamemap;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f origin_gamemap_pos = animation_animation.gamemap_pos;
            Vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            Vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            Vec2f new_iso_pos = origin_iso_pos;
            Vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            Vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            animation_animation.sprite->gamemap_pos.x = new_gamemap_pos.x;
            animation_animation.sprite->gamemap_pos.y = new_gamemap_pos.y;
            animation_animation.sprite->gamemap_pos.z = -animation_animation.length * time_ratio;
            animation_animation.time += delta_time;

            animation->ascend_sprite_in_gamemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__DESCEND_SPRITE_IN_GAMEMAP:
        {
            Animation_DescendSpriteInGamemap animation_animation = animation->descend_sprite_in_gamemap;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f origin_gamemap_pos = animation_animation.gamemap_pos;
            Vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            Vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            Vec2f new_iso_pos = origin_iso_pos;
            Vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            Vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            animation_animation.sprite->gamemap_pos.x = new_gamemap_pos.x;
            animation_animation.sprite->gamemap_pos.y = new_gamemap_pos.y;
            animation_animation.sprite->gamemap_pos.z = -animation_animation.length + animation_animation.length * time_ratio;
            animation_animation.time += delta_time;

            animation->descend_sprite_in_gamemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__FALL_SPRITE_IN_GAMEMAP:
        {
            Animation_FallSpriteInGamemap animation_animation = animation->fall_sprite_in_gamemap;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f origin_gamemap_pos = animation_animation.gamemap_pos;
            Vec2f origin_world_pos = gamemap_pos_to_world_pos(origin_gamemap_pos);
            Vec2f origin_iso_pos = cart_pos_to_iso_pos(origin_world_pos);
            Vec2f new_iso_pos = origin_iso_pos;
            Vec2f new_world_pos = iso_pos_to_cart_pos(new_iso_pos);
            Vec2f new_gamemap_pos = world_pos_to_gamemap_pos(new_world_pos);
            animation_animation.sprite->gamemap_pos.x = new_gamemap_pos.x;
            animation_animation.sprite->gamemap_pos.y = new_gamemap_pos.y;
            animation_animation.sprite->gamemap_pos.z = animation_animation.length * time_ratio;
            animation_animation.time += delta_time;

            animation->fall_sprite_in_gamemap = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_WORLD_IN_LINE:
        {
            Animation_MoveCameraInWorldInLine animation_animation = animation->move_camera_in_world_in_line;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f world_diff;
            world_diff.x = animation_animation.to_world_pos.x - animation_animation.from_world_pos.x;
            world_diff.y = animation_animation.to_world_pos.y - animation_animation.from_world_pos.y;
            Vec2f camera_world_pos;
            camera_world_pos.x = animation_animation.from_world_pos.x + world_diff.x * time_ratio;
            camera_world_pos.y = animation_animation.from_world_pos.y + world_diff.y * time_ratio;
            state->camera_world_pos = camera_world_pos;
            animation_animation.time += delta_time;

            animation->move_camera_in_world_in_line = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_WORLD_IN_ARCH:
        {
            Animation_MoveCameraInWorldInArch animation_animation = animation->move_camera_in_world_in_arch;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f world_diff;
            world_diff.x = animation_animation.to_world_pos.x - animation_animation.from_world_pos.x;
            world_diff.y = animation_animation.to_world_pos.y - animation_animation.from_world_pos.y;
            Vec2f camera_world_pos;
            camera_world_pos.x = animation_animation.from_world_pos.x + world_diff.x * time_ratio;
            camera_world_pos.y = animation_animation.from_world_pos.y + world_diff.y * time_ratio;
            camera_world_pos.y -= sin(3.14f * time_ratio) * TILE_LENGTH * 0.5f * animation_animation.sin_mul;
            state->camera_world_pos = camera_world_pos;
            animation_animation.time += delta_time;

            animation->move_camera_in_world_in_arch = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:
        {
            Animation_MoveCameraInGamemapInLine animation_animation = animation->move_camera_in_gamemap_in_line;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f gamemap_diff;
            gamemap_diff.x = animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x;
            gamemap_diff.y = animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y;
            Vec2f camera_gamemap_pos;
            camera_gamemap_pos.x = animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            camera_gamemap_pos.y = animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            state->camera_world_pos = gamemap_pos_to_world_pos(camera_gamemap_pos);
            animation_animation.time += delta_time;

            animation->move_camera_in_gamemap_in_line = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:
        {
            Animation_MoveCameraInGamemapInArch animation_animation = animation->move_camera_in_gamemap_in_arch;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec2f gamemap_diff;
            gamemap_diff.x = animation_animation.to_gamemap_pos.x - animation_animation.from_gamemap_pos.x;
            gamemap_diff.y = animation_animation.to_gamemap_pos.y - animation_animation.from_gamemap_pos.y;
            Vec2f camera_gamemap_pos;
            camera_gamemap_pos.x = animation_animation.from_gamemap_pos.x + gamemap_diff.x * time_ratio;
            camera_gamemap_pos.y = animation_animation.from_gamemap_pos.y + gamemap_diff.y * time_ratio;
            Vec2f camera_world_pos;
            camera_world_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(camera_gamemap_pos));
            camera_world_pos.y -= sin(3.14f * time_ratio) * TILE_LENGTH * 0.5f * animation_animation.sin_mul;
            state->camera_world_pos = camera_world_pos;
            animation_animation.time += delta_time;

            animation->move_camera_in_gamemap_in_arch = animation_animation;

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
        case ANIMATION__PLAY_SOUND:
        {
            animation->is_finished = 1;
        }
        break;
        case ANIMATION__CHANGE_BACKGROUND_COLOR:
        {
            Animation_ChangeBackgroundColor animation_animation = animation->change_background_color;

            float time_ratio = animation_animation.time / animation_animation.seconds;
            Vec3i color = vec3i(
                animation_animation.from_color.x + (animation_animation.to_color.x - animation_animation.from_color.x) * time_ratio,
                animation_animation.from_color.y + (animation_animation.to_color.y - animation_animation.from_color.y) * time_ratio,
                animation_animation.from_color.z + (animation_animation.to_color.z - animation_animation.from_color.z) * time_ratio
            );
            animation_animation.time += delta_time;

            animation->change_background_color = animation_animation;

            change_background_color(state, color);

            animation->is_finished = (animation_animation.time > animation_animation.seconds);
        }
        break;
    }
}
