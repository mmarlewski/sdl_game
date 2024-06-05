#include "../inc/state.h"

void update_action(State* state, Action* sequence, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("update action:      %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION__NONE:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__SEQUENCE:
        {
            ListElem* curr_elem = action->sequence.curr_action_list_elem;
            Action* curr_action = (Action*) curr_elem->data;

            if(curr_action->is_finished)
            {
                end_action(state, action, curr_action, textures, sounds, musics, colors);
                ListElem* next_elem = curr_elem->next;
                action->sequence.curr_action_list_elem = next_elem;

                if(next_elem != NULL)
                {
                    Action* next_action = (Action*) next_elem->data;
                    start_action(state, action, next_action, textures, sounds, musics, colors);
                }
            }
            else
            {
                update_action(state, action, curr_action, delta_time, textures, sounds, musics, colors);
            }

            action->is_finished = (!action->sequence.curr_action_list_elem);
        }
        break;
        case ACTION__SIMULTANEOUS:
        {
            int are_all_actions_finished = TRUE;
            List* action_to_be_removed_list = new_list(0);

            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Action* curr_action = (Action*) curr_elem->data;
                if(curr_action->is_finished)
                {
                    end_action(state, curr_action, curr_action, textures, sounds, musics, colors);
                    add_new_list_element_to_list_end(action_to_be_removed_list, curr_action);
                }
                else
                {
                    update_action(state, curr_action, curr_action, delta_time, textures, sounds, musics, colors);
                    are_all_actions_finished = FALSE;
                }
            }

            for(ListElem* curr_elem = action_to_be_removed_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                remove_list_element_of_data(action->simultaneous.action_list, curr_elem->data, 1);
            }

            destroy_list(action_to_be_removed_list);

            action->is_finished = (are_all_actions_finished);
        }
        break;
        case ACTION__MOVE:
        case ACTION__MOVE_FLOATING:
        case ACTION__MOVE_FLYING:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__CRASH:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__FALL:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__DEATH:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__BLOW_UP:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__THROW:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__LIFT:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__DROP:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION__CHANGE_FLOOR:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__CHANGE_OBJECT:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__ADD_OBJECT:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__REMOVE_OBJECT:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__CHANGE_OBJECT_TILEMAP_POS:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__MELT:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__BREAK:
        {
            action->is_finished = TRUE;
        }
        break;
        case ACTION__SHAKE:
        {
            action->is_finished = TRUE;
        }
        break;
        default:
        break;
    }
}
