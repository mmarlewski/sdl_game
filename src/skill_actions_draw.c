#include "../inc/state.h"
#include <stdio.h>

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
    Textures* textures,
    Sounds* sounds
)
{
    if(!is_tilemap_in_bounds(target_1_tilemap_pos) ||
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

    switch(skill)
    {
        case SKILL__ATTACK_DIR:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            Texture* above_texture = NULL;

            switch(distance_info.dir4)
            {
                case DIR4__UP: above_texture = textures->skill.attack_dir4_up; break;
                case DIR4__RIGHT: above_texture = textures->skill.attack_dir4_right; break;
                case DIR4__DOWN: above_texture = textures->skill.attack_dir4_down; break;
                case DIR4__LEFT: above_texture = textures->skill.attack_dir4_left; break;
                default: break;
            }

            // draw above
            add_new_list_element_to_list_end(
                draw_above_texture_list,
                above_texture
            );
            add_new_list_element_to_list_end(
                draw_above_tilemap_pos_list,
                new_vec2i_from_vec2i(source_tilemap_pos)
            );
            
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_none()
            );
        }
        break;
        case SKILL__NO_ATTACK:
        {
            // draw effect
            add_new_list_element_to_list_end(
                draw_effect_texture_list,
                textures->skill.no_attack
            );
            add_new_list_element_to_list_end(
                draw_effect_tilemap_pos_list,
                new_vec2i_from_vec2i(source_tilemap_pos)
            );
            
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_none()
            );
        }
        break;
        case SKILL__USE:
        {
            if(target_2_object != NULL &&
               (is_object_station(target_2_object) ||
               is_object_secret(target_2_object) ||
                is_object_exit(target_2_object)))
            {
                if(is_object_station(target_2_object))
                {
                    // actions
                    add_action_after_curr_action_action_sequence(
                        action_sequence,
                        new_action_change_object(
                            OBJECT__STATION_TAKEN,
                            target_2_tilemap_pos
                        )
                    );
                }
                if(is_object_secret(target_2_object))
                {
                    // actions
                    add_action_after_curr_action_action_sequence(
                        action_sequence,
                        new_action_change_object(
                            OBJECT__SECRET_TAKEN,
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
    //     case SKILL__MANIPULATION:
    //     {
    //         if(target_2_object != NULL &&
    //            is_object_manipulatable(target_2_object))
    //         {
    //             // actions
    //             object_on_manipulate(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_object,
    //                 target_2_tilemap_pos
    //             );

    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.manipulation_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
    //         else if(target_2_floor != FLOOR__NONE &&
    //                 is_floor_manipulatable(target_2_floor))
    //         {
    //             // actions
    //             floor_on_manipulation(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_floor,
    //                 target_2_tilemap_pos
    //             );

    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.manipulation_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__TELEPORTATION:
    //     {
    //         if(target_2_object == NULL)
    //         {
    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.teleportation_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
            
    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_none()
    //         );
    //     }
    //     break;
    //     case SKILL__TELEKINESIS:
    //     {
    //         DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(
    //             target_1_tilemap_pos, target_2_tilemap_pos
    //         );

    //         if(distance_info.dir4 != DIR4__NONE)
    //             {
    //                 // init

    //                 Vec2i prev_tilemap_pos = target_1_tilemap_pos;
    //                 Vec2i curr_tilemap_pos = target_1_tilemap_pos;
    //                 Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(
    //                     curr_tilemap_pos,
    //                     distance_info.dir4,
    //                     1
    //                 );

    //                 Object* prev_object = room_get_object_at(
    //                     state->curr_room,
    //                     prev_tilemap_pos
    //                 );
    //                 Object* curr_object = room_get_object_at(
    //                     state->curr_room,
    //                     curr_tilemap_pos
    //                 );
    //                 Object* next_object = room_get_object_at(
    //                     state->curr_room,
    //                     next_tilemap_pos
    //                 );

    //                 int prev_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     prev_tilemap_pos
    //                 );
    //                 int curr_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     curr_tilemap_pos
    //                 );
    //                 int next_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     next_tilemap_pos
    //                 );

    //                 int go_on = TRUE;
    //                 for(int i = 0; i < distance_info.abs_diff + 1 && go_on; i++)
    //                 {
    //                     Texture* arrow_texture = NULL;

    //                     if(vec2i_equals(curr_tilemap_pos, target_1_tilemap_pos))
    //                     {
    //                         arrow_texture =
    //                             get_texture_arrow_thick_start(
    //                                 textures,
    //                                 distance_info.dir4
    //                             );
    //                     }
    //                     else if(curr_object != NULL ||
    //                             is_floor_deadly_on_move_for_object(
    //                                 curr_floor,
    //                                 target_1_object)
    //                             )
    //                     {
    //                         go_on = FALSE;

    //                         arrow_texture =
    //                             get_texture_arrow_thick_end(
    //                                 textures,
    //                                 get_opposite_dir4(distance_info.dir4)
    //                             );

    //                         if(is_floor_deadly_on_move_for_object(
    //                             curr_floor,
    //                             target_1_object)
    //                             )
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 textures->skill.death_effect
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(curr_tilemap_pos)
    //                             );
    //                         }
    //                         else
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 get_texture_1_from_object(target_1_object, textures)
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(curr_tilemap_pos)
    //                             );
    //                         }
    //                     }
    //                     else if(vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
    //                     {
    //                         arrow_texture =
    //                             get_texture_arrow_thick_end(
    //                                 textures,
    //                                 get_opposite_dir4(distance_info.dir4)
    //                             );

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             get_texture_1_from_object(target_1_object, textures)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(curr_tilemap_pos)
    //                         );
    //                     }
    //                     else
    //                     {
    //                         arrow_texture =
    //                             get_texture_arrow_thick_from_to(
    //                                 textures,
    //                                 distance_info.dir4,
    //                                 get_opposite_dir4(distance_info.dir4)
    //                             );
    //                     }

    //                     if(!vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
    //                     {
    //                         if(!is_object_floating(target_1_object) &&
    //                            !is_object_flying(target_1_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move(
    //                                     curr_tilemap_pos,
    //                                     distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                         else if(is_object_floating(target_1_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move_floating(
    //                                     curr_tilemap_pos,
    //                                     distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                         else if(is_object_flying(target_1_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move_flying(
    //                                     curr_tilemap_pos,
    //                                     distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                     }

    //                     // draw below
    //                     add_new_list_element_to_list_end(
    //                         draw_below_texture_list,
    //                         arrow_texture
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_below_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(curr_tilemap_pos)
    //                     );

    //                     // next

    //                     prev_tilemap_pos = curr_tilemap_pos;
    //                     curr_tilemap_pos = next_tilemap_pos;
    //                     next_tilemap_pos = vec2i_move_in_dir4_by(
    //                         curr_tilemap_pos,
    //                         distance_info.dir4,
    //                         1
    //                     );

    //                     prev_object = room_get_object_at(
    //                         state->curr_room,
    //                         prev_tilemap_pos
    //                     );
    //                     curr_object = room_get_object_at(
    //                         state->curr_room,
    //                         curr_tilemap_pos
    //                     );
    //                     next_object = room_get_object_at(
    //                         state->curr_room,
    //                         next_tilemap_pos
    //                     );

    //                     prev_floor = room_get_floor_at(
    //                         state->curr_room,
    //                         prev_tilemap_pos
    //                     );
    //                     curr_floor = room_get_floor_at(
    //                         state->curr_room,
    //                         curr_tilemap_pos
    //                     );
    //                     next_floor = room_get_floor_at(
    //                         state->curr_room,
    //                         next_tilemap_pos
    //                     );
    //                 }
    //             }
    //     }
    //     break;
        case SKILL__MOVE:
        {
            if(source_object != NULL && target_2_object == NULL)
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
                    ListElem* prev_elem = NULL;
                    ListElem* curr_elem = path_tilemap_pos_list->head;
                    ListElem* next_elem = (curr_elem) ? (curr_elem->next) : (0);

                    Vec2i* prev_tilemap_pos = (prev_elem) ? (prev_elem->data) : (0);
                    Vec2i* curr_tilemap_pos = (curr_elem) ? (curr_elem->data) : (0);
                    Vec2i* next_tilemap_pos = (next_elem) ? (next_elem->data) : (0);

                    while(curr_elem != NULL)
                    {
                        if(next_elem != NULL)
                        {
                            if(skill == SKILL__MOVE)
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
                        }

                        Texture* arrow_texture = NULL;

                        if(prev_elem == NULL)
                        {
                            arrow_texture = get_texture_arrow_thin_start(
                                textures,
                                get_distance_info_from_vec2i_to_vec2i(
                                    *curr_tilemap_pos,
                                    *next_tilemap_pos
                                ).dir4
                            );
                        }
                        else if(next_elem == NULL)
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
        case SKILL__BURROW:
        {
            if(target_2_object == NULL)
            {
                // draw above
                add_new_list_element_to_list_end(
                    draw_above_texture_list,
                    textures->skill.burrow_in
                );
                add_new_list_element_to_list_end(
                    draw_above_tilemap_pos_list,
                    new_vec2i_from_vec2i(source_tilemap_pos)
                );

                // draw above
                add_new_list_element_to_list_end(
                    draw_above_texture_list,
                    textures->skill.burrow_out
                );
                add_new_list_element_to_list_end(
                    draw_above_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                );
            }
            
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_none()
            );
        }
        break;
    //     case SKILL__PICK_ITEM_CLOSE:
    //     case SKILL__PICK_ITEM_FAR:
    //     {
    //         if(target_2_object != NULL)
    //         {
    //             // actions
    //             object_on_pick_item(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_object,
    //                 target_2_tilemap_pos
    //             );

    //             int item_type = get_object_item_type(target_2_object);
    //             int item_count = get_object_item_count(target_2_object);

    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 get_texture_item(
    //                     textures,
    //                     item_type,
    //                     item_count
    //                 )
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(source_tilemap_pos)
    //             );
    //         }
    //         else if(target_2_floor != FLOOR__NONE)
    //         {
    //             // actions
    //             floor_on_pick_item(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_floor,
    //                 target_2_tilemap_pos
    //             );

    //             int item_type = get_floor_item_type(target_2_floor);
    //             int item_count = get_floor_item_count(target_2_floor);

    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 get_texture_item(
    //                     textures,
    //                     item_type,
    //                     item_count
    //                 )
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(source_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__PUT_ITEM_CELL_CLOSE:
    //     case SKILL__PUT_ITEM_CELL_FAR:
    //     case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
    //     case SKILL__PUT_ITEM_DYNAMITE_FAR:
    //     case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
    //     case SKILL__PUT_ITEM_GEMSTONE_FAR:
    //     {
    //         int item_type = ITEM__NONE;
    //         if(skill == SKILL__PUT_ITEM_CELL_CLOSE ||
    //            skill == SKILL__PUT_ITEM_CELL_FAR)
    //         {
    //             item_type = ITEM__CELL;
    //         }
    //         if(skill == SKILL__PUT_ITEM_DYNAMITE_CLOSE ||
    //            skill == SKILL__PUT_ITEM_DYNAMITE_FAR)
    //         {
    //             item_type = ITEM__DYNAMITE;
    //         }
    //         if(skill == SKILL__PUT_ITEM_GEMSTONE_CLOSE ||
    //            skill == SKILL__PUT_ITEM_GEMSTONE_FAR)
    //         {
    //             item_type = ITEM__GEMSTONE;
    //         }

    //         if(target_2_object != NULL)
    //         {
    //             // actions
    //             object_on_put_item(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_object,
    //                 target_2_tilemap_pos,
    //                 item_type
    //             );

    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 get_texture_item(textures, item_type, -1)
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(source_tilemap_pos)
    //             );
    //         }
    //         else if(target_2_floor != FLOOR__NONE)
    //         {
    //             // actions
    //             floor_on_put_item(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_floor,
    //                 target_2_tilemap_pos,
    //                 item_type
    //             );

    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 get_texture_item(textures, item_type, -1)
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(source_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__THROW_ITEM_CELL:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         for(int i = 0; i < distance_info.abs_diff + 1; i++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 distance_info.dir4,
    //                 i
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Texture* dots_arch_texture = NULL;

    //                 switch(distance_info.dir4)
    //                 {
    //                     case DIR4__UP: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break; break;
    //                     case DIR4__RIGHT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, i + 1); break;
    //                     case DIR4__DOWN: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, i + 1); break; break;
    //                     case DIR4__LEFT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break;
    //                 }

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     dots_arch_texture
    //                 );
    //                 add_new_list_element_to_list_end
    //                 (
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }

    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_play_sound(target_2_tilemap_pos, sounds->cell)
    //         );
    //         if((target_2_object != NULL && is_object_meltable(target_2_object)) ||
    //             (target_2_floor != FLOOR__NONE && is_floor_meltable(target_2_floor)))
    //         {
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_melt(target_2_tilemap_pos)
    //             );
    //         }

    //         // draw effect
    //         add_new_list_element_to_list_end(
    //             draw_effect_texture_list,
    //             get_texture_item(textures, ITEM__CELL, -1)
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_effect_tilemap_pos_list,
    //             new_vec2i_from_vec2i(source_tilemap_pos)
    //         );

    //         if(target_2_object != NULL &&
    //            is_object_meltable(target_2_object))
    //         {
    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.melt_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__THROW_ITEM_DYNAMITE:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         for(int i = 0; i < distance_info.abs_diff + 1; i++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 distance_info.dir4,
    //                 i
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Texture* dots_arch_texture = NULL;
                    
    //                 switch(distance_info.dir4)
    //                 {
    //                     case DIR4__UP: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break; break;
    //                     case DIR4__RIGHT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, i + 1); break;
    //                     case DIR4__DOWN: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, i + 1); break; break;
    //                     case DIR4__LEFT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break;
    //                 }

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     dots_arch_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }

    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_play_sound(target_2_tilemap_pos, sounds->bomb)
    //         );
    //         if(target_2_object != NULL && is_object_breakable(target_2_object) ||
    //             (target_2_floor != FLOOR__NONE && is_floor_breakable(target_2_floor)))
    //         {
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_break(target_2_tilemap_pos)
    //             );
    //         }

    //         // draw effect
    //         add_new_list_element_to_list_end(
    //             draw_effect_texture_list,
    //             get_texture_item(textures, ITEM__DYNAMITE, -1)
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_effect_tilemap_pos_list,
    //             new_vec2i_from_vec2i(source_tilemap_pos)
    //         );

    //         if(target_2_object != NULL &&
    //            is_object_breakable(target_2_object))
    //         {
    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.break_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__THROW_ITEM_GEMSTONE:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         for(int i = 0; i < distance_info.abs_diff + 1; i++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 distance_info.dir4,
    //                 i
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Texture* dots_arch_texture = NULL;
                    
    //                 switch(distance_info.dir4)
    //                 {
    //                     case DIR4__UP: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break; break;
    //                     case DIR4__RIGHT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, i + 1); break;
    //                     case DIR4__DOWN: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, i + 1); break; break;
    //                     case DIR4__LEFT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break;
    //                 }

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     dots_arch_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }

    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_play_sound(target_2_tilemap_pos, sounds->shake)
    //         );
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_shake(target_2_tilemap_pos)
    //         );

    //         // draw effect
    //         add_new_list_element_to_list_end(
    //             draw_effect_texture_list,
    //             get_texture_item(textures, ITEM__GEMSTONE, -1)
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_effect_tilemap_pos_list,
    //             new_vec2i_from_vec2i(source_tilemap_pos)
    //         );

    //         if(target_2_object != NULL)
    //         {
    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.shake_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__SHOOT_PROJECTILE_FLY:
    //     case SKILL__SHOOT_PROJECTILE_SQUIRREL:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         for(int i = 1; i < distance_info.abs_diff; i++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 distance_info.dir4,
    //                 i
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Texture* dots_line_texture = NULL;
    //                 if(distance_info.dir4 == DIR4__RIGHT ||
    //                    distance_info.dir4 == DIR4__LEFT)
    //                 {
    //                     dots_line_texture = textures->skill.dots_line_horizontal;
    //                 }
    //                 if(distance_info.dir4 == DIR4__UP ||
    //                    distance_info.dir4 == DIR4__DOWN)
    //                 {
    //                     dots_line_texture = textures->skill.dots_line_vertical;
    //                 }

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     dots_line_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }

    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_shake(target_2_tilemap_pos)
    //         );

    //         if(target_2_object != NULL)
    //         {
    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.shake_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
        case SKILL__PUSH:
    //     case SKILL__DRAG_HOOK:
    //     case SKILL__DRAG_SPIDERWEB:
    //     case SKILL__DRAG_TENTACLE:
        {
            if(target_1_object != NULL &&
               is_object_movable(target_1_object))
            {
                DistanceInfo distance_info =
                    get_distance_info_from_vec2i_to_vec2i(
                        target_1_tilemap_pos,
                        target_2_tilemap_pos
                    );

                if(distance_info.dir4 != DIR4__NONE)
                {
                    // init

                    Vec2i prev_tilemap_pos = target_1_tilemap_pos;
                    Vec2i curr_tilemap_pos = target_1_tilemap_pos;
                    Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        distance_info.dir4,
                        1
                    );

                    Object* prev_object = room_get_object_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    Object* curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    Object* next_object = room_get_object_at(
                        state->curr_room,
                        next_tilemap_pos
                    );

                    int prev_floor = room_get_floor_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    int curr_floor = room_get_floor_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    int next_floor = room_get_floor_at(
                        state->curr_room,
                        next_tilemap_pos
                    );

                    int go_on = TRUE;
                    for(int i = 0; i < distance_info.abs_diff + 1 && go_on; i++)
                    {
                        Texture* arrow_texture = NULL;

                        if(vec2i_equals(curr_tilemap_pos, target_1_tilemap_pos))
                        {
                            arrow_texture =
                                get_texture_arrow_thick_start(
                                    textures,
                                    distance_info.dir4
                                );
                        }
                        else if(curr_object != NULL ||
                                is_floor_deadly_on_move_for_object(
                                    curr_floor,
                                    target_1_object)
                                )
                        {
                            go_on = FALSE;

                            arrow_texture =
                                get_texture_arrow_thick_end(
                                    textures,
                                    get_opposite_dir4(distance_info.dir4)
                                );

                            if(is_floor_deadly_on_move_for_object(
                                curr_floor,
                                target_1_object)
                                )
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    textures->skill.death_effect
                                );
                                add_new_list_element_to_list_end(
                                    draw_effect_tilemap_pos_list,
                                    new_vec2i_from_vec2i(curr_tilemap_pos)
                                );
                            }
                            else
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    get_texture_1_from_object(target_1_object, textures)
                                );
                                add_new_list_element_to_list_end(
                                    draw_effect_tilemap_pos_list,
                                    new_vec2i_from_vec2i(curr_tilemap_pos)
                                );
                            }
                        }
                        else if(vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
                        {
                            arrow_texture =
                                get_texture_arrow_thick_end(
                                    textures,
                                    get_opposite_dir4(distance_info.dir4)
                                );

                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                get_texture_1_from_object(target_1_object, textures)
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(curr_tilemap_pos)
                            );
                        }
                        else
                        {
                            arrow_texture =
                                get_texture_arrow_thick_from_to(
                                    textures,
                                    distance_info.dir4,
                                    get_opposite_dir4(distance_info.dir4)
                                );
                        }

                        if(!vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
                        {
                            if(!is_object_floating(target_1_object) &&
                               !is_object_flying(target_1_object))
                            {
                                // actions
                                add_action_to_end_action_sequence(
                                    action_sequence,
                                    new_action_move(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                            else if(is_object_floating(target_1_object))
                            {
                                // actions
                                add_action_to_end_action_sequence(
                                    action_sequence,
                                    new_action_move_floating(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                            else if(is_object_flying(target_1_object))
                            {
                                // actions
                                add_action_to_end_action_sequence(
                                    action_sequence,
                                    new_action_move_flying(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                        }

                        // draw below
                        add_new_list_element_to_list_end(
                            draw_below_texture_list,
                            arrow_texture
                        );
                        add_new_list_element_to_list_end(
                            draw_below_tilemap_pos_list,
                            new_vec2i_from_vec2i(curr_tilemap_pos)
                        );

                        // next

                        prev_tilemap_pos = curr_tilemap_pos;
                        curr_tilemap_pos = next_tilemap_pos;
                        next_tilemap_pos = vec2i_move_in_dir4_by(
                            curr_tilemap_pos,
                            distance_info.dir4,
                            1
                        );

                        prev_object = room_get_object_at(
                            state->curr_room,
                            prev_tilemap_pos
                        );
                        curr_object = room_get_object_at(
                            state->curr_room,
                            curr_tilemap_pos
                        );
                        next_object = room_get_object_at(
                            state->curr_room,
                            next_tilemap_pos
                        );

                        prev_floor = room_get_floor_at(
                            state->curr_room,
                            prev_tilemap_pos
                        );
                        curr_floor = room_get_floor_at(
                            state->curr_room,
                            curr_tilemap_pos
                        );
                        next_floor = room_get_floor_at(
                            state->curr_room,
                            next_tilemap_pos
                        );
                    }
                }
            }
        }
        break;
        case SKILL__PUNCH:
        {
            if(target_1_object != NULL && is_object_movable(target_1_object))
            {
                // actions
                add_action_to_end_action_sequence(
                    action_sequence,
                    new_action_damage(target_1_object, 1)
                );

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.damage_1
                );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_1_tilemap_pos)
                );

                DistanceInfo distance_info =
                    get_distance_info_from_vec2i_to_vec2i(
                        target_1_tilemap_pos,
                        target_2_tilemap_pos
                    );

                if(distance_info.dir4 != DIR4__NONE)
                {
                    // init

                    Vec2i prev_tilemap_pos = target_1_tilemap_pos;
                    Vec2i curr_tilemap_pos = target_1_tilemap_pos;
                    Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        distance_info.dir4,
                        1
                    );

                    Object* prev_object = room_get_object_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    Object* curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    Object* next_object = room_get_object_at(
                        state->curr_room,
                        next_tilemap_pos
                    );

                    int prev_floor = room_get_floor_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    int curr_floor = room_get_floor_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    int next_floor = room_get_floor_at(
                        state->curr_room,
                        next_tilemap_pos
                    );

                    int go_on = TRUE;
                    for(int i = 0; i < distance_info.abs_diff + 1 && go_on; i++)
                    {
                        Texture* arrow_texture = NULL;

                        if(vec2i_equals(curr_tilemap_pos, target_1_tilemap_pos))
                        {
                            arrow_texture =
                                get_texture_arrow_thick_start(
                                    textures,
                                    distance_info.dir4
                                );
                        }
                        else if(curr_object != NULL ||
                                is_floor_deadly_on_move_for_object(
                                    curr_floor,
                                    target_1_object)
                                )
                        {
                            go_on = FALSE;

                            arrow_texture =
                                get_texture_arrow_thick_end(
                                    textures,
                                    get_opposite_dir4(distance_info.dir4)
                                );

                            if(is_floor_deadly_on_move_for_object(
                                curr_floor,
                                target_1_object)
                                )
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    textures->skill.death_effect
                                );
                                add_new_list_element_to_list_end(
                                    draw_effect_tilemap_pos_list,
                                    new_vec2i_from_vec2i(curr_tilemap_pos)
                                );
                            }
                            else
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    get_texture_1_from_object(target_1_object, textures)
                                );
                                add_new_list_element_to_list_end(
                                    draw_effect_tilemap_pos_list,
                                    new_vec2i_from_vec2i(curr_tilemap_pos)
                                );
                            }
                        }
                        else if(vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
                        {
                            arrow_texture =
                                get_texture_arrow_thick_end(
                                    textures,
                                    get_opposite_dir4(distance_info.dir4)
                                );

                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                get_texture_1_from_object(target_1_object, textures)
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(curr_tilemap_pos)
                            );
                        }
                        else
                        {
                            arrow_texture =
                                get_texture_arrow_thick_from_to(
                                    textures,
                                    distance_info.dir4,
                                    get_opposite_dir4(distance_info.dir4)
                                );
                        }

                        if(!vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
                        {
                            if(!is_object_floating(target_1_object) &&
                               !is_object_flying(target_1_object))
                            {
                                // actions
                                add_action_to_end_action_sequence(
                                    action_sequence,
                                    new_action_move(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                            else if(is_object_floating(target_1_object))
                            {
                                // actions
                                add_action_to_end_action_sequence(
                                    action_sequence,
                                    new_action_move_floating(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                            else if(is_object_flying(target_1_object))
                            {
                                // actions
                                add_action_to_end_action_sequence(
                                    action_sequence,
                                    new_action_move_flying(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                        }

                        // draw below
                        add_new_list_element_to_list_end(
                            draw_below_texture_list,
                            arrow_texture
                        );
                        add_new_list_element_to_list_end(
                            draw_below_tilemap_pos_list,
                            new_vec2i_from_vec2i(curr_tilemap_pos)
                        );

                        // next

                        prev_tilemap_pos = curr_tilemap_pos;
                        curr_tilemap_pos = next_tilemap_pos;
                        next_tilemap_pos = vec2i_move_in_dir4_by(
                            curr_tilemap_pos,
                            distance_info.dir4,
                            1
                        );

                        prev_object = room_get_object_at(
                            state->curr_room,
                            prev_tilemap_pos
                        );
                        curr_object = room_get_object_at(
                            state->curr_room,
                            curr_tilemap_pos
                        );
                        next_object = room_get_object_at(
                            state->curr_room,
                            next_tilemap_pos
                        );

                        prev_floor = room_get_floor_at(
                            state->curr_room,
                            prev_tilemap_pos
                        );
                        curr_floor = room_get_floor_at(
                            state->curr_room,
                            curr_tilemap_pos
                        );
                        next_floor = room_get_floor_at(
                            state->curr_room,
                            next_tilemap_pos
                        );
                    }
                }
            }
        }
        break;
        case SKILL__THROW:
        {
            if(target_1_object != NULL &&
               is_object_movable(target_1_object))
            {
                DistanceInfo distance_info =
                    get_distance_info_from_vec2i_to_vec2i(
                        target_1_tilemap_pos,
                        target_2_tilemap_pos
                    );

                if(distance_info.dir4 != DIR4__NONE)
                {
                    // lift
                    if(target_2_object != NULL)
                    {
                        // actions
                        add_action_to_end_action_sequence(
                            action_sequence,
                            new_action_lift(
                                target_1_tilemap_pos,
                                distance_info.dir4
                            )
                        );

                        // draw above
                        add_new_list_element_to_list_end(
                            draw_above_texture_list,
                            get_texture_lift(
                                textures,
                                distance_info.dir4
                            )
                        );
                        add_new_list_element_to_list_end(
                            draw_above_tilemap_pos_list,
                            new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );
                    }
                    // throw
                    else
                    {
                        // actions
                        add_action_to_end_action_sequence(
                            action_sequence,
                            new_action_throw(
                                target_1_tilemap_pos,
                                distance_info.dir4,
                                distance_info.abs_diff
                            )
                        );

                        // draw above
                        add_new_list_element_to_list_end(
                            draw_above_texture_list,
                            get_texture_throw(
                                textures,
                                distance_info.dir4
                            )
                        );
                        add_new_list_element_to_list_end(
                            draw_above_tilemap_pos_list,
                            new_vec2i_from_vec2i(target_1_tilemap_pos)
                        );
                        add_new_list_element_to_list_end(
                            draw_above_texture_list,
                            textures->skill.drop
                        );
                        add_new_list_element_to_list_end(
                            draw_above_tilemap_pos_list,
                            new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );

                        if(is_floor_deadly_on_drop_for_object(
                            target_2_floor,
                            target_1_object)
                            )
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.death_effect
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(target_2_tilemap_pos)
                            );
                        }
                        else
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                get_texture_1_from_object(target_1_object, textures)
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(target_2_tilemap_pos)
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
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         if(distance_info.dir4 != DIR4__NONE)
    //         {
    //             // init

    //             Vec2i prev_tilemap_pos = source_tilemap_pos;
    //             Vec2i curr_tilemap_pos = source_tilemap_pos;
    //             Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(
    //                 curr_tilemap_pos,
    //                 distance_info.dir4,
    //                 1
    //             );

    //             Object* prev_object = room_get_object_at(
    //                 state->curr_room,
    //                 prev_tilemap_pos
    //             );
    //             Object* curr_object = room_get_object_at(
    //                 state->curr_room,
    //                 curr_tilemap_pos
    //             );
    //             Object* next_object = room_get_object_at(
    //                 state->curr_room,
    //                 next_tilemap_pos
    //             );

    //             int prev_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 prev_tilemap_pos
    //             );
    //             int curr_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 curr_tilemap_pos
    //             );
    //             int next_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 next_tilemap_pos
    //             );

    //             int go_on = TRUE;
    //             for(int i = 0; i < distance_info.abs_diff + 1 && go_on; i++)
    //             {
    //                 Texture* arrow_texture = NULL;

    //                 if(vec2i_equals(curr_tilemap_pos, source_tilemap_pos))
    //                 {
    //                     arrow_texture =
    //                         get_texture_arrow_thick_start(
    //                             textures,
    //                             distance_info.dir4
    //                         );
    //                 }
    //                 else if(curr_object != NULL ||
    //                         is_floor_deadly_on_move_for_flying(curr_floor))
    //                 {
    //                     go_on = FALSE;

    //                     arrow_texture =
    //                         get_texture_arrow_thick_end(
    //                             textures,
    //                             get_opposite_dir4(distance_info.dir4)
    //                         );

    //                     if(is_floor_deadly_on_move_for_flying(curr_floor))
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.death_effect
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(curr_tilemap_pos)
    //                         );
    //                     }
    //                     else
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             get_texture_1_from_object(source_object, textures)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(curr_tilemap_pos)
    //                         );
    //                     }
    //                 }
    //                 else if(vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
    //                 {
    //                     arrow_texture =
    //                         get_texture_arrow_thick_end(
    //                             textures,
    //                             get_opposite_dir4(distance_info.dir4)
    //                         );

    //                     if(is_floor_deadly_on_move_for_object(
    //                         curr_floor,
    //                         source_object)
    //                         )
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.death_effect
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(curr_tilemap_pos)
    //                         );
    //                     }
    //                     else
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             get_texture_1_from_object(source_object, textures)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(curr_tilemap_pos)
    //                         );
    //                     }
    //                 }
    //                 else
    //                 {
    //                     arrow_texture =
    //                         get_texture_arrow_thick_from_to(
    //                             textures,
    //                             distance_info.dir4,
    //                             get_opposite_dir4(distance_info.dir4)
    //                         );
    //                 }

    //                 // if pos before target_2_pos
    //                 if(!vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
    //                 {
    //                     Vec2i just_before_target_2_tilemap_pos =
    //                         vec2i_move_in_dir4_by(
    //                             target_2_tilemap_pos,
    //                             get_opposite_dir4(distance_info.dir4),
    //                             1
    //                         );
    //                     // if pos just before target_2_pos
    //                     if(vec2i_equals(curr_tilemap_pos, just_before_target_2_tilemap_pos))
    //                     {
    //                         if(!is_object_floating(source_object) &&
    //                            !is_object_flying(source_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move(
    //                                     curr_tilemap_pos,
    //                                     distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                         else if(is_object_floating(source_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move_floating(
    //                                     curr_tilemap_pos,
    //                                     distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                         else if(is_object_flying(source_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move_flying(
    //                                     curr_tilemap_pos,
    //                                     distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                     }
    //                     else
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_move_flying(
    //                                 curr_tilemap_pos,
    //                                 distance_info.dir4
    //                             )
    //                         );
    //                     }
    //                 }

    //                 // draw below
    //                 add_new_list_element_to_list_end(
    //                     draw_below_texture_list,
    //                     arrow_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_below_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(curr_tilemap_pos)
    //                 );

    //                 // next

    //                 prev_tilemap_pos = curr_tilemap_pos;
    //                 curr_tilemap_pos = next_tilemap_pos;
    //                 next_tilemap_pos = vec2i_move_in_dir4_by(
    //                     curr_tilemap_pos,
    //                     distance_info.dir4,
    //                     1
    //                 );

    //                 prev_object = room_get_object_at(
    //                     state->curr_room,
    //                     prev_tilemap_pos
    //                 );
    //                 curr_object = room_get_object_at(
    //                     state->curr_room,
    //                     curr_tilemap_pos
    //                 );
    //                 next_object = room_get_object_at(
    //                     state->curr_room,
    //                     next_tilemap_pos
    //                 );

    //                 prev_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     prev_tilemap_pos
    //                 );
    //                 curr_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     curr_tilemap_pos
    //                 );
    //                 next_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     next_tilemap_pos
    //                 );
    //             }
    //         }
    //     }
    //     break;
        case SKILL__JUMP:
        case SKILL__ROCKET_JUMP:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                // lift
                if(target_2_object != NULL)
                {
                    // actions
                    add_action_to_end_action_sequence(
                        action_sequence,
                        new_action_lift(
                            source_tilemap_pos,
                            distance_info.dir4
                        )
                    );

                    // draw above
                    add_new_list_element_to_list_end(
                        draw_above_texture_list,
                        get_texture_lift(
                            textures,
                            distance_info.dir4
                        )
                    );
                    add_new_list_element_to_list_end(
                        draw_above_tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                    );
                }
                // throw
                else
                {
                    // actions
                    add_action_to_end_action_sequence(
                        action_sequence,
                        new_action_throw(
                            source_tilemap_pos,
                            distance_info.dir4,
                            distance_info.abs_diff
                        )
                    );

                    // draw above
                    add_new_list_element_to_list_end(
                        draw_above_texture_list,
                        get_texture_throw(
                            textures,
                            distance_info.dir4
                        )
                    );
                    add_new_list_element_to_list_end(
                        draw_above_tilemap_pos_list,
                        new_vec2i_from_vec2i(source_tilemap_pos)
                    );
                    add_new_list_element_to_list_end(
                        draw_above_texture_list,
                        textures->skill.drop
                    );
                    add_new_list_element_to_list_end(
                        draw_above_tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );

                    if(is_floor_deadly_on_drop_for_object(
                        target_2_floor,
                        source_object)
                        )
                    {
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.death_effect
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(target_2_tilemap_pos)
                        );
                    }
                    else
                    {
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
            }
        }
        break;
        case SKILL__CHARGE:
        case SKILL__ROCKET_DASH:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                // init

                Vec2i prev_tilemap_pos = source_tilemap_pos;
                Vec2i curr_tilemap_pos = source_tilemap_pos;
                Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(
                    curr_tilemap_pos,
                    distance_info.dir4,
                    1
                );

                Object* prev_object = room_get_object_at(
                    state->curr_room,
                    prev_tilemap_pos
                );
                Object* curr_object = room_get_object_at(
                    state->curr_room,
                    curr_tilemap_pos
                );
                Object* next_object = room_get_object_at(
                    state->curr_room,
                    next_tilemap_pos
                );

                int prev_floor = room_get_floor_at(
                    state->curr_room,
                    prev_tilemap_pos
                );
                int curr_floor = room_get_floor_at(
                    state->curr_room,
                    curr_tilemap_pos
                );
                int next_floor = room_get_floor_at(
                    state->curr_room,
                    next_tilemap_pos
                );

                int go_on = TRUE;
                for(int i = 0; i < distance_info.abs_diff + 1 && go_on; i++)
                {
                    Texture* arrow_texture = NULL;

                    if(vec2i_equals(curr_tilemap_pos, source_tilemap_pos))
                    {
                        arrow_texture =
                            get_texture_arrow_thin_start(
                                textures,
                                distance_info.dir4
                            );
                    }
                    else if(curr_object != NULL ||
                            is_floor_deadly_on_move_for_object(
                                curr_floor,
                                source_object)
                            )
                    {
                        go_on = FALSE;

                        arrow_texture =
                            get_texture_arrow_thin_end(
                                textures,
                                get_opposite_dir4(distance_info.dir4)
                            );

                        if(is_floor_deadly_on_move_for_object(
                            curr_floor,
                            source_object)
                            )
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.death_effect
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(curr_tilemap_pos)
                            );
                        }
                        else
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                get_texture_1_from_object(source_object, textures)
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(curr_tilemap_pos)
                            );
                        }
                    }
                    else if(vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
                    {
                        arrow_texture =
                            get_texture_arrow_thin_end(
                                textures,
                                get_opposite_dir4(distance_info.dir4)
                            );

                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            get_texture_1_from_object(source_object, textures)
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(curr_tilemap_pos)
                        );
                    }
                    else
                    {
                        arrow_texture =
                            get_texture_arrow_thin_from_to(
                                textures,
                                distance_info.dir4,
                                get_opposite_dir4(distance_info.dir4)
                            );
                    }

                    if(!vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
                    {
                        if(!is_object_floating(source_object) && !is_object_flying(source_object))
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_move(
                                    curr_tilemap_pos,
                                    distance_info.dir4
                                )
                            );
                        }
                        else if(is_object_floating(source_object))
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_move_floating(
                                    curr_tilemap_pos,
                                    distance_info.dir4
                                )
                            );
                        }
                        else if(is_object_flying(source_object))
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_move_flying(
                                    curr_tilemap_pos,
                                    distance_info.dir4
                                )
                            );
                        }
                    }

                    // draw below
                    add_new_list_element_to_list_end(
                        draw_below_texture_list,
                        arrow_texture
                    );
                    add_new_list_element_to_list_end(
                        draw_below_tilemap_pos_list,
                        new_vec2i_from_vec2i(curr_tilemap_pos)
                    );

                    // next

                    prev_tilemap_pos = curr_tilemap_pos;
                    curr_tilemap_pos = next_tilemap_pos;
                    next_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        distance_info.dir4,
                        1
                    );

                    prev_object = room_get_object_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    next_object = room_get_object_at(
                        state->curr_room,
                        next_tilemap_pos
                    );

                    prev_floor = room_get_floor_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    curr_floor = room_get_floor_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    next_floor = room_get_floor_at(
                        state->curr_room,
                        next_tilemap_pos
                    );
                }
            }
        }
        break;
    //     case SKILL__STOMP:
    //     {
    //         if(target_2_object != NULL)
    //         {
    //             // actions
    //             object_on_stomp(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_object,
    //                 target_2_tilemap_pos
    //             );
    //         }
    //         else
    //         {
    //             // actions
    //             floor_on_stomp(
    //                 state,
    //                 sounds,
    //                 action_sequence,
    //                 target_2_floor,
    //                 target_2_tilemap_pos
    //             );
    //         }

    //         // draw effect
    //         add_new_list_element_to_list_end(
    //             draw_effect_texture_list,
    //             textures->skill.stomp_effect
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_effect_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );

    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 target_2_tilemap_pos,
    //                 dir4,
    //                 1
    //             );

    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_shake(tilemap_pos)
    //             );

    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.shake_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__DRAG_AND_THROW_HOOK:
    //     case SKILL__DRAG_AND_THROW_TONGUE:
    //     {
    //         if(target_1_object != NULL &&
    //            is_object_movable(target_1_object))
    //         {
    //             DistanceInfo drag_distance_info =
    //                 get_distance_info_from_vec2i_to_vec2i(
    //                     target_1_tilemap_pos,
    //                     source_tilemap_pos
    //                 );

    //             if(drag_distance_info.dir4 != DIR4__NONE)
    //             {
    //                 Vec2i just_before_source_tilemap_pos =
    //                     vec2i_move_in_dir4_by(
    //                         source_tilemap_pos,
    //                         get_opposite_dir4(drag_distance_info.dir4),
    //                         1
    //                     );

    //                 // init

    //                 Vec2i drag_prev_tilemap_pos = target_1_tilemap_pos;
    //                 Vec2i drag_curr_tilemap_pos = target_1_tilemap_pos;
    //                 Vec2i drag_next_tilemap_pos = vec2i_move_in_dir4_by(
    //                     drag_curr_tilemap_pos,
    //                     drag_distance_info.dir4,
    //                     1
    //                 );

    //                 Object* prev_object = room_get_object_at(
    //                     state->curr_room,
    //                     drag_prev_tilemap_pos
    //                 );
    //                 Object* curr_object = room_get_object_at(
    //                     state->curr_room,
    //                     drag_curr_tilemap_pos
    //                 );
    //                 Object* next_object = room_get_object_at(
    //                     state->curr_room,
    //                     drag_next_tilemap_pos
    //                 );

    //                 int prev_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     drag_prev_tilemap_pos
    //                 );
    //                 int curr_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     drag_curr_tilemap_pos
    //                 );
    //                 int next_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     drag_next_tilemap_pos
    //                 );

    //                 int drag_go_on = TRUE;
    //                 for(int i = 0; i < drag_distance_info.abs_diff && drag_go_on; i++)
    //                 {
    //                     Texture* drag_arrow_texture = NULL;

    //                     if(vec2i_equals(drag_curr_tilemap_pos, target_1_tilemap_pos))
    //                     {
    //                         drag_arrow_texture =
    //                             get_texture_arrow_thin_start(
    //                                 textures,
    //                                 drag_distance_info.dir4
    //                             );
    //                     }
    //                     else if(curr_object != NULL ||
    //                             is_floor_deadly_on_move_for_object(
    //                                 curr_floor,
    //                                 target_1_object)
    //                             )
    //                     {
    //                         drag_go_on = FALSE;

    //                         drag_arrow_texture =
    //                             get_texture_arrow_thin_end(
    //                                 textures,
    //                                 get_opposite_dir4(drag_distance_info.dir4)
    //                             );

    //                         if(is_floor_deadly_on_move_for_object(
    //                             curr_floor,
    //                             target_1_object)
    //                             )
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 textures->skill.death_effect
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(drag_curr_tilemap_pos)
    //                             );
    //                         }
    //                         else
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 get_texture_1_from_object(target_1_object, textures)
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(drag_curr_tilemap_pos)
    //                             );
    //                         }
    //                     }
    //                     else if(vec2i_equals(drag_curr_tilemap_pos, just_before_source_tilemap_pos))
    //                     {
    //                         drag_arrow_texture =
    //                             get_texture_arrow_thin_end(
    //                                 textures,
    //                                 get_opposite_dir4(drag_distance_info.dir4)
    //                             );

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             get_texture_1_from_object(target_1_object, textures)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(drag_curr_tilemap_pos)
    //                         );
    //                     }
    //                     else
    //                     {
    //                         drag_arrow_texture =
    //                             get_texture_arrow_thin_from_to(
    //                                 textures,
    //                                 drag_distance_info.dir4,
    //                                 get_opposite_dir4(drag_distance_info.dir4)
    //                             );
    //                     }

    //                     if(!vec2i_equals(drag_curr_tilemap_pos, just_before_source_tilemap_pos))
    //                     {
    //                         if(!is_object_floating(target_1_object) &&
    //                            !is_object_flying(target_1_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move(
    //                                     drag_curr_tilemap_pos,
    //                                     drag_distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                         else if(is_object_floating(target_1_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move_floating(
    //                                     drag_curr_tilemap_pos,
    //                                     drag_distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                         else if(is_object_flying(target_1_object))
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_move_flying(
    //                                     drag_curr_tilemap_pos,
    //                                     drag_distance_info.dir4
    //                                 )
    //                             );
    //                         }
    //                     }

    //                     // draw below
    //                     add_new_list_element_to_list_end(
    //                         draw_below_texture_list,
    //                         drag_arrow_texture
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_below_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(drag_curr_tilemap_pos)
    //                     );

    //                     // next

    //                     drag_prev_tilemap_pos = drag_curr_tilemap_pos;
    //                     drag_curr_tilemap_pos = drag_next_tilemap_pos;
    //                     drag_next_tilemap_pos = vec2i_move_in_dir4_by(
    //                         drag_curr_tilemap_pos,
    //                         drag_distance_info.dir4,
    //                         1
    //                     );

    //                     prev_object = room_get_object_at(
    //                         state->curr_room,
    //                         drag_prev_tilemap_pos
    //                     );
    //                     curr_object = room_get_object_at(
    //                         state->curr_room,
    //                         drag_curr_tilemap_pos
    //                     );
    //                     next_object = room_get_object_at(
    //                         state->curr_room,
    //                         drag_next_tilemap_pos
    //                     );

    //                     prev_floor = room_get_floor_at(
    //                         state->curr_room,
    //                         drag_prev_tilemap_pos
    //                     );
    //                     curr_floor = room_get_floor_at(
    //                         state->curr_room,
    //                         drag_curr_tilemap_pos
    //                     );
    //                     next_floor = room_get_floor_at(
    //                         state->curr_room,
    //                         drag_next_tilemap_pos
    //                     );
    //                 }

    //                 if(drag_go_on)
    //                 {
    //                     DistanceInfo throw_distance_info =
    //                         get_distance_info_from_vec2i_to_vec2i(
    //                             just_before_source_tilemap_pos,
    //                             target_2_tilemap_pos
    //                         );

    //                     if(throw_distance_info.dir4 != DIR4__NONE)
    //                     {
    //                         // lift
    //                         if(target_2_object != NULL)
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_lift(
    //                                     just_before_source_tilemap_pos,
    //                                     throw_distance_info.dir4
    //                                 )
    //                             );

    //                             // draw above
    //                             add_new_list_element_to_list_end(
    //                                 draw_above_texture_list,
    //                                 get_texture_lift(
    //                                     textures,
    //                                     throw_distance_info.dir4
    //                                 )
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_above_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(just_before_source_tilemap_pos)
    //                             );
    //                         }
    //                         // throw
    //                         else
    //                         {
    //                             // actions
    //                             add_action_to_end_action_sequence(
    //                                 action_sequence,
    //                                 new_action_throw(
    //                                     just_before_source_tilemap_pos,
    //                                     throw_distance_info.dir4,
    //                                     throw_distance_info.abs_diff
    //                                 )
    //                             );

    //                             // draw above
    //                             add_new_list_element_to_list_end(
    //                                 draw_above_texture_list,
    //                                 get_texture_throw(
    //                                     textures,
    //                                     throw_distance_info.dir4
    //                                 )
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_above_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(just_before_source_tilemap_pos)
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_above_texture_list,
    //                                 textures->skill.drop
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_above_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                             );

    //                             if(is_floor_deadly_on_drop_for_object(
    //                                 target_2_floor,
    //                                 target_1_object)
    //                                 )
    //                             {
    //                                 // draw effect
    //                                 add_new_list_element_to_list_end(
    //                                     draw_effect_texture_list,
    //                                     textures->skill.death_effect
    //                                 );
    //                                 add_new_list_element_to_list_end(
    //                                     draw_effect_tilemap_pos_list,
    //                                     new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                                 );
    //                             }
    //                             else
    //                             {
    //                                 // draw effect
    //                                 add_new_list_element_to_list_end(
    //                                     draw_effect_texture_list,
    //                                     get_texture_1_from_object(target_1_object, textures)
    //                                 );
    //                                 add_new_list_element_to_list_end(
    //                                     draw_effect_tilemap_pos_list,
    //                                     new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                                 );
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
        // case SKILL__CHARGE_AND_PUSH:
        // {
        //     DistanceInfo charge_distance_info =
        //         get_distance_info_from_vec2i_to_vec2i(
        //             source_tilemap_pos,
        //             target_1_tilemap_pos
        //         );

        //     if(charge_distance_info.dir4 != DIR4__NONE)
        //     {
        //         Vec2i just_before_target_1_position = vec2i_move_in_dir4_by(
        //             target_1_tilemap_pos,
        //             get_opposite_dir4(charge_distance_info.dir4),
        //             1
        //         );

        //         // init

        //         Vec2i charge_prev_tilemap_pos = source_tilemap_pos;
        //         Vec2i charge_curr_tilemap_pos = source_tilemap_pos;
        //         Vec2i charge_next_tilemap_pos = vec2i_move_in_dir4_by(
        //             charge_curr_tilemap_pos,
        //             charge_distance_info.dir4,
        //             1
        //         );

        //         Object* charge_prev_object = room_get_object_at(
        //             state->curr_room,
        //             charge_prev_tilemap_pos
        //         );
        //         Object* charge_curr_object = room_get_object_at(
        //             state->curr_room,
        //             charge_curr_tilemap_pos
        //         );
        //         Object* charge_next_object = room_get_object_at(
        //             state->curr_room,
        //             charge_next_tilemap_pos
        //         );

        //         int charge_prev_floor = room_get_floor_at(
        //             state->curr_room,
        //             charge_prev_tilemap_pos
        //         );
        //         int charge_curr_floor = room_get_floor_at(
        //             state->curr_room,
        //             charge_curr_tilemap_pos
        //         );
        //         int charge_next_floor = room_get_floor_at(
        //             state->curr_room,
        //             charge_next_tilemap_pos
        //         );

        //         int charge_go_on = TRUE;
        //         for(int i = 0; i < charge_distance_info.abs_diff && charge_go_on; i++)
        //         {
        //             Texture* charge_arrow_texture = NULL;

        //             if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
        //             {
        //                 charge_arrow_texture =
        //                     get_texture_arrow_thin_start(
        //                         textures,
        //                         charge_distance_info.dir4
        //                     );
        //             }
        //             else if(charge_curr_object != NULL ||
        //                     is_floor_deadly_on_move_for_object(
        //                         charge_curr_floor,
        //                         source_object)
        //                     )
        //             {
        //                 charge_go_on = FALSE;

        //                 charge_arrow_texture =
        //                     get_texture_arrow_thin_end(
        //                         textures,
        //                         get_opposite_dir4(charge_distance_info.dir4)
        //                     );

        //                 if(is_floor_deadly_on_move_for_object(
        //                     charge_curr_floor,
        //                     source_object)
        //                     )
        //                 {
        //                     // draw effect
        //                     add_new_list_element_to_list_end(
        //                         draw_effect_texture_list,
        //                         textures->skill.death_effect
        //                     );
        //                     add_new_list_element_to_list_end(
        //                         draw_effect_tilemap_pos_list,
        //                         new_vec2i_from_vec2i(charge_curr_tilemap_pos)
        //                     );
        //                 }
        //                 else
        //                 {
        //                     // draw effect
        //                     add_new_list_element_to_list_end(
        //                         draw_effect_texture_list,
        //                         get_texture_1_from_object(source_object, textures)
        //                     );
        //                     add_new_list_element_to_list_end(
        //                         draw_effect_tilemap_pos_list,
        //                         new_vec2i_from_vec2i(charge_curr_tilemap_pos)
        //                     );
        //                 }
        //             }
        //             else if(vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_position))
        //             {
        //                 charge_arrow_texture =
        //                     get_texture_arrow_thin_end(
        //                         textures,
        //                         get_opposite_dir4(charge_distance_info.dir4)
        //                     );

        //                 // draw effect
        //                 add_new_list_element_to_list_end(
        //                     draw_effect_texture_list,
        //                     get_texture_1_from_object(source_object, textures)
        //                 );
        //                 add_new_list_element_to_list_end(
        //                     draw_effect_tilemap_pos_list,
        //                     new_vec2i_from_vec2i(charge_curr_tilemap_pos)
        //                 );
        //             }
        //             else
        //             {
        //                 charge_arrow_texture =
        //                     get_texture_arrow_thin_from_to(
        //                         textures,
        //                         charge_distance_info.dir4,
        //                         get_opposite_dir4(charge_distance_info.dir4)
        //                     );
        //             }

        //             if(!vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_position))
        //             {
        //                 // actions
        //                 add_action_to_end_action_sequence(
        //                     action_sequence,
        //                     new_action_move(
        //                         charge_curr_tilemap_pos,
        //                         charge_distance_info.dir4
        //                     )
        //                 );
        //             }

        //             // draw below
        //             add_new_list_element_to_list_end(
        //                 draw_below_texture_list,
        //                 charge_arrow_texture
        //             );
        //             add_new_list_element_to_list_end(
        //                 draw_below_tilemap_pos_list,
        //                 new_vec2i_from_vec2i(charge_curr_tilemap_pos)
        //             );

        //             // next

        //             charge_prev_tilemap_pos = charge_curr_tilemap_pos;
        //             charge_curr_tilemap_pos = charge_next_tilemap_pos;
        //             charge_next_tilemap_pos = vec2i_move_in_dir4_by(
        //                 charge_curr_tilemap_pos,
        //                 charge_distance_info.dir4,
        //                 1
        //             );

        //             charge_prev_object = room_get_object_at(
        //                 state->curr_room,
        //                 charge_prev_tilemap_pos
        //             );
        //             charge_curr_object = room_get_object_at(
        //                 state->curr_room,
        //                 charge_curr_tilemap_pos
        //             );
        //             charge_next_object = room_get_object_at(
        //                 state->curr_room,
        //                 charge_next_tilemap_pos
        //             );

        //             charge_prev_floor = room_get_floor_at(
        //                 state->curr_room,
        //                 charge_prev_tilemap_pos
        //             );
        //             charge_curr_floor = room_get_floor_at(
        //                 state->curr_room,
        //                 charge_curr_tilemap_pos
        //             );
        //             charge_next_floor = room_get_floor_at(
        //                 state->curr_room,
        //                 charge_next_tilemap_pos
        //             );
        //         }

        //         if(charge_go_on)
        //         {
        //             if(target_1_object != NULL &&
        //                is_object_movable(target_1_object))
        //             {
        //                 DistanceInfo push_distance_info =
        //                     get_distance_info_from_vec2i_to_vec2i(
        //                         target_1_tilemap_pos,
        //                         target_2_tilemap_pos
        //                     );

        //                 if(push_distance_info.dir4 != DIR4__NONE)
        //                 {
        //                     // init

        //                     Vec2i push_prev_tilemap_pos = target_1_tilemap_pos;
        //                     Vec2i push_curr_tilemap_pos = target_1_tilemap_pos;
        //                     Vec2i push_next_tilemap_pos = vec2i_move_in_dir4_by(
        //                         push_curr_tilemap_pos,
        //                         push_distance_info.dir4,
        //                         1
        //                     );

        //                     Object* push_prev_object = room_get_object_at(
        //                         state->curr_room,
        //                         push_prev_tilemap_pos
        //                     );
        //                     Object* push_curr_object = room_get_object_at(
        //                         state->curr_room,
        //                         push_curr_tilemap_pos
        //                     );
        //                     Object* push_next_object = room_get_object_at(
        //                         state->curr_room,
        //                         push_next_tilemap_pos
        //                     );

        //                     int push_prev_floor = room_get_floor_at(
        //                         state->curr_room,
        //                         push_prev_tilemap_pos
        //                     );
        //                     int push_curr_floor = room_get_floor_at(
        //                         state->curr_room,
        //                         push_curr_tilemap_pos
        //                     );
        //                     int push_next_floor = room_get_floor_at(
        //                         state->curr_room,
        //                         push_next_tilemap_pos
        //                     );

        //                     int push_go_on = TRUE;
        //                     for(int i = 0; i < push_distance_info.abs_diff + 1 && push_go_on; i++)
        //                     {
        //                         Texture* push_arrow_texture = NULL;

        //                         if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
        //                         {
        //                             push_arrow_texture =
        //                                 get_texture_arrow_thin_start(
        //                                     textures,
        //                                     push_distance_info.dir4
        //                                 );
        //                         }
        //                         else if(push_curr_object != NULL ||
        //                                 is_floor_deadly_on_move_for_object(
        //                                     push_curr_floor,
        //                                     target_1_object)
        //                                 )
        //                         {
        //                             push_go_on = FALSE;

        //                             push_arrow_texture =
        //                                 get_texture_arrow_thin_end(
        //                                     textures,
        //                                     get_opposite_dir4(push_distance_info.dir4)
        //                                 );

        //                             if(is_floor_deadly_on_move_for_object(
        //                                 push_curr_floor,
        //                                 target_1_object)
        //                                 )
        //                             {
        //                                 // draw effect
        //                                 add_new_list_element_to_list_end(
        //                                     draw_effect_texture_list,
        //                                     textures->skill.death_effect
        //                                 );
        //                                 add_new_list_element_to_list_end(
        //                                     draw_effect_tilemap_pos_list,
        //                                     new_vec2i_from_vec2i(push_curr_tilemap_pos)
        //                                 );
        //                             }
        //                             else
        //                             {
        //                                 // draw effect
        //                                 add_new_list_element_to_list_end(
        //                                     draw_effect_texture_list,
        //                                     get_texture_1_from_object(target_1_object, textures)
        //                                 );
        //                                 add_new_list_element_to_list_end(
        //                                     draw_effect_tilemap_pos_list,
        //                                     new_vec2i_from_vec2i(push_curr_tilemap_pos)
        //                                 );
        //                             }
        //                         }
        //                         else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
        //                         {
        //                             push_arrow_texture =
        //                                 get_texture_arrow_thin_end(
        //                                     textures,
        //                                     get_opposite_dir4(push_distance_info.dir4)
        //                                 );

        //                             // draw effect
        //                             add_new_list_element_to_list_end(
        //                                 draw_effect_texture_list,
        //                                 get_texture_1_from_object(target_1_object, textures)
        //                             );
        //                             add_new_list_element_to_list_end(
        //                                 draw_effect_tilemap_pos_list,
        //                                 new_vec2i_from_vec2i(push_curr_tilemap_pos)
        //                             );
        //                         }
        //                         else
        //                         {
        //                             push_arrow_texture =
        //                                 get_texture_arrow_thin_from_to(
        //                                     textures,
        //                                     push_distance_info.dir4,
        //                                     get_opposite_dir4(push_distance_info.dir4)
        //                                 );
        //                         }

        //                         if(!vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
        //                         {
        //                             if(!is_object_floating(target_1_object) &&
        //                             !is_object_flying(target_1_object))
        //                             {
        //                                 // actions
        //                                 add_action_to_end_action_sequence(
        //                                     action_sequence,
        //                                     new_action_move(
        //                                         push_curr_tilemap_pos,
        //                                         push_distance_info.dir4
        //                                     )
        //                                 );
        //                             }
        //                             else if(is_object_floating(target_1_object))
        //                             {
        //                                 // actions
        //                                 add_action_to_end_action_sequence(
        //                                     action_sequence,
        //                                     new_action_move_floating(
        //                                         push_curr_tilemap_pos,
        //                                         push_distance_info.dir4
        //                                     )
        //                                 );
        //                             }
        //                             else if(is_object_flying(target_1_object))
        //                             {
        //                                 // actions
        //                                 add_action_to_end_action_sequence(
        //                                     action_sequence,
        //                                     new_action_move_flying(
        //                                         push_curr_tilemap_pos,
        //                                         push_distance_info.dir4
        //                                     )
        //                                 );
        //                             }
        //                         }

        //                         // draw below
        //                         add_new_list_element_to_list_end(
        //                             draw_below_texture_list,
        //                             push_arrow_texture
        //                         );
        //                         add_new_list_element_to_list_end(
        //                             draw_below_tilemap_pos_list,
        //                             new_vec2i_from_vec2i(push_curr_tilemap_pos)
        //                         );

        //                         // next

        //                         push_prev_tilemap_pos = push_curr_tilemap_pos;
        //                         push_curr_tilemap_pos = push_next_tilemap_pos;
        //                         push_next_tilemap_pos = vec2i_move_in_dir4_by(
        //                             push_curr_tilemap_pos,
        //                             push_distance_info.dir4,
        //                             1
        //                         );

        //                         push_prev_object = room_get_object_at(
        //                             state->curr_room,
        //                             push_prev_tilemap_pos
        //                         );
        //                         push_curr_object = room_get_object_at(
        //                             state->curr_room,
        //                             push_curr_tilemap_pos
        //                         );
        //                         push_next_object = room_get_object_at(
        //                             state->curr_room,
        //                             push_next_tilemap_pos
        //                         );

        //                         push_prev_floor = room_get_floor_at(
        //                             state->curr_room,
        //                             push_prev_tilemap_pos
        //                         );
        //                         push_curr_floor = room_get_floor_at(
        //                             state->curr_room,
        //                             push_curr_tilemap_pos
        //                         );
        //                         push_next_floor = room_get_floor_at(
        //                             state->curr_room,
        //                             push_next_tilemap_pos
        //                         );
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // break;
        case SKILL__CHARGE_AND_PUNCH:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                );

            if(charge_distance_info.dir4 != DIR4__NONE)
            {
                Vec2i just_before_target_1_position = vec2i_move_in_dir4_by(
                    target_1_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1
                );

                // init

                Vec2i charge_prev_tilemap_pos = source_tilemap_pos;
                Vec2i charge_curr_tilemap_pos = source_tilemap_pos;
                Vec2i charge_next_tilemap_pos = vec2i_move_in_dir4_by(
                    charge_curr_tilemap_pos,
                    charge_distance_info.dir4,
                    1
                );

                Object* charge_prev_object = room_get_object_at(
                    state->curr_room,
                    charge_prev_tilemap_pos
                );
                Object* charge_curr_object = room_get_object_at(
                    state->curr_room,
                    charge_curr_tilemap_pos
                );
                Object* charge_next_object = room_get_object_at(
                    state->curr_room,
                    charge_next_tilemap_pos
                );

                int charge_prev_floor = room_get_floor_at(
                    state->curr_room,
                    charge_prev_tilemap_pos
                );
                int charge_curr_floor = room_get_floor_at(
                    state->curr_room,
                    charge_curr_tilemap_pos
                );
                int charge_next_floor = room_get_floor_at(
                    state->curr_room,
                    charge_next_tilemap_pos
                );

                int charge_go_on = TRUE;
                for(int i = 0; i < charge_distance_info.abs_diff && charge_go_on; i++)
                {
                    Texture* charge_arrow_texture = NULL;

                    if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
                    {
                        charge_arrow_texture =
                            get_texture_arrow_thin_start(
                                textures,
                                charge_distance_info.dir4
                            );
                    }
                    else if(charge_curr_object != NULL ||
                            is_floor_deadly_on_move_for_object(
                                charge_curr_floor,
                                source_object)
                            )
                    {
                        charge_go_on = FALSE;

                        charge_arrow_texture =
                            get_texture_arrow_thin_end(
                                textures,
                                get_opposite_dir4(charge_distance_info.dir4)
                            );

                        if(is_floor_deadly_on_move_for_object(
                            charge_curr_floor,
                            source_object)
                            )
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.death_effect
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(charge_curr_tilemap_pos)
                            );
                        }
                        else
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                get_texture_1_from_object(source_object, textures)
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(charge_curr_tilemap_pos)
                            );
                        }
                    }
                    else if(vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_position))
                    {
                        charge_arrow_texture =
                            get_texture_arrow_thin_end(
                                textures,
                                get_opposite_dir4(charge_distance_info.dir4)
                            );

                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            get_texture_1_from_object(source_object, textures)
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(charge_curr_tilemap_pos)
                        );
                    }
                    else
                    {
                        charge_arrow_texture =
                            get_texture_arrow_thin_from_to(
                                textures,
                                charge_distance_info.dir4,
                                get_opposite_dir4(charge_distance_info.dir4)
                            );
                    }

                    if(!vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_position))
                    {
                        // actions
                        add_action_to_end_action_sequence(
                            action_sequence,
                            new_action_move(
                                charge_curr_tilemap_pos,
                                charge_distance_info.dir4
                            )
                        );
                    }

                    // draw below
                    add_new_list_element_to_list_end(
                        draw_below_texture_list,
                        charge_arrow_texture
                    );
                    add_new_list_element_to_list_end(
                        draw_below_tilemap_pos_list,
                        new_vec2i_from_vec2i(charge_curr_tilemap_pos)
                    );

                    // next

                    charge_prev_tilemap_pos = charge_curr_tilemap_pos;
                    charge_curr_tilemap_pos = charge_next_tilemap_pos;
                    charge_next_tilemap_pos = vec2i_move_in_dir4_by(
                        charge_curr_tilemap_pos,
                        charge_distance_info.dir4,
                        1
                    );

                    charge_prev_object = room_get_object_at(
                        state->curr_room,
                        charge_prev_tilemap_pos
                    );
                    charge_curr_object = room_get_object_at(
                        state->curr_room,
                        charge_curr_tilemap_pos
                    );
                    charge_next_object = room_get_object_at(
                        state->curr_room,
                        charge_next_tilemap_pos
                    );

                    charge_prev_floor = room_get_floor_at(
                        state->curr_room,
                        charge_prev_tilemap_pos
                    );
                    charge_curr_floor = room_get_floor_at(
                        state->curr_room,
                        charge_curr_tilemap_pos
                    );
                    charge_next_floor = room_get_floor_at(
                        state->curr_room,
                        charge_next_tilemap_pos
                    );
                }

                // actions
                add_action_to_end_action_sequence(
                    action_sequence,
                    new_action_damage(target_1_object, 1)
                );

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.damage_1
                );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_1_tilemap_pos)
                );

                if(charge_go_on)
                {
                    if(target_1_object != NULL &&
                       is_object_movable(target_1_object))
                    {
                        DistanceInfo push_distance_info =
                            get_distance_info_from_vec2i_to_vec2i(
                                target_1_tilemap_pos,
                                target_2_tilemap_pos
                            );

                        if(push_distance_info.dir4 != DIR4__NONE)
                        {
                            // init

                            Vec2i push_prev_tilemap_pos = target_1_tilemap_pos;
                            Vec2i push_curr_tilemap_pos = target_1_tilemap_pos;
                            Vec2i push_next_tilemap_pos = vec2i_move_in_dir4_by(
                                push_curr_tilemap_pos,
                                push_distance_info.dir4,
                                1
                            );

                            Object* push_prev_object = room_get_object_at(
                                state->curr_room,
                                push_prev_tilemap_pos
                            );
                            Object* push_curr_object = room_get_object_at(
                                state->curr_room,
                                push_curr_tilemap_pos
                            );
                            Object* push_next_object = room_get_object_at(
                                state->curr_room,
                                push_next_tilemap_pos
                            );

                            int push_prev_floor = room_get_floor_at(
                                state->curr_room,
                                push_prev_tilemap_pos
                            );
                            int push_curr_floor = room_get_floor_at(
                                state->curr_room,
                                push_curr_tilemap_pos
                            );
                            int push_next_floor = room_get_floor_at(
                                state->curr_room,
                                push_next_tilemap_pos
                            );

                            int push_go_on = TRUE;
                            for(int i = 0; i < push_distance_info.abs_diff + 1 && push_go_on; i++)
                            {
                                Texture* push_arrow_texture = NULL;

                                if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
                                {
                                    push_arrow_texture =
                                        get_texture_arrow_thin_start(
                                            textures,
                                            push_distance_info.dir4
                                        );
                                }
                                else if(push_curr_object != NULL ||
                                        is_floor_deadly_on_move_for_object(
                                            push_curr_floor,
                                            target_1_object)
                                        )
                                {
                                    push_go_on = FALSE;

                                    push_arrow_texture =
                                        get_texture_arrow_thin_end(
                                            textures,
                                            get_opposite_dir4(push_distance_info.dir4)
                                        );

                                    if(is_floor_deadly_on_move_for_object(
                                        push_curr_floor,
                                        target_1_object)
                                        )
                                    {
                                        // draw effect
                                        add_new_list_element_to_list_end(
                                            draw_effect_texture_list,
                                            textures->skill.death_effect
                                        );
                                        add_new_list_element_to_list_end(
                                            draw_effect_tilemap_pos_list,
                                            new_vec2i_from_vec2i(push_curr_tilemap_pos)
                                        );
                                    }
                                    else
                                    {
                                        // draw effect
                                        add_new_list_element_to_list_end(
                                            draw_effect_texture_list,
                                            get_texture_1_from_object(target_1_object, textures)
                                        );
                                        add_new_list_element_to_list_end(
                                            draw_effect_tilemap_pos_list,
                                            new_vec2i_from_vec2i(push_curr_tilemap_pos)
                                        );
                                    }
                                }
                                else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                                {
                                    push_arrow_texture =
                                        get_texture_arrow_thin_end(
                                            textures,
                                            get_opposite_dir4(push_distance_info.dir4)
                                        );

                                    // draw effect
                                    add_new_list_element_to_list_end(
                                        draw_effect_texture_list,
                                        get_texture_1_from_object(target_1_object, textures)
                                    );
                                    add_new_list_element_to_list_end(
                                        draw_effect_tilemap_pos_list,
                                        new_vec2i_from_vec2i(push_curr_tilemap_pos)
                                    );
                                }
                                else
                                {
                                    push_arrow_texture =
                                        get_texture_arrow_thin_from_to(
                                            textures,
                                            push_distance_info.dir4,
                                            get_opposite_dir4(push_distance_info.dir4)
                                        );
                                }

                                if(!vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                                {
                                    if(!is_object_floating(target_1_object) &&
                                    !is_object_flying(target_1_object))
                                    {
                                        // actions
                                        add_action_to_end_action_sequence(
                                            action_sequence,
                                            new_action_move(
                                                push_curr_tilemap_pos,
                                                push_distance_info.dir4
                                            )
                                        );
                                    }
                                    else if(is_object_floating(target_1_object))
                                    {
                                        // actions
                                        add_action_to_end_action_sequence(
                                            action_sequence,
                                            new_action_move_floating(
                                                push_curr_tilemap_pos,
                                                push_distance_info.dir4
                                            )
                                        );
                                    }
                                    else if(is_object_flying(target_1_object))
                                    {
                                        // actions
                                        add_action_to_end_action_sequence(
                                            action_sequence,
                                            new_action_move_flying(
                                                push_curr_tilemap_pos,
                                                push_distance_info.dir4
                                            )
                                        );
                                    }
                                }

                                // draw below
                                add_new_list_element_to_list_end(
                                    draw_below_texture_list,
                                    push_arrow_texture
                                );
                                add_new_list_element_to_list_end(
                                    draw_below_tilemap_pos_list,
                                    new_vec2i_from_vec2i(push_curr_tilemap_pos)
                                );

                                // next

                                push_prev_tilemap_pos = push_curr_tilemap_pos;
                                push_curr_tilemap_pos = push_next_tilemap_pos;
                                push_next_tilemap_pos = vec2i_move_in_dir4_by(
                                    push_curr_tilemap_pos,
                                    push_distance_info.dir4,
                                    1
                                );

                                push_prev_object = room_get_object_at(
                                    state->curr_room,
                                    push_prev_tilemap_pos
                                );
                                push_curr_object = room_get_object_at(
                                    state->curr_room,
                                    push_curr_tilemap_pos
                                );
                                push_next_object = room_get_object_at(
                                    state->curr_room,
                                    push_next_tilemap_pos
                                );

                                push_prev_floor = room_get_floor_at(
                                    state->curr_room,
                                    push_prev_tilemap_pos
                                );
                                push_curr_floor = room_get_floor_at(
                                    state->curr_room,
                                    push_curr_tilemap_pos
                                );
                                push_next_floor = room_get_floor_at(
                                    state->curr_room,
                                    push_next_tilemap_pos
                                );
                            }
                        }
                    }
                }
            }
        }
        break;
    //     case SKILL__CHARGE_AND_THROW:
    //     {
    //         DistanceInfo charge_distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_1_tilemap_pos
    //             );

    //         if(charge_distance_info.dir4 != DIR4__NONE)
    //         {
    //             Vec2i just_before_target_1_position = vec2i_move_in_dir4_by(
    //                 target_1_tilemap_pos,
    //                 get_opposite_dir4(charge_distance_info.dir4),
    //                 1
    //             );

    //             // init

    //             Vec2i charge_prev_tilemap_pos = source_tilemap_pos;
    //             Vec2i charge_curr_tilemap_pos = source_tilemap_pos;
    //             Vec2i charge_next_tilemap_pos = vec2i_move_in_dir4_by(
    //                 charge_curr_tilemap_pos,
    //                 charge_distance_info.dir4,
    //                 1
    //             );

    //             Object* charge_prev_object = room_get_object_at(
    //                 state->curr_room,
    //                 charge_prev_tilemap_pos
    //             );
    //             Object* charge_curr_object = room_get_object_at(
    //                 state->curr_room,
    //                 charge_curr_tilemap_pos
    //             );
    //             Object* charge_next_object = room_get_object_at(
    //                 state->curr_room,
    //                 charge_next_tilemap_pos
    //             );

    //             int charge_prev_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 charge_prev_tilemap_pos
    //             );
    //             int charge_curr_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 charge_curr_tilemap_pos
    //             );
    //             int charge_next_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 charge_next_tilemap_pos
    //             );

    //             int charge_go_on = TRUE;
    //             for(int i = 0; i < charge_distance_info.abs_diff && charge_go_on; i++)
    //             {
    //                 Texture* charge_arrow_texture = NULL;

    //                 if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
    //                 {
    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_start(
    //                             textures,
    //                             charge_distance_info.dir4
    //                         );
    //                 }
    //                 else if(charge_curr_object != NULL ||
    //                         is_floor_deadly_on_move_for_object(
    //                             charge_curr_floor,
    //                             source_object)
    //                         )
    //                 {
    //                     charge_go_on = FALSE;

    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_end(
    //                             textures,
    //                             get_opposite_dir4(charge_distance_info.dir4)
    //                         );

    //                     if(is_floor_deadly_on_move_for_object(
    //                         charge_curr_floor,
    //                         source_object)
    //                         )
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.death_effect
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                         );
    //                     }
    //                     else
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             get_texture_1_from_object(source_object, textures)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                         );
    //                     }
    //                 }
    //                 else if(vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_position))
    //                 {
    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_end(
    //                             textures,
    //                             get_opposite_dir4(charge_distance_info.dir4)
    //                         );

    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         get_texture_1_from_object(source_object, textures)
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                     );
    //                 }
    //                 else
    //                 {
    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_from_to(
    //                             textures,
    //                             charge_distance_info.dir4,
    //                             get_opposite_dir4(charge_distance_info.dir4)
    //                         );
    //                 }

    //                 if(!vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_position))
    //                 {
    //                     // actions
    //                     add_action_to_end_action_sequence(
    //                         action_sequence,
    //                         new_action_move(
    //                             charge_curr_tilemap_pos,
    //                             charge_distance_info.dir4
    //                         )
    //                     );
    //                 }

    //                 // draw below
    //                 add_new_list_element_to_list_end(
    //                     draw_below_texture_list,
    //                     charge_arrow_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_below_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                 );

    //                 // next

    //                 charge_prev_tilemap_pos = charge_curr_tilemap_pos;
    //                 charge_curr_tilemap_pos = charge_next_tilemap_pos;
    //                 charge_next_tilemap_pos = vec2i_move_in_dir4_by(
    //                     charge_curr_tilemap_pos,
    //                     charge_distance_info.dir4,
    //                     1
    //                 );

    //                 charge_prev_object = room_get_object_at(
    //                     state->curr_room,
    //                     charge_prev_tilemap_pos
    //                 );
    //                 charge_curr_object = room_get_object_at(
    //                     state->curr_room,
    //                     charge_curr_tilemap_pos
    //                 );
    //                 charge_next_object = room_get_object_at(
    //                     state->curr_room,
    //                     charge_next_tilemap_pos
    //                 );

    //                 charge_prev_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     charge_prev_tilemap_pos
    //                 );
    //                 charge_curr_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     charge_curr_tilemap_pos
    //                 );
    //                 charge_next_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     charge_next_tilemap_pos
    //                 );
    //             }

    //             if(charge_go_on)
    //             {
    //                 DistanceInfo throw_distance_info =
    //                     get_distance_info_from_vec2i_to_vec2i(
    //                         target_1_tilemap_pos,
    //                         target_2_tilemap_pos
    //                     );

    //                 if(throw_distance_info.dir4 != DIR4__NONE)
    //                 {
    //                     // lift
    //                     if(target_2_object != NULL)
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_lift(
    //                                 target_1_tilemap_pos,
    //                                 throw_distance_info.dir4
    //                             )
    //                         );

    //                         // draw above
    //                         add_new_list_element_to_list_end(
    //                             draw_above_texture_list,
    //                             get_texture_lift(
    //                                 textures,
    //                                 throw_distance_info.dir4
    //                             )
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(target_1_tilemap_pos)
    //                         );
    //                     }
    //                     // throw
    //                     else
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_throw(
    //                                 target_1_tilemap_pos,
    //                                 throw_distance_info.dir4,
    //                                 throw_distance_info.abs_diff
    //                             )
    //                         );

    //                         // draw above
    //                         add_new_list_element_to_list_end(
    //                             draw_above_texture_list,
    //                             get_texture_throw(
    //                                 textures,
    //                                 throw_distance_info.dir4
    //                             )
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(target_1_tilemap_pos)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_texture_list,
    //                             textures->skill.drop
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                         );

    //                         if(is_floor_deadly_on_drop_for_object(
    //                             target_2_floor,
    //                             target_1_object)
    //                             )
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 textures->skill.death_effect
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                             );
    //                         }
    //                         else
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 get_texture_1_from_object(target_1_object, textures)
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                             );
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__CHARGE_AND_JUMP:
    //     {
    //         DistanceInfo charge_distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_1_tilemap_pos
    //             );

    //         if(charge_distance_info.dir4 != DIR4__NONE)
    //         {
    //             // init

    //             Vec2i charge_prev_tilemap_pos = source_tilemap_pos;
    //             Vec2i charge_curr_tilemap_pos = source_tilemap_pos;
    //             Vec2i charge_next_tilemap_pos = vec2i_move_in_dir4_by(
    //                 charge_curr_tilemap_pos,
    //                 charge_distance_info.dir4,
    //                 1
    //             );

    //             Object* charge_prev_object = room_get_object_at(
    //                 state->curr_room,
    //                 charge_prev_tilemap_pos
    //             );
    //             Object* charge_curr_object = room_get_object_at(
    //                 state->curr_room,
    //                 charge_curr_tilemap_pos
    //             );
    //             Object* charge_next_object = room_get_object_at(
    //                 state->curr_room,
    //                 charge_next_tilemap_pos
    //             );

    //             int charge_prev_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 charge_prev_tilemap_pos
    //             );
    //             int charge_curr_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 charge_curr_tilemap_pos
    //             );
    //             int charge_next_floor = room_get_floor_at(
    //                 state->curr_room,
    //                 charge_next_tilemap_pos
    //             );

    //             int charge_go_on = TRUE;
    //             for(int i = 0; i < charge_distance_info.abs_diff + 1 && charge_go_on; i++)
    //             {
    //                 Texture* charge_arrow_texture = NULL;

    //                 if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
    //                 {
    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_start(
    //                             textures,
    //                             charge_distance_info.dir4
    //                         );
    //                 }
    //                 else if(charge_curr_object != NULL ||
    //                         is_floor_deadly_on_move_for_object(
    //                             charge_curr_floor,
    //                             source_object)
    //                         )
    //                 {
    //                     charge_go_on = FALSE;

    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_end(
    //                             textures,
    //                             get_opposite_dir4(charge_distance_info.dir4)
    //                         );

    //                     if(is_floor_deadly_on_move_for_object(
    //                         charge_curr_floor,
    //                         source_object)
    //                         )
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.death_effect
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                         );
    //                     }
    //                     else
    //                     {
    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             get_texture_1_from_object(source_object, textures)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                         );
    //                     }
    //                 }
    //                 else if(vec2i_equals(charge_curr_tilemap_pos, target_1_tilemap_pos))
    //                 {
    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_end(
    //                             textures,
    //                             get_opposite_dir4(charge_distance_info.dir4)
    //                         );

    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         get_texture_1_from_object(source_object, textures)
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                     );
    //                 }
    //                 else
    //                 {
    //                     charge_arrow_texture =
    //                         get_texture_arrow_thin_from_to(
    //                             textures,
    //                             charge_distance_info.dir4,
    //                             get_opposite_dir4(charge_distance_info.dir4)
    //                         );
    //                 }

    //                 if(!vec2i_equals(charge_curr_tilemap_pos, target_1_tilemap_pos))
    //                 {
    //                     // actions
    //                     add_action_to_end_action_sequence(
    //                         action_sequence,
    //                         new_action_move(
    //                             charge_curr_tilemap_pos,
    //                             charge_distance_info.dir4
    //                         )
    //                     );
    //                 }

    //                 // draw below
    //                 add_new_list_element_to_list_end(
    //                     draw_below_texture_list,
    //                     charge_arrow_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_below_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(charge_curr_tilemap_pos)
    //                 );

    //                 // next

    //                 charge_prev_tilemap_pos = charge_curr_tilemap_pos;
    //                 charge_curr_tilemap_pos = charge_next_tilemap_pos;
    //                 charge_next_tilemap_pos = vec2i_move_in_dir4_by(
    //                     charge_curr_tilemap_pos,
    //                     charge_distance_info.dir4,
    //                     1
    //                 );

    //                 charge_prev_object = room_get_object_at(
    //                     state->curr_room,
    //                     charge_prev_tilemap_pos
    //                 );
    //                 charge_curr_object = room_get_object_at(
    //                     state->curr_room,
    //                     charge_curr_tilemap_pos
    //                 );
    //                 charge_next_object = room_get_object_at(
    //                     state->curr_room,
    //                     charge_next_tilemap_pos
    //                 );

    //                 charge_prev_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     charge_prev_tilemap_pos
    //                 );
    //                 charge_curr_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     charge_curr_tilemap_pos
    //                 );
    //                 charge_next_floor = room_get_floor_at(
    //                     state->curr_room,
    //                     charge_next_tilemap_pos
    //                 );
    //             }

    //             if(charge_go_on)
    //             {
    //                 DistanceInfo throw_distance_info =
    //                     get_distance_info_from_vec2i_to_vec2i(
    //                         target_1_tilemap_pos,
    //                         target_2_tilemap_pos
    //                     );

    //                 if(throw_distance_info.dir4 != DIR4__NONE)
    //                 {
    //                     // lift
    //                     if(target_2_object != NULL)
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_lift(
    //                                 target_1_tilemap_pos,
    //                                 throw_distance_info.dir4
    //                             )
    //                         );

    //                         // draw above
    //                         add_new_list_element_to_list_end(
    //                             draw_above_texture_list,
    //                             get_texture_lift(
    //                                 textures,
    //                                 throw_distance_info.dir4
    //                             )
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(target_1_tilemap_pos)
    //                         );
    //                     }
    //                     // throw
    //                     else
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_throw(
    //                                 target_1_tilemap_pos,
    //                                 throw_distance_info.dir4,
    //                                 throw_distance_info.abs_diff
    //                             )
    //                         );

    //                         // draw above
    //                         add_new_list_element_to_list_end(
    //                             draw_above_texture_list,
    //                             get_texture_throw(
    //                                 textures,
    //                                 throw_distance_info.dir4
    //                             )
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(target_1_tilemap_pos)
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_texture_list,
    //                             textures->skill.drop
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_above_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                         );

    //                         if(is_floor_deadly_on_drop_for_object(
    //                             target_2_floor,
    //                             source_object)
    //                             )
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 textures->skill.death_effect
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                             );
    //                         }
    //                         else
    //                         {
    //                             // draw effect
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_texture_list,
    //                                 get_texture_1_from_object(source_object, textures)
    //                             );
    //                             add_new_list_element_to_list_end(
    //                                 draw_effect_tilemap_pos_list,
    //                                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                             );
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
        case SKILL__DRILL:
        {
            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_damage(target_2_object, 2)
            );

            // draw effect
            add_new_list_element_to_list_end(
                draw_effect_texture_list,
                textures->skill.damage_2
            );
            add_new_list_element_to_list_end(
                draw_effect_tilemap_pos_list,
                new_vec2i_from_vec2i(target_2_tilemap_pos)
            );
        }
        break;
        case SKILL__PENETRATING_BEAM:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            if(charge_distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i < 5 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, charge_distance_info.dir4, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object != NULL && (is_object_ally(object) || is_object_enemy(object)))
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_damage(object, 1)
                            );

                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.damage_1
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                        else
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.damage_0
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
        case SKILL__BOUNCING_BEAM:
        {
            // source to target_1

            DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
            Vec2i tilemap_pos = source_tilemap_pos;
            while(!vec2i_equals(tilemap_pos, target_1_tilemap_pos))
            {
                tilemap_pos = vec2i_move_in_dir8_by(tilemap_pos, distance_info.dir8, 1);

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.damage_0
                );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(tilemap_pos)
                );
            }

            // target_1 to target_2

            distance_info = get_distance_info_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
            tilemap_pos = target_1_tilemap_pos;
            while(!vec2i_equals(tilemap_pos, target_2_tilemap_pos))
            {
                tilemap_pos = vec2i_move_in_dir8_by(tilemap_pos, distance_info.dir8, 1);

                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.damage_0
                );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(tilemap_pos)
                );
            }

            // actions
            add_action_to_end_action_sequence(
                action_sequence,
                new_action_damage(target_2_object, 2)
            );

            // draw effect
            add_new_list_element_to_list_end(
                draw_effect_texture_list,
                textures->skill.damage_2
            );
            add_new_list_element_to_list_end(
                draw_effect_tilemap_pos_list,
                new_vec2i_from_vec2i(target_2_tilemap_pos)
            );
        }
        break;
        case SKILL__FOCUSED_BEAM:
        case SKILL__COOKING_BOLT:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            if(charge_distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, charge_distance_info.dir4, i);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(object) go_on = FALSE;

                    if(object != NULL && (is_object_ally(object) || is_object_enemy(object)))
                    {
                        // actions
                        add_action_to_end_action_sequence(
                            action_sequence,
                            new_action_damage(object, 3)
                        );

                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_3
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                    else
                    {
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_0
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
        case SKILL__BRANCHING_BOLT:
        {
            // bfs lol

            int visited[TILEMAP_LENGTH * TILEMAP_LENGTH] = {0};
            int queue[TILEMAP_LENGTH * TILEMAP_LENGTH] = {0};
            int front = 0;
            int rear = 0;
            
            visited[source_tilemap_pos.y * TILEMAP_LENGTH + source_tilemap_pos.x] = 1;
            visited[target_2_tilemap_pos.y * TILEMAP_LENGTH + target_2_tilemap_pos.x] = 1;

            queue[rear++] = target_2_tilemap_pos.y * TILEMAP_LENGTH + target_2_tilemap_pos.x;

            while (front < rear)
            {
                int curr = queue[front++];
                Vec2i curr_tilemap_pos = vec2i(curr % TILEMAP_LENGTH, curr / TILEMAP_LENGTH);
                Object* curr_object = room_get_object_at(state->curr_room, curr_tilemap_pos);

                if(curr_object != NULL)
                {
                    if(is_object_ally(curr_object) || is_object_enemy(curr_object))
                    {
                        // actions
                        add_action_to_end_action_sequence(
                            action_sequence,
                            new_action_damage(curr_object, 1)
                        );
                        
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_1
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(curr_tilemap_pos)
                        );
                    }
                    else
                    {
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_0
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(curr_tilemap_pos)
                        );
                    }
                }

                for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(curr_tilemap_pos, dir8, 1);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);

                    if(is_tilemap_in_bounds(tilemap_pos) && 
                    visited[tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x] == 0 &&
                    object != NULL && !is_object_wall(object))
                    {
                        int neighbor = tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x;
                        visited[tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x] = 1;
                        queue[rear++] = tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x;
                    }
                }
            }
        }
        break;
        case SKILL__STUNNING_BOLT:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            if(distance_info.dir8 != DIR8__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(source_tilemap_pos, distance_info.dir8, i);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(object) go_on = FALSE;

                    if(object != NULL && (is_object_ally(object) || is_object_enemy(object)))
                    {
                        // stun enemy: cancel attack

                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.crash_effect
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                    else
                    {
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_0
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
        case SKILL__ELECTRIFY_FLOOR:
        {
            // bfs lol

            int visited[TILEMAP_LENGTH * TILEMAP_LENGTH] = {0};
            int queue[TILEMAP_LENGTH * TILEMAP_LENGTH] = {0};
            int front = 0;
            int rear = 0;
            
            visited[source_tilemap_pos.y * TILEMAP_LENGTH + source_tilemap_pos.x] = 1;
            visited[target_2_tilemap_pos.y * TILEMAP_LENGTH + target_2_tilemap_pos.x] = 1;

            queue[rear++] = target_2_tilemap_pos.y * TILEMAP_LENGTH + target_2_tilemap_pos.x;

            while (front < rear)
            {
                int curr = queue[front++];
                Vec2i curr_tilemap_pos = vec2i(curr % TILEMAP_LENGTH, curr / TILEMAP_LENGTH);
                Object* curr_object = room_get_object_at(state->curr_room, curr_tilemap_pos);
                int curr_floor = room_get_floor_at(state->curr_room, curr_tilemap_pos);

                if(curr_floor == FLOOR__WATER)
                {
                    if(curr_object != NULL && (is_object_ally(curr_object) || is_object_enemy(curr_object)))
                    {
                        // actions
                        add_action_to_end_action_sequence(
                            action_sequence,
                            new_action_damage(curr_object, 1)
                        );
                        
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_1
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(curr_tilemap_pos)
                        );
                    }
                    else
                    {
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_0
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(curr_tilemap_pos)
                        );
                    }
                }

                for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir8_by(curr_tilemap_pos, dir8, 1);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(is_tilemap_in_bounds(tilemap_pos) && 
                    visited[tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x] == 0 &&
                    floor == FLOOR__WATER)
                    {
                        int neighbor = tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x;
                        visited[tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x] = 1;
                        queue[rear++] = tilemap_pos.y * TILEMAP_LENGTH + tilemap_pos.x;
                    }
                }
            }
        }
        break;
        case SKILL__SCORCH_WITH_FIRE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );
            
            List* cone_tilemap_pos_list = new_list((void(*)(void*))destroy_vec2i);

            int x = source_tilemap_pos.x;
            int y = source_tilemap_pos.y;

            switch(distance_info.dir8)
            {
                case DIR8__UP_LEFT:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y - 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y - 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y - 2));
                    
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y - 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y - 3));
                }
                break;
                case DIR8__UP:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 0, y - 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 0, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y - 2));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 0, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y - 3));
                }
                break;
                case DIR8__UP_RIGHT:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y - 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y - 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y - 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y - 1));
                }
                break;
                case DIR8__RIGHT:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y + 0));
                    
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y - 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y + 0));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y + 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y - 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y + 0));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y + 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y + 2));
                }
                break;
                case DIR8__DOWN_RIGHT:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y + 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y + 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 3, y + 1));
                }
                break;
                case DIR8__DOWN:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 0, y + 1));
                    
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 0, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y + 2));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 0, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 1, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x + 2, y + 3));
                }
                break;
                case DIR8__DOWN_LEFT:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y + 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y + 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y + 3));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y + 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y + 1));
                }
                break;
                case DIR8__LEFT:
                {
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 1, y + 0));
                    
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y - 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y + 0));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 2, y + 1));

                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y - 2));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y - 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y + 0));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y + 1));
                    add_new_list_element_to_list_end(cone_tilemap_pos_list, new_vec2i(x - 3, y + 2));
                }
                break;
                default:
                break;
            }

            if(distance_info.dir8 != DIR8__NONE)
            {
                for(ListElem* list_elem = cone_tilemap_pos_list->head; list_elem != NULL; list_elem = list_elem->next)
                {
                    Vec2i* tilemap_pos_ptr = list_elem->data;
                    Vec2i tilemap_pos = vec2i(tilemap_pos_ptr->x, tilemap_pos_ptr->y);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object != NULL && (is_object_ally(object) || is_object_enemy(object)))
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_damage(object, 1)
                            );
                            
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.damage_1
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                        else
                        {
                            // draw effect
                            add_new_list_element_to_list_end(
                                draw_effect_texture_list,
                                textures->skill.damage_0
                            );
                            add_new_list_element_to_list_end(
                                draw_effect_tilemap_pos_list,
                                new_vec2i_from_vec2i(tilemap_pos)
                            );
                        }
                    }
                }
            }

            remove_all_list_elements(cone_tilemap_pos_list, TRUE);
            destroy_list(cone_tilemap_pos_list);
        }
        break;
        case SKILL__SPEW_TAR_BALL:
        {
            if(target_2_object == NULL)
            {
                DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

                for(int i = 0; i < distance_info.abs_diff + 1; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        distance_info.dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Texture* dots_arch_texture = NULL;

                        switch(distance_info.dir4)
                        {
                            case DIR4__UP: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break; break;
                            case DIR4__RIGHT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, i + 1); break;
                            case DIR4__DOWN: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, i + 1); break; break;
                            case DIR4__LEFT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break;
                        }

                        // draw above
                        add_new_list_element_to_list_end(
                            draw_above_texture_list,
                            dots_arch_texture
                        );
                        add_new_list_element_to_list_end
                        (
                            draw_above_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }

                // actions
                Object* new_object_tar_ball = new_object(OBJECT__TAR_BALL);
                add_action_after_curr_action_action_sequence(
                    action_sequence,
                    new_action_add_object(
                        new_object_tar_ball,
                        target_2_tilemap_pos
                    )
                );
                add_action_after_curr_action_action_sequence(
                    action_sequence,
                    new_action_drop(
                        new_object_tar_ball,
                        target_2_tilemap_pos,
                        distance_info.dir4
                    )
                );

                if(is_floor_deadly_on_drop_for_object(
                    target_2_floor,
                    state->minibot_object)
                    )
                {
                    // draw effect
                    add_new_list_element_to_list_end(
                        draw_effect_texture_list,
                        textures->skill.death_effect
                    );
                    add_new_list_element_to_list_end(
                        draw_effect_tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
                }
                else
                {
                    // draw effect
                    add_new_list_element_to_list_end(
                        draw_effect_texture_list,
                        textures->object.tar_ball
                    );
                    add_new_list_element_to_list_end(
                        draw_effect_tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
                }
            }
        }
        break;
        case SKILL__ICE_BLOCK:
        {
            // actions
            Object* new_object_ice_block = new_object(OBJECT__ICE_BLOCK);
            add_action_after_curr_action_action_sequence(
                action_sequence,
                new_action_add_object(
                    new_object_ice_block,
                    target_2_tilemap_pos
                )
            );
            add_action_after_curr_action_action_sequence(
                action_sequence,
                new_action_drop(
                    new_object_ice_block,
                    target_2_tilemap_pos,
                    DIR4__NONE
                )
            );

            if(is_floor_deadly_on_drop_for_object(
                target_2_floor,
                new_object_ice_block)
                )
            {
                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->skill.death_effect
                );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                );
            }
            else
            {
                // draw effect
                add_new_list_element_to_list_end(
                    draw_effect_texture_list,
                    textures->object.ice_block
                );
                add_new_list_element_to_list_end(
                    draw_effect_tilemap_pos_list,
                    new_vec2i_from_vec2i(target_2_tilemap_pos)
                );
            }
        }
        break;
        case SKILL__ICE_WALL:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            List* wall_tilemap_pos_list = new_list((void(*)(void*))destroy_vec2i);

            int x = target_2_tilemap_pos.x;
            int y = target_2_tilemap_pos.y;

            switch(distance_info.dir4)
            {
                case DIR4__UP:
                {
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x - 1, y ));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 0, y));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 1, y));
                }
                break;
                case DIR4__RIGHT:
                {
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x, y - 1));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x, y + 0));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x, y + 1));
                }
                break;
                case DIR4__DOWN:
                {
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x - 1, y));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 0, y));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 1, y));
                }
                break;
                case DIR4__LEFT:
                {
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x, y - 1));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x, y + 0));
                    add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x, y + 1));
                }
                break;
                default:
                break;
            }

            if(distance_info.dir4 != DIR4__NONE)
            {
                for(ListElem* list_elem = wall_tilemap_pos_list->head; list_elem != NULL; list_elem = list_elem->next)
                {
                    Vec2i* tilemap_pos_ptr = list_elem->data;
                    Vec2i tilemap_pos = vec2i(tilemap_pos_ptr->x, tilemap_pos_ptr->y);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object == NULL)
                        {
                            // actions
                            Object* new_object_ice_block = new_object(OBJECT__ICE_BLOCK);
                            add_action_after_curr_action_action_sequence(
                                action_sequence,
                                new_action_add_object(
                                    new_object_ice_block,
                                    tilemap_pos
                                )
                            );
                            add_action_after_curr_action_action_sequence(
                                action_sequence,
                                new_action_drop(
                                    new_object_ice_block,
                                    tilemap_pos,
                                    DIR4__NONE
                                )
                            );

                            if(is_floor_deadly_on_drop_for_object(
                                floor,
                                new_object_ice_block)
                                )
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    textures->skill.death_effect
                                );
                                add_new_list_element_to_list_end(
                                    draw_effect_tilemap_pos_list,
                                    new_vec2i_from_vec2i(tilemap_pos)
                                );
                            }
                            else
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    textures->object.ice_block
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

            remove_all_list_elements(wall_tilemap_pos_list, TRUE);
            destroy_list(wall_tilemap_pos_list);
        }
        break;
        case SKILL__ICE_BUNKER:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            List* wall_tilemap_pos_list = new_list((void(*)(void*))destroy_vec2i);

            int x = target_2_tilemap_pos.x;
            int y = target_2_tilemap_pos.y;

            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x - 1, y - 1));
            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x - 1, y + 0));
            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x - 1, y + 1));
            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 0, y + 1));
            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 1, y + 1));
            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 1, y + 0));
            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 1, y - 1));
            add_new_list_element_to_list_end(wall_tilemap_pos_list, new_vec2i(x + 0, y - 1));

                for(ListElem* list_elem = wall_tilemap_pos_list->head; list_elem != NULL; list_elem = list_elem->next)
                {
                    Vec2i* tilemap_pos_ptr = list_elem->data;
                    Vec2i tilemap_pos = vec2i(tilemap_pos_ptr->x, tilemap_pos_ptr->y);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                        int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(object == NULL)
                        {
                            // actions
                            Object* new_object_ice_block = new_object(OBJECT__ICE_BLOCK);
                            add_action_after_curr_action_action_sequence(
                                action_sequence,
                                new_action_add_object(
                                    new_object_ice_block,
                                    tilemap_pos
                                )
                            );
                            add_action_after_curr_action_action_sequence(
                                action_sequence,
                                new_action_drop(
                                    new_object_ice_block,
                                    tilemap_pos,
                                    DIR4__NONE
                                )
                            );

                            if(is_floor_deadly_on_drop_for_object(
                                floor,
                                new_object_ice_block)
                                )
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    textures->skill.death_effect
                                );
                                add_new_list_element_to_list_end(
                                    draw_effect_tilemap_pos_list,
                                    new_vec2i_from_vec2i(tilemap_pos)
                                );
                            }
                            else
                            {
                                // draw effect
                                add_new_list_element_to_list_end(
                                    draw_effect_texture_list,
                                    textures->object.ice_block
                                );
                                add_new_list_element_to_list_end(
                                    draw_effect_tilemap_pos_list,
                                    new_vec2i_from_vec2i(tilemap_pos)
                                );
                            }
                        }
                    }
                }

            remove_all_list_elements(wall_tilemap_pos_list, TRUE);
            destroy_list(wall_tilemap_pos_list);
        }
        break;
        case SKILL__ICE_PROJECTILE:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            if(charge_distance_info.dir4 != DIR4__NONE)
            {
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, charge_distance_info.dir4, i);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                    if(object) go_on = FALSE;

                    if(object != NULL && (is_object_ally(object) || is_object_enemy(object)))
                    {
                        // actions
                        add_action_to_end_action_sequence(
                            action_sequence,
                            new_action_damage(object, 1)
                        );

                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_1
                        );
                        add_new_list_element_to_list_end(
                            draw_effect_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                    else
                    {
                        // draw effect
                        add_new_list_element_to_list_end(
                            draw_effect_texture_list,
                            textures->skill.damage_0
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
        case SKILL__FREEZE_FLOOR:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                for(int i = 1; i < TILEMAP_LENGTH; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos,distance_info.dir4,i);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                        if(floor == FLOOR__WATER)
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_change_floor(FLOOR__ICE, tilemap_pos)
                            );
                        }
                        else if(floor == FLOOR__LAVA)
                        {
                            // actions
                            add_action_to_end_action_sequence(
                                action_sequence,
                                new_action_change_floor(FLOOR__ROCK_CRACK_LAVA, tilemap_pos)
                            );
                        }
                }
            }
        }
        break;
    //     case SKILL__JUMP_AND_CARRY:
    //     {
    //         DistanceInfo source_carry_distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_1_tilemap_pos
    //             );

    //         Vec2i carry_target_2_tilemap_pos =
    //             vec2i_move_in_dir4_by(
    //                 target_2_tilemap_pos,
    //                 source_carry_distance_info.dir4,
    //                 1
    //             );
    //         Object* carry_target_2_object = room_get_object_at(
    //             state->curr_room,
    //             carry_target_2_tilemap_pos
    //         );
    //         int carry_target_2_floor = room_get_floor_at(
    //             state->curr_room,
    //             carry_target_2_tilemap_pos
    //         );

    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         if(distance_info.dir4 != DIR4__NONE)
    //         {
    //             Action* source_and_carry_throw_action_simultaneous =
    //                 new_action_simultaneous();

    //             // source_object

    //             // lift
    //             if(target_2_object != NULL)
    //             {
    //                 // actions
    //                 add_action_sequence_to_action_simultaneous(
    //                     source_and_carry_throw_action_simultaneous,
    //                     new_action_sequence_of_1(
    //                         new_action_lift(
    //                             source_tilemap_pos,
    //                             distance_info.dir4
    //                         )
    //                     )
    //                 );

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     get_texture_lift(
    //                         textures,
    //                         distance_info.dir4
    //                     )
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(source_tilemap_pos)
    //                 );
    //             }
    //             // throw
    //             else
    //             {
    //                 // actions
    //                 add_action_sequence_to_action_simultaneous(
    //                     source_and_carry_throw_action_simultaneous,
    //                     new_action_sequence_of_1(
    //                         new_action_throw(
    //                             source_tilemap_pos,
    //                             distance_info.dir4,
    //                             distance_info.abs_diff
    //                         )
    //                     )
    //                 );

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     get_texture_throw(
    //                         textures,
    //                         distance_info.dir4
    //                     )
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(source_tilemap_pos)
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     textures->skill.drop
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                 );

    //                 if(is_floor_deadly_on_drop_for_object(
    //                     target_2_floor,
    //                     source_object)
    //                     )
    //                 {
    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         textures->skill.death_effect
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                     );
    //                 }
    //                 else
    //                 {
    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         get_texture_1_from_object(source_object, textures)
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                     );
    //                 }
    //             }

    //             // target_1_object

    //             // lift
    //             if(carry_target_2_object != NULL)
    //             {
    //                 // actions
    //                 add_action_sequence_to_action_simultaneous(
    //                     source_and_carry_throw_action_simultaneous,
    //                     new_action_sequence_of_1(
    //                         new_action_lift(
    //                             target_1_tilemap_pos,
    //                             distance_info.dir4
    //                         )
    //                     )
    //                 );

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     get_texture_lift(
    //                         textures,
    //                         distance_info.dir4
    //                     )
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(target_1_tilemap_pos)
    //                 );
    //             }
    //             // throw
    //             else
    //             {
    //                 // actions
    //                 add_action_sequence_to_action_simultaneous(
    //                     source_and_carry_throw_action_simultaneous,
    //                     new_action_sequence_of_1(
    //                         new_action_throw(
    //                             target_1_tilemap_pos,
    //                             distance_info.dir4,
    //                             distance_info.abs_diff
    //                         )
    //                     )
    //                 );

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     get_texture_throw(
    //                         textures,
    //                         distance_info.dir4
    //                     )
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(target_1_tilemap_pos)
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     textures->skill.drop
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(carry_target_2_tilemap_pos)
    //                 );

    //                 if(is_floor_deadly_on_drop_for_object(
    //                     carry_target_2_floor,
    //                     target_1_object)
    //                     )
    //                 {
    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         textures->skill.death_effect
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(carry_target_2_tilemap_pos)
    //                     );
    //                 }
    //                 else
    //                 {
    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         get_texture_1_from_object(target_1_object, textures)
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(carry_target_2_tilemap_pos)
    //                     );
    //                 }
    //             }

    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 source_and_carry_throw_action_simultaneous
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__JUMP_AND_STOMP:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         if(distance_info.dir4 != DIR4__NONE)
    //         {
    //             // lift
    //             if(target_2_object != NULL)
    //             {
    //                 // actions
    //                 add_action_to_end_action_sequence(
    //                     action_sequence,
    //                     new_action_lift(
    //                         source_tilemap_pos,
    //                         distance_info.dir4
    //                     )
    //                 );

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     get_texture_lift(
    //                         textures,
    //                         distance_info.dir4
    //                     )
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(source_tilemap_pos)
    //                 );
    //             }
    //             // throw
    //             else
    //             {
    //                 // actions
    //                 add_action_to_end_action_sequence(
    //                     action_sequence,
    //                     new_action_throw(
    //                         source_tilemap_pos,
    //                         distance_info.dir4,
    //                         distance_info.abs_diff
    //                     )
    //                 );

    //                 for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //                 {
    //                     Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                         target_2_tilemap_pos,
    //                         dir4,
    //                         1
    //                     );

    //                     if(is_tilemap_in_bounds(tilemap_pos))
    //                     {
    //                         Object* object = room_get_object_at(
    //                             state->curr_room,
    //                             tilemap_pos
    //                         );
    //                         int floor = room_get_floor_at(
    //                             state->curr_room,
    //                             tilemap_pos
    //                         );

    //                         if(object != NULL)
    //                         {
    //                             // actions
    //                             object_on_stomp(
    //                                 state,
    //                                 sounds,
    //                                 action_sequence,
    //                                 object,
    //                                 tilemap_pos
    //                             );
    //                         }
    //                         else
    //                         {
    //                             // actions
    //                             floor_on_stomp(
    //                                 state,
    //                                 sounds,
    //                                 action_sequence,
    //                                 floor,
    //                                 tilemap_pos
    //                             );
    //                         }

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.stomp_effect
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );
    //                     }
    //                 }

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     get_texture_throw(
    //                         textures,
    //                         distance_info.dir4
    //                     )
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(source_tilemap_pos)
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     textures->skill.drop
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                 );

    //                 if(is_floor_deadly_on_drop_for_object(
    //                     target_2_floor,
    //                     source_object)
    //                     )
    //                 {
    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         textures->skill.death_effect
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                     );
    //                 }
    //                 else
    //                 {
    //                     // draw effect
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_texture_list,
    //                         get_texture_1_from_object(source_object, textures)
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_effect_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(target_2_tilemap_pos)
    //                     );
    //                 }
    //             }
    //         }
    //     }
    //     break;
        case SKILL__LAUNCH_MINIBOT:
        {
            if(target_2_object == NULL)
            {
                DistanceInfo distance_info = get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                );

                for(int i = 0; i < distance_info.abs_diff + 1; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        distance_info.dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Texture* dots_arch_texture = NULL;

                        switch(distance_info.dir4)
                        {
                            case DIR4__UP: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break; break;
                            case DIR4__RIGHT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, i + 1); break;
                            case DIR4__DOWN: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, i + 1); break; break;
                            case DIR4__LEFT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break;
                        }

                        // draw above
                        add_new_list_element_to_list_end(
                            draw_above_texture_list,
                            dots_arch_texture
                        );
                        add_new_list_element_to_list_end
                        (
                            draw_above_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }

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

                if(is_floor_deadly_on_drop_for_object(
                    target_2_floor,
                    state->minibot_object)
                    )
                {
                    // draw effect
                    add_new_list_element_to_list_end(
                        draw_effect_texture_list,
                        textures->skill.death_effect
                    );
                    add_new_list_element_to_list_end(
                        draw_effect_tilemap_pos_list,
                        new_vec2i_from_vec2i(target_2_tilemap_pos)
                    );
                }
                else
                {
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
        }
        break;
        case SKILL__MINIBOT_MERGE:
        {
            //
        }
        break;
    //     case SKILL__TURRET_LASER:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         if(distance_info.dir4 != DIR4__NONE)
    //         {
    //             for(int i = 1; i <= OBJECT_TURRET_RANGE; i++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     source_tilemap_pos,
    //                     distance_info.dir4,
    //                     i
    //                 );

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     // draw below
    //                     add_new_list_element_to_list_end(
    //                         draw_below_texture_list,
    //                         textures->skill.floor_danger
    //                     );
    //                     add_new_list_element_to_list_end(
    //                         draw_below_tilemap_pos_list,
    //                         new_vec2i_from_vec2i(tilemap_pos)
    //                     );

    //                     if(object != NULL && is_object_meltable(object))
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_melt(tilemap_pos)
    //                         );

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.melt_effect
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__TURRET_BOMB:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         for(int i = 0; i < distance_info.abs_diff + 1; i++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 distance_info.dir4,
    //                 i
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Texture* dots_arch_texture = NULL;
                    
    //                 switch(distance_info.dir4)
    //                 {
    //                     case DIR4__UP: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break; break;
    //                     case DIR4__RIGHT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, i + 1); break;
    //                     case DIR4__DOWN: dots_arch_texture = get_texture_dots_arch_vertical(textures, distance_info.abs_diff + 1, i + 1); break; break;
    //                     case DIR4__LEFT: dots_arch_texture = get_texture_dots_arch_horizontal(textures, distance_info.abs_diff + 1, distance_info.abs_diff - i + 1); break;
    //                 }

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     dots_arch_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }

    //         // actions
    //         if(target_2_object != NULL && 
    //             is_object_breakable(target_2_object))
    //         {
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_break(target_2_tilemap_pos)
    //             );
    //         }

    //         // draw below
    //         // add_new_list_element_to_list_end(
    //         //     draw_below_texture_list,
    //         //     textures->skill.floor_danger
    //         //     );
    //         // add_new_list_element_to_list_end(
    //         //     draw_below_tilemap_pos_list,
    //         //     new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         //     );

    //         if(target_2_object != NULL && 
    //             is_object_breakable(target_2_object))
    //         {
    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.break_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }

    //         for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 target_2_tilemap_pos,
    //                 dir4,
    //                 1
    //             );
    //             Object* object = room_get_object_at(
    //                 state->curr_room,
    //                 tilemap_pos
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 // actions
    //                 add_action_to_end_action_sequence(
    //                     action_sequence,
    //                     new_action_shake(tilemap_pos)
    //                 );

    //                 // draw below
    //                 // add_new_list_element_to_list_end(
    //                 //     draw_below_texture_list,
    //                 //     textures->skill.floor_danger
    //                 //     );
    //                 // add_new_list_element_to_list_end(
    //                 //     draw_below_tilemap_pos_list,
    //                 //     new_vec2i_from_vec2i(tilemap_pos)
    //                 //     );

    //                 // draw effect
    //                 add_new_list_element_to_list_end(
    //                     draw_effect_texture_list,
    //                     textures->skill.shake_effect
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_effect_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__TURRET_PROJECTILE:
    //     {
    //         DistanceInfo distance_info =
    //             get_distance_info_from_vec2i_to_vec2i(
    //                 source_tilemap_pos,
    //                 target_2_tilemap_pos
    //             );

    //         for(int i = 1; i < distance_info.abs_diff; i++)
    //         {
    //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                 source_tilemap_pos,
    //                 distance_info.dir4,
    //                 i
    //             );

    //             if(is_tilemap_in_bounds(tilemap_pos))
    //             {
    //                 Texture* dots_line_texture = NULL;
    //                 if(distance_info.dir4 == DIR4__RIGHT ||
    //                    distance_info.dir4 == DIR4__LEFT)
    //                 {
    //                     dots_line_texture = textures->skill.dots_line_horizontal;
    //                 }
    //                 if(distance_info.dir4 == DIR4__UP ||
    //                    distance_info.dir4 == DIR4__DOWN)
    //                 {
    //                     dots_line_texture = textures->skill.dots_line_vertical;
    //                 }

    //                 // draw above
    //                 add_new_list_element_to_list_end(
    //                     draw_above_texture_list,
    //                     dots_line_texture
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_above_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }

    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_shake(target_2_tilemap_pos)
    //         );

    //         // draw below
    //         // add_new_list_element_to_list_end(
    //         //     draw_below_texture_list,
    //         //     textures->skill.floor_danger
    //         //     );
    //         // add_new_list_element_to_list_end(
    //         //     draw_below_tilemap_pos_list,
    //         //     new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         //     );

    //         // draw effect
    //         add_new_list_element_to_list_end(
    //             draw_effect_texture_list,
    //             textures->skill.shake_effect
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_effect_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );
    //     }
    //     break;
    //     case SKILL__KILL_AROUND:
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

    //                 if(object != NULL)
    //                 {
    //                     if(object->type == OBJECT__BARREL)
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_blow_up(
    //                                 tilemap_pos
    //                             )
    //                         );
    //                     }
    //                     else if(is_object_wall(object) || is_object_exit(object))
    //                     {
    //                         //
    //                     }
    //                     else if(is_object_ally(object) || is_object_enemy(object))
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_death(
    //                                 object,
    //                                 tilemap_pos
    //                             )
    //                         );
    //                     }
    //                     else
    //                     {
    //                         // actions
    //                         add_action_to_end_action_sequence(
    //                             action_sequence,
    //                             new_action_remove_object(
    //                                 object,
    //                                 tilemap_pos
    //                             )
    //                         );
    //                     }
    //                 }

    //                 // draw below
    //                 add_new_list_element_to_list_end(
    //                     draw_below_texture_list,
    //                     textures->skill.floor_danger
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_below_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );

    //                 // draw effect
    //                 add_new_list_element_to_list_end(
    //                     draw_effect_texture_list,
    //                     textures->skill.death_effect
    //                 );
    //                 add_new_list_element_to_list_end(
    //                     draw_effect_tilemap_pos_list,
    //                     new_vec2i_from_vec2i(tilemap_pos)
    //                 );
    //             }
    //         }
    //     }
    //     break;
    //     case SKILL__ENVIRONMENT_FALLING_STALACTITE:
    //     {
    //         if(target_2_object != NULL)
    //         {
    //             if(is_object_ally(target_2_object) ||
    //                is_object_enemy(target_2_object))
    //             {
    //                 // actions
    //                 add_action_to_end_action_sequence(
    //                     action_sequence,
    //                     new_action_death(
    //                         target_2_object,
    //                         target_2_tilemap_pos
    //                     )
    //                 );
    //             }
    //             else
    //             {
    //                 // actions
    //                 add_action_to_end_action_sequence(
    //                     action_sequence,
    //                     new_action_remove_object(
    //                         target_2_object,
    //                         target_2_tilemap_pos
    //                     )
    //                 );
    //             }
    //         }

    //         if(target_2_floor == FLOOR__WATER)
    //         {
    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_change_floor(
    //                     FLOOR__WATER_STALACTITE_FALLEN,
    //                     target_2_tilemap_pos
    //                 )
    //             );
    //         }
    //         else if(target_2_floor == FLOOR__LAVA)
    //         {
    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_change_floor(
    //                     FLOOR__LAVA_STALACTITE_FALLEN,
    //                     target_2_tilemap_pos
    //                 )
    //             );
    //         }
    //         else if(target_2_floor == FLOOR__PIT)
    //         {
    //             //
    //         }
    //         else
    //         {
    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_add_object(
    //                     new_object(OBJECT__STALACTITE_FALLEN),
    //                     target_2_tilemap_pos
    //                 )
    //             );
    //         }

    //         // draw below
    //         add_new_list_element_to_list_end(
    //             draw_below_texture_list,
    //             textures->skill.floor_environment_falling_stalactite
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_below_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );

    //         if(target_2_object != NULL)
    //         {
    //             // draw effect
    //             add_new_list_element_to_list_end(
    //                 draw_effect_texture_list,
    //                 textures->skill.death_effect
    //             );
    //             add_new_list_element_to_list_end(
    //                 draw_effect_tilemap_pos_list,
    //                 new_vec2i_from_vec2i(target_2_tilemap_pos)
    //             );
    //         }
    //     }
    //     break;
    //     case SKILL__ENVIRONMENT_EMERGE_WATER:
    //     {
    //         if(target_2_object == NULL)
    //         {
    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_add_object(
    //                     new_object(OBJECT__SQUID),
    //                     target_2_tilemap_pos
    //                 )
    //             );
    //         }

    //         // draw below
    //         add_new_list_element_to_list_end(
    //             draw_below_texture_list,
    //             textures->skill.floor_environment_emerge_water
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_below_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );
    //     }
    //     break;
    //     case SKILL__ENVIRONMENT_EMERGE_PIT:
    //     {
    //         if(target_2_object == NULL)
    //         {
    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_add_object(
    //                     new_object(OBJECT__FLY),
    //                     target_2_tilemap_pos
    //                 )
    //             );
    //         }

    //         // draw below
    //         add_new_list_element_to_list_end(
    //             draw_below_texture_list,
    //             textures->skill.floor_environment_emerge_pit
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_below_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );
    //     }
    //     break;
    //     case SKILL__ENVIRONMENT_EMERGE_BURROW:
    //     {
    //         if(target_2_object == NULL)
    //         {
    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_add_object(
    //                     new_object(OBJECT__MOLE),
    //                     target_2_tilemap_pos
    //                 )
    //             );
    //         }

    //         // draw below
    //         add_new_list_element_to_list_end(
    //             draw_below_texture_list,
    //             textures->skill.floor_environment_emerge_burrow
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_below_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );
    //     }
    //     break;
    //     case SKILL__ENVIRONMENT_EMERGE_PIPE:
    //     {
    //         if(target_2_object != NULL && target_2_object->type == OBJECT__PIPE)
    //         {
    //             int is_able_to_emerge = FALSE;
    //             int emerge_dir4 = DIR4__NONE;
    //             for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
    //             {
    //                 Vec2i tilemap_pos = vec2i_move_in_dir4_by(
    //                     target_2_tilemap_pos,
    //                     dir4,
    //                     1
    //                 );
    //                 Object* object = room_get_object_at(
    //                     state->curr_room,
    //                     tilemap_pos
    //                 );
    //                 if(object == NULL)
    //                 {
    //                     is_able_to_emerge = TRUE;
    //                     emerge_dir4 = dir4;
    //                 }
    //             }
    //             if(is_able_to_emerge)
    //             {
    //                 // actions
    //                 add_action_to_end_action_sequence(
    //                     action_sequence,
    //                     new_action_add_object(
    //                         new_object(OBJECT__MINIBOT_ENEMY),
    //                         vec2i_move_in_dir4_by(
    //                             target_2_tilemap_pos,
    //                             emerge_dir4,
    //                             1
    //                         )
    //                     )
    //                 );
    //                 add_action_to_end_action_sequence(
    //                     action_sequence,
    //                     new_action_drop(
    //                         new_object(OBJECT__MINIBOT_ENEMY),
    //                         vec2i_move_in_dir4_by(
    //                             target_2_tilemap_pos,
    //                             emerge_dir4,
    //                             1
    //                         ),
    //                         emerge_dir4
    //                     )
    //                 );
    //             }
    //         }

    //         // draw below
    //         add_new_list_element_to_list_end(
    //             draw_below_texture_list,
    //             textures->skill.floor_border_solid
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_below_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );

    //         // draw above
    //         add_new_list_element_to_list_end(
    //             draw_above_texture_list,
    //             textures->skill.environment_emerge_pipe
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_above_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );
    //     }
    //     break;
    //     case SKILL__ENVIRONMENT_COLLAPSE_BURROW:
    //     {
    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             new_action_change_floor(
    //                 FLOOR__PIT,
    //                 target_2_tilemap_pos
    //             )
    //         );

    //         if(target_2_object != NULL)
    //         {
    //             // actions
    //             add_action_to_end_action_sequence(
    //                 action_sequence,
    //                 new_action_fall(
    //                     target_2_object,
    //                     target_2_tilemap_pos
    //                 )
    //             );
    //         }

    //         // draw below
    //         add_new_list_element_to_list_end(
    //             draw_below_texture_list,
    //             textures->skill.floor_environment_collapse_burrow
    //         );
    //         add_new_list_element_to_list_end(
    //             draw_below_tilemap_pos_list,
    //             new_vec2i_from_vec2i(target_2_tilemap_pos)
    //         );
    //     }
    //     break;
    //     case SKILL__ENVIRONMENT_CONV_BELT:
    //     {
    //         Action* action_simultaneous = new_action_simultaneous();

    //         for(int i = 0; i < TILEMAP_LENGTH; i++)
    //         {
    //             for(int j = 0; j < TILEMAP_LENGTH; j++)
    //             {
    //                 Vec2i tilemap_pos = vec2i(i, j);

    //                 if(is_tilemap_in_bounds(tilemap_pos))
    //                 {
    //                     int floor = room_get_floor_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );
    //                     Object* object = room_get_object_at(
    //                         state->curr_room,
    //                         tilemap_pos
    //                     );

    //                     if(floor == FLOOR__CONV_BELT_UP)
    //                     {
    //                         // draw below
    //                         add_new_list_element_to_list_end(
    //                             draw_below_texture_list,
    //                             textures->skill.arrow_thin_down_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_below_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.arrow_thin_down_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         if(object != NULL)
    //                         {
    //                             if(is_object_flying(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_flying(
    //                                             tilemap_pos,
    //                                             DIR4__UP
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else if(is_object_floating(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_floating(
    //                                             tilemap_pos,
    //                                             DIR4__UP
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move(
    //                                             tilemap_pos,
    //                                             DIR4__UP
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                         }
    //                     }
    //                     else if(floor == FLOOR__CONV_BELT_RIGHT)
    //                     {
    //                         // draw below
    //                         add_new_list_element_to_list_end(
    //                             draw_below_texture_list,
    //                             textures->skill.arrow_thin_left_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_below_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.arrow_thin_left_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         if(object != NULL)
    //                         {
    //                             if(is_object_flying(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_flying(
    //                                             tilemap_pos,
    //                                             DIR4__RIGHT
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else if(is_object_floating(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_floating(
    //                                             tilemap_pos,
    //                                             DIR4__RIGHT
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move(
    //                                             tilemap_pos,
    //                                             DIR4__RIGHT
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                         }
    //                     }
    //                     else if(floor == FLOOR__CONV_BELT_DOWN)
    //                     {
    //                         // draw below
    //                         add_new_list_element_to_list_end(
    //                             draw_below_texture_list,
    //                             textures->skill.arrow_thin_up_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_below_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.arrow_thin_up_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         if(object != NULL)
    //                         {
    //                             if(is_object_flying(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_flying(
    //                                             tilemap_pos,
    //                                             DIR4__DOWN
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else if(is_object_floating(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_floating(
    //                                             tilemap_pos,
    //                                             DIR4__DOWN
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move(
    //                                             tilemap_pos,
    //                                             DIR4__DOWN
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                         }
    //                     }
    //                     else if(floor == FLOOR__CONV_BELT_LEFT)
    //                     {
    //                         // draw below
    //                         add_new_list_element_to_list_end(
    //                             draw_below_texture_list,
    //                             textures->skill.arrow_thin_right_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_below_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         // draw effect
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_texture_list,
    //                             textures->skill.arrow_thin_right_end
    //                         );
    //                         add_new_list_element_to_list_end(
    //                             draw_effect_tilemap_pos_list,
    //                             new_vec2i_from_vec2i(tilemap_pos)
    //                         );

    //                         if(object != NULL)
    //                         {
    //                             if(is_object_flying(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_flying(
    //                                             tilemap_pos,
    //                                             DIR4__LEFT
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else if(is_object_floating(object))
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move_floating(
    //                                             tilemap_pos,
    //                                             DIR4__LEFT
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                             else
    //                             {
    //                                 // actions
    //                                 add_action_sequence_to_action_simultaneous(
    //                                     action_simultaneous,
    //                                     new_action_sequence_of_1(
    //                                         new_action_move(
    //                                             tilemap_pos,
    //                                             DIR4__LEFT
    //                                         )
    //                                     )
    //                                 );
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }

    //         // actions
    //         add_action_to_end_action_sequence(
    //             action_sequence,
    //             action_simultaneous
    //         );
    //     }
    //     break;
        default:
        break;
    }
}
