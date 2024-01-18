#include "../inc/state.h"

void object_enemy_prepare_move(State* state, Object* object)
{
    if(object->type == OBJECT_TYPE__TURRET_LASER_GROUNDED ||
    object->type == OBJECT_TYPE__TURRET_LASER_STANDING ||
    object->type == OBJECT_TYPE__TURRET_LASER_UNDEPLOYED ||
    object->type == OBJECT_TYPE__TURRET_LASER_DEPLOYED ||
    object->type == OBJECT_TYPE__TURRET_BOMB_GROUNDED ||
    object->type == OBJECT_TYPE__TURRET_BOMB_STANDING ||
    object->type == OBJECT_TYPE__TURRET_BOMB_UNDEPLOYED ||
    object->type == OBJECT_TYPE__TURRET_BOMB_DEPLOYED ||
    object->type == OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED ||
    object->type == OBJECT_TYPE__TURRET_PROJECTILE_STANDING ||
    object->type == OBJECT_TYPE__TURRET_PROJECTILE_UNDEPLOYED ||
    object->type == OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED)
    {
        return;
    }

    Vec2i tilemap_pos_up = object->tilemap_pos;
    Object* object_up = 0;
    int distance_up = 0;

    Vec2i tilemap_pos_right = object->tilemap_pos;
    Object* object_right = 0;
    int distance_right = 0;

    Vec2i tilemap_pos_down = object->tilemap_pos;
    Object* object_down = 0;
    int distance_down = 0;

    Vec2i tilemap_pos_left = object->tilemap_pos;
    Object* object_left = 0;
    int distance_left = 0;

    for(int i = 0; i < 10; i++)
    {
        if(object_up == 0)
        {
            tilemap_pos_up = vec2i_move_in_dir4_by(tilemap_pos_up, DIR4__UP, 1);
            object_up = get_object_on_tilemap_pos(state, tilemap_pos_up);
            if(object_up != 0) distance_up = i;
        }

        if(object_right == 0)
        {
            tilemap_pos_right = vec2i_move_in_dir4_by(tilemap_pos_right, DIR4__RIGHT, 1);
            object_right = get_object_on_tilemap_pos(state, tilemap_pos_right);
            if(object_right != 0) distance_right = i;
        }

        if(object_down == 0)
        {
            tilemap_pos_down = vec2i_move_in_dir4_by(tilemap_pos_down, DIR4__DOWN, 1);
            object_down = get_object_on_tilemap_pos(state, tilemap_pos_down);
            if(object_down != 0) distance_down = i;
        }

        if(object_left == 0)
        {
            tilemap_pos_left = vec2i_move_in_dir4_by(tilemap_pos_left, DIR4__LEFT, 1);
            object_left = get_object_on_tilemap_pos(state, tilemap_pos_left);
            if(object_left != 0) distance_left = i;
        }
    }

    int min_distance = distance_up;
    int min_dir4 = DIR4__UP;

    if(distance_right < min_distance)
    {
        min_distance = distance_right;
        min_dir4 = DIR4__RIGHT;
    }
    if(distance_down < min_distance)
    {
        min_distance = distance_down;
        min_dir4 = DIR4__DOWN;
    }
    if(distance_left < min_distance)
    {
        min_distance = distance_left;
        min_dir4 = DIR4__LEFT;
    }

    int dir4 = DIR4__UP;
    int distance = 0;

    if(object_up != 0 || object_right != 0 || object_down != 0 || object_left != 0)
    {
        while(1)
        {
            int new_dir4 = rand() % 4 + 1;
            if(new_dir4 == DIR4__UP && object_up != 0)
            { dir4 = new_dir4; distance = distance_up; break; }
            if(new_dir4 == DIR4__RIGHT && object_right != 0)
            { dir4 = new_dir4; distance = distance_right; break; }
            if(new_dir4 == DIR4__DOWN && object_down != 0)
            { dir4 = new_dir4; distance = distance_down; break; }
            if(new_dir4 == DIR4__LEFT && object_left != 0)
            { dir4 = new_dir4; distance = distance_left; break; }
        }

        distance = fmin(distance, 5);
    }
    else
    {
        dir4 = rand() % 4 + 1;
        distance = rand() % 5 + 1;
    }

    Vec2i curr_tilemap_pos = object->tilemap_pos;
    Vec2i new_tilemap_pos = object->tilemap_pos;
    Object* new_tilemap_pos_object = 0;
    for(int i = 0; i < distance; i++)
    {
        new_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, dir4, 1);
        new_tilemap_pos_object = get_object_on_tilemap_pos(state, new_tilemap_pos);
        if(new_tilemap_pos_object == 0)
        {
            add_action_to_end_action_sequence(object->enemy.action_sequence, new_action_move(curr_tilemap_pos,dir4));
            curr_tilemap_pos = new_tilemap_pos;
        }
        else break;
    }
    object->enemy.attack_dir4 = dir4;

    switch(object->type)
    {
        case OBJECT_TYPE__GOAT:
        {
            //
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            //
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            //
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            //
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            //
        }
        break;
        default:
        break;
    }
}
