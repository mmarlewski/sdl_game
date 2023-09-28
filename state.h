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
#include "action.h"
#include "texture.h"
#include "textures.h"
#include "sounds.h"
#include "musics.h"

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
    Object* object_acting;

    vec2i* danger_tilemap_pos_head;
    vec2i* danger_tilemap_pos_tail;

    vec2i highlight_tilemap_pos;

    Sprite* sprite_head;
    Sprite* sprite_tail;

} State_Gamemap;

typedef struct
{
    int is_executing_actions;
    Action* curr_action;
    Action* action_head;
    Action* action_tail;

} State_Action;

typedef struct
{
    int is_game_running;

    State_Camera camera;
    State_Mouse mouse;
    State_Gamemap gamemap;
    State_Action action;

} State;

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics);
void update_state (Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);

int is_tilemap_pos_in_tilemap(vec2i tilemap_pos);
Object* get_object_on_tilemap_pos(State* state, vec2i tilemap_pos);
int get_floor_on_tilemap_pos(State* state, vec2i tilemap_pos);

void change_floor_in_tilemap_pos(State* state, int new_floor, vec2i tilemap_pos);

void add_object_to_gamemap_objects(State* state, Object* new_object);
void remove_object_from_gamemap_objects(State* state, Object* object);

void add_pos_to_gamemap_danger_pos(State* state, vec2i* new_pos);
void remove_pos_from_gamemap_danger_pos(State* state, vec2i* pos);
void remove_all_pos_from_gamemap_danger_pos(State* state);

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite);
void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite);
void remove_all_sprites_from_gamemap_sprites(State* state);

void add_action_to_end_actions(State* state, Action* new_action);
void add_action_after_curr_action(State* state, Action* new_action);
void remove_all_actions_after_curr_action(State* state);
void execute_actions(State* state, Textures* textures, Sounds* sounds, Musics* musics);

void start_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics);
void update_action(State* state, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);
void end_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics);

Action* get_action_from_floor_on_action(Action* action_trigger, int floor);

#endif