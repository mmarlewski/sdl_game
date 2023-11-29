#include "../inc/object.h"

#include "../inc/action.h"

Object* new_object(int type)
{
    Object* object = malloc(sizeof(*object));

    object->is_visible = 1;
    object->is_dead = 0;
    object->type = type;
    object->tilemap_pos = vec2i(0,0);

    object->enemy.action_sequence = new_action_sequence();
    object->enemy.performed_attack = 0;
    object->enemy.order_number = 0;
    object->enemy.attack_dir4 = DIR4__RIGHT;

    if(type == OBJECT_TYPE__PILLAR)
    {
        object->pillar.spikes_on = 0;
    }
    if(type == OBJECT_TYPE__DOOR)
    {
        object->door.dir4 = DIR4__UP;
    }

    return object;
}

void destroy_object(Object* object)
{
    free(object);
}

int is_object_flying(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: is = 0; break;
        case OBJECT_TYPE__WALL: is = 0; break;
        case OBJECT_TYPE__DOOR: is = 0; break;
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

int is_object_enemy(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: is = 0; break;
        case OBJECT_TYPE__WALL: is = 0; break;
        case OBJECT_TYPE__DOOR: is = 0; break;
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

int is_object_interactable(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: is = 0; break;
        case OBJECT_TYPE__WALL: is = 0; break;
        case OBJECT_TYPE__DOOR: is = 0; break;
        case OBJECT_TYPE__PILLAR: is = 1; break;
        case OBJECT_TYPE__BARREL: is = 1; break;
        case OBJECT_TYPE__SPRING: is = 1; break;
        case OBJECT_TYPE__WEIGHT: is = 0; break;
        case OBJECT_TYPE__HERO: is = 0; break;
        case OBJECT_TYPE__GOAT: is = 0; break;
        case OBJECT_TYPE__SPIDER: is = 0; break;
        case OBJECT_TYPE__BULL: is = 0; break;
        case OBJECT_TYPE__FLY: is = 0; break;
        case OBJECT_TYPE__CHAMELEON: is = 0; break;
        default: break;
    }

    return is;
}

int is_object_movable(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: is = 0; break;
        case OBJECT_TYPE__WALL: is = 0; break;
        case OBJECT_TYPE__DOOR: is = 0; break;
        case OBJECT_TYPE__PILLAR: is = 1; break;
        case OBJECT_TYPE__BARREL: is = 1; break;
        case OBJECT_TYPE__SPRING: is = 1; break;
        case OBJECT_TYPE__WEIGHT: is = 1; break;
        case OBJECT_TYPE__HERO: is = 1; break;
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
        case OBJECT_TYPE__WALL: name = "wall"; break;
        case OBJECT_TYPE__DOOR: name = "door"; break;
        case OBJECT_TYPE__PILLAR: name = "pillar"; break;
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

Texture* get_texture_1_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: texture = 0; break;
        case OBJECT_TYPE__WALL: texture = textures->object.wall; break;
        case OBJECT_TYPE__DOOR:
        {
            switch(object->door.dir4)
            {
                case DIR4__UP: texture = textures->object.door_up; break;
                case DIR4__RIGHT: texture = textures->object.door_right; break;
                case DIR4__DOWN: texture = textures->object.door_down; break;
                case DIR4__LEFT: texture = textures->object.door_left; break;
                break;
            }
        }
        break;
        case OBJECT_TYPE__PILLAR:
        {
            if(object->pillar.spikes_on)
            {
                texture = textures->object.pillar_spikes;
            }
            else
            {
                texture = textures->object.pillar;
            }
        }
        break;
        case OBJECT_TYPE__BARREL: texture = textures->object.barrel; break;
        case OBJECT_TYPE__SPRING: texture = textures->object.spring; break;
        case OBJECT_TYPE__WEIGHT: texture = textures->object.weight; break;
        case OBJECT_TYPE__HERO: texture = textures->object.hero_1; break;
        case OBJECT_TYPE__GOAT: texture = textures->object.goat_1; break;
        case OBJECT_TYPE__SPIDER: texture = textures->object.spider_1; break;
        case OBJECT_TYPE__BULL: texture = textures->object.bull_1; break;
        case OBJECT_TYPE__FLY: texture = textures->object.fly_1; break;
        case OBJECT_TYPE__CHAMELEON: texture = textures->object.chameleon_1; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_2_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: texture = 0; break;
        case OBJECT_TYPE__WALL: texture = textures->object.wall; break;
        case OBJECT_TYPE__DOOR:
        {
            switch(object->door.dir4)
            {
                case DIR4__UP: texture = textures->object.door_up; break;
                case DIR4__RIGHT: texture = textures->object.door_right; break;
                case DIR4__DOWN: texture = textures->object.door_down; break;
                case DIR4__LEFT: texture = textures->object.door_left; break;
                break;
            }
        }
        break;
        case OBJECT_TYPE__PILLAR:
        {
            if(object->pillar.spikes_on)
            {
                texture = textures->object.pillar_spikes;
            }
            else
            {
                texture = textures->object.pillar;
            }
        }
        break;
        case OBJECT_TYPE__BARREL: texture = textures->object.barrel; break;
        case OBJECT_TYPE__SPRING: texture = textures->object.spring; break;
        case OBJECT_TYPE__WEIGHT: texture = textures->object.weight; break;
        case OBJECT_TYPE__HERO: texture = textures->object.hero_2; break;
        case OBJECT_TYPE__GOAT: texture = textures->object.goat_2; break;
        case OBJECT_TYPE__SPIDER: texture = textures->object.spider_2; break;
        case OBJECT_TYPE__BULL: texture = textures->object.bull_2; break;
        case OBJECT_TYPE__FLY: texture = textures->object.fly_2; break;
        case OBJECT_TYPE__CHAMELEON: texture = textures->object.chameleon_2; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_1_outline_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: texture = 0; break;
        case OBJECT_TYPE__WALL: texture = textures->object.wall_outline; break;
        case OBJECT_TYPE__DOOR:
        {
            switch(object->door.dir4)
            {
                case DIR4__UP: texture = textures->object.door_up_outline; break;
                case DIR4__RIGHT: texture = textures->object.door_right_outline; break;
                case DIR4__DOWN: texture = textures->object.door_down_outline; break;
                case DIR4__LEFT: texture = textures->object.door_left_outline; break;
                break;
            }
        }
        break;
        case OBJECT_TYPE__PILLAR:
        {
            if(object->pillar.spikes_on)
            {
                texture = textures->object.pillar_spikes_outline;
            }
            else
            {
                texture = textures->object.pillar_outline;
            }
        }
        break;
        case OBJECT_TYPE__BARREL: texture = textures->object.barrel_outline; break;
        case OBJECT_TYPE__SPRING: texture = textures->object.spring_outline; break;
        case OBJECT_TYPE__WEIGHT: texture = textures->object.weight_outline; break;
        case OBJECT_TYPE__HERO: texture = textures->object.hero_outline_1; break;
        case OBJECT_TYPE__GOAT: texture = textures->object.goat_outline_1; break;
        case OBJECT_TYPE__SPIDER: texture = textures->object.spider_outline_1; break;
        case OBJECT_TYPE__BULL: texture = textures->object.bull_outline_1; break;
        case OBJECT_TYPE__FLY: texture = textures->object.fly_outline_1; break;
        case OBJECT_TYPE__CHAMELEON: texture = textures->object.chameleon_outline_1; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_2_outline_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__NONE: texture = 0; break;
        case OBJECT_TYPE__WALL: texture = textures->object.wall_outline; break;
        case OBJECT_TYPE__DOOR:
        {
            switch(object->door.dir4)
            {
                case DIR4__UP: texture = textures->object.door_up_outline; break;
                case DIR4__RIGHT: texture = textures->object.door_right_outline; break;
                case DIR4__DOWN: texture = textures->object.door_down_outline; break;
                case DIR4__LEFT: texture = textures->object.door_left_outline; break;
                break;
            }
        }
        break;
        case OBJECT_TYPE__PILLAR:
        {
            if(object->pillar.spikes_on)
            {
                texture = textures->object.pillar_spikes_outline;
            }
            else
            {
                texture = textures->object.pillar_outline;
            }
        }
        break;
        case OBJECT_TYPE__BARREL: texture = textures->object.barrel_outline; break;
        case OBJECT_TYPE__SPRING: texture = textures->object.spring_outline; break;
        case OBJECT_TYPE__WEIGHT: texture = textures->object.weight_outline; break;
        case OBJECT_TYPE__HERO: texture = textures->object.hero_outline_2; break;
        case OBJECT_TYPE__GOAT: texture = textures->object.goat_outline_2; break;
        case OBJECT_TYPE__SPIDER: texture = textures->object.spider_outline_2; break;
        case OBJECT_TYPE__BULL: texture = textures->object.bull_outline_2; break;
        case OBJECT_TYPE__FLY: texture = textures->object.fly_outline_2; break;
        case OBJECT_TYPE__CHAMELEON: texture = textures->object.chameleon_outline_2; break;
        default: break;
    }

    return texture;
}
