#include "../inc/state.h"

void object_enemy_add_actions_to_action_sequence_attack(State* state, Action* action_sequence, Object* object)
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
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__CHARGE_AND_PUSH,
                        object->tilemap_pos,
                        target_1_tilemap_pos,
                        vec2i_move_in_dir4_by(
                            target_1_tilemap_pos,
                            object->enemy.attack_dir4, 1
                            )
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                skill_add_actions_to_action_sequence(
                    state,
                    action_sequence,
                    SKILL__CHARGE_AND_PUSH,
                    object->tilemap_pos,
                    vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy.attack_dir4, 10
                        ),
                    vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy.attack_dir4, 11
                        )
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
                        skill_add_actions_to_action_sequence(
                            state,
                            action_sequence,
                            SKILL__PULL,
                            object->tilemap_pos,
                            target_1_tilemap_pos,
                            object->tilemap_pos
                            );
                        found = 1;
                        break;
                    }
                }
                else
                {
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__PULL,
                        object->tilemap_pos,
                        old_target_1_tilemap_pos,
                        object->tilemap_pos
                        );
                    found = 1;
                    break;
                }
                old_target_1_tilemap_pos = target_1_tilemap_pos;
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy.attack_dir4,1);
            }
            if(!found)
            {
                skill_add_actions_to_action_sequence(
                    state,
                    action_sequence,
                    SKILL__PULL,
                    object->tilemap_pos,
                    old_target_1_tilemap_pos,
                    object->tilemap_pos
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
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__CHARGE_AND_THROW,
                        object->tilemap_pos,
                        target_1_tilemap_pos,
                        vec2i_move_in_dir4_by(
                            target_1_tilemap_pos,
                            object->enemy.attack_dir4, 2
                            )
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                skill_add_actions_to_action_sequence(
                    state,
                    action_sequence,
                    SKILL__CHARGE_AND_THROW,
                    object->tilemap_pos,
                    vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy.attack_dir4, 10
                        ),
                    vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy.attack_dir4, 12
                        )
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
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__PUSH,
                        object->tilemap_pos,
                        target_1_tilemap_pos,
                        vec2i_move_in_dir4_by(
                            target_1_tilemap_pos,
                            object->enemy.attack_dir4, 1
                            )
                        );
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                skill_add_actions_to_action_sequence(
                    state,
                    action_sequence,
                    SKILL__CHARGE,
                    object->tilemap_pos,
                    vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy.attack_dir4, 1
                        ),
                    vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy.attack_dir4, 1
                        )
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
                        skill_add_actions_to_action_sequence(
                            state,
                            action_sequence,
                            SKILL__PULL_AND_THROW,
                            object->tilemap_pos,
                            target_1_tilemap_pos,
                            vec2i_move_in_dir4_by(
                                object->tilemap_pos,
                                get_opposite_dir4(object->enemy.attack_dir4),
                                1
                                )
                            );
                        found = 1;
                        break;
                    }
                }
                else
                {
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__PULL_AND_THROW,
                        object->tilemap_pos,
                        old_target_1_tilemap_pos,
                        vec2i_move_in_dir4_by(
                            object->tilemap_pos,
                            get_opposite_dir4(object->enemy.attack_dir4),
                            1
                            )
                        );
                    found = 1;
                    break;
                }
                old_target_1_tilemap_pos = target_1_tilemap_pos;
                target_1_tilemap_pos = vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy.attack_dir4, 1);
            }
            if(!found)
            {
                skill_add_actions_to_action_sequence(
                    state,
                    action_sequence,
                    SKILL__PULL_AND_THROW,
                    object->tilemap_pos,
                    old_target_1_tilemap_pos,
                    vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        get_opposite_dir4(object->enemy.attack_dir4),
                        1
                        )
                    );
            }
        }
        break;
        default:
        break;
    }
}
