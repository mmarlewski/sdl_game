#include "../inc/state.h"

void skill_get_possible_hint_pos(
    State* state,
    int skill,
    List* hint_pos_list
)
{
    switch(skill)
    {
        case SKILL__USE:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL && 
                    (is_object_exit(object) || is_object_station(object)))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
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
        case SKILL__PICK_ITEM_FAR:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL && get_object_item_type(object) != ITEM__NONE)
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
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
            //
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if((object != NULL && is_object_meltable(object)) ||
                    is_floor_meltable(floor))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if((object != NULL && is_object_breakable(object)) ||
                    is_floor_breakable(floor))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if((object != NULL && is_object_fragile(object)) ||
                    is_floor_fragile(floor))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
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
        case SKILL__DRAG_HOOK:
        case SKILL__DRAG_SPIDERWEB:
        case SKILL__DRAG_TENTACLE:
        case SKILL__DRAG_AND_THROW_HOOK:
        case SKILL__DRAG_AND_THROW_TONGUE:
        case SKILL__CHARGE_AND_PUSH:
        case SKILL__CHARGE_AND_THROW:
        case SKILL__JUMP_AND_CARRY:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL && is_object_movable(object))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
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
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL && is_object_pull_towards(object))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
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
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL && is_object_fragile(object))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__STOMP:
        case SKILL__JUMP_AND_STOMP:
        {
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if((object != NULL && is_object_stomp(object)) ||
                    is_floor_stomp(floor))
                    {
                        add_new_list_element_to_list_end(
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
        }
        break;
        case SKILL__CHARGE_AND_JUMP:
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
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);

                    int floor = room_get_floor_at(
                        state->curr_room, 
                        tilemap_pos
                    );

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
                            hint_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }
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
