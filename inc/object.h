#ifndef OBJECT_H
#define OBJECT_H

#include "../inc/common.h"
#include "../inc/vec.h"
#include "../inc/textures.h"

enum OBJECT_TYPE
{
    OBJECT_TYPE__NONE,

    OBJECT_TYPE__WALL_ROCK,

    OBJECT_TYPE__WALL_STONE,

    OBJECT_TYPE__WALL_METAL,

    OBJECT_TYPE__EXIT_ROCK_UP,
    OBJECT_TYPE__EXIT_ROCK_RIGHT,
    OBJECT_TYPE__EXIT_ROCK_DOWN,
    OBJECT_TYPE__EXIT_ROCK_LEFT,
    OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP,
    OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT,
    OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN,
    OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT,

    OBJECT_TYPE__EXIT_STONE_UP,
    OBJECT_TYPE__EXIT_STONE_RIGHT,
    OBJECT_TYPE__EXIT_STONE_DOWN,
    OBJECT_TYPE__EXIT_STONE_LEFT,
    OBJECT_TYPE__EXIT_STONE_BLOCKED_UP,
    OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT,
    OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN,
    OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT,

    OBJECT_TYPE__EXIT_METAL_UP,
    OBJECT_TYPE__EXIT_METAL_RIGHT,
    OBJECT_TYPE__EXIT_METAL_DOWN,
    OBJECT_TYPE__EXIT_METAL_LEFT,
    OBJECT_TYPE__EXIT_METAL_BLOCKED_UP,
    OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT,
    OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN,
    OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT,

    OBJECT_TYPE__PILLAR,

    OBJECT_TYPE__PIPE,

    OBJECT_TYPE__STALACTITE,
    OBJECT_TYPE__STALACTITE_FALLEN,
    OBJECT_TYPE__STALACTITE_FALLEN_ITEM,

    OBJECT_TYPE__STALAGMITE,

    OBJECT_TYPE__STALAGNATE,

    OBJECT_TYPE__COVER_ROCK,
    OBJECT_TYPE__COVER_METAL,
    OBJECT_TYPE__COVER_GLASS,

    OBJECT_TYPE__CRATE_GEMSTONE,
    OBJECT_TYPE__CRATE_GEMSTONE_ITEM,

    OBJECT_TYPE__CRATE_CELL,
    OBJECT_TYPE__CRATE_CELL_ITEM,

    OBJECT_TYPE__CRATE_DYNAMITE,
    OBJECT_TYPE__CRATE_DYNAMITE_ITEM,

    OBJECT_TYPE__ROCK,
    OBJECT_TYPE__ROCK_DAMAGED,
    OBJECT_TYPE__ROCK_DAMAGED_ITEM,

    OBJECT_TYPE__SAFE,
    OBJECT_TYPE__SAFE_DAMAGED,
    OBJECT_TYPE__SAFE_DAMAGED_ITEM,

    OBJECT_TYPE__DISPLAY,
    OBJECT_TYPE__DISPLAY_DAMAGED,
    OBJECT_TYPE__DISPLAY_DAMAGED_ITEM,

    OBJECT_TYPE__VENDING_CELL,
    OBJECT_TYPE__VENDING_CELL_ITEM,
    OBJECT_TYPE__VENDING_CELL_DAMAGED,
    OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM,

    OBJECT_TYPE__VENDING_DYNAMITE,
    OBJECT_TYPE__VENDING_DYNAMITE_ITEM,
    OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED,
    OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM,

    OBJECT_TYPE__BARREL,

    OBJECT_TYPE__WEIGHT,

    OBJECT_TYPE__PISTON,

    OBJECT_TYPE__BALL,
    OBJECT_TYPE__BALL_SPIKES,

    OBJECT_TYPE__HERO,
    OBJECT_TYPE__GOAT,
    OBJECT_TYPE__SPIDER,
    OBJECT_TYPE__BULL,
    OBJECT_TYPE__FLY,
    OBJECT_TYPE__CHAMELEON,

    OBJECT_TYPE_TURRET_GROUNDED,
    OBJECT_TYPE_TURRET_STANDING,
    OBJECT_TYPE_TURRET_UNDEPLOYED,
    OBJECT_TYPE_TURRET_DEPLOYED,

    OBJECT_TYPE__COUNT
};

struct _Action;

typedef struct _Object Object;

typedef struct
{
    int item_1;
    int item_2;
    int item_3;

} Object_Container;

typedef struct
{
    Vec2i to_tilemap_pos;

} Object_Exit;

typedef struct
{
    struct _Action* action_sequence;
    int performed_attack;
    int order_number;
    int attack_dir4;

} Object_Enemy;

struct _Object
{
    int is_dead;
    int is_visible;
    int type;
    Vec2i tilemap_pos;

    int is_container;
    Object_Container container;
    int is_exit;
    Object_Exit exit;
    int is_enemy;
    Object_Enemy enemy;
};

Object* new_object(int type);
void destroy_object(Object* object);

int is_object_flying(Object* object);
int is_object_interactable(Object* object);
int is_object_movable(Object* object);

char* get_name_from_object_type(int object_type);
Texture* get_texture_1_from_object(Object* object, Textures* textures);
Texture* get_texture_2_from_object(Object* object, Textures* textures);
Texture* get_texture_1_outline_from_object(Object* object, Textures* textures);
Texture* get_texture_2_outline_from_object(Object* object, Textures* textures);
#endif
