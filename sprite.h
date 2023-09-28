#ifndef SPRITE_H
#define SPRITE_H

#include "common.h"
#include "vec.h"

typedef struct _Sprite Sprite;

struct _Sprite
{
    Sprite* next;
    Texture* texture;
    vec2f gamemap_pos;
};

Sprite* new_sprite(Texture* texture);
void destroy_sprite(Sprite* sprite);

#endif