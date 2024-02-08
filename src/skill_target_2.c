#include "../inc/state.h"

void skill_get_possible_target_2_pos(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    List* target_2_pos_list
)
{
    Object* source_object = room_get_object_at(state->curr_room, source_tilemap_pos);
    Object* target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);

    switch(skill)
    {
        case SKILL__NONE:
        {
            //
        }
        break;
        case SKILL__STOMP:
        {
            Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, 1);
            add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(up_tilemap_pos));

            Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, 1);
            add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(right_tilemap_pos));

            Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, 1);
            add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(down_tilemap_pos));

            Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, 1);
            add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(left_tilemap_pos));
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);
                int floor = room_get_floor_at(state->curr_room, tilemap_pos);
                Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                if(get_floor_item_type(floor) != ITEM__NONE ||
                (object != 0 && get_object_item_type(object) != ITEM__NONE))
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                }
            }
        }
        break;
        case SKILL__PICK_ITEM_FAR:
        {
            for(int i = 1; i < 10; i++)
            {
                for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    if(get_floor_item_type(floor) != ITEM__NONE ||
                    (object != 0 && get_object_item_type(object) != ITEM__NONE))
                    {
                        add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                    }
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_CLOSE:
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);
                int floor = room_get_floor_at(state->curr_room, tilemap_pos);
                Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                if(is_floor_put_item(floor) ||
                (object != 0 && is_object_put_item(object)))
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_FAR:
        case SKILL__PUT_ITEM_DYNAMITE_FAR:
        case SKILL__PUT_ITEM_GEMSTONE_FAR:
        {
            for(int i = 1; i < 10; i++)
            {
                for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);
                    int floor = room_get_floor_at(state->curr_room, tilemap_pos);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                    if(is_floor_put_item(floor) ||
                    (object != 0 && is_object_put_item(object)))
                    {
                        add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                    }
                }
            }
        }
        break;
        case SKILL__USE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, 1);
                Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                int floor = room_get_floor_at(state->curr_room, tilemap_pos);

                if(object != 0)
                {
                    if(is_object_exit(object))
                    {
                        add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                    }
                    else if(is_object_station(object))
                    {
                        if(state->curr_ally->object->type == OBJECT_TYPE__HERO ||
                        state->curr_ally->object->type == OBJECT_TYPE__HERO_FLOATING ||
                        state->curr_ally->object->type == OBJECT_TYPE__HERO_FLYING)
                        {
                            add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                        }
                    }
                }
                else if(floor != FLOOR_TYPE__NONE)
                {
                    if(is_floor_exit(floor))
                    {
                        add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                    }
                }
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            List* square_area_pos = new_list((void(*)(void*))destroy_vec2i);
            get_square_area_tilemap_pos(source_tilemap_pos, 10, square_area_pos);
            for(ListElem* curr_elem = square_area_pos->head; curr_elem != 0; curr_elem = curr_elem->next)
            {
                Vec2i curr_tilemap_pos = *(Vec2i*)curr_elem->data;
                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    int curr_floor = room_get_floor_at(state->curr_room, curr_tilemap_pos);
                    Object* curr_object = room_get_object_at(state->curr_room, curr_tilemap_pos);

                    if((curr_object == 0 && is_floor_manipulatable(curr_floor)) ||
                    (curr_object != 0 && is_object_manipulatable(curr_object)))
                    {
                        add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(curr_tilemap_pos));
                    }
                }
            }
            remove_all_list_elements(square_area_pos, 1);
            destroy_list(square_area_pos);
        }
        break;
        case SKILL__MOVE:
        case SKILL__MOVE_FLOATING:
        case SKILL__MOVE_FLYING:
        {
            List* square_area_pos = new_list((void(*)(void*))destroy_vec2i);
            get_square_area_tilemap_pos(source_tilemap_pos, 10, square_area_pos);
            for(ListElem* curr_elem = square_area_pos->head; curr_elem != 0; curr_elem = curr_elem->next)
            {
                Vec2i* curr_tilemap_pos = (Vec2i*)curr_elem->data;
                List* path_pos = new_list((void(*)(void*))destroy_vec2i);
                find_path(
                    state,
                    source_tilemap_pos,
                    *curr_tilemap_pos,
                    path_pos,
                    is_object_floating(source_object),
                    is_object_flying(source_object)
                    );
                if(path_pos->size > 0 && path_pos->size < 10)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(*curr_tilemap_pos));
                }
                remove_all_list_elements(path_pos, 1);
                destroy_list(path_pos);
            }
            remove_all_list_elements(square_area_pos, 1);
            destroy_list(square_area_pos);
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i < 10; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                }
            }
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i < 10; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                }
            }
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i < 10; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                }
            }
        }
        break;
        case SKILL__CHARGE:
        {
            int up_cont = 1;
            int right_cont = 1;
            int down_cont = 1;
            int left_cont = 1;

            Vec2i up_tilemap_pos = source_tilemap_pos;
            Vec2i right_tilemap_pos = source_tilemap_pos;
            Vec2i down_tilemap_pos = source_tilemap_pos;
            Vec2i left_tilemap_pos = source_tilemap_pos;

            Object* up_object = 0;
            Object* right_object = 0;
            Object* down_object = 0;
            Object* left_object = 0;

            for(int i = 1; i < 10; i++)
            {
                up_tilemap_pos = vec2i_move_in_dir4_by(up_tilemap_pos, DIR4__UP, 1);
                right_tilemap_pos = vec2i_move_in_dir4_by(right_tilemap_pos, DIR4__RIGHT, 1);
                down_tilemap_pos = vec2i_move_in_dir4_by(down_tilemap_pos, DIR4__DOWN, 1);
                left_tilemap_pos = vec2i_move_in_dir4_by(left_tilemap_pos, DIR4__LEFT, 1);

                int up_floor = room_get_floor_at(state->curr_room, up_tilemap_pos);
                int right_floor = room_get_floor_at(state->curr_room, right_tilemap_pos);
                int down_floor = room_get_floor_at(state->curr_room, down_tilemap_pos);
                int left_floor = room_get_floor_at(state->curr_room, left_tilemap_pos);

                up_object = room_get_object_at(state->curr_room, up_tilemap_pos);
                right_object = room_get_object_at(state->curr_room, right_tilemap_pos);
                down_object = room_get_object_at(state->curr_room, down_tilemap_pos);
                left_object = room_get_object_at(state->curr_room, left_tilemap_pos);

                if(up_cont) add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(up_tilemap_pos));
                if(right_cont) add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(right_tilemap_pos));
                if(down_cont) add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(down_tilemap_pos));
                if(left_cont)  add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(left_tilemap_pos));

                if(up_object != 0) up_cont = 0;
                if(right_object != 0) right_cont = 0;
                if(down_object != 0) down_cont = 0;
                if(left_object != 0) left_cont = 0;
            }
        }
        break;
        case SKILL__JUMP:
        {
            for(int i = 1; i < 10; i++)
            {
                Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i);
                if(room_get_object_at(state->curr_room, up_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(up_tilemap_pos));
                }

                Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i);
                if(room_get_object_at(state->curr_room, right_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(right_tilemap_pos));
                }

                Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i);
                if(room_get_object_at(state->curr_room, down_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(down_tilemap_pos));
                }

                Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i);
                if(room_get_object_at(state->curr_room, left_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(left_tilemap_pos));
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

            for(int i = 0; i < 10; i++)
            {
                Vec2i target_2_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, distance_info.dir4, i+1);
                add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(target_2_pos));
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

            for(int i = 0; i < 10; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, distance_info.dir4, i+1);
                Object* object = room_get_object_at(state->curr_room, tilemap_pos);
                if(object == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
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

            for(int i = 0; i < 10; i++)
            {
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        distance_info.dir4,
                        i+1)));
            }
        }
        break;
        case SKILL__PULL:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                    );

            for(int i = 1; i < distance_info.abs_diff + 1; i++)
            {
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        distance_info.dir4,
                        -i)));
            }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                    );

            for(int i = 1; i < 10; i++)
            {
                add_new_list_element_to_list_end(
                    target_2_pos_list,
                    new_vec2i_from_vec2i(vec2i_move_in_dir4_by(
                        source_tilemap_pos,
                        distance_info.dir4,
                         -i)));
            }
        }
        break;
        case SKILL__THROW:
        {
            for(int i = 1; i < 10; i++)
            {
                Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__UP, i);
                if(room_get_object_at(state->curr_room, up_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(up_tilemap_pos));
                }

                Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__RIGHT, i);
                if(room_get_object_at(state->curr_room, right_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(right_tilemap_pos));
                }

                Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__DOWN, i);
                if(room_get_object_at(state->curr_room, down_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(down_tilemap_pos));
                }

                Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, DIR4__LEFT, i);
                if(room_get_object_at(state->curr_room, left_tilemap_pos) == 0)
                {
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(left_tilemap_pos));
                }
            }
        }
        break;
        case SKILL__TURRET_LASER:
        {
            for(int i = 1; i <= OBJECT_TURRET_RANGE; i++)
            {
                for(int dir4 = 0; dir4 < DIR4__COUNT; dir4++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, dir4, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(tilemap_pos));
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            for(int i = 2; i <= OBJECT_TURRET_RANGE; i++)
            {
                List* square_perimeter_tilemap_pos = new_list((void(*)(void*))destroy_vec2i);

                get_square_perimeter_tilemap_pos(
                    source_tilemap_pos,
                    i,
                    square_perimeter_tilemap_pos
                    );

                for(ListElem* curr_elem = square_perimeter_tilemap_pos->head; curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Vec2i* curr_tilemap_pos = (Vec2i*)curr_elem->data;
                    add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(*curr_tilemap_pos));
                }

                remove_all_list_elements(square_perimeter_tilemap_pos, 1);
            }
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            for(int i = 1; i <= OBJECT_TURRET_RANGE; i++)
            {
                List* square_perimeter_tilemap_pos = new_list((void(*)(void*))destroy_vec2i);

                get_square_perimeter_tilemap_pos(
                    source_tilemap_pos,
                    i,
                    square_perimeter_tilemap_pos
                    );

                for(ListElem* perimeter_elem = square_perimeter_tilemap_pos->head; perimeter_elem != 0; perimeter_elem = perimeter_elem->next)
                {
                    Vec2i perimeter_tilemap_pos = *(Vec2i*)perimeter_elem->data;

                    List* line_tilemap_pos = new_list((void(*)(void*))destroy_vec2i);

                    get_line_from_tilemap_pos_to_tilemap_pos(
                        source_tilemap_pos,
                        perimeter_tilemap_pos,
                        line_tilemap_pos
                        );

                    int is_line_obstructed = 0;
                    for(ListElem* line_elem = line_tilemap_pos->head; line_elem != 0; line_elem = line_elem->next)
                    {
                        Vec2i line_tilemap_pos = *(Vec2i*)line_elem->data;
                        Object* line_object = room_get_object_at(state->curr_room, line_tilemap_pos);

                        if(!vec2i_equals(line_tilemap_pos, source_tilemap_pos) &&
                        !vec2i_equals(line_tilemap_pos, perimeter_tilemap_pos))
                        {
                            if(line_object != 0)
                            {
                                is_line_obstructed = 1;
                            }
                        }
                    }

                    if(!is_line_obstructed)
                    {
                         add_new_list_element_to_list_end(target_2_pos_list, new_vec2i_from_vec2i(perimeter_tilemap_pos));
                    }

                    remove_all_list_elements(line_tilemap_pos, 0);
                    destroy_list(line_tilemap_pos);
                }

                remove_all_list_elements(square_perimeter_tilemap_pos, 1);
                destroy_list(square_perimeter_tilemap_pos);
            }
        }
        break;
        default:
        break;
    }
}
