#include "../inc/state.h"

void update_enemy_attack_dir4(State* state, Enemy* enemy)
{
    Object* enemy_object = enemy->object;

    enemy->skill = SKILL__NONE;
    enemy->target_1_tilemap_pos = vec2i(0,0);
    enemy->target_2_tilemap_pos = vec2i(0,0);

    switch(enemy_object->type)
    {
        case OBJECT__GOAT:
        case OBJECT__SPIDER:
        case OBJECT__BULL:
        case OBJECT__FLY:
        case OBJECT__CHAMELEON:
        case OBJECT__SQUID:
        {
            enemy->object->attack_dir4 = rand() % 4 + 1;
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

                    if(object == 0)
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

                    if(floor == FLOOR__WATER && object == 0)
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
