#include "../inc/state.h"

void skill_get_possible_target_2_pos(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    List* target_2_pos_list
)
{
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

    switch(skill)
    {
        case SKILL__USE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL &&
                       (object->type == OBJECT__THRONE ||
                        is_object_exit(object) ||
                        ((source_object->type == OBJECT__HERO || 
                        source_object->type == OBJECT__HERO_FLOATING || 
                        source_object->type == OBJECT__HERO_FLYING) && 
                        is_object_station(object) || is_object_secret(object))))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if((object != NULL && is_object_manipulatable(object)) ||
                       is_floor_manipulatable(floor))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__TELEPORTATION:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(object == NULL &&
                       !is_floor_deadly_on_move_for_object(floor, source_object))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__TELEKINESIS:
        {
            for(int dir4 = DIR4__NONE + 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i < 10 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, dir4, i);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    add_new_list_element_to_list_end(
                        target_2_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                    );

                    if(object != NULL)
                    {
                        go_on = FALSE;
                    }
                }
            }
        }
        break;
        case SKILL__MOVE:
        case SKILL__MOVE_FLOATING:
        case SKILL__MOVE_FLYING:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    List* path_tilemap_pos_list = new_list(
                        (void(*)(void*))destroy_vec2i
                    );
                    find_path(
                        state,
                        source_tilemap_pos,
                        tilemap_pos,
                        path_tilemap_pos_list,
                        is_object_floating(source_object),
                        is_object_flying(source_object)
                    );

                    if(path_tilemap_pos_list->size > 0 &&
                       (state->enemy_list->size == 0 ||
                        path_tilemap_pos_list->size <= state->curr_ally->object->action_points + 1))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }

                    remove_all_list_elements(
                        path_tilemap_pos_list,
                        1
                    );
                    destroy_list(path_tilemap_pos_list);
                }
            }
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL &&
                       get_object_item_type(object) != ITEM__NONE)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__PICK_ITEM_FAR:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object != NULL &&
                           get_object_item_type(object) != ITEM__NONE)
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL && (!is_object_throw_over(object) || is_object_wall(object)))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_CLOSE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL &&
                       is_object_put_item(object))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_FAR:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object != NULL &&
                           is_object_put_item(object))
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL &&
                       is_object_put_item(object))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object != NULL &&
                           is_object_put_item(object))
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL &&
                       is_object_put_item(object))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object != NULL &&
                           is_object_put_item(object))
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_THROW_ITEM_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        if(object != NULL && !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_THROW_ITEM_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        if(object != NULL && !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_THROW_ITEM_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        if(object != NULL && !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__SHOOT_PROJECTILE_FLY:
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= 10 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        if(object != NULL)
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__PUSH:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_PUSH_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        distance_info.dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        if(object != NULL)
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__THROW:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_THROW_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        distance_info.dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object == NULL)
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL &&
                           !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__DRAG_HOOK:
        case SKILL__DRAG_SPIDERWEB:
        case SKILL__DRAG_TENTACLE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_DRAG_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        get_opposite_dir4(distance_info.dir4),
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }

                    if(vec2i_equals(tilemap_pos, source_tilemap_pos))
                    {
                        go_on = FALSE;
                    }
                }
            }
        }
        break;
        case SKILL__PULL_HOOK:
        case SKILL__PULL_SPIDERWEB:
        case SKILL__PULL_TENTACLE:
        case SKILL__PULL_TONGUE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 0; i <= SKILL_PULL_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        get_opposite_dir4(distance_info.dir4),
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }

                    if(vec2i_equals(tilemap_pos, source_tilemap_pos))
                    {
                        go_on = FALSE;
                    }
                }
            }
        }
        break;
        case SKILL__JUMP:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_JUMP_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object == NULL)
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL &&
                           !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__CHARGE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_CHARGE_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object != NULL)
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__STOMP:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    add_new_list_element_to_list_end(
                        target_2_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                    );
                }
            }
        }
        break;
        case SKILL__DRAG_AND_THROW_HOOK:
        case SKILL__DRAG_AND_THROW_TONGUE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            int go_on = TRUE;
            for(int i = 1; i <= SKILL_THROW_RANGE && go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    get_opposite_dir4(distance_info.dir4),
                    i
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object == NULL)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }

                    if(object != NULL &&
                       !is_object_throw_over(object))
                    {
                        go_on = FALSE;
                    }
                }
            }
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_CHARGE_PUSH_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        distance_info.dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        if(object != NULL)
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_CHARGE_THROW_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        distance_info.dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object == NULL)
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL &&
                           !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__CHARGE_AND_JUMP:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            int go_on = TRUE;
            for(int i = 1; i <= SKILL_CHARGE_JUMP_RANGE && go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    target_1_tilemap_pos,
                    distance_info.dir4,
                    i
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object == NULL)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }

                    if(object != NULL &&
                       !is_object_throw_over(object))
                    {
                        go_on = FALSE;
                    }
                }
            }
        }
        break;
        case SKILL__JUMP_AND_CARRY:
        {
            DistanceInfo carry_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i <= SKILL_JUMP_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    Vec2i carry_tilemap_pos = vec2i_move_in_dir4_by(
                        tilemap_pos,
                        carry_distance_info.dir4,
                        1
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        Object* carry_object = room_get_object_at(
                            state->curr_room,
                            carry_tilemap_pos
                        );

                        if(object == NULL && carry_object == NULL)
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__JUMP_AND_STOMP:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_JUMP_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object == NULL)
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL &&
                           !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__LAUNCH_MINIBOT:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_LAUNCH_MINIBOT_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object == NULL)
                        {
                            add_new_list_element_to_list_end(
                                target_2_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL && !is_object_throw_over(object))
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__MINIBOT_MERGE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL &&
                       (object->type == OBJECT__HERO ||
                        object->type == OBJECT__HERO_FLOATING ||
                        object->type == OBJECT__HERO_FLYING))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_LASER:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    add_new_list_element_to_list_end(
                        target_2_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                    );
                }
            }
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i < 5; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i < 5 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );

                        if(object != NULL)
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        default:
        break;
    }
}
