#include "../inc/object.h"

#include "../inc/action.h"
#include "../inc/skill.h"
#include "../inc/item.h"
#include "../inc/augmentation.h"
#include <stdlib.h>

Object* new_object(int type)
{
    Object* object = malloc(sizeof(*object));

    object->is_visible = 1;
    object->is_dead = 0;
    object->type = type;
    object->tilemap_pos = vec2i(0,0);

    return object;
}

void destroy_object(Object* object)
{
    free(object);
}

Enemy* new_enemy(Object* object)
{
    Enemy* enemy = malloc(sizeof(*enemy));

    enemy->object = object;
    enemy->action_sequence = new_action_sequence();
    enemy->target_1_tilemap_pos = vec2i(0, 0);
    enemy->target_2_tilemap_pos = vec2i(0, 0);
    enemy->skill = SKILL__NONE;
    enemy->attack_dir4 = DIR4__NONE;
    enemy->performed_attack = 0;
    enemy->order_number = 0;

    return enemy;
}

void destroy_enemy(Enemy* enemy)
{
    free(enemy);
}


Ally* new_ally(Object* object)
{
    Ally* ally = malloc(sizeof(*ally));

    ally->object = object;

    return ally;
}

void destroy_ally(Ally* ally)
{
    free(ally);
}

int is_object_enemy(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__GOAT:                             is = 1; break;
        case OBJECT_TYPE__SPIDER:                           is = 1; break;
        case OBJECT_TYPE__BULL:                             is = 1; break;
        case OBJECT_TYPE__FLY:                              is = 1; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 1; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            is = 1; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            is = 1; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            is = 1; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             is = 1; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             is = 1; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             is = 1; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       is = 1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       is = 1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       is = 1; break;

        default: break;
    }

    return is;
}

int is_object_ally(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__HERO:                             is = 1; break;
        case OBJECT_TYPE__HERO_FLOATING:                    is = 1; break;
        case OBJECT_TYPE__HERO_FLYING:                      is = 1; break;
        case OBJECT_TYPE__MINIBOT:                          is = 1; break;

        default: break;
    }

    return is;
}

int is_object_exit(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__EXIT_ROCK_UP:                     is = 1; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  is = 1; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   is = 1; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   is = 1; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          is = 1; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               is = 1; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               is = 1; break;

        default: break;
    }

    return is;
}

int is_object_station(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__STATION_FIST_HAND:                is = 1; break;
        case OBJECT_TYPE__STATION_HOOK_HAND:                is = 1; break;
        case OBJECT_TYPE__STATION_CHAIN_HAND:               is = 1; break;
        case OBJECT_TYPE__STATION_SCISSOR_HAND:             is = 1; break;
        case OBJECT_TYPE__STATION_SPRING_LEG:               is = 1; break;
        case OBJECT_TYPE__STATION_STRIDER_LEG:              is = 1; break;
        case OBJECT_TYPE__STATION_TRACK_LEG:                is = 1; break;
        case OBJECT_TYPE__STATION_BOOT_LEG:                 is = 1; break;
        case OBJECT_TYPE__STATION_MINIBOT_TORSO:            is = 1; break;
        case OBJECT_TYPE__STATION_WINGS_TORSO:              is = 1; break;
        case OBJECT_TYPE__STATION_MANIPULATION_HEAD:        is = 1; break;
        case OBJECT_TYPE__STATION_TELEPORTATION_HEAD:       is = 1; break;

        default: break;
    }

    return is;
}

int get_station_augmentation(Object* object)
{
    int augmentation = AUGMENTATION__NONE;

    switch(object->type)
    {
        case OBJECT_TYPE__STATION_FIST_HAND:            augmentation = AUGMENTATION__FIST_HAND; break;
        case OBJECT_TYPE__STATION_HOOK_HAND:            augmentation = AUGMENTATION__HOOK_HAND; break;
        case OBJECT_TYPE__STATION_CHAIN_HAND:           augmentation = AUGMENTATION__CHAIN_HAND; break;
        case OBJECT_TYPE__STATION_SCISSOR_HAND:         augmentation = AUGMENTATION__SCISSOR_HAND; break;
        case OBJECT_TYPE__STATION_SPRING_LEG:           augmentation = AUGMENTATION__SPRING_LEG; break;
        case OBJECT_TYPE__STATION_STRIDER_LEG:          augmentation = AUGMENTATION__STRIDER_LEG; break;
        case OBJECT_TYPE__STATION_TRACK_LEG:            augmentation = AUGMENTATION__TRACK_LEG; break;
        case OBJECT_TYPE__STATION_BOOT_LEG:             augmentation = AUGMENTATION__BOOT_LEG; break;
        case OBJECT_TYPE__STATION_MINIBOT_TORSO:        augmentation = AUGMENTATION__MINIBOT_TORSO; break;
        case OBJECT_TYPE__STATION_WINGS_TORSO:          augmentation = AUGMENTATION__WINGS_TORSO; break;
        case OBJECT_TYPE__STATION_MANIPULATION_HEAD:    augmentation = AUGMENTATION__MANIPULATION_HEAD; break;
        case OBJECT_TYPE__STATION_TELEPORTATION_HEAD:   augmentation = AUGMENTATION__TELEPORTATION_HEAD; break;

        default: break;
    }

    return augmentation;
}

int is_object_floating(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__HERO_FLOATING:                    is = 1; break;

        default: break;
    }

    return is;
}

int is_object_flying(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__FLY:                              is = 1; break;
        case OBJECT_TYPE__HERO_FLYING:                      is = 1; break;

        default: break;
    }

    return is;
}

int is_object_manipulatable(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        is = 0; break;

        case OBJECT_TYPE__WALL_STONE:                       is = 0; break;

        case OBJECT_TYPE__WALL_METAL:                       is = 0; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           is = 0; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              is = 1; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__PILLAR:                           is = 0; break;

        case OBJECT_TYPE__PIPE:                             is = 0; break;

        case OBJECT_TYPE__STALACTITE:                       is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 0; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 0; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 0; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 0; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 0; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   is = 0; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              is = 0; break;

        case OBJECT_TYPE__CRATE_CELL:                       is = 0; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  is = 0; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   is = 0; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              is = 0; break;

        case OBJECT_TYPE__ROCK:                             is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                is = 0; break;

        case OBJECT_TYPE__SAFE:                             is = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     is = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                is = 0; break;

        case OBJECT_TYPE__DISPLAY:                          is = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  is = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             is = 0; break;

        case OBJECT_TYPE__VENDING_CELL:                     is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        is = 0; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    is = 0; break;

        case OBJECT_TYPE__BARREL:                           is = 1; break;

        case OBJECT_TYPE__PISTON:                           is = 1; break;
        case OBJECT_TYPE__PISTON_CELL:                      is = 1; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  is = 1; break;
        case OBJECT_TYPE__PISTON_BARREL:                    is = 1; break;

        case OBJECT_TYPE__BALL:                             is = 1; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 1; break;

        case OBJECT_TYPE__HERO:                             is = 0; break;
        case OBJECT_TYPE__HERO_FLOATING:                    is = 0; break;
        case OBJECT_TYPE__HERO_FLYING:                      is = 0; break;

        case OBJECT_TYPE__GOAT:                             is = 0; break;
        case OBJECT_TYPE__SPIDER:                           is = 0; break;
        case OBJECT_TYPE__BULL:                             is = 0; break;
        case OBJECT_TYPE__FLY:                              is = 0; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 0; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            is = 0; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             is = 0; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       is = 0; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               is = 0; break;

        default: break;
    }

    return is;
}

