#include "../inc/state.h"

void skill_add_pos_to_possible_target_2_tilemap_pos_list(State* state, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);

    switch(skill)
    {
        case SKILL__CHARGE:
        {
            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
        }
        break;
        case SKILL__FLY:
        {
            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
        }
        break;
        case SKILL__JUMP:
        {
            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            for(int i = 0; i < 5; i++)
            {
                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, distance_info.dir4, i+1));
            }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            for(int i = 0; i < 5; i++)
            {
                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, distance_info.dir4, i+1));
            }
        }
        break;
        case SKILL__PUSH:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            for(int i = 0; i < 5; i++)
            {
                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, distance_info.dir4, i+1));
            }
        }
        break;
        case SKILL__PULL:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            for(int i = 1; i < distance_info.abs_diff; i++)
            {
                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, distance_info.dir4, -i));
            }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            for(int i = 1; i < 5; i++)
            {
                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, distance_info.dir4, -i));
            }
        }
        break;
        case SKILL__THROW:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            for(int i = 0; i < 5; i++)
            {
                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, distance_info.dir4, i+1));
            }
        }
        break;
        default:
        break;
    }
}
