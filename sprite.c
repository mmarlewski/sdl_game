#include "sprite.h"

Sprite* new_sprite(Texture* texture)
{
    Sprite* sprite = malloc(sizeof(*sprite));

    sprite->next = 0;
    sprite->texture = texture;
    sprite->gamemap_pos = make_vec2f(0.0f,0.0f);

    return sprite;
}

void destroy_sprite(Sprite* sprite)
{
    free(sprite);
}