int is_object_movable(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        is = 0; break;

        case OBJECT_TYPE__WALL_STONE:                       is = 0; break;

        case OBJECT_TYPE__WALL_METAL:                       is = 0; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           is = 0; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__PILLAR:                           is = 0; break;

        case OBJECT_TYPE__PIPE:                             is = 0; break;

        case OBJECT_TYPE__STALACTITE:                       is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 0; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 0; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 1; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 1; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 1; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   is = 1; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              is = 1; break;

        case OBJECT_TYPE__CRATE_CELL:                       is = 1; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  is = 1; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   is = 1; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              is = 1; break;

        case OBJECT_TYPE__ROCK:                             is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                is = 0; break;

        case OBJECT_TYPE__SAFE:                             is = 1; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     is = 1; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                is = 1; break;

        case OBJECT_TYPE__DISPLAY:                          is = 1; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  is = 1; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             is = 1; break;

        case OBJECT_TYPE__VENDING_CELL:                     is = 1; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                is = 1; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             is = 1; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        is = 1; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 is = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            is = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         is = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    is = 1; break;

        case OBJECT_TYPE__BARREL:                           is = 1; break;

        case OBJECT_TYPE__PISTON:                           is = 0; break;
        case OBJECT_TYPE__PISTON_CELL:                      is = 0; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  is = 0; break;
        case OBJECT_TYPE__PISTON_BARREL:                    is = 0; break;

        case OBJECT_TYPE__BALL:                             is = 1; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 1; break;

        case OBJECT_TYPE__HERO:                             is = 1; break;
        case OBJECT_TYPE__HERO_FLOATING:                    is = 1; break;
        case OBJECT_TYPE__HERO_FLYING:                      is = 1; break;
        case OBJECT_TYPE__MINIBOT:                          is = 1; break;

        case OBJECT_TYPE__GOAT:                             is = 1; break;
        case OBJECT_TYPE__SPIDER:                           is = 1; break;
        case OBJECT_TYPE__BULL:                             is = 1; break;
        case OBJECT_TYPE__FLY:                              is = 1; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 1; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            is = 1; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          is = 1; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            is = 1; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             is = 1; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           is = 1; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             is = 1; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       is = 1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     is = 1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       is = 1; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               is = 0; break;

        default: break;
    }

    return is;
}

int is_object_meltable(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        is = 0; break;

        case OBJECT_TYPE__WALL_STONE:                       is = 0; break;

        case OBJECT_TYPE__WALL_METAL:                       is = 0; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           is = 0; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          is = 1; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__PILLAR:                           is = 0; break;

        case OBJECT_TYPE__PIPE:                             is = 1; break;

        case OBJECT_TYPE__STALACTITE:                       is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 0; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 0; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 0; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 1; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 0; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   is = 1; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              is = 1; break;

        case OBJECT_TYPE__CRATE_CELL:                       is = 1; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  is = 1; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   is = 1; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              is = 1; break;

        case OBJECT_TYPE__ROCK:                             is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                is = 0; break;

        case OBJECT_TYPE__SAFE:                             is = 1; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     is = 1; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                is = 1; break;

        case OBJECT_TYPE__DISPLAY:                          is = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  is = 1; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             is = 1; break;

        case OBJECT_TYPE__VENDING_CELL:                     is = 1; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                is = 1; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             is = 1; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        is = 1; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 is = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            is = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         is = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    is = 1; break;

        case OBJECT_TYPE__BARREL:                           is = 1; break;

        case OBJECT_TYPE__PISTON:                           is = 1; break;
        case OBJECT_TYPE__PISTON_CELL:                      is = 1; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  is = 1; break;
        case OBJECT_TYPE__PISTON_BARREL:                    is = 1; break;

        case OBJECT_TYPE__BALL:                             is = 1; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 1; break;

        case OBJECT_TYPE__HERO:                             is = 1; break;
        case OBJECT_TYPE__HERO_FLOATING:                    is = 1; break;
        case OBJECT_TYPE__HERO_FLYING:                      is = 1; break;
        case OBJECT_TYPE__MINIBOT:                          is = 1; break;

        case OBJECT_TYPE__GOAT:                             is = 1; break;
        case OBJECT_TYPE__SPIDER:                           is = 1; break;
        case OBJECT_TYPE__BULL:                             is = 1; break;
        case OBJECT_TYPE__FLY:                              is = 1; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 1; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            is = 1; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            is = 1; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          is = 1; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            is = 1; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             is = 1; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             is = 1; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           is = 1; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             is = 1; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       is = 1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       is = 1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     is = 1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       is = 1; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               is = 1; break;

        default: break;
    }

    return is;
}

int is_object_breakable(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        is = 0; break;

        case OBJECT_TYPE__WALL_STONE:                       is = 0; break;

        case OBJECT_TYPE__WALL_METAL:                       is = 0; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             is = 1; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          is = 1; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           is = 1; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           is = 1; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__PILLAR:                           is = 1; break;

        case OBJECT_TYPE__PIPE:                             is = 0; break;

        case OBJECT_TYPE__STALACTITE:                       is = 1; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 1; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 1; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 1; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 1; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 1; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 0; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 0; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   is = 0; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              is = 0; break;

        case OBJECT_TYPE__CRATE_CELL:                       is = 0; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  is = 0; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   is = 0; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              is = 0; break;

        case OBJECT_TYPE__ROCK:                             is = 1; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     is = 1; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                is = 1; break;

        case OBJECT_TYPE__SAFE:                             is = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     is = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                is = 0; break;

        case OBJECT_TYPE__DISPLAY:                          is = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  is = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             is = 0; break;

        case OBJECT_TYPE__VENDING_CELL:                     is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        is = 0; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    is = 0; break;

        case OBJECT_TYPE__BARREL:                           is = 0; break;

        case OBJECT_TYPE__PISTON:                           is = 0; break;
        case OBJECT_TYPE__PISTON_CELL:                      is = 0; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  is = 0; break;
        case OBJECT_TYPE__PISTON_BARREL:                    is = 0; break;

        case OBJECT_TYPE__BALL:                             is = 0; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 0; break;

        case OBJECT_TYPE__HERO:                             is = 0; break;
        case OBJECT_TYPE__HERO_FLOATING:                    is = 0; break;
        case OBJECT_TYPE__HERO_FLYING:                      is = 0; break;
        case OBJECT_TYPE__MINIBOT:                          is = 0; break;

        case OBJECT_TYPE__GOAT:                             is = 0; break;
        case OBJECT_TYPE__SPIDER:                           is = 0; break;
        case OBJECT_TYPE__BULL:                             is = 0; break;
        case OBJECT_TYPE__FLY:                              is = 0; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 0; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            is = 0; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             is = 0; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       is = 0; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                is = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               is = 0; break;

        default: break;
    }

    return is;
}

