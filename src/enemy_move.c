#include "../inc/state.h"

void object_enemy_add_actions_to_action_sequence_move(State* state, Action* action_sequence, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__GOAT:
        {
            add_action_to_end_action_sequence(action_sequence, new_action_move_ground(object, object->tilemap_pos, DIR4__RIGHT));
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            add_action_to_end_action_sequence(action_sequence, new_action_move_ground(object, object->tilemap_pos, DIR4__RIGHT));
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            add_action_to_end_action_sequence(action_sequence, new_action_move_ground(object, object->tilemap_pos, DIR4__RIGHT));
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            add_action_to_end_action_sequence(action_sequence, new_action_move_air(object, object->tilemap_pos, DIR4__RIGHT));
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            add_action_to_end_action_sequence(action_sequence, new_action_move_ground(object, object->tilemap_pos, DIR4__RIGHT));
        }
        break;
        default:
        break;
    }
}
