#include "../inc/state.h"

int is_skill_two_target(int skill)
{
    int is = 0;

    switch(skill)
    {
        case SKILL__CHARGE: is = 0; break;
        case SKILL__CHARGE_AND_PUSH: is = 1; break;
        case SKILL__CHARGE_AND_THROW: is = 1; break;
        case SKILL__JUMP: is = 0; break;
        case SKILL__PUSH: is = 1; break;
        case SKILL__PULL: is = 1; break;
        case SKILL__PULL_AND_THROW: is = 1; break;
        case SKILL__THROW: is = 1; break;
        default: break;
    }

    return is;
}

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

void skill_add_pos_to_possible_target_2_tilemap_pos_list(State* state, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);

    switch(state->gamemap.curr_skill)
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

void skill_add_actions_to_action_sequence(State* state, Action* action_sequence, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos, vec2i target_2_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
    Object* target_2_object = get_object_on_tilemap_pos(state, target_2_tilemap_pos);

    switch(state->gamemap.curr_skill)
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
            if(target_1_object)
            {
                DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                vec2i source_object_tilemap_pos = source_object->tilemap_pos;
                for(int i = 0; i < move_distance_info.abs_diff - 1; i++)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move_ground(source_object,source_object_tilemap_pos,move_distance_info.dir4));
                    source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
                }

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
            if(target_1_object)
            {
                DistanceInfo move_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                vec2i source_object_tilemap_pos = source_object->tilemap_pos;
                for(int i = 0; i < move_distance_info.abs_diff - 1; i++)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move_ground(source_object,source_object_tilemap_pos,move_distance_info.dir4));
                    source_object_tilemap_pos = make_vec2i_move_in_dir4_by(source_object_tilemap_pos, move_distance_info.dir4, 1);
                }

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

char* get_skill_name(int skill)
{
    char* name = "";

    switch(skill)
    {
        case SKILL__NONE:               name = "none";              break;
        case SKILL__FLY:                name = "fly";               break;
        case SKILL__JUMP:               name = "jump";              break;
        case SKILL__CHARGE:             name = "charge";            break;
        case SKILL__CHARGE_AND_PUSH:    name = "charge_and_push";   break;
        case SKILL__CHARGE_AND_THROW:   name = "charge_and_throw";  break;
        case SKILL__PUSH:               name = "push";              break;
        case SKILL__PULL:               name = "pull";              break;
        case SKILL__PULL_AND_THROW:     name = "pull_and_throw";    break;
        case SKILL__THROW:              name = "throw";             break;
        default: break;
    }

    return name;
}