int get_object_item_type(Object* object)
{
    int item_type = ITEM__NONE;

    switch(object->type)
    {
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            item_type = ITEM__CELL; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         item_type = ITEM__CELL; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          item_type = ITEM__CELL; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          item_type = ITEM__CELL; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          item_type = ITEM__NONE; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       item_type = ITEM__NONE; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        item_type = ITEM__NONE; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        item_type = ITEM__NONE; break;

        case OBJECT_TYPE__WALL_ROCK:                        item_type = ITEM__NONE; break;

        case OBJECT_TYPE__WALL_STONE:                       item_type = ITEM__NONE; break;

        case OBJECT_TYPE__WALL_METAL:                       item_type = ITEM__NONE; break;

        case OBJECT_TYPE__PILLAR:                           item_type = ITEM__NONE; break;

        case OBJECT_TYPE__PIPE:                             item_type = ITEM__NONE; break;

        case OBJECT_TYPE__STALACTITE:                       item_type = ITEM__NONE; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                item_type = ITEM__NONE; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           item_type = ITEM__GEMSTONE; break;

        case OBJECT_TYPE__STALAGMITE:                       item_type = ITEM__NONE; break;

        case OBJECT_TYPE__STALAGNATE:                       item_type = ITEM__NONE; break;

        case OBJECT_TYPE__COVER_ROCK:                       item_type = ITEM__NONE; break;
        case OBJECT_TYPE__COVER_METAL:                      item_type = ITEM__NONE; break;
        case OBJECT_TYPE__COVER_GLASS:                      item_type = ITEM__NONE; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   item_type = ITEM__NONE; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              item_type = ITEM__GEMSTONE; break;

        case OBJECT_TYPE__CRATE_CELL:                       item_type = ITEM__NONE; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  item_type = ITEM__CELL; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   item_type = ITEM__NONE; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              item_type = ITEM__DYNAMITE; break;

        case OBJECT_TYPE__ROCK:                             item_type = ITEM__NONE; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     item_type = ITEM__NONE; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                item_type = ITEM__GEMSTONE; break;

        case OBJECT_TYPE__SAFE:                             item_type = ITEM__NONE; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     item_type = ITEM__NONE; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                item_type = ITEM__GEMSTONE; break;

        case OBJECT_TYPE__DISPLAY:                          item_type = ITEM__NONE; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  item_type = ITEM__NONE; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             item_type = ITEM__GEMSTONE; break;

        case OBJECT_TYPE__VENDING_CELL:                     item_type = ITEM__NONE; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                item_type = ITEM__CELL; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             item_type = ITEM__NONE; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        item_type = ITEM__CELL; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 item_type = ITEM__NONE; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            item_type = ITEM__DYNAMITE; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         item_type = ITEM__NONE; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    item_type = ITEM__DYNAMITE; break;

        case OBJECT_TYPE__BARREL:                           item_type = ITEM__NONE; break;

        case OBJECT_TYPE__PISTON:                           item_type = ITEM__NONE; break;
        case OBJECT_TYPE__PISTON_CELL:                      item_type = ITEM__CELL; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  item_type = ITEM__DYNAMITE; break;
        case OBJECT_TYPE__PISTON_BARREL:                    item_type = ITEM__NONE; break;

        case OBJECT_TYPE__BALL:                             item_type = ITEM__NONE; break;
        case OBJECT_TYPE__BALL_SPIKES:                      item_type = ITEM__NONE; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       item_type = ITEM__CELL; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               item_type = ITEM__NONE; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                item_type = ITEM__NONE; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            item_type = ITEM__NONE; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               item_type = ITEM__NONE; break;

        default: break;
    }

    return item_type;
}

int get_object_item_count(Object* object)
{
    int count = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            count = 1; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         count = 1; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          count = 1; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          count = 1; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          count = 0; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       count = 0; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        count = 0; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        count = 0; break;

        case OBJECT_TYPE__WALL_ROCK:                        count = 0; break;

        case OBJECT_TYPE__WALL_STONE:                       count = 0; break;

        case OBJECT_TYPE__WALL_METAL:                       count = 0; break;

        case OBJECT_TYPE__PILLAR:                           count = 0; break;

        case OBJECT_TYPE__PIPE:                             count = 0; break;

        case OBJECT_TYPE__STALACTITE:                       count = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                count = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           count = 1; break;

        case OBJECT_TYPE__STALAGMITE:                       count = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       count = 0; break;

        case OBJECT_TYPE__COVER_ROCK:                       count = 0; break;
        case OBJECT_TYPE__COVER_METAL:                      count = 0; break;
        case OBJECT_TYPE__COVER_GLASS:                      count = 0; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   count = 0; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              count = 1; break;

        case OBJECT_TYPE__CRATE_CELL:                       count = 0; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  count = 0; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   count = 0; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              count = 1; break;

        case OBJECT_TYPE__ROCK:                             count = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     count = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                count = 1; break;

        case OBJECT_TYPE__SAFE:                             count = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     count = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                count = 1; break;

        case OBJECT_TYPE__DISPLAY:                          count = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  count = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             count = 1; break;

        case OBJECT_TYPE__VENDING_CELL:                     count = 0; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                count = 1; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             count = 0; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        count = 3; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 count = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            count = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         count = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    count = 3; break;

        case OBJECT_TYPE__BARREL:                           count = 0; break;

        case OBJECT_TYPE__PISTON:                           count = 0; break;
        case OBJECT_TYPE__PISTON_CELL:                      count = 2; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  count = 2; break;
        case OBJECT_TYPE__PISTON_BARREL:                    count = 0; break;

        case OBJECT_TYPE__BALL:                             count = 0; break;
        case OBJECT_TYPE__BALL_SPIKES:                      count = 0; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       count = 1; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               count = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                count = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            count = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               count = 0; break;

        default: break;
    }

    return count;
}

int is_object_put_item(Object* object)
{
    int is = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        is = 1; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        is = 1; break;

        case OBJECT_TYPE__WALL_ROCK:                        is = 0; break;

        case OBJECT_TYPE__WALL_STONE:                       is = 0; break;

        case OBJECT_TYPE__WALL_METAL:                       is = 0; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           is = 0; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           is = 0; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          is = 0; break;

        case OBJECT_TYPE__EXIT_GOLD_LOCKED_UP:              is = 1; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_RIGHT:           is = 1; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_DOWN:            is = 1; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_LEFT:            is = 1; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_UP:            is = 0; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_RIGHT:         is = 0; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_DOWN:          is = 0; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_LEFT:          is = 0; break;


        case OBJECT_TYPE__PILLAR:                           is = 0; break;

        case OBJECT_TYPE__PIPE:                             is = 0; break;

        case OBJECT_TYPE__STALACTITE:                       is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 0; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 0; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 0; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 0; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 0; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   is = 0; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              is = 0; break;

        case OBJECT_TYPE__CRATE_CELL:                       is = 0; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  is = 0; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   is = 0; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              is = 0; break;

        case OBJECT_TYPE__ROCK:                             is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     is = 0; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                is = 0; break;

        case OBJECT_TYPE__SAFE:                             is = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     is = 0; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                is = 0; break;

        case OBJECT_TYPE__DISPLAY:                          is = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  is = 0; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             is = 0; break;

        case OBJECT_TYPE__VENDING_CELL:                     is = 1; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             is = 0; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        is = 0; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 is = 1; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         is = 0; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    is = 0; break;

        case OBJECT_TYPE__BARREL:                           is = 0; break;

        case OBJECT_TYPE__PISTON:                           is = 0; break;
        case OBJECT_TYPE__PISTON_CELL:                      is = 0; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  is = 0; break;
        case OBJECT_TYPE__PISTON_BARREL:                    is = 0; break;

        case OBJECT_TYPE__BALL:                             is = 0; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 0; break;

        case OBJECT_TYPE__HERO:                             is = 0; break;
        case OBJECT_TYPE__GOAT:                             is = 0; break;
        case OBJECT_TYPE__SPIDER:                           is = 0; break;
        case OBJECT_TYPE__BULL:                             is = 0; break;
        case OBJECT_TYPE__FLY:                              is = 0; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 0; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          is = 0; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            is = 0; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           is = 0; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             is = 0; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     is = 0; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       is = 0; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            is = 0; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               is = 0; break;

        default: break;
    }

    return is;
}

