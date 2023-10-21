#include "../inc/state.h"

void object_enemy_add_actions_to_action_sequence_move(State* state, Action* action_sequence, Object* object)
{
    int dir4 = rand() % 4 + 1;
    int distance = rand() % 5 + 1;

    vec2i curr_tilemap_pos = object->tilemap_pos;
    vec2i new_tilemap_pos = object->tilemap_pos;
    Object* new_tilemap_pos_object = 0;
    for(int i = 0; i < distance; i++)
    {
        new_tilemap_pos = make_vec2i_move_in_dir4_by(curr_tilemap_pos, dir4, 1);
        new_tilemap_pos_object = get_object_on_tilemap_pos(state, new_tilemap_pos);
        if(new_tilemap_pos_object == 0)
        {
            add_action_to_end_action_sequence(action_sequence, new_action_move(curr_tilemap_pos,dir4));
            curr_tilemap_pos = new_tilemap_pos;
        }
        else break;
    }

    switch(object->type)
    {
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
