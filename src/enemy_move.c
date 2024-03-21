#include "../inc/state.h"

void object_enemy_prepare_move(State* state, Enemy* enemy)
{
    Object* enemy_object = enemy->object;
    int enemy_move_skill = SKILL__MOVE;
    if(is_object_floating(enemy_object))
    {
        enemy_move_skill = SKILL__MOVE_FLOATING;
    }
    if(is_object_flying(enemy_object))
    {
        enemy_move_skill = SKILL__MOVE_FLYING;
    }

    switch(enemy_object->type)
    {
        case OBJECT__MOLE:
        {
            List* possible_burrow_tilemap_pos_list =
                new_list((void (*)(void *)) &destroy_vec2i);

            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i,j);
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                        );
                    int floor = room_get_floor_at(
                        state->curr_room,
                        tilemap_pos
                        );

                    if(is_floor_burrow(floor) && object == 0)
                    {
                        add_new_list_element_to_list_end(
                            possible_burrow_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }

            if(possible_burrow_tilemap_pos_list->size > 0)
            {
                int random_index = rand() % possible_burrow_tilemap_pos_list->size;
                ListElem* random_list_elem = get_nth_list_element(
                    possible_burrow_tilemap_pos_list,
                    random_index
                    );
                Vec2i random_tilemap_pos = *(Vec2i*)random_list_elem->data;

                add_action_to_end_action_sequence(
                    enemy->action_sequence,
                    new_action_change_object_tilemap_pos(
                        enemy->object,
                        random_tilemap_pos
                        )
                    );
            }

            remove_all_list_elements(
                possible_burrow_tilemap_pos_list,
                1
                );
            destroy_list(possible_burrow_tilemap_pos_list);
        }
        break;
        case OBJECT__GOAT:
        case OBJECT__BULL:
        case OBJECT__SPIDER:
        case OBJECT__FLY:
        case OBJECT__CHAMELEON:
        case OBJECT__SQUID:
        case OBJECT__MINIBOT_ENEMY:
        case OBJECT__MINIBOT_ENEMY_CELL:
        case OBJECT__MINIBOT_ENEMY_DYNAMITE:
        case OBJECT__MINIBOT_ENEMY_GEMSTONE:
        {
            Vec2i tilemap_pos_up = enemy_object->tilemap_pos;
            Object* object_up = 0;
            int distance_up = 0;

            Vec2i tilemap_pos_right = enemy_object->tilemap_pos;
            Object* object_right = 0;
            int distance_right = 0;

            Vec2i tilemap_pos_down = enemy_object->tilemap_pos;
            Object* object_down = 0;
            int distance_down = 0;

            Vec2i tilemap_pos_left = enemy_object->tilemap_pos;
            Object* object_left = 0;
            int distance_left = 0;

            for(int i = 0; i < 10; i++)
            {
                if(object_up == 0)
                {
                    tilemap_pos_up = vec2i_move_in_dir4_by(tilemap_pos_up, DIR4__UP, 1);
                    object_up = room_get_object_at(state->curr_room, tilemap_pos_up);
                    if(object_up != 0) distance_up = i;
                }

                if(object_right == 0)
                {
                    tilemap_pos_right = vec2i_move_in_dir4_by(tilemap_pos_right, DIR4__RIGHT, 1);
                    object_right = room_get_object_at(state->curr_room, tilemap_pos_right);
                    if(object_right != 0) distance_right = i;
                }

                if(object_down == 0)
                {
                    tilemap_pos_down = vec2i_move_in_dir4_by(tilemap_pos_down, DIR4__DOWN, 1);
                    object_down = room_get_object_at(state->curr_room, tilemap_pos_down);
                    if(object_down != 0) distance_down = i;
                }

                if(object_left == 0)
                {
                    tilemap_pos_left = vec2i_move_in_dir4_by(tilemap_pos_left, DIR4__LEFT, 1);
                    object_left = room_get_object_at(state->curr_room, tilemap_pos_left);
                    if(object_left != 0) distance_left = i;
                }
            }

            int min_distance = distance_up;
            int min_dir4 = DIR4__UP;

            if(distance_right < min_distance)
            {
                min_distance = distance_right;
                min_dir4 = DIR4__RIGHT;
            }
            if(distance_down < min_distance)
            {
                min_distance = distance_down;
                min_dir4 = DIR4__DOWN;
            }
            if(distance_left < min_distance)
            {
                min_distance = distance_left;
                min_dir4 = DIR4__LEFT;
            }

            int dir4 = DIR4__UP;
            int distance = 0;

            if(object_up != 0 || object_right != 0 || object_down != 0 || object_left != 0)
            {
                while(1)
                {
                    int new_dir4 = rand() % 4 + 1;
                    if(new_dir4 == DIR4__UP && object_up != 0)
                    { dir4 = new_dir4; distance = distance_up; break; }
                    if(new_dir4 == DIR4__RIGHT && object_right != 0)
                    { dir4 = new_dir4; distance = distance_right; break; }
                    if(new_dir4 == DIR4__DOWN && object_down != 0)
                    { dir4 = new_dir4; distance = distance_down; break; }
                    if(new_dir4 == DIR4__LEFT && object_left != 0)
                    { dir4 = new_dir4; distance = distance_left; break; }
                }

                distance = fmin(distance, 5);
            }
            else
            {
                dir4 = rand() % 4 + 1;
                distance = rand() % 5 + 1;
            }

            Vec2i curr_tilemap_pos = enemy_object->tilemap_pos;
            Vec2i new_tilemap_pos = enemy_object->tilemap_pos;
            Object* new_tilemap_pos_object = 0;
            for(int i = 0; i < distance; i++)
            {
                new_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, dir4, 1);
                new_tilemap_pos_object = room_get_object_at(state->curr_room, new_tilemap_pos);
                if(new_tilemap_pos_object == 0)
                {
                    add_action_to_end_action_sequence(enemy->action_sequence, new_action_move(curr_tilemap_pos,dir4));
                    curr_tilemap_pos = new_tilemap_pos;
                }
                else break;
            }
            enemy->object->attack_dir4 = dir4;
        }
        break;
        case 69:
        {
            List* path_tilemap_pos_list = new_list((void (*)(void *))&destroy_vec2i);
            find_path(
                state,
                enemy_object->tilemap_pos,
                vec2i(7,7),
                path_tilemap_pos_list,
                is_object_floating(enemy_object),
                is_object_flying(enemy_object)
                );
            if(path_tilemap_pos_list->size > 0)
            {
                for(int i = 0; i < path_tilemap_pos_list->size; i++)
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
                            if(enemy_move_skill == SKILL__MOVE)
                            {
                                add_action_to_end_action_sequence(
                                    enemy->action_sequence,
                                    new_action_move(
                                        *curr_tilemap_pos,
                                        get_distance_info_from_vec2i_to_vec2i(
                                            *curr_tilemap_pos,
                                            *next_tilemap_pos
                                            ).dir4
                                        )
                                    );
                            }
                            else if(enemy_move_skill == SKILL__MOVE_FLOATING)
                            {
                                add_action_to_end_action_sequence(
                                    enemy->action_sequence,
                                    new_action_move_floating(
                                        *curr_tilemap_pos,
                                        get_distance_info_from_vec2i_to_vec2i(
                                            *curr_tilemap_pos,
                                            *next_tilemap_pos
                                            ).dir4
                                        )
                                    );
                            }
                            else if(enemy_move_skill == SKILL__MOVE_FLYING)
                            {
                                add_action_to_end_action_sequence(
                                    enemy->action_sequence,
                                    new_action_move_flying(
                                        *curr_tilemap_pos,
                                        get_distance_info_from_vec2i_to_vec2i(
                                            *curr_tilemap_pos,
                                            *next_tilemap_pos
                                            ).dir4
                                        )
                                    );
                            }
                        }

                        prev_elem = curr_elem;
                        curr_elem = next_elem;
                        next_elem = (curr_elem) ? (curr_elem->next) : (0);

                        prev_tilemap_pos = (prev_elem) ? (prev_elem->data) : (0);
                        curr_tilemap_pos = (curr_elem) ? (curr_elem->data) : (0);
                        next_tilemap_pos = (next_elem) ? (next_elem->data) : (0);
                    }
                }
            }
            remove_all_list_elements(path_tilemap_pos_list, 1);
            destroy_list(path_tilemap_pos_list);
        }
        break;
        default:
        break;
    }
}
