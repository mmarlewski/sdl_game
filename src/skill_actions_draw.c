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
            }
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
            //
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
