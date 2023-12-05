#ifndef OBJECT_H
#define OBJECT_H

#include "../inc/common.h"
#include "../inc/vec.h"
#include "../inc/textures.h"

enum OBJECT_TYPE
{
    OBJECT_TYPE__NONE,

    OBJECT_TYPE__WALL,
    OBJECT_TYPE__DOOR,
    OBJECT_TYPE__STALACTITE,
    OBJECT_TYPE__STALACTITE_FALLEN,
    OBJECT_TYPE__STALAGMITE,
    OBJECT_TYPE__STALAGNATE,
    OBJECT_TYPE__PILLAR,
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
} Object_Wall;

typedef struct
{
    int dir4;

} Object_Door;

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
    struct _Action* action_sequence;
    int performed_attack;
    int order_number;
    int attack_dir4;

} Object_Enemy;

struct _Object
{
    int is_visible;
    int is_dead;
    int type;
    Vec2i tilemap_pos;

    Object_Enemy enemy;

    union
    {
        Object_Wall             wall;
        Object_Door             door;
        Object_Stalactite       stalactite;
        Object_StalactiteFallen stalactite_fallen;
        Object_Stalagmite       stalagmite;
        Object_Stalagnate       stalagnate;
        Object_Pillar           pillar;
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
int is_object_enemy(Object* object);
int is_object_interactable(Object* object);
int is_object_movable(Object* object);

char* get_name_from_object_type(int object_type);
Texture* get_texture_1_from_object(Object* object, Textures* textures);
Texture* get_texture_2_from_object(Object* object, Textures* textures);
Texture* get_texture_1_outline_from_object(Object* object, Textures* textures);
Texture* get_texture_2_outline_from_object(Object* object, Textures* textures);
#endif
