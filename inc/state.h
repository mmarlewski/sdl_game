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
#include "../inc/colors.h"
#include "../inc/font.h"
#include "../inc/fonts.h"
#include "../inc/augmentation.h"
#include "../inc/item.h"
#include "../inc/room.h"
#include "../inc/mechanism.h"

enum GAMESTATE
{
    GAMESTATE__NONE,

    GAMESTATE__ALLY_CHOOSING_SKILL,
    GAMESTATE__ALLY_CHOOSING_TARGET_1,
    GAMESTATE__ALLY_CHOOSING_TARGET_2,
    GAMESTATE__ALLY_EXECUTING_ANIMATION,
    GAMESTATE__ALLY_EXECUTING_SKILL,

    GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK,
    GAMESTATE__ENEMY_EXECUTING_ANIMATION,
    GAMESTATE__ENEMY_EXECUTING_ATTACK,
    GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE,
    GAMESTATE__ENEMY_MOVING,
    GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET,

    GAMESTATE__GAME_START,
    GAMESTATE__GAME_OVER,
    GAMESTATE__GAME_WON,

    GAMESTATE__COUNT
};

typedef struct
{
    int is_game_running;
    float time;
    float prev_save_time;
    float delta_time;
    int gamestate;
    float timer;
    Vec3i background_color;
    Texture* background_texture;

    Vec2f camera_world_pos;
    float camera_zoom;

    Vec2i mouse_screen_pos;
    Vec2f mouse_world_pos;
    Vec2f mouse_gamemap_pos;
    Vec2i mouse_tilemap_pos;

    int mouse_is_dragging;
    Vec2f mouse_drag_origin_world_pos;

    int is_executing_actions;
    Action* ally_action_sequence;
    Action* enemy_action_sequence;

    List* room_list;
    List* visited_room_list;
    List* passage_list;
    Room* curr_room;

    List* animation_list;
    List* sprite_list;

    List* possible_hint_tilemap_pos_list;
    List* possible_target_1_tilemap_pos_list;
    List* possible_target_2_tilemap_pos_list;
    int show_all_order_numbers;
    Vec2i selected_tilemap_pos;

    List* enemy_list;
    ListElem* curr_enemy_list_elem;
    Enemy* curr_enemy;

    List* ally_list;
    ListElem* curr_ally_list_elem;
    Ally* curr_ally;
    Object* curr_ally_object;
    int curr_ally_skill;
    int ally_move_distance;
    Vec2i curr_ally_target_1_tilemap_pos;
    Vec2i curr_ally_target_2_tilemap_pos;
    Animation* curr_skill_animation;

    Object* hero_object;
    int hero_item_number[ITEM__COUNT];
    int hero_body_part_augmentation[BODY_PART__COUNT];
    int hero_curr_item;

    Object* minibot_object;
    int was_minibot_launched;
    int was_throne_used;

    int was_secret_1_taken;
    int was_secret_2_taken;
    int was_secret_3_taken;
    int was_secret_4_taken;
    int was_secret_aug_unlocked;

    int reset_turn_uses;
    int game_over_uses;

    List* curr_ally_draw_below_texture_list;
    List* curr_ally_draw_below_tilemap_pos_list;
    List* curr_ally_draw_above_texture_list;
    List* curr_ally_draw_above_tilemap_pos_list;
    List* curr_ally_draw_effect_texture_list;
    List* curr_ally_draw_effect_tilemap_pos_list;

    List* mechanism_list;

    int prev_prev_music_index;
    int prev_music_index;
    int curr_music_index;

    int show_tutorial;
    int was_tutorial_finished;
    
    int is_game_start_animation_started;
    int is_game_start_animation_finished;

    int tutorial__go_to_exit;
    int tutorial__use_exit;
    int tutorial__get_goat_killed;
    int tutorial__get_chain_aug;
    int tutorial__go_back_for_dynamite;
    int tutorial__get_dynamite;
    int tutorial__unlock_rock_exit;
    int tutorial__save_cell;
    int tutorial__get_past_moles;

} State;