char* get_name_from_object_type(int object_type)
{
    char* name = "";

    switch(object_type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        name = "wall rock"; break;

        case OBJECT_TYPE__WALL_STONE:                       name = "wall stone"; break;

        case OBJECT_TYPE__WALL_METAL:                       name = "wall metal"; break;

        case OBJECT_TYPE__WALL_GOLD:                        name = "wall gold"; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     name = "exit rock up"; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  name = "exit rock right"; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   name = "exit rock down"; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   name = "exit rock left"; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             name = "exit rock blocked up"; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          name = "exit rock blocked right"; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           name = "exit rock blocked down"; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           name = "exit rock blocked left"; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    name = "exit stone up"; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 name = "exit stone right"; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  name = "exit stone down"; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  name = "exit stone left"; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            name = "exit stone blocked up"; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         name = "exit stone blocked right"; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          name = "exit stone blocked down"; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          name = "exit stone blocked left"; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            name = "exit stone powered up"; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         name = "exit stone powered right"; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          name = "exit stone powered down"; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          name = "exit stone powered left"; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          name = "exit stone unpowered up"; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       name = "exit stone unpowered right"; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        name = "exit stone unpowered down"; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        name = "exit stone unpowered left"; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    name = "exit metal up"; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 name = "exit metal right"; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  name = "exit metal down"; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  name = "exit metal left"; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 name = "exit metal on up"; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              name = "exit metal on right"; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               name = "exit metal on down"; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               name = "exit metal on left"; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                name = "exit metal off up"; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             name = "exit metal off right"; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              name = "exit metal off down"; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              name = "exit metal off left"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            name = "exit metal blocked up"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         name = "exit metal blocked right"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          name = "exit metal blocked down"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          name = "exit metal blocked left"; break;

        case OBJECT_TYPE__EXIT_GOLD_LOCKED_UP:              name = "exit gold locked up"; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_RIGHT:           name = "exit gold locked right"; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_DOWN:            name = "exit gold locked down"; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_LEFT:            name = "exit gold locked left"; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_UP:            name = "exit gold unlocked up"; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_RIGHT:         name = "exit gold unlocked right"; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_DOWN:          name = "exit gold unlocked down"; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_LEFT:          name = "exit gold unlocked left"; break;

        case OBJECT_TYPE__PILLAR:                           name = "pillar"; break;

        case OBJECT_TYPE__PIPE:                             name = "pipe"; break;

        case OBJECT_TYPE__STALACTITE:                       name = "stalactite"; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                name = "stalactite fallen"; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           name = "stalactite fallen item"; break;

        case OBJECT_TYPE__STALAGMITE:                       name = "stalagmite"; break;

        case OBJECT_TYPE__STALAGNATE:                       name = "stalagnate"; break;

        case OBJECT_TYPE__COVER_ROCK:                       name = "cover rock"; break;
        case OBJECT_TYPE__COVER_METAL:                      name = "cover metal"; break;
        case OBJECT_TYPE__COVER_GLASS:                      name = "cover glass"; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   name = "crate gemstone"; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              name = "crate gemstone item"; break;

        case OBJECT_TYPE__CRATE_CELL:                       name = "crate cell"; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  name = "crate cell item"; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   name = "crate dynamite"; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              name = "crate dynamite item"; break;

        case OBJECT_TYPE__ROCK:                             name = "rock"; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     name = "rock damaged"; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                name = "rock damaged item"; break;

        case OBJECT_TYPE__SAFE:                             name = "safe"; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     name = "safe damaged"; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                name = "safe damaged item"; break;

        case OBJECT_TYPE__DISPLAY:                          name = "display"; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  name = "display damaged"; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             name = "display damaged item"; break;

        case OBJECT_TYPE__VENDING_CELL:                     name = "vending cell"; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                name = "vending cell item"; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             name = "vending cell damaged"; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        name = "vending cell damaged item"; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 name = "vending dynamite"; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            name = "vending dynamite item"; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         name = "vending dynamite damaged"; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    name = "vending dynamite damaged item"; break;

        case OBJECT_TYPE__BARREL:                           name = "barrel"; break;

        case OBJECT_TYPE__PISTON:                           name = "piston"; break;
        case OBJECT_TYPE__PISTON_CELL:                      name = "piston cell"; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  name = "piston dynamite"; break;
        case OBJECT_TYPE__PISTON_BARREL:                    name = "piston barrel"; break;

        case OBJECT_TYPE__BALL:                             name = "ball"; break;
        case OBJECT_TYPE__BALL_SPIKES:                      name = "ball spikes"; break;

        case OBJECT_TYPE__HERO:                             name = "hero"; break;
        case OBJECT_TYPE__HERO_FLOATING:                    name = "hero floating"; break;
        case OBJECT_TYPE__HERO_FLYING:                      name = "hero flying"; break;
        case OBJECT_TYPE__MINIBOT:                          name = "minibot"; break;

        case OBJECT_TYPE__GOAT:                             name = "goat"; break;
        case OBJECT_TYPE__SPIDER:                           name = "spider"; break;
        case OBJECT_TYPE__BULL:                             name = "bull"; break;
        case OBJECT_TYPE__FLY:                              name = "fly"; break;
        case OBJECT_TYPE__CHAMELEON:                        name = "chameleon"; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            name = "turret laser grounded"; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            name = "turret laser standing"; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          name = "turret laser undeployed"; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            name = "turret laser deployed"; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             name = "turret bomb grounded"; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             name = "turret bomb standing"; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           name = "turret bomb undeployed"; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             name = "turret bomb deployed"; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       name = "turret projectile grounded"; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       name = "turret projectile standing"; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     name = "turret projectile undeployed"; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       name = "turret projectile deployed"; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       name = "stairs above stone powered"; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               name = "stairs above stone"; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                name = "stairs above rock"; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            name = "stairs above metal on"; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               name = "stairs above metal"; break;

        case OBJECT_TYPE__STATION_FIST_HAND:                name = "station push hand"; break;
        case OBJECT_TYPE__STATION_HOOK_HAND:                name = "station hook hand"; break;
        case OBJECT_TYPE__STATION_CHAIN_HAND:               name = "station chain hand"; break;
        case OBJECT_TYPE__STATION_SCISSOR_HAND:             name = "station scissor hand"; break;
        case OBJECT_TYPE__STATION_SPRING_LEG:               name = "station spring leg"; break;
        case OBJECT_TYPE__STATION_STRIDER_LEG:              name = "station strider leg"; break;
        case OBJECT_TYPE__STATION_TRACK_LEG:                name = "station track leg"; break;
        case OBJECT_TYPE__STATION_BOOT_LEG:                 name = "station boot leg"; break;
        case OBJECT_TYPE__STATION_MINIBOT_TORSO:            name = "station minibot torso"; break;
        case OBJECT_TYPE__STATION_WINGS_TORSO:              name = "station wings torso"; break;
        case OBJECT_TYPE__STATION_MANIPULATION_HEAD:        name = "station manipulation head"; break;
        case OBJECT_TYPE__STATION_TELEPORTATION_HEAD:       name = "station teleportation head"; break;
        case OBJECT_TYPE__STATION_TAKEN:                    name = "station taken"; break;

        default: break;
    }

    return name;
}

