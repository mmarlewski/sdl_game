#ifndef OBJECT_H
#define OBJECT_H

#include "../inc/common.h"
#include "../inc/vec.h"
#include "../inc/textures.h"

enum OBJECT_TYPE
{
    OBJECT__NONE,

    OBJECT__WALL_ROCK,
    OBJECT__WALL_STONE,
    OBJECT__WALL_METAL,
    OBJECT__WALL_GOLD,
    OBJECT__WALL_MARBLE,
    OBJECT__WALL_OBSIDIAN,

    OBJECT__EXIT_ROCK_UP,
    OBJECT__EXIT_ROCK_RIGHT,
    OBJECT__EXIT_ROCK_DOWN,
    OBJECT__EXIT_ROCK_LEFT,
    OBJECT__EXIT_ROCK_BLOCKED_UP,
    OBJECT__EXIT_ROCK_BLOCKED_RIGHT,
    OBJECT__EXIT_ROCK_BLOCKED_DOWN,
    OBJECT__EXIT_ROCK_BLOCKED_LEFT,

    OBJECT__EXIT_STONE_UP,
    OBJECT__EXIT_STONE_RIGHT,
    OBJECT__EXIT_STONE_DOWN,
    OBJECT__EXIT_STONE_LEFT,
    OBJECT__EXIT_STONE_BLOCKED_UP,
    OBJECT__EXIT_STONE_BLOCKED_RIGHT,
    OBJECT__EXIT_STONE_BLOCKED_DOWN,
    OBJECT__EXIT_STONE_BLOCKED_LEFT,
    OBJECT__EXIT_STONE_POWERED_UP,
    OBJECT__EXIT_STONE_POWERED_RIGHT,
    OBJECT__EXIT_STONE_POWERED_DOWN,
    OBJECT__EXIT_STONE_POWERED_LEFT,
    OBJECT__EXIT_STONE_UNPOWERED_UP,
    OBJECT__EXIT_STONE_UNPOWERED_RIGHT,
    OBJECT__EXIT_STONE_UNPOWERED_DOWN,
    OBJECT__EXIT_STONE_UNPOWERED_LEFT,

    OBJECT__EXIT_METAL_UP,
    OBJECT__EXIT_METAL_RIGHT,
    OBJECT__EXIT_METAL_DOWN,
    OBJECT__EXIT_METAL_LEFT,
    OBJECT__EXIT_METAL_BLOCKED_UP,
    OBJECT__EXIT_METAL_BLOCKED_RIGHT,
    OBJECT__EXIT_METAL_BLOCKED_DOWN,
    OBJECT__EXIT_METAL_BLOCKED_LEFT,
    OBJECT__EXIT_METAL_ON_UP,
    OBJECT__EXIT_METAL_ON_RIGHT,
    OBJECT__EXIT_METAL_ON_DOWN,
    OBJECT__EXIT_METAL_ON_LEFT,
    OBJECT__EXIT_METAL_OFF_UP,
    OBJECT__EXIT_METAL_OFF_RIGHT,
    OBJECT__EXIT_METAL_OFF_DOWN,
    OBJECT__EXIT_METAL_OFF_LEFT,

    OBJECT__EXIT_GOLD_LOCKED_UP,
    OBJECT__EXIT_GOLD_LOCKED_RIGHT,
    OBJECT__EXIT_GOLD_LOCKED_DOWN,
    OBJECT__EXIT_GOLD_LOCKED_LEFT,
    OBJECT__EXIT_GOLD_UNLOCKED_UP,
    OBJECT__EXIT_GOLD_UNLOCKED_RIGHT,
    OBJECT__EXIT_GOLD_UNLOCKED_DOWN,
    OBJECT__EXIT_GOLD_UNLOCKED_LEFT,

    OBJECT__EXIT_MARBLE_UP,
    OBJECT__EXIT_MARBLE_RIGHT,
    OBJECT__EXIT_MARBLE_DOWN,
    OBJECT__EXIT_MARBLE_LEFT,

    OBJECT__EXIT_OBSIDIAN_UP,
    OBJECT__EXIT_OBSIDIAN_RIGHT,
    OBJECT__EXIT_OBSIDIAN_DOWN,
    OBJECT__EXIT_OBSIDIAN_LEFT,

    OBJECT__PILLAR,
    OBJECT__SARCOPHAGUS,
    OBJECT__MENHIR,

    OBJECT__PIPE,

    OBJECT__STALACTITE,
    OBJECT__STALACTITE_FALLEN,
    OBJECT__STALACTITE_FALLEN_ITEM,

