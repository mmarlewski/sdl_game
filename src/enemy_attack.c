#include "../inc/state.h"

void object_enemy_add_actions_to_action_sequence_attack(State* state, Action* action_sequence, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__GOAT:
        {
            skill_add_actions_to_action_sequence(state, action_sequence, SKILL__CHARGE_AND_PUSH, object->tilemap_pos, make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 2), make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 4));
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            skill_add_actions_to_action_sequence(state, action_sequence, SKILL__PULL, object->tilemap_pos, make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 2), make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 4));
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            skill_add_actions_to_action_sequence(state, action_sequence, SKILL__CHARGE_AND_THROW, object->tilemap_pos, make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 2), make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 4));
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            skill_add_actions_to_action_sequence(state, action_sequence, SKILL__PUSH, object->tilemap_pos, make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 2), make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 4));
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            skill_add_actions_to_action_sequence(state, action_sequence, SKILL__PULL_AND_THROW, object->tilemap_pos, make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 2), make_vec2i_move_in_dir4_by(object->tilemap_pos, DIR4__RIGHT, 4));
        }
        break;
        default: break;
    }
}