Texture* get_texture_1_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        texture = textures->object.wall_rock; break;

        case OBJECT_TYPE__WALL_STONE:                       texture = textures->object.wall_stone; break;

        case OBJECT_TYPE__WALL_METAL:                       texture = textures->object.wall_metal; break;

        case OBJECT_TYPE__WALL_GOLD:                       texture = textures->object.wall_gold; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     texture = textures->object.exit_rock_up; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  texture = textures->object.exit_rock_right; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   texture = textures->object.exit_rock_down; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   texture = textures->object.exit_rock_left; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             texture = textures->object.exit_rock_blocked_up; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          texture = textures->object.exit_rock_blocked_right; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           texture = textures->object.exit_rock_blocked_down; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           texture = textures->object.exit_rock_blocked_left; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    texture = textures->object.exit_stone_up; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 texture = textures->object.exit_stone_right; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  texture = textures->object.exit_stone_down; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  texture = textures->object.exit_stone_left; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            texture = textures->object.exit_stone_blocked_up; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         texture = textures->object.exit_stone_blocked_right; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          texture = textures->object.exit_stone_blocked_down; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          texture = textures->object.exit_stone_blocked_left; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            texture = textures->object.exit_stone_powered_up; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         texture = textures->object.exit_stone_powered_right; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          texture = textures->object.exit_stone_powered_down; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          texture = textures->object.exit_stone_powered_left; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          texture = textures->object.exit_stone_unpowered_up; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       texture = textures->object.exit_stone_unpowered_right; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        texture = textures->object.exit_stone_unpowered_down; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        texture = textures->object.exit_stone_unpowered_left; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 texture = textures->object.exit_metal_on_up; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              texture = textures->object.exit_metal_on_right; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               texture = textures->object.exit_metal_on_down; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               texture = textures->object.exit_metal_on_left; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                texture = textures->object.exit_metal_off_up; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             texture = textures->object.exit_metal_off_right; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              texture = textures->object.exit_metal_off_down; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              texture = textures->object.exit_metal_off_left; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_blocked_up; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_blocked_right; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_blocked_down; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_blocked_left; break;

        case OBJECT_TYPE__EXIT_GOLD_LOCKED_UP:              texture = textures->object.exit_gold_locked_up; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_RIGHT:           texture = textures->object.exit_gold_locked_right; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_DOWN:            texture = textures->object.exit_gold_locked_down; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_LEFT:            texture = textures->object.exit_gold_locked_left; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_UP:            texture = textures->object.exit_gold_unlocked_up; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_RIGHT:         texture = textures->object.exit_gold_unlocked_right; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_DOWN:          texture = textures->object.exit_gold_unlocked_down; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_LEFT:          texture = textures->object.exit_gold_unlocked_left; break;

        case OBJECT_TYPE__PILLAR:                           texture = textures->object.pillar; break;

        case OBJECT_TYPE__PIPE:                             texture = textures->object.pipe; break;

        case OBJECT_TYPE__STALACTITE:                       texture = textures->object.stalactite; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                texture = textures->object.stalactite_fallen; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           texture = textures->object.stalactite_fallen_item; break;

        case OBJECT_TYPE__STALAGMITE:                       texture = textures->object.stalagmite; break;

        case OBJECT_TYPE__STALAGNATE:                       texture = textures->object.stalagnate; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   texture = textures->object.crate_gemstone; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              texture = textures->object.crate_gemstone_item; break;

        case OBJECT_TYPE__CRATE_CELL:                       texture = textures->object.crate_cell; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  texture = textures->object.crate_cell_item; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   texture = textures->object.crate_dynamite; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              texture = textures->object.crate_dynamite_item; break;

        case OBJECT_TYPE__ROCK:                             texture = textures->object.rock; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     texture = textures->object.rock_damaged; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                texture = textures->object.rock_damaged_item; break;

        case OBJECT_TYPE__SAFE:                             texture = textures->object.safe; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     texture = textures->object.safe_damaged; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                texture = textures->object.safe_damaged_item; break;

        case OBJECT_TYPE__DISPLAY:                          texture = textures->object.display; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  texture = textures->object.display_damaged; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             texture = textures->object.display_damaged_item; break;

        case OBJECT_TYPE__VENDING_CELL:                     texture = textures->object.vending_cell; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                texture = textures->object.vending_cell_item; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             texture = textures->object.vending_cell_damaged; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        texture = textures->object.vending_cell_damaged_item; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 texture = textures->object.vending_dynamite; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            texture = textures->object.vending_dynamite_item; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         texture = textures->object.vending_dynamite_damaged; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    texture = textures->object.vending_dynamite_damaged_item; break;

        case OBJECT_TYPE__BARREL:                           texture = textures->object.barrel; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston; break;
        case OBJECT_TYPE__PISTON_CELL:                      texture = textures->object.piston_cell; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  texture = textures->object.piston_dynamite; break;
        case OBJECT_TYPE__PISTON_BARREL:                    texture = textures->object.piston_barrel; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_1; break;
        case OBJECT_TYPE__HERO_FLOATING:                    texture = textures->object.hero_floating_1; break;
        case OBJECT_TYPE__HERO_FLYING:                      texture = textures->object.hero_flying_1; break;
        case OBJECT_TYPE__MINIBOT:                          texture = textures->object.minibot_1; break;

        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_1; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_1; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_1; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_1; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_1; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            texture = textures->object.turret_laser_grounded_1; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            texture = textures->object.turret_laser_standing_1; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          texture = textures->object.turret_laser_undeployed_1; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            texture = textures->object.turret_laser_deployed_1; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             texture = textures->object.turret_bomb_grounded_1; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             texture = textures->object.turret_bomb_standing_1; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           texture = textures->object.turret_bomb_undeployed_1; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             texture = textures->object.turret_bomb_deployed_1; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       texture = textures->object.turret_projectile_grounded_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       texture = textures->object.turret_projectile_standing_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     texture = textures->object.turret_projectile_undeployed_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       texture = textures->object.turret_projectile_deployed_1; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       texture = textures->object.stairs_above_stone_powered; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               texture = textures->object.stairs_above_stone; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                texture = textures->object.stairs_above_rock; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            texture = textures->object.stairs_above_metal_on; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               texture = textures->object.stairs_above_metal; break;

        case OBJECT_TYPE__STATION_FIST_HAND:                texture = textures->object.station_fist_hand; break;
        case OBJECT_TYPE__STATION_HOOK_HAND:                texture = textures->object.station_hook_hand; break;
        case OBJECT_TYPE__STATION_CHAIN_HAND:               texture = textures->object.station_chain_hand; break;
        case OBJECT_TYPE__STATION_SCISSOR_HAND:             texture = textures->object.station_scissor_hand; break;
        case OBJECT_TYPE__STATION_SPRING_LEG:               texture = textures->object.station_spring_leg; break;
        case OBJECT_TYPE__STATION_STRIDER_LEG:              texture = textures->object.station_strider_leg; break;
        case OBJECT_TYPE__STATION_TRACK_LEG:                texture = textures->object.station_track_leg; break;
        case OBJECT_TYPE__STATION_BOOT_LEG:                 texture = textures->object.station_boot_leg; break;
        case OBJECT_TYPE__STATION_MINIBOT_TORSO:            texture = textures->object.station_minibot_torso; break;
        case OBJECT_TYPE__STATION_WINGS_TORSO:              texture = textures->object.station_wings_torso; break;
        case OBJECT_TYPE__STATION_MANIPULATION_HEAD:        texture = textures->object.station_manipulation_head; break;
        case OBJECT_TYPE__STATION_TELEPORTATION_HEAD:       texture = textures->object.station_teleportation_head; break;
        case OBJECT_TYPE__STATION_TAKEN:                    texture = textures->object.station_taken; break;

        default: break;
    }

    return texture;
}

