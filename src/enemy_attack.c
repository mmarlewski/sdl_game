#include "../inc/state.h"

void object_enemy_add_actions_to_action_sequence_attack(State* state, Action* action_sequence, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__GOAT:
        {
            int found = 0;
            Object* target_1_object = 0;
            vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy_attack_dir4,1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__CHARGE_AND_PUSH,
                        object->tilemap_pos,
                        target_1_tilemap_pos,
                        make_vec2i_move_in_dir4_by(
                            target_1_tilemap_pos,
                            object->enemy_attack_dir4, 1
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
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 10
                        ),
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 11
                        )
                    );
            }
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            int found = 0;
            Object* target_1_object = 0;
            vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy_attack_dir4,1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
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
            if(!found)
            {
                skill_add_actions_to_action_sequence(
                    state,
                    action_sequence,
                    SKILL__CHARGE,
                    object->tilemap_pos,
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 1
                        ),
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 1
                        )
                    );
            }
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            int found = 0;
            Object* target_1_object = 0;
            vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy_attack_dir4,1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__CHARGE_AND_THROW,
                        object->tilemap_pos,
                        target_1_tilemap_pos,
                        make_vec2i_move_in_dir4_by(
                            target_1_tilemap_pos,
                            object->enemy_attack_dir4, 2
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
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 10
                        ),
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 12
                        )
                    );
            }
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            int found = 0;
            Object* target_1_object = 0;
            vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy_attack_dir4,1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__PUSH,
                        object->tilemap_pos,
                        target_1_tilemap_pos,
                        make_vec2i_move_in_dir4_by(
                            target_1_tilemap_pos,
                            object->enemy_attack_dir4, 1
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
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 1
                        ),
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4, 1
                        )
                    );
            }
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            int found = 0;
            Object* target_1_object = 0;
            vec2i target_1_tilemap_pos = object->tilemap_pos;
            for(int i = 0; i < 10; i++)
            {
                target_1_tilemap_pos = make_vec2i_move_in_dir4_by(target_1_tilemap_pos, object->enemy_attack_dir4, 1);
                target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
                if(target_1_object != 0)
                {
                    skill_add_actions_to_action_sequence(
                        state,
                        action_sequence,
                        SKILL__PULL_AND_THROW,
                        object->tilemap_pos,
                        target_1_tilemap_pos,
                        make_vec2i_move_in_dir4_by(
                            object->tilemap_pos,
                            get_opposite_dir4(object->enemy_attack_dir4), 1
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
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4,1
                        ),
                    make_vec2i_move_in_dir4_by(
                        object->tilemap_pos,
                        object->enemy_attack_dir4,1
                        )
                    );
            }
        }
        break;
        default:
        break;
    }
}
