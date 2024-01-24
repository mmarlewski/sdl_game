#include "../inc/state.h"

void skill_add_pos_to_possible_target_1_tilemap_pos_list(State* state, int skill, Vec2i source_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);

    switch(skill)
    {
        case SKILL__HERO_PICK_ITEM_CLOSE:
        {
            //
        }
        break;
        case SKILL__HERO_PICK_ITEM_FAR:
        {
            //
        }
        break;
        case SKILL__HERO_PUT_ITEM_CLOSE:
        {
            //
        }
        break;
        case SKILL__HERO_PUT_ITEM_FAR:
        {
            //
        }
        break;
        case SKILL__HERO_MOVE:
        {
            //
        }
        break;
        case SKILL__HERO_INTERACT:
        {
            //
        }
        break;
        case SKILL__HERO_THROW_CELL:
        {
            //
        }
        break;
        case SKILL__HERO_THROW_DYNAMITE:
        {
            //
        }
        break;
        case SKILL__HERO_THROW_GEMSTONE:
        {
            //
        }
        break;
        case SKILL__CHARGE:
        {
            //
        }
        break;
        case SKILL__JUMP:
        {
            //
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        case SKILL__CHARGE_AND_THROW:
        case SKILL__PULL:
        case SKILL__PULL_AND_THROW:
        {
            int is_up_target = 0;
            int is_right_target = 0;
            int is_down_target = 0;
            int is_left_target = 0;

            Vec2i up_tilemap_pos = source_tilemap_pos;
            Vec2i right_tilemap_pos = source_tilemap_pos;
            Vec2i down_tilemap_pos = source_tilemap_pos;
            Vec2i left_tilemap_pos = source_tilemap_pos;

            int up_floor = 0;
            int right_floor = 0;
            int down_floor = 0;
            int left_floor = 0;

            Object* up_object = 0;
            Object* right_object = 0;
            Object* down_object = 0;
            Object* left_object = 0;

            for(int i = 1; i < 10; i++)
            {
                if(!is_up_target)
                {
                    up_tilemap_pos = vec2i_move_in_dir4_by(up_tilemap_pos, DIR4__UP, 1);
                    up_floor = get_floor_on_tilemap_pos(state, up_tilemap_pos);
                    up_object = get_object_on_tilemap_pos(state, up_tilemap_pos);
                    if(up_object != 0) is_up_target = 1;
                }

                if(!is_right_target)
                {
                    right_tilemap_pos = vec2i_move_in_dir4_by(right_tilemap_pos, DIR4__RIGHT, 1);
                    right_floor = get_floor_on_tilemap_pos(state, up_tilemap_pos);
                    right_object = get_object_on_tilemap_pos(state, right_tilemap_pos);
                    if(right_object != 0) is_right_target = 1;
                }

                if(!is_down_target)
                {
                    down_tilemap_pos = vec2i_move_in_dir4_by(down_tilemap_pos, DIR4__DOWN, 1);
                    down_floor = get_floor_on_tilemap_pos(state, down_tilemap_pos);
                    down_object = get_object_on_tilemap_pos(state, down_tilemap_pos);
                    if(down_object != 0) is_down_target = 1;
                }

                if(!is_left_target)
                {
                    left_tilemap_pos = vec2i_move_in_dir4_by(left_tilemap_pos, DIR4__LEFT, 1);
                    left_floor = get_floor_on_tilemap_pos(state, left_tilemap_pos);
                    left_object = get_object_on_tilemap_pos(state, left_tilemap_pos);
                    if(left_object != 0) is_left_target = 1;
                }
            }

            if(is_up_target) add_pos_to_possible_target_1_tilemap_pos_list(state, up_tilemap_pos);
            if(is_right_target) add_pos_to_possible_target_1_tilemap_pos_list(state, right_tilemap_pos);
            if(is_down_target) add_pos_to_possible_target_1_tilemap_pos_list(state, down_tilemap_pos);
            if(is_left_target) add_pos_to_possible_target_1_tilemap_pos_list(state, left_tilemap_pos);
        }
        break;
        case SKILL__PUSH:
        case SKILL__THROW:
        {
            Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, 1);
            if(get_object_on_tilemap_pos(state, up_tilemap_pos) != 0)
            {
                add_pos_to_possible_target_1_tilemap_pos_list(state, up_tilemap_pos);
            }

            Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, 1);
            if(get_object_on_tilemap_pos(state, right_tilemap_pos) != 0)
            {
                add_pos_to_possible_target_1_tilemap_pos_list(state, right_tilemap_pos);
            }

            Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, 1);
            if(get_object_on_tilemap_pos(state, down_tilemap_pos) != 0)
            {
                add_pos_to_possible_target_1_tilemap_pos_list(state, down_tilemap_pos);
            }

            Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, 1);
            if(get_object_on_tilemap_pos(state, left_tilemap_pos) != 0)
            {
                add_pos_to_possible_target_1_tilemap_pos_list(state, left_tilemap_pos);
            }
        }
        break;
        case SKILL__TURRET_LASER:
        {
            //
        }
        case SKILL__TURRET_BOMB:
        {
            //
        }
        case SKILL__TURRET_PROJECTILE:
        {
            //
        }
        break;
        default:
        break;
    }
}
