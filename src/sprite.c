#include "../inc/sprite.h"

Sprite* new_sprite(Texture* texture)
{
    Sprite* sprite = malloc(sizeof(*sprite));

    sprite->texture = texture;
    sprite->gamemap_pos = vec3f(0.0f, 0.0f, 0.0f);

    return sprite;
}

void destroy_sprite(Sprite* sprite)
{
    free(sprite);
}
