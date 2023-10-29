#include "../inc/object.h"

#include "../inc/action.h"

Object* new_object(int type)
{
    Object* object = malloc(sizeof(*object));

    object->is_visible = 1;
    object->is_dead = 0;
    object->type = type;
    object->tilemap_pos = vec2i(0,0);

    object->enemy_action_sequence = new_action_sequence();
    object->enemy_performed_attack = 0;
    object->enemy_order_number = 0;
    object->enemy_attack_dir4 = DIR4__RIGHT;

    return object;
}

void destroy_object(Object* object)
{
    free(object);
}

int is_object_flying(int object_type)
{
    int is = 0;

    switch(object_type)
    {
        case OBJECT_TYPE__NONE: is = 0; break;
        case OBJECT_TYPE__PILLAR: is = 0; break;
        case OBJECT_TYPE__BARREL: is = 0; break;
        case OBJECT_TYPE__SPRING: is = 0; break;
        case OBJECT_TYPE__WEIGHT: is = 0; break;
        case OBJECT_TYPE__HERO: is = 0; break;
        case OBJECT_TYPE__GOAT: is = 0; break;
        case OBJECT_TYPE__SPIDER: is = 0; break;
        case OBJECT_TYPE__BULL: is = 0; break;
        case OBJECT_TYPE__FLY: is = 1; break;
        case OBJECT_TYPE__CHAMELEON: is = 0; break;
        default: break;
    }

    return is;
}

int is_object_enemy(int object_type)
{
    int is = 0;

    switch(object_type)
    {
        case OBJECT_TYPE__NONE: is = 0; break;
        case OBJECT_TYPE__PILLAR: is = 0; break;
        case OBJECT_TYPE__BARREL: is = 0; break;
        case OBJECT_TYPE__SPRING: is = 0; break;
        case OBJECT_TYPE__WEIGHT: is = 0; break;
        case OBJECT_TYPE__HERO: is = 0; break;
        case OBJECT_TYPE__GOAT: is = 1; break;
        case OBJECT_TYPE__SPIDER: is = 1; break;
        case OBJECT_TYPE__BULL: is = 1; break;
        case OBJECT_TYPE__FLY: is = 1; break;
        case OBJECT_TYPE__CHAMELEON: is = 1; break;
        default: break;
    }

    return is;
}

char* get_name_from_object_type(int object_type)
{
    char* name = "";

    switch(object_type)
    {
        case OBJECT_TYPE__NONE: name = "none"; break;
        case OBJECT_TYPE__PILLAR: name = "pillar"; break;
        case OBJECT_TYPE__PILLAR_SPIKES: name = "pillar_spikes"; break;
        case OBJECT_TYPE__BARREL: name = "barrel"; break;
        case OBJECT_TYPE__SPRING: name = "spring"; break;
        case OBJECT_TYPE__WEIGHT: name = "weight"; break;
        case OBJECT_TYPE__HERO: name = "hero"; break;
        case OBJECT_TYPE__GOAT: name = "goat"; break;
        case OBJECT_TYPE__SPIDER: name = "spider"; break;
        case OBJECT_TYPE__BULL: name = "bull"; break;
        case OBJECT_TYPE__FLY: name = "fly"; break;
        case OBJECT_TYPE__CHAMELEON: name = "chameleon"; break;
        default: break;
    }

    return name;
}

Texture* get_texture_from_object_type(int object_type, Textures* textures)
{
    Texture* texture = 0;

    switch(object_type)
    {
        case OBJECT_TYPE__NONE: texture = 0; break;
        case OBJECT_TYPE__PILLAR: texture = textures->object.pillar; break;
        case OBJECT_TYPE__PILLAR_SPIKES: texture = textures->object.pillar_spikes; break;
        case OBJECT_TYPE__BARREL: texture = textures->object.barrel; break;
        case OBJECT_TYPE__SPRING: texture = textures->object.spring; break;
        case OBJECT_TYPE__WEIGHT: texture = textures->object.weight; break;
        case OBJECT_TYPE__HERO: texture = textures->object.hero; break;
        case OBJECT_TYPE__GOAT: texture = textures->object.goat; break;
        case OBJECT_TYPE__SPIDER: texture = textures->object.spider; break;
        case OBJECT_TYPE__BULL: texture = textures->object.bull; break;
        case OBJECT_TYPE__FLY: texture = textures->object.fly; break;
        case OBJECT_TYPE__CHAMELEON: texture = textures->object.chameleon; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_outline_from_object_type(int object_type, Textures* textures)
{
    Texture* texture = 0;

    switch(object_type)
    {
        case OBJECT_TYPE__NONE: texture = 0; break;
        case OBJECT_TYPE__PILLAR: texture = textures->object.pillar_outline; break;
        case OBJECT_TYPE__PILLAR_SPIKES: texture = textures->object.pillar_spikes_outline; break;
        case OBJECT_TYPE__BARREL: texture = textures->object.barrel_outline; break;
        case OBJECT_TYPE__SPRING: texture = textures->object.spring_outline; break;
        case OBJECT_TYPE__WEIGHT: texture = textures->object.weight_outline; break;
        case OBJECT_TYPE__HERO: texture = textures->object.hero_outline; break;
        case OBJECT_TYPE__GOAT: texture = textures->object.goat_outline; break;
        case OBJECT_TYPE__SPIDER: texture = textures->object.spider_outline; break;
        case OBJECT_TYPE__BULL: texture = textures->object.bull_outline; break;
        case OBJECT_TYPE__FLY: texture = textures->object.fly_outline; break;
        case OBJECT_TYPE__CHAMELEON: texture = textures->object.chameleon_outline; break;
        default: break;
    }

    return texture;
}
