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
    OBJECT_TYPE__EXIT_ROCK,
    OBJECT_TYPE__EXIT_STONE,
    OBJECT_TYPE__EXIT_METAL,
    OBJECT_TYPE__STALACTITE,
    OBJECT_TYPE__STALACTITE_FALLEN,
    OBJECT_TYPE__STALAGMITE,
    OBJECT_TYPE__STALAGNATE,
    OBJECT_TYPE__PILLAR,
    OBJECT_TYPE__COVER_ROCK,
    OBJECT_TYPE__COVER_METAL,
    OBJECT_TYPE__COVER_GLASS,
    OBJECT_TYPE__ROCK,
    OBJECT_TYPE__ROCK_DAMAGED,
    OBJECT_TYPE__SAFE,
    OBJECT_TYPE__SAFE_DAMAGED,
    OBJECT_TYPE__DISPLAY,
    OBJECT_TYPE__DISPLAY_DAMAGED,
    OBJECT_TYPE__VENDING,
    OBJECT_TYPE__VENDING_DAMAGED,
    OBJECT_TYPE__BARREL,
    OBJECT_TYPE__SPRING,
    OBJECT_TYPE__WEIGHT,
    OBJECT_TYPE__HERO,
    OBJECT_TYPE__GOAT,
    OBJECT_TYPE__SPIDER,
    OBJECT_TYPE__BULL,
    OBJECT_TYPE__FLY,
    OBJECT_TYPE__CHAMELEON,

    OBJECT_TYPE__COUNT
};

struct _Action;

typedef struct _Object Object;

typedef struct
{
} Object_WallRock;

typedef struct
{
} Object_WallStone;

typedef struct
{
} Object_WallMetal;

typedef struct
{
    int is_blocked;
    int dir4;

} Object_ExitRock;

typedef struct
{
    int is_blocked;
    int dir4;

} Object_ExitStone;

typedef struct
{
    int is_blocked;
    int dir4;

} Object_ExitMetal;

typedef struct
{
} Object_Stalactite;

typedef struct
{
} Object_StalactiteFallen;

typedef struct
{
} Object_Stalagmite;

typedef struct
{
} Object_Stalagnate;

typedef struct
{
    int spikes_on;

} Object_Pillar;

typedef struct
{
} Object_CoverRock;

typedef struct
{
} Object_CoverMetal;

typedef struct
{
} Object_CoverGlass;

typedef struct
{
} Object_Rock;

typedef struct
{
} Object_RockDamaged;

typedef struct
{
} Object_Safe;

typedef struct
{
} Object_SafeDamaged;

typedef struct
{
} Object_Display;

typedef struct
{
} Object_DisplayDamaged;

typedef struct
{
} Object_Vending;

typedef struct
{
} Object_VendingDamaged;

typedef struct
{
} Object_Barrel;

typedef struct
{
} Object_Spring;

typedef struct
{
} Object_Weight;

typedef struct
{
} Object_Hero;

typedef struct
{
} Object_Goat;

typedef struct
{
} Object_Spider;

typedef struct
{
} Object_Bull;

typedef struct
{
} Object_Fly;

typedef struct
{
} Object_Chameleon;

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

    int is_exit;
    Object_Exit exit;
    int is_enemy;
    Object_Enemy enemy;

    union
    {
        Object_WallRock         wall_rock;
        Object_WallStone        wall_stone;
        Object_WallMetal        wall_metal;
        Object_ExitRock         exit_rock;
        Object_ExitStone        exit_stone;
        Object_ExitMetal        exit_metal;
        Object_Stalactite       stalactite;
        Object_StalactiteFallen stalactite_fallen;
        Object_Stalagmite       stalagmite;
        Object_Stalagnate       stalagnate;
        Object_Pillar           pillar;
        Object_CoverRock        cover_rock;
        Object_CoverMetal       cover_metal;
        Object_CoverGlass       cover_glass;
        Object_Rock             rock;
        Object_RockDamaged      rock_damaged;
        Object_Safe             safe;
        Object_SafeDamaged      safe_damaged;
        Object_Display          display;
        Object_DisplayDamaged   display_damaged;
        Object_Vending          vending;
        Object_VendingDamaged   vending_damaged;
        Object_Barrel           barrel;
        Object_Spring           spring;
        Object_Weight           weight;
        Object_Hero             hero;
        Object_Goat             goat;
        Object_Spider           spider;
        Object_Bull             bull;
        Object_Fly              fly;
        Object_Chameleon        chameleon;
    };
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
