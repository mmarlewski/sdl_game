#include "../inc/state.h"

void object_enemy_prepare_attack(State* state, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__GOAT:
        {
            int found = 0;
            Object* target_1_object = 0;
            Vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy.attack_dir4,1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    object->enemy.skill = SKILL__CHARGE_AND_PUSH;
                    object->enemy.target_1_tilemap_pos = target_1_tilemap_pos;
                    object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        object->enemy.attack_dir4, 1
                        );
                    skill_add_actions_to_action_sequence(
                        state,
                        object->enemy.action_sequence,
                        object->enemy.skill,
                        object->tilemap_pos,
                        object->enemy.target_1_tilemap_pos,
                        object->enemy.target_2_tilemap_pos
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                object->enemy.skill = SKILL__CHARGE_AND_PUSH;
                object->enemy.target_1_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    object->enemy.attack_dir4, 10
                    );
                object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    object->enemy.attack_dir4, 11
                    );
                skill_add_actions_to_action_sequence(
                    state,
                    object->enemy.action_sequence,
                    object->enemy.skill,
                    object->tilemap_pos,
                    object->enemy.target_1_tilemap_pos,
                    object->enemy.target_2_tilemap_pos
                    );
            }
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            int found = 0;
            Vec2i old_target_1_tilemap_pos = object->tilemap_pos;
            Vec2i target_1_tilemap_pos = vec2i_move_in_dir4_by(object->tilemap_pos, object->enemy.attack_dir4,1);
            for(int i = 0; i < 10; i++)
            {
                if(is_tilemap_pos_in_tilemap(target_1_tilemap_pos))
                {
                    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                    if(target_1_object != 0)
                    {
                        object->enemy.skill = SKILL__PULL;
                        object->enemy.target_1_tilemap_pos = target_1_tilemap_pos;
                        object->enemy.target_2_tilemap_pos = object->tilemap_pos;
                        skill_add_actions_to_action_sequence(
                            state,
                            object->enemy.action_sequence,
                            object->enemy.skill,
                            object->tilemap_pos,
                            object->enemy.target_1_tilemap_pos,
                            object->enemy.target_2_tilemap_pos
                            );
                        found = 1;
                        break;
                    }
                }
                else
                {
                    object->enemy.skill = SKILL__PULL;
                    object->enemy.target_1_tilemap_pos = old_target_1_tilemap_pos;
                    object->enemy.target_2_tilemap_pos = object->tilemap_pos;
                    skill_add_actions_to_action_sequence(
                        state,
                        object->enemy.action_sequence,
                        object->enemy.skill,
                        object->tilemap_pos,
                        object->enemy.target_1_tilemap_pos,
                        object->enemy.target_2_tilemap_pos
                        );
                    found = 1;
                    break;
                }
                old_target_1_tilemap_pos = target_1_tilemap_pos;
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy.attack_dir4,1);
            }
            if(!found)
            {
                object->enemy.skill = SKILL__PULL;
                object->enemy.target_1_tilemap_pos = old_target_1_tilemap_pos;
                object->enemy.target_2_tilemap_pos = object->tilemap_pos;
                skill_add_actions_to_action_sequence(
                    state,
                    object->enemy.action_sequence,
                    object->enemy.skill,
                    object->tilemap_pos,
                    object->enemy.target_1_tilemap_pos,
                    object->enemy.target_2_tilemap_pos
                    );
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
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy.attack_dir4,1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    object->enemy.skill = SKILL__CHARGE_AND_THROW;
                    object->enemy.target_1_tilemap_pos = target_1_tilemap_pos;
                    object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        object->enemy.attack_dir4, 2
                        );
                    skill_add_actions_to_action_sequence(
                        state,
                        object->enemy.action_sequence,
                        object->enemy.skill,
                        object->tilemap_pos,
                        object->enemy.target_1_tilemap_pos,
                        object->enemy.target_2_tilemap_pos
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                object->enemy.skill = SKILL__CHARGE_AND_THROW;
                object->enemy.target_1_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    object->enemy.attack_dir4, 10
                    );
                object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    object->enemy.attack_dir4, 12
                    );
                skill_add_actions_to_action_sequence(
                    state,
                    object->enemy.action_sequence,
                    object->enemy.skill,
                    object->tilemap_pos,
                    object->enemy.target_1_tilemap_pos,
                    object->enemy.target_2_tilemap_pos
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
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy.attack_dir4,1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    object->enemy.skill = SKILL__PUSH;
                    object->enemy.target_1_tilemap_pos = target_1_tilemap_pos;
                    object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        target_1_tilemap_pos,
                        object->enemy.attack_dir4, 1
                        );
                    skill_add_actions_to_action_sequence(
                        state,
                        object->enemy.action_sequence,
                        object->enemy.skill,
                        object->tilemap_pos,
                        object->enemy.target_1_tilemap_pos,
                        object->enemy.target_2_tilemap_pos
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                object->enemy.skill = SKILL__CHARGE;
                object->enemy.target_1_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    object->enemy.attack_dir4, 1
                    );
                object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    object->enemy.attack_dir4, 1
                    );
                skill_add_actions_to_action_sequence(
                    state,
                    object->enemy.action_sequence,
                    object->enemy.skill,
                    object->tilemap_pos,
                    object->enemy.target_1_tilemap_pos,
                    object->enemy.target_2_tilemap_pos
                    );
            }
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            int found = 0;
            Vec2i old_target_1_tilemap_pos = object->tilemap_pos;
            Vec2i target_1_tilemap_pos = vec2i_move_in_dir4_by(object->tilemap_pos,object->enemy.attack_dir4,1);
            Object* target_1_object = 0;
            for(int i = 0; i < 10; i++)
            {
                if(is_tilemap_pos_in_tilemap(target_1_tilemap_pos))
                {
                    target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                    if(target_1_object != 0)
                    {
                        object->enemy.skill = SKILL__PULL_AND_THROW;
                        object->enemy.target_1_tilemap_pos = target_1_tilemap_pos;
                        object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                            object->tilemap_pos,
                            get_opposite_dir4(object->enemy.attack_dir4),
                            1
                            );
                        skill_add_actions_to_action_sequence(
                        state,
                        object->enemy.action_sequence,
                        object->enemy.skill,
                        object->tilemap_pos,
                        object->enemy.target_1_tilemap_pos,
                        object->enemy.target_2_tilemap_pos
                        );
                        found = 1;
                        break;
                    }
                }
                else
                {
                    object->enemy.skill = SKILL__PULL_AND_THROW;
                    object->enemy.target_1_tilemap_pos = old_target_1_tilemap_pos;
                    object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        get_opposite_dir4(object->enemy.attack_dir4),
                        1
                        );
                    skill_add_actions_to_action_sequence(
                        state,
                        object->enemy.action_sequence,
                        object->enemy.skill,
                        object->tilemap_pos,
                        object->enemy.target_1_tilemap_pos,
                        object->enemy.target_2_tilemap_pos
                        );
                    found = 1;
                    break;
                }
                old_target_1_tilemap_pos = target_1_tilemap_pos;
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy.attack_dir4, 1);
            }
            if(!found)
            {
                object->enemy.skill = SKILL__PULL_AND_THROW;
                object->enemy.target_1_tilemap_pos = old_target_1_tilemap_pos;
                object->enemy.target_2_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    get_opposite_dir4(object->enemy.attack_dir4),
                    1
                    );
                skill_add_actions_to_action_sequence(
                    state,
                    object->enemy.action_sequence,
                    object->enemy.skill,
                    object->tilemap_pos,
                    object->enemy.target_1_tilemap_pos,
                    object->enemy.target_2_tilemap_pos
                    );
            }
        }
        break;
        default:
        break;
    }
}
