#ifndef STATE_H
#define STATE_H

#include "../inc/common.h"
#include "../inc/input.h"
#include "../inc/vec.h"
#include "../inc/dir.h"
#include "../inc/list.h"
#include "../inc/math_utils.h"
#include "../inc/floor.h"
#include "../inc/object.h"
#include "../inc/sprite.h"
#include "../inc/animation.h"
#include "../inc/action.h"
#include "../inc/skill.h"
#include "../inc/texture.h"
#include "../inc/textures.h"
#include "../inc/sounds.h"
#include "../inc/musics.h"

enum GAMESTATE
{
    GAMESTATE__NONE,

    GAMESTATE__HERO_CHOOSING_SKILL,
    GAMESTATE__HERO_CHOOSING_TARGET_1,
    GAMESTATE__HERO_CHOOSING_TARGET_2,
    GAMESTATE__HERO_EXECUTING_SKILL,

    GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK,
    GAMESTATE__ENEMY_ATTACKING,
    GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE,
    GAMESTATE__ENEMY_MOVING,
    GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET,

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

    List* possible_target_1_tilemap_pos_list;
    List* possible_target_2_tilemap_pos_list;

    List* sprite_list;

    List* object_list;
    List* object_enemy_list;
    ListElem* curr_object_enemy_list_elem;
    Object* curr_object_enemy;
    Object* object_hero;

    vec2i prev_selected_tilemap_pos;
    vec2i curr_selected_tilemap_pos;

    int curr_skill;
    int is_skill_two_target;
    vec2i target_1_tilemap_pos;
    vec2i target_2_tilemap_pos;

} State_Gamemap;

typedef struct
{
    int is_executing_actions;
    Action* main_action_sequence;
    Action* enemy_action_sequence;
    List* enemy_action_sequence_list;
    ListElem* curr_enemy_action_sequence_list_elem;

} State_Action;

typedef struct
{
    int is_game_running;
    int gamestate;
    float timer;
    vec3i background_color;

    State_Camera camera;
    State_Mouse mouse;
    State_Gamemap gamemap;
    State_Action action;

} State;

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics);
void update_state (Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);

void change_gamestate(State* state, int new_gamestate);
void change_background_color(State* state, vec3i new_background_color);

int is_tilemap_pos_in_tilemap(vec2i tilemap_pos);
Object* get_object_on_tilemap_pos(State* state, vec2i tilemap_pos);
int get_floor_on_tilemap_pos(State* state, vec2i tilemap_pos);
void change_floor_in_tilemap_pos(State* state, int new_floor, vec2i tilemap_pos);

void add_object_to_gamemap_objects(State* state, Object* new_object);
void remove_object_from_gamemap_objects(State* state, Object* object);
void remove_all_dead_objects_from_gamemap_objects(State* state);

void add_action_sequence_to_gamemap_action_sequence(State* state, Action* new_action_sequence);
void remove_action_sequence_from_gamemap_action_sequence(State* state, Action* action_sequence);

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite);
void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite);

void add_pos_to_possible_target_1_tilemap_pos_list(State* state, vec2i* new_pos);
void remove_all_pos_from_possible_target_1_tilemap_pos_list(State* state);
int is_tilemap_pos_in_possible_target_1_tilemap_pos_list(State* state, vec2i pos);

void add_pos_to_possible_target_2_tilemap_pos_list(State* state, vec2i* new_pos);
void remove_all_pos_from_possible_target_2_tilemap_pos_list(State* state);
int is_tilemap_pos_in_possible_target_2_tilemap_pos_list(State* state, vec2i pos);

void start_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics);
void update_animation(State* state, Animation* animation, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);
void end_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics);

void remove_all_actions_from_main_action_sequence(State* state);
void execute_action_sequence(State* state, Action* action_sequence, Textures* textures, Sounds* sounds, Musics* musics);
void print_action(Action* action, int depth);

void start_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics);
void update_action(State* state, Action* sequence, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics);
void end_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics);

void floor_on_move_ground_start(State* state, Action* sequence, Action* action, int floor);
void floor_on_move_air_start(State* state, Action* sequence, Action* action, int floor);

void floor_on_move_ground_end(State* state, Action* sequence, Action* action, int floor);
void floor_on_move_air_end(State* state, Action* sequence, Action* action, int floor);

void floor_on_drop(State* state, Action* sequence, Action* action, int floor);

void object_on_crashing_ground(State* state, Action* sequence, Action* action, Object* object);
void object_on_crashing_air(State* state, Action* sequence, Action* action, Object* object);

void object_on_crashed_ground(State* state, Action* sequence, Action* action, Object* object);
void object_on_crashed_air(State* state, Action* sequence, Action* action, Object* object);

void object_on_death(State* state, Action* sequence, Action* action, Object* object);
void object_on_drop(State* state, Action* sequence, Action* action, Object* object);

void skill_add_pos_to_possible_target_1_tilemap_pos_list(State* state, int skill, vec2i source_tilemap_pos);
void skill_add_pos_to_possible_target_2_tilemap_pos_list(State* state, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos);
void skill_add_actions_to_action_sequence(State* state, Action* action_sequence, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos, vec2i target_2_tilemap_pos);

void object_enemy_add_actions_to_action_sequence_move(State* state, Action* action_sequence, Object* object);
void object_enemy_add_actions_to_action_sequence_attack(State* state, Action* action_sequence, Object* object);

char* get_gamestate_name(int gamestate);

#endif
