#include "../inc/state.h"

void update_enemy_attack_dir4(State* state, Enemy* enemy)
{
    enemy->skill = SKILL__NONE;
    enemy->target_1_tilemap_pos = vec2i(0, 0);
    enemy->target_2_tilemap_pos = vec2i(0, 0);

    switch(enemy->object->type)
    {
        case OBJECT__GOAT:
        case OBJECT__BULL:
        {
            int chosen_dir4 = DIR4__DOWN;
            int max_score = 0;

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int score = 0;
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        enemy->object->tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );
                        int floor = room_get_floor_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(!is_floor_traversable_for_object(floor, enemy->object))
                        {
                            go_on = FALSE;
                        }

                        if(object != NULL)
                        {
                            go_on = FALSE;

                            score = (TILEMAP_LENGTH - i) / 2;

                            if(!is_object_wall(object)) score += 2;

                            if(is_object_movable(object)) score += 2;

                            if(is_object_ally(object)) score += 2;
                        }
                    }
                }

                // printf("dir4: %i, score: %i \n",
                //        dir4,
                //        score
                // );

                if(score > max_score)
                {
                    max_score = score;
                    chosen_dir4 = dir4;
                }
            }

            // printf("\ndir4: %i, score: %i \n",
            //        chosen_dir4,
            //        max_score
            // );

            enemy->object->attack_dir4 = chosen_dir4;
        }
        break;
        case OBJECT__SPIDER:
        case OBJECT__CHAMELEON:
        case OBJECT__FLY:
        {
            int chosen_dir4 = DIR4__DOWN;
            int max_score = 0;

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int score = 0;
                int go_on = TRUE;
                for(int i = 1; i < TILEMAP_LENGTH && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        enemy->object->tilemap_pos,
                        dir4,
                        i
                    );

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* object = room_get_object_at(
                            state->curr_room,
                            tilemap_pos
                        );
                        int floor = room_get_floor_at(
                            state->curr_room,
                            tilemap_pos
                        );

                        if(object != NULL)
                        {
                            go_on = FALSE;

                            score = i / 2;

                            if(!is_object_wall(object)) score += 2;

                            if(is_object_movable(object)) score += 10;

                            if(is_object_pull_towards(object)) score += 10;

                            if(is_object_ally(object)) score += 2;
                        }
                    }
                }

                // printf("dir4: %i, score: %i \n",
                //        dir4,
                //        score
                // );

                if(score > max_score)
                {
                    max_score = score;
                    chosen_dir4 = dir4;
                }
            }

            // printf("\ndir4: %i, score: %i \n",
            //        chosen_dir4,
            //        max_score
            // );

            enemy->object->attack_dir4 = chosen_dir4;
        }
        break;
        case OBJECT__SQUIRREL_EXIT_OBSIDIAN_DOWN:
        {
            enemy->object->attack_dir4 = DIR4__DOWN;
        }
        break;
        case OBJECT__ENVIRONMENT_FALLING_STALACTITE:
        {
            List* possible_emerge_tilemap_pos_list =
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

                    if(object == NULL)
                    {
                        add_new_list_element_to_list_end(
                            possible_emerge_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }

            if(possible_emerge_tilemap_pos_list->size > 0)
            {
                int random_index = rand() % possible_emerge_tilemap_pos_list->size;
                ListElem* random_list_elem = get_nth_list_element(
                    possible_emerge_tilemap_pos_list,
                    random_index
                );
                Vec2i random_tilemap_pos = *(Vec2i*) random_list_elem->data;

                enemy->object->attack_dir4 = 10 * random_tilemap_pos.x + random_tilemap_pos.y;
            }
            else
            {
                enemy->object->attack_dir4 = -1;
            }

            remove_all_list_elements(
                possible_emerge_tilemap_pos_list,
                1
            );
            destroy_list(possible_emerge_tilemap_pos_list);
        }
        break;
        case OBJECT__ENVIRONMENT_EMERGE_WATER:
        {
            List* possible_emerge_tilemap_pos_list =
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

                    if(floor == FLOOR__WATER && object == NULL)
                    {
                        add_new_list_element_to_list_end(
                            possible_emerge_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }

            if(possible_emerge_tilemap_pos_list->size > 0)
            {
                int random_index = rand() % possible_emerge_tilemap_pos_list->size;
                ListElem* random_list_elem = get_nth_list_element(
                    possible_emerge_tilemap_pos_list,
                    random_index
                );
                Vec2i random_tilemap_pos = *(Vec2i*) random_list_elem->data;

                enemy->object->attack_dir4 = 10 * random_tilemap_pos.x + random_tilemap_pos.y;
            }
            else
            {
                enemy->object->attack_dir4 = -1;
            }

            remove_all_list_elements(
                possible_emerge_tilemap_pos_list,
                1
            );
            destroy_list(possible_emerge_tilemap_pos_list);
        }
        break;
        case OBJECT__ENVIRONMENT_EMERGE_PIT:
        {
            List* possible_emerge_tilemap_pos_list =
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

                    if(floor == FLOOR__PIT && object == NULL)
                    {
                        add_new_list_element_to_list_end(
                            possible_emerge_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }

            if(possible_emerge_tilemap_pos_list->size > 0)
            {
                int random_index = rand() % possible_emerge_tilemap_pos_list->size;
                ListElem* random_list_elem = get_nth_list_element(
                    possible_emerge_tilemap_pos_list,
                    random_index
                );
                Vec2i random_tilemap_pos = *(Vec2i*) random_list_elem->data;

                enemy->object->attack_dir4 = 10 * random_tilemap_pos.x + random_tilemap_pos.y;
            }
            else
            {
                enemy->object->attack_dir4 = -1;
            }

            remove_all_list_elements(
                possible_emerge_tilemap_pos_list,
                1
            );
            destroy_list(possible_emerge_tilemap_pos_list);
        }
        break;
        case OBJECT__ENVIRONMENT_EMERGE_BURROW:
        {
            List* possible_emerge_tilemap_pos_list =
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

                    if(is_floor_burrow(floor) && object == NULL)
                    {
                        add_new_list_element_to_list_end(
                            possible_emerge_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }

            if(possible_emerge_tilemap_pos_list->size > 0)
            {
                int random_index = rand() % possible_emerge_tilemap_pos_list->size;
                ListElem* random_list_elem = get_nth_list_element(
                    possible_emerge_tilemap_pos_list,
                    random_index
                );
                Vec2i random_tilemap_pos = *(Vec2i*) random_list_elem->data;

                enemy->object->attack_dir4 = 10 * random_tilemap_pos.x + random_tilemap_pos.y;
            }
            else
            {
                enemy->object->attack_dir4 = -1;
            }

            remove_all_list_elements(
                possible_emerge_tilemap_pos_list,
                1
            );
            destroy_list(possible_emerge_tilemap_pos_list);
        }
        break;
        case OBJECT__ENVIRONMENT_EMERGE_PIPE:
        {
            List* possible_emerge_tilemap_pos_list =
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

                    if(object != NULL && object->type == OBJECT__PIPE)
                    {
                        add_new_list_element_to_list_end(
                            possible_emerge_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }

            if(possible_emerge_tilemap_pos_list->size > 0)
            {
                int random_index = rand() % possible_emerge_tilemap_pos_list->size;
                ListElem* random_list_elem = get_nth_list_element(
                    possible_emerge_tilemap_pos_list,
                    random_index
                );
                Vec2i random_tilemap_pos = *(Vec2i*) random_list_elem->data;

                enemy->object->attack_dir4 = 10 * random_tilemap_pos.x + random_tilemap_pos.y;
            }
            else
            {
                enemy->object->attack_dir4 = -1;
            }

            remove_all_list_elements(
                possible_emerge_tilemap_pos_list,
                1
            );
            destroy_list(possible_emerge_tilemap_pos_list);
        }
        break;
        case OBJECT__ENVIRONMENT_COLLAPSE_BURROW:
        {
            List* possible_emerge_tilemap_pos_list =
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

                    if(is_floor_burrow(floor))
                    {
                        add_new_list_element_to_list_end(
                            possible_emerge_tilemap_pos_list,
                            new_vec2i_from_vec2i(tilemap_pos)
                        );
                    }
                }
            }

            if(possible_emerge_tilemap_pos_list->size > 0)
            {
                int random_index = rand() % possible_emerge_tilemap_pos_list->size;
                ListElem* random_list_elem = get_nth_list_element(
                    possible_emerge_tilemap_pos_list,
                    random_index
                );
                Vec2i random_tilemap_pos = *(Vec2i*) random_list_elem->data;

                enemy->object->attack_dir4 = 10 * random_tilemap_pos.x + random_tilemap_pos.y;
            }
            else
            {
                enemy->object->attack_dir4 = -1;
            }

            remove_all_list_elements(
                possible_emerge_tilemap_pos_list,
                1
            );
            destroy_list(possible_emerge_tilemap_pos_list);
        }
        break;
        default:
        break;
    }
}
