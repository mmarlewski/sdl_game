#include "../inc/animation.h"

Animation* new_animation_none()
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__NONE;

    return animation;
}

Animation* new_animation_sequence()
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__SEQUENCE;

    animation->sequence.animation_list = new_list((void(*)(void*))&destroy_animation);
    animation->sequence.curr_animation_list_elem = 0;

    return animation;
}

Animation* new_animation_sequence_of_1(Animation* animation_1)
{
    Animation* sequence = new_animation_sequence();
    add_animation_to_end_animation_sequence(sequence, animation_1);
    return sequence;
}

Animation* new_animation_sequence_of_2(Animation* animation_1, Animation* animation_2)
{
    Animation* sequence = new_animation_sequence();
    add_animation_to_end_animation_sequence(sequence, animation_1);
    add_animation_to_end_animation_sequence(sequence, animation_2);
    return sequence;
}

Animation* new_animation_sequence_of_3(Animation* animation_1, Animation* animation_2, Animation* animation_3)
{
    Animation* sequence = new_animation_sequence();
    add_animation_to_end_animation_sequence(sequence, animation_1);
    add_animation_to_end_animation_sequence(sequence, animation_2);
    add_animation_to_end_animation_sequence(sequence, animation_3);
    return sequence;
}

void add_animation_to_end_animation_sequence(Animation* animation_sequence, Animation* new_animation)
{
    add_new_list_element_to_list_end(animation_sequence->sequence.animation_list, new_animation);
}

Animation* new_animation_simultaneous()
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__SIMULTANEOUS;

    animation->simultaneous.animation_list = new_list((void(*)(void*))&destroy_animation);

    return animation;
}

Animation* new_animation_simultaneous_of_1(Animation* animation_1)
{
    Animation* simultaneous = new_animation_simultaneous();
    add_animation_to_end_animation_simultaneous(simultaneous, animation_1);
    return simultaneous;
}

Animation* new_animation_simultaneous_of_2(Animation* animation_1, Animation* animation_2)
{
    Animation* simultaneous = new_animation_simultaneous();
    add_animation_to_end_animation_simultaneous(simultaneous, animation_1);
    add_animation_to_end_animation_simultaneous(simultaneous, animation_2);
    return simultaneous;
}

Animation* new_animation_simultaneous_of_3(Animation* animation_1, Animation* animation_2, Animation* animation_3)
{
    Animation* simultaneous = new_animation_simultaneous();
    add_animation_to_end_animation_simultaneous(simultaneous, animation_1);
    add_animation_to_end_animation_simultaneous(simultaneous, animation_2);
    add_animation_to_end_animation_simultaneous(simultaneous, animation_3);
    return simultaneous;
}

void add_animation_to_end_animation_simultaneous(Animation* animation_simultaneous, Animation* new_animation)
{
    add_new_list_element_to_list_end(animation_simultaneous->simultaneous.animation_list, new_animation);
}

Animation* new_animation_move_sprite_in_gamemap_in_line(Texture* texture, Vec2f from_gamemap_pos, Vec2f to_gamemap_pos, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE;

    animation->move_sprite_in_gamemap_in_line.time = 0.0f;
    animation->move_sprite_in_gamemap_in_line.sprite = 0;

    animation->move_sprite_in_gamemap_in_line.texture = texture;
    animation->move_sprite_in_gamemap_in_line.from_gamemap_pos = from_gamemap_pos;
    animation->move_sprite_in_gamemap_in_line.to_gamemap_pos = to_gamemap_pos;
    animation->move_sprite_in_gamemap_in_line.seconds = seconds;

    return animation;
}

Animation* new_animation_move_sprite_in_gamemap_in_arch(Texture* texture, Vec2f from_gamemap_pos, Vec2f to_gamemap_pos, float seconds, float sin_mul)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH;

    animation->move_sprite_in_gamemap_in_arch.time = 0.0f;
    animation->move_sprite_in_gamemap_in_arch.sprite = 0;

    animation->move_sprite_in_gamemap_in_arch.texture = texture;
    animation->move_sprite_in_gamemap_in_arch.from_gamemap_pos = from_gamemap_pos;
    animation->move_sprite_in_gamemap_in_arch.to_gamemap_pos = to_gamemap_pos;
    animation->move_sprite_in_gamemap_in_arch.seconds = seconds;
    animation->move_sprite_in_gamemap_in_arch.sin_mul = sin_mul;

    return animation;
}

