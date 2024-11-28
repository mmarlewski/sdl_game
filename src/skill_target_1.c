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
        case SKILL__USE:
        {
            //
        }
        break;
        case SKILL__MANIPULATION:
        {
            //
        }
        break;
        case SKILL__TELEPORTATION:
        {
            //
        }
        break;
        case SKILL__MOVE:
        case SKILL__MOVE_FLOATING:
        case SKILL__MOVE_FLYING:
        {
            //
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        {
            //
        }
        break;
        case SKILL__PICK_ITEM_FAR:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_CELL_CLOSE:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_CELL_FAR:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_DYNAMITE_FAR:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
        {
            //
        }
        break;
        case SKILL__PUT_ITEM_GEMSTONE_FAR:
        {
            //
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            //
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            //
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            //
        }
        break;
        case SKILL__SHOOT_PROJECTILE_FLY:
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:
        {
            //
        }
        break;
        case SKILL__PUSH:
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
        case SKILL__DRAG_HOOK:
        case SKILL__DRAG_SPIDERWEB:
        case SKILL__DRAG_TENTACLE:
        case SKILL__DRAG_AND_THROW_HOOK:
        case SKILL__DRAG_AND_THROW_TONGUE:
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
        case SKILL__PULL_HOOK:
        case SKILL__PULL_SPIDERWEB:
        case SKILL__PULL_TENTACLE:
        case SKILL__PULL_TONGUE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = TRUE;
                for(int i = 1; i <= SKILL_PULL_RANGE && go_on; i++)
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
                           is_object_pull_towards(object))
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
        case SKILL__CHARGE_AND_PUSH:
        case SKILL__CHARGE_AND_THROW:
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
        case SKILL__JUMP_AND_STOMP:
        {
            //
        }
        break;
        case SKILL__LAUNCH_MINIBOT:
        {
            //
        }
        break;
        case SKILL__MINIBOT_MERGE:
        {
            //
        }
        break;
        case SKILL__TURRET_LASER:
        {
            //
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            //
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            //
        }
        break;
        default:
        break;
    }
}