Texture* get_texture_2_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        texture = textures->object.wall_rock; break;

        case OBJECT_TYPE__WALL_STONE:                       texture = textures->object.wall_stone; break;

        case OBJECT_TYPE__WALL_METAL:                       texture = textures->object.wall_metal; break;

        case OBJECT_TYPE__WALL_GOLD:                       texture = textures->object.wall_gold; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     texture = textures->object.exit_rock_up; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  texture = textures->object.exit_rock_right; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   texture = textures->object.exit_rock_down; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   texture = textures->object.exit_rock_left; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             texture = textures->object.exit_rock_blocked_up; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          texture = textures->object.exit_rock_blocked_right; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           texture = textures->object.exit_rock_blocked_down; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           texture = textures->object.exit_rock_blocked_left; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    texture = textures->object.exit_stone_up; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 texture = textures->object.exit_stone_right; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  texture = textures->object.exit_stone_down; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  texture = textures->object.exit_stone_left; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            texture = textures->object.exit_stone_blocked_up; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         texture = textures->object.exit_stone_blocked_right; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          texture = textures->object.exit_stone_blocked_down; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          texture = textures->object.exit_stone_blocked_left; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            texture = textures->object.exit_stone_powered_up; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         texture = textures->object.exit_stone_powered_right; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          texture = textures->object.exit_stone_powered_down; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          texture = textures->object.exit_stone_powered_left; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          texture = textures->object.exit_stone_unpowered_up; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       texture = textures->object.exit_stone_unpowered_right; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        texture = textures->object.exit_stone_unpowered_down; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        texture = textures->object.exit_stone_unpowered_left; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 texture = textures->object.exit_metal_on_up; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              texture = textures->object.exit_metal_on_right; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               texture = textures->object.exit_metal_on_down; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               texture = textures->object.exit_metal_on_left; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                texture = textures->object.exit_metal_off_up; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             texture = textures->object.exit_metal_off_right; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              texture = textures->object.exit_metal_off_down; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              texture = textures->object.exit_metal_off_left; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_blocked_up; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_blocked_right; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_blocked_down; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_blocked_left; break;

        case OBJECT_TYPE__EXIT_GOLD_LOCKED_UP:              texture = textures->object.exit_gold_locked_up; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_RIGHT:           texture = textures->object.exit_gold_locked_right; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_DOWN:            texture = textures->object.exit_gold_locked_down; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_LEFT:            texture = textures->object.exit_gold_locked_left; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_UP:            texture = textures->object.exit_gold_unlocked_up; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_RIGHT:         texture = textures->object.exit_gold_unlocked_right; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_DOWN:          texture = textures->object.exit_gold_unlocked_down; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_LEFT:          texture = textures->object.exit_gold_unlocked_left; break;

        case OBJECT_TYPE__PILLAR:                           texture = textures->object.pillar; break;

        case OBJECT_TYPE__PIPE:                             texture = textures->object.pipe; break;

        case OBJECT_TYPE__STALACTITE:                       texture = textures->object.stalactite; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                texture = textures->object.stalactite_fallen; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           texture = textures->object.stalactite_fallen_item; break;

        case OBJECT_TYPE__STALAGMITE:                       texture = textures->object.stalagmite; break;

        case OBJECT_TYPE__STALAGNATE:                       texture = textures->object.stalagnate; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   texture = textures->object.crate_gemstone; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              texture = textures->object.crate_gemstone_item; break;

        case OBJECT_TYPE__CRATE_CELL:                       texture = textures->object.crate_cell; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  texture = textures->object.crate_cell_item; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   texture = textures->object.crate_dynamite; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              texture = textures->object.crate_dynamite_item; break;

        case OBJECT_TYPE__ROCK:                             texture = textures->object.rock; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     texture = textures->object.rock_damaged; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                texture = textures->object.rock_damaged_item; break;

        case OBJECT_TYPE__SAFE:                             texture = textures->object.safe; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     texture = textures->object.safe_damaged; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                texture = textures->object.safe_damaged_item; break;

        case OBJECT_TYPE__DISPLAY:                          texture = textures->object.display; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  texture = textures->object.display_damaged; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             texture = textures->object.display_damaged_item; break;

        case OBJECT_TYPE__VENDING_CELL:                     texture = textures->object.vending_cell; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                texture = textures->object.vending_cell_item; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             texture = textures->object.vending_cell_damaged; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        texture = textures->object.vending_cell_damaged_item; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 texture = textures->object.vending_dynamite; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            texture = textures->object.vending_dynamite_item; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         texture = textures->object.vending_dynamite_damaged; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    texture = textures->object.vending_dynamite_damaged_item; break;

        case OBJECT_TYPE__BARREL:                           texture = textures->object.barrel; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston; break;
        case OBJECT_TYPE__PISTON_CELL:                      texture = textures->object.piston_cell; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  texture = textures->object.piston_dynamite; break;
        case OBJECT_TYPE__PISTON_BARREL:                    texture = textures->object.piston_barrel; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_2; break;
        case OBJECT_TYPE__HERO_FLOATING:                    texture = textures->object.hero_floating_2; break;
        case OBJECT_TYPE__HERO_FLYING:                      texture = textures->object.hero_flying_2; break;
        case OBJECT_TYPE__MINIBOT:                          texture = textures->object.minibot_2; break;

        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_2; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_2; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_2; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_2; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_2; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            texture = textures->object.turret_laser_grounded_2; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            texture = textures->object.turret_laser_standing_2; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          texture = textures->object.turret_laser_undeployed_2; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            texture = textures->object.turret_laser_deployed_2; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             texture = textures->object.turret_bomb_grounded_2; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             texture = textures->object.turret_bomb_standing_2; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           texture = textures->object.turret_bomb_undeployed_2; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             texture = textures->object.turret_bomb_deployed_2; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       texture = textures->object.turret_projectile_grounded_2; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       texture = textures->object.turret_projectile_standing_2; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     texture = textures->object.turret_projectile_undeployed_2; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       texture = textures->object.turret_projectile_deployed_2; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       texture = textures->object.stairs_above_stone_powered; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               texture = textures->object.stairs_above_stone; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                texture = textures->object.stairs_above_rock; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            texture = textures->object.stairs_above_metal_on; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               texture = textures->object.stairs_above_metal; break;

        case OBJECT_TYPE__STATION_FIST_HAND:                texture = textures->object.station_fist_hand; break;
        case OBJECT_TYPE__STATION_HOOK_HAND:                texture = textures->object.station_hook_hand; break;
        case OBJECT_TYPE__STATION_CHAIN_HAND:               texture = textures->object.station_chain_hand; break;
        case OBJECT_TYPE__STATION_SCISSOR_HAND:             texture = textures->object.station_scissor_hand; break;
        case OBJECT_TYPE__STATION_SPRING_LEG:               texture = textures->object.station_spring_leg; break;
        case OBJECT_TYPE__STATION_STRIDER_LEG:              texture = textures->object.station_strider_leg; break;
        case OBJECT_TYPE__STATION_TRACK_LEG:                texture = textures->object.station_track_leg; break;
        case OBJECT_TYPE__STATION_BOOT_LEG:                 texture = textures->object.station_boot_leg; break;
        case OBJECT_TYPE__STATION_MINIBOT_TORSO:            texture = textures->object.station_minibot_torso; break;
        case OBJECT_TYPE__STATION_WINGS_TORSO:              texture = textures->object.station_wings_torso; break;
        case OBJECT_TYPE__STATION_MANIPULATION_HEAD:        texture = textures->object.station_manipulation_head; break;
        case OBJECT_TYPE__STATION_TELEPORTATION_HEAD:       texture = textures->object.station_teleportation_head; break;
        case OBJECT_TYPE__STATION_TAKEN:                    texture = textures->object.station_taken; break;

        default: break;
    }

    return texture;
}

