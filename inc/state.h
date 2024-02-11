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
#include "../inc/augmentation.h"
#include "../inc/item.h"
#include "../inc/room.h"

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

    GAMESTATE__COUNT
};

typedef struct
{
    int is_game_running;
    float time;
    int gamestate;
    float timer;
    Vec3i background_color;

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
    Vec2i curr_ally_target_1_tilemap_pos;
    Vec2i curr_ally_target_2_tilemap_pos;
    Animation* curr_skill_animation;

    Object* hero_object;
    int hero_ap;
    int hero_item_number[ITEM__COUNT];
    int hero_body_part_augmentation[BODY_PART__COUNT];
    int hero_curr_item;

    Object* minibot_object;
    int was_minibot_launched;

    List* curr_ally_draw_below_texture_list;
    List* curr_ally_draw_below_tilemap_pos_list;
    List* curr_ally_draw_above_texture_list;
    List* curr_ally_draw_above_tilemap_pos_list;
    List* curr_ally_draw_effect_texture_list;
    List* curr_ally_draw_effect_tilemap_pos_list;

} State;

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void update_state (Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);

void add_room(State* state, Room* room);
Room* get_room(State* state, char* name);
void set_curr_room(State* state, Room* room);

void add_passage(State* state, Passage* passage);
Passage* get_passage(State* state, char* from_room_name, Vec2i from_tilemap_pos);

void change_gamestate(State* state, int new_gamestate);
void change_background_color(State* state, Vec3i new_background_color);

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite);
void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite);

void draw_texture_list(
    Renderer* renderer,
    State* state,
    List* texture_list,
    List* tilemap_pos_list,
    Vec3i color,
    float transparency
    );

void add_animation_to_animation_list(State* state, Animation* animation, Textures *textures, Sounds *sounds, Musics *musics, Colors *colors);

void start_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void update_animation(State* state, Animation* animation, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void end_animation(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);

void remove_all_actions_from_action_sequence(Action* action_sequence);
void execute_action_sequence(State* state, Action* action_sequence, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void print_action(Action* action, int depth);

void start_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void update_action(State* state, Action* sequence, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);
void end_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors);

void floor_on_move_start(State* state, Action* sequence, Action* action, int floor);
void floor_on_move_end(State* state, Action* sequence, Action* action, int floor);
void floor_on_drop(State* state, Action* sequence, Action* action, int floor);
void floor_on_stomp(State* state, Action* sequence, int floor, Vec2i tilemap_pos);
void floor_on_manipulation(State* state, Action* sequence, int floor, Vec2i tilemap_pos);
Animation* floor_on_manipulation_get_animation(State* state, int floor, Vec2i tilemap_pos, Textures* textures);
void floor_on_pick_item(State* state, Action* sequence, int floor, Vec2i tilemap_pos);
void floor_on_put_item(State* state, Action* sequence, int floor, Vec2i tilemap_pos, int item_type);

void object_on_crashing(State* state, Action* sequence, Action* action, Object* object);
void object_on_crashed(State* state, Action* sequence, Action* action, Object* object);
void object_on_death(State* state, Action* sequence, Action* action, Object* object);
void object_on_drop(State* state, Action* sequence, Action* action, Object* object);
void object_on_melt(State* state, Action* sequence, Action* action, Object* object);
void object_on_break(State* state, Action* sequence, Action* action, Object* object);
void object_on_shake(State* state, Action* sequence, Action* action, Object* object);
void object_on_stomp(State* state, Action* sequence, Object* object, Vec2i tilemap_pos);
void object_on_manipulate(State* state, Action* sequence, Object* object, Vec2i tilemap_pos);
Animation* object_on_manipulate_get_animation(State* state, Object* object, Vec2i tilemap_pos, Textures* textures);
void object_on_pick_item(State* state, Action* sequence, Object* object, Vec2i tilemap_pos);
void object_on_put_item(State* state, Action* sequence, Object* object, Vec2i tilemap_pos, int item_type);

void skill_on_use(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    Textures* textures,
    Colors* colors
    );
void skill_get_possible_target_1_pos(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    List* target_1_pos_list
    );
void skill_get_possible_target_2_pos(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    List* target_2_pos_list
    );
void skill_get_actions(
    State* state,
    Action* action_sequence,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos
    );
void skill_get_draw_below(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    List* texture_list,
    List* tilemap_pos_list,
    Textures* textures,
    Colors* colors
    );
void skill_get_draw_above(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    List* texture_list,
    List* tilemap_pos_list,
    Textures* textures,
    Colors* colors
    );
void skill_get_draw_effect(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    List* texture_list,
    List* tilemap_pos_list,
    Textures* textures,
    Colors* colors
    );
Animation* skill_get_animation(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    Textures* textures,
    Colors* colors
    );

void object_enemy_prepare_move(State* state, Enemy* enemy);
void object_enemy_prepare_attack(State* state, Enemy* enemy);

char* get_gamestate_name(int gamestate);

void hero_add_augmentation(State* state, int augmentation);
int hero_has_augmentation(State* state, int augmentation);

void get_object_skills(State* state, Object* object, List* skill_list);

Enemy* get_enemy_of_object(State* state, Object* object);
Ally* get_ally_of_object(State* state, Object* object);

void find_path(State* state, Vec2i start_tilemap_pos, Vec2i end_tilemap_pos, List* path, int is_floating, int is_flying);

void update_enemy_list(State* state);
void update_all_enemy_order(State* state);
void update_enemy_attack_dir4(State* state, Enemy* enemy);
void update_enemy_attack_targets(State* state, Enemy* enemy);
void update_enemy_draw(State* state, Enemy* enemy, Textures* textures, Colors* colors);

void update_ally_list(State* state);
void update_ally_skill_list(State* state, Ally* ally);
void restore_ally_action_points(State* state, Ally* ally);
void update_curr_ally_draw(State* state, Textures* textures, Colors* colors);
void clear_curr_ally_draw(State* state, Textures* textures, Colors* colors);

void remove_all_object_to_be_removed(State* state);

#endif