Animation* new_animation_show_sprite_in_gamemap(Texture* texture, Vec2f gamemap_pos, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__SHOW_SPRITE_IN_GAMEMAP;

    animation->show_sprite_in_gamemap.time = 0.0f;
    animation->show_sprite_in_gamemap.sprite = 0;

    animation->show_sprite_in_gamemap.texture = texture;
    animation->show_sprite_in_gamemap.gamemap_pos = gamemap_pos;
    animation->show_sprite_in_gamemap.seconds = seconds;

    return animation;
}

Animation* new_animation_ascend_sprite_in_gamemap(Texture* texture, Vec2f gamemap_pos, float length, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__ASCEND_SPRITE_IN_GAMEMAP;

    animation->ascend_sprite_in_gamemap.time = 0.0f;
    animation->ascend_sprite_in_gamemap.sprite = 0;

    animation->ascend_sprite_in_gamemap.texture = texture;
    animation->ascend_sprite_in_gamemap.gamemap_pos = gamemap_pos;
    animation->ascend_sprite_in_gamemap.length = length;
    animation->ascend_sprite_in_gamemap.seconds = seconds;

    return animation;
}

Animation* new_animation_descend_sprite_in_gamemap(Texture* texture, Vec2f gamemap_pos, float length, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__DESCEND_SPRITE_IN_GAMEMAP;

    animation->descend_sprite_in_gamemap.time = 0.0f;
    animation->descend_sprite_in_gamemap.sprite = 0;

    animation->descend_sprite_in_gamemap.texture = texture;
    animation->descend_sprite_in_gamemap.gamemap_pos = gamemap_pos;
    animation->descend_sprite_in_gamemap.length = length;
    animation->descend_sprite_in_gamemap.seconds = seconds;

    return animation;
}

Animation* new_animation_fall_sprite_in_gamemap(Texture* texture, Vec2f gamemap_pos, float length, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__FALL_SPRITE_IN_GAMEMAP;

    animation->fall_sprite_in_gamemap.time = 0.0f;
    animation->fall_sprite_in_gamemap.sprite = 0;

    animation->fall_sprite_in_gamemap.texture = texture;
    animation->fall_sprite_in_gamemap.gamemap_pos = gamemap_pos;
    animation->fall_sprite_in_gamemap.length = length;
    animation->fall_sprite_in_gamemap.seconds = seconds;

    return animation;
}

Animation* new_animation_move_camera_in_world_in_line(Vec2f from_world_pos, Vec2f to_world_pos, float seconds, int start_from_curr)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE;

    animation->move_camera_in_world_in_line.time = 0.0f;
    animation->move_camera_in_world_in_line.from_world_pos = from_world_pos;
    animation->move_camera_in_world_in_line.to_world_pos = to_world_pos;
    animation->move_camera_in_world_in_line.seconds = seconds;
    animation->move_camera_in_world_in_line.start_from_curr = start_from_curr;

    return animation;
}

Animation* new_animation_move_camera_in_world_in_arch(Vec2f from_world_pos, Vec2f to_world_pos, float seconds, float sin_mul, int start_from_curr)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH;

    animation->move_camera_in_world_in_arch.time = 0.0f;
    animation->move_camera_in_world_in_arch.from_world_pos = from_world_pos;
    animation->move_camera_in_world_in_arch.to_world_pos = to_world_pos;
    animation->move_camera_in_world_in_arch.seconds = seconds;
    animation->move_camera_in_world_in_arch.sin_mul = sin_mul;
    animation->move_camera_in_world_in_arch.start_from_curr = start_from_curr;

    return animation;
}
Animation* new_animation_move_camera_in_gamemap_in_line(Vec2f from_gamemap_pos, Vec2f to_gamemap_pos, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE;

    animation->move_camera_in_gamemap_in_line.time = 0.0f;
    animation->move_camera_in_gamemap_in_line.from_gamemap_pos = from_gamemap_pos;
    animation->move_camera_in_gamemap_in_line.to_gamemap_pos = to_gamemap_pos;
    animation->move_camera_in_gamemap_in_line.seconds = seconds;

    return animation;
}

