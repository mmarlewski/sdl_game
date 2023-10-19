#include "../inc/state.h"

void skill_add_actions_to_action_sequence(State* state, Action* action_sequence, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos, vec2i target_2_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
    Object* target_2_object = get_object_on_tilemap_pos(state, target_2_tilemap_pos);

    switch(skill)
    {
        case SKILL__CHARGE:
        {
            DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

            vec2i source_object_tilemap_pos = source_object->tilemap_pos;
            for(int i = 0; i < move_distance_info.abs_diff; i++)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_move(source_object_tilemap_pos,move_distance_info.dir4));
                source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
            }
        }
        break;
        case SKILL__FLY:
        {
            DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

            vec2i source_object_tilemap_pos = source_object->tilemap_pos;
            for(int i = 0; i < move_distance_info.abs_diff; i++)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_move(source_object_tilemap_pos,move_distance_info.dir4));
                source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
            }
        }
        break;
        case SKILL__JUMP:
        {
                DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

                add_action_to_end_action_sequence(action_sequence, new_action_throw( source_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            vec2i source_object_tilemap_pos = source_object->tilemap_pos;
            for(int i = 0; i < move_distance_info.abs_diff - 1; i++)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_move(source_object_tilemap_pos,move_distance_info.dir4));
                source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
            }

            DistanceInfo push_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                vec2i tilemap_pos = target_1_tilemap_pos;
                for(int i = 0; i < push_distance_info.abs_diff; i++)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(tilemap_pos,push_distance_info.dir4));
                    tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, push_distance_info.dir4, 1);
                }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            vec2i source_object_tilemap_pos = source_object->tilemap_pos;
            for(int i = 0; i < move_distance_info.abs_diff - 1; i++)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_move(source_object_tilemap_pos,move_distance_info.dir4));
                source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
            }

                DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                add_action_to_end_action_sequence(action_sequence, new_action_throw( target_1_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
        }
        break;
        case SKILL__PUSH:
        {
                DistanceInfo push_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                    vec2i tilemap_pos = target_1_tilemap_pos;
                    for(int i = 0; i < push_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move(tilemap_pos,push_distance_info.dir4));
                        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, push_distance_info.dir4, 1);
                    }
        }
        break;
        case SKILL__PULL:
        {
                DistanceInfo pull_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                    vec2i tilemap_pos = target_1_tilemap_pos;
                    for(int i = 0; i < pull_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move(tilemap_pos,pull_distance_info.dir4));
                        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, pull_distance_info.dir4, 1);
                    }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
                DistanceInfo pull_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, source_tilemap_pos);

                    vec2i tilemap_pos = target_1_tilemap_pos;
                    for(int i = 0; i < pull_distance_info.abs_diff - 1; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move(tilemap_pos,pull_distance_info.dir4));
                        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, pull_distance_info.dir4, 1);
                    }

                    vec2i before_source_tilemap_pos = make_vec2i_move_in_dir4_by(source_tilemap_pos, pull_distance_info.dir4, -1);

                    DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(before_source_tilemap_pos, target_2_tilemap_pos);

                    add_action_to_end_action_sequence(action_sequence, new_action_throw( before_source_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
        }
        break;
        case SKILL__THROW:
        {
                DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                add_action_to_end_action_sequence(action_sequence, new_action_throw( target_1_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
        }
        break;
        default:
        break;
    }
}
