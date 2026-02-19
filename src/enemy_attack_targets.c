#include "../inc/state.h"

void update_enemy_attack_targets(State* state, Enemy* enemy)
{
    Object* enemy_object = enemy->object;

    enemy->skill = SKILL__NONE;
    enemy->target_1_tilemap_pos = vec2i(0, 0);
    enemy->target_2_tilemap_pos = vec2i(0, 0);

    switch(enemy_object->type)
    {
        case OBJECT__GOAT:
        {
            int go_on = TRUE;
            for(int i = 1; i < SKILL_CHARGE_RANGE && go_on; i++)
            {
                Vec2i curr_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy->object->tilemap_pos,
                    enemy->object->attack_dir4,
                    i
                );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    Object* curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );

                    if(curr_object != NULL)
                    {
                        if(is_object_movable(curr_object))
                        {
                            enemy->skill = SKILL__CHARGE_AND_PUNCH;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                enemy->object->attack_dir4,
                                1
                            );
                            go_on = FALSE;
                        }
                        else
                        {
                            enemy->skill = SKILL__CHARGE;
                            enemy->target_1_tilemap_pos = vec2i(0, 0);
                            enemy->target_2_tilemap_pos = curr_tilemap_pos;
                            go_on = FALSE;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0, 0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                        ),
                        1
                    );
                    go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__LION:
        {
            int go_on = TRUE;
            for(int i = 1; i < 10 && go_on; i++)
            {
                Vec2i curr_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy->object->tilemap_pos,
                    enemy->object->attack_dir4,
                    i
                );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    Object* curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );

                    if(curr_object != NULL)
                    {
                        
                        enemy->skill = SKILL__CHARGE_AND_DAMAGE_3;
                        enemy->target_1_tilemap_pos = vec2i(0, 0);
                        enemy->target_2_tilemap_pos = curr_tilemap_pos;
                        go_on = FALSE;
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0, 0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                        ),
                        1
                    );
                    go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__RABBIT:
        {
            int go_on = TRUE;
            for(int i = 1; i < 10 && go_on; i++)
            {
                Vec2i curr_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy->object->tilemap_pos,
                    enemy->object->attack_dir4,
                    i
                );

                List* around_tilemap_pos_list = new_list((void(*)(void*))destroy_vec2i);

                for(int dir8 = 1; dir8 < DIR8__COUNT; dir8++)
                {
                    Vec2i around_tilemap_pos = vec2i_move_in_dir8_by(curr_tilemap_pos, dir8, 1);

                    add_new_list_element_to_list_end(around_tilemap_pos_list, new_vec2i_from_vec2i(around_tilemap_pos));
                }

                int is_ally_around = FALSE;
                for(ListElem* list_elem = around_tilemap_pos_list->head; list_elem != NULL && go_on; list_elem = list_elem->next)
                {
                    Vec2i* around_tilemap_pos = (Vec2i*)list_elem->data;

                    if(is_tilemap_in_bounds(*around_tilemap_pos))
                    {
                        Object* around_object = room_get_object_at(state->curr_room, *around_tilemap_pos);

                        if(around_object != NULL && is_object_ally(around_object))
                        {
                            is_ally_around = TRUE;

                            enemy->skill = SKILL__JUMP_DAMAGE_AROUND;
                            enemy->target_1_tilemap_pos = vec2i(0, 0);
                            enemy->target_2_tilemap_pos = curr_tilemap_pos;
                            go_on = FALSE;
                        }
                    }
                }

                remove_all_list_elements(around_tilemap_pos_list, TRUE);
                destroy_list(around_tilemap_pos_list);
            }
        }
        break;
        case OBJECT__SPIDER:
        case OBJECT__FROG:
        case OBJECT__AARDVARK:
        {
            int go_on = TRUE;
            for(int i = 1; i < SKILL_DRAG_RANGE && go_on; i++)
            {
                Vec2i curr_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy->object->tilemap_pos,
                    enemy->object->attack_dir4,
                    i
                );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    Object* curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );

                    if(curr_object != NULL)
                    {
                        if(is_object_movable(curr_object))
                        {
                            enemy->skill = SKILL__DRAG_DAMAGE;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                enemy->object->tilemap_pos,
                                enemy->object->attack_dir4,
                                1
                            );
                            go_on = FALSE;
                        }
                        // else if(is_object_pull_towards(curr_object))
                        // {
                        //     enemy->skill = SKILL__PULL;
                        //     enemy->target_1_tilemap_pos = curr_tilemap_pos;
                        //     enemy->target_2_tilemap_pos = curr_tilemap_pos;
                        //     go_on = FALSE;
                        // }
                        else
                        {
                            enemy->skill = SKILL__NONE;
                            enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
                            enemy->target_2_tilemap_pos = enemy->object->tilemap_pos;
                            go_on = FALSE;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__NONE;
                    enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
                    enemy->target_2_tilemap_pos = enemy->object->tilemap_pos;
                    go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__BULL:
        {
            int go_on = TRUE;
            for(int i = 1; i < SKILL_CHARGE_RANGE && go_on; i++)
            {
                Vec2i curr_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy->object->tilemap_pos,
                    enemy->object->attack_dir4,
                    i
                );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    Object* curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );

                    if(curr_object != NULL)
                    {
                        if(is_object_movable(curr_object))
                        {
                            Vec2i drop_tilemap_pos_1 = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                enemy->object->attack_dir4,
                                1
                            );
                            Object* drop_object_1 = room_get_object_at(
                                state->curr_room,
                                drop_tilemap_pos_1
                            );
                            Vec2i drop_tilemap_pos_2 = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                enemy->object->attack_dir4,
                                2
                            );
                            Object* drop_object_2 = room_get_object_at(
                                state->curr_room,
                                drop_tilemap_pos_2
                            );

                            if(is_tilemap_in_bounds(drop_tilemap_pos_2) &&
                               drop_object_2 == NULL)
                            {
                                enemy->skill = SKILL__CHARGE_AND_THROW;
                                enemy->target_1_tilemap_pos = curr_tilemap_pos;
                                enemy->target_2_tilemap_pos = drop_tilemap_pos_2;
                                go_on = FALSE;
                            }
                            else if(is_tilemap_in_bounds(drop_tilemap_pos_1) &&
                                    drop_object_1 == NULL)
                            {
                                enemy->skill = SKILL__CHARGE_AND_THROW;
                                enemy->target_1_tilemap_pos = curr_tilemap_pos;
                                enemy->target_2_tilemap_pos = drop_tilemap_pos_1;
                                go_on = FALSE;
                            }
                            else if(i > 1)
                            {
                                enemy->skill = SKILL__CHARGE;
                                enemy->target_1_tilemap_pos = vec2i(0, 0);
                                enemy->target_2_tilemap_pos = curr_tilemap_pos;
                                go_on = FALSE;
                            }
                            else
                            {
                                enemy->skill = SKILL__ATTACK_DIR;
                                enemy->target_1_tilemap_pos = curr_tilemap_pos;
                                enemy->target_2_tilemap_pos = drop_tilemap_pos_1;
                                go_on = FALSE;
                            }
                        }
                        else
                        {
                            enemy->skill = SKILL__CHARGE;
                            enemy->target_1_tilemap_pos = vec2i(0, 0);
                            enemy->target_2_tilemap_pos = curr_tilemap_pos;
                            go_on = FALSE;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0, 0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                        ),
                        1
                    );
                    go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__GORILLA:
        {
            Vec2i dir4_1_tilemap_pos = vec2i_move_in_dir4_by(enemy->object->tilemap_pos, enemy->object->attack_dir4, 1);
            Vec2i dir4_2_tilemap_pos = vec2i_move_in_dir4_by(enemy->object->tilemap_pos, enemy->object->attack_dir4, 2);
            Vec2i dir4_3_tilemap_pos = vec2i_move_in_dir4_by(enemy->object->tilemap_pos, enemy->object->attack_dir4, 3);

            Object* dir4_1_object = room_get_object_at(state->curr_room, dir4_1_tilemap_pos);
            Object* dir4_2_object = room_get_object_at(state->curr_room, dir4_2_tilemap_pos);
            Object* dir4_3_object = room_get_object_at(state->curr_room, dir4_3_tilemap_pos);

            if(dir4_1_object != NULL && is_object_movable(dir4_1_object))
            {
                if(((dir4_2_object != NULL && is_object_throw_over(dir4_2_object)) || dir4_2_object == NULL) && dir4_3_object == NULL)
                {
                    enemy->skill = SKILL__THROW_DAMAGE;
                    enemy->target_1_tilemap_pos = dir4_1_tilemap_pos;
                    enemy->target_2_tilemap_pos = dir4_3_tilemap_pos;
                }
                else
                {
                    enemy->skill = SKILL__PUSH_DAMAGE;
                    enemy->target_1_tilemap_pos = dir4_1_tilemap_pos;
                    enemy->target_2_tilemap_pos = dir4_2_tilemap_pos;
                }
            }
            else
            {
                enemy->skill = SKILL__ATTACK_DIR;
                enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
                enemy->target_2_tilemap_pos = enemy->object->tilemap_pos;
            }
        }
        break;
        case OBJECT__MOLE:
        {
            enemy->skill = SKILL__DAMAGE_3;
            enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(enemy->object->tilemap_pos, enemy->object->attack_dir4, 1);
        }
        break;
        case OBJECT__MINIBOT_ENEMY:
        {
            enemy->skill = SKILL__DAMAGE_1;
            enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(enemy->object->tilemap_pos, enemy->object->attack_dir4, 1);
        }
        break;
        case OBJECT__DRAGON:
        {
            if(enemy->object->attack_dir4 != DIR4__NONE)
            {
                enemy->skill = SKILL__SCORCH_WITH_FIRE;
                enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(enemy->object->tilemap_pos, enemy->object->attack_dir4, 1);
            }
            else
            {
                enemy->skill = SKILL__NONE;
                enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
                enemy->target_2_tilemap_pos = enemy->object->tilemap_pos;
            }
        }
        break;
        case OBJECT__GRASSHOPPER:
        case OBJECT__WORM:
        {
            if(enemy->object->attack_dir4 == DIR4__NONE) break;
            
            int go_on = TRUE;
            for(int i = 1; i < 10 && go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    enemy->object->tilemap_pos,
                    enemy->object->attack_dir4,
                    i
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL)
                    {
                        enemy->skill = SKILL__PROJECTILE_LINE_1;
                        enemy->target_1_tilemap_pos = vec2i(0, 0);
                        enemy->target_2_tilemap_pos = tilemap_pos;
                        go_on = FALSE;
                    }
                }
                else
                {
                    enemy->skill = SKILL__PROJECTILE_LINE_1;
                    enemy->target_1_tilemap_pos = vec2i(0, 0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                        ),
                        1
                    );
                    go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__CENTIPEDE:
        {
            if(enemy->object->attack_dir4 == DIR4__NONE) break;
            
            int go_on = TRUE;
            for(int i = 1; i < 10 && go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    enemy->object->tilemap_pos,
                    enemy->object->attack_dir4,
                    i
                );

                if(is_tilemap_in_bounds(tilemap_pos))
                {
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );

                    if(object != NULL)
                    {
                        if(is_object_ally(object) || !is_object_throw_over(object))
                        {
                            enemy->skill = SKILL__PROJECTILE_ARCH_1;
                            enemy->target_1_tilemap_pos = vec2i(0, 0);
                            enemy->target_2_tilemap_pos = tilemap_pos;
                            go_on = FALSE;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__PROJECTILE_ARCH_1;
                    enemy->target_1_tilemap_pos = vec2i(0, 0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                        ),
                        1
                    );
                    go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__MEGASPIDER:
        {
            if(enemy->object->attack_dir4 == DIR4__NONE) break;

            int how_many_minispiders = 0;
            for(int i = 0; i < TILEMAP_LENGTH; i++)
            {
                for(int j = 0; j < TILEMAP_LENGTH; j++)
                {
                    Vec2i tilemap_pos = vec2i(i, j);
                    Object* object = room_get_object_at(state->curr_room, tilemap_pos);

                    if(object != NULL && object->type == OBJECT__MINIBOT_ENEMY)
                    {
                        how_many_minispiders++;
                    }
                }
            }

            if(how_many_minispiders < 5)
            {
                int go_on = TRUE;
                for(int i = 1; i < 10 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        enemy->object->tilemap_pos,
                        enemy->object->attack_dir4,
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
                            enemy->skill = SKILL__LAUNCH_MINIBOT_MEGASPIDER;
                            enemy->target_1_tilemap_pos = vec2i(0, 0);
                            enemy->target_2_tilemap_pos = tilemap_pos;
                            go_on = FALSE;
                        }
                    }
                }
            }
            else
            {
                enemy->skill = SKILL__DAMAGE_3;
                enemy->target_1_tilemap_pos = vec2i(0, 0);
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(enemy->object->tilemap_pos, enemy->object->attack_dir4, 1);
            }
        }
        break;
        case OBJECT__PORCUPINE:
        {
            enemy->skill = SKILL__PROJECTILE_LINE_AROUND;
            enemy->target_1_tilemap_pos = vec2i(0, 0);
            enemy->target_2_tilemap_pos = vec2i(0, 0);
        }
        break;
        // case OBJECT__FLY:
        // {
        //     if(enemy->object->attack_dir4 == DIR4__NONE) break;
            
        //     int go_on = TRUE;
        //     for(int i = 1; i < 10 && go_on; i++)
        //     {
        //         Vec2i tilemap_pos = vec2i_move_in_dir4_by(
        //             enemy->object->tilemap_pos,
        //             enemy->object->attack_dir4,
        //             i
        //         );

        //         if(is_tilemap_in_bounds(tilemap_pos))
        //         {
        //             Object* object = room_get_object_at(
        //                 state->curr_room,
        //                 tilemap_pos
        //             );

        //             if(object != NULL)
        //             {
        //                 enemy->skill = SKILL__SHOOT_PROJECTILE_FLY;
        //                 enemy->target_1_tilemap_pos = vec2i(0, 0);
        //                 enemy->target_2_tilemap_pos = tilemap_pos;
        //                 go_on = FALSE;
        //             }
        //         }
        //         else
        //         {
        //             enemy->skill = SKILL__SHOOT_PROJECTILE_FLY;
        //             enemy->target_1_tilemap_pos = vec2i(0, 0);
        //             enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //                 tilemap_pos,
        //                 get_opposite_dir4(
        //                     enemy->object->attack_dir4
        //                 ),
        //                 1
        //             );
        //             go_on = FALSE;
        //         }
        //     }
        // }
        // break;
        // case OBJECT__SQUIRREL_EXIT_OBSIDIAN_DOWN:
        // {
        //     int go_on = TRUE;
        //     for(int i = 1; i < 10 && go_on; i++)
        //     {
        //         Vec2i tilemap_pos = vec2i_move_in_dir4_by(
        //             enemy->object->tilemap_pos,
        //             enemy->object->attack_dir4,
        //             i
        //         );

        //         if(is_tilemap_in_bounds(tilemap_pos))
        //         {
        //             Object* object = room_get_object_at(
        //                 state->curr_room,
        //                 tilemap_pos
        //             );

        //             if(object != NULL)
        //             {
        //                 enemy->skill = SKILL__SHOOT_PROJECTILE_SQUIRREL;
        //                 enemy->target_1_tilemap_pos = vec2i(0, 0);
        //                 enemy->target_2_tilemap_pos = tilemap_pos;
        //                 go_on = FALSE;
        //             }
        //         }
        //         else
        //         {
        //             enemy->skill = SKILL__SHOOT_PROJECTILE_SQUIRREL;
        //             enemy->target_1_tilemap_pos = vec2i(0, 0);
        //             enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //                 tilemap_pos,
        //                 get_opposite_dir4(
        //                     enemy->object->attack_dir4
        //                 ),
        //                 1
        //             );
        //             go_on = FALSE;
        //         }
        //     }
        // }
        // break;
        // case OBJECT__CHAMELEON:
        // {
        //     int go_on = TRUE;
        //     for(int i = 1; i < SKILL_CHARGE_RANGE && go_on; i++)
        //     {
        //         Vec2i curr_tilemap_pos = vec2i_move_in_dir4_by(
        //             enemy->object->tilemap_pos,
        //             enemy->object->attack_dir4,
        //             i
        //         );

        //         if(is_tilemap_in_bounds(curr_tilemap_pos))
        //         {
        //             Object* curr_object = room_get_object_at(
        //                 state->curr_room,
        //                 curr_tilemap_pos
        //             );

        //             if(curr_object != NULL)
        //             {
        //                 if(is_object_movable(curr_object))
        //                 {
        //                     enemy->skill = SKILL__DRAG_AND_THROW_TONGUE;
        //                     enemy->target_1_tilemap_pos = curr_tilemap_pos;
        //                     enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //                         enemy_object->tilemap_pos,
        //                         get_opposite_dir4(
        //                             enemy->object->attack_dir4
        //                         ),
        //                         1
        //                     );
        //                     go_on = FALSE;
        //                 }
        //                 else if(is_object_pull_towards(curr_object))
        //                 {
        //                     enemy->skill = SKILL__PULL_TONGUE;
        //                     enemy->target_1_tilemap_pos = curr_tilemap_pos;
        //                     enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //                         curr_tilemap_pos,
        //                         get_opposite_dir4(
        //                             enemy->object->attack_dir4
        //                         ),
        //                         1
        //                     );
        //                     go_on = FALSE;
        //                 }
        //                 else
        //                 {
        //                     enemy->skill = SKILL__ATTACK_DIR;
        //                     enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
        //                     enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //                         enemy->object->tilemap_pos,
        //                         enemy->object->attack_dir4,
        //                         1
        //                     );
        //                     go_on = FALSE;
        //                 }
        //             }
        //         }
        //         else
        //         {
        //             enemy->skill = SKILL__ATTACK_DIR;
        //             enemy->target_1_tilemap_pos = enemy->object->tilemap_pos;
        //             enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //                 enemy->object->tilemap_pos,
        //                 enemy->object->attack_dir4,
        //                 1
        //             );
        //             go_on = FALSE;
        //         }
        //     }
        // }
        // break;
        // case OBJECT__SQUID:
        // {
        //     int min_diff = 10;
        //     int chosen_dir4 = DIR4__NONE;

        //     for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
        //     {
        //         for(int i = 1; i < 10; i++)
        //         {
        //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
        //                 enemy_object->tilemap_pos,
        //                 dir4,
        //                 i
        //             );

        //             Object* object = room_get_object_at(
        //                 state->curr_room,
        //                 tilemap_pos
        //             );

        //             if(object != NULL && is_object_movable(object))
        //             {
        //                 if(i < min_diff)
        //                 {
        //                     min_diff = i;
        //                     chosen_dir4 = dir4;
        //                 }
        //             }
        //         }
        //     }

        //     enemy->object->attack_dir4 = chosen_dir4;

        //     if(chosen_dir4 == DIR4__NONE)
        //     {
        //         enemy->skill = SKILL__NONE;
        //         enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //         enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        //     }
        //     else
        //     {
        //         int go_on = TRUE;
        //         for(int i = 1; i < SKILL_CHARGE_RANGE && go_on; i++)
        //         {
        //             Vec2i curr_tilemap_pos = vec2i_move_in_dir4_by(
        //                 enemy->object->tilemap_pos,
        //                 enemy->object->attack_dir4,
        //                 i
        //             );

        //             if(is_tilemap_in_bounds(curr_tilemap_pos))
        //             {
        //                 Object* curr_object = room_get_object_at(
        //                     state->curr_room,
        //                     curr_tilemap_pos
        //                 );

        //                 if(curr_object != NULL)
        //                 {
        //                     if(is_object_movable(curr_object))
        //                     {
        //                         enemy->skill = SKILL__DRAG_TENTACLE;
        //                         enemy->target_1_tilemap_pos = curr_tilemap_pos;
        //                         enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        //                         go_on = FALSE;
        //                     }
        //                     else
        //                     {
        //                         go_on = FALSE;
        //                     }
        //                 }
        //             }
        //             else
        //             {
        //                 enemy->skill = SKILL__ATTACK_DIR;
        //                 enemy->target_1_tilemap_pos = vec2i(0, 0);
        //                 enemy->target_2_tilemap_pos = curr_tilemap_pos;
        //                 go_on = FALSE;
        //             }
        //         }
        //     }
        // }
        // break;
        // case OBJECT__MIMIC:
        // {
        //     enemy->skill = SKILL__KILL_AROUND;
        //     enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //     enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        // }
        // break;
        // case OBJECT__SHARK:
        // {
        //     enemy->skill = SKILL__KILL_AROUND;
        //     enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //     enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        // }
        // break;
        // case OBJECT__SHARK_FIN:
        // {
        //     enemy->skill = SKILL__NO_ATTACK;
        //     enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //     enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        // }
        // break;
        // case OBJECT__MINIBOT_ENEMY:
        // case OBJECT__MINIBOT_ENEMY_CELL:
        // case OBJECT__MINIBOT_ENEMY_DYNAMITE:
        // case OBJECT__MINIBOT_ENEMY_GEMSTONE:
        // {
        //     enemy->skill = SKILL__NO_ATTACK;
        //     enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //     enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        // }
        // break;
        // case OBJECT__TURRET_LASER_GROUNDED:
        // case OBJECT__TURRET_LASER_STANDING:
        // case OBJECT__TURRET_LASER_DEPLOYED:
        // case OBJECT__MOLE:
        // {
        //     int min_diff = 10;
        //     int chosen_dir4 = DIR4__NONE;

        //     for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
        //     {
        //         int go_on = TRUE;

        //         for(int i = 1; i < OBJECT_TURRET_RANGE + 1 && go_on; i++)
        //         {
        //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
        //                 enemy_object->tilemap_pos,
        //                 dir4,
        //                 i
        //             );

        //             Object* object = room_get_object_at(
        //                 state->curr_room,
        //                 tilemap_pos
        //             );

        //             if(object != NULL)
        //             {
        //                 if(is_object_meltable(object))
        //                 {
        //                     if(i < min_diff)
        //                     {
        //                         min_diff = i;
        //                         chosen_dir4 = dir4;
        //                     }
        //                 }
        //                 else
        //                 {
        //                     go_on = FALSE;
        //                 }
        //             }
        //         }
        //     }

        //     enemy->object->attack_dir4 = chosen_dir4;

        //     if(chosen_dir4 == DIR4__NONE)
        //     {
        //         enemy->skill = SKILL__NONE;
        //         enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //         enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        //     }
        //     else
        //     {
        //         enemy->skill = SKILL__TURRET_LASER;
        //         enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //         enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //             enemy_object->tilemap_pos,
        //             chosen_dir4,
        //             min_diff
        //         );
        //     }
        // }
        // break;
        // case OBJECT__TURRET_BOMB_GROUNDED:
        // case OBJECT__TURRET_BOMB_STANDING:
        // case OBJECT__TURRET_BOMB_DEPLOYED:
        // {
        //     int min_diff = 10;
        //     int chosen_dir4 = DIR4__NONE;

        //     for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
        //     {
        //         int go_on = TRUE;
        //         for(int i = 1; i < 10 && go_on; i++)
        //         {
        //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
        //                 enemy_object->tilemap_pos,
        //                 dir4,
        //                 i
        //             );

        //             Object* object = room_get_object_at(
        //                 state->curr_room,
        //                 tilemap_pos
        //             );

        //             if(object != NULL && is_object_breakable(object))
        //             {
        //                 if(i < min_diff)
        //                 {
        //                     min_diff = i;
        //                     chosen_dir4 = dir4;
        //                 }
        //             }

        //             if(object != NULL && !is_object_throw_over(object))
        //             {
        //                 go_on = FALSE;
        //             }
        //         }
        //     }

        //     enemy->object->attack_dir4 = chosen_dir4;

        //     if(chosen_dir4 == DIR4__NONE)
        //     {
        //         enemy->skill = SKILL__NONE;
        //         enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //         enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        //     }
        //     else
        //     {
        //         enemy->skill = SKILL__TURRET_BOMB;
        //         enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //         enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //             enemy_object->tilemap_pos,
        //             chosen_dir4,
        //             min_diff
        //         );
        //     }
        // }
        // break;
        // case OBJECT__TURRET_PROJECTILE_GROUNDED:
        // case OBJECT__TURRET_PROJECTILE_STANDING:
        // case OBJECT__TURRET_PROJECTILE_DEPLOYED:
        // {
        //     int min_diff = 10;
        //     int chosen_dir4 = DIR4__NONE;

        //     for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
        //     {
        //         int go_on = TRUE;
        //         for(int i = 1; i < 10 && go_on; i++)
        //         {
        //             Vec2i tilemap_pos = vec2i_move_in_dir4_by(
        //                 enemy_object->tilemap_pos,
        //                 dir4,
        //                 i
        //             );

        //             Object* object = room_get_object_at(
        //                 state->curr_room,
        //                 tilemap_pos
        //             );

        //             if(object != NULL && !is_object_wall(object))
        //             {
        //                 if(i < min_diff)
        //                 {
        //                     min_diff = i;
        //                     chosen_dir4 = dir4;
        //                 }
        //             }

        //             if(object != NULL)
        //             {
        //                 go_on = FALSE;
        //             }
        //         }
        //     }

        //     enemy->object->attack_dir4 = chosen_dir4;

        //     if(chosen_dir4 == DIR4__NONE)
        //     {
        //         enemy->skill = SKILL__NONE;
        //         enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //         enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
        //     }
        //     else
        //     {
        //         enemy->skill = SKILL__TURRET_PROJECTILE;
        //         enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
        //         enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
        //             enemy_object->tilemap_pos,
        //             chosen_dir4,
        //             min_diff
        //         );
        //     }
        // }
        // break;
        // case OBJECT__ENVIRONMENT_FALLING_STALACTITE:
        // {
        //     if(enemy->object->attack_dir4 != -1)
        //     {
        //         Vec2i tilemap_pos = vec2i(
        //             enemy->object->attack_dir4 / 10,
        //             enemy->object->attack_dir4 % 10
        //         );

        //         enemy->skill = SKILL__ENVIRONMENT_FALLING_STALACTITE;
        //         enemy->target_1_tilemap_pos = tilemap_pos;
        //         enemy->target_2_tilemap_pos = tilemap_pos;
        //     }
        // }
        // break;
        // case OBJECT__ENVIRONMENT_EMERGE_WATER:
        // {
        //     if(enemy->object->attack_dir4 != -1)
        //     {
        //         Vec2i tilemap_pos = vec2i(
        //             enemy->object->attack_dir4 / 10,
        //             enemy->object->attack_dir4 % 10
        //         );

        //         enemy->skill = SKILL__ENVIRONMENT_EMERGE_WATER;
        //         enemy->target_1_tilemap_pos = tilemap_pos;
        //         enemy->target_2_tilemap_pos = tilemap_pos;
        //     }
        // }
        // break;
        // case OBJECT__ENVIRONMENT_EMERGE_PIT:
        // {
        //     if(enemy->object->attack_dir4 != -1)
        //     {
        //         Vec2i tilemap_pos = vec2i(
        //             enemy->object->attack_dir4 / 10,
        //             enemy->object->attack_dir4 % 10
        //         );

        //         enemy->skill = SKILL__ENVIRONMENT_EMERGE_PIT;
        //         enemy->target_1_tilemap_pos = tilemap_pos;
        //         enemy->target_2_tilemap_pos = tilemap_pos;
        //     }
        // }
        // break;
        // case OBJECT__ENVIRONMENT_EMERGE_BURROW:
        // {
        //     if(enemy->object->attack_dir4 != -1)
        //     {
        //         Vec2i tilemap_pos = vec2i(
        //             enemy->object->attack_dir4 / 10,
        //             enemy->object->attack_dir4 % 10
        //         );

        //         enemy->skill = SKILL__ENVIRONMENT_EMERGE_BURROW;
        //         enemy->target_1_tilemap_pos = tilemap_pos;
        //         enemy->target_2_tilemap_pos = tilemap_pos;
        //     }
        // }
        // break;
        // case OBJECT__ENVIRONMENT_EMERGE_PIPE:
        // {
        //     if(enemy->object->attack_dir4 != -1)
        //     {
        //         Vec2i tilemap_pos = vec2i(
        //             enemy->object->attack_dir4 / 10,
        //             enemy->object->attack_dir4 % 10
        //         );

        //         enemy->skill = SKILL__ENVIRONMENT_EMERGE_PIPE;
        //         enemy->target_1_tilemap_pos = tilemap_pos;
        //         enemy->target_2_tilemap_pos = tilemap_pos;
        //     }
        // }
        // break;
        // case OBJECT__ENVIRONMENT_COLLAPSE_BURROW:
        // {
        //     if(enemy->object->attack_dir4 != -1)
        //     {
        //         Vec2i tilemap_pos = vec2i(
        //             enemy->object->attack_dir4 / 10,
        //             enemy->object->attack_dir4 % 10
        //         );

        //         enemy->skill = SKILL__ENVIRONMENT_COLLAPSE_BURROW;
        //         enemy->target_1_tilemap_pos = tilemap_pos;
        //         enemy->target_2_tilemap_pos = tilemap_pos;
        //     }
        // }
        // break;
        // case OBJECT__ENVIRONMENT_CONV_BELT:
        // {
        //     if(enemy->object->attack_dir4 != -1)
        //     {
        //         Vec2i tilemap_pos = vec2i(
        //             enemy->object->attack_dir4 / 10,
        //             enemy->object->attack_dir4 % 10
        //         );

        //         enemy->skill = SKILL__ENVIRONMENT_CONV_BELT;
        //         enemy->target_1_tilemap_pos = tilemap_pos;
        //         enemy->target_2_tilemap_pos = tilemap_pos;
        //     }
        // }
        // break;
        default:
        break;
    }
}
