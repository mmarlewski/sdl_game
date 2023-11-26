#include "../inc/state.h"

void skill_add_actions_to_action_sequence(State* state, Action* action_sequence, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
    Object* target_2_object = get_object_on_tilemap_pos(state, target_2_tilemap_pos);

    switch(skill)
    {
        case SKILL__NONE:
        {
            //
        }
        break;
        case SKILL__INTERACT:
        {
            Object* object = target_2_object;
            int floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);

            if(object != 0)
            {
                object_on_interact(state, action_sequence, object, target_2_tilemap_pos);
            }
            else if(floor != FLOOR_TYPE__NONE)
            {
                floor_on_interact(state, action_sequence, floor, target_2_tilemap_pos);
            }
        }
        break;
        case SKILL__MOVE:
        {
            List* path_pos = new_list((void(*)(void*))destroy_vec2i);
            find_path(state, source_tilemap_pos, target_2_tilemap_pos, path_pos);

            if(path_pos->size > 0)
            {
                ListElem* curr_elem = path_pos->head;
                ListElem* next_elem = (curr_elem) ? (curr_elem->next) : (0);

                Vec2i* curr_tilemap_pos = (curr_elem) ? ((Vec2i*)curr_elem->data) : (0);
                Vec2i* next_tilemap_pos = (next_elem) ? ((Vec2i*)next_elem->data) : (0);

                while(curr_elem != 0 && next_elem != 0)
                {
                    DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(*curr_tilemap_pos, *next_tilemap_pos);

                    add_action_to_end_action_sequence(action_sequence, new_action_move(*curr_tilemap_pos, distance_info.dir4));

                    curr_elem = next_elem;
                    next_elem = (curr_elem) ? (curr_elem->next) : (0);

                    curr_tilemap_pos = (curr_elem) ? ((Vec2i*)curr_elem->data) : (0);
                    next_tilemap_pos = (next_elem) ? ((Vec2i*)next_elem->data) : (0);
                }
            }

            remove_all_list_elements(path_pos, 1);
            destroy_list(path_pos);
        }
        break;
        case SKILL__CHARGE:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);
            int abs_diff = distance_info.abs_diff;
            int dir4 = distance_info.dir4;

            Vec2i old_tilemap_pos = source_object->tilemap_pos;
            Vec2i tilemap_pos = source_object->tilemap_pos;
            int floor = FLOOR_TYPE__NONE;
            Object* object = 0;

            for(int i = 0; i < abs_diff; i++)
            {
                old_tilemap_pos = tilemap_pos;
                tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, dir4, 1);
                floor = get_floor_on_tilemap_pos(state, tilemap_pos);
                object = get_object_on_tilemap_pos(state, tilemap_pos);

                if(!is_tilemap_pos_in_tilemap(tilemap_pos) || object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(old_tilemap_pos, dir4));
                    break;
                }
                else if(!is_object_flying(source_object) && (
                floor == FLOOR_TYPE__WATER ||
                floor == FLOOR_TYPE__LAVA ||
                floor == FLOOR_TYPE__METAL_SPIKES ||
                floor == FLOOR_TYPE__HATCH_OPEN))
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(old_tilemap_pos,dir4));
                    add_action_to_end_action_sequence(action_sequence, new_action_death(source_object,tilemap_pos));
                    break;
                }
                else
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(old_tilemap_pos,dir4));
                }
            }
        }
        break;
        case SKILL__JUMP:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);
            int abs_diff = distance_info.abs_diff;
            int dir4 = distance_info.dir4;

            int floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);
            Object* object = target_2_object;

            if(!is_tilemap_pos_in_tilemap(target_2_tilemap_pos) || object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(source_tilemap_pos, dir4));
            }
            else if(!is_object_flying(source_object) && (
            floor == FLOOR_TYPE__WATER ||
            floor == FLOOR_TYPE__ICE_WATER_CRACK ||
            floor == FLOOR_TYPE__LAVA ||
            floor == FLOOR_TYPE__METAL_LAVA_CRACK ||
            floor == FLOOR_TYPE__METAL_SPIKES ||
            floor == FLOOR_TYPE__HATCH_OPEN))
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( source_tilemap_pos, dir4, abs_diff));
                add_action_to_end_action_sequence(action_sequence, new_action_death(source_object, target_2_tilemap_pos));
            }
            else
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( source_tilemap_pos, dir4, abs_diff));
            }
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            DistanceInfo charge_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
            int charge_abs_diff = charge_distance_info.abs_diff;
            int charge_dir4 = charge_distance_info.dir4;

            Vec2i charge_old_tilemap_pos = source_object->tilemap_pos;
            Vec2i charge_tilemap_pos = source_object->tilemap_pos;
            int charge_floor = FLOOR_TYPE__NONE;
            Object* charge_object = 0;

            for(int i = 0; i < charge_abs_diff - 1; i++)
            {
                charge_old_tilemap_pos = charge_tilemap_pos;
                charge_tilemap_pos = vec2i_move_in_dir4_by(charge_tilemap_pos, charge_dir4, 1);
                charge_floor = get_floor_on_tilemap_pos(state, charge_tilemap_pos);
                charge_object = get_object_on_tilemap_pos(state, charge_tilemap_pos);

                if(!is_tilemap_pos_in_tilemap(charge_tilemap_pos) || charge_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(charge_old_tilemap_pos, charge_dir4));
                    break;
                }
                else if(!is_object_flying(source_object) && (
                charge_floor == FLOOR_TYPE__WATER ||
                charge_floor == FLOOR_TYPE__LAVA ||
                charge_floor == FLOOR_TYPE__METAL_SPIKES ||
                charge_floor == FLOOR_TYPE__HATCH_OPEN))
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(charge_old_tilemap_pos,charge_dir4));
                    add_action_to_end_action_sequence(action_sequence, new_action_death(source_object,charge_tilemap_pos));
                    break;
                }
                else
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(charge_old_tilemap_pos,charge_dir4));
                }
            }

            DistanceInfo push_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
            int push_abs_diff = push_distance_info.abs_diff;
            int push_dir4 = push_distance_info.dir4;

            if(target_1_object == 0) break;

            Vec2i push_old_tilemap_pos = target_1_object->tilemap_pos;
            Vec2i push_tilemap_pos = target_1_object->tilemap_pos;
            int push_floor = FLOOR_TYPE__NONE;
            Object* push_object = 0;

            for(int i = 0; i < push_abs_diff; i++)
            {
                push_old_tilemap_pos = push_tilemap_pos;
                push_tilemap_pos = vec2i_move_in_dir4_by(push_tilemap_pos, push_dir4, 1);
                push_floor = get_floor_on_tilemap_pos(state, push_tilemap_pos);
                push_object = get_object_on_tilemap_pos(state, push_tilemap_pos);

                if(!is_tilemap_pos_in_tilemap(push_tilemap_pos) || push_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(push_old_tilemap_pos, push_dir4));
                    break;
                }
                else if(!is_object_flying(target_1_object) && (
                push_floor == FLOOR_TYPE__WATER ||
                push_floor == FLOOR_TYPE__LAVA ||
                push_floor == FLOOR_TYPE__METAL_SPIKES ||
                push_floor == FLOOR_TYPE__HATCH_OPEN))
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(push_old_tilemap_pos,push_dir4));
                    add_action_to_end_action_sequence(action_sequence, new_action_death(target_1_object,push_tilemap_pos));
                    break;
                }
                else
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(push_old_tilemap_pos,push_dir4));
                }
            }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            DistanceInfo charge_distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
            int charge_abs_diff = charge_distance_info.abs_diff;
            int charge_dir4 = charge_distance_info.dir4;

            Vec2i charge_old_tilemap_pos = source_object->tilemap_pos;
            Vec2i charge_tilemap_pos = source_object->tilemap_pos;
            int charge_floor = FLOOR_TYPE__NONE;
            Object* charge_object = 0;

            for(int i = 0; i < charge_abs_diff - 1; i++)
            {
                charge_old_tilemap_pos = charge_tilemap_pos;
                charge_tilemap_pos = vec2i_move_in_dir4_by(charge_tilemap_pos, charge_dir4, 1);
                charge_floor = get_floor_on_tilemap_pos(state, charge_tilemap_pos);
                charge_object = get_object_on_tilemap_pos(state, charge_tilemap_pos);

                if(!is_tilemap_pos_in_tilemap(charge_tilemap_pos) || charge_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(charge_old_tilemap_pos, charge_dir4));
                    break;
                }
                else if(!is_object_flying(source_object) && (
                charge_floor == FLOOR_TYPE__WATER ||
                charge_floor == FLOOR_TYPE__LAVA ||
                charge_floor == FLOOR_TYPE__METAL_SPIKES ||
                charge_floor == FLOOR_TYPE__HATCH_OPEN))
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(charge_old_tilemap_pos,charge_dir4));
                    add_action_to_end_action_sequence(action_sequence, new_action_death(source_object,charge_tilemap_pos));
                    break;
                }
                else
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(charge_old_tilemap_pos,charge_dir4));
                }
            }

            if(target_1_object == 0) break;

            DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
            int throw_abs_diff = throw_distance_info.abs_diff;
            int throw_dir4 = throw_distance_info.dir4;

            int throw_floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);
            Object* throw_object = target_2_object;

            if(!is_tilemap_pos_in_tilemap(target_2_tilemap_pos) || throw_object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(target_1_tilemap_pos, throw_dir4));
            }
            else if(!is_object_flying(target_1_object) && (
            throw_floor == FLOOR_TYPE__WATER ||
            throw_floor == FLOOR_TYPE__ICE_WATER_CRACK ||
            throw_floor == FLOOR_TYPE__LAVA ||
            throw_floor == FLOOR_TYPE__METAL_LAVA_CRACK ||
            throw_floor == FLOOR_TYPE__METAL_SPIKES ||
            throw_floor == FLOOR_TYPE__HATCH_OPEN))
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( target_1_tilemap_pos, throw_dir4, throw_abs_diff));
                add_action_to_end_action_sequence(action_sequence, new_action_death(target_1_object, target_2_tilemap_pos));
            }
            else
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( target_1_tilemap_pos, throw_dir4, throw_abs_diff));
            }
        }
        break;
        case SKILL__PUSH: case SKILL__PULL:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
            int abs_diff = distance_info.abs_diff;
            int dir4 = distance_info.dir4;

            if(target_1_object == 0)
            {
                Vec2i tilemap_pos = target_1_tilemap_pos;
                for(int i = 0; i < abs_diff - 1; i++)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(tilemap_pos, dir4));
                    tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, dir4, 1);
                }
                break;
            }

            Vec2i old_tilemap_pos = target_1_object->tilemap_pos;
            Vec2i tilemap_pos = target_1_object->tilemap_pos;
            int floor = FLOOR_TYPE__NONE;
            Object* object = 0;

            for(int i = 0; i < abs_diff; i++)
            {
                old_tilemap_pos = tilemap_pos;
                tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, dir4, 1);
                floor = get_floor_on_tilemap_pos(state, tilemap_pos);
                object = get_object_on_tilemap_pos(state, tilemap_pos);

                if(!is_tilemap_pos_in_tilemap(tilemap_pos) || object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(old_tilemap_pos, dir4));
                    break;
                }
                else if(!is_object_flying(target_1_object) && (
                floor == FLOOR_TYPE__WATER ||
                floor == FLOOR_TYPE__LAVA ||
                floor == FLOOR_TYPE__METAL_SPIKES ||
                floor == FLOOR_TYPE__HATCH_OPEN))
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(old_tilemap_pos,dir4));
                    add_action_to_end_action_sequence(action_sequence, new_action_death(target_1_object,tilemap_pos));
                    break;
                }
                else
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(old_tilemap_pos,dir4));
                }
            }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            DistanceInfo pull_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, source_tilemap_pos);
            int pull_abs_diff = pull_distance_info.abs_diff;
            int pull_dir4 = pull_distance_info.dir4;

            if(target_1_object == 0)
            {
                Vec2i pull_tilemap_pos = target_1_tilemap_pos;
                for(int i = 0; i < pull_abs_diff - 1; i++)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(pull_tilemap_pos, pull_dir4));
                    pull_tilemap_pos = vec2i_move_in_dir4_by(pull_tilemap_pos, pull_dir4, 1);
                }
                break;
            }

            Vec2i pull_old_tilemap_pos = target_1_object->tilemap_pos;
            Vec2i pull_tilemap_pos = target_1_object->tilemap_pos;
            int pull_floor = FLOOR_TYPE__NONE;
            Object* pull_object = 0;

            for(int i = 0; i < pull_abs_diff - 1; i++)
            {
                pull_old_tilemap_pos = pull_tilemap_pos;
                pull_tilemap_pos = vec2i_move_in_dir4_by(pull_tilemap_pos, pull_dir4, 1);
                pull_floor = get_floor_on_tilemap_pos(state, pull_tilemap_pos);
                pull_object = get_object_on_tilemap_pos(state, pull_tilemap_pos);

                if(!is_tilemap_pos_in_tilemap(pull_tilemap_pos) || pull_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(pull_old_tilemap_pos, pull_dir4));
                    break;
                }
                else if(!is_object_flying(target_1_object) && (
                pull_floor == FLOOR_TYPE__WATER ||
                pull_floor == FLOOR_TYPE__LAVA ||
                pull_floor == FLOOR_TYPE__METAL_SPIKES ||
                pull_floor == FLOOR_TYPE__HATCH_OPEN))
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(pull_old_tilemap_pos,pull_dir4));
                    add_action_to_end_action_sequence(action_sequence, new_action_death(target_1_object,pull_tilemap_pos));
                    break;
                }
                else
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(pull_old_tilemap_pos,pull_dir4));
                }
            }

            Vec2i before_source_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, pull_dir4, -1);

            DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(before_source_tilemap_pos, target_2_tilemap_pos);
            int throw_abs_diff = throw_distance_info.abs_diff;
            int throw_dir4 = throw_distance_info.dir4;

            int throw_floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);
            Object* throw_object = target_2_object;

            if(!is_tilemap_pos_in_tilemap(target_2_tilemap_pos) || throw_object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(before_source_tilemap_pos, throw_dir4));
            }
            else if(!is_object_flying(target_1_object) && (
            throw_floor == FLOOR_TYPE__WATER ||
            throw_floor == FLOOR_TYPE__ICE_WATER_CRACK ||
            throw_floor == FLOOR_TYPE__LAVA ||
            throw_floor == FLOOR_TYPE__METAL_LAVA_CRACK ||
            throw_floor == FLOOR_TYPE__METAL_SPIKES ||
            throw_floor == FLOOR_TYPE__HATCH_OPEN))
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( before_source_tilemap_pos, throw_dir4, throw_abs_diff));
                add_action_to_end_action_sequence(action_sequence, new_action_death(target_1_object, target_2_tilemap_pos));
            }
            else
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( before_source_tilemap_pos, throw_dir4, throw_abs_diff));
            }
        }
        break;
        case SKILL__THROW:
        {
            if(target_1_object == 0) break;

            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
            int abs_diff = distance_info.abs_diff;
            int dir4 = distance_info.dir4;

            int floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);
            Object* object = target_2_object;

            if(!is_tilemap_pos_in_tilemap(target_2_tilemap_pos) || object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(target_1_tilemap_pos, dir4));
            }
            else if(!is_object_flying(target_1_object) && (
            floor == FLOOR_TYPE__WATER ||
            floor == FLOOR_TYPE__ICE_WATER_CRACK ||
            floor == FLOOR_TYPE__LAVA ||
            floor == FLOOR_TYPE__METAL_LAVA_CRACK ||
            floor == FLOOR_TYPE__METAL_SPIKES ||
            floor == FLOOR_TYPE__HATCH_OPEN))
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( target_1_tilemap_pos, dir4, abs_diff));
                add_action_to_end_action_sequence(action_sequence, new_action_death(target_1_object, target_2_tilemap_pos));
            }
            else
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( target_1_tilemap_pos, dir4, abs_diff));
            }
        }
        break;
        default:
        break;
    }
}
