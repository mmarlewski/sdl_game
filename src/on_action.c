#include "../inc/state.h"

void floor_on_move_start(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR_TYPE__METAL:
        {
            //
        }
        break;
        case FLOOR_TYPE__METAL_SPIKES:
        {
            //
        }
        break;
        case FLOOR_TYPE__METAL_LAVA_CRACK:
        {
            change_floor_in_tilemap_pos(state, FLOOR_TYPE__LAVA, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR_TYPE__LAVA:
        {
            //
        }
        break;
        case FLOOR_TYPE__ICE:
        {
            //
        }
        break;
        case FLOOR_TYPE__ICE_WATER_CRACK:
        {
            change_floor_in_tilemap_pos(state, FLOOR_TYPE__WATER, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR_TYPE__WATER:
        {
            //
        }
        break;
        default:
        break;
    }
}

void floor_on_move_end(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR_TYPE__METAL:
        {
            //
        }
        break;
        case FLOOR_TYPE__METAL_SPIKES:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, new_action_death(action->move.object, make_vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            }
        }
        break;
        case FLOOR_TYPE__METAL_LAVA_CRACK:
        {
            //
        }
        break;
        case FLOOR_TYPE__LAVA:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->move.object, make_vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            }
        }
        break;
        case FLOOR_TYPE__ICE:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_move( make_vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
            }
        }
        break;
        case FLOOR_TYPE__ICE_WATER_CRACK:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_move( make_vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
            }
        }
        break;
        case FLOOR_TYPE__WATER:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->move.object, make_vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            }
        }
        break;
        default:
        break;
    }
}

void floor_on_drop(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR_TYPE__METAL:
        {
            //
        }
        break;
        case FLOOR_TYPE__METAL_SPIKES:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_death(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__METAL_LAVA_CRACK:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                change_floor_in_tilemap_pos(state, FLOOR_TYPE__LAVA, action->tilemap_pos);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__LAVA:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__ICE:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_move(action->tilemap_pos, action->drop.dir4));
            }
        }
        break;
        case FLOOR_TYPE__ICE_WATER_CRACK:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                change_floor_in_tilemap_pos(state, FLOOR_TYPE__WATER, action->tilemap_pos);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__WATER:
        {
            if(!is_object_flying(action->move.object->type))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        default:
        break;
    }
}

void object_on_crashing(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PILLAR:
        {
            //
        }
        break;
        case OBJECT_TYPE__PILLAR_SPIKES:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(sequence, new_action_death(action->crash.object_crushed, action->crash.object_crushed->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__SPRING:
        {
            //
        }
        break;
        case OBJECT_TYPE__HERO:
        {
            //
        }
        break;
        case OBJECT_TYPE__GOAT:
        {
            //
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            //
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            //
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            //
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            //
        }
        break;
        default:
        break;
    }
}

void object_on_crashed(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PILLAR:
        {
            //
        }
        break;
        case OBJECT_TYPE__PILLAR_SPIKES:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(sequence, new_action_death(action->crash.object_crushing, action->crash.object_crushing->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__SPRING:
        {
            add_action_to_end_action_sequence(sequence, new_action_move(object->tilemap_pos, action->crash.dir4));
        }
        break;
        case OBJECT_TYPE__HERO:
        {
            //
        }
        break;
        case OBJECT_TYPE__GOAT:
        {
            //
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            //
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            //
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            //
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            //
        }
        break;
        default:
        break;
    }
}

void object_on_death(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PILLAR:
        {
            //
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_blow_up(object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__SPRING:
        {
            //
        }
        break;
        case OBJECT_TYPE__HERO:
        {
            //
        }
        break;
        case OBJECT_TYPE__GOAT:
        {
            //
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            //
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            //
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            //
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            //
        }
        break;
        default:
        break;
    }
}

void object_on_drop(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PILLAR:
        {
            //
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__SPRING:
        {
            add_action_to_end_action_sequence(sequence, new_action_move( action->tilemap_pos, action->drop.dir4));
        }
        break;
        case OBJECT_TYPE__HERO:
        {
            //
        }
        break;
        case OBJECT_TYPE__GOAT:
        {
            //
        }
        break;
        case OBJECT_TYPE__SPIDER:
        {
            //
        }
        break;
        case OBJECT_TYPE__BULL:
        {
            //
        }
        break;
        case OBJECT_TYPE__FLY:
        {
            //
        }
        break;
        case OBJECT_TYPE__CHAMELEON:
        {
            //
        }
        break;
        default:
        break;
    }
}
