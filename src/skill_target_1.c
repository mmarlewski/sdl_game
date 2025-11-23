#include "../inc/state.h"

void skill_get_possible_target_1_pos(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    List* target_1_pos_list
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

    switch(skill)
    {
    //     case SKILL__TELEKINESIS:
    //     {
    //         for(int i = 0; i < TILEMAP_LENGTH; i++)
    //         {
    //             for(int j = 0; j < TILEMAP_LENGTH; j++)
    //             {
    //                 Vec2i tilemap_pos = vec2i(i, j);
    //                 Object* object = room_get_object_at(state->curr_room, tilemap_pos);
    //                 int floor = room_get_floor_at(state->curr_room, tilemap_pos);

    //                 if(object != NULL &&
    //                 is_object_movable(object))
    //                 {
    //                     add_new_list_element_to_list_end(
    //                         target_1_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
        case SKILL__PUSH:
        case SKILL__PUNCH:
        case SKILL__THROW:
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

                    if(object != NULL && is_object_movable(object))
                    {
                        add_new_list_element_to_list_end(
                            target_1_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
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
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, dir8, i);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(object != NULL && !is_object_wall(object))
                    {
                        add_new_list_element_to_list_end(
                            target_1_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                        go_on = FALSE;
                    }
                }
            }
        }
        break;
    //     case SKILL__DRAG_HOOK:
    //     case SKILL__DRAG_SPIDERWEB:
    //     case SKILL__DRAG_TENTACLE:
    //     case SKILL__DRAG_AND_THROW_HOOK:
    //     case SKILL__DRAG_AND_THROW_TONGUE:
        case SKILL__HARPOON_SHOT:
        case SKILL__BURY:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_DRAG_RANGE && go_on; i++)
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

                        if(object != NULL && is_object_movable(object))
                        {
                            add_new_list_element_to_list_end(
                                target_1_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL)
                        {
                            go_on = FALSE;
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

                        if(object != NULL && get_object_max_hp(object) != -1)
                        {
                            add_new_list_element_to_list_end(
                                target_1_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__SWING:
        {
            for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
            {
                if(dir8 == DIR8__UP_LEFT || dir8 == DIR8__UP_RIGHT || dir8 == DIR8__DOWN_RIGHT || dir8 == DIR8__DOWN_LEFT)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, dir8,1);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room,tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room,tilemap_pos);

                        if(object != NULL && get_object_max_hp(object) != -1 && is_object_movable(object))
                        {
                            add_new_list_element_to_list_end(
                                target_1_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }
        }
        break;
    //     case SKILL__PULL_HOOK:
    //     case SKILL__PULL_SPIDERWEB:
    //     case SKILL__PULL_TENTACLE:
    //     case SKILL__PULL_TONGUE:
        // {
        //     for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
        //     {
        //         int go_on = TRUE;
        //         for(int i = 1; i <= SKILL_PULL_RANGE && go_on; i++)
        //         {
        //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
        //                 source_tilemap_pos,
        //                 dir4,
        //                 i
        //             );

        //             if(is_tilemap_in_bounds(tilemap_pos))
        //             {
        //                 Object* object = room_get_object_at(
        //                     state->curr_room,
        //                     tilemap_pos
        //                 );

        //                 if(object != NULL &&
        //                    is_object_pull_towards(object))
        //                 {
        //                     add_new_list_element_to_list_end(
        //                         target_1_pos_list,
        //                         new_vec2i_from_vec2i(tilemap_pos)
        //                     );
        //                 }

        //                 if(object != NULL)
        //                 {
        //                     go_on = FALSE;
        //                 }
        //             }
        //         }
        //     }
        // }
        // break;
        // case SKILL__CHARGE_AND_PUSH:
        // case SKILL__CHARGE_AND_THROW:
        case SKILL__CHARGE_AND_PUNCH:
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
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object != NULL &&
                           is_object_movable(object))
                        {
                            add_new_list_element_to_list_end(
                                target_1_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL)
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
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object == NULL)
                        {
                            add_new_list_element_to_list_end(
                                target_1_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }

                        if(object != NULL)
                        {
                            go_on = FALSE;
                        }
                    }
                }
            }
        }
        break;
        case SKILL__JUMP_AND_CARRY:
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
                       is_object_movable(object))
                    {
                        add_new_list_element_to_list_end(
                            target_1_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__BURROW_AND_GTFO:
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

                        if(object != NULL && get_object_max_hp(object) != -1 && is_object_movable(object) && is_floor_burrow(floor))
                        {
                            add_new_list_element_to_list_end(
                                target_1_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }
        }
        break;
        case SKILL__WHIP_PULL:
        {
            Vec2i up_left_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__UP_LEFT, 1);
            Vec2i up_right_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__UP_RIGHT, 1);
            Vec2i down_right_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__DOWN_RIGHT, 1);
            Vec2i down_left_tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, DIR8__DOWN_LEFT, 1);

            // add_new_list_element_to_list_end(
            //     target_1_pos_list,
            //     new_vec2i_from_vec2i(up_left_tilemap_pos)
            // );
            // add_new_list_element_to_list_end(
            //     target_1_pos_list,
            //     new_vec2i_from_vec2i(up_right_tilemap_pos)
            // );
            // add_new_list_element_to_list_end(
            //     target_1_pos_list,
            //     new_vec2i_from_vec2i(down_right_tilemap_pos)
            // );
            // add_new_list_element_to_list_end(
            //     target_1_pos_list,
            //     new_vec2i_from_vec2i(down_left_tilemap_pos)
            // );

            for(int i = 1; i < SKILL_WHIP_RANGE; i++)
            {
                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_left_tilemap_pos, DIR4__UP, i))
                );
                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_left_tilemap_pos, DIR4__LEFT, i))
                );

                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_right_tilemap_pos, DIR4__UP, i))
                );
                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(up_right_tilemap_pos, DIR4__RIGHT, i))
                );

                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_right_tilemap_pos, DIR4__DOWN, i))
                );
                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_right_tilemap_pos, DIR4__RIGHT, i))
                );

                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_left_tilemap_pos, DIR4__DOWN, i))
                );
                add_new_list_element_to_list_end(
                    target_1_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(down_left_tilemap_pos, DIR4__LEFT, i))
                );
            }
        }
        break;
        default:
        break;
    }
}
