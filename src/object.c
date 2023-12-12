#include "../inc/object.h"

#include "../inc/action.h"
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

        case OBJECT_TYPE__STALACTITE:                       is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 0; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 0; break;

        case OBJECT_TYPE__PILLAR:                           is = 0; break;
        case OBJECT_TYPE__PILLAR_SPIKES:                    is = 0; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 0; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 0; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 0; break;

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

        case OBJECT_TYPE__SPRING:                           is = 0; break;

        case OBJECT_TYPE__WEIGHT:                           is = 0; break;

        case OBJECT_TYPE__HERO:                             is = 0; break;
        case OBJECT_TYPE__GOAT:                             is = 0; break;
        case OBJECT_TYPE__SPIDER:                           is = 0; break;
        case OBJECT_TYPE__BULL:                             is = 0; break;
        case OBJECT_TYPE__FLY:                              is = 1; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 0; break;

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

        case OBJECT_TYPE__STALACTITE:                       is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 0; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 0; break;

        case OBJECT_TYPE__PILLAR:                           is = 1; break;
        case OBJECT_TYPE__PILLAR_SPIKES:                    is = 1; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 0; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 0; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 0; break;

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

        case OBJECT_TYPE__SPRING:                           is = 1; break;

        case OBJECT_TYPE__WEIGHT:                           is = 0; break;

        case OBJECT_TYPE__HERO:                             is = 0; break;
        case OBJECT_TYPE__GOAT:                             is = 0; break;
        case OBJECT_TYPE__SPIDER:                           is = 0; break;
        case OBJECT_TYPE__BULL:                             is = 0; break;
        case OBJECT_TYPE__FLY:                              is = 0; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 0; break;

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

        case OBJECT_TYPE__STALACTITE:                       is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                is = 0; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           is = 0; break;

        case OBJECT_TYPE__STALAGMITE:                       is = 0; break;

        case OBJECT_TYPE__STALAGNATE:                       is = 0; break;

        case OBJECT_TYPE__PILLAR:                           is = 1; break;
        case OBJECT_TYPE__PILLAR_SPIKES:                    is = 1; break;

        case OBJECT_TYPE__COVER_ROCK:                       is = 1; break;
        case OBJECT_TYPE__COVER_METAL:                      is = 1; break;
        case OBJECT_TYPE__COVER_GLASS:                      is = 1; break;

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

        case OBJECT_TYPE__SPRING:                           is = 1; break;

        case OBJECT_TYPE__WEIGHT:                           is = 1; break;

        case OBJECT_TYPE__HERO:                             is = 1; break;
        case OBJECT_TYPE__GOAT:                             is = 1; break;
        case OBJECT_TYPE__SPIDER:                           is = 1; break;
        case OBJECT_TYPE__BULL:                             is = 1; break;
        case OBJECT_TYPE__FLY:                              is = 1; break;
        case OBJECT_TYPE__CHAMELEON:                        is = 1; break;

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

        case OBJECT_TYPE__STALACTITE:                       name = "stalactite"; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                name = "stalactite fallen"; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           name = "stalactite fallen item"; break;

        case OBJECT_TYPE__STALAGMITE:                       name = "stalagmite"; break;

        case OBJECT_TYPE__STALAGNATE:                       name = "stalagnate"; break;

        case OBJECT_TYPE__PILLAR:                           name = "pillar"; break;
        case OBJECT_TYPE__PILLAR_SPIKES:                    name = "pillar spikes"; break;

        case OBJECT_TYPE__COVER_ROCK:                       name = "cover rock"; break;
        case OBJECT_TYPE__COVER_METAL:                      name = "cover metal"; break;
        case OBJECT_TYPE__COVER_GLASS:                      name = "cover glass"; break;

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

        case OBJECT_TYPE__SPRING:                           name = "spring"; break;

        case OBJECT_TYPE__WEIGHT:                           name = "weight"; break;

        case OBJECT_TYPE__HERO:                             name = "hero"; break;
        case OBJECT_TYPE__GOAT:                             name = "goat"; break;
        case OBJECT_TYPE__SPIDER:                           name = "spider"; break;
        case OBJECT_TYPE__BULL:                             name = "bull"; break;
        case OBJECT_TYPE__FLY:                              name = "fly"; break;
        case OBJECT_TYPE__CHAMELEON:                        name = "chameleon"; break;

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

        case OBJECT_TYPE__STALACTITE:                       texture = textures->object.stalactite; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                texture = textures->object.stalactite_fallen; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           texture = textures->object.stalactite_fallen_item; break;

        case OBJECT_TYPE__STALAGMITE:                       texture = textures->object.stalagmite; break;

        case OBJECT_TYPE__STALAGNATE:                       texture = textures->object.stalagnate; break;

        case OBJECT_TYPE__PILLAR:                           texture = textures->object.pillar; break;
        case OBJECT_TYPE__PILLAR_SPIKES:                    texture = textures->object.pillar_spikes; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass; break;

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

        case OBJECT_TYPE__SPRING:                           texture = textures->object.spring; break;

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_1; break;
        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_1; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_1; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_1; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_1; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_1; break;

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

        case OBJECT_TYPE__STALACTITE:                       texture = textures->object.stalactite; break;
        case OBJECT_TYPE__STALACTITE_FALLEN:                texture = textures->object.stalactite_fallen; break;
        case OBJECT_TYPE__STALACTITE_FALLEN_ITEM:           texture = textures->object.stalactite_fallen_item; break;

        case OBJECT_TYPE__STALAGMITE:                       texture = textures->object.stalagmite; break;

        case OBJECT_TYPE__STALAGNATE:                       texture = textures->object.stalagnate; break;

        case OBJECT_TYPE__PILLAR:                           texture = textures->object.pillar; break;
        case OBJECT_TYPE__PILLAR_SPIKES:                    texture = textures->object.pillar_spikes; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass; break;

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

        case OBJECT_TYPE__SPRING:                           texture = textures->object.spring; break;

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_2; break;
        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_2; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_2; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_2; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_2; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_2; break;

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
        case OBJECT_TYPE__PILLAR_SPIKES:                    texture = textures->object.pillar_spikes_outline; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock_outline; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal_outline; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass_outline; break;

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

        case OBJECT_TYPE__SPRING:                           texture = textures->object.spring_outline; break;

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight_outline; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_outline_1; break;
        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_outline_1; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_outline_1; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_outline_1; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_outline_1; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_outline_1; break;

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
        case OBJECT_TYPE__PILLAR_SPIKES:                    texture = textures->object.pillar_spikes_outline; break;

        case OBJECT_TYPE__COVER_ROCK:                       texture = textures->object.cover_rock_outline; break;
        case OBJECT_TYPE__COVER_METAL:                      texture = textures->object.cover_metal_outline; break;
        case OBJECT_TYPE__COVER_GLASS:                      texture = textures->object.cover_glass_outline; break;

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

        case OBJECT_TYPE__SPRING:                           texture = textures->object.spring_outline; break;

        case OBJECT_TYPE__WEIGHT:                           texture = textures->object.weight_outline; break;

        case OBJECT_TYPE__HERO:                             texture = textures->object.hero_outline_2; break;
        case OBJECT_TYPE__GOAT:                             texture = textures->object.goat_outline_2; break;
        case OBJECT_TYPE__SPIDER:                           texture = textures->object.spider_outline_2; break;
        case OBJECT_TYPE__BULL:                             texture = textures->object.bull_outline_2; break;
        case OBJECT_TYPE__FLY:                              texture = textures->object.fly_outline_2; break;
        case OBJECT_TYPE__CHAMELEON:                        texture = textures->object.chameleon_outline_2; break;

        default: break;
    }

    return texture;
}