    OBJECT__STALAGMITE,

    OBJECT__STALAGNATE,

    OBJECT__COVER_ROCK,
    OBJECT__COVER_METAL,
    OBJECT__COVER_GLASS,

    OBJECT__CRATE_GEMSTONE,
    OBJECT__CRATE_GEMSTONE_ITEM,

    OBJECT__CRATE_CELL,
    OBJECT__CRATE_CELL_ITEM,

    OBJECT__CRATE_DYNAMITE,
    OBJECT__CRATE_DYNAMITE_ITEM,

    OBJECT__ROCK,
    OBJECT__ROCK_DAMAGED,
    OBJECT__ROCK_DAMAGED_ITEM,

    OBJECT__SAFE,
    OBJECT__SAFE_DAMAGED,
    OBJECT__SAFE_DAMAGED_ITEM,

    OBJECT__DISPLAY,
    OBJECT__DISPLAY_DAMAGED,
    OBJECT__DISPLAY_DAMAGED_ITEM,

    OBJECT__VENDING_CELL,
    OBJECT__VENDING_CELL_ITEM,
    OBJECT__VENDING_CELL_DAMAGED,
    OBJECT__VENDING_CELL_DAMAGED_ITEM,

    OBJECT__VENDING_DYNAMITE,
    OBJECT__VENDING_DYNAMITE_ITEM,
    OBJECT__VENDING_DYNAMITE_DAMAGED,
    OBJECT__VENDING_DYNAMITE_DAMAGED_ITEM,

    OBJECT__BARREL,

    OBJECT__COLUMN,

    OBJECT__PISTON,
    OBJECT__PISTON_CELL,
    OBJECT__PISTON_DYNAMITE,
    OBJECT__PISTON_BARREL,

    OBJECT__OBSTACLE,

    OBJECT__BALL,
    OBJECT__BALL_SPIKES,
    OBJECT__GLASS_BALL,

    OBJECT__THRONE,

    OBJECT__SIGN_MOLE_WARNING,

    OBJECT__GOLEM_UNPOWERED,
    OBJECT__GOLEM_HALF_POWERED,
    OBJECT__GOLEM_POWERED,

    OBJECT__HERO,
    OBJECT__HERO_FLOATING,
    OBJECT__HERO_FLYING,

    OBJECT__MINIBOT_ALLY,
    OBJECT__MINIBOT_ALLY_CELL,
    OBJECT__MINIBOT_ALLY_DYNAMITE,
    OBJECT__MINIBOT_ALLY_GEMSTONE,

    OBJECT__GOAT,
    OBJECT__SPIDER,
    OBJECT__BULL,
    OBJECT__FLY,
    OBJECT__CHAMELEON,
    OBJECT__SQUID,
    OBJECT__MOLE,
    OBJECT__MIMIC,
    OBJECT__SHARK,
    OBJECT__SHARK_FIN,

    OBJECT__MINIBOT_ENEMY,
    OBJECT__MINIBOT_ENEMY_CELL,
    OBJECT__MINIBOT_ENEMY_DYNAMITE,
    OBJECT__MINIBOT_ENEMY_GEMSTONE,

    OBJECT__TURRET_LASER_GROUNDED,
    OBJECT__TURRET_LASER_STANDING,
    OBJECT__TURRET_LASER_UNDEPLOYED,
    OBJECT__TURRET_LASER_DEPLOYED,

    OBJECT__TURRET_BOMB_GROUNDED,
    OBJECT__TURRET_BOMB_STANDING,
    OBJECT__TURRET_BOMB_UNDEPLOYED,
    OBJECT__TURRET_BOMB_DEPLOYED,

    OBJECT__TURRET_PROJECTILE_GROUNDED,
    OBJECT__TURRET_PROJECTILE_STANDING,
    OBJECT__TURRET_PROJECTILE_UNDEPLOYED,
    OBJECT__TURRET_PROJECTILE_DEPLOYED,

    OBJECT__SQUIRREL_EXIT_OBSIDIAN_DOWN,

    OBJECT__ENVIRONMENT_FALLING_STALACTITE,
    OBJECT__ENVIRONMENT_EMERGE_WATER,
    OBJECT__ENVIRONMENT_EMERGE_PIT,
    OBJECT__ENVIRONMENT_EMERGE_BURROW,
    OBJECT__ENVIRONMENT_EMERGE_PIPE,
    OBJECT__ENVIRONMENT_COLLAPSE_BURROW,
    OBJECT__ENVIRONMENT_CONV_BELT,

