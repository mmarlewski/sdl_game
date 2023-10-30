#include "../inc/state.h"

void update_action(State* state, Action* sequence, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("update action:      %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            action->is_finished = 1;
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            ListElem* curr_elem = action->sequence.curr_action_list_elem;
            Action* curr_action = (Action*)curr_elem->data;

            if(curr_action->is_finished)
            {
                end_action(state, action, curr_action, textures, sounds, musics, colors);
                ListElem* next_elem = curr_elem->next;
                // remove_list_element(action->sequence.action_list, curr_elem, 1);
                action->sequence.curr_action_list_elem = next_elem;

                if(next_elem != 0)
                {
                    Action* next_action = (Action*)next_elem->data;
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
        case ACTION_TYPE__SIMULTANEOUS:
        {
            int are_all_actions_finished = 1;
            List* action_to_be_removed_list = new_list(0);

            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Action* curr_action = (Action*)curr_elem->data;
                if(curr_action->is_finished)
                {
                    end_action(state, curr_action, curr_action, textures, sounds, musics, colors);
                    add_new_list_element_to_list_end(action_to_be_removed_list, curr_action);
                }
                else
                {
                    update_action(state, curr_action, curr_action, delta_time, textures, sounds, musics, colors);
                    are_all_actions_finished = 0;
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
        case ACTION_TYPE__MOVE:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__FALL:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__THROW:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__LIFT:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__CHANGE:
        {
            action->is_finished = 1;
        }
        break;
        default:
        break;
    }
}
