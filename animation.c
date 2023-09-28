#include "animation.h"

Animation* new_animation_none()
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__NONE;

    return animation;
}

Animation* new_animation_sequence()
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__SEQUENCE;

    animation->sequence.curr_animation = 0;
    animation->sequence.animation_head = 0;
    animation->sequence.animation_tail = 0;

    return animation;
}

void add_animation_to_end_animation_sequence(Animation* animation_sequence, Animation* new_animation)
{
    if(animation_sequence->sequence.animation_head)
    {
        animation_sequence->sequence.animation_tail->next = new_animation;
    }
    else
    {
        animation_sequence->sequence.animation_head = new_animation;
    }

    animation_sequence->sequence.animation_tail = new_animation;
    new_animation->next = 0;
}

Animation* new_animation_simultaneous()
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__SIMULTANEOUS;

    animation->simultaneous.are_all_animations_finished = 0;
    animation->simultaneous.animation_head = 0;
    animation->simultaneous.animation_tail = 0;

    return animation;
}

void add_animation_to_end_animation_simultaneous(Animation* animation_simultaneous, Animation* new_animation)
{
    if(animation_simultaneous->simultaneous.animation_head)
    {
        animation_simultaneous->simultaneous.animation_tail->next = new_animation;
    }
    else
    {
        animation_simultaneous->simultaneous.animation_head = new_animation;
    }

    animation_simultaneous->simultaneous.animation_tail = new_animation;
    new_animation->next = 0;
}

Animation* new_animation_move_sprite_in_gamemap_in_line(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
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

Animation* new_animation_move_sprite_in_gamemap_in_arch(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH;

    animation->move_sprite_in_gamemap_in_arch.time = 0.0f;
    animation->move_sprite_in_gamemap_in_arch.sprite = 0;

    animation->move_sprite_in_gamemap_in_arch.texture = texture;
    animation->move_sprite_in_gamemap_in_arch.from_gamemap_pos = from_gamemap_pos;
    animation->move_sprite_in_gamemap_in_arch.to_gamemap_pos = to_gamemap_pos;
    animation->move_sprite_in_gamemap_in_arch.seconds = seconds;

    return animation;
}

Animation* new_animation_show_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__SHOW_SPRITE_IN_TILEMAP;

    animation->show_sprite_in_tilemap.time = 0.0f;
    animation->show_sprite_in_tilemap.sprite = 0;

    animation->show_sprite_in_tilemap.texture = texture;
    animation->show_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    animation->show_sprite_in_tilemap.seconds = seconds;

    return animation;
}

Animation* new_animation_ascend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float length, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__ASCEND_SPRITE_IN_TILEMAP;

    animation->ascend_sprite_in_tilemap.time = 0.0f;
    animation->ascend_sprite_in_tilemap.sprite = 0;

    animation->ascend_sprite_in_tilemap.texture = texture;
    animation->ascend_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    animation->ascend_sprite_in_tilemap.length = length;
    animation->ascend_sprite_in_tilemap.seconds = seconds;

    return animation;
}

Animation* new_animation_descend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float length, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__DESCEND_SPRITE_IN_TILEMAP;

    animation->descend_sprite_in_tilemap.time = 0.0f;
    animation->descend_sprite_in_tilemap.sprite = 0;

    animation->descend_sprite_in_tilemap.texture = texture;
    animation->descend_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    animation->descend_sprite_in_tilemap.length = length;
    animation->descend_sprite_in_tilemap.seconds = seconds;

    return animation;
}

Animation* new_animation_drop_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float length, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__DROP_SPRITE_IN_TILEMAP;

    animation->drop_sprite_in_tilemap.time = 0.0f;
    animation->drop_sprite_in_tilemap.sprite = 0;

    animation->drop_sprite_in_tilemap.texture = texture;
    animation->drop_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    animation->drop_sprite_in_tilemap.length = length;
    animation->drop_sprite_in_tilemap.seconds = seconds;

    return animation;
}

Animation* new_animation_move_camera_in_world_in_line(vec2f from_world_pos, vec2f to_world_pos, float seconds, int start_from_curr)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE;

    animation->move_camera_in_world_in_line.time = 0.0f;
    animation->move_camera_in_world_in_line.from_world_pos = from_world_pos;
    animation->move_camera_in_world_in_line.to_world_pos = to_world_pos;
    animation->move_camera_in_world_in_line.seconds = seconds;
    animation->move_camera_in_world_in_line.start_from_curr = start_from_curr;

    return animation;
}

Animation* new_animation_move_camera_in_world_in_arch(vec2f from_world_pos, vec2f to_world_pos, float seconds, float sin_mul, int start_from_curr)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
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
Animation* new_animation_move_camera_in_gamemap_in_line(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE;

    animation->move_camera_in_gamemap_in_line.time = 0.0f;
    animation->move_camera_in_gamemap_in_line.from_gamemap_pos = from_gamemap_pos;
    animation->move_camera_in_gamemap_in_line.to_gamemap_pos = to_gamemap_pos;
    animation->move_camera_in_gamemap_in_line.seconds = seconds;

    return animation;
}

Animation* new_animation_move_camera_in_gamemap_in_arch(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds, float sin_mul)
{
    Animation* animation = malloc(sizeof(* animation));

    animation->next = 0;
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

    animation->next = 0;
    animation->is_finished = 0;
    animation->type = ANIMATION_TYPE__PLAY_SOUND;
    animation->play_sound.sound = sound;

    return animation;
}

Animation* new_animation_camera_shake(int times, float distance, float seconds)
{
    Animation* camera_shake = new_animation_sequence();

    float seconds_quarter = seconds * 0.25f;
    vec2f to_left_world_pos = make_vec2f(-distance, 0.0f);
    vec2f to_right_world_pos = make_vec2f(distance, 0.0f);

    for(int i = 0; i < times; i++)
    {
        Animation* camera_move_1 = new_animation_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_left_world_pos,seconds_quarter,1);
        Animation* camera_move_2 = new_animation_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_right_world_pos,seconds_quarter,1);
        Animation* camera_move_3 = new_animation_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_right_world_pos,seconds_quarter,1);
        Animation* camera_move_4 = new_animation_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_left_world_pos,seconds_quarter,1);

        add_animation_to_end_animation_sequence(camera_shake,camera_move_1);
        add_animation_to_end_animation_sequence(camera_shake,camera_move_2);
        add_animation_to_end_animation_sequence(camera_shake,camera_move_3);
        add_animation_to_end_animation_sequence(camera_shake,camera_move_4);
    }

    return camera_shake;
}

void destroy_animation(Animation* animation)
{
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
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:   name = "move sprite in gamemap_in_line";    break;
        case ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:   name = "move sprite in gamemap_in_arch";    break;
        case ANIMATION_TYPE__SHOW_SPRITE_IN_TILEMAP:           name = "show sprite in tilemap";            break;
        case ANIMATION_TYPE__ASCEND_SPRITE_IN_TILEMAP:         name = "ascend sprite in tilemap";          break;
        case ANIMATION_TYPE__DESCEND_SPRITE_IN_TILEMAP:        name = "descend sprite in tilemap";         break;
        case ANIMATION_TYPE__DROP_SPRITE_IN_TILEMAP:           name = "drop sprite in tilemap";            break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:     name = "move camera in world in line";      break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:     name = "move camera in world in arch";      break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:   name = "move camera in gamemap in line";    break;
        case ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:   name = "move camera in gamemap in arch";    break;
        case ANIMATION_TYPE__PLAY_SOUND:                       name = "play sound";                        break;
        default: break;
    }

    return name;
}