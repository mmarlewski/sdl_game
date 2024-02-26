#include "../inc/state.h"

void skill_get_actions_and_draw(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    Action* action_sequence,
    List* draw_below_texture_list,
    List* draw_below_tilemap_pos_list,
    List* draw_above_texture_list,
    List* draw_above_tilemap_pos_list,
    List* draw_effect_texture_list,
    List* draw_effect_tilemap_pos_list,
    Textures* textures
)
{
    if(!is_tilemap_in_bounds(source_tilemap_pos) ||
    !is_tilemap_in_bounds(target_1_tilemap_pos) ||
    !is_tilemap_in_bounds(target_2_tilemap_pos))
    {
        return;
    }

    Object* source_object = room_get_object_at(
        state->curr_room,
        source_tilemap_pos
        );
    int source_floor = room_get_floor_at(
        state->curr_room,
        source_tilemap_pos
        );
    Object* target_1_object = room_get_object_at(
        state->curr_room,
        target_1_tilemap_pos
        );
    int target_1_floor = room_get_floor_at(
        state->curr_room,
        target_1_tilemap_pos
        );
    Object* target_2_object = room_get_object_at(
        state->curr_room,
        target_2_tilemap_pos
        );
    int target_2_floor = room_get_floor_at(
        state->curr_room,
        target_2_tilemap_pos
        );

    switch (skill)
    {
        case SKILL__USE:
        {
            if(target_2_object != 0 &&
            (is_object_station(target_2_object) ||
            is_object_exit(target_2_object)))
            {
                if(is_object_station(target_2_object))
                {
                    // actions
                    add_action_after_curr_action_action_sequence(
                        action_sequence,
                        new_action_change_object(
                            OBJECT_TYPE__STATION_TAKEN,
                            target_2_tilemap_pos
                            )
                        );
                }

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.use_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            if(target_2_object != 0 &&
            is_object_manipulatable(target_2_object))
            {
                // actions
                object_on_manipulate(
                    state,
                    action_sequence,
                    target_2_object,
                    target_2_tilemap_pos
                    );

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.manipulation_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
            else if(target_2_floor != FLOOR_TYPE__NONE &&
            is_floor_manipulatable(target_2_floor))
            {
                // actions
                floor_on_manipulation(
                    state,
                    action_sequence,
                    target_2_floor,
                    target_2_tilemap_pos
                    );

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.manipulation_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__TELEPORTATION:
        {
            if(target_2_object == 0)
            {
                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.teleportation_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__MOVE:
        case SKILL__MOVE_FLOATING:
        case SKILL__MOVE_FLYING:
        {
            if(source_object != 0 && target_2_object == 0)
            {
                List* path_tilemap_pos_list = new_list(
                    (void(*)(void*))destroy_vec2i
                    );
                find_path(
                    state,
                    source_tilemap_pos,
                    target_2_tilemap_pos,
                    path_tilemap_pos_list,
                    is_object_floating(source_object),
                    is_object_flying(source_object)
                    );

                state->ally_move_distance = path_tilemap_pos_list->size - 1;

                if(path_tilemap_pos_list->size > 0)
                {
                    ListElem* prev_elem = 0;
                    ListElem* curr_elem = path_tilemap_pos_list->head;
                    ListElem* next_elem = (curr_elem) ? (curr_elem->next) : (0);

                    Vec2i* prev_tilemap_pos = (prev_elem) ? (prev_elem->data) : (0);
                    Vec2i* curr_tilemap_pos = (curr_elem) ? (curr_elem->data) : (0);
                    Vec2i* next_tilemap_pos = (next_elem) ? (next_elem->data) : (0);

                    while(curr_elem != 0)
                    {
                        if(next_elem != 0)
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_move(
                                    *curr_tilemap_pos,
                                    get_distance_info_from_vec2i_to_vec2i(
                                        *curr_tilemap_pos,
                                        *next_tilemap_pos
                                        ).dir4
                                    )
                                );
                        }

                        Texture* arrow_texture = 0;

                        if(prev_elem == 0)
                        {
                            arrow_texture = get_texture_arrow_thin_start(
                                textures,
                                get_distance_info_from_vec2i_to_vec2i(
                                    *curr_tilemap_pos,
                                    *next_tilemap_pos
                                    ).dir4
                                );
                        }
                        else if(next_elem == 0)
                        {
                            arrow_texture = get_texture_arrow_thin_end(
                                textures,
                                get_distance_info_from_vec2i_to_vec2i(
                                    *curr_tilemap_pos,
                                    *prev_tilemap_pos
                                    ).dir4
                                );
                        }
                        else
                        {
                            arrow_texture = get_texture_arrow_thin_from_to(
                                textures,
                                get_distance_info_from_vec2i_to_vec2i(
                                    *curr_tilemap_pos,
                                    *prev_tilemap_pos
                                    ).dir4,
                                get_distance_info_from_vec2i_to_vec2i(
                                    *curr_tilemap_pos,
                                    *next_tilemap_pos
                                    ).dir4
                                );
                        }

                        // draw below
                        add_new_list_element_to_list_end(
                            draw_below_texture_list,
                            arrow_texture
                            );
                        add_new_list_element_to_list_end(
                            draw_below_tilemap_pos_list,
                            new_vec2i_from_vec2i(*curr_tilemap_pos)
                            );

                        prev_elem = curr_elem;
                        curr_elem = next_elem;
                        next_elem = (curr_elem) ? (curr_elem->next) : (0);

                        prev_tilemap_pos = (prev_elem) ? (prev_elem->data) : (0);
                        curr_tilemap_pos = (curr_elem) ? (curr_elem->data) : (0);
                        next_tilemap_pos = (next_elem) ? (next_elem->data) : (0);
                    }
                }

                remove_all_list_elements(
                    path_tilemap_pos_list,
                    1
                    );
                destroy_list(path_tilemap_pos_list);

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    get_texture_1_from_object(source_object, textures)
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        case SKILL__PICK_ITEM_FAR:
        {
            if(target_2_object != 0)
            {
                // actions
                object_on_pick_item(
                    state,
                    action_sequence,
                    target_2_object,
                    target_2_tilemap_pos
                    );

                int item_type = get_object_item_type(target_2_object);
                int item_count = get_object_item_count(target_2_object);

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    get_texture_item(
                        textures,
                        item_type,
                        item_count
                        )
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(source_tilemap_pos)
                    );
            }
            else if(target_2_floor != FLOOR_TYPE__NONE)
            {
                // actions
                floor_on_pick_item(
                    state,
                    action_sequence,
                    target_2_floor,
                    target_2_tilemap_pos
                    );

                int item_type = get_floor_item_type(target_2_floor);
                int item_count = get_floor_item_count(target_2_floor);

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    get_texture_item(
                        textures,
                        item_type,
                        item_count
                        )
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
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
                // actions
                object_on_put_item(
                    state,
                    action_sequence,
                    target_2_object,
                    target_2_tilemap_pos,
                    item_type
                    );

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    get_texture_item(textures, item_type, -1)
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(source_tilemap_pos)
                    );
            }
            else if(target_2_floor != FLOOR_TYPE__NONE)
            {
                // actions
                floor_on_put_item(
                    state,
                    action_sequence,
                    target_2_floor,
                    target_2_tilemap_pos,
                    item_type
                    );

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    get_texture_item(textures, item_type, -1)
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(source_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_melt(target_2_tilemap_pos)
                );

            // draw effect
            add_new_list_element_to_list_end(
                draw_effect_texture_list,
                get_texture_item(textures, ITEM__CELL, -1)
                );
            add_new_list_element_to_list_end(
                draw_effect_tilemap_pos_list,
                new_vec2i_from_vec2i(source_tilemap_pos)
                );

            if(target_2_object != 0 &&
            is_object_meltable(target_2_object))
            {
                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.melt_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_break(target_2_tilemap_pos)
                );

            // draw effect
            add_new_list_element_to_list_end(
                draw_effect_texture_list,
                get_texture_item(textures, ITEM__DYNAMITE, -1)
                );
            add_new_list_element_to_list_end(
                draw_effect_tilemap_pos_list,
                new_vec2i_from_vec2i(source_tilemap_pos)
                );

            if(target_2_object != 0 &&
            is_object_breakable(target_2_object))
            {
                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.break_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_shake(target_2_tilemap_pos)
                );

            // draw effect
            add_new_list_element_to_list_end(
                draw_effect_texture_list,
                get_texture_item(textures, ITEM__GEMSTONE, -1)
                );
            add_new_list_element_to_list_end(
                draw_effect_tilemap_pos_list,
                new_vec2i_from_vec2i(source_tilemap_pos)
                );

            if(target_2_object != 0)
            {
                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.shake_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__PUSH:
        {
            //
        }
        break;
        case SKILL__THROW:
        {
            //
        }
        break;
        case SKILL__PULL:
        {
            //
        }
        break;
        case SKILL__JUMP:
        {
            //
        }
        break;
        case SKILL__CHARGE:
        {
            //
        }
        break;
        case SKILL__STOMP:
        {
            //
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            //
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            //
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            //
        }
        break;
        case SKILL__CHARGE_AND_JUMP:
        {
            //
        }
        break;
        case SKILL__JUMP_AND_CARRY:
        {
            //
        }
        break;
        case SKILL__JUMP_AND_STOMP:
        {
            //
        }
        break;
        case SKILL__LAUNCH_MINIBOT:
        {
            if(target_2_object == 0)
            {
                DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                    );

                // actions
                add_action_after_curr_action_action_sequence(
                    action_sequence,
                    new_action_add_object(
                        state->minibot_object,
                        target_2_tilemap_pos
                        )
                    );
                add_action_after_curr_action_action_sequence(
                    action_sequence,
                    new_action_drop(
                        state->minibot_object,
                        target_2_tilemap_pos,
                        distance_info.dir4
                        )
                    );

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->object.minibot_ally_1
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }
        }
        break;
        case SKILL__ASCEND:
        {
            //
        }
        break;
        case SKILL__DESCEND:
        {
            //
        }
        break;
        case SKILL__TURRET_LASER:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                    );

            if(distance_info.dir4 != DIR4__NONE)
            {
                for(int i = 1; i <= OBJECT_TURRET_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        distance_info.dir4,
                        i
                        );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                            );

                        if(object != 0 && is_object_meltable(object))
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_melt(tilemap_pos)
                                );

                            // draw below
                            add_new_list_element_to_list_end(
                                draw_below_texture_list,
                                textures->skill.floor_danger
                                );
                            add_new_list_element_to_list_end(
                                draw_below_tilemap_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                                );

                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.melt_effect
                                );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                                );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_break(target_2_tilemap_pos)
                );

            // draw below
            add_new_list_element_to_list_end(
                draw_below_texture_list,
                textures->skill.floor_danger
                );
            add_new_list_element_to_list_end(
                draw_below_tilemap_pos_list,
                new_vec2i_from_vec2i(target_2_tilemap_pos)
                );

            if(target_2_object != 0 && is_object_breakable(target_2_object))
            {
                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.break_effect
                    );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
            }

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    target_2_tilemap_pos,
                    dir4,
                    1
                    );
                Object* object = room_get_object_at(
                    state->curr_room,
                    tilemap_pos
                    );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    // actions
                    add_action_to_end_action_sequence(
                        action_sequence,
                        new_action_shake(tilemap_pos)
                        );

                    // draw below
                    add_new_list_element_to_list_end(
                        draw_below_texture_list,
                        textures->skill.floor_danger
                        );
                    add_new_list_element_to_list_end(
                        draw_below_tilemap_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                        );

                    if(object != 0)
                    {
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.shake_effect
                            );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                            );
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_shake(target_2_tilemap_pos)
                );

            // draw below
            add_new_list_element_to_list_end(
                draw_below_texture_list,
                textures->skill.floor_danger
                );
            add_new_list_element_to_list_end(
                draw_below_tilemap_pos_list,
                new_vec2i_from_vec2i(target_2_tilemap_pos)
                );

            // draw effect
            add_new_list_element_to_list_end(
                draw_effect_texture_list,
                textures->skill.shake_effect
                );
            add_new_list_element_to_list_end(
                draw_effect_tilemap_pos_list,
                new_vec2i_from_vec2i(target_2_tilemap_pos)
                );
        }
        break;
        default:
        break;
    }
}
