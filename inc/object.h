#ifndef OBJECT_H
#define OBJECT_H

#include "../inc/common.h"
#include "../inc/vec.h"
#include "../inc/textures.h"

enum OBJECT_TYPE
{
    OBJECT_TYPE__NONE,

    OBJECT_TYPE__PILLAR,
    OBJECT_TYPE__PILLAR_SPIKES,
    OBJECT_TYPE__BARREL,
    OBJECT_TYPE__SPRING,
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

struct _Object
{
    int is_visible;
    int is_dead;
    int type;
    vec2i tilemap_pos;

    struct _Action* enemy_action_sequence;
};

Object* new_object(int type);
void destroy_object(Object* object);

int is_object_flying(int object_type);
int is_object_enemy(int object_type);

char* get_name_from_object_type(int object_type);
Texture* get_texture_from_object_type(int type, Textures* textures);

#endif
