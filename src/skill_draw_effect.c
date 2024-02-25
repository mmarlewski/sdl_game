#include "../inc/state.h"

void xxx4(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    List* texture_list,
    List* tilemap_pos_list,
    Textures* textures,
    Colors* colors
)
{
    Object* source_object = room_get_object_at(state->curr_room, source_tilemap_pos);
    Object* target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
    Object* target_2_object = room_get_object_at(state->curr_room, target_2_tilemap_pos);

    switch(skill)
    {
        case SKILL__LAUNCH_MINIBOT:
        {
                    add_new_list_element_to_list_end(
                        texture_list,
                        textures->object.minibot_ally_1
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
        }
        break;
        case SKILL__USE:
        {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.use_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
        }
        break;
        case SKILL__STOMP:
        {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.stomp_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos =vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);

            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.shake_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                        );
            }
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        case SKILL__PICK_ITEM_FAR:
        {
            if(target_2_object != 0)
            {
                int item_type = get_object_item_type(target_2_object);
                int item_count = get_object_item_count(target_2_object);

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_item(textures, item_type, item_count)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                        );
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

                int item_type = get_floor_item_type(floor);
                int item_count = get_floor_item_count(floor);

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_item(textures, item_type, item_count)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
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

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_item(textures, item_type, -1)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                        );
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_item(textures, item_type, -1)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                        );
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            //
        }
        break;
        case SKILL__MOVE:
        case SKILL__MOVE_FLOATING:
        case SKILL__MOVE_FLYING:
        {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(source_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            if(target_2_object != 0 && is_object_meltable(target_2_object))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.melt_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_item(textures, ITEM__CELL, -1)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                        );
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            if(target_2_object != 0 && is_object_breakable(target_2_object))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.break_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.shake_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                        );
                }
            }

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_item(textures, ITEM__DYNAMITE, -1)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                        );
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.shake_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_item(textures, ITEM__GEMSTONE, -1)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                        );
        }
        break;
        case SKILL__CHARGE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                    );

            int target_2_floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
            if((is_object_floating(source_object) && is_floor_deadly_on_move_for_floating(target_2_floor)) ||
            (is_object_flying(source_object) && is_floor_deadly_on_move_for_flying(target_2_floor)) ||
            (!is_object_floating(source_object) && !is_object_flying(source_object) && is_floor_deadly_on_move(target_2_floor)))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }
            else if(room_get_object_at(state->curr_room, target_2_tilemap_pos) == 0)
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(source_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }
            else
            {
                Vec2i just_before_target_2_tilemap_pos =
                    vec2i_move_in_dir4_by(
                        target_2_tilemap_pos,
                        get_opposite_dir4(distance_info.dir4),
                        1
                        );

            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(source_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(just_before_target_2_tilemap_pos)
                        );

            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.crash_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }
        }
        break;
        case SKILL__JUMP:
        {
            int target_2_floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
            if((is_object_floating(source_object) && is_floor_deadly_on_move_for_floating(target_2_floor)) ||
            (is_object_flying(source_object) && is_floor_deadly_on_move_for_flying(target_2_floor)) ||
            (!is_object_floating(source_object) && !is_object_flying(source_object) && is_floor_deadly_on_move(target_2_floor)))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }
            else
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(source_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                    );

            Vec2i just_before_target_1_tilemap_pos =
                vec2i_move_in_dir4_by(
                    target_1_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1
                    );

            int will_push_after_charge = 1;

            Vec2i charge_curr_tilemap_pos = source_object->tilemap_pos;
            int charge_curr_floor = room_get_floor_at(state->curr_room, charge_curr_tilemap_pos);
            Object* charge_curr_object = room_get_object_at(state->curr_room, charge_curr_tilemap_pos);

            int charge_go_on = 1;
            for(int i = 0; charge_go_on && i < charge_distance_info.abs_diff; i++)
            {
                if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(source_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(charge_curr_tilemap_pos)
                        );
                }
                else if(is_tilemap_in_bounds(charge_curr_tilemap_pos) &&
                (is_floor_traversable(charge_curr_floor) ||
                is_object_flying(source_object)) &&
                charge_curr_object == 0)
                {
                    //
                }
                else
                {
                    charge_go_on = 0;
                    will_push_after_charge = 0;
                }

                charge_curr_tilemap_pos = vec2i_move_in_dir4_by(charge_curr_tilemap_pos,charge_distance_info.dir4,1);
                charge_curr_floor = room_get_floor_at(state->curr_room, charge_curr_tilemap_pos);
                charge_curr_object = room_get_object_at(state->curr_room, charge_curr_tilemap_pos);
            }

            if(!will_push_after_charge)
            {
                Vec2i death_tilemap_pos = vec2i_move_in_dir4_by(
                    charge_curr_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1);

            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(death_tilemap_pos)
                        );

                break;
            }

            if(!is_object_movable(target_1_object))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.immovable_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );

                break;
            }

            DistanceInfo push_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            Vec2i push_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_next_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);

            int push_curr_floor = room_get_floor_at(state->curr_room, push_curr_tilemap_pos);
            int push_next_floor = room_get_floor_at(state->curr_room, push_next_tilemap_pos);

            Object* push_curr_object = room_get_object_at(state->curr_room, push_curr_tilemap_pos);
            Object* push_next_object = room_get_object_at(state->curr_room, push_next_tilemap_pos);

            int push_go_on = 1;
            for(int i = 0; push_go_on && i < push_distance_info.abs_diff + 1; i++)
            {
                if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(target_1_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(push_curr_tilemap_pos)
                        );
                }
                else if(is_tilemap_in_bounds(push_curr_tilemap_pos) &&
                (is_floor_traversable(push_curr_floor) ||
                is_object_flying(target_1_object)) &&
                push_curr_object == 0)
                {
                    //
                }
                else
                {
                    push_go_on = 0;

                    if(!is_floor_traversable(push_curr_floor) &&
                    !is_object_flying(target_1_object))
                    {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(push_curr_tilemap_pos)
                        );
                    }
                }

                push_curr_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);
                push_curr_floor = room_get_floor_at(state->curr_room, push_curr_tilemap_pos);
                push_curr_object = room_get_object_at(state->curr_room, push_curr_tilemap_pos);
            }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                    );

            Vec2i just_before_target_1_tilemap_pos =
                vec2i_move_in_dir4_by(
                    target_1_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1
                    );

            int will_throw_after_charge = 1;

            Vec2i charge_curr_tilemap_pos = source_object->tilemap_pos;
            int charge_curr_floor = room_get_floor_at(state->curr_room, charge_curr_tilemap_pos);
            Object* charge_curr_object = room_get_object_at(state->curr_room, charge_curr_tilemap_pos);

            int charge_go_on = 1;
            for(int i = 0; charge_go_on && i < charge_distance_info.abs_diff; i++)
            {
                if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(source_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(charge_curr_tilemap_pos)
                        );
                }
                else if(is_tilemap_in_bounds(charge_curr_tilemap_pos) &&
                (is_floor_traversable(charge_curr_floor) ||
                is_object_flying(source_object)) &&
                charge_curr_object == 0)
                {
                    //
                }
                else
                {
                    charge_go_on = 0;
                    will_throw_after_charge = 0;
                }

                charge_curr_tilemap_pos = vec2i_move_in_dir4_by(charge_curr_tilemap_pos,charge_distance_info.dir4,1);
                charge_curr_floor = room_get_floor_at(state->curr_room, charge_curr_tilemap_pos);
                charge_curr_object = room_get_object_at(state->curr_room, charge_curr_tilemap_pos);
            }

            if(!will_throw_after_charge)
            {
                Vec2i death_tilemap_pos = vec2i_move_in_dir4_by(
                    charge_curr_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1);

            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(death_tilemap_pos)
                        );

                break;
            }

            if(is_object_movable(target_1_object))
            {
                int target_2_floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
                if((is_object_floating(target_1_object) && is_floor_deadly_on_move_for_floating(target_2_floor)) ||
                (is_object_flying(target_1_object) && is_floor_deadly_on_move_for_flying(target_2_floor)) ||
                (!is_object_floating(target_1_object) && !is_object_flying(target_1_object) && is_floor_deadly_on_move(target_2_floor)))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
                }
                else
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(target_1_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
                }
            }
            else
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.immovable_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );
            }
        }
        break;
        case SKILL__PUSH:
        {
            if(!is_object_movable(target_1_object))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.immovable_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );

                break;
            }

            DistanceInfo push_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            Vec2i push_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_next_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);

            int push_curr_floor = room_get_floor_at(state->curr_room, push_curr_tilemap_pos);
            int push_next_floor =room_get_floor_at(state->curr_room, push_next_tilemap_pos);

            Object* push_curr_object = room_get_object_at(state->curr_room, push_curr_tilemap_pos);
            Object* push_next_object = room_get_object_at(state->curr_room, push_next_tilemap_pos);

            int push_go_on = 1;
            for(int i = 0; push_go_on && i < push_distance_info.abs_diff + 1; i++)
            {
                if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(target_1_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(push_curr_tilemap_pos)
                        );
                }
                else if(is_tilemap_in_bounds(push_curr_tilemap_pos) &&
                (is_floor_traversable(push_curr_floor) ||
                is_object_flying(target_1_object)) &&
                push_curr_object == 0)
                {
                    //
                }
                else
                {
                    push_go_on = 0;

                   if(!is_floor_traversable(push_curr_floor) &&
                    !is_object_flying(target_1_object))
                    {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(push_curr_tilemap_pos)
                        );
                    }
                }

                push_curr_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);
                push_curr_floor = room_get_floor_at(state->curr_room, push_curr_tilemap_pos);
                push_curr_object = room_get_object_at(state->curr_room, push_curr_tilemap_pos);
            }
        }
        break;
        case SKILL__PULL:
        {
            if(!is_object_movable(target_1_object))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.immovable_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );

                break;
            }

            DistanceInfo pull_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            Vec2i pull_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_next_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);

            int pull_curr_floor = room_get_floor_at(state->curr_room, pull_curr_tilemap_pos);
            int pull_next_floor = room_get_floor_at(state->curr_room, pull_next_tilemap_pos);

            Object* pull_curr_object = room_get_object_at(state->curr_room, pull_curr_tilemap_pos);
            Object* pull_next_object = room_get_object_at(state->curr_room, pull_next_tilemap_pos);

            int pull_go_on = 1;
            for(int i = 0; pull_go_on && i < pull_distance_info.abs_diff + 1; i++)
            {
                if(vec2i_equals(pull_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(pull_curr_tilemap_pos, target_2_tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(target_1_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(pull_curr_tilemap_pos)
                        );
                }
                else if(is_tilemap_in_bounds(pull_curr_tilemap_pos) &&
                (is_floor_traversable(pull_curr_floor) ||
                is_object_flying(target_1_object)) &&
                pull_curr_object == 0)
                {
                    //
                }
                else
                {
                    pull_go_on = 0;

                    if(!is_floor_traversable(pull_curr_floor) &&
                    !is_object_flying(target_1_object))
                    {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(pull_curr_tilemap_pos)
                        );
                    }
                }

                pull_curr_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);
                pull_curr_floor = room_get_floor_at(state->curr_room, pull_curr_tilemap_pos);
                pull_curr_object = room_get_object_at(state->curr_room, pull_curr_tilemap_pos);
            }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            if(!is_object_movable(target_1_object))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.immovable_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );

                break;
            }

            DistanceInfo pull_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    source_tilemap_pos
                    );

            int will_throw_after_pull = 1;

            Vec2i pull_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_next_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);

            int pull_curr_floor = room_get_floor_at(state->curr_room, pull_curr_tilemap_pos);
            int pull_next_floor = room_get_floor_at(state->curr_room, pull_next_tilemap_pos);

            Object* pull_curr_object = room_get_object_at(state->curr_room, pull_curr_tilemap_pos);
            Object* pull_next_object = room_get_object_at(state->curr_room, pull_next_tilemap_pos);

            int pull_go_on = 1;
            for(int i = 0; pull_go_on && i < pull_distance_info.abs_diff; i++)
            {
                if(vec2i_equals(pull_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(pull_curr_tilemap_pos, target_2_tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(target_1_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(pull_curr_tilemap_pos)
                        );
                }
                else if(is_tilemap_in_bounds(pull_curr_tilemap_pos) &&
                (is_floor_traversable(pull_curr_floor) ||
                is_object_flying(target_1_object)) &&
                pull_curr_object == 0)
                {
                    //
                }
                else
                {
                    pull_go_on = 0;
                    will_throw_after_pull = 0;
                }

                pull_curr_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);
                pull_curr_floor = room_get_floor_at(state->curr_room, pull_curr_tilemap_pos);
                pull_curr_object = room_get_object_at(state->curr_room, pull_curr_tilemap_pos);
            }

            if(!will_throw_after_pull)
            {
                Vec2i death_tilemap_pos = vec2i_move_in_dir4_by(
                    pull_curr_tilemap_pos,
                    get_opposite_dir4(pull_distance_info.dir4),
                    1);

            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(death_tilemap_pos)
                        );

                break;
            }

            if(is_object_movable(target_1_object))
            {
                if(is_floor_deadly_on_drop(room_get_floor_at(state->curr_room, target_2_tilemap_pos)) &&
                !is_object_flying(target_1_object))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
                }
                else if(target_2_object == 0)
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(target_1_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
                }
            }
            else
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.immovable_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );
            }
        }
        break;
        case SKILL__THROW:
        {
            if(is_object_movable(target_1_object))
            {
                if(is_floor_deadly_on_drop(room_get_floor_at(state->curr_room, target_2_tilemap_pos)) &&
                !is_object_flying(target_1_object))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.death_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
                }
                else
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        get_texture_1_from_object(target_1_object, textures)
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
                }
            }
            else
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.immovable_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );
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

                        if(object != 0)
                        {
                            if(is_object_meltable(object))
                            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.melt_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                        );
                            }
                        }
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            if(target_2_object != 0 && is_object_breakable(target_2_object))
            {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.break_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
            }

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.shake_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                        );
                }
            }
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            add_new_list_element_to_list_end(
                        texture_list,
                        textures->skill.shake_effect
                        );
                    add_new_list_element_to_list_end(
                        tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
        }
        break;
        default:
        break;
    }
}
