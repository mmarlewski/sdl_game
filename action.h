#ifndef ACTION_H
#define ACTION_H

#include "common.h"
#include "vec.h"
#include "dir.h"
#include "sprite.h"
#include "floor.h"
#include "object.h"

enum ACTION_TYPE
{
    ACTION_TYPE__NONE,


    ACTION_TYPE__SEQUENCE,
    ACTION_TYPE__SIMULTANEOUS,


    ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE,
    ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH,

    ACTION_TYPE__SHOW_SPRITE_IN_TILEMAP,
    ACTION_TYPE__ASCEND_SPRITE_IN_TILEMAP,
    ACTION_TYPE__DESCEND_SPRITE_IN_TILEMAP,
    ACTION_TYPE__DROP_SPRITE_IN_TILEMAP,

    ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE,
    ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH,

    ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE,
    ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH,

    ACTION_TYPE__PLAY_SOUND,


    ACTION_TYPE__MOVE,
    ACTION_TYPE__PUSH,
    ACTION_TYPE__CRASH,

    ACTION_TYPE__DROP,
    ACTION_TYPE__DEATH,


    ACTION_TYPE__COUNT
};

//////////

//////////

typedef struct _Action Action;

typedef struct
{
} Action_None;

typedef struct
{
    Action* curr_action;
    Action* action_head;
    Action* action_tail;

} Action_Sequence;

typedef struct
{
    int are_all_actions_finished;
    Action* action_head;
    Action* action_tail;

} Action_Simultaneous;

//////////

//////////

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;

} Action_MoveSpriteInGamemapInLine;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;

} Action_MoveSpriteInGamemapInArch;

//////////

//////////

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float seconds;

} Action_ShowSpriteInTilemap;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float seconds;

} Action_AscendSpriteInTilemap;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float seconds;

} Action_DescendSpriteInTilemap;

typedef struct
{
    float time;
    Sprite* sprite;

    Texture* texture;
    vec2i tilemap_pos;
    float seconds;

} Action_DropSpriteInTilemap;

//////////

//////////

typedef struct
{
    float time;

    vec2f from_world_pos;
    vec2f to_world_pos;
    float seconds;
    int start_from_curr;

} Action_MoveCameraInWorldInLine;

typedef struct
{
    float time;

    vec2f from_world_pos;
    vec2f to_world_pos;
    float seconds;
    float sin_mul;
    int start_from_curr;

} Action_MoveCameraInWorldInArch;

typedef struct
{
    float time;

    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;

} Action_MoveCameraInGamemapInLine;

typedef struct
{
    float time;

    vec2f from_gamemap_pos;
    vec2f to_gamemap_pos;
    float seconds;
    float sin_mul;

} Action_MoveCameraInGamemapInArch;

//////////

//////////

typedef struct
{
    Sound* sound;

} Action_PlaySound;

typedef struct
{
    Action* action_move_sprite_in_gamemap;
    int is_move_blocked;
    
    Object* object;
    int dir4;

} Action_Move;

typedef struct
{
    Action* action_move_sprite_in_gamemap;
    int is_move_blocked;

    Object* object;
    int dir4;

} Action_Push;

typedef struct
{
    Action* action_sequence;

    Object* object;
    int dir4;

} Action_Crash;

typedef struct
{
    Action* action_drop_sprite_in_tilemap;

    Object* object;

} Action_Drop;

typedef struct
{
    Object* object;

} Action_Death;

//////////

//////////

struct _Action
{
    Action* next;
    int is_finished;
    int type;

    union
    {
        Action_None action_none;

        Action_Sequence sequence;
        Action_Simultaneous simultaneous;

        Action_MoveSpriteInGamemapInLine move_sprite_in_gamemap_in_line;
        Action_MoveSpriteInGamemapInArch move_sprite_in_gamemap_in_arch;

        Action_ShowSpriteInTilemap show_sprite_in_tilemap;
        Action_AscendSpriteInTilemap ascend_sprite_in_tilemap;
        Action_DescendSpriteInTilemap descend_sprite_in_tilemap;
        Action_DropSpriteInTilemap drop_sprite_in_tilemap;

        Action_MoveCameraInWorldInLine move_camera_in_world_in_line;
        Action_MoveCameraInWorldInArch move_camera_in_world_in_arch;

        Action_MoveCameraInGamemapInLine move_camera_in_gamemap_in_line;
        Action_MoveCameraInGamemapInArch move_camera_in_gamemap_in_arch;

        Action_PlaySound play_sound;

        Action_Move move;
        Action_Push push;
        Action_Crash crash;

        Action_Drop drop;
        Action_Death death;
    };

};

Action* new_action_none();

Action* new_action_sequence();
void add_action_to_end_action_sequence(Action* action_sequence, Action* new_action);
Action* new_action_simultaneous();
void add_action_to_end_action_simultaneous(Action* action_simultaneous, Action* new_action);

Action* new_action_move_sprite_in_gamemap_in_line(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds);
Action* new_action_move_sprite_in_gamemap_in_arch(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds);

Action* new_action_show_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds);
Action* new_action_ascend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds);
Action* new_action_descend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds);
Action* new_action_drop_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds);

Action* new_action_move_camera_in_world_in_line(vec2f from_world_pos, vec2f to_world_pos, float seconds, int start_from_curr);
Action* new_action_move_camera_in_world_in_arch(vec2f from_world_pos, vec2f to_world_pos, float seconds, float sin_mul, int start_from_curr);

Action* new_action_move_camera_in_gamemap_in_line(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds);
Action* new_action_move_camera_in_gamemap_in_arch(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds, float sin_mul);

Action* new_action_play_sound(Sound* sound);

Action* new_action_move(Object* object, int dir4);
Action* new_action_push(Object* object, int dir4);
Action* new_action_crash(Object* object, int dir4);

Action* new_action_drop(Object* object);
Action* new_action_death(Object* object);

Action* new_action_camera_shake(int times, float distance, float seconds);

void destroy_action(Action* action);

char* get_action_name_from_type(int action_type);

#endif