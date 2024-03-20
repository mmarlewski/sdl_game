#include "../inc/state.h"

void update_enemy_attack_targets(State* state, Enemy* enemy)
{
    Object* enemy_object = enemy->object;

    enemy->skill = SKILL__NONE;
    enemy->target_1_tilemap_pos = vec2i(0,0);
    enemy->target_2_tilemap_pos = vec2i(0,0);

    switch(enemy_object->type)
    {
        case OBJECT__GOAT:
        {
            Vec2i curr_tilemap_pos = enemy_object->tilemap_pos;
            Object* curr_object = 0;

            int go_on = 1;
            for(int i = 0; i < SKILL_CHARGE_RANGE && go_on; i++)
            {
                curr_tilemap_pos = vec2i_move_in_dir4_by(
                    curr_tilemap_pos,
                    enemy->object->attack_dir4,
                    1
                    );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                        );

                    if(curr_object != 0)
                    {
                        if(is_object_movable(curr_object))
                        {
                            enemy->skill = SKILL__CHARGE_AND_PUSH;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                enemy->object->attack_dir4,
                                1
                                );
                            go_on = 0;
                        }
                        else
                        {
                            enemy->skill = SKILL__CHARGE;
                            enemy->target_1_tilemap_pos = vec2i(0,0);
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0,0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                            ),
                        1
                        );
                    go_on = 0;
                }
            }
        }
        break;
        case OBJECT__SPIDER:
        {
            Vec2i curr_tilemap_pos = enemy_object->tilemap_pos;
            Object* curr_object = 0;

            int go_on = 1;
            for(int i = 0; i < SKILL_CHARGE_RANGE && go_on; i++)
            {
                curr_tilemap_pos = vec2i_move_in_dir4_by(
                    curr_tilemap_pos,
                    enemy->object->attack_dir4,
                    1
                    );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                        );

                    if(curr_object != 0)
                    {
                        if(is_object_movable(curr_object))
                        {
                            enemy->skill = SKILL__DRAG_SPIDERWEB;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
                            go_on = 0;
                        }
                        else if(is_object_pull_towards(curr_object))
                        {
                            enemy->skill = SKILL__PULL_SPIDERWEB;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = curr_tilemap_pos;
                            go_on = 0;
                        }
                        else
                        {
                            enemy->skill = SKILL__CHARGE;
                            enemy->target_1_tilemap_pos = vec2i(0,0);
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0,0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                            ),
                        1
                        );
                    go_on = 0;
                }
            }
        }
        break;
        case OBJECT__BULL:
        {
            Vec2i curr_tilemap_pos = enemy_object->tilemap_pos;
            Object* curr_object = 0;

            int go_on = 1;
            for(int i = 0; i < SKILL_CHARGE_RANGE && go_on; i++)
            {
                curr_tilemap_pos = vec2i_move_in_dir4_by(
                    curr_tilemap_pos,
                    enemy->object->attack_dir4,
                    1
                    );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                        );

                    if(curr_object != 0)
                    {
                        if(is_object_movable(curr_object))
                        {
                            enemy->skill = SKILL__CHARGE_AND_THROW;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                enemy->object->attack_dir4,
                                1
                                );
                            go_on = 0;
                        }
                        else
                        {
                            enemy->skill = SKILL__CHARGE;
                            enemy->target_1_tilemap_pos = vec2i(0,0);
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0,0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                            ),
                        1
                        );
                    go_on = 0;
                }
            }
        }
        break;
        case OBJECT__FLY:
        {
            int go_on = 1;
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

                    if(object != 0)
                    {
                        enemy->skill = SKILL__SHOOT_PROJECTILE_FLY;
                        enemy->target_1_tilemap_pos = vec2i(0,0);
                        enemy->target_2_tilemap_pos = tilemap_pos;
                        go_on = 0;
                    }
                }
                else
                {
                    enemy->skill = SKILL__SHOOT_PROJECTILE_FLY;
                    enemy->target_1_tilemap_pos = vec2i(0,0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                            ),
                        1
                        );
                    go_on = 0;
                }
            }
        }
        break;
        case OBJECT__SQUIRREL_EXIT_OBSIDIAN_DOWN:
        {
            int go_on = 1;
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

                    if(object != 0)
                    {
                        enemy->skill = SKILL__SHOOT_PROJECTILE_SQUIRREL;
                        enemy->target_1_tilemap_pos = vec2i(0,0);
                        enemy->target_2_tilemap_pos = tilemap_pos;
                        go_on = 0;
                    }
                }
                else
                {
                    enemy->skill = SKILL__SHOOT_PROJECTILE_SQUIRREL;
                    enemy->target_1_tilemap_pos = vec2i(0,0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                            ),
                        1
                        );
                    go_on = 0;
                }
            }
        }
        break;
        case OBJECT__CHAMELEON:
        {
            Vec2i curr_tilemap_pos = enemy_object->tilemap_pos;
            Object* curr_object = 0;

            int go_on = 1;
            for(int i = 0; i < SKILL_CHARGE_RANGE && go_on; i++)
            {
                curr_tilemap_pos = vec2i_move_in_dir4_by(
                    curr_tilemap_pos,
                    enemy->object->attack_dir4,
                    1
                    );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                        );

                    if(curr_object != 0)
                    {
                        if(is_object_movable(curr_object))
                        {
                            enemy->skill = SKILL__DRAG_AND_THROW_TONGUE;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                enemy_object->tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                        else if(is_object_pull_towards(curr_object))
                        {
                            enemy->skill = SKILL__PULL_TONGUE;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                        else
                        {
                            enemy->skill = SKILL__CHARGE;
                            enemy->target_1_tilemap_pos = vec2i(0,0);
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0,0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                            ),
                        1
                        );
                    go_on = 0;
                }
            }
        }
        break;
        case OBJECT__SQUID:
        {
            Vec2i curr_tilemap_pos = enemy_object->tilemap_pos;
            Object* curr_object = 0;

            int go_on = 1;
            for(int i = 0; i < SKILL_CHARGE_RANGE && go_on; i++)
            {
                curr_tilemap_pos = vec2i_move_in_dir4_by(
                    curr_tilemap_pos,
                    enemy->object->attack_dir4,
                    1
                    );

                if(is_tilemap_in_bounds(curr_tilemap_pos))
                {
                    curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                        );

                    if(curr_object != 0)
                    {
                        if(is_object_movable(curr_object))
                        {
                            enemy->skill = SKILL__DRAG_TENTACLE;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                enemy_object->tilemap_pos,
                                enemy->object->attack_dir4,
                                1
                                );
                            go_on = 0;
                        }
                        else if(is_object_pull_towards(curr_object))
                        {
                            enemy->skill = SKILL__PULL_TENTACLE;
                            enemy->target_1_tilemap_pos = curr_tilemap_pos;
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                        else
                        {
                            enemy->skill = SKILL__CHARGE;
                            enemy->target_1_tilemap_pos = vec2i(0,0);
                            enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                                curr_tilemap_pos,
                                get_opposite_dir4(
                                    enemy->object->attack_dir4
                                    ),
                                1
                                );
                            go_on = 0;
                        }
                    }
                }
                else
                {
                    enemy->skill = SKILL__CHARGE;
                    enemy->target_1_tilemap_pos = vec2i(0,0);
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        get_opposite_dir4(
                            enemy->object->attack_dir4
                            ),
                        1
                        );
                    go_on = 0;
                }
            }
        }
        break;
        case OBJECT__TURRET_LASER_GROUNDED:
        case OBJECT__TURRET_LASER_STANDING:
        case OBJECT__TURRET_LASER_DEPLOYED:
        {
            int min_diff = 10;
            int chosen_dir4 = DIR4__NONE;

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                for(int i = 1; i < 10; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        enemy_object->tilemap_pos,
                        dir4,
                        i
                        );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                        );

                    if(object != 0 && is_object_meltable(object))
                    {
                        if(i < min_diff)
                        {
                            min_diff = i;
                            chosen_dir4 = dir4;
                        }
                    }
                }
            }

            enemy->object->attack_dir4 = chosen_dir4;

            if(chosen_dir4 == DIR4__NONE)
            {
                enemy->skill = SKILL__NONE;
                enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
                enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
            }
            else
            {
                enemy->skill = SKILL__TURRET_LASER;
                enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy_object->tilemap_pos,
                    chosen_dir4,
                    min_diff
                    );
            }
        }
        break;
        case OBJECT__TURRET_BOMB_GROUNDED:
        case OBJECT__TURRET_BOMB_STANDING:
        case OBJECT__TURRET_BOMB_DEPLOYED:
        {
            int min_diff = 10;
            int chosen_dir4 = DIR4__NONE;

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = 1;
                for(int i = 1; i < 10 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        enemy_object->tilemap_pos,
                        dir4,
                        i
                        );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                        );

                    if(object != 0 && is_object_breakable(object))
                    {
                        if(i < min_diff)
                        {
                            min_diff = i;
                            chosen_dir4 = dir4;
                        }
                    }

                    if(object != 0 && !is_object_throw_over(object))
                    {
                        go_on = 0;
                    }
                }
            }

            enemy->object->attack_dir4 = chosen_dir4;

            if(chosen_dir4 == DIR4__NONE)
            {
                enemy->skill = SKILL__NONE;
                enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
                enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
            }
            else
            {
                enemy->skill = SKILL__TURRET_BOMB;
                enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy_object->tilemap_pos,
                    chosen_dir4,
                    min_diff
                    );
            }
        }
        break;
        case OBJECT__TURRET_PROJECTILE_GROUNDED:
        case OBJECT__TURRET_PROJECTILE_STANDING:
        case OBJECT__TURRET_PROJECTILE_DEPLOYED:
        {
            int min_diff = 10;
            int chosen_dir4 = DIR4__NONE;

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                int go_on = 1;
                for(int i = 1; i < 10 && go_on; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        enemy_object->tilemap_pos,
                        dir4,
                        i
                        );

                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                        );

                    if(object != 0 && !is_object_wall(object))
                    {
                        if(i < min_diff)
                        {
                            min_diff = i;
                            chosen_dir4 = dir4;
                        }
                    }

                    if(object != 0)
                    {
                        go_on = 0;
                    }
                }
            }

            enemy->object->attack_dir4 = chosen_dir4;

            if(chosen_dir4 == DIR4__NONE)
            {
                enemy->skill = SKILL__NONE;
                enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
                enemy->target_2_tilemap_pos = enemy_object->tilemap_pos;
            }
            else
            {
                enemy->skill = SKILL__TURRET_PROJECTILE;
                enemy->target_1_tilemap_pos = enemy_object->tilemap_pos;
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    enemy_object->tilemap_pos,
                    chosen_dir4,
                    min_diff
                    );
            }
        }
        break;
        default:
        break;
    }
}
