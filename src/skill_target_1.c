#include "../inc/state.h"

void skill_get_possible_target_1_pos(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    List* target_1_pos_list
)
{
    Object* source_object = room_get_object_at(state->curr_room, source_tilemap_pos);

    switch(skill)
    {
        case SKILL__PICK_ITEM_CLOSE:
        {
            //
        }
        break;
        case SKILL__PICK_ITEM_FAR:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_CLOSE:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_FAR:
        {
            //
        }
        break;
        case SKILL__MOVE:
        {
            //
        }
        break;
        case SKILL__MANIPULATION:
        {
            //
        }
        break;
        case SKILL__THROW_CELL:
        {
            //
        }
        break;
        case SKILL__THROW_DYNAMITE:
        {
            //
        }
        break;
        case SKILL__THROW_GEMSTONE:
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
                    up_floor = room_get_floor_at(state->curr_room, up_tilemap_pos);
                    up_object = room_get_object_at(state->curr_room, up_tilemap_pos);
                    if(up_object != 0) is_up_target = 1;
                }

                if(!is_right_target)
                {
                    right_tilemap_pos = vec2i_move_in_dir4_by(right_tilemap_pos, DIR4__RIGHT, 1);
                    right_floor = room_get_floor_at(state->curr_room, up_tilemap_pos);
                    right_object = room_get_object_at(state->curr_room, right_tilemap_pos);
                    if(right_object != 0) is_right_target = 1;
                }

                if(!is_down_target)
                {
                    down_tilemap_pos = vec2i_move_in_dir4_by(down_tilemap_pos, DIR4__DOWN, 1);
                    down_floor = room_get_floor_at(state->curr_room, down_tilemap_pos);
                    down_object = room_get_object_at(state->curr_room, down_tilemap_pos);
                    if(down_object != 0) is_down_target = 1;
                }

                if(!is_left_target)
                {
                    left_tilemap_pos = vec2i_move_in_dir4_by(left_tilemap_pos, DIR4__LEFT, 1);
                    left_floor = room_get_floor_at(state->curr_room, left_tilemap_pos);
                    left_object = room_get_object_at(state->curr_room, left_tilemap_pos);
                    if(left_object != 0) is_left_target = 1;
                }
            }

            if(is_up_target) add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(up_tilemap_pos));
            if(is_right_target) add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(right_tilemap_pos));
            if(is_down_target) add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(down_tilemap_pos));
            if(is_left_target) add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(left_tilemap_pos));
        }
        break;
        case SKILL__PUSH:
        case SKILL__THROW:
        {
            Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, 1);
            if(room_get_object_at(state->curr_room, up_tilemap_pos) != 0)
            {
                add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(up_tilemap_pos));
            }

            Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, 1);
            if(room_get_object_at(state->curr_room, right_tilemap_pos) != 0)
            {
                add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(right_tilemap_pos));
            }

            Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, 1);
            if(room_get_object_at(state->curr_room, down_tilemap_pos) != 0)
            {
                add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(down_tilemap_pos));
            }

            Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, 1);
            if(room_get_object_at(state->curr_room, left_tilemap_pos) != 0)
            {
                add_new_list_element_to_list_end(target_1_pos_list, new_vec2i_from_vec2i(left_tilemap_pos));
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
