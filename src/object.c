#include "../inc/object.h"

#include "../inc/action.h"
#include "../inc/skill.h"
#include "../inc/item.h"

Object* new_object(int type)
{
    Object* object = malloc(sizeof(*object));

    object->is_visible = 1;
    object->is_dead = 0;
    object->type = type;
    object->tilemap_pos = vec2i(0,0);

    object->is_exit = 0;
    object->exit.to_tilemap_pos = vec2i(0,0);

    object->is_container = 0;
    object->container.item_1 = ITEM__NONE;
    object->container.item_2 = ITEM__NONE;
    object->container.item_3 = ITEM__NONE;

    object->is_enemy = 0;
    object->enemy.action_sequence = new_action_sequence();
    object->enemy.performed_attack = 0;
    object->enemy.order_number = 0;
    object->enemy.attack_dir4 = DIR4__RIGHT;

    object->enemy.action_sequence = new_action_sequence();
    object->enemy.target_1_tilemap_pos = vec2i(0, 0);
    object->enemy.target_2_tilemap_pos = vec2i(0, 0);
    object->enemy.skill = SKILL__NONE;
    object->enemy.attack_dir4 = DIR4__NONE;
    object->enemy.performed_attack = 0;
    object->enemy.order_number = 0;

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

        case OBJECT_TYPE__BARREL:                           is = 0; break;

        case OBJECT_TYPE__WEIGHT:                           is = 0; break;

        case OBJECT_TYPE__PISTON:                           is = 0; break;

        case OBJECT_TYPE__BALL:                             is = 0; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 0; break;

        case OBJECT_TYPE__HERO:                             is = 0; break;
        case OBJECT_TYPE__GOAT:                             is = 0; break;
        case OBJECT_TYPE__SPIDER:                           is = 0; break;
        case OBJECT_TYPE__BULL:                             is = 0; break;
        case OBJECT_TYPE__FLY:                              is = 1; break;
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

        default: break;
    }

    return is;
}

int is_object_interactable(Object* object)
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

        case OBJECT_TYPE__WEIGHT:                           is = 0; break;

        case OBJECT_TYPE__PISTON:                           is = 1; break;

        case OBJECT_TYPE__BALL:                             is = 1; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 1; break;

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

        case OBJECT_TYPE__WEIGHT:                           is = 1; break;

        case OBJECT_TYPE__PISTON:                           is = 0; break;

        case OBJECT_TYPE__BALL:                             is = 1; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 1; break;

        case OBJECT_TYPE__HERO:                             is = 1; break;
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

        case OBJECT_TYPE__WEIGHT:                           is = 1; break;

        case OBJECT_TYPE__PISTON:                           is = 1; break;

        case OBJECT_TYPE__BALL:                             is = 1; break;
        case OBJECT_TYPE__BALL_SPIKES:                      is = 1; break;

        case OBJECT_TYPE__HERO:                             is = 1; break;
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

        case OBJECT_TYPE__WEIGHT:                           is = 0; break;

        case OBJECT_TYPE__PISTON:                           is = 0; break;

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

        default: break;
    }

    return is;
}

int get_object_item_type(Object* object)
{
    int item_type = ITEM__NONE;

    switch(object->type)
    {
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

        case OBJECT_TYPE__WEIGHT:                           item_type = ITEM__NONE; break;

        case OBJECT_TYPE__PISTON:                           item_type = ITEM__NONE; break;

        case OBJECT_TYPE__BALL:                             item_type = ITEM__NONE; break;
        case OBJECT_TYPE__BALL_SPIKES:                      item_type = ITEM__NONE; break;

        default: break;
    }

    return item_type;
}

int get_object_item_count(Object* object)
{
    int count = 0;

    switch(object->type)
    {
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

        case OBJECT_TYPE__WEIGHT:                           count = 0; break;

        case OBJECT_TYPE__PISTON:                           count = 0; break;

        case OBJECT_TYPE__BALL:                             count = 0; break;
        case OBJECT_TYPE__BALL_SPIKES:                      count = 0; break;

        default: break;
    }

    return count;
}

char* get_name_from_object_type(int object_type)
{
    char* name = "";

    switch(object_type)
    {
        case OBJECT_TYPE__WALL_ROCK:                        name = "wall rock"; break;

        case OBJECT_TYPE__WALL_STONE:                       name = "wall stone"; break;

        case OBJECT_TYPE__WALL_METAL:                       name = "wall metal"; break;

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

        case OBJECT_TYPE__EXIT_METAL_UP:                    name = "exit metal up"; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 name = "exit metal right"; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  name = "exit metal down"; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  name = "exit metal left"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            name = "exit metal blocked up"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         name = "exit metal blocked right"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          name = "exit metal blocked down"; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          name = "exit metal blocked left"; break;

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

        case OBJECT_TYPE__WEIGHT:                           name = "weight"; break;

        case OBJECT_TYPE__PISTON:                           name = "piston"; break;

        case OBJECT_TYPE__BALL:                             name = "ball"; break;
        case OBJECT_TYPE__BALL_SPIKES:                      name = "ball spikes"; break;

        case OBJECT_TYPE__HERO:                             name = "hero"; break;
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

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_blocked_up; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_blocked_right; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_blocked_down; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_blocked_left; break;

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

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_1; break;
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

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_blocked_up; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_blocked_right; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_blocked_down; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_blocked_left; break;

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

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_2; break;
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

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_left_outline; break;

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

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight_outline; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston_outline; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball_outline; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes_outline; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_outline_1; break;
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

        case OBJECT_TYPE__EXIT_METAL_UP:                    texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_RIGHT:                 texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_DOWN:                  texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_LEFT:                  texture = textures->object.exit_metal_left_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_UP:            texture = textures->object.exit_metal_up_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT:         texture = textures->object.exit_metal_right_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_DOWN:          texture = textures->object.exit_metal_down_outline; break;
        case OBJECT_TYPE__EXIT_METAL_BLOCKED_LEFT:          texture = textures->object.exit_metal_left_outline; break;

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

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight_outline; break;

        case OBJECT_TYPE__PISTON:                           texture = textures->object.piston_outline; break;

        case OBJECT_TYPE__BALL:                             texture = textures->object.ball_outline; break;
        case OBJECT_TYPE__BALL_SPIKES:                      texture = textures->object.ball_spikes_outline; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_outline_2; break;
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

        default: break;
    }

    return texture;
}
