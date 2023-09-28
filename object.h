#ifndef OBJECT_H
#define OBJECT_H

#include "common.h"
#include "vec.h"
#include "textures.h"

enum OBJECT_TYPE
{
    OBJECT_TYPE__PILLAR,
    OBJECT_TYPE__GOAT,
    OBJECT_TYPE__SPIDER,

    OBJECT_TYPE__COUNT
};

typedef struct _Object Object;

struct _Object
{
    Object* next;
    int type;
    vec2i tilemap_pos;

};

Object* new_object(int type);
void destroy_object(Object* object);

Texture* get_texture_from_object_type(int type, Textures* textures);

#endif