Animation* new_animation_move_camera_in_gamemap_in_arch(Vec2f from_gamemap_pos, Vec2f to_gamemap_pos, float seconds, float sin_mul)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH;

    animation->move_camera_in_gamemap_in_arch.time = 0.0f;
    animation->move_camera_in_gamemap_in_arch.from_gamemap_pos = from_gamemap_pos;
    animation->move_camera_in_gamemap_in_arch.to_gamemap_pos = to_gamemap_pos;
    animation->move_camera_in_gamemap_in_arch.seconds = seconds;
    animation->move_camera_in_gamemap_in_arch.sin_mul = sin_mul;

    return animation;
}

Animation* new_animation_play_sound(Sound* sound)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__PLAY_SOUND;
    animation->play_sound.sound = sound;

    return animation;
}

Animation* new_animation_camera_shake(int times, float distance, float seconds)
{
    Animation* camera_shake = new_animation_sequence();

    float seconds_quarter = seconds * 0.25f * (1.0f / times);
    Vec2f to_left_world_pos = vec2f(-distance, 0.0f);
    Vec2f to_right_world_pos = vec2f(distance, 0.0f);

    for(int i = 0; i < times; i++)
    {
        Animation* camera_move_1 = new_animation_move_camera_in_world_in_line(vec2f(0.0f, 0.0f),to_left_world_pos,seconds_quarter,1);
        Animation* camera_move_2 = new_animation_move_camera_in_world_in_line(vec2f(0.0f, 0.0f),to_right_world_pos,seconds_quarter,1);
        Animation* camera_move_3 = new_animation_move_camera_in_world_in_line(vec2f(0.0f, 0.0f),to_right_world_pos,seconds_quarter,1);
        Animation* camera_move_4 = new_animation_move_camera_in_world_in_line(vec2f(0.0f, 0.0f),to_left_world_pos,seconds_quarter,1);

        add_animation_to_end_animation_sequence(camera_shake,camera_move_1);
        add_animation_to_end_animation_sequence(camera_shake,camera_move_2);
        add_animation_to_end_animation_sequence(camera_shake,camera_move_3);
        add_animation_to_end_animation_sequence(camera_shake,camera_move_4);
    }

    return camera_shake;
}

void destroy_animation(Animation* animation)
{
    if(animation->type == ANIMATION_TYPE__SEQUENCE)
    {
        destroy_list(animation->sequence.animation_list);
    }

    if(animation->type == ANIMATION_TYPE__SIMULTANEOUS)
    {
        destroy_list(animation->simultaneous.animation_list);
    }

    free(animation);
}

char* get_animation_name_from_type(int animation_type)
{
    char* name = "";

    switch(animation_type)
    {
        case ANIMATION_TYPE__NONE:                             name = "none";                              break;
        case ANIMATION_TYPE__SEQUENCE:                         name = "sequence";                          break;
        case ANIMATION_TYPE__SIMULTANEOUS:                     name = "simultaneous";                      break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:   name = "move sprite in gamemap in line";    break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:   name = "move sprite in gamemap in arch";    break;
        case ANIMATION_TYPE__SHOW_SPRITE_IN_GAMEMAP:           name = "show sprite in gamemap";            break;
        case ANIMATION_TYPE__ASCEND_SPRITE_IN_GAMEMAP:         name = "ascend sprite in gamemap";          break;
        case ANIMATION_TYPE__DESCEND_SPRITE_IN_GAMEMAP:        name = "descend sprite in gamemap";         break;
        case ANIMATION_TYPE__FALL_SPRITE_IN_GAMEMAP:           name = "fall sprite in gamemap";            break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:     name = "move camera in world in line";      break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:     name = "move camera in world in arch";      break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:   name = "move camera in gamemap in line";    break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:   name = "move camera in gamemap in arch";    break;
        case ANIMATION_TYPE__PLAY_SOUND:                       name = "play sound";                        break;
        default: break;
    }

    return name;
}
