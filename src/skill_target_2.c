#include "../inc/state.h"
#include <wchar.h>

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
    //     case SKILL__MANIPULATION:
    //     {
    //         for(int i = 0; i < TILEMAP_LENGTH; i++)
    //         {
    //             for(int j = 0; j < TILEMAP_LENGTH; j++)
    //             {
    //                 Vec2i tilemap_pos = vec2i(i, j);
    //                 Object* object = room_get_object_at(state->curr_room, tilemap_pos);
    //                 int floor = room_get_floor_at(state->curr_room, tilemap_pos);

    //                 if((object != NULL && is_object_manipulatable(object)) ||
    //                    (object == NULL && is_floor_manipulatable(floor)))
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__TELEPORTATION:
    //     {
    //         for(int i = 0; i < TILEMAP_LENGTH; i++)
    //         {
    //             for(int j = 0; j < TILEMAP_LENGTH; j++)
    //             {
    //                 Vec2i tilemap_pos = vec2i(i, j);
    //                 Object* object = room_get_object_at(state->curr_room, tilemap_pos);
    //                 int floor = room_get_floor_at(state->curr_room, tilemap_pos);

    //                 if(object == NULL &&
    //                    !is_floor_deadly_on_move_for_object(floor, source_object))
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__TELEKINESIS:
    //     {
    //         for(int dir4 = DIR4__NONE + 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i < 10 && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, dir4, i);
    //                 Object* object = room_get_object_at(state->curr_room, tilemap_pos);
    //                 int floor = room_get_floor_at(state->curr_room, tilemap_pos);

    //                 add_new_list_element_to_list_end(
    //                     target_2_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );

    //                 if(object != NULL)
    //                 {
    //                     go_on = FALSE;
    //                 }
    //             }
    //         }
    //     }
    //     break;
        case SKILL__MOVE:
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
        case SKILL__BURROW:
        case SKILL__BURY:
        {
            int floor_on_source = room_get_floor_at(state->curr_room, source_tilemap_pos);

            if(is_floor_burrow(floor_on_source))
            {
                for(int i = 0; i < TILEMAP_LENGTH; i++)
                {
                    for(int j = 0; j < TILEMAP_LENGTH; j++)
                    {
                        Vec2i tilemap_pos = vec2i(i, j);
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object == NULL && is_floor_burrow(floor))
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
    //     case SKILL__PICK_ITEM_CLOSE:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 dir4,
    //                 1
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Object* object = room_get_object_at(
    //                     state->curr_room,
    //                     tilemap_pos
    //                 );

    //                 if(object != NULL &&
    //                    get_object_item_type(object) != ITEM__NONE)
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__PICK_ITEM_FAR:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     if(object != NULL &&
    //                        get_object_item_type(object) != ITEM__NONE)
    //                     {
    //                         add_new_list_element_to_list_end(
    //                             target_2_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );
    //                     }

    //                     if(object != NULL && (!is_object_throw_over(object) || is_object_wall(object)))
    //                     {
    //                         go_on = FALSE;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__PUT_ITEM_CELL_CLOSE:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 dir4,
    //                 1
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Object* object = room_get_object_at(
    //                     state->curr_room,
    //                     tilemap_pos
    //                 );

    //                 if(object != NULL &&
    //                    is_object_put_item(object))
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__PUT_ITEM_CELL_FAR:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     if(object != NULL &&
    //                        is_object_put_item(object))
    //                     {
    //                         add_new_list_element_to_list_end(
    //                             target_2_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 dir4,
    //                 1
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Object* object = room_get_object_at(
    //                     state->curr_room,
    //                     tilemap_pos
    //                 );

    //                 if(object != NULL &&
    //                    is_object_put_item(object))
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__PUT_ITEM_DYNAMITE_FAR:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     if(object != NULL &&
    //                        is_object_put_item(object))
    //                     {
    //                         add_new_list_element_to_list_end(
    //                             target_2_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 dir4,
    //                 1
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Object* object = room_get_object_at(
    //                     state->curr_room,
    //                     tilemap_pos
    //                 );

    //                 if(object != NULL &&
    //                    is_object_put_item(object))
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__PUT_ITEM_GEMSTONE_FAR:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             for(int i = 1; i <= SKILL_PICK_AND_PUT_ITEM_FAR_RANGE; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     if(object != NULL &&
    //                        is_object_put_item(object))
    //                     {
    //                         add_new_list_element_to_list_end(
    //                             target_2_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__THROW_ITEM_CELL:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i <= SKILL_THROW_ITEM_RANGE && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );

    //                     if(object != NULL && !is_object_throw_over(object))
    //                     {
    //                         go_on = FALSE;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__THROW_ITEM_DYNAMITE:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i <= SKILL_THROW_ITEM_RANGE && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );

    //                     if(object != NULL && !is_object_throw_over(object))
    //                     {
    //                         go_on = FALSE;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__THROW_ITEM_GEMSTONE:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i <= SKILL_THROW_ITEM_RANGE && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );

    //                     if(object != NULL && !is_object_throw_over(object))
    //                     {
    //                         go_on = FALSE;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__SHOOT_PROJECTILE_FLY:
    //     case SKILL__SHOOT_PROJECTILE_SQUIRREL:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i <= 10 && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );

    //                     if(object != NULL)
    //                     {
    //                         go_on = FALSE;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
        case SKILL__PUSH:
        case SKILL__PUSH_DAMAGE:
        case SKILL__PUNCH:
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
        case SKILL__THROW_DAMAGE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );
            
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                if(dir4 != get_opposite_dir4(distance_info.dir4))
                {
                    int go_on = TRUE;
                    for(int i = 1; i <= SKILL_THROW_RANGE && go_on; i++)
                    {
                        Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                            target_1_tilemap_pos,
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
        }
        break;
        case SKILL__DRILL:
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

                    if(object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__DRILL_FLOOR:
        case SKILL__NAIL_FLOOR:
        {
            if(get_floor_not_burrow_into_burrow(source_floor) != FLOOR__NONE)
            {
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(source_tilemap_pos)
                );
            }

            for(int dir4 = 0; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room,tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room,tilemap_pos);

                    if(object == NULL && get_floor_not_burrow_into_burrow(floor) != FLOOR__NONE)
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
        case SKILL__LASER_WELD_FLOOR:
        case SKILL__FIRE_WELD_FLOOR:
        {
            if(get_floor_burrow_into_not_burrow(source_floor) != FLOOR__NONE)
            {
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(source_tilemap_pos)
                );
            }

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    1
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room,tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room,tilemap_pos);

                    if(object == NULL && get_floor_burrow_into_not_burrow(floor) != FLOOR__NONE)
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
        case SKILL__PENETRATING_BEAM:
        {
            for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir8_by(
                    source_tilemap_pos,
                    dir8,
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
        case SKILL__BOUNCING_BEAM:
        case SKILL__RICOSHET:
        {
            for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
            {
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(target_1_tilemap_pos, dir8, i);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(!vec2i_equals(tilemap_pos, source_tilemap_pos) && 
                    object != NULL && get_object_max_hp(object) != -1)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                        go_on = FALSE;
                    }
                }
            }
        }
        break;
        case SKILL__FOCUSED_BEAM:
        case SKILL__COOKING_BOLT:
        {
            for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
            {
                int go_on = TRUE;
                for(int i = 1; i < 3 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, dir8, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        if(object) go_on = FALSE;
                    }
                }

                if(!go_on) continue;

                go_on = TRUE;
                for(int i = 3; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, dir8, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object) go_on = FALSE;

                        if(!vec2i_equals(tilemap_pos, source_tilemap_pos) && 
                        object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__BRANCHING_BOLT:
        {
            for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, dir8, 1);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(object != NULL && !is_object_wall(object))
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
        case SKILL__STUNNING_BOLT:
        {
            for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
            {
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, dir8, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object) go_on = FALSE;

                        if(object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__ELECTRIFY_FLOOR:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(object == NULL && floor == FLOOR__WATER)
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
        case SKILL__SCORCH_WITH_FIRE:
        {
            for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, dir8, 1);

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
        case SKILL__DRAG:
    //     case SKILL__DRAG_HOOK:
    //     case SKILL__DRAG_SPIDERWEB:
    //     case SKILL__DRAG_TENTACLE:
        case SKILL__HARPOON_SHOT:
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
        // case SKILL__PULL_HOOK:
        // case SKILL__PULL_SPIDERWEB:
        // case SKILL__PULL_TENTACLE:
        // case SKILL__PULL_TONGUE:
        case SKILL__PULL:
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
        case SKILL__JUMP_AND_NAIL:
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
        case SKILL__ROCKET_JUMP:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_ROCKET_JUMP_RANGE && go_on; i++)
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
        case SKILL__CHARGE_AND_DAMAGE_3:
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
                            // go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__ROCKET_DASH:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_ROCKET_CHARGE_RANGE && go_on; i++)
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
        case SKILL__ICE_BLOCK:
        case SKILL__ICE_WALL:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= TILEMAP_LENGTH && go_on; i++)
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
                        else
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__ICE_BUNKER:
        {
            add_new_list_element_to_list_end(
                target_2_pos_list,
                new_vec2i_from_vec2i(source_tilemap_pos)
            );
        }
        break;
        case SKILL__ICE_PROJECTILE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= TILEMAP_LENGTH && go_on; i++)
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
        case SKILL__FREEZE_FLOOR:
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
        case SKILL__POINT_BLANK_SHOT:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    
                    if(object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__LONG_SHOT:
        case SKILL__STUNNING_SHOT:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object) go_on = FALSE;

                        if(!vec2i_equals(tilemap_pos, source_tilemap_pos) && 
                        object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__HEAD_SHOT:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);
                Vec2i back_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 2);

                if(is_tilemap_in_bounds(tilemap_pos) && is_tilemap_in_bounds(back_tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);
                    Object* back_object = room_get_object_at(state->curr_room, back_tilemap_pos);
                    int back_floor = room_get_floor_at(state->curr_room, back_tilemap_pos);


                    if(object != NULL && get_object_max_hp(object) != -1 && back_object == NULL)
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
        case SKILL__HIGH_PROJECTILE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i < TILEMAP_LENGTH; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(!vec2i_equals(tilemap_pos, source_tilemap_pos) && 
                        object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__DOUBLE_JUMP:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i <= SKILL_JUMP_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
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
                    }
                }
            }
        }
        break;
        case SKILL__NEST:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);

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
        case SKILL__NAIL:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4,1);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room,tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room,tilemap_pos);

                    if(object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__SWING:
        {
            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            int dir4_1 = DIR4__NONE;
            int dir4_2 = DIR4__NONE;

            switch(distance_info.dir8)
            {
                case DIR8__UP_LEFT:     dir4_1 = DIR4__UP;      dir4_2 = DIR4__LEFT;    break;
                case DIR8__UP_RIGHT:    dir4_1 = DIR4__UP;      dir4_2 = DIR4__RIGHT;   break;
                case DIR8__DOWN_RIGHT:  dir4_1 = DIR4__DOWN;    dir4_2 = DIR4__RIGHT;   break;
                case DIR8__DOWN_LEFT:   dir4_1 = DIR4__DOWN;    dir4_2 = DIR4__LEFT;    break;
                default:
                break;
            }

            int go_on = TRUE;
            for(int i = 1; i <= SKILL_PUSH_RANGE && go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos,dir4_1,i);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room,tilemap_pos);

                    add_new_list_element_to_list_end(
                        target_2_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                    );

                    if(object != NULL) go_on = FALSE;
                }
            }

            go_on = TRUE;
            for(int i = 1; i <= SKILL_PUSH_RANGE && go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos,dir4_2,i);

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room,tilemap_pos);

                    add_new_list_element_to_list_end(
                        target_2_pos_list,
                        new_vec2i_from_vec2i(tilemap_pos)
                    );

                    if(object != NULL) go_on = FALSE;
                }
            }
        }
        break;
    //     case SKILL__STOMP:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 dir4,
    //                 1
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 add_new_list_element_to_list_end(
    //                     target_2_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__DRAG_AND_THROW_HOOK:
    //     case SKILL__DRAG_AND_THROW_TONGUE:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_1_tilemap_pos
    //             );

    //         int go_on = TRUE;
    //         for(int i = 1; i <= SKILL_THROW_RANGE && go_on; i++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 get_opposite_dir4(distance_info.dir4),
    //                 i
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Object* object = room_get_object_at(
    //                     state->curr_room,
    //                     tilemap_pos
    //                 );

    //                 if(object == NULL)
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }

    //                 if(object != NULL &&
    //                    !is_object_throw_over(object))
    //                 {
    //                     go_on = FALSE;
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__CHARGE_AND_PUSH:
        case SKILL__CHARGE_AND_PUNCH:
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
        case SKILL__BURROW_AND_GTFO:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_THROW_RANGE && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
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
        case SKILL__THRUST:
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

                    if(object != NULL && get_object_max_hp(object) != -1)
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
        case SKILL__PENETRATING_THRUST:
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
        case SKILL__HEAD_SLICE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);
                Vec2i back_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 2);

                if(is_tilemap_in_bounds(tilemap_pos) && is_tilemap_in_bounds(back_tilemap_pos))
                {
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);
                    Object* back_object = room_get_object_at(state->curr_room, back_tilemap_pos);
                    int back_floor = room_get_floor_at(state->curr_room, back_tilemap_pos);


                    if(object != NULL && get_object_max_hp(object) != -1 && back_object == NULL)
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
        case SKILL__BURROW_AND_SLICE:
        {
            int floor_on_source = room_get_floor_at(state->curr_room, source_tilemap_pos);

            if(is_floor_burrow(floor_on_source))
            {
                for(int i = 0; i < TILEMAP_LENGTH; i++)
                {
                    for(int j = 0; j < TILEMAP_LENGTH; j++)
                    {
                        Vec2i tilemap_pos = vec2i(i, j);
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object != NULL && get_object_max_hp(object) != -1 && is_floor_burrow(floor) && object != state->hero_object)
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
        case SKILL__CHARGE_AND_SLICE:
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
        case SKILL__WHIP_SMACK:
        {
            Vec2i up_left_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__UP_LEFT, 1);
            Vec2i up_right_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__UP_RIGHT, 1);
            Vec2i down_right_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__DOWN_RIGHT, 1);
            Vec2i down_left_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__DOWN_LEFT, 1);

            add_new_list_element_to_list_end(
                target_2_pos_list,
                new_vec2i_from_vec2i(up_left_tilemap_pos)
            );
            add_new_list_element_to_list_end(
                target_2_pos_list,
                new_vec2i_from_vec2i(up_right_tilemap_pos)
            );
            add_new_list_element_to_list_end(
                target_2_pos_list,
                new_vec2i_from_vec2i(down_right_tilemap_pos)
            );
            add_new_list_element_to_list_end(
                target_2_pos_list,
                new_vec2i_from_vec2i(down_left_tilemap_pos)
            );

            for(int i = 1; i < SKILL_WHIP_RANGE; i++)
            {
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_left_tilemap_pos, DIR4__UP, i))
                );
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_left_tilemap_pos, DIR4__LEFT, i))
                );

                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_right_tilemap_pos, DIR4__UP, i))
                );
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_right_tilemap_pos, DIR4__RIGHT, i))
                );

                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_right_tilemap_pos, DIR4__DOWN, i))
                );
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_right_tilemap_pos, DIR4__RIGHT, i))
                );

                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_left_tilemap_pos, DIR4__DOWN, i))
                );
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_left_tilemap_pos, DIR4__LEFT, i))
                );
            }
        }
        break;
        case SKILL__WHIP_PULL:
        {
            if(target_1_object != NULL && is_object_movable(target_1_object))
            {
                DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, source_tilemap_pos);

                if(distance_info.x_diff < -1)
                {
                    for(int i = 0; i < distance_info.abs_x_diff; i++)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__LEFT, i))
                        );
                    }
                }

                if(distance_info.x_diff > 1)
                {
                    for(int i = 0; i < distance_info.abs_x_diff; i++)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__RIGHT, i))
                        );
                    }
                }

                if(distance_info.y_diff < -1)
                {
                    for(int i = 0; i < distance_info.abs_y_diff; i++)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__UP, i))
                        );
                    }
                }

                if(distance_info.y_diff > 1)
                {
                    for(int i = 0; i < distance_info.abs_y_diff; i++)
                    {
                        add_new_list_element_to_list_end(
                            target_2_pos_list,
                            new_vec2i_from_vec2i(vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__DOWN, i))
                        );
                    }
                }
            }
        }
        break;
    //     case SKILL__JUMP_AND_STOMP:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i <= SKILL_JUMP_RANGE && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     if(object == NULL)
    //                     {
    //                         add_new_list_element_to_list_end(
    //                             target_2_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );
    //                     }

    //                     if(object != NULL &&
    //                        !is_object_throw_over(object))
    //                     {
    //                         go_on = FALSE;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
        case SKILL__LAUNCH_MINIBOT:
        case SKILL__SPEW_TAR_BALL:
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
    //     case SKILL__TURRET_LASER:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 dir4,
    //                 1
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 add_new_list_element_to_list_end(
    //                     target_2_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__TURRET_BOMB:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             for(int i = 1; i < 5; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__TURRET_PROJECTILE:
    //     {
    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             int go_on = TRUE;
    //             for(int i = 1; i < 5 && go_on; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     add_new_list_element_to_list_end(
    //                         target_2_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );

    //                     if(object != NULL)
    //                     {
    //                         go_on = FALSE;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
        default:
        break;
    }
}
