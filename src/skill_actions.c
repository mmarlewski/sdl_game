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
                add_action_to_end_action_sequence(action_sequence, new_action_move_ground(source_object,source_object_tilemap_pos,move_distance_info.dir4));
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
                add_action_to_end_action_sequence(action_sequence, new_action_move_air(source_object,source_object_tilemap_pos,move_distance_info.dir4));
                source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
            }
        }
        break;
        case SKILL__JUMP:
        {
            if(!target_2_object)
            {
                DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

                add_action_to_end_action_sequence(action_sequence, new_action_throw(source_object, source_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
            }
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            vec2i source_object_tilemap_pos = source_object->tilemap_pos;
            for(int i = 0; i < move_distance_info.abs_diff - 1; i++)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_move_ground(source_object,source_object_tilemap_pos,move_distance_info.dir4));
                source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
            }

            if(target_1_object)
            {
                DistanceInfo push_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                if(is_object_flying(target_1_object->type))
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < push_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_air(target_1_object,target_1_object_tilemap_pos,push_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, push_distance_info.dir4, 1);
                    }
                }
                else
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < push_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_ground(target_1_object,target_1_object_tilemap_pos,push_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, push_distance_info.dir4, 1);
                    }
                }
            }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            vec2i source_object_tilemap_pos = source_object->tilemap_pos;
            for(int i = 0; i < move_distance_info.abs_diff - 1; i++)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_move_ground(source_object,source_object_tilemap_pos,move_distance_info.dir4));
                source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
            }

            if(target_1_object)
            {
                DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                if(!target_2_object)
                {
                    DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                    add_action_to_end_action_sequence(action_sequence, new_action_throw(target_1_object, target_1_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
                }
            }
        }
        break;
        case SKILL__PUSH:
        {
            if(target_1_object)
            {
                DistanceInfo push_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                if(is_object_flying(target_1_object->type))
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < push_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_air(target_1_object,target_1_object_tilemap_pos,push_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, push_distance_info.dir4, 1);
                    }
                }
                else
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < push_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_ground(target_1_object,target_1_object_tilemap_pos,push_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, push_distance_info.dir4, 1);
                    }
                }
            }
        }
        break;
        case SKILL__PULL:
        {
            if(target_1_object)
            {
                DistanceInfo pull_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                if(is_object_flying(target_1_object->type))
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < pull_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_air(target_1_object,target_1_object_tilemap_pos,pull_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, pull_distance_info.dir4, 1);
                    }
                }
                else
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < pull_distance_info.abs_diff; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_ground(target_1_object,target_1_object_tilemap_pos,pull_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, pull_distance_info.dir4, 1);
                    }
                }
            }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            if(target_1_object)
            {
                DistanceInfo pull_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, source_tilemap_pos);

                if(is_object_flying(target_1_object->type))
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < pull_distance_info.abs_diff - 1; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_air(target_1_object,target_1_object_tilemap_pos,pull_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, pull_distance_info.dir4, 1);
                    }
                }
                else
                {
                    vec2i target_1_object_tilemap_pos = target_1_object->tilemap_pos;
                    for(int i = 0; i < pull_distance_info.abs_diff - 1; i++)
                    {
                        add_action_to_end_action_sequence(action_sequence, new_action_move_ground(target_1_object,target_1_object_tilemap_pos,pull_distance_info.dir4));
                        target_1_object_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_object_tilemap_pos, pull_distance_info.dir4, 1);
                    }
                }

                if(!target_2_object)
                {
                    vec2i before_source_tilemap_pos = make_vec2i_move_in_dir4_by(source_tilemap_pos, pull_distance_info.dir4, -1);

                    DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(before_source_tilemap_pos, target_2_tilemap_pos);

                    add_action_to_end_action_sequence(action_sequence, new_action_throw(target_1_object, before_source_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
                }
            }
        }
        break;
        case SKILL__THROW:
        {
            if(target_1_object && !target_2_object)
            {
                DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                add_action_to_end_action_sequence(action_sequence, new_action_throw(target_1_object, target_1_tilemap_pos, throw_distance_info.dir4, throw_distance_info.abs_diff));
            }
        }
        break;
        default:
        break;
    }
}
