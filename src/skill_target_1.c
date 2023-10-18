#include "../inc/state.h"

void skill_add_pos_to_possible_target_1_tilemap_pos_list(State* state, int skill, vec2i source_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);

    switch(skill)
    {
        case SKILL__CHARGE:
        {
            //
        }
        break;
        case SKILL__FLY:
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
        {
            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
        }
        break;
        case SKILL__PUSH:
        {
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, 1));
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, 1));
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, 1));
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, 1));
        }
        break;
        case SKILL__PULL:
        {
            for(int i = 1; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

            for(int i = 1; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

            for(int i = 1; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

            for(int i = 1; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

            for(int i = 0; i < 5; i++)
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
        }
        break;
        case SKILL__THROW:
        {
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, 1));
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, 1));
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, 1));
            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, 1));
        }
        break;
        default:
        break;
    }
}
