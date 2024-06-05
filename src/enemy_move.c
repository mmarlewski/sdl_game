#include "../inc/state.h"
#include <math.h>

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
                new_list((void (*)(void*)) & destroy_vec2i);

            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);
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
                Vec2i random_tilemap_pos = *(Vec2i*) random_list_elem->data;

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
        case OBJECT__SHARK:
        {
            add_action_to_end_action_sequence(
                enemy->action_sequence,
                new_action_change_object(
                    OBJECT__SHARK_FIN,
                    enemy->object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__SHARK_FIN:
        {
            add_action_to_end_action_sequence(
                enemy->action_sequence,
                new_action_change_object(
                    OBJECT__SHARK,
                    enemy->object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__GOAT:
        case OBJECT__BULL:
        case OBJECT__SPIDER:
        case OBJECT__FLY:
        case OBJECT__CHAMELEON:
        case OBJECT__SQUID:
        case OBJECT__MIMIC:
        case OBJECT__MINIBOT_ENEMY:
        case OBJECT__MINIBOT_ENEMY_CELL:
        case OBJECT__MINIBOT_ENEMY_DYNAMITE:
        case OBJECT__MINIBOT_ENEMY_GEMSTONE:
        {
            Vec2i tilemap_pos_array[TILEMAP_LENGTH * TILEMAP_LENGTH];
            int score_array[TILEMAP_LENGTH * TILEMAP_LENGTH];

            // gather

            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );
                    int floor = room_get_floor_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    int score = 0;

                    if((object == 0 || object == enemy->object) &&
                       is_floor_traversable_for_object(floor, enemy->object) &&
                       (enemy->object->type != OBJECT__SQUID || floor == FLOOR__WATER))
                    {
                        List* path_pos_list = new_list((void (*)(void*)) & destroy_vec2i);

                        find_path(
                            state,
                            enemy->object->tilemap_pos,
                            tilemap_pos,
                            path_pos_list,
                            is_object_floating(enemy->object),
                            is_object_flying(enemy->object)
                        );

                        int distance = path_pos_list->size;

                        if(distance >= 1 && distance <= 10 ||
                           object == enemy->object)
                        {
                            score = distance / 2;

                            if(object != enemy->object) score += 10;

                            if(floor == FLOOR__METAL_TARGET_UNCHECKED) score += 10;

                            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
                            {
                                int go_on = 1;
                                for(int k = 1; k <= 5 && go_on; k++)
                                {
                                    int mul = 1;

                                    if(enemy->object->type == OBJECT__GOAT ||
                                       enemy->object->type == OBJECT__BULL)
                                    {
                                        mul = (5 - k);
                                    }
                                    else if(enemy->object->type == OBJECT__SPIDER ||
                                            enemy->object->type == OBJECT__CHAMELEON ||
                                            enemy->object->type == OBJECT__FLY)
                                    {
                                        mul = k;
                                    }
                                    else if(enemy->object->type == OBJECT__MIMIC)
                                    {
                                        if(k == 1) mul = 10;
                                    }

                                    Vec2i neighbor_tilemap_pos = vec2i_move_in_dir4_by(
                                        tilemap_pos,
                                        dir4,
                                        k
                                    );
                                    Object* neighbor_object = room_get_object_at(
                                        state->curr_room,
                                        neighbor_tilemap_pos
                                    );

                                    if(neighbor_object != 0)
                                    {
                                        go_on = 0;

                                        if(floor == FLOOR__METAL_TARGET_UNCHECKED) score += 2 * mul;

                                        if(!is_object_wall(neighbor_object)) score += 1 * mul;

                                        if(is_object_movable(neighbor_object)) score += 1 * mul;

                                        if(is_object_ally(neighbor_object)) score += 1 * mul;
                                    }
                                }
                            }
                        }

                        remove_all_list_elements(path_pos_list, 1);
                        destroy_list(path_pos_list);
                    }

                    tilemap_pos_array[i * TILEMAP_LENGTH + j] = tilemap_pos;
                    score_array[i * TILEMAP_LENGTH + j] = score;

                    printf("x: %i, y: %i, score: %i \n",
                           tilemap_pos.x,
                           tilemap_pos.y,
                           score
                    );
                }
            }

            // sort

            for(int i = 0; i < TILEMAP_LENGTH * TILEMAP_LENGTH - 1; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH * TILEMAP_LENGTH - i - 1; j++)
                {
                    if(score_array[j] < score_array[j + 1])
                    {
                        int score_temp = score_array[j];
                        score_array[j] = score_array[j + 1];
                        score_array[j + 1] = score_temp;

                        Vec2i tilemap_pos_temp = tilemap_pos_array[j];
                        tilemap_pos_array[j] = tilemap_pos_array[j + 1];
                        tilemap_pos_array[j + 1] = tilemap_pos_temp;
                    }
                }
            }

            // choose

            int top = 3;
            int go_on = 1;
            for(int i = 0; i < top && go_on; i++)
            {
                if(score_array[i] == 0)
                {
                    go_on = 0;
                    top = i;
                }
            }

            if(top > 0)
            {
                int random_index = (int) state->time % top;
                int random_score = score_array[random_index];
                Vec2i random_tilemap_pos = tilemap_pos_array[random_index];

                printf("\n");
                printf("x: %i, y: %i, score: %i \n",
                       random_tilemap_pos.x,
                       random_tilemap_pos.y,
                       random_score
                );

                if(enemy->object->type == OBJECT__SQUID)
                {
                    add_action_to_end_action_sequence(
                        enemy->action_sequence,
                        new_action_change_object_tilemap_pos(
                            enemy->object,
                            random_tilemap_pos
                        )
                    );
                }
                else
                {
                    List* path_pos_list = new_list((void (*)(void*)) & destroy_vec2i);

                    find_path(
                        state,
                        enemy->object->tilemap_pos,
                        random_tilemap_pos,
                        path_pos_list,
                        is_object_floating(enemy->object),
                        is_object_flying(enemy->object)
                    );

                    if(path_pos_list->size > 0)
                    {
                        for(int i = 0; i < path_pos_list->size; i++)
                        {
                            ListElem* prev_elem = 0;
                            ListElem* curr_elem = path_pos_list->head;
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

                    remove_all_list_elements(path_pos_list, 1);
                    destroy_list(path_pos_list);
                }
            }
        }
        break;
        default:
        break;
    }
}
