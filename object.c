#include "object.h"

Object* new_object(int type)
{
    Object* object = malloc(sizeof(*object));

    object->next = 0;
    object->is_visible = 1;
    object->type = type;
    object->tilemap_pos = make_vec2i(0,0);

    return object;
}

void destroy_object(Object* object)
{
    free(object);
}

Texture* get_texture_from_object_type(int type, Textures* textures)
{
    Texture* texture = 0;

    switch(type)
    {
        case OBJECT_TYPE__PILLAR: texture = textures->object.pillar; break;
        case OBJECT_TYPE__HERO: texture = textures->object.hero; break;
        case OBJECT_TYPE__GOAT: texture = textures->object.goat; break;
        case OBJECT_TYPE__SPIDER: texture = textures->object.spider; break;
        default: break;
    }

    return texture;
}