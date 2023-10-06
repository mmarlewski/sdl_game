#ifndef STATE_H
#define STATE_H

#include "common.h"
#include "input.h"
#include "vec.h"
#include "dir.h"
#include "math_utils.h"
#include "floor.h"
#include "object.h"
#include "sprite.h"
#include "animation.h"
#include "action.h"
#include "skill.h"
#include "texture.h"
#include "textures.h"
#include "sounds.h"
#include "musics.h"

enum GAMESTATE
{
    GAMESTATE__NONE,

    GAMESTATE__CHOOSING_SKILL,
    GAMESTATE__CHOOSING_TARGET_1,
    GAMESTATE__CHOOSING_TARGET_2,
    GAMESTATE__SKILL_EXECUTING,

    GAMESTATE__COUNT
};

typedef struct
{
    int floor;

} Tile;

typedef struct
{
    vec2f world_pos;
    float zoom;

} State_Camera;

typedef struct
{
    vec2i screen_pos;
    vec2f world_pos;
    vec2f gamemap_pos;
    vec2i tilemap_pos;

    int is_dragging;
    vec2f drag_origin_world_pos;

} State_Mouse;

typedef struct
{
    Tile* tilemap[TILEMAP_HEIGHT][TILEMAP_WIDTH];

    Object* object_head;
    Object* object_tail;
    Object* object_hero;

    Sprite* sprite_head;
    Sprite* sprite_tail;

    vec2i selected_tilemap_pos;

    int curr_skill;
    int is_skill_two_target;
    vec2i target_1_tilemap_pos;
    vec2i target_2_tilemap_pos;

    vec2i* possible_target_1_tilemap_pos[100];
    vec2i* possible_target_2_tilemap_pos[100];

} State_Gamemap;

typedef struct
{
    int is_executing_actions;
    Action* action_sequence;

} State_Action;

typedef struct
{
    int is_game_running;
    int gamestate;

    State_Camera camera;
    State_Mouse mouse;
    State_Gamemap gamemap;
    State_Action action;

} State;

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics);
void update_state (Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);

void change_gamestate(State* state, int new_gamestate);

int is_tilemap_pos_in_tilemap(vec2i tilemap_pos);
Object* get_object_on_tilemap_pos(State* state, vec2i tilemap_pos);
int get_floor_on_tilemap_pos(State* state, vec2i tilemap_pos);
void change_floor_in_tilemap_pos(State* state, int new_floor, vec2i tilemap_pos);

void add_object_to_gamemap_objects(State* state, Object* new_object);
void remove_object_from_gamemap_objects(State* state, Object* object);

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite);
void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite);

void add_pos_to_possible_target_1_tilemap_pos(State* state, vec2i* new_pos);
void remove_all_pos_from_possible_target_1_tilemap_pos(State* state);
int is_tilemap_pos_in_possible_target_1_tilemap_pos(State* state, vec2i pos);

void add_pos_to_possible_target_2_tilemap_pos(State* state, vec2i* new_pos);
void remove_all_pos_from_possible_target_2_tilemap_pos(State* state);
int is_tilemap_pos_in_possible_target_2_tilemap_pos(State* state, vec2i pos);

void start_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics);
void update_animation(State* state, Animation* animation, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);
void end_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics);

void execute_actions(State* state, Textures* textures, Sounds* sounds, Musics* musics);
void print_action(Action* action, int depth);

void start_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics);
void update_action(State* state, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);
void end_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics);

void floor_on_move_end(State* state, Action* action_sequence, int floor);
void floor_on_push_end(State* state, Action* action_sequence, int floor);
void floor_on_move_start(State* state, Action* action_sequence, int floor);
void floor_on_push_start(State* state, Action* action_sequence, int floor);
void floor_on_drop(State* state, Action* action_sequence, int floor);

void object_on_crashing(State* state, Action* action_sequence, Object* object);
void object_on_crashed(State* state, Action* action_sequence, Object* object);
void object_on_death(State* state, Action* action_sequence, Object* object);
void object_on_drop(State* state, Action* action_sequence, Object* object);

void skill_add_pos_to_possible_target_1_tilemap_pos(State* state, int skill, vec2i source_tilemap_pos);
void skill_add_pos_to_possible_target_2_tilemap_pos(State* state, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos);
void skill_get_actions_to_execute(State* state, Action* action, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos, vec2i target_2_tilemap_pos);

char* get_gamestate_name(int gamestate);

#endif