Texture* get_texture_1_outline_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        texture = textures->object.wall_rock_outline; break;

        case OBJECT_TYPE__WALL_STONE:                       texture = textures->object.wall_stone_outline; break;

        case OBJECT_TYPE__WALL_METAL:                       texture = textures->object.wall_metal_outline; break;

        case OBJECT_TYPE__WALL_GOLD:                       texture = textures->object.wall_gold_outline; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     texture = textures->object.exit_rock_up_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  texture = textures->object.exit_rock_right_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   texture = textures->object.exit_rock_down_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   texture = textures->object.exit_rock_left_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             texture = textures->object.exit_rock_up_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          texture = textures->object.exit_rock_right_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           texture = textures->object.exit_rock_down_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           texture = textures->object.exit_rock_left_outline; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  texture = textures->object.exit_stone_left_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          texture = textures->object.exit_stone_left_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          texture = textures->object.exit_stone_left_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        texture = textures->object.exit_stone_left_outline; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_left_outline; break;

        case OBJECT_TYPE__EXIT_GOLD_LOCKED_UP:              texture = textures->object.exit_gold_up_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_RIGHT:           texture = textures->object.exit_gold_right_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_DOWN:            texture = textures->object.exit_gold_down_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_LEFT:            texture = textures->object.exit_gold_left_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_UP:            texture = textures->object.exit_gold_up_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_RIGHT:         texture = textures->object.exit_gold_right_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_DOWN:          texture = textures->object.exit_gold_down_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_LEFT:          texture = textures->object.exit_gold_left_outline; break;

        case OBJECT_TYPE__STALACTITE:                       texture = textures->object.stalactite_outline; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                texture = textures->object.stalactite_fallen_outline; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           texture = textures->object.stalactite_fallen_item_outline; break;

        case OBJECT_TYPE__STALAGMITE:                       texture = textures->object.stalagmite_outline; break;

        case OBJECT_TYPE__STALAGNATE:                       texture = textures->object.stalagnate_outline; break;

        case OBJECT_TYPE__PILLAR:                           texture = textures->object.pillar_outline; break;

        case OBJECT_TYPE__PIPE:                             texture = textures->object.pipe_outline; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock_outline; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal_outline; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass_outline; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   texture = textures->object.crate_gemstone_outline; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              texture = textures->object.crate_gemstone_item_outline; break;

        case OBJECT_TYPE__CRATE_CELL:                       texture = textures->object.crate_cell_outline; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  texture = textures->object.crate_cell_item_outline; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   texture = textures->object.crate_dynamite_outline; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              texture = textures->object.crate_dynamite_item_outline; break;

        case OBJECT_TYPE__ROCK:                             texture = textures->object.rock_outline; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     texture = textures->object.rock_damaged_outline; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                texture = textures->object.rock_damaged_item_outline; break;

        case OBJECT_TYPE__SAFE:                             texture = textures->object.safe_outline; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     texture = textures->object.safe_damaged_outline; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                texture = textures->object.safe_damaged_item_outline; break;

        case OBJECT_TYPE__DISPLAY:                          texture = textures->object.display_outline; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  texture = textures->object.display_damaged_outline; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             texture = textures->object.display_damaged_item_outline; break;

        case OBJECT_TYPE__VENDING_CELL:                     texture = textures->object.vending_cell_outline; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                texture = textures->object.vending_cell_item_outline; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             texture = textures->object.vending_cell_damaged_outline; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        texture = textures->object.vending_cell_damaged_item_outline; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 texture = textures->object.vending_dynamite_outline; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            texture = textures->object.vending_dynamite_item_outline; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         texture = textures->object.vending_dynamite_damaged_outline; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    texture = textures->object.vending_dynamite_damaged_item_outline; break;

        case OBJECT_TYPE__BARREL:                           texture = textures->object.barrel_outline; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston_outline; break;
        case OBJECT_TYPE__PISTON_CELL:                      texture = textures->object.piston_cell_outline; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  texture = textures->object.piston_dynamite_outline; break;
        case OBJECT_TYPE__PISTON_BARREL:                    texture = textures->object.piston_barrel_outline; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball_outline; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes_outline; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_outline_1; break;
        case OBJECT_TYPE__HERO_FLOATING:                    texture = textures->object.hero_floating_outline_1; break;
        case OBJECT_TYPE__HERO_FLYING:                      texture = textures->object.hero_flying_outline_1; break;
        case OBJECT_TYPE__MINIBOT:                          texture = textures->object.minibot_outline_1; break;

        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_outline_1; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_outline_1; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_outline_1; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_outline_1; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_outline_1; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            texture = textures->object.turret_laser_grounded_outline_1; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            texture = textures->object.turret_laser_standing_outline_1; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          texture = textures->object.turret_laser_undeployed_outline_1; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            texture = textures->object.turret_laser_deployed_outline_1; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             texture = textures->object.turret_bomb_grounded_outline_1; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             texture = textures->object.turret_bomb_standing_outline_1; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           texture = textures->object.turret_bomb_undeployed_outline_1; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             texture = textures->object.turret_bomb_deployed_outline_1; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       texture = textures->object.turret_projectile_grounded_outline_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       texture = textures->object.turret_projectile_standing_outline_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     texture = textures->object.turret_projectile_undeployed_outline_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       texture = textures->object.turret_projectile_deployed_outline_1; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       texture = textures->object.stairs_above_stone_powered_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               texture = textures->object.stairs_above_stone_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                texture = textures->object.stairs_above_rock_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            texture = textures->object.stairs_above_metal_on_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               texture = textures->object.stairs_above_metal_outline; break;

        case OBJECT_TYPE__STATION_FIST_HAND:                texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_HOOK_HAND:                texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_CHAIN_HAND:               texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_SCISSOR_HAND:             texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_SPRING_LEG:               texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_STRIDER_LEG:              texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_TRACK_LEG:                texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_BOOT_LEG:                 texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_MINIBOT_TORSO:            texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_WINGS_TORSO:              texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_MANIPULATION_HEAD:        texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_TELEPORTATION_HEAD:       texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_TAKEN:                    texture = textures->object.station_outline; break;

        default: break;
    }

    return texture;
}

