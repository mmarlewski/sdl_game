#include "../inc/state.h"

void object_enemy_prepare_attack(State* state, Enemy* enemy)
{
    Object* object = enemy->object;

    enemy->skill = SKILL__NONE;
    enemy->target_1_tilemap_pos = vec2i(-1,-1);
    enemy->target_2_tilemap_pos = vec2i(-1,-1);

    switch(object->type)
    {
        case OBJECT_TYPE__GOAT:
        {
            int found = 0;
            Object* target_1_object = 0;
            Vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, enemy->object->attack_dir4,1);
                target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    enemy->skill = SKILL__CHARGE_AND_PUSH;
                    enemy->target_1_tilemap_pos = target_1_tilemap_pos;
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        enemy->object->attack_dir4, 1
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                enemy->skill = SKILL__CHARGE_AND_PUSH;
                enemy->target_1_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    enemy->object->attack_dir4, 10
                    );
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    enemy->object->attack_dir4, 11
                    );
            }
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            int found = 0;
            Vec2i old_target_1_tilemap_pos = object->tilemap_pos;
            Vec2i target_1_tilemap_pos = vec2i_move_in_dir4_by(object->tilemap_pos, enemy->object->attack_dir4,1);
            for(int i = 0; i < 10; i++)
            {
                if(is_tilemap_in_bounds(target_1_tilemap_pos))
                {
                    Object* target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
                    if(target_1_object != 0)
                    {
                        enemy->skill = SKILL__PULL;
                        enemy->target_1_tilemap_pos = target_1_tilemap_pos;
                        enemy->target_2_tilemap_pos = object->tilemap_pos;
                        found = 1;
                        break;
                    }
                }
                else
                {
                    enemy->skill = SKILL__PULL;
                    enemy->target_1_tilemap_pos = old_target_1_tilemap_pos;
                    enemy->target_2_tilemap_pos = object->tilemap_pos;
                    found = 1;
                    break;
                }
                old_target_1_tilemap_pos = target_1_tilemap_pos;
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, enemy->object->attack_dir4,1);
            }
            if(!found)
            {
                enemy->skill = SKILL__PULL;
                enemy->target_1_tilemap_pos = old_target_1_tilemap_pos;
                enemy->target_2_tilemap_pos = object->tilemap_pos;
            }
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            int found = 0;
            Object* target_1_object = 0;
            Vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, enemy->object->attack_dir4,1);
                target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    enemy->skill = SKILL__CHARGE_AND_THROW;
                    enemy->target_1_tilemap_pos = target_1_tilemap_pos;
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        enemy->object->attack_dir4, 2
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                enemy->skill = SKILL__CHARGE_AND_THROW;
                enemy->target_1_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    enemy->object->attack_dir4, 10
                    );
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    enemy->object->attack_dir4, 12
                    );
            }
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            int found = 0;
            Object* target_1_object = 0;
            Vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, enemy->object->attack_dir4,1);
                target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    enemy->skill = SKILL__PUSH;
                    enemy->target_1_tilemap_pos = target_1_tilemap_pos;
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        enemy->object->attack_dir4, 1
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                enemy->skill = SKILL__CHARGE;
                enemy->target_1_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    enemy->object->attack_dir4, 1
                    );
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    enemy->object->attack_dir4, 1
                    );
            }
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            int found = 0;
            Vec2i old_target_1_tilemap_pos = object->tilemap_pos;
            Vec2i target_1_tilemap_pos = vec2i_move_in_dir4_by(object->tilemap_pos,enemy->object->attack_dir4,1);
            Object* target_1_object = 0;
            for(int i = 0; i < 10; i++)
            {
                if(is_tilemap_in_bounds(target_1_tilemap_pos))
                {
                    target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
                    if(target_1_object != 0)
                    {
                        enemy->skill = SKILL__PULL_AND_THROW;
                        enemy->target_1_tilemap_pos = target_1_tilemap_pos;
                        enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                            object->tilemap_pos,
                            get_opposite_dir4(enemy->object->attack_dir4),
                            1
                            );
                        found = 1;
                        break;
                    }
                }
                else
                {
                    enemy->skill = SKILL__PULL_AND_THROW;
                    enemy->target_1_tilemap_pos = old_target_1_tilemap_pos;
                    enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        get_opposite_dir4(enemy->object->attack_dir4),
                        1
                        );
                    found = 1;
                    break;
                }
                old_target_1_tilemap_pos = target_1_tilemap_pos;
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, enemy->object->attack_dir4, 1);
            }
            if(!found)
            {
                enemy->skill = SKILL__PULL_AND_THROW;
                enemy->target_1_tilemap_pos = old_target_1_tilemap_pos;
                enemy->target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    get_opposite_dir4(enemy->object->attack_dir4),
                    1
                    );
            }
        }
        break;
        case OBJECT_TYPE__TURRET_LASER_GROUNDED:
        case OBJECT_TYPE__TURRET_LASER_STANDING:
        case OBJECT_TYPE__TURRET_LASER_DEPLOYED:
        {
            int found_target = 0;
            for(int i = 1; i < 3; i++)
            {
                for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(object->tilemap_pos, dir4, i);

                    if(is_tilemap_in_bounds(tilemap_pos))
                    {
                        Object* curr_object = room_get_object_at(state->curr_room, tilemap_pos);

                        if(curr_object != 0 && !found_target)
                        {
                            found_target = 1;

                            enemy->skill = SKILL__TURRET_LASER;
                            enemy->target_1_tilemap_pos = vec2i(-1,-1);
                            enemy->target_2_tilemap_pos = tilemap_pos;
                        }
                    }
                }
            }
        }
        break;
        case OBJECT_TYPE__TURRET_BOMB_GROUNDED:
        case OBJECT_TYPE__TURRET_BOMB_STANDING:
        case OBJECT_TYPE__TURRET_BOMB_DEPLOYED:
        {
            int found_target = 0;
            for(int i = 2; i <= OBJECT_TURRET_RANGE; i++)
            {
                List* square_perimeter_tilemap_pos = new_list((void(*)(void*))destroy_vec2i);

                get_square_perimeter_tilemap_pos(
                    object->tilemap_pos,
                    i,
                    square_perimeter_tilemap_pos
                    );

                for(ListElem* curr_elem = square_perimeter_tilemap_pos->head; curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Vec2i curr_tilemap_pos = *(Vec2i*)curr_elem->data;

                    if(is_tilemap_in_bounds(curr_tilemap_pos))
                    {
                        Object* curr_object = room_get_object_at(state->curr_room, curr_tilemap_pos);

                        if(curr_object != 0 && !found_target)
                        {
                            found_target = 1;

                            enemy->skill = SKILL__TURRET_BOMB;
                            enemy->target_1_tilemap_pos = vec2i(-1,-1);
                            enemy->target_2_tilemap_pos = curr_tilemap_pos;
                        }
                    }
                }

                remove_all_list_elements(square_perimeter_tilemap_pos, 1);
            }
        }
        break;
        case OBJECT_TYPE__TURRET_PROJECTILE_GROUNDED:
        case OBJECT_TYPE__TURRET_PROJECTILE_STANDING:
        case OBJECT_TYPE__TURRET_PROJECTILE_DEPLOYED:
        {
            int found_target = 0;
            for(int i = 1; i <= OBJECT_TURRET_RANGE; i++)
            {
                List* square_perimeter_tilemap_pos = new_list((void(*)(void*))destroy_vec2i);

                get_square_perimeter_tilemap_pos(
                    object->tilemap_pos,
                    i,
                    square_perimeter_tilemap_pos
                    );

                for(ListElem* perimeter_elem = square_perimeter_tilemap_pos->head; perimeter_elem != 0; perimeter_elem = perimeter_elem->next)
                {
                    Vec2i perimeter_tilemap_pos = *(Vec2i*)perimeter_elem->data;
                    Object* perimeter_object = room_get_object_at(state->curr_room, perimeter_tilemap_pos);

                    List* line_tilemap_pos = new_list((void(*)(void*))destroy_vec2i);

                    get_line_from_tilemap_pos_to_tilemap_pos(
                        object->tilemap_pos,
                        perimeter_tilemap_pos,
                        line_tilemap_pos
                        );

                    int is_line_obstructed = 0;
                    for(ListElem* line_elem = line_tilemap_pos->head; line_elem != 0; line_elem = line_elem->next)
                    {
                        Vec2i line_tilemap_pos = *(Vec2i*)line_elem->data;
                        Object* line_object = room_get_object_at(state->curr_room, line_tilemap_pos);

                        if(!vec2i_equals(line_tilemap_pos, object->tilemap_pos) &&
                        !vec2i_equals(line_tilemap_pos, perimeter_tilemap_pos))
                        {
                            if(line_object != 0)
                            {
                                is_line_obstructed = 1;
                            }
                        }
                    }

                    if(!is_line_obstructed && perimeter_object != 0 && !found_target)
                    {
                        found_target = 1;

                        enemy->skill = SKILL__TURRET_PROJECTILE;
                        enemy->target_1_tilemap_pos = vec2i(-1,-1);
                        enemy->target_2_tilemap_pos = perimeter_tilemap_pos;
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