    OBJECT__STAIRS_ABOVE_STONE_POWERED,
    OBJECT__STAIRS_ABOVE_STONE,
    OBJECT__STAIRS_ABOVE_ROCK,
    OBJECT__STAIRS_ABOVE_METAL_ON,
    OBJECT__STAIRS_ABOVE_METAL,

    OBJECT__STATION_FIST_HAND,
    OBJECT__STATION_HOOK_HAND,
    OBJECT__STATION_CHAIN_HAND,
    OBJECT__STATION_SCISSOR_HAND,
    OBJECT__STATION_SPRING_LEG,
    OBJECT__STATION_STRIDER_LEG,
    OBJECT__STATION_TRACK_LEG,
    OBJECT__STATION_BOOT_LEG,
    OBJECT__STATION_MINIBOT_TORSO,
    OBJECT__STATION_WINGS_TORSO,
    OBJECT__STATION_MANIPULATION_HEAD,
    OBJECT__STATION_TELEPORTATION_HEAD,
    OBJECT__STATION_TAKEN,

    OBJECT__SECRET_1,
    OBJECT__SECRET_2,
    OBJECT__SECRET_3,
    OBJECT__SECRET_4,
    OBJECT__SECRET_TAKEN,

    OBJECT__LEVER_METAL_OFF,
    OBJECT__LEVER_METAL_ON,
    OBJECT__LEVER_STONE_UNPOWERED,
    OBJECT__LEVER_STONE_POWERED,

    OBJECT__EXT_WALL_SOURCE_ON_HORIZONTAL,
    OBJECT__EXT_WALL_SOURCE_OFF_HORIZONTAL,
    OBJECT__EXT_WALL_PART_HORIZONTAL,
    OBJECT__EXT_WALL_SOURCE_ON_VERTICAL,
    OBJECT__EXT_WALL_SOURCE_OFF_VERTICAL,
    OBJECT__EXT_WALL_PART_VERTICAL,

    OBJECT__HARPOON_GUN_UP,
    OBJECT__HARPOON_GUN_RIGHT,
    OBJECT__HARPOON_GUN_DOWN,
    OBJECT__HARPOON_GUN_LEFT,

    OBJECT__COUNT
};

struct _Action;

typedef struct
{
    int is_to_be_removed;
    int is_visible;
    int type;
    Vec2i tilemap_pos;
    int attack_dir4;
    int action_points;

} Object;

typedef struct
{
    Object* object;
    struct _Action* action_sequence;
    Vec2i target_1_tilemap_pos;
    Vec2i target_2_tilemap_pos;
    int skill;
    int performed_attack;
    int order_number;

    List* draw_below_texture_list;
    List* draw_below_tilemap_pos_list;
    List* draw_above_texture_list;
    List* draw_above_tilemap_pos_list;
    List* draw_effect_texture_list;
    List* draw_effect_tilemap_pos_list;

} Enemy;

typedef struct
{
    Object* object;
    List* skill_list;

} Ally;

Object* new_object(int type);
void destroy_object(Object* object);

Enemy* new_enemy(Object* object);
void destroy_enemy(Enemy* enemy);

Ally* new_ally(Object* object);
void destroy_ally(Ally* ally);

int is_object_wall(Object* object);
int is_object_enemy(Object* object);
int is_object_ally(Object* object);
int is_object_environment(Object* object);
int is_object_exit(Object* object);
int is_object_pull_towards(Object* object);
int is_object_throw_over(Object* object);
int is_object_station(Object* object);
int is_object_secret(Object* object);
int get_station_augmentation(Object* object);
int is_object_floating(Object* object);
int is_object_flying(Object* object);
int is_object_manipulatable(Object* object);
int is_object_movable(Object* object);
int is_object_meltable(Object* object);
int is_object_breakable(Object* object);
int is_object_fragile(Object* object);
int is_object_stomp(Object* object);
int is_object_stone(Object* object);
int is_object_metal(Object* object);
int is_object_glass(Object* object);

int get_object_item_type(Object* object);
int get_object_item_count(Object* object);
int is_object_put_item(Object* object);

char* get_in_game_name_from_object_type(int object_type);
char* get_debug_name_from_object_type(int object_type);
Texture* get_texture_1_from_object(Object* object, Textures* textures);
Texture* get_texture_2_from_object(Object* object, Textures* textures);
Texture* get_texture_1_outline_from_object(Object* object, Textures* textures);
Texture* get_texture_2_outline_from_object(Object* object, Textures* textures);
Texture* get_hud_texture_from_object(Object* object, Textures* textures);

#endif