Texture* get_texture_2_outline_from_object(Object* object, Textures* textures)
{
    Texture* texture = 0;

    switch(object->type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        texture = textures->object.wall_rock_outline; break;

        case OBJECT_TYPE__WALL_STONE:                       texture = textures->object.wall_stone_outline; break;

        case OBJECT_TYPE__WALL_METAL:                       texture = textures->object.wall_metal_outline; break;

        case OBJECT_TYPE__WALL_GOLD:                       texture = textures->object.wall_gold_outline; break;

        case OBJECT_TYPE__EXIT_ROCK_UP:                     texture = textures->object.exit_rock_up_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_RIGHT:                  texture = textures->object.exit_rock_right_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_DOWN:                   texture = textures->object.exit_rock_down_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_LEFT:                   texture = textures->object.exit_rock_left_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_UP:             texture = textures->object.exit_rock_up_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT:          texture = textures->object.exit_rock_right_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_DOWN:           texture = textures->object.exit_rock_down_outline; break;
        case OBJECT_TYPE__EXIT_ROCK_BLOCKED_LEFT:           texture = textures->object.exit_rock_left_outline; break;

        case OBJECT_TYPE__EXIT_STONE_UP:                    texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_RIGHT:                 texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_DOWN:                  texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_LEFT:                  texture = textures->object.exit_stone_left_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_UP:            texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_RIGHT:         texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_DOWN:          texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_BLOCKED_LEFT:          texture = textures->object.exit_stone_left_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_UP:            texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_RIGHT:         texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_DOWN:          texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_POWERED_LEFT:          texture = textures->object.exit_stone_left_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_UP:          texture = textures->object.exit_stone_up_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT:       texture = textures->object.exit_stone_right_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_DOWN:        texture = textures->object.exit_stone_down_outline; break;
        case OBJECT_TYPE__EXIT_STONE_UNPOWERED_LEFT:        texture = textures->object.exit_stone_left_outline; break;

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_UP:                 texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_RIGHT:              texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_DOWN:               texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_ON_LEFT:               texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_UP:                texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_RIGHT:             texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_DOWN:              texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_OFF_LEFT:              texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_left_outline; break;

        case OBJECT_TYPE__EXIT_GOLD_LOCKED_UP:              texture = textures->object.exit_gold_up_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_RIGHT:           texture = textures->object.exit_gold_right_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_DOWN:            texture = textures->object.exit_gold_down_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_LOCKED_LEFT:            texture = textures->object.exit_gold_left_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_UP:            texture = textures->object.exit_gold_up_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_RIGHT:         texture = textures->object.exit_gold_right_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_DOWN:          texture = textures->object.exit_gold_down_outline; break;
        case OBJECT_TYPE__EXIT_GOLD_UNLOCKED_LEFT:          texture = textures->object.exit_gold_left_outline; break;

        case OBJECT_TYPE__STALACTITE:                       texture = textures->object.stalactite_outline; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                texture = textures->object.stalactite_fallen_outline; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           texture = textures->object.stalactite_fallen_item_outline; break;

        case OBJECT_TYPE__STALAGMITE:                       texture = textures->object.stalagmite_outline; break;

        case OBJECT_TYPE__STALAGNATE:                       texture = textures->object.stalagnate_outline; break;

        case OBJECT_TYPE__PILLAR:                           texture = textures->object.pillar_outline; break;

        case OBJECT_TYPE__PIPE:                             texture = textures->object.pipe_outline; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock_outline; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal_outline; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass_outline; break;

        case OBJECT_TYPE__CRATE_GEMSTONE:                   texture = textures->object.crate_gemstone_outline; break;
        case OBJECT_TYPE__CRATE_GEMSTONE_ITEM:              texture = textures->object.crate_gemstone_item_outline; break;

        case OBJECT_TYPE__CRATE_CELL:                       texture = textures->object.crate_cell_outline; break;
        case OBJECT_TYPE__CRATE_CELL_ITEM:                  texture = textures->object.crate_cell_item_outline; break;

        case OBJECT_TYPE__CRATE_DYNAMITE:                   texture = textures->object.crate_dynamite_outline; break;
        case OBJECT_TYPE__CRATE_DYNAMITE_ITEM:              texture = textures->object.crate_dynamite_item_outline; break;

        case OBJECT_TYPE__ROCK:                             texture = textures->object.rock_outline; break;
        case OBJECT_TYPE__ROCK_DAMAGED:                     texture = textures->object.rock_damaged_outline; break;
        case OBJECT_TYPE__ROCK_DAMAGED_ITEM:                texture = textures->object.rock_damaged_item_outline; break;

        case OBJECT_TYPE__SAFE:                             texture = textures->object.safe_outline; break;
        case OBJECT_TYPE__SAFE_DAMAGED:                     texture = textures->object.safe_damaged_outline; break;
        case OBJECT_TYPE__SAFE_DAMAGED_ITEM:                texture = textures->object.safe_damaged_item_outline; break;

        case OBJECT_TYPE__DISPLAY:                          texture = textures->object.display_outline; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED:                  texture = textures->object.display_damaged_outline; break;
        case OBJECT_TYPE__DISPLAY_DAMAGED_ITEM:             texture = textures->object.display_damaged_item_outline; break;

        case OBJECT_TYPE__VENDING_CELL:                     texture = textures->object.vending_cell_outline; break;
        case OBJECT_TYPE__VENDING_CELL_ITEM:                texture = textures->object.vending_cell_item_outline; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED:             texture = textures->object.vending_cell_damaged_outline; break;
        case OBJECT_TYPE__VENDING_CELL_DAMAGED_ITEM:        texture = textures->object.vending_cell_damaged_item_outline; break;

        case OBJECT_TYPE__VENDING_DYNAMITE:                 texture = textures->object.vending_dynamite_outline; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_ITEM:            texture = textures->object.vending_dynamite_item_outline; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED:         texture = textures->object.vending_dynamite_damaged_outline; break;
        case OBJECT_TYPE__VENDING_DYNAMITE_DAMAGED_ITEM:    texture = textures->object.vending_dynamite_damaged_item_outline; break;

        case OBJECT_TYPE__BARREL:                           texture = textures->object.barrel_outline; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston_outline; break;
        case OBJECT_TYPE__PISTON_CELL:                      texture = textures->object.piston_cell_outline; break;
        case OBJECT_TYPE__PISTON_DYNAMITE:                  texture = textures->object.piston_dynamite_outline; break;
        case OBJECT_TYPE__PISTON_BARREL:                    texture = textures->object.piston_barrel_outline; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball_outline; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes_outline; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_outline_2; break;
        case OBJECT_TYPE__HERO_FLOATING:                    texture = textures->object.hero_floating_outline_2; break;
        case OBJECT_TYPE__HERO_FLYING:                      texture = textures->object.hero_flying_outline_2; break;
        case OBJECT_TYPE__MINIBOT:                          texture = textures->object.minibot_outline_2; break;

        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_outline_2; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_outline_2; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_outline_2; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_outline_2; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_outline_2; break;

        case OBJECT_TYPE__TURRET_LASER_GROUNDED:            texture = textures->object.turret_laser_grounded_outline_1; break;
        case OBJECT_TYPE__TURRET_LASER_STANDING:            texture = textures->object.turret_laser_standing_outline_1; break;
        case OBJECT_TYPE__TURRET_LASER_UNDEPLOYED:          texture = textures->object.turret_laser_undeployed_outline_1; break;
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:            texture = textures->object.turret_laser_deployed_outline_1; break;

        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:             texture = textures->object.turret_bomb_grounded_outline_1; break;
        case OBJECT_TYPE__TURRET_BOMB_STANDING:             texture = textures->object.turret_bomb_standing_outline_1; break;
        case OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED:           texture = textures->object.turret_bomb_undeployed_outline_1; break;
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:             texture = textures->object.turret_bomb_deployed_outline_1; break;

        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:       texture = textures->object.turret_projectile_grounded_outline_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:       texture = textures->object.turret_projectile_standing_outline_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED:     texture = textures->object.turret_projectile_undeployed_outline_1; break;
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:       texture = textures->object.turret_projectile_deployed_outline_1; break;

        case OBJECT_TYPE__STAIRS_ABOVE_STONE_POWERED:       texture = textures->object.stairs_above_stone_powered_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_STONE:               texture = textures->object.stairs_above_stone_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_ROCK:                texture = textures->object.stairs_above_rock_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL_ON:            texture = textures->object.stairs_above_metal_on_outline; break;
        case OBJECT_TYPE__STAIRS_ABOVE_METAL:               texture = textures->object.stairs_above_metal_outline; break;

        case OBJECT_TYPE__STATION_FIST_HAND:                texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_HOOK_HAND:                texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_CHAIN_HAND:               texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_SCISSOR_HAND:             texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_SPRING_LEG:               texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_STRIDER_LEG:              texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_TRACK_LEG:                texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_BOOT_LEG:                 texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_MINIBOT_TORSO:            texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_WINGS_TORSO:              texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_MANIPULATION_HEAD:        texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_TELEPORTATION_HEAD:       texture = textures->object.station_outline; break;
        case OBJECT_TYPE__STATION_TAKEN:                    texture = textures->object.station_outline; break;

        default: break;
    }

    return texture;
}
