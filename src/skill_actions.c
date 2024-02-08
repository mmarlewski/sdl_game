#include "../inc/state.h"

void skill_get_actions(
    State* state,
    Action* action_sequence,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos
)
{
    Object* source_object = room_get_object_at(state->curr_room, source_tilemap_pos);
    Object* target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
    Object* target_2_object = room_get_object_at(state->curr_room, target_2_tilemap_pos);

    switch(skill)
    {
        case SKILL__USE:
        {
            if(target_2_object != 0 && is_object_station(target_2_object))
            {
                add_action_after_curr_action_action_sequence(
                    action_sequence,
                    new_action_change_object(
                        OBJECT_TYPE__STATION_TAKEN,
                        target_2_tilemap_pos
                        )
                    );
            }
        }
        break;
        case SKILL__STOMP:
        {
            if(target_2_object != 0)
            {
                object_on_stomp(
                    state,
                    action_sequence,
                    target_2_object,
                    target_2_tilemap_pos
                    );
            }
            else
            {
                floor_on_stomp(
                    state,
                    action_sequence,
                    room_get_floor_at(state->curr_room, target_2_tilemap_pos),
                    target_2_tilemap_pos
                    );
            }

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos =vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);
                Object* object = room_get_object_at(state->curr_room, tilemap_pos);

                if(object != 0)
                {
                    object_on_shake(
                        state,
                        action_sequence,
                        new_action_shake(tilemap_pos),
                        object
                        );
                }
            }
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        case SKILL__PICK_ITEM_FAR:
        {
            if(target_2_object != 0)
            {
                object_on_pick_item(
                    state,
                    action_sequence,
                    target_2_object,
                    target_2_tilemap_pos
                    );
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

                floor_on_pick_item(
                    state,
                    action_sequence,
                    floor,
                    target_2_tilemap_pos
                    );
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_CLOSE:
        case SKILL__PUT_ITEM_CELL_FAR:
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
        case SKILL__PUT_ITEM_DYNAMITE_FAR:
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
        case SKILL__PUT_ITEM_GEMSTONE_FAR:
        {
            int item_type = ITEM__NONE;
            if(skill == SKILL__PUT_ITEM_CELL_CLOSE ||
            skill == SKILL__PUT_ITEM_CELL_FAR)
            {
                item_type = ITEM__CELL;
            }
            if(skill == SKILL__PUT_ITEM_DYNAMITE_CLOSE ||
            skill == SKILL__PUT_ITEM_DYNAMITE_FAR)
            {
                item_type = ITEM__DYNAMITE;
            }
            if(skill == SKILL__PUT_ITEM_GEMSTONE_CLOSE ||
            skill == SKILL__PUT_ITEM_GEMSTONE_FAR)
            {
                item_type = ITEM__GEMSTONE;
            }

            if(target_2_object != 0)
            {
                if(source_object->type == OBJECT_TYPE__HERO ||
                source_object->type == OBJECT_TYPE__HERO_FLOATING ||
                source_object->type == OBJECT_TYPE__HERO_FLYING)
                {
                    object_on_put_item(
                        state,
                        action_sequence,
                        target_2_object,
                        target_2_tilemap_pos,
                        item_type
                        );
                }
                else if(source_object->type == OBJECT_TYPE__MINIBOT_ALLY_CELL)
                {
                    object_on_put_item(
                        state,
                        action_sequence,
                        target_2_object,
                        target_2_tilemap_pos,
                        ITEM__CELL
                        );
                }
                else if(source_object->type == OBJECT_TYPE__MINIBOT_ALLY_DYNAMITE)
                {
                    object_on_put_item(
                        state,
                        action_sequence,
                        target_2_object,
                        target_2_tilemap_pos,
                        ITEM__DYNAMITE
                        );
                }
                else if(source_object->type == OBJECT_TYPE__MINIBOT_ALLY_GEMSTONE)
                {
                    object_on_put_item(
                        state,
                        action_sequence,
                        target_2_object,
                        target_2_tilemap_pos,
                        ITEM__GEMSTONE
                        );
                }
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

                if(source_object->type == OBJECT_TYPE__HERO ||
                source_object->type == OBJECT_TYPE__HERO_FLOATING ||
                source_object->type == OBJECT_TYPE__HERO_FLYING)
                {
                    floor_on_put_item(
                        state,
                        action_sequence,
                        floor,
                        target_2_tilemap_pos,
                        item_type
                        );
                }
                else if(source_object->type == OBJECT_TYPE__MINIBOT_ALLY_CELL)
                {
                    floor_on_put_item(
                        state,
                        action_sequence,
                        floor,
                        target_2_tilemap_pos,
                        ITEM__CELL
                        );
                }
                else if(source_object->type == OBJECT_TYPE__MINIBOT_ALLY_DYNAMITE)
                {
                    floor_on_put_item(
                        state,
                        action_sequence,
                        floor,
                        target_2_tilemap_pos,
                        ITEM__DYNAMITE
                        );
                }
                else if(source_object->type == OBJECT_TYPE__MINIBOT_ALLY_GEMSTONE)
                {
                    floor_on_put_item(
                        state,
                        action_sequence,
                        floor,
                        target_2_tilemap_pos,
                        ITEM__GEMSTONE
                        );
                }
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            Object* object = target_2_object;
            int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

            if(object != 0 && is_object_manipulatable(object))
            {
                object_on_manipulate(state, action_sequence, object, target_2_tilemap_pos);
            }
            else if(floor != FLOOR_TYPE__NONE && is_floor_manipulatable(floor))
            {
                floor_on_manipulation(state, action_sequence, floor, target_2_tilemap_pos);
            }
        }
        break;
        case SKILL__MOVE:
        case SKILL__MOVE_FLOATING:
        case SKILL__MOVE_FLYING:
        {
            List* path_pos = new_list((void(*)(void*))destroy_vec2i);
            find_path(
                state,
                source_tilemap_pos,
                target_2_tilemap_pos,
                path_pos,
                is_object_floating(source_object),
                is_object_flying(source_object)
                );

            if(path_pos->size > 0)
            {
                ListElem* curr_elem = path_pos->head;
                ListElem* next_elem = (curr_elem) ? (curr_elem->next) : (0);

                Vec2i* curr_tilemap_pos = (curr_elem) ? ((Vec2i*)curr_elem->data) : (0);
                Vec2i* next_tilemap_pos = (next_elem) ? ((Vec2i*)next_elem->data) : (0);

                while(curr_elem != 0 && next_elem != 0)
                {
                    DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(*curr_tilemap_pos, *next_tilemap_pos);

                    add_action_to_end_action_sequence(
                        action_sequence,
                        new_action_move(
                            *curr_tilemap_pos,
                            distance_info.dir4
                            )
                        );

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
        case SKILL__THROW_ITEM_CELL:
        {
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_melt(target_2_tilemap_pos)
                );
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_break(target_2_tilemap_pos)
                );

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);

                add_action_to_end_action_sequence(
                    action_sequence,
                    new_action_shake(tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_shake(target_2_tilemap_pos)
                );
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
                floor = room_get_floor_at(state->curr_room, tilemap_pos);
                object = room_get_object_at(state->curr_room, tilemap_pos);

                if(!is_tilemap_in_bounds(tilemap_pos) || object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(old_tilemap_pos, dir4));
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

            int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
            Object* object = target_2_object;

            if(!is_tilemap_in_bounds(target_2_tilemap_pos) || object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(source_tilemap_pos, dir4));
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
                charge_floor = room_get_floor_at(state->curr_room, charge_tilemap_pos);
                charge_object = room_get_object_at(state->curr_room, charge_tilemap_pos);

                if(!is_tilemap_in_bounds(charge_tilemap_pos) || charge_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(charge_old_tilemap_pos, charge_dir4));
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

            if(target_1_object == 0 || !is_object_movable(target_1_object)) break;

            Vec2i push_old_tilemap_pos = target_1_object->tilemap_pos;
            Vec2i push_tilemap_pos = target_1_object->tilemap_pos;
            int push_floor = FLOOR_TYPE__NONE;
            Object* push_object = 0;

            for(int i = 0; i < push_abs_diff; i++)
            {
                push_old_tilemap_pos = push_tilemap_pos;
                push_tilemap_pos = vec2i_move_in_dir4_by(push_tilemap_pos, push_dir4, 1);
                push_floor = room_get_floor_at(state->curr_room, push_tilemap_pos);
                push_object = room_get_object_at(state->curr_room, push_tilemap_pos);

                if(!is_tilemap_in_bounds(push_tilemap_pos) || push_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(push_old_tilemap_pos, push_dir4));
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
                charge_floor = room_get_floor_at(state->curr_room, charge_tilemap_pos);
                charge_object = room_get_object_at(state->curr_room, charge_tilemap_pos);

                if(!is_tilemap_in_bounds(charge_tilemap_pos) || charge_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(charge_old_tilemap_pos, charge_dir4));
                    break;
                }
                else
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_move(charge_old_tilemap_pos,charge_dir4));
                }
            }

            if(target_1_object == 0 || !is_object_movable(target_1_object)) break;

            DistanceInfo throw_distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
            int throw_abs_diff = throw_distance_info.abs_diff;
            int throw_dir4 = throw_distance_info.dir4;

            int throw_floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
            Object* throw_object = target_2_object;

            if(!is_tilemap_in_bounds(target_2_tilemap_pos) || throw_object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(target_1_tilemap_pos, throw_dir4));
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
            else if(!is_object_movable(target_1_object)) break;

            Vec2i old_tilemap_pos = target_1_object->tilemap_pos;
            Vec2i tilemap_pos = target_1_object->tilemap_pos;
            int floor = FLOOR_TYPE__NONE;
            Object* object = 0;

            for(int i = 0; i < abs_diff; i++)
            {
                old_tilemap_pos = tilemap_pos;
                tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, dir4, 1);
                floor = room_get_floor_at(state->curr_room, tilemap_pos);
                object = room_get_object_at(state->curr_room, tilemap_pos);

                if(!is_tilemap_in_bounds(tilemap_pos) || object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(old_tilemap_pos, dir4));
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
            else if(!is_object_movable(target_1_object)) break;

            Vec2i pull_old_tilemap_pos = target_1_object->tilemap_pos;
            Vec2i pull_tilemap_pos = target_1_object->tilemap_pos;
            int pull_floor = FLOOR_TYPE__NONE;
            Object* pull_object = 0;

            for(int i = 0; i < pull_abs_diff - 1; i++)
            {
                pull_old_tilemap_pos = pull_tilemap_pos;
                pull_tilemap_pos = vec2i_move_in_dir4_by(pull_tilemap_pos, pull_dir4, 1);
                pull_floor = room_get_floor_at(state->curr_room, pull_tilemap_pos);
                pull_object = room_get_object_at(state->curr_room, pull_tilemap_pos);

                if(!is_tilemap_in_bounds(pull_tilemap_pos) || pull_object != 0)
                {
                    add_action_to_end_action_sequence(action_sequence, new_action_crash(pull_old_tilemap_pos, pull_dir4));
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

            int throw_floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
            Object* throw_object = target_2_object;

            if(!is_tilemap_in_bounds(target_2_tilemap_pos) || throw_object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(before_source_tilemap_pos, throw_dir4));
            }
            else
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( before_source_tilemap_pos, throw_dir4, throw_abs_diff));
            }
        }
        break;
        case SKILL__THROW:
        {
            if(target_1_object == 0 || !is_object_movable(target_1_object)) break;

            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
            int abs_diff = distance_info.abs_diff;
            int dir4 = distance_info.dir4;

            int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
            Object* object = target_2_object;

            if(!is_tilemap_in_bounds(target_2_tilemap_pos) || object != 0)
            {
                add_action_to_end_action_sequence(action_sequence, new_action_lift(target_1_tilemap_pos, dir4));
            }
            else
            {
                add_action_to_end_action_sequence(action_sequence, new_action_throw( target_1_tilemap_pos, dir4, abs_diff));
            }
        }
        break;
        case SKILL__TURRET_LASER:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

            if(distance_info.dir4 != DIR4__NONE)
            {
                for(int i = 1; i <= OBJECT_TURRET_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, distance_info.dir4, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);

                        if(object != 0 && is_object_meltable(object))
                        {
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_melt(tilemap_pos)
                                );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_break(target_2_tilemap_pos)
                );

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);

                add_action_to_end_action_sequence(
                    action_sequence,
                    new_action_shake(tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_shake(target_2_tilemap_pos)
                );
        }
        break;
        default:
        break;
    }
}