void init_state(State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void start_state(State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void update_state(Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void create_level(State* state, Textures* textures);
void create_mechanisms(State* state);
void save_state(State* state, Textures* textures);
void load_state(State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);

void get_tutorial_line_and_update_tutorial(State* state, int* n, char** line_1, char** line_2, char** line_3);

void add_room(State* state, Room* room);
Room* get_room(State* state, char* name);
void set_curr_room(State* state, Room* room);

void add_passage(State* state, Passage* passage);
Passage* get_passage(State* state, char* from_room_name, Vec2i from_tilemap_pos);

void change_gamestate(State* state, int new_gamestate);
void change_background_color(State* state, Vec3i new_background_color);

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite);
void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite);

void draw_texture_list(Renderer* renderer, State* state, List* texture_list, List* tilemap_pos_list, Vec3i color, float transparency);

void add_animation_to_animation_list(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);

void start_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void update_animation(State* state, Animation* animation, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void end_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);

void remove_all_actions_from_action_sequence(Action* action_sequence);
void execute_action_sequence(State* state, Action* action_sequence, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void print_action(Action* action, int depth);

void start_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void update_action(State* state, Action* sequence, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void end_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);

void floor_on_move_start(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_move_floating_start(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_move_flying_start(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_move_end(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_move_floating_end(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_move_flying_end(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_drop(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_drop_floating(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_drop_flying(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_melt(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_break(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_shake(State* state, Sounds* sounds, Action* sequence, Action* action, int floor);
void floor_on_stomp(State* state, Sounds* sounds, Action* sequence, int floor, Vec2i tilemap_pos);
void floor_on_manipulation(State* state, Sounds* sounds, Action* sequence, int floor, Vec2i tilemap_pos);
Animation* floor_on_manipulation_get_animation(State* state, int floor, Vec2i tilemap_pos, Textures* textures, Sounds* sounds);
void floor_on_pick_item(State* state, Sounds* sounds, Action* sequence, int floor, Vec2i tilemap_pos);
void floor_on_put_item(State* state, Sounds* sounds, Action* sequence, int floor, Vec2i tilemap_pos, int item_type);

void object_on_crashing(State* state, Sounds* sounds, Action* sequence, Action* action, Object* object);
void object_on_crashed(State* state, Sounds* sounds, Action* sequence, Action* action, Object* object);
void object_on_death(State* state, Sounds* sounds, Action* sequence, Action* action, Object* object);
void object_on_drop(State* state, Sounds* sounds, Action* sequence, Action* action, Object* object);
void object_on_melt(State* state, Sounds* sounds, Action* sequence, Action* action, Object* object);
void object_on_break(State* state, Sounds* sounds, Action* sequence, Action* action, Object* object);
void object_on_shake(State* state, Sounds* sounds, Action* sequence, Action* action, Object* object);
void object_on_stomp(State* state, Sounds* sounds, Action* sequence, Object* object, Vec2i tilemap_pos);
void object_on_manipulate(State* state, Sounds* sounds, Action* sequence, Object* object, Vec2i tilemap_pos);
Animation* object_on_manipulate_get_animation(State* state, Object* object, Vec2i tilemap_pos, Textures* textures);
void object_on_pick_item(State* state, Sounds* sounds, Action* sequence, Object* object, Vec2i tilemap_pos);
void object_on_put_item(State* state, Sounds* sounds, Action* sequence, Object* object, Vec2i tilemap_pos, int item_type);

void skill_on_use(State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void skill_get_possible_hint_pos(State* state, int skill, List* hint_pos_list);
void skill_get_possible_target_1_pos(State* state, int skill, Vec2i source_tilemap_pos, List* target_1_pos_list);
void skill_get_possible_target_2_pos(State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, List* target_2_pos_list);
Animation* skill_get_animation(State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos, Textures* textures, Colors* colors, Sounds* sounds);
void skill_get_actions_and_draw(State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos, Action* action_sequence, List* draw_below_texture_list, List* draw_below_tilemap_pos_list, List* draw_above_texture_list, List* draw_above_tilemap_pos_list, List* draw_effect_texture_list, List* draw_effect_tilemap_pos_list, Textures* textures, Sounds* sounds);

void object_enemy_prepare_move(State* state, Enemy* enemy, Sounds* sounds);
void update_enemy_attack_dir4(State* state, Enemy* enemy);
void update_enemy_attack_targets(State* state, Enemy* enemy);

char* get_gamestate_debug_name(int gamestate);

void hero_add_augmentation(State* state, int augmentation);
int hero_has_augmentation(State* state, int augmentation);

void get_object_skills(State* state, Object* object, List* skill_list);

Enemy* get_enemy_of_object(State* state, Object* object);
Ally* get_ally_of_object(State* state, Object* object);

void find_path(State* state, Vec2i start_tilemap_pos, Vec2i end_tilemap_pos, List* path, int is_floating, int is_flying);

void update_enemy_list(State* state);
void update_all_enemy_order(State* state);
void clear_enemy_attack_actions_and_draw(State* state, Enemy* enemy);
void get_enemy_attack_actions_and_draw(State* state, Enemy* enemy, Textures* textures, Sounds* sounds);

void update_ally_list(State* state);
void update_ally_skill_list(State* state, Ally* ally);
void restore_ally_action_points(State* state, Ally* ally);
void clear_curr_ally_attack_actions_and_draw(State* state);
void get_curr_ally_attack_actions_and_draw(State* state, Textures* textures, Sounds* sounds);

void remove_all_object_to_be_removed(State* state);

int is_floor_traversable_for_object(int floor, Object* object);
int is_floor_deadly_on_move_for_object(int floor, Object* object);
int is_floor_deadly_on_drop_for_object(int floor, Object* object);

// mechanism

void add_mechanism(State* state, Mechanism* mechanism);
void execute_all_mechanisms(State* state);
void execute_mechanism(State* state, Mechanism* mechanism);

#endif
