#ifndef ANIMATION_H
#define ANIMATION_H

#include "common.h"
#include "vec.h"
#include "sprite.h"

enum ANIMATION_TYPE
{
    ANIMATION_TYPE__NONE,

    ANIMATION_TYPE__SEQUENCE,
    ANIMATION_TYPE__SIMULTANEOUS,

    ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE,
    ANIMATION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH,

    ANIMATION_TYPE__SHOW_SPRITE_IN_TILEMAP,
    ANIMATION_TYPE__ASCEND_SPRITE_IN_TILEMAP,
    ANIMATION_TYPE__DESCEND_SPRITE_IN_TILEMAP,
    ANIMATION_TYPE__FALL_SPRITE_IN_TILEMAP,

    ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE,
    ANIMATION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH,

    ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE,
    ANIMATION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH,

    ANIMATION_TYPE__PLAY_SOUND
};

typedef struct _Animation Animation;

typedef struct
{
} Animation_None;

typedef struct
{
    Animation* curr_animation;
    Animation* animation_head;
    Animation* animation_tail;

} Animation_Sequence;

typedef struct
{
    int are_all_animations_finished;
    Animation* animation_head;
    Animation* animation_tail;

} Animation_Simultaneous;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;

} Animation_MoveSpriteInGamemapInLine;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;
    float sin_mul;

} Animation_MoveSpriteInGamemapInArch;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float seconds;

} Animation_ShowSpriteInTilemap;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float length;
    float seconds;

} Animation_AscendSpriteInTilemap;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float length;
    float seconds;

} Animation_DescendSpriteInTilemap;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float length;
    float seconds;

} Animation_FallSpriteInTilemap;

typedef struct
{
    float time;

    vec2f from_world_pos;
    vec2f to_world_pos;
    float seconds;
    int start_from_curr;

} Animation_MoveCameraInWorldInLine;

typedef struct
{
    float time;

    vec2f from_world_pos;
    vec2f to_world_pos;
    float seconds;
    float sin_mul;
    int start_from_curr;

} Animation_MoveCameraInWorldInArch;

typedef struct
{
    float time;

    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;

} Animation_MoveCameraInGamemapInLine;

typedef struct
{
    float time;

    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;
    float sin_mul;

} Animation_MoveCameraInGamemapInArch;

typedef struct
{
    Sound* sound;

} Animation_PlaySound;

struct _Animation
{
    Animation* next;
    int is_finished;
    int type;

    union
    {
        Animation_None none;

        Animation_Sequence sequence;
        Animation_Simultaneous simultaneous;

        Animation_MoveSpriteInGamemapInLine move_sprite_in_gamemap_in_line;
        Animation_MoveSpriteInGamemapInArch move_sprite_in_gamemap_in_arch;

        Animation_ShowSpriteInTilemap show_sprite_in_tilemap;
        Animation_AscendSpriteInTilemap ascend_sprite_in_tilemap;
        Animation_DescendSpriteInTilemap descend_sprite_in_tilemap;
        Animation_FallSpriteInTilemap fall_sprite_in_tilemap;

        Animation_MoveCameraInWorldInLine move_camera_in_world_in_line;
        Animation_MoveCameraInWorldInArch move_camera_in_world_in_arch;

        Animation_MoveCameraInGamemapInLine move_camera_in_gamemap_in_line;
        Animation_MoveCameraInGamemapInArch move_camera_in_gamemap_in_arch;

        Animation_PlaySound play_sound;
    };
};

Animation* new_animation_none();

Animation* new_animation_sequence();
Animation* new_animation_sequence_of_1(Animation* animation_1);
Animation* new_animation_sequence_of_2(Animation* animation_1, Animation* animation_2);
Animation* new_animation_sequence_of_3(Animation* animation_1, Animation* animation_2, Animation* animation_3);
void add_animation_to_end_animation_sequence(Animation* animation_sequence, Animation* new_animation);

Animation* new_animation_simultaneous();
Animation* new_animation_simultaneous_of_1(Animation* animation_1);
Animation* new_animation_simultaneous_of_2(Animation* animation_1, Animation* animation_2);
Animation* new_animation_simultaneous_of_3(Animation* animation_1, Animation* animation_2, Animation* animation_3);
void add_animation_to_end_animation_simultaneous(Animation* animation_simultaneous, Animation* new_animation);

Animation* new_animation_move_sprite_in_gamemap_in_line(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds);
Animation* new_animation_move_sprite_in_gamemap_in_arch(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds, float sin_mul);

Animation* new_animation_show_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds);
Animation* new_animation_ascend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float length, float seconds);
Animation* new_animation_descend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float length, float seconds);
Animation* new_animation_fall_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float length, float seconds);

Animation* new_animation_move_camera_in_world_in_line(vec2f from_world_pos, vec2f to_world_pos, float seconds, int start_from_curr);
Animation* new_animation_move_camera_in_world_in_arch(vec2f from_world_pos, vec2f to_world_pos, float seconds, float sin_mul, int start_from_curr);

Animation* new_animation_move_camera_in_gamemap_in_line(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds);
Animation* new_animation_move_camera_in_gamemap_in_arch(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds, float sin_mul);

Animation* new_animation_play_sound(Sound* sound);

Animation* new_animation_camera_shake(int times, float distance, float seconds);

void destroy_animation(Animation* animation);

char* get_animation_name_from_type(int animation_type);

#endif