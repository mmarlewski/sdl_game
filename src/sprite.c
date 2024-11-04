#include "../inc/sprite.h"

Sprite* new_sprite(Texture* texture)
{
    Sprite* sprite = calloc(sizeof(*sprite), 1);

    sprite->texture = texture;
    sprite->gamemap_pos = vec3f(0.0f, 0.0f, 0.0f);
    sprite->transparency = 1.0f;

    return sprite;
}

void destroy_sprite(Sprite* sprite)
{
    free(sprite);